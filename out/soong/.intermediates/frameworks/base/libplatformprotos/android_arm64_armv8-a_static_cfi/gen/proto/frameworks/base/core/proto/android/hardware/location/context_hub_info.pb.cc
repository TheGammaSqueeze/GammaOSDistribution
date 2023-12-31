// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/hardware/location/context_hub_info.proto

#include "frameworks/base/core/proto/android/hardware/location/context_hub_info.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace android {
namespace hardware {
namespace location {
class ContextHubInfoProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ContextHubInfoProto> _instance;
} _ContextHubInfoProto_default_instance_;
}  // namespace location
}  // namespace hardware
}  // namespace android
static void InitDefaultsscc_info_ContextHubInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fhardware_2flocation_2fcontext_5fhub_5finfo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::hardware::location::_ContextHubInfoProto_default_instance_;
    new (ptr) ::android::hardware::location::ContextHubInfoProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::hardware::location::ContextHubInfoProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ContextHubInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fhardware_2flocation_2fcontext_5fhub_5finfo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_ContextHubInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fhardware_2flocation_2fcontext_5fhub_5finfo_2eproto}, {}};

namespace android {
namespace hardware {
namespace location {

// ===================================================================

void ContextHubInfoProto::InitAsDefaultInstance() {
}
class ContextHubInfoProto::_Internal {
 public:
  using HasBits = decltype(std::declval<ContextHubInfoProto>()._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_vendor(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_toolchain(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_platform_version(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_static_sw_version(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_toolchain_version(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_chre_platform_id(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_peak_mips(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_stopped_power_draw_mw(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static void set_has_sleep_power_draw_mw(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
  static void set_has_peak_power_draw_mw(HasBits* has_bits) {
    (*has_bits)[0] |= 2048u;
  }
  static void set_has_max_packet_length_bytes(HasBits* has_bits) {
    (*has_bits)[0] |= 4096u;
  }
};

ContextHubInfoProto::ContextHubInfoProto()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.hardware.location.ContextHubInfoProto)
}
ContextHubInfoProto::ContextHubInfoProto(const ContextHubInfoProto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  vendor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_vendor()) {
    vendor_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.vendor_);
  }
  toolchain_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_toolchain()) {
    toolchain_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.toolchain_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&max_packet_length_bytes_) -
    reinterpret_cast<char*>(&id_)) + sizeof(max_packet_length_bytes_));
  // @@protoc_insertion_point(copy_constructor:android.hardware.location.ContextHubInfoProto)
}

void ContextHubInfoProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ContextHubInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fhardware_2flocation_2fcontext_5fhub_5finfo_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  vendor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  toolchain_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&max_packet_length_bytes_) -
      reinterpret_cast<char*>(&id_)) + sizeof(max_packet_length_bytes_));
}

ContextHubInfoProto::~ContextHubInfoProto() {
  // @@protoc_insertion_point(destructor:android.hardware.location.ContextHubInfoProto)
  SharedDtor();
}

void ContextHubInfoProto::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  vendor_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  toolchain_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ContextHubInfoProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ContextHubInfoProto& ContextHubInfoProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ContextHubInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fhardware_2flocation_2fcontext_5fhub_5finfo_2eproto.base);
  return *internal_default_instance();
}


