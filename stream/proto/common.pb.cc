// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common.proto

#include "proto/common.pb.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
#include <google/protobuf/wire_format_lite.h>

#include <algorithm>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace snail {
namespace stream {
PROTOBUF_CONSTEXPR
CommonReq_HeadersEntry_DoNotUse::CommonReq_HeadersEntry_DoNotUse(
    ::_pbi::ConstantInitialized) {}
struct CommonReq_HeadersEntry_DoNotUseDefaultTypeInternal {
    PROTOBUF_CONSTEXPR CommonReq_HeadersEntry_DoNotUseDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~CommonReq_HeadersEntry_DoNotUseDefaultTypeInternal() {}
    union {
        CommonReq_HeadersEntry_DoNotUse _instance;
    };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
        CommonReq_HeadersEntry_DoNotUseDefaultTypeInternal
            _CommonReq_HeadersEntry_DoNotUse_default_instance_;
PROTOBUF_CONSTEXPR CommonReq::CommonReq(::_pbi::ConstantInitialized)
    : _impl_{
          /*decltype(_impl_.headers_)*/ {::_pbi::ConstantInitialized()},
          /*decltype(_impl_.reqid_)*/
          {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}},
          /*decltype(_impl_._cached_size_)*/ {}} {}
struct CommonReqDefaultTypeInternal {
    PROTOBUF_CONSTEXPR CommonReqDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~CommonReqDefaultTypeInternal() {}
    union {
        CommonReq _instance;
    };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CommonReqDefaultTypeInternal
        _CommonReq_default_instance_;
PROTOBUF_CONSTEXPR
CommonResp_HeadersEntry_DoNotUse::CommonResp_HeadersEntry_DoNotUse(
    ::_pbi::ConstantInitialized) {}
struct CommonResp_HeadersEntry_DoNotUseDefaultTypeInternal {
    PROTOBUF_CONSTEXPR CommonResp_HeadersEntry_DoNotUseDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~CommonResp_HeadersEntry_DoNotUseDefaultTypeInternal() {}
    union {
        CommonResp_HeadersEntry_DoNotUse _instance;
    };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
        CommonResp_HeadersEntry_DoNotUseDefaultTypeInternal
            _CommonResp_HeadersEntry_DoNotUse_default_instance_;
PROTOBUF_CONSTEXPR CommonResp::CommonResp(::_pbi::ConstantInitialized)
    : _impl_{
          /*decltype(_impl_.headers_)*/ {::_pbi::ConstantInitialized()},
          /*decltype(_impl_.reqid_)*/
          {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}},
          /*decltype(_impl_.reason_)*/
          {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}},
          /*decltype(_impl_.code_)*/ 0,
          /*decltype(_impl_._cached_size_)*/ {}} {}
struct CommonRespDefaultTypeInternal {
    PROTOBUF_CONSTEXPR CommonRespDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~CommonRespDefaultTypeInternal() {}
    union {
        CommonResp _instance;
    };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CommonRespDefaultTypeInternal
        _CommonResp_default_instance_;
}  // namespace stream
}  // namespace snail
static ::_pb::Metadata file_level_metadata_common_2eproto[4];
static constexpr ::_pb::EnumDescriptor const**
    file_level_enum_descriptors_common_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const**
    file_level_service_descriptors_common_2eproto = nullptr;

