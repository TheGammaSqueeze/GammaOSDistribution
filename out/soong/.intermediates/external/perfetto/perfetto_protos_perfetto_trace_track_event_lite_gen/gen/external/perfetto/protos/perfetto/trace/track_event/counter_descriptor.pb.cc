// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/perfetto/trace/track_event/counter_descriptor.proto

#include "protos/perfetto/trace/track_event/counter_descriptor.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace perfetto {
namespace protos {
class CounterDescriptorDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CounterDescriptor> _instance;
} _CounterDescriptor_default_instance_;
}  // namespace protos
}  // namespace perfetto
static void InitDefaultsscc_info_CounterDescriptor_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fcounter_5fdescriptor_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::perfetto::protos::_CounterDescriptor_default_instance_;
    new (ptr) ::perfetto::protos::CounterDescriptor();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::perfetto::protos::CounterDescriptor::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CounterDescriptor_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fcounter_5fdescriptor_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_CounterDescriptor_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fcounter_5fdescriptor_2eproto}, {}};

namespace perfetto {
namespace protos {
bool CounterDescriptor_BuiltinCounterType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> CounterDescriptor_BuiltinCounterType_strings[3] = {};

static const char CounterDescriptor_BuiltinCounterType_names[] =
  "COUNTER_THREAD_INSTRUCTION_COUNT"
  "COUNTER_THREAD_TIME_NS"
  "COUNTER_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry CounterDescriptor_BuiltinCounterType_entries[] = {
  { {CounterDescriptor_BuiltinCounterType_names + 0, 32}, 2 },
  { {CounterDescriptor_BuiltinCounterType_names + 32, 22}, 1 },
  { {CounterDescriptor_BuiltinCounterType_names + 54, 19}, 0 },
};

static const int CounterDescriptor_BuiltinCounterType_entries_by_number[] = {
  2, // 0 -> COUNTER_UNSPECIFIED
  1, // 1 -> COUNTER_THREAD_TIME_NS
  0, // 2 -> COUNTER_THREAD_INSTRUCTION_COUNT
};

const std::string& CounterDescriptor_BuiltinCounterType_Name(
    CounterDescriptor_BuiltinCounterType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          CounterDescriptor_BuiltinCounterType_entries,
          CounterDescriptor_BuiltinCounterType_entries_by_number,
          3, CounterDescriptor_BuiltinCounterType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      CounterDescriptor_BuiltinCounterType_entries,
      CounterDescriptor_BuiltinCounterType_entries_by_number,
      3, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     CounterDescriptor_BuiltinCounterType_strings[idx].get();
}
bool CounterDescriptor_BuiltinCounterType_Parse(
    const std::string& name, CounterDescriptor_BuiltinCounterType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      CounterDescriptor_BuiltinCounterType_entries, 3, name, &int_value);
  if (success) {
    *value = static_cast<CounterDescriptor_BuiltinCounterType>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr CounterDescriptor_BuiltinCounterType CounterDescriptor::COUNTER_UNSPECIFIED;
constexpr CounterDescriptor_BuiltinCounterType CounterDescriptor::COUNTER_THREAD_TIME_NS;
constexpr CounterDescriptor_BuiltinCounterType CounterDescriptor::COUNTER_THREAD_INSTRUCTION_COUNT;
constexpr CounterDescriptor_BuiltinCounterType CounterDescriptor::BuiltinCounterType_MIN;
constexpr CounterDescriptor_BuiltinCounterType CounterDescriptor::BuiltinCounterType_MAX;
constexpr int CounterDescriptor::BuiltinCounterType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
bool CounterDescriptor_Unit_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> CounterDescriptor_Unit_strings[4] = {};

static const char CounterDescriptor_Unit_names[] =
  "UNIT_COUNT"
  "UNIT_SIZE_BYTES"
  "UNIT_TIME_NS"
  "UNIT_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry CounterDescriptor_Unit_entries[] = {
  { {CounterDescriptor_Unit_names + 0, 10}, 2 },
  { {CounterDescriptor_Unit_names + 10, 15}, 3 },
  { {CounterDescriptor_Unit_names + 25, 12}, 1 },
  { {CounterDescriptor_Unit_names + 37, 16}, 0 },
};

static const int CounterDescriptor_Unit_entries_by_number[] = {
  3, // 0 -> UNIT_UNSPECIFIED
  2, // 1 -> UNIT_TIME_NS
  0, // 2 -> UNIT_COUNT
  1, // 3 -> UNIT_SIZE_BYTES
};

const std::string& CounterDescriptor_Unit_Name(
    CounterDescriptor_Unit value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          CounterDescriptor_Unit_entries,
          CounterDescriptor_Unit_entries_by_number,
          4, CounterDescriptor_Unit_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      CounterDescriptor_Unit_entries,
      CounterDescriptor_Unit_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     CounterDescriptor_Unit_strings[idx].get();
}
bool CounterDescriptor_Unit_Parse(
    const std::string& name, CounterDescriptor_Unit* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      CounterDescriptor_Unit_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<CounterDescriptor_Unit>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr CounterDescriptor_Unit CounterDescriptor::UNIT_UNSPECIFIED;
constexpr CounterDescriptor_Unit CounterDescriptor::UNIT_TIME_NS;
constexpr CounterDescriptor_Unit CounterDescriptor::UNIT_COUNT;
constexpr CounterDescriptor_Unit CounterDescriptor::UNIT_SIZE_BYTES;
constexpr CounterDescriptor_Unit CounterDescriptor::Unit_MIN;
constexpr CounterDescriptor_Unit CounterDescriptor::Unit_MAX;
constexpr int CounterDescriptor::Unit_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void CounterDescriptor::InitAsDefaultInstance() {
}
class CounterDescriptor::_Internal {
 public:
  using HasBits = decltype(std::declval<CounterDescriptor>()._has_bits_);
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_unit(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_unit_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_unit_multiplier(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_is_incremental(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

CounterDescriptor::CounterDescriptor()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:perfetto.protos.CounterDescriptor)
}
CounterDescriptor::CounterDescriptor(const CounterDescriptor& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      categories_(from.categories_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  unit_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_unit_name()) {
    unit_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.unit_name_);
  }
  ::memcpy(&type_, &from.type_,
    static_cast<size_t>(reinterpret_cast<char*>(&is_incremental_) -
    reinterpret_cast<char*>(&type_)) + sizeof(is_incremental_));
  // @@protoc_insertion_point(copy_constructor:perfetto.protos.CounterDescriptor)
}

void CounterDescriptor::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CounterDescriptor_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fcounter_5fdescriptor_2eproto.base);
  unit_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&is_incremental_) -
      reinterpret_cast<char*>(&type_)) + sizeof(is_incremental_));
}

