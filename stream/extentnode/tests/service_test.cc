
#include "extentnode/service.h"

#include <isa-l.h>

#include <iostream>
#include <random>
#include <seastar/core/memory.hh>
#include <seastar/core/sharded.hh>
#include <seastar/core/thread.hh>
#include <seastar/testing/test_case.hh>
#include <seastar/testing/thread_test_case.hh>

#include "mem_stream.h"
#include "net/byteorder.h"
#include "proto/extentnode.pb.h"
#include "util/logger.h"

namespace snail {
namespace stream {

static bool ParseResponse(const char* p, size_t len,
                          ::google::protobuf::Message* resp,
                          ExtentnodeMsgType& type) {
    if (len <= kMetaMsgHeaderLen) {
        LOG_ERROR("invalid len");
        return false;
    }
    uint32_t origin_crc = net::BigEndian::Uint32(p);
    uint32_t crc = crc32_gzip_refl(0, (const unsigned char*)(p + 4), len - 4);
    if (origin_crc != crc) {
        LOG_ERROR("invalid crc");
        return false;
    }
    type = static_cast<ExtentnodeMsgType>(net::BigEndian::Uint16(p + 4));
    uint16_t body_len = net::BigEndian::Uint16(p + 6);
    if (body_len + kMetaMsgHeaderLen != len) {
        LOG_ERROR("invalid body_len={} len={}", body_len, len);
        return false;
    }
    return resp->ParseFromArray(p + kMetaMsgHeaderLen, body_len);
}

/*
SEASTAR_THREAD_TEST_CASE(handle_write_read_test) {
    auto ok = snail::stream::Store::Format("/dev/sdb", 1,
                                           snail::stream::DevType::HDD, 1)
                  .get0();
    BOOST_REQUIRE(ok);
    auto store = Store::Load("/dev/sdb").get0();
    BOOST_REQUIRE(store);

    Status<> s;
    ExtentID extent_id(1, 1);
    s = store->CreateExtent(extent_id).get0();
    BOOST_REQUIRE(s);
    char str_extent_id[16];
    net::BigEndian::PutUint64(&str_extent_id[0], extent_id.hi);
    net::BigEndian::PutUint64(&str_extent_id[8], extent_id.lo);
    auto pair_streams = MemStream::make_stream_pair();

    net::StreamPtr client_stream = pair_streams.first;
    net::StreamPtr server_stream = pair_streams.second;

    Service service(store);

    auto extent_ptr = store->GetExtent(extent_id);
    uint64_t off = 0;
    size_t body_len = 1 << 20;
    TmpBuffer content(16 << 20);
    memset(content.get_write(), 'a', content.size());
    // write 16M data
    for (int i = 0; i < 16; ++i, off += body_len) {
        std::unique_ptr<WriteExtentReq> req =
            std::make_unique<WriteExtentReq>();
        req->mutable_base()->set_reqid("123456");
        req->set_diskid(1);
        req->set_extent_id(std::string(str_extent_id, 16));
        req->set_off(off);
        req->set_len(body_len);

        TmpBuffer body =
            content.share(off, std::min(body_len, content.size() - off));
        std::vector<TmpBuffer> packets;
        size_t packets_len = 0;
        bool first_block = true;
        size_t first_block_len = kBlockDataSize - off % kBlockDataSize;
        for (size_t pos = 0; pos < body.size();) {
            size_t n = std::min(kBlockDataSize, (size_t)(body.size() - pos));
            if (first_block) {
                first_block = false;
                n = std::min(first_block_len, n);
            }
            if (packets_len + n + 4 > client_stream->MaxFrameSize()) {
                s = client_stream->WriteFrame(std::move(packets)).get0();
                BOOST_REQUIRE(s);
                packets_len = 0;
            }
            uint32_t crc =
                crc32_gzip_refl(0, (const unsigned char*)(body.get() + pos), n);
            TmpBuffer crc_buf(4);
            net::BigEndian::PutUint32(crc_buf.get_write(), crc);
            packets.emplace_back(std::move(body.share(pos, n)));
            packets.emplace_back(std::move(crc_buf));
            pos += n;
            packets_len += n + 4;
        }

        if (packets_len) {
            s = client_stream->WriteFrame(std::move(packets)).get0();
            BOOST_REQUIRE(s);
        }
        s = service
                .HandleWriteExtent(req.get(),
                                   seastar::make_foreign(server_stream))
                .get0();
        BOOST_REQUIRE(s);
        auto st = client_stream->ReadFrame().get0();
        BOOST_REQUIRE(st);
        TmpBuffer resp_buf = std::move(st.Value());
        std::unique_ptr<CommonResp> resp(new CommonResp());
        ExtentnodeMsgType type;
        BOOST_REQUIRE(
            ParseResponse(resp_buf.get(), resp_buf.size(), resp.get(), type));
        BOOST_REQUIRE_EQUAL(resp->code(), static_cast<int>(ErrCode::OK));
        BOOST_REQUIRE_EQUAL(extent_ptr->len, body_len * (i + 1));
    }

    uint64_t lens[4] = {4 << 20, 4 << 20, 4 << 20, (4 << 20) - 10};
    uint64_t offs[4] = {1233, 1233, (16 << 20) - (4 << 20),
                        (16 << 20) - (4 << 20)};
    for (int i = 0; i < 4; i++) {
        // the second read is hit cache
        auto read_streams = MemStream::make_stream_pair();
        net::StreamPtr read_client_stream = read_streams.first;
        net::StreamPtr read_server_stream = read_streams.second;
        // read data by service interface
        std::unique_ptr<ReadExtentReq> read_req(new ReadExtentReq);
        read_req->mutable_base()->set_reqid("1234567");
        read_req->set_diskid(1);
        read_req->set_extent_id(std::string(str_extent_id, 16));
        read_req->set_off(offs[i]);
        read_req->set_len(lens[i]);

        LOG_INFO("begin read i={} off={} len={}", i, read_req->off(),
                 read_req->len());
        auto fu = service.HandleReadExtent(
            read_req.get(), seastar::make_foreign(read_server_stream));

        auto st2 = read_client_stream->ReadFrame().get0();
        BOOST_REQUIRE(st2);
        TmpBuffer read_buf = std::move(st2.Value());
        std::unique_ptr<ReadExtentResp> read_resp(new ReadExtentResp);
        ExtentnodeMsgType type;
        BOOST_REQUIRE(ParseResponse(read_buf.get(), read_buf.size(),
                                    read_resp.get(), type));
        BOOST_REQUIRE(type == ExtentnodeMsgType::READ_EXTENT_RESP);
        BOOST_REQUIRE(read_resp->base().code() ==
                      static_cast<int>(ErrCode::OK));
        BOOST_REQUIRE(read_resp->len() == lens[i]);
        // read data
        size_t read_len = 0;
        bool first = true;
        size_t first_block_len = kBlockDataSize - offs[i] % kBlockDataSize;
        while (read_len < read_resp->len()) {
            auto st3 = read_client_stream->ReadFrame().get0();
            if (st3.Code() == ErrCode::ErrEOF) {
                break;
            }
            BOOST_REQUIRE(st3);
            TmpBuffer b = std::move(st3.Value());
            size_t data_len = b.size();
            const char* p = b.get();
            while (p < b.end()) {
                size_t n = std::min(kBlockSize, (size_t)(b.end() - p));
                if (first) {
                    n = first_block_len + 4;
                    first = false;
                }
                read_len += n - 4;
                uint32_t origin_crc = net::BigEndian::Uint32(p + n - 4);
                uint32_t crc =
                    crc32_gzip_refl(0, (const unsigned char*)p, n - 4);
                BOOST_REQUIRE_EQUAL(origin_crc, crc);
                p += n;
            }
        }
        BOOST_REQUIRE_EQUAL(read_len, read_resp->len());
        fu.get0();
    }

    store->Close().get();
}
*/

SEASTAR_THREAD_TEST_CASE(handle_multi_thread_write_read_test) {
    auto ok = snail::stream::Store::Format("/dev/sdb", 1,
                                           snail::stream::DevType::HDD, 1)
                  .get0();
    BOOST_REQUIRE(ok);
    auto store = Store::Load("/dev/sdb").get0();
    BOOST_REQUIRE(store);

    if (seastar::smp::count <= 1) {
        LOG_WARN("no multi thread env");
        return;
    }

    Status<> s;
    ExtentID extent_id(1, 1);
    s = store->CreateExtent(extent_id).get0();
    BOOST_REQUIRE(s);
    char str_extent_id[16];
    net::BigEndian::PutUint64(&str_extent_id[0], extent_id.hi);
    net::BigEndian::PutUint64(&str_extent_id[8], extent_id.lo);
    auto tp = seastar::smp::submit_to(1, []() {
                  auto pair_streams = MemStream::make_stream_pair();
                  return std::make_tuple(
                      seastar::make_foreign(std::move(pair_streams.first)),
                      seastar::make_foreign(std::move(pair_streams.second)));
              }).get0();

    seastar::foreign_ptr<net::StreamPtr> client_stream =
        std::move(std::get<0>(tp));
    seastar::foreign_ptr<net::StreamPtr> server_stream =
        std::move(std::get<1>(tp));

    Service service(store);

    auto extent_ptr = store->GetExtent(extent_id);
    uint64_t off = 0;
    size_t body_len = 1 << 20;
    TmpBuffer content(16 << 20);
    memset(content.get_write(), 'a', content.size());
    // write 16M data
    for (int i = 0; i < 16; ++i, off += body_len) {
        std::unique_ptr<WriteExtentReq> req =
            std::make_unique<WriteExtentReq>();
        req->mutable_base()->set_reqid("123456");
        req->set_diskid(1);
        req->set_extent_id(std::string(str_extent_id, 16));
        req->set_off(off);
        req->set_len(body_len);

        TmpBuffer body =
            content.share(off, std::min(body_len, content.size() - off));
        std::vector<TmpBuffer> packets;
        size_t packets_len = 0;
        bool first_block = true;
        size_t first_block_len = kBlockDataSize - off % kBlockDataSize;
        for (size_t pos = 0; pos < body.size();) {
            size_t n = std::min(kBlockDataSize, (size_t)(body.size() - pos));
            if (first_block) {
                first_block = false;
                n = std::min(first_block_len, n);
            }
            if (packets_len + n + 4 > client_stream->MaxFrameSize()) {
                s = seastar::smp::submit_to(1, [stream = client_stream.get(),
                                                packets = std::move(
                                                    packets)]() mutable {
                        return stream->WriteFrame(std::move(packets));
                    }).get0();
                BOOST_REQUIRE(s);
                packets_len = 0;
            }
            uint32_t crc =
                crc32_gzip_refl(0, (const unsigned char*)(body.get() + pos), n);
            TmpBuffer crc_buf(4);
            net::BigEndian::PutUint32(crc_buf.get_write(), crc);
            packets.emplace_back(std::move(body.share(pos, n)));
            packets.emplace_back(std::move(crc_buf));
            pos += n;
            packets_len += n + 4;
        }

        if (packets_len) {
            s = seastar::smp::submit_to(1, [stream = client_stream.get(),
                                            packets =
                                                std::move(packets)]() mutable {
                    return stream->WriteFrame(std::move(packets));
                }).get0();
            BOOST_REQUIRE(s);
        }
        auto tmp_server_stream = server_stream.copy().get0();
        s = service.HandleWriteExtent(req.get(), std::move(tmp_server_stream))
                .get0();
        BOOST_REQUIRE(s);
        auto st = seastar::smp::submit_to(1, [stream = client_stream.get()] {
                      return stream->ReadFrame();
                  }).get0();
        BOOST_REQUIRE(st);
        TmpBuffer resp_buf = std::move(st.Value());
        std::unique_ptr<CommonResp> resp(new CommonResp());
        ExtentnodeMsgType type;
        BOOST_REQUIRE(
            ParseResponse(resp_buf.get(), resp_buf.size(), resp.get(), type));
        BOOST_REQUIRE_EQUAL(resp->code(), static_cast<int>(ErrCode::OK));
        BOOST_REQUIRE_EQUAL(extent_ptr->len, body_len * (i + 1));
    }

    uint64_t lens[4] = {4 << 20, 4 << 20, 4 << 20, (4 << 20) - 10};
    uint64_t offs[4] = {1233, 1233, (16 << 20) - (4 << 20),
                        (16 << 20) - (4 << 20)};
    for (int i = 0; i < 4; i++) {
        // the second read is hit cache
        tp = seastar::smp::submit_to(1, []() {
                 auto pair_streams = MemStream::make_stream_pair();
                 return std::make_tuple(
                     seastar::make_foreign(pair_streams.first),
                     seastar::make_foreign(pair_streams.second));
             }).get0();

        seastar::foreign_ptr<net::StreamPtr> read_client_stream =
            std::move(std::get<0>(tp));
        seastar::foreign_ptr<net::StreamPtr> read_server_stream =
            std::move(std::get<1>(tp));
        // read data by service interface
        std::unique_ptr<ReadExtentReq> read_req(new ReadExtentReq);
        read_req->mutable_base()->set_reqid("1234567");
        read_req->set_diskid(1);
        read_req->set_extent_id(std::string(str_extent_id, 16));
        read_req->set_off(offs[i]);
        read_req->set_len(lens[i]);

        LOG_INFO("begin read i={} off={} len={}", i, read_req->off(),
                 read_req->len());
        auto stat = seastar::memory::stats();
        LOG_INFO(
            "total_memory={}, free_memory={}, cross_cpu_frees={}, "
            "foreign_mallocs={}, "
            "foreign_frees={}, foreign_cross_frees={}",
            stat.total_memory(), stat.free_memory(), stat.cross_cpu_frees(),
            stat.foreign_mallocs(), stat.foreign_frees(),
            stat.foreign_cross_frees());
        auto fu = service.HandleReadExtent(read_req.get(),
                                           std::move(read_server_stream));

        auto st2 =
            seastar::smp::submit_to(1, [stream = read_client_stream.get()] {
                return stream->ReadFrame();
            }).get0();
        BOOST_REQUIRE(st2);
        TmpBuffer read_buf = std::move(st2.Value());
        std::unique_ptr<ReadExtentResp> read_resp(new ReadExtentResp);
        ExtentnodeMsgType type;
        BOOST_REQUIRE(ParseResponse(read_buf.get(), read_buf.size(),
                                    read_resp.get(), type));
        BOOST_REQUIRE(type == ExtentnodeMsgType::READ_EXTENT_RESP);
        BOOST_REQUIRE(read_resp->base().code() ==
                      static_cast<int>(ErrCode::OK));
        BOOST_REQUIRE(read_resp->len() == lens[i]);
        // read data
        size_t read_len = 0;
        bool first = true;
        size_t first_block_len = kBlockDataSize - offs[i] % kBlockDataSize;
        while (read_len < read_resp->len()) {
            auto st3 =
                seastar::smp::submit_to(
                    1,
                    [stream = read_client_stream.get()]()
                        -> seastar::future<Status<
                            seastar::foreign_ptr<std::unique_ptr<TmpBuffer>>>> {
                        Status<seastar::foreign_ptr<std::unique_ptr<TmpBuffer>>>
                            s;
                        auto st = co_await stream->ReadFrame();
                        if (!st) {
                            s.Set(st.Code(), st.Reason());
                        } else {
                            s.SetValue(seastar::make_foreign(
                                std::make_unique<TmpBuffer>(
                                    std::move(st.Value()))));
                        }
                        co_return s;
                    })
                    .get0();
            if (st3.Code() == ErrCode::ErrEOF) {
                break;
            }
            BOOST_REQUIRE(st3);
            TmpBuffer b = std::move(st3.Value()->share());
            size_t data_len = b.size();
            const char* p = b.get();
            while (p < b.end()) {
                size_t n = std::min(kBlockSize, (size_t)(b.end() - p));
                if (first) {
                    n = first_block_len + 4;
                    first = false;
                }
                read_len += n - 4;
                uint32_t origin_crc = net::BigEndian::Uint32(p + n - 4);
                uint32_t crc =
                    crc32_gzip_refl(0, (const unsigned char*)p, n - 4);
                BOOST_REQUIRE_EQUAL(origin_crc, crc);
                p += n;
            }
        }
        BOOST_REQUIRE_EQUAL(read_len, read_resp->len());
        fu.get0();
    }

    store->Close().get();
}

}  // namespace stream
}  // namespace snail