const uint32_t TableStruct_common_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq_HeadersEntry_DoNotUse,
                          _has_bits_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq_HeadersEntry_DoNotUse,
                          _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq_HeadersEntry_DoNotUse,
                          key_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq_HeadersEntry_DoNotUse,
                          value_),
    0,
    1,
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq, _impl_.reqid_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonReq, _impl_.headers_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp_HeadersEntry_DoNotUse,
                          _has_bits_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp_HeadersEntry_DoNotUse,
                          _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp_HeadersEntry_DoNotUse,
                          key_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp_HeadersEntry_DoNotUse,
                          value_),
    0,
    1,
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp, _impl_.reqid_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp, _impl_.code_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp, _impl_.reason_),
    PROTOBUF_FIELD_OFFSET(::snail::stream::CommonResp, _impl_.headers_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    {0, 8, -1, sizeof(::snail::stream::CommonReq_HeadersEntry_DoNotUse)},
    {10, -1, -1, sizeof(::snail::stream::CommonReq)},
    {18, 26, -1, sizeof(::snail::stream::CommonResp_HeadersEntry_DoNotUse)},
    {28, -1, -1, sizeof(::snail::stream::CommonResp)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::snail::stream::_CommonReq_HeadersEntry_DoNotUse_default_instance_
         ._instance,
    &::snail::stream::_CommonReq_default_instance_._instance,
    &::snail::stream::_CommonResp_HeadersEntry_DoNotUse_default_instance_
         ._instance,
    &::snail::stream::_CommonResp_default_instance_._instance,
};

const char descriptor_table_protodef_common_2eproto[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) =
    "\n\014common.proto\022\014snail.stream\"\201\001\n\tCommonR"
    "eq\022\r\n\005reqid\030\001 \001(\t\0225\n\007headers\030\002 "
    "\003(\0132$.sna"
    "il.stream.CommonReq.HeadersEntry\032.\n\014Head"
    "ersEntry\022\013\n\003key\030\001 \001(\t\022\r\n\005value\030\002 "
    "\001(\t:\0028\001"
    "\"\241\001\n\nCommonResp\022\r\n\005reqid\030\001 "
    "\001(\t\022\014\n\004code\030\002"
    " \001(\005\022\016\n\006reason\030\003 \001(\t\0226\n\007headers\030\004 "
    "\003(\0132%."
    "snail.stream.CommonResp.HeadersEntry\032.\n\014"
    "HeadersEntry\022\013\n\003key\030\001 \001(\t\022\r\n\005value\030\002 "
    "\001(\t"
    ":\0028\001b\006proto3";
static ::_pbi::once_flag descriptor_table_common_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_common_2eproto = {
    false,
    false,
    332,
    descriptor_table_protodef_common_2eproto,
    "common.proto",
    &descriptor_table_common_2eproto_once,
    nullptr,
    0,
    4,
    schemas,
    file_default_instances,
    TableStruct_common_2eproto::offsets,
    file_level_metadata_common_2eproto,
    file_level_enum_descriptors_common_2eproto,
    file_level_service_descriptors_common_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable*
descriptor_table_common_2eproto_getter() {
    return &descriptor_table_common_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner
    dynamic_init_dummy_common_2eproto(&descriptor_table_common_2eproto);
namespace snail {
namespace stream {

// ===================================================================

CommonReq_HeadersEntry_DoNotUse::CommonReq_HeadersEntry_DoNotUse() {}
CommonReq_HeadersEntry_DoNotUse::CommonReq_HeadersEntry_DoNotUse(
    ::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void CommonReq_HeadersEntry_DoNotUse::MergeFrom(
    const CommonReq_HeadersEntry_DoNotUse& other) {
    MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata CommonReq_HeadersEntry_DoNotUse::GetMetadata()
    const {
    return ::_pbi::AssignDescriptors(&descriptor_table_common_2eproto_getter,
                                     &descriptor_table_common_2eproto_once,
                                     file_level_metadata_common_2eproto[0]);
}

// ===================================================================

class CommonReq::_Internal {
   public:
};

CommonReq::CommonReq(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                     bool is_message_owned)
    : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
    SharedCtor(arena, is_message_owned);
    if (arena != nullptr && !is_message_owned) {
        arena->OwnCustomDestructor(this, &CommonReq::ArenaDtor);
    }
    // @@protoc_insertion_point(arena_constructor:snail.stream.CommonReq)
}
CommonReq::CommonReq(const CommonReq& from)
    : ::PROTOBUF_NAMESPACE_ID::Message() {
    CommonReq* const _this = this;
    (void)_this;
    new (&_impl_)
        Impl_{/*decltype(_impl_.headers_)*/ {}, decltype(_impl_.reqid_){},
              /*decltype(_impl_._cached_size_)*/ {}};

    _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
        from._internal_metadata_);
    _this->_impl_.headers_.MergeFrom(from._impl_.headers_);
    _impl_.reqid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reqid_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_reqid().empty()) {
        _this->_impl_.reqid_.Set(from._internal_reqid(),
                                 _this->GetArenaForAllocation());
    }
    // @@protoc_insertion_point(copy_constructor:snail.stream.CommonReq)
}

inline void CommonReq::SharedCtor(::_pb::Arena* arena, bool is_message_owned) {
    (void)arena;
    (void)is_message_owned;
    new (&_impl_)
        Impl_{/*decltype(_impl_.headers_)*/ {::_pbi::ArenaInitialized(), arena},
              decltype(_impl_.reqid_){}, /*decltype(_impl_._cached_size_)*/ {}};
    _impl_.reqid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reqid_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

CommonReq::~CommonReq() {
    // @@protoc_insertion_point(destructor:snail.stream.CommonReq)
    if (auto* arena = _internal_metadata_.DeleteReturnArena<
                      ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
        (void)arena;
        ArenaDtor(this);
        return;
    }
    SharedDtor();
}

inline void CommonReq::SharedDtor() {
    GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
    _impl_.headers_.Destruct();
    _impl_.headers_.~MapField();
    _impl_.reqid_.Destroy();
}

void CommonReq::ArenaDtor(void* object) {
    CommonReq* _this = reinterpret_cast<CommonReq*>(object);
    _this->_impl_.headers_.Destruct();
}
void CommonReq::SetCachedSize(int size) const {
    _impl_._cached_size_.Set(size);
}

void CommonReq::Clear() {
    // @@protoc_insertion_point(message_clear_start:snail.stream.CommonReq)
    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    _impl_.headers_.Clear();
    _impl_.reqid_.ClearToEmpty();
    _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CommonReq::_InternalParse(const char* ptr,
                                      ::_pbi::ParseContext* ctx) {
#define CHK_(x) \
    if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
    while (!ctx->Done(&ptr)) {
        uint32_t tag;
        ptr = ::_pbi::ReadTag(ptr, &tag);
        switch (tag >> 3) {
            // string reqid = 1;
            case 1:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
                    auto str = _internal_mutable_reqid();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
                    CHK_(::_pbi::VerifyUTF8(str,
                                            "snail.stream.CommonReq.reqid"));
                } else
                    goto handle_unusual;
                continue;
            // map<string, string> headers = 2;
            case 2:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
                    ptr -= 1;
                    do {
                        ptr += 1;
                        ptr = ctx->ParseMessage(&_impl_.headers_, ptr);
                        CHK_(ptr);
                        if (!ctx->DataAvailable(ptr)) break;
                    } while (
                        ::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
                } else
                    goto handle_unusual;
                continue;
            default:
                goto handle_unusual;
        }  // switch
    handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
            CHK_(ptr);
            ctx->SetLastTag(tag);
            goto message_done;
        }
        ptr = UnknownFieldParse(tag,
                                _internal_metadata_.mutable_unknown_fields<
                                    ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
                                ptr, ctx);
        CHK_(ptr != nullptr);
    }  // while
message_done:
    return ptr;
failure:
    ptr = nullptr;
    goto message_done;
#undef CHK_
}

uint8_t* CommonReq::_InternalSerialize(
    uint8_t* target,
    ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
    // @@protoc_insertion_point(serialize_to_array_start:snail.stream.CommonReq)
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    // string reqid = 1;
    if (!this->_internal_reqid().empty()) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->_internal_reqid().data(),
            static_cast<int>(this->_internal_reqid().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
            "snail.stream.CommonReq.reqid");
        target =
            stream->WriteStringMaybeAliased(1, this->_internal_reqid(), target);
    }

    // map<string, string> headers = 2;
    if (!this->_internal_headers().empty()) {
        using MapType = ::_pb::Map<std::string, std::string>;
        using WireHelper = CommonReq_HeadersEntry_DoNotUse::Funcs;
        const auto& map_field = this->_internal_headers();
        auto check_utf8 = [](const MapType::value_type& entry) {
            (void)entry;
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
                entry.first.data(), static_cast<int>(entry.first.length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
                "snail.stream.CommonReq.HeadersEntry.key");
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
                entry.second.data(), static_cast<int>(entry.second.length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
                "snail.stream.CommonReq.HeadersEntry.value");
        };

        if (stream->IsSerializationDeterministic() && map_field.size() > 1) {
            for (const auto& entry : ::_pbi::MapSorterPtr<MapType>(map_field)) {
                target = WireHelper::InternalSerialize(
                    2, entry.first, entry.second, target, stream);
                check_utf8(entry);
            }
        } else {
            for (const auto& entry : map_field) {
                target = WireHelper::InternalSerialize(
                    2, entry.first, entry.second, target, stream);
                check_utf8(entry);
            }
        }
    }

    if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
        target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_
                .unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
                    ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance),
            target, stream);
    }
    // @@protoc_insertion_point(serialize_to_array_end:snail.stream.CommonReq)
    return target;
}

