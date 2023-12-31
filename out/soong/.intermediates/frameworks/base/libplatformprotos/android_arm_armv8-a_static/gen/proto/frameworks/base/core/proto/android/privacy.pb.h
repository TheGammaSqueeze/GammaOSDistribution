// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/privacy.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace android {
class PrivacyFlags;
class PrivacyFlagsDefaultTypeInternal;
extern PrivacyFlagsDefaultTypeInternal _PrivacyFlags_default_instance_;
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> ::android::PrivacyFlags* Arena::CreateMaybeMessage<::android::PrivacyFlags>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace android {

enum Destination : int {
  DEST_LOCAL = 0,
  DEST_EXPLICIT = 100,
  DEST_AUTOMATIC = 200,
  DEST_UNSET = 255
};
bool Destination_IsValid(int value);
constexpr Destination Destination_MIN = DEST_LOCAL;
constexpr Destination Destination_MAX = DEST_UNSET;
constexpr int Destination_ARRAYSIZE = Destination_MAX + 1;

const std::string& Destination_Name(Destination value);
template<typename T>
inline const std::string& Destination_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Destination>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Destination_Name.");
  return Destination_Name(static_cast<Destination>(enum_t_value));
}
bool Destination_Parse(
    const std::string& name, Destination* value);
// ===================================================================

class PrivacyFlags :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:android.PrivacyFlags) */ {
 public:
  PrivacyFlags();
  virtual ~PrivacyFlags();

  PrivacyFlags(const PrivacyFlags& from);
  PrivacyFlags(PrivacyFlags&& from) noexcept
    : PrivacyFlags() {
    *this = ::std::move(from);
  }

  inline PrivacyFlags& operator=(const PrivacyFlags& from) {
    CopyFrom(from);
    return *this;
  }
  inline PrivacyFlags& operator=(PrivacyFlags&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const PrivacyFlags& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PrivacyFlags* internal_default_instance() {
    return reinterpret_cast<const PrivacyFlags*>(
               &_PrivacyFlags_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PrivacyFlags& a, PrivacyFlags& b) {
    a.Swap(&b);
  }
  inline void Swap(PrivacyFlags* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PrivacyFlags* New() const final {
    return CreateMaybeMessage<PrivacyFlags>(nullptr);
  }

  PrivacyFlags* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PrivacyFlags>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const PrivacyFlags& from);
  void MergeFrom(const PrivacyFlags& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PrivacyFlags* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "android.PrivacyFlags";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPatternsFieldNumber = 2,
    kDestFieldNumber = 1,
  };
  // repeated string patterns = 2;
  int patterns_size() const;
  void clear_patterns();
  const std::string& patterns(int index) const;
  std::string* mutable_patterns(int index);
  void set_patterns(int index, const std::string& value);
  void set_patterns(int index, std::string&& value);
  void set_patterns(int index, const char* value);
  void set_patterns(int index, const char* value, size_t size);
  std::string* add_patterns();
  void add_patterns(const std::string& value);
  void add_patterns(std::string&& value);
  void add_patterns(const char* value);
  void add_patterns(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& patterns() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_patterns();

  // optional .android.Destination dest = 1 [default = DEST_UNSET];
  bool has_dest() const;
  void clear_dest();
  ::android::Destination dest() const;
  void set_dest(::android::Destination value);

  // @@protoc_insertion_point(class_scope:android.PrivacyFlags)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> patterns_;
  int dest_;
  friend struct ::TableStruct_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto;
};
// ===================================================================

static const int kPrivacyFieldNumber = 102672883;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::android::PrivacyFlags >, 11, false >
  privacy;
static const int kMsgPrivacyFieldNumber = 102672883;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::android::PrivacyFlags >, 11, false >
  msg_privacy;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PrivacyFlags

// optional .android.Destination dest = 1 [default = DEST_UNSET];
inline bool PrivacyFlags::has_dest() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PrivacyFlags::clear_dest() {
  dest_ = 255;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::android::Destination PrivacyFlags::dest() const {
  // @@protoc_insertion_point(field_get:android.PrivacyFlags.dest)
  return static_cast< ::android::Destination >(dest_);
}
inline void PrivacyFlags::set_dest(::android::Destination value) {
  assert(::android::Destination_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  dest_ = value;
  // @@protoc_insertion_point(field_set:android.PrivacyFlags.dest)
}

// repeated string patterns = 2;
inline int PrivacyFlags::patterns_size() const {
  return patterns_.size();
}
inline void PrivacyFlags::clear_patterns() {
  patterns_.Clear();
}
inline const std::string& PrivacyFlags::patterns(int index) const {
  // @@protoc_insertion_point(field_get:android.PrivacyFlags.patterns)
  return patterns_.Get(index);
}
inline std::string* PrivacyFlags::mutable_patterns(int index) {
  // @@protoc_insertion_point(field_mutable:android.PrivacyFlags.patterns)
  return patterns_.Mutable(index);
}
inline void PrivacyFlags::set_patterns(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:android.PrivacyFlags.patterns)
  patterns_.Mutable(index)->assign(value);
}
inline void PrivacyFlags::set_patterns(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:android.PrivacyFlags.patterns)
  patterns_.Mutable(index)->assign(std::move(value));
}
inline void PrivacyFlags::set_patterns(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  patterns_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:android.PrivacyFlags.patterns)
}
inline void PrivacyFlags::set_patterns(int index, const char* value, size_t size) {
  patterns_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:android.PrivacyFlags.patterns)
}
inline std::string* PrivacyFlags::add_patterns() {
  // @@protoc_insertion_point(field_add_mutable:android.PrivacyFlags.patterns)
  return patterns_.Add();
}
inline void PrivacyFlags::add_patterns(const std::string& value) {
  patterns_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:android.PrivacyFlags.patterns)
}
inline void PrivacyFlags::add_patterns(std::string&& value) {
  patterns_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:android.PrivacyFlags.patterns)
}
inline void PrivacyFlags::add_patterns(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  patterns_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:android.PrivacyFlags.patterns)
}
inline void PrivacyFlags::add_patterns(const char* value, size_t size) {
  patterns_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:android.PrivacyFlags.patterns)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
PrivacyFlags::patterns() const {
  // @@protoc_insertion_point(field_list:android.PrivacyFlags.patterns)
  return patterns_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
PrivacyFlags::mutable_patterns() {
  // @@protoc_insertion_point(field_mutable_list:android.PrivacyFlags.patterns)
  return &patterns_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace android

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::android::Destination> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fprivacy_2eproto