CounterDescriptor::~CounterDescriptor() {
  // @@protoc_insertion_point(destructor:perfetto.protos.CounterDescriptor)
  SharedDtor();
}

void CounterDescriptor::SharedDtor() {
  unit_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CounterDescriptor::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CounterDescriptor& CounterDescriptor::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CounterDescriptor_protos_2fperfetto_2ftrace_2ftrack_5fevent_2fcounter_5fdescriptor_2eproto.base);
  return *internal_default_instance();
}


void CounterDescriptor::Clear() {
// @@protoc_insertion_point(message_clear_start:perfetto.protos.CounterDescriptor)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  categories_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    unit_name_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 0x0000001eu) {
    ::memset(&type_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&is_incremental_) -
        reinterpret_cast<char*>(&type_)) + sizeof(is_incremental_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CounterDescriptor::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .perfetto.protos.CounterDescriptor.BuiltinCounterType type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::perfetto::protos::CounterDescriptor_BuiltinCounterType_IsValid(val))) {
            set_type(static_cast<::perfetto::protos::CounterDescriptor_BuiltinCounterType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // repeated string categories = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(add_categories(), ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 18);
        } else goto handle_unusual;
        continue;
      // optional .perfetto.protos.CounterDescriptor.Unit unit = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::perfetto::protos::CounterDescriptor_Unit_IsValid(val))) {
            set_unit(static_cast<::perfetto::protos::CounterDescriptor_Unit>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(3, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional int64 unit_multiplier = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_unit_multiplier(&has_bits);
          unit_multiplier_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool is_incremental = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_is_incremental(&has_bits);
          is_incremental_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string unit_name = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_unit_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool CounterDescriptor::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:perfetto.protos.CounterDescriptor)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .perfetto.protos.CounterDescriptor.BuiltinCounterType type = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::perfetto::protos::CounterDescriptor_BuiltinCounterType_IsValid(value)) {
            set_type(static_cast< ::perfetto::protos::CounterDescriptor_BuiltinCounterType >(value));
          } else {
            unknown_fields_stream.WriteVarint32(8u);
            unknown_fields_stream.WriteVarint32(
                static_cast<::PROTOBUF_NAMESPACE_ID::uint32>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string categories = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->add_categories()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .perfetto.protos.CounterDescriptor.Unit unit = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (24 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::perfetto::protos::CounterDescriptor_Unit_IsValid(value)) {
            set_unit(static_cast< ::perfetto::protos::CounterDescriptor_Unit >(value));
          } else {
            unknown_fields_stream.WriteVarint32(24u);
            unknown_fields_stream.WriteVarint32(
                static_cast<::PROTOBUF_NAMESPACE_ID::uint32>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 unit_multiplier = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (32 & 0xFF)) {
          _Internal::set_has_unit_multiplier(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &unit_multiplier_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool is_incremental = 5;
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (40 & 0xFF)) {
          _Internal::set_has_is_incremental(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   bool, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_incremental_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string unit_name = 6;
      case 6: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (50 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_unit_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:perfetto.protos.CounterDescriptor)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:perfetto.protos.CounterDescriptor)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CounterDescriptor::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:perfetto.protos.CounterDescriptor)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .perfetto.protos.CounterDescriptor.BuiltinCounterType type = 1;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // repeated string categories = 2;
  for (int i = 0, n = this->categories_size(); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteString(
      2, this->categories(i), output);
  }

  // optional .perfetto.protos.CounterDescriptor.Unit unit = 3;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      3, this->unit(), output);
  }

  // optional int64 unit_multiplier = 4;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(4, this->unit_multiplier(), output);
  }

  // optional bool is_incremental = 5;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBool(5, this->is_incremental(), output);
  }

  // optional string unit_name = 6;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->unit_name(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:perfetto.protos.CounterDescriptor)
}

size_t CounterDescriptor::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:perfetto.protos.CounterDescriptor)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string categories = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->categories_size());
  for (int i = 0, n = this->categories_size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      this->categories(i));
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional string unit_name = 6;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->unit_name());
    }

    // optional .perfetto.protos.CounterDescriptor.BuiltinCounterType type = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->type());
    }

    // optional .perfetto.protos.CounterDescriptor.Unit unit = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->unit());
    }

    // optional int64 unit_multiplier = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->unit_multiplier());
    }

    // optional bool is_incremental = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 + 1;
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CounterDescriptor::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CounterDescriptor*>(
      &from));
}