size_t CommonReq::ByteSizeLong() const {
    // @@protoc_insertion_point(message_byte_size_start:snail.stream.CommonReq)
    size_t total_size = 0;

    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // map<string, string> headers = 2;
    total_size += 1 * ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(
                          this->_internal_headers_size());
    for (::PROTOBUF_NAMESPACE_ID::Map<std::string, std::string>::const_iterator
             it = this->_internal_headers().begin();
         it != this->_internal_headers().end(); ++it) {
        total_size += CommonReq_HeadersEntry_DoNotUse::Funcs::ByteSizeLong(
            it->first, it->second);
    }

    // string reqid = 1;
    if (!this->_internal_reqid().empty()) {
        total_size +=
            1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_reqid());
    }

    return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CommonReq::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CommonReq::MergeImpl};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* CommonReq::GetClassData()
    const {
    return &_class_data_;
}

void CommonReq::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg,
                          const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
    auto* const _this = static_cast<CommonReq*>(&to_msg);
    auto& from = static_cast<const CommonReq&>(from_msg);
    // @@protoc_insertion_point(class_specific_merge_from_start:snail.stream.CommonReq)
    GOOGLE_DCHECK_NE(&from, _this);
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    _this->_impl_.headers_.MergeFrom(from._impl_.headers_);
    if (!from._internal_reqid().empty()) {
        _this->_internal_set_reqid(from._internal_reqid());
    }
    _this->_internal_metadata_
        .MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
            from._internal_metadata_);
}

