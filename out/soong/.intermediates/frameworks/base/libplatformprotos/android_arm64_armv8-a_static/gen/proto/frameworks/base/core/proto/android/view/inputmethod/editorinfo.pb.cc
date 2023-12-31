// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/view/inputmethod/editorinfo.proto

#include "frameworks/base/core/proto/android/view/inputmethod/editorinfo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace android {
namespace view {
namespace inputmethod {
class EditorInfoProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EditorInfoProto> _instance;
} _EditorInfoProto_default_instance_;
}  // namespace inputmethod
}  // namespace view
}  // namespace android
static void InitDefaultsscc_info_EditorInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fview_2finputmethod_2feditorinfo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::view::inputmethod::_EditorInfoProto_default_instance_;
    new (ptr) ::android::view::inputmethod::EditorInfoProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::view::inputmethod::EditorInfoProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EditorInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fview_2finputmethod_2feditorinfo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_EditorInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fview_2finputmethod_2feditorinfo_2eproto}, {}};

namespace android {
namespace view {
namespace inputmethod {

// ===================================================================

void EditorInfoProto::InitAsDefaultInstance() {
}
class EditorInfoProto::_Internal {
 public:
  using HasBits = decltype(std::declval<EditorInfoProto>()._has_bits_);
  static void set_has_input_type(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_ime_options(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_private_ime_options(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_package_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_field_id(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_target_input_method_user_id(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
};

EditorInfoProto::EditorInfoProto()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.view.inputmethod.EditorInfoProto)
}
EditorInfoProto::EditorInfoProto(const EditorInfoProto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  private_ime_options_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_private_ime_options()) {
    private_ime_options_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.private_ime_options_);
  }
  package_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_package_name()) {
    package_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.package_name_);
  }
  ::memcpy(&input_type_, &from.input_type_,
    static_cast<size_t>(reinterpret_cast<char*>(&target_input_method_user_id_) -
    reinterpret_cast<char*>(&input_type_)) + sizeof(target_input_method_user_id_));
  // @@protoc_insertion_point(copy_constructor:android.view.inputmethod.EditorInfoProto)
}

void EditorInfoProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_EditorInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fview_2finputmethod_2feditorinfo_2eproto.base);
  private_ime_options_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  package_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&input_type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&target_input_method_user_id_) -
      reinterpret_cast<char*>(&input_type_)) + sizeof(target_input_method_user_id_));
}

EditorInfoProto::~EditorInfoProto() {
  // @@protoc_insertion_point(destructor:android.view.inputmethod.EditorInfoProto)
  SharedDtor();
}

void EditorInfoProto::SharedDtor() {
  private_ime_options_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  package_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EditorInfoProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EditorInfoProto& EditorInfoProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EditorInfoProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fview_2finputmethod_2feditorinfo_2eproto.base);
  return *internal_default_instance();
}


void EditorInfoProto::Clear() {
// @@protoc_insertion_point(message_clear_start:android.view.inputmethod.EditorInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      private_ime_options_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      package_name_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x0000003cu) {
    ::memset(&input_type_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&target_input_method_user_id_) -
        reinterpret_cast<char*>(&input_type_)) + sizeof(target_input_method_user_id_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* EditorInfoProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 input_type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_input_type(&has_bits);
          input_type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 ime_options = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_ime_options(&has_bits);
          ime_options_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string private_ime_options = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_private_ime_options(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string package_name = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_package_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 field_id = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_field_id(&has_bits);
          field_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 target_input_method_user_id = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _Internal::set_has_target_input_method_user_id(&has_bits);
          target_input_method_user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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
bool EditorInfoProto::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.view.inputmethod.EditorInfoProto)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 input_type = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          _Internal::set_has_input_type(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &input_type_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 ime_options = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {
          _Internal::set_has_ime_options(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &ime_options_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string private_ime_options = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (26 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_private_ime_options()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string package_name = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (34 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_package_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 field_id = 5;
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (40 & 0xFF)) {
          _Internal::set_has_field_id(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &field_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 target_input_method_user_id = 6;
      case 6: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (48 & 0xFF)) {
          _Internal::set_has_target_input_method_user_id(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &target_input_method_user_id_)));
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
  // @@protoc_insertion_point(parse_success:android.view.inputmethod.EditorInfoProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.view.inputmethod.EditorInfoProto)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void EditorInfoProto::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.view.inputmethod.EditorInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 input_type = 1;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(1, this->input_type(), output);
  }

  // optional int32 ime_options = 2;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(2, this->ime_options(), output);
  }

  // optional string private_ime_options = 3;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->private_ime_options(), output);
  }

  // optional string package_name = 4;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->package_name(), output);
  }

  // optional int32 field_id = 5;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(5, this->field_id(), output);
  }

  // optional int32 target_input_method_user_id = 6;
  if (cached_has_bits & 0x00000020u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(6, this->target_input_method_user_id(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.view.inputmethod.EditorInfoProto)
}

size_t EditorInfoProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.view.inputmethod.EditorInfoProto)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    // optional string private_ime_options = 3;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->private_ime_options());
    }

    // optional string package_name = 4;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->package_name());
    }

    // optional int32 input_type = 1;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->input_type());
    }

    // optional int32 ime_options = 2;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->ime_options());
    }

    // optional int32 field_id = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->field_id());
    }

    // optional int32 target_input_method_user_id = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->target_input_method_user_id());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EditorInfoProto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const EditorInfoProto*>(
      &from));
}

void EditorInfoProto::MergeFrom(const EditorInfoProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.view.inputmethod.EditorInfoProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      private_ime_options_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.private_ime_options_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      package_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.package_name_);
    }
    if (cached_has_bits & 0x00000004u) {
      input_type_ = from.input_type_;
    }
    if (cached_has_bits & 0x00000008u) {
      ime_options_ = from.ime_options_;
    }
    if (cached_has_bits & 0x00000010u) {
      field_id_ = from.field_id_;
    }
    if (cached_has_bits & 0x00000020u) {
      target_input_method_user_id_ = from.target_input_method_user_id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void EditorInfoProto::CopyFrom(const EditorInfoProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.view.inputmethod.EditorInfoProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EditorInfoProto::IsInitialized() const {
  return true;
}

void EditorInfoProto::InternalSwap(EditorInfoProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  private_ime_options_.Swap(&other->private_ime_options_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  package_name_.Swap(&other->package_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(input_type_, other->input_type_);
  swap(ime_options_, other->ime_options_);
  swap(field_id_, other->field_id_);
  swap(target_input_method_user_id_, other->target_input_method_user_id_);
}

std::string EditorInfoProto::GetTypeName() const {
  return "android.view.inputmethod.EditorInfoProto";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace inputmethod
}  // namespace view
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::android::view::inputmethod::EditorInfoProto* Arena::CreateMaybeMessage< ::android::view::inputmethod::EditorInfoProto >(Arena* arena) {
  return Arena::CreateInternal< ::android::view::inputmethod::EditorInfoProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