void ContextHubInfoProto::Clear() {
// @@protoc_insertion_point(message_clear_start:android.hardware.location.ContextHubInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      vendor_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      toolchain_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x000000f8u) {
    ::memset(&id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&chre_platform_id_) -
        reinterpret_cast<char*>(&id_)) + sizeof(chre_platform_id_));
  }
  if (cached_has_bits & 0x00001f00u) {
    ::memset(&peak_mips_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&max_packet_length_bytes_) -
        reinterpret_cast<char*>(&peak_mips_)) + sizeof(max_packet_length_bytes_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ContextHubInfoProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string vendor = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_vendor(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string toolchain = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_toolchain(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 platform_version = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_platform_version(&has_bits);
          platform_version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 static_sw_version = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_static_sw_version(&has_bits);
          static_sw_version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 toolchain_version = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          _Internal::set_has_toolchain_version(&has_bits);
          toolchain_version_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 chre_platform_id = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 64)) {
          _Internal::set_has_chre_platform_id(&has_bits);
          chre_platform_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional float peak_mips = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 77)) {
          _Internal::set_has_peak_mips(&has_bits);
          peak_mips_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional float stopped_power_draw_mw = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 85)) {
          _Internal::set_has_stopped_power_draw_mw(&has_bits);
          stopped_power_draw_mw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional float sleep_power_draw_mw = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 93)) {
          _Internal::set_has_sleep_power_draw_mw(&has_bits);
          sleep_power_draw_mw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional float peak_power_draw_mw = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 101)) {
          _Internal::set_has_peak_power_draw_mw(&has_bits);
          peak_power_draw_mw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional int32 max_packet_length_bytes = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 104)) {
          _Internal::set_has_max_packet_length_bytes(&has_bits);
          max_packet_length_bytes_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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
bool ContextHubInfoProto::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.hardware.location.ContextHubInfoProto)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          _Internal::set_has_id(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string name = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string vendor = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (26 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_vendor()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string toolchain = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (34 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_toolchain()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 platform_version = 5;
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (40 & 0xFF)) {
          _Internal::set_has_platform_version(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &platform_version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 static_sw_version = 6;
      case 6: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (48 & 0xFF)) {
          _Internal::set_has_static_sw_version(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &static_sw_version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 toolchain_version = 7;
      case 7: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (56 & 0xFF)) {
          _Internal::set_has_toolchain_version(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &toolchain_version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 chre_platform_id = 8;
      case 8: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (64 & 0xFF)) {
          _Internal::set_has_chre_platform_id(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &chre_platform_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float peak_mips = 9;
      case 9: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (77 & 0xFF)) {
          _Internal::set_has_peak_mips(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   float, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &peak_mips_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float stopped_power_draw_mw = 10;
      case 10: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (85 & 0xFF)) {
          _Internal::set_has_stopped_power_draw_mw(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   float, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &stopped_power_draw_mw_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float sleep_power_draw_mw = 11;
      case 11: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (93 & 0xFF)) {
          _Internal::set_has_sleep_power_draw_mw(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   float, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &sleep_power_draw_mw_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float peak_power_draw_mw = 12;
      case 12: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (101 & 0xFF)) {
          _Internal::set_has_peak_power_draw_mw(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   float, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &peak_power_draw_mw_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 max_packet_length_bytes = 13;
      case 13: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (104 & 0xFF)) {
          _Internal::set_has_max_packet_length_bytes(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &max_packet_length_bytes_)));
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
  // @@protoc_insertion_point(parse_success:android.hardware.location.ContextHubInfoProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.hardware.location.ContextHubInfoProto)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ContextHubInfoProto::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.hardware.location.ContextHubInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 id = 1;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional string name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional string vendor = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->vendor(), output);
  }

  // optional string toolchain = 4;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->toolchain(), output);
  }

  // optional int32 platform_version = 5;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(5, this->platform_version(), output);
  }

  // optional int32 static_sw_version = 6;
  if (cached_has_bits & 0x00000020u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(6, this->static_sw_version(), output);
  }

  // optional int32 toolchain_version = 7;
  if (cached_has_bits & 0x00000040u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(7, this->toolchain_version(), output);
  }

  // optional int64 chre_platform_id = 8;
  if (cached_has_bits & 0x00000080u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(8, this->chre_platform_id(), output);
  }

  // optional float peak_mips = 9;
  if (cached_has_bits & 0x00000100u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloat(9, this->peak_mips(), output);
  }

  // optional float stopped_power_draw_mw = 10;
  if (cached_has_bits & 0x00000200u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloat(10, this->stopped_power_draw_mw(), output);
  }

  // optional float sleep_power_draw_mw = 11;
  if (cached_has_bits & 0x00000400u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloat(11, this->sleep_power_draw_mw(), output);
  }

  // optional float peak_power_draw_mw = 12;
  if (cached_has_bits & 0x00000800u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloat(12, this->peak_power_draw_mw(), output);
  }

  // optional int32 max_packet_length_bytes = 13;
  if (cached_has_bits & 0x00001000u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(13, this->max_packet_length_bytes(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.hardware.location.ContextHubInfoProto)
}

size_t ContextHubInfoProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.hardware.location.ContextHubInfoProto)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // optional string name = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional string vendor = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->vendor());
    }

    // optional string toolchain = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->toolchain());
    }

    // optional int32 id = 1;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional int32 platform_version = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->platform_version());
    }

    // optional int32 static_sw_version = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->static_sw_version());
    }

    // optional int32 toolchain_version = 7;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->toolchain_version());
    }

    // optional int64 chre_platform_id = 8;
    if (cached_has_bits & 0x00000080u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->chre_platform_id());
    }

  }
  if (cached_has_bits & 0x00001f00u) {
    // optional float peak_mips = 9;
    if (cached_has_bits & 0x00000100u) {
      total_size += 1 + 4;
    }

    // optional float stopped_power_draw_mw = 10;
    if (cached_has_bits & 0x00000200u) {
      total_size += 1 + 4;
    }

    // optional float sleep_power_draw_mw = 11;
    if (cached_has_bits & 0x00000400u) {
      total_size += 1 + 4;
    }

    // optional float peak_power_draw_mw = 12;
    if (cached_has_bits & 0x00000800u) {
      total_size += 1 + 4;
    }

    // optional int32 max_packet_length_bytes = 13;
    if (cached_has_bits & 0x00001000u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->max_packet_length_bytes());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ContextHubInfoProto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ContextHubInfoProto*>(
      &from));
}