void CommonReq::CopyFrom(const CommonReq& from) {
    // @@protoc_insertion_point(class_specific_copy_from_start:snail.stream.CommonReq)
    if (&from == this) return;
    Clear();
    MergeFrom(from);
}

bool CommonReq::IsInitialized() const { return true; }

void CommonReq::InternalSwap(CommonReq* other) {
    using std::swap;
    auto* lhs_arena = GetArenaForAllocation();
    auto* rhs_arena = other->GetArenaForAllocation();
    _internal_metadata_.InternalSwap(&other->_internal_metadata_);
    _impl_.headers_.InternalSwap(&other->_impl_.headers_);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.reqid_, lhs_arena, &other->_impl_.reqid_, rhs_arena);
}

::PROTOBUF_NAMESPACE_ID::Metadata CommonReq::GetMetadata() const {
    return ::_pbi::AssignDescriptors(&descriptor_table_common_2eproto_getter,
                                     &descriptor_table_common_2eproto_once,
                                     file_level_metadata_common_2eproto[1]);
}

// ===================================================================

CommonResp_HeadersEntry_DoNotUse::CommonResp_HeadersEntry_DoNotUse() {}
CommonResp_HeadersEntry_DoNotUse::CommonResp_HeadersEntry_DoNotUse(
    ::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void CommonResp_HeadersEntry_DoNotUse::MergeFrom(
    const CommonResp_HeadersEntry_DoNotUse& other) {
    MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata
CommonResp_HeadersEntry_DoNotUse::GetMetadata() const {
    return ::_pbi::AssignDescriptors(&descriptor_table_common_2eproto_getter,
                                     &descriptor_table_common_2eproto_once,
                                     file_level_metadata_common_2eproto[2]);
}

// ===================================================================

class CommonResp::_Internal {
   public:
};

CommonResp::CommonResp(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned)
    : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
    SharedCtor(arena, is_message_owned);
    if (arena != nullptr && !is_message_owned) {
        arena->OwnCustomDestructor(this, &CommonResp::ArenaDtor);
    }
    // @@protoc_insertion_point(arena_constructor:snail.stream.CommonResp)
}
CommonResp::CommonResp(const CommonResp& from)
    : ::PROTOBUF_NAMESPACE_ID::Message() {
    CommonResp* const _this = this;
    (void)_this;
    new (&_impl_)
        Impl_{/*decltype(_impl_.headers_)*/ {}, decltype(_impl_.reqid_){},
              decltype(_impl_.reason_){}, decltype(_impl_.code_){},
              /*decltype(_impl_._cached_size_)*/ {}};

    _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
        from._internal_metadata_);
    _this->_impl_.headers_.MergeFrom(from._impl_.headers_);
    _impl_.reqid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reqid_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_reqid().empty()) {
        _this->_impl_.reqid_.Set(from._internal_reqid(),
                                 _this->GetArenaForAllocation());
    }
    _impl_.reason_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reason_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_reason().empty()) {
        _this->_impl_.reason_.Set(from._internal_reason(),
                                  _this->GetArenaForAllocation());
    }
    _this->_impl_.code_ = from._impl_.code_;
    // @@protoc_insertion_point(copy_constructor:snail.stream.CommonResp)
}

