// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: src/algorithm_service.proto
// Protobuf C++ Version: 5.29.0

#include "src/algorithm_service.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace algorithm {

inline constexpr AlgorithmResponse::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : json_output_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR AlgorithmResponse::AlgorithmResponse(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct AlgorithmResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AlgorithmResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AlgorithmResponseDefaultTypeInternal() {}
  union {
    AlgorithmResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AlgorithmResponseDefaultTypeInternal _AlgorithmResponse_default_instance_;

inline constexpr AlgorithmRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : json_input_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR AlgorithmRequest::AlgorithmRequest(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct AlgorithmRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AlgorithmRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AlgorithmRequestDefaultTypeInternal() {}
  union {
    AlgorithmRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AlgorithmRequestDefaultTypeInternal _AlgorithmRequest_default_instance_;
}  // namespace algorithm
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_src_2falgorithm_5fservice_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_src_2falgorithm_5fservice_2eproto = nullptr;
const ::uint32_t
    TableStruct_src_2falgorithm_5fservice_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::algorithm::AlgorithmRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::algorithm::AlgorithmRequest, _impl_.json_input_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::algorithm::AlgorithmResponse, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::algorithm::AlgorithmResponse, _impl_.json_output_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::algorithm::AlgorithmRequest)},
        {9, -1, -1, sizeof(::algorithm::AlgorithmResponse)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::algorithm::_AlgorithmRequest_default_instance_._instance,
    &::algorithm::_AlgorithmResponse_default_instance_._instance,
};
const char descriptor_table_protodef_src_2falgorithm_5fservice_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\033src/algorithm_service.proto\022\talgorithm"
    "\"&\n\020AlgorithmRequest\022\022\n\njson_input\030\001 \001(\t"
    "\"(\n\021AlgorithmResponse\022\023\n\013json_output\030\001 \001"
    "(\t2\355\001\n\020AlgorithmService\022C\n\006DbScan\022\033.algo"
    "rithm.AlgorithmRequest\032\034.algorithm.Algor"
    "ithmResponse\022G\n\nconvexHull\022\033.algorithm.A"
    "lgorithmRequest\032\034.algorithm.AlgorithmRes"
    "ponse\022K\n\016PointInPolygon\022\033.algorithm.Algo"
    "rithmRequest\032\034.algorithm.AlgorithmRespon"
    "seb\006proto3"
};
static ::absl::once_flag descriptor_table_src_2falgorithm_5fservice_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_src_2falgorithm_5fservice_2eproto = {
    false,
    false,
    370,
    descriptor_table_protodef_src_2falgorithm_5fservice_2eproto,
    "src/algorithm_service.proto",
    &descriptor_table_src_2falgorithm_5fservice_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_src_2falgorithm_5fservice_2eproto::offsets,
    file_level_enum_descriptors_src_2falgorithm_5fservice_2eproto,
    file_level_service_descriptors_src_2falgorithm_5fservice_2eproto,
};
namespace algorithm {
// ===================================================================

class AlgorithmRequest::_Internal {
 public:
};

AlgorithmRequest::AlgorithmRequest(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:algorithm.AlgorithmRequest)
}
inline PROTOBUF_NDEBUG_INLINE AlgorithmRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::algorithm::AlgorithmRequest& from_msg)
      : json_input_(arena, from.json_input_),
        _cached_size_{0} {}

AlgorithmRequest::AlgorithmRequest(
    ::google::protobuf::Arena* arena,
    const AlgorithmRequest& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  AlgorithmRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:algorithm.AlgorithmRequest)
}
inline PROTOBUF_NDEBUG_INLINE AlgorithmRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : json_input_(arena),
        _cached_size_{0} {}

inline void AlgorithmRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
AlgorithmRequest::~AlgorithmRequest() {
  // @@protoc_insertion_point(destructor:algorithm.AlgorithmRequest)
  SharedDtor(*this);
}
inline void AlgorithmRequest::SharedDtor(MessageLite& self) {
  AlgorithmRequest& this_ = static_cast<AlgorithmRequest&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.json_input_.Destroy();
  this_._impl_.~Impl_();
}

inline void* AlgorithmRequest::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) AlgorithmRequest(arena);
}
constexpr auto AlgorithmRequest::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(AlgorithmRequest),
                                            alignof(AlgorithmRequest));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull AlgorithmRequest::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_AlgorithmRequest_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &AlgorithmRequest::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<AlgorithmRequest>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &AlgorithmRequest::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<AlgorithmRequest>(), &AlgorithmRequest::ByteSizeLong,
            &AlgorithmRequest::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(AlgorithmRequest, _impl_._cached_size_),
        false,
    },
    &AlgorithmRequest::kDescriptorMethods,
    &descriptor_table_src_2falgorithm_5fservice_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* AlgorithmRequest::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 45, 2> AlgorithmRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::algorithm::AlgorithmRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string json_input = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(AlgorithmRequest, _impl_.json_input_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string json_input = 1;
    {PROTOBUF_FIELD_OFFSET(AlgorithmRequest, _impl_.json_input_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\32\12\0\0\0\0\0\0"
    "algorithm.AlgorithmRequest"
    "json_input"
  }},
};