void CounterDescriptor::MergeFrom(const CounterDescriptor& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:perfetto.protos.CounterDescriptor)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  categories_.MergeFrom(from.categories_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      unit_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.unit_name_);
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    if (cached_has_bits & 0x00000004u) {
      unit_ = from.unit_;
    }
    if (cached_has_bits & 0x00000008u) {
      unit_multiplier_ = from.unit_multiplier_;
    }
    if (cached_has_bits & 0x00000010u) {
      is_incremental_ = from.is_incremental_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void CounterDescriptor::CopyFrom(const CounterDescriptor& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:perfetto.protos.CounterDescriptor)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CounterDescriptor::IsInitialized() const {
  return true;
}

void CounterDescriptor::InternalSwap(CounterDescriptor* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  categories_.InternalSwap(CastToBase(&other->categories_));
  unit_name_.Swap(&other->unit_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(type_, other->type_);
  swap(unit_, other->unit_);
  swap(unit_multiplier_, other->unit_multiplier_);
  swap(is_incremental_, other->is_incremental_);
}

std::string CounterDescriptor::GetTypeName() const {
  return "perfetto.protos.CounterDescriptor";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protos
}  // namespace perfetto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::perfetto::protos::CounterDescriptor* Arena::CreateMaybeMessage< ::perfetto::protos::CounterDescriptor >(Arena* arena) {
  return Arena::CreateInternal< ::perfetto::protos::CounterDescriptor >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