inline void CommonResp::SharedCtor(::_pb::Arena* arena, bool is_message_owned) {
    (void)arena;
    (void)is_message_owned;
    new (&_impl_)
        Impl_{/*decltype(_impl_.headers_)*/ {::_pbi::ArenaInitialized(), arena},
              decltype(_impl_.reqid_){}, decltype(_impl_.reason_){},
              decltype(_impl_.code_){0}, /*decltype(_impl_._cached_size_)*/ {}};
    _impl_.reqid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reqid_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reason_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.reason_.Set("", GetArenaForAllocation());
#endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

CommonResp::~CommonResp() {
    // @@protoc_insertion_point(destructor:snail.stream.CommonResp)
    if (auto* arena = _internal_metadata_.DeleteReturnArena<
                      ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
        (void)arena;
        ArenaDtor(this);
        return;
    }
    SharedDtor();
}

inline void CommonResp::SharedDtor() {
    GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
    _impl_.headers_.Destruct();
    _impl_.headers_.~MapField();
    _impl_.reqid_.Destroy();
    _impl_.reason_.Destroy();
}

void CommonResp::ArenaDtor(void* object) {
    CommonResp* _this = reinterpret_cast<CommonResp*>(object);
    _this->_impl_.headers_.Destruct();
}
void CommonResp::SetCachedSize(int size) const {
    _impl_._cached_size_.Set(size);
}

void CommonResp::Clear() {
    // @@protoc_insertion_point(message_clear_start:snail.stream.CommonResp)
    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    _impl_.headers_.Clear();
    _impl_.reqid_.ClearToEmpty();
    _impl_.reason_.ClearToEmpty();
    _impl_.code_ = 0;
    _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CommonResp::_InternalParse(const char* ptr,
                                       ::_pbi::ParseContext* ctx) {
#define CHK_(x) \
    if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
    while (!ctx->Done(&ptr)) {
        uint32_t tag;
        ptr = ::_pbi::ReadTag(ptr, &tag);
        switch (tag >> 3) {
            // string reqid = 1;
            case 1:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
                    auto str = _internal_mutable_reqid();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
                    CHK_(::_pbi::VerifyUTF8(str,
                                            "snail.stream.CommonResp.reqid"));
                } else
                    goto handle_unusual;
                continue;
            // int32 code = 2;
            case 2:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
                    _impl_.code_ =
                        ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
                    CHK_(ptr);
                } else
                    goto handle_unusual;
                continue;
            // string reason = 3;
            case 3:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
                    auto str = _internal_mutable_reason();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
                    CHK_(::_pbi::VerifyUTF8(str,
                                            "snail.stream.CommonResp.reason"));
                } else
                    goto handle_unusual;
                continue;
            // map<string, string> headers = 4;
            case 4:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
                    ptr -= 1;
                    do {
                        ptr += 1;
                        ptr = ctx->ParseMessage(&_impl_.headers_, ptr);
                        CHK_(ptr);
                        if (!ctx->DataAvailable(ptr)) break;
                    } while (
                        ::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
                } else
                    goto handle_unusual;
                continue;
            default:
                goto handle_unusual;
        }  // switch
    handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
            CHK_(ptr);
            ctx->SetLastTag(tag);
            goto message_done;
        }
        ptr = UnknownFieldParse(tag,
                                _internal_metadata_.mutable_unknown_fields<
                                    ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
                                ptr, ctx);
        CHK_(ptr != nullptr);
    }  // while