void ContextHubInfoProto::MergeFrom(const ContextHubInfoProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.hardware.location.ContextHubInfoProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      vendor_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.vendor_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      toolchain_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.toolchain_);
    }
    if (cached_has_bits & 0x00000008u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000010u) {
      platform_version_ = from.platform_version_;
    }
    if (cached_has_bits & 0x00000020u) {
      static_sw_version_ = from.static_sw_version_;
    }
    if (cached_has_bits & 0x00000040u) {
      toolchain_version_ = from.toolchain_version_;
    }
    if (cached_has_bits & 0x00000080u) {
      chre_platform_id_ = from.chre_platform_id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00001f00u) {
    if (cached_has_bits & 0x00000100u) {
      peak_mips_ = from.peak_mips_;
    }
    if (cached_has_bits & 0x00000200u) {
      stopped_power_draw_mw_ = from.stopped_power_draw_mw_;
    }
    if (cached_has_bits & 0x00000400u) {
      sleep_power_draw_mw_ = from.sleep_power_draw_mw_;
    }
    if (cached_has_bits & 0x00000800u) {
      peak_power_draw_mw_ = from.peak_power_draw_mw_;
    }
    if (cached_has_bits & 0x00001000u) {
      max_packet_length_bytes_ = from.max_packet_length_bytes_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ContextHubInfoProto::CopyFrom(const ContextHubInfoProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.hardware.location.ContextHubInfoProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContextHubInfoProto::IsInitialized() const {
  return true;
}

void ContextHubInfoProto::InternalSwap(ContextHubInfoProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  vendor_.Swap(&other->vendor_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  toolchain_.Swap(&other->toolchain_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(id_, other->id_);
  swap(platform_version_, other->platform_version_);
  swap(static_sw_version_, other->static_sw_version_);
  swap(toolchain_version_, other->toolchain_version_);
  swap(chre_platform_id_, other->chre_platform_id_);
  swap(peak_mips_, other->peak_mips_);
  swap(stopped_power_draw_mw_, other->stopped_power_draw_mw_);
  swap(sleep_power_draw_mw_, other->sleep_power_draw_mw_);
  swap(peak_power_draw_mw_, other->peak_power_draw_mw_);
  swap(max_packet_length_bytes_, other->max_packet_length_bytes_);
}

std::string ContextHubInfoProto::GetTypeName() const {
  return "android.hardware.location.ContextHubInfoProto";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace location
}  // namespace hardware
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::android::hardware::location::ContextHubInfoProto* Arena::CreateMaybeMessage< ::android::hardware::location::ContextHubInfoProto >(Arena* arena) {
  return Arena::CreateInternal< ::android::hardware::location::ContextHubInfoProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