PROTOBUF_NOINLINE void AlgorithmRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:algorithm.AlgorithmRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.json_input_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* AlgorithmRequest::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const AlgorithmRequest& this_ = static_cast<const AlgorithmRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* AlgorithmRequest::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const AlgorithmRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:algorithm.AlgorithmRequest)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string json_input = 1;
          if (!this_._internal_json_input().empty()) {
            const std::string& _s = this_._internal_json_input();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "algorithm.AlgorithmRequest.json_input");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:algorithm.AlgorithmRequest)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t AlgorithmRequest::ByteSizeLong(const MessageLite& base) {
          const AlgorithmRequest& this_ = static_cast<const AlgorithmRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t AlgorithmRequest::ByteSizeLong() const {
          const AlgorithmRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:algorithm.AlgorithmRequest)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // string json_input = 1;
            if (!this_._internal_json_input().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_json_input());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void AlgorithmRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AlgorithmRequest*>(&to_msg);
  auto& from = static_cast<const AlgorithmRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:algorithm.AlgorithmRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_json_input().empty()) {
    _this->_internal_set_json_input(from._internal_json_input());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AlgorithmRequest::CopyFrom(const AlgorithmRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:algorithm.AlgorithmRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void AlgorithmRequest::InternalSwap(AlgorithmRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.json_input_, &other->_impl_.json_input_, arena);
}

::google::protobuf::Metadata AlgorithmRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class AlgorithmResponse::_Internal {
 public:
};

AlgorithmResponse::AlgorithmResponse(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:algorithm.AlgorithmResponse)
}
inline PROTOBUF_NDEBUG_INLINE AlgorithmResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::algorithm::AlgorithmResponse& from_msg)
      : json_output_(arena, from.json_output_),
        _cached_size_{0} {}

AlgorithmResponse::AlgorithmResponse(
    ::google::protobuf::Arena* arena,
    const AlgorithmResponse& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  AlgorithmResponse* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:algorithm.AlgorithmResponse)
}
inline PROTOBUF_NDEBUG_INLINE AlgorithmResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : json_output_(arena),
        _cached_size_{0} {}

inline void AlgorithmResponse::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
AlgorithmResponse::~AlgorithmResponse() {
  // @@protoc_insertion_point(destructor:algorithm.AlgorithmResponse)
  SharedDtor(*this);
}
inline void AlgorithmResponse::SharedDtor(MessageLite& self) {
  AlgorithmResponse& this_ = static_cast<AlgorithmResponse&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.json_output_.Destroy();
  this_._impl_.~Impl_();
}

inline void* AlgorithmResponse::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) AlgorithmResponse(arena);
}
constexpr auto AlgorithmResponse::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(AlgorithmResponse),
                                            alignof(AlgorithmResponse));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull AlgorithmResponse::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_AlgorithmResponse_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &AlgorithmResponse::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<AlgorithmResponse>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &AlgorithmResponse::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<AlgorithmResponse>(), &AlgorithmResponse::ByteSizeLong,
            &AlgorithmResponse::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(AlgorithmResponse, _impl_._cached_size_),
        false,
    },
    &AlgorithmResponse::kDescriptorMethods,
    &descriptor_table_src_2falgorithm_5fservice_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* AlgorithmResponse::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 47, 2> AlgorithmResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::algorithm::AlgorithmResponse>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string json_output = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(AlgorithmResponse, _impl_.json_output_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string json_output = 1;
    {PROTOBUF_FIELD_OFFSET(AlgorithmResponse, _impl_.json_output_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\33\13\0\0\0\0\0\0"
    "algorithm.AlgorithmResponse"
    "json_output"
  }},
};

PROTOBUF_NOINLINE void AlgorithmResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:algorithm.AlgorithmResponse)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.json_output_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* AlgorithmResponse::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const AlgorithmResponse& this_ = static_cast<const AlgorithmResponse&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* AlgorithmResponse::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const AlgorithmResponse& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:algorithm.AlgorithmResponse)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string json_output = 1;
          if (!this_._internal_json_output().empty()) {
            const std::string& _s = this_._internal_json_output();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "algorithm.AlgorithmResponse.json_output");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:algorithm.AlgorithmResponse)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t AlgorithmResponse::ByteSizeLong(const MessageLite& base) {
          const AlgorithmResponse& this_ = static_cast<const AlgorithmResponse&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t AlgorithmResponse::ByteSizeLong() const {
          const AlgorithmResponse& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:algorithm.AlgorithmResponse)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // string json_output = 1;
            if (!this_._internal_json_output().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_json_output());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void AlgorithmResponse::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AlgorithmResponse*>(&to_msg);
  auto& from = static_cast<const AlgorithmResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:algorithm.AlgorithmResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_json_output().empty()) {
    _this->_internal_set_json_output(from._internal_json_output());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AlgorithmResponse::CopyFrom(const AlgorithmResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:algorithm.AlgorithmResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void AlgorithmResponse::InternalSwap(AlgorithmResponse* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.json_output_, &other->_impl_.json_output_, arena);
}

::google::protobuf::Metadata AlgorithmResponse::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace algorithm
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_src_2falgorithm_5fservice_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