message_done:
    return ptr;
failure:
    ptr = nullptr;
    goto message_done;
#undef CHK_
}

uint8_t* CommonResp::_InternalSerialize(
    uint8_t* target,
    ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
    // @@protoc_insertion_point(serialize_to_array_start:snail.stream.CommonResp)
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    // string reqid = 1;
    if (!this->_internal_reqid().empty()) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->_internal_reqid().data(),
            static_cast<int>(this->_internal_reqid().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
            "snail.stream.CommonResp.reqid");
        target =
            stream->WriteStringMaybeAliased(1, this->_internal_reqid(), target);
    }

    // int32 code = 2;
    if (this->_internal_code() != 0) {
        target = stream->EnsureSpace(target);
        target = ::_pbi::WireFormatLite::WriteInt32ToArray(
            2, this->_internal_code(), target);
    }

    // string reason = 3;
    if (!this->_internal_reason().empty()) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->_internal_reason().data(),
            static_cast<int>(this->_internal_reason().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
            "snail.stream.CommonResp.reason");
        target = stream->WriteStringMaybeAliased(3, this->_internal_reason(),
                                                 target);
    }

    // map<string, string> headers = 4;
    if (!this->_internal_headers().empty()) {
        using MapType = ::_pb::Map<std::string, std::string>;
        using WireHelper = CommonResp_HeadersEntry_DoNotUse::Funcs;
        const auto& map_field = this->_internal_headers();
        auto check_utf8 = [](const MapType::value_type& entry) {
            (void)entry;
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
                entry.first.data(), static_cast<int>(entry.first.length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
                "snail.stream.CommonResp.HeadersEntry.key");
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
                entry.second.data(), static_cast<int>(entry.second.length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
                "snail.stream.CommonResp.HeadersEntry.value");
        };

        if (stream->IsSerializationDeterministic() && map_field.size() > 1) {
            for (const auto& entry : ::_pbi::MapSorterPtr<MapType>(map_field)) {
                target = WireHelper::InternalSerialize(
                    4, entry.first, entry.second, target, stream);
                check_utf8(entry);
            }
        } else {
            for (const auto& entry : map_field) {
                target = WireHelper::InternalSerialize(
                    4, entry.first, entry.second, target, stream);
                check_utf8(entry);
            }
        }
    }

    if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
        target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_
                .unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
                    ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance),
            target, stream);
    }
    // @@protoc_insertion_point(serialize_to_array_end:snail.stream.CommonResp)
    return target;
}

