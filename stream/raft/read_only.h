#pragma once
#include <deque>
#include <seastar/core/sstring.hh>
#include <seastar/core/temporary_buffer.hh>
#include <unordered_map>

#include "raft_proto.h"
#include "util/util.h"

namespace snail {
namespace raft {

struct ReadState {
    uint64_t index;
    Buffer request_ctx;

    ReadState() : index(0) {}
    ReadState(const ReadState& x) = delete;
    ReadState(ReadState&& x)
        : index(x.index), request_ctx(std::move(x.request_ctx)) {}

    ReadState& operator=(const ReadState& x) = delete;
    ReadState& operator=(ReadState&& x) {
        if (this != &x) {
            index = x.index;
            request_ctx = std::move(x.request_ctx);
        }
        return *this;
    }
};

enum class ReadOnlyOption {
    ReadOnlySafe = 0,
    ReadOnlyLeaseBased = 1,
};

class ReadOnly {
   public:
    struct ReadIndexStatus {
        uint64_t index;
        MessagePtr req;
        std::unordered_map<uint64_t, bool> acks;
        ReadIndexStatus() : index(0) {}
    };
    using ReadIndexStatusPtr = seastar::lw_shared_ptr<ReadIndexStatus>;

    explicit ReadOnly(ReadOnlyOption option) : option_(option) {}

    void AddRequest(uint64_t index, MessagePtr m);

    std::unordered_map<uint64_t, bool> RecvAck(uint64_t id,
                                               const seastar::sstring& context);

    std::vector<ReadIndexStatusPtr> Advance(MessagePtr m);

    seastar::sstring LastPendingRequestCtx();

    void Reset();

    ReadOnlyOption option() const { return option_; }

#ifdef RAFT_UT_TEST
   public:
#else
   private:
#endif
    ReadOnlyOption option_;
    std::unordered_map<seastar::sstring, ReadIndexStatusPtr>
        pending_read_index_;
    std::deque<seastar::sstring> read_index_queue_;
};

}  // namespace raft
}  // namespace snail