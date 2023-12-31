// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/app/notification.proto

#include "frameworks/base/core/proto/android/app/notification.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto;
namespace android {
namespace app {
class NotificationProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<NotificationProto> _instance;
} _NotificationProto_default_instance_;
}  // namespace app
}  // namespace android
static void InitDefaultsscc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::app::_NotificationProto_default_instance_;
    new (ptr) ::android::app::NotificationProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::app::NotificationProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto}, {}};

namespace android {
namespace app {
bool NotificationProto_Visibility_IsValid(int value) {
  switch (value) {
    case -1:
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> NotificationProto_Visibility_strings[3] = {};

static const char NotificationProto_Visibility_names[] =
  "VISIBILITY_PRIVATE"
  "VISIBILITY_PUBLIC"
  "VISIBILITY_SECRET";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry NotificationProto_Visibility_entries[] = {
  { {NotificationProto_Visibility_names + 0, 18}, 0 },
  { {NotificationProto_Visibility_names + 18, 17}, 1 },
  { {NotificationProto_Visibility_names + 35, 17}, -1 },
};

static const int NotificationProto_Visibility_entries_by_number[] = {
  2, // -1 -> VISIBILITY_SECRET
  0, // 0 -> VISIBILITY_PRIVATE
  1, // 1 -> VISIBILITY_PUBLIC
};

const std::string& NotificationProto_Visibility_Name(
    NotificationProto_Visibility value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          NotificationProto_Visibility_entries,
          NotificationProto_Visibility_entries_by_number,
          3, NotificationProto_Visibility_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      NotificationProto_Visibility_entries,
      NotificationProto_Visibility_entries_by_number,
      3, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     NotificationProto_Visibility_strings[idx].get();
}
bool NotificationProto_Visibility_Parse(
    const std::string& name, NotificationProto_Visibility* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      NotificationProto_Visibility_entries, 3, name, &int_value);
  if (success) {
    *value = static_cast<NotificationProto_Visibility>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr NotificationProto_Visibility NotificationProto::VISIBILITY_SECRET;
constexpr NotificationProto_Visibility NotificationProto::VISIBILITY_PRIVATE;
constexpr NotificationProto_Visibility NotificationProto::VISIBILITY_PUBLIC;
constexpr NotificationProto_Visibility NotificationProto::Visibility_MIN;
constexpr NotificationProto_Visibility NotificationProto::Visibility_MAX;
constexpr int NotificationProto::Visibility_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void NotificationProto::InitAsDefaultInstance() {
  ::android::app::_NotificationProto_default_instance_._instance.get_mutable()->public_version_ = const_cast< ::android::app::NotificationProto*>(
      ::android::app::NotificationProto::internal_default_instance());
}
class NotificationProto::_Internal {
 public:
  using HasBits = decltype(std::declval<NotificationProto>()._has_bits_);
  static void set_has_channel_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_has_ticker_text(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_flags(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_color(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_category(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_group_key(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_sort_key(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_action_length(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_visibility(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static const ::android::app::NotificationProto& public_version(const NotificationProto* msg);
  static void set_has_public_version(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

const ::android::app::NotificationProto&
NotificationProto::_Internal::public_version(const NotificationProto* msg) {
  return *msg->public_version_;
}
NotificationProto::NotificationProto()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.app.NotificationProto)
}
NotificationProto::NotificationProto(const NotificationProto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  channel_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_channel_id()) {
    channel_id_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.channel_id_);
  }
  category_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_category()) {
    category_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.category_);
  }
  group_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_group_key()) {
    group_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.group_key_);
  }
  sort_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_sort_key()) {
    sort_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.sort_key_);
  }
  if (from.has_public_version()) {
    public_version_ = new ::android::app::NotificationProto(*from.public_version_);
  } else {
    public_version_ = nullptr;
  }
  ::memcpy(&has_ticker_text_, &from.has_ticker_text_,
    static_cast<size_t>(reinterpret_cast<char*>(&visibility_) -
    reinterpret_cast<char*>(&has_ticker_text_)) + sizeof(visibility_));
  // @@protoc_insertion_point(copy_constructor:android.app.NotificationProto)
}

void NotificationProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto.base);
  channel_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  category_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  group_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sort_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&public_version_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&action_length_) -
      reinterpret_cast<char*>(&public_version_)) + sizeof(action_length_));
  visibility_ = -1;
}