size_t CommonResp::ByteSizeLong() const {
    // @@protoc_insertion_point(message_byte_size_start:snail.stream.CommonResp)
    size_t total_size = 0;

    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // map<string, string> headers = 4;
    total_size += 1 * ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(
                          this->_internal_headers_size());
    for (::PROTOBUF_NAMESPACE_ID::Map<std::string, std::string>::const_iterator
             it = this->_internal_headers().begin();
         it != this->_internal_headers().end(); ++it) {
        total_size += CommonResp_HeadersEntry_DoNotUse::Funcs::ByteSizeLong(
            it->first, it->second);
    }

    // string reqid = 1;
    if (!this->_internal_reqid().empty()) {
        total_size +=
            1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_reqid());
    }

    // string reason = 3;
    if (!this->_internal_reason().empty()) {
        total_size +=
            1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_reason());
    }

    // int32 code = 2;
    if (this->_internal_code() != 0) {
        total_size +=
            ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_code());
    }

    return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CommonResp::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CommonResp::MergeImpl};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* CommonResp::GetClassData()
    const {
    return &_class_data_;
}

void CommonResp::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg,
                           const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
    auto* const _this = static_cast<CommonResp*>(&to_msg);
    auto& from = static_cast<const CommonResp&>(from_msg);
    // @@protoc_insertion_point(class_specific_merge_from_start:snail.stream.CommonResp)
    GOOGLE_DCHECK_NE(&from, _this);
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    _this->_impl_.headers_.MergeFrom(from._impl_.headers_);
    if (!from._internal_reqid().empty()) {
        _this->_internal_set_reqid(from._internal_reqid());
    }
    if (!from._internal_reason().empty()) {
        _this->_internal_set_reason(from._internal_reason());
    }
    if (from._internal_code() != 0) {
        _this->_internal_set_code(from._internal_code());
    }
    _this->_internal_metadata_
        .MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(
            from._internal_metadata_);
}

void CommonResp::CopyFrom(const CommonResp& from) {
    // @@protoc_insertion_point(class_specific_copy_from_start:snail.stream.CommonResp)
    if (&from == this) return;
    Clear();
    MergeFrom(from);
}

bool CommonResp::IsInitialized() const { return true; }

void CommonResp::InternalSwap(CommonResp* other) {
    using std::swap;
    auto* lhs_arena = GetArenaForAllocation();
    auto* rhs_arena = other->GetArenaForAllocation();
    _internal_metadata_.InternalSwap(&other->_internal_metadata_);
    _impl_.headers_.InternalSwap(&other->_impl_.headers_);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.reqid_, lhs_arena, &other->_impl_.reqid_, rhs_arena);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.reason_, lhs_arena, &other->_impl_.reason_, rhs_arena);
    swap(_impl_.code_, other->_impl_.code_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CommonResp::GetMetadata() const {
    return ::_pbi::AssignDescriptors(&descriptor_table_common_2eproto_getter,
                                     &descriptor_table_common_2eproto_once,
                                     file_level_metadata_common_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace stream
}  // namespace snail
PROTOBUF_NAMESPACE_OPEN
template <>
PROTOBUF_NOINLINE ::snail::stream::CommonReq_HeadersEntry_DoNotUse*
Arena::CreateMaybeMessage<::snail::stream::CommonReq_HeadersEntry_DoNotUse>(
    Arena* arena) {
    return Arena::CreateMessageInternal<
        ::snail::stream::CommonReq_HeadersEntry_DoNotUse>(arena);
}
template <>
PROTOBUF_NOINLINE ::snail::stream::CommonReq*
Arena::CreateMaybeMessage<::snail::stream::CommonReq>(Arena* arena) {
    return Arena::CreateMessageInternal<::snail::stream::CommonReq>(arena);
}
template <>
PROTOBUF_NOINLINE ::snail::stream::CommonResp_HeadersEntry_DoNotUse*
Arena::CreateMaybeMessage<::snail::stream::CommonResp_HeadersEntry_DoNotUse>(
    Arena* arena) {
    return Arena::CreateMessageInternal<
        ::snail::stream::CommonResp_HeadersEntry_DoNotUse>(arena);
}
template <>
PROTOBUF_NOINLINE ::snail::stream::CommonResp*
Arena::CreateMaybeMessage<::snail::stream::CommonResp>(Arena* arena) {
    return Arena::CreateMessageInternal<::snail::stream::CommonResp>(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>