NotificationProto::~NotificationProto() {
  // @@protoc_insertion_point(destructor:android.app.NotificationProto)
  SharedDtor();
}

void NotificationProto::SharedDtor() {
  channel_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  category_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  group_key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sort_key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete public_version_;
}

void NotificationProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const NotificationProto& NotificationProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_NotificationProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fapp_2fnotification_2eproto.base);
  return *internal_default_instance();
}


void NotificationProto::Clear() {
// @@protoc_insertion_point(message_clear_start:android.app.NotificationProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      channel_id_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      category_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      group_key_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000008u) {
      sort_key_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000010u) {
      GOOGLE_DCHECK(public_version_ != nullptr);
      public_version_->Clear();
    }
  }
  if (cached_has_bits & 0x000000e0u) {
    ::memset(&has_ticker_text_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&color_) -
        reinterpret_cast<char*>(&has_ticker_text_)) + sizeof(color_));
  }
  if (cached_has_bits & 0x00000300u) {
    action_length_ = 0;
    visibility_ = -1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* NotificationProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string channel_id = 1 [(.android.privacy) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_channel_id(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool has_ticker_text = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_has_ticker_text(&has_bits);
          has_ticker_text_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 flags = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_flags(&has_bits);
          flags_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 color = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_color(&has_bits);
          color_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string category = 5 [(.android.privacy) = {
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_category(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string group_key = 6 [(.android.privacy) = {
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_group_key(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string sort_key = 7 [(.android.privacy) = {
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_sort_key(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 action_length = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 64)) {
          _Internal::set_has_action_length(&has_bits);
          action_length_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .android.app.NotificationProto.Visibility visibility = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::android::app::NotificationProto_Visibility_IsValid(val))) {
            set_visibility(static_cast<::android::app::NotificationProto_Visibility>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(9, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional .android.app.NotificationProto public_version = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 82)) {
          ptr = ctx->ParseMessage(mutable_public_version(), ptr);
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
bool NotificationProto::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.app.NotificationProto)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string channel_id = 1 [(.android.privacy) = {
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_channel_id()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool has_ticker_text = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {
          _Internal::set_has_has_ticker_text(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   bool, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_BOOL>(
                 input, &has_ticker_text_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 flags = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (24 & 0xFF)) {
          _Internal::set_has_flags(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &flags_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 color = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (32 & 0xFF)) {
          _Internal::set_has_color(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &color_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string category = 5 [(.android.privacy) = {
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (42 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_category()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string group_key = 6 [(.android.privacy) = {
      case 6: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (50 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_group_key()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string sort_key = 7 [(.android.privacy) = {
      case 7: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (58 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_sort_key()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 action_length = 8;
      case 8: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (64 & 0xFF)) {
          _Internal::set_has_action_length(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &action_length_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .android.app.NotificationProto.Visibility visibility = 9;
      case 9: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (72 & 0xFF)) {
          int value = 0;
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   int, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::android::app::NotificationProto_Visibility_IsValid(value)) {
            set_visibility(static_cast< ::android::app::NotificationProto_Visibility >(value));
          } else {
            unknown_fields_stream.WriteVarint32(72u);
            unknown_fields_stream.WriteVarint32(
                static_cast<::PROTOBUF_NAMESPACE_ID::uint32>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .android.app.NotificationProto public_version = 10;
      case 10: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (82 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_public_version()));
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
  // @@protoc_insertion_point(parse_success:android.app.NotificationProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.app.NotificationProto)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void NotificationProto::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.app.NotificationProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string channel_id = 1 [(.android.privacy) = {
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->channel_id(), output);
  }

  // optional bool has_ticker_text = 2;
  if (cached_has_bits & 0x00000020u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBool(2, this->has_ticker_text(), output);
  }

  // optional int32 flags = 3;
  if (cached_has_bits & 0x00000040u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(3, this->flags(), output);
  }

  // optional int32 color = 4;
  if (cached_has_bits & 0x00000080u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(4, this->color(), output);
  }

  // optional string category = 5 [(.android.privacy) = {
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->category(), output);
  }

  // optional string group_key = 6 [(.android.privacy) = {
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->group_key(), output);
  }

  // optional string sort_key = 7 [(.android.privacy) = {
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->sort_key(), output);
  }

  // optional int32 action_length = 8;
  if (cached_has_bits & 0x00000100u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(8, this->action_length(), output);
  }

  // optional .android.app.NotificationProto.Visibility visibility = 9;
  if (cached_has_bits & 0x00000200u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnum(
      9, this->visibility(), output);
  }

  // optional .android.app.NotificationProto public_version = 10;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessage(
      10, _Internal::public_version(this), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.app.NotificationProto)
}

size_t NotificationProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.app.NotificationProto)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // optional string channel_id = 1 [(.android.privacy) = {
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->channel_id());
    }

    // optional string category = 5 [(.android.privacy) = {
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->category());
    }

    // optional string group_key = 6 [(.android.privacy) = {
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->group_key());
    }

    // optional string sort_key = 7 [(.android.privacy) = {
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->sort_key());
    }

    // optional .android.app.NotificationProto public_version = 10;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *public_version_);
    }

    // optional bool has_ticker_text = 2;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 + 1;
    }

    // optional int32 flags = 3;
    if (cached_has_bits & 0x00000040u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->flags());
    }

    // optional int32 color = 4;
    if (cached_has_bits & 0x00000080u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->color());
    }

  }
  if (cached_has_bits & 0x00000300u) {
    // optional int32 action_length = 8;
    if (cached_has_bits & 0x00000100u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->action_length());
    }

    // optional .android.app.NotificationProto.Visibility visibility = 9;
    if (cached_has_bits & 0x00000200u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->visibility());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void NotificationProto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const NotificationProto*>(
      &from));
}

void NotificationProto::MergeFrom(const NotificationProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.app.NotificationProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      channel_id_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.channel_id_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      category_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.category_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      group_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.group_key_);
    }
    if (cached_has_bits & 0x00000008u) {
      _has_bits_[0] |= 0x00000008u;
      sort_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.sort_key_);
    }
    if (cached_has_bits & 0x00000010u) {
      mutable_public_version()->::android::app::NotificationProto::MergeFrom(from.public_version());
    }
    if (cached_has_bits & 0x00000020u) {
      has_ticker_text_ = from.has_ticker_text_;
    }
    if (cached_has_bits & 0x00000040u) {
      flags_ = from.flags_;
    }
    if (cached_has_bits & 0x00000080u) {
      color_ = from.color_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x00000300u) {
    if (cached_has_bits & 0x00000100u) {
      action_length_ = from.action_length_;
    }
    if (cached_has_bits & 0x00000200u) {
      visibility_ = from.visibility_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void NotificationProto::CopyFrom(const NotificationProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.app.NotificationProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NotificationProto::IsInitialized() const {
  return true;
}

void NotificationProto::InternalSwap(NotificationProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  channel_id_.Swap(&other->channel_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  category_.Swap(&other->category_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  group_key_.Swap(&other->group_key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  sort_key_.Swap(&other->sort_key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(public_version_, other->public_version_);
  swap(has_ticker_text_, other->has_ticker_text_);
  swap(flags_, other->flags_);
  swap(color_, other->color_);
  swap(action_length_, other->action_length_);
  swap(visibility_, other->visibility_);
}

std::string NotificationProto::GetTypeName() const {
  return "android.app.NotificationProto";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace app
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::android::app::NotificationProto* Arena::CreateMaybeMessage< ::android::app::NotificationProto >(Arena* arena) {
  return Arena::CreateInternal< ::android::app::NotificationProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
