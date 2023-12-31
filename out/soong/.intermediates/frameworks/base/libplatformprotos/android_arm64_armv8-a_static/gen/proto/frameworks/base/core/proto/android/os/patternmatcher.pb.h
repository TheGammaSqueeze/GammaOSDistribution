// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/os/patternmatcher.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto

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
#include "frameworks/base/core/proto/android/privacy.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto {
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
namespace os {
class PatternMatcherProto;
class PatternMatcherProtoDefaultTypeInternal;
extern PatternMatcherProtoDefaultTypeInternal _PatternMatcherProto_default_instance_;
}  // namespace os
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> ::android::os::PatternMatcherProto* Arena::CreateMaybeMessage<::android::os::PatternMatcherProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace android {
namespace os {

enum PatternMatcherProto_Type : int {
  PatternMatcherProto_Type_TYPE_LITERAL = 0,
  PatternMatcherProto_Type_TYPE_PREFIX = 1,
  PatternMatcherProto_Type_TYPE_SIMPLE_GLOB = 2,
  PatternMatcherProto_Type_TYPE_ADVANCED_GLOB = 3
};
bool PatternMatcherProto_Type_IsValid(int value);
constexpr PatternMatcherProto_Type PatternMatcherProto_Type_Type_MIN = PatternMatcherProto_Type_TYPE_LITERAL;
constexpr PatternMatcherProto_Type PatternMatcherProto_Type_Type_MAX = PatternMatcherProto_Type_TYPE_ADVANCED_GLOB;
constexpr int PatternMatcherProto_Type_Type_ARRAYSIZE = PatternMatcherProto_Type_Type_MAX + 1;

const std::string& PatternMatcherProto_Type_Name(PatternMatcherProto_Type value);
template<typename T>
inline const std::string& PatternMatcherProto_Type_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PatternMatcherProto_Type>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PatternMatcherProto_Type_Name.");
  return PatternMatcherProto_Type_Name(static_cast<PatternMatcherProto_Type>(enum_t_value));
}
bool PatternMatcherProto_Type_Parse(
    const std::string& name, PatternMatcherProto_Type* value);
// ===================================================================

class PatternMatcherProto :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:android.os.PatternMatcherProto) */ {
 public:
  PatternMatcherProto();
  virtual ~PatternMatcherProto();

  PatternMatcherProto(const PatternMatcherProto& from);
  PatternMatcherProto(PatternMatcherProto&& from) noexcept
    : PatternMatcherProto() {
    *this = ::std::move(from);
  }

  inline PatternMatcherProto& operator=(const PatternMatcherProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline PatternMatcherProto& operator=(PatternMatcherProto&& from) noexcept {
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

  static const PatternMatcherProto& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PatternMatcherProto* internal_default_instance() {
    return reinterpret_cast<const PatternMatcherProto*>(
               &_PatternMatcherProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PatternMatcherProto& a, PatternMatcherProto& b) {
    a.Swap(&b);
  }
  inline void Swap(PatternMatcherProto* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PatternMatcherProto* New() const final {
    return CreateMaybeMessage<PatternMatcherProto>(nullptr);
  }

  PatternMatcherProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PatternMatcherProto>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const PatternMatcherProto& from);
  void MergeFrom(const PatternMatcherProto& from);
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
  void InternalSwap(PatternMatcherProto* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "android.os.PatternMatcherProto";
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

  typedef PatternMatcherProto_Type Type;
  static constexpr Type TYPE_LITERAL =
    PatternMatcherProto_Type_TYPE_LITERAL;
  static constexpr Type TYPE_PREFIX =
    PatternMatcherProto_Type_TYPE_PREFIX;
  static constexpr Type TYPE_SIMPLE_GLOB =
    PatternMatcherProto_Type_TYPE_SIMPLE_GLOB;
  static constexpr Type TYPE_ADVANCED_GLOB =
    PatternMatcherProto_Type_TYPE_ADVANCED_GLOB;
  static inline bool Type_IsValid(int value) {
    return PatternMatcherProto_Type_IsValid(value);
  }
  static constexpr Type Type_MIN =
    PatternMatcherProto_Type_Type_MIN;
  static constexpr Type Type_MAX =
    PatternMatcherProto_Type_Type_MAX;
  static constexpr int Type_ARRAYSIZE =
    PatternMatcherProto_Type_Type_ARRAYSIZE;
  template<typename T>
  static inline const std::string& Type_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Type>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Type_Name.");
    return PatternMatcherProto_Type_Name(enum_t_value);
  }
  static inline bool Type_Parse(const std::string& name,
      Type* value) {
    return PatternMatcherProto_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kPatternFieldNumber = 1,
    kTypeFieldNumber = 2,
  };
  // optional string pattern = 1;
  bool has_pattern() const;
  void clear_pattern();
  const std::string& pattern() const;
  void set_pattern(const std::string& value);
  void set_pattern(std::string&& value);
  void set_pattern(const char* value);
  void set_pattern(const char* value, size_t size);
  std::string* mutable_pattern();
  std::string* release_pattern();
  void set_allocated_pattern(std::string* pattern);

  // optional .android.os.PatternMatcherProto.Type type = 2;
  bool has_type() const;
  void clear_type();
  ::android::os::PatternMatcherProto_Type type() const;
  void set_type(::android::os::PatternMatcherProto_Type value);

  // @@protoc_insertion_point(class_scope:android.os.PatternMatcherProto)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pattern_;
  int type_;
  friend struct ::TableStruct_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PatternMatcherProto

// optional string pattern = 1;
inline bool PatternMatcherProto::has_pattern() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PatternMatcherProto::clear_pattern() {
  pattern_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PatternMatcherProto::pattern() const {
  // @@protoc_insertion_point(field_get:android.os.PatternMatcherProto.pattern)
  return pattern_.GetNoArena();
}
inline void PatternMatcherProto::set_pattern(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  pattern_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:android.os.PatternMatcherProto.pattern)
}
inline void PatternMatcherProto::set_pattern(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  pattern_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:android.os.PatternMatcherProto.pattern)
}
inline void PatternMatcherProto::set_pattern(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  pattern_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:android.os.PatternMatcherProto.pattern)
}
inline void PatternMatcherProto::set_pattern(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  pattern_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:android.os.PatternMatcherProto.pattern)
}
inline std::string* PatternMatcherProto::mutable_pattern() {
  _has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_mutable:android.os.PatternMatcherProto.pattern)
  return pattern_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PatternMatcherProto::release_pattern() {
  // @@protoc_insertion_point(field_release:android.os.PatternMatcherProto.pattern)
  if (!has_pattern()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return pattern_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PatternMatcherProto::set_allocated_pattern(std::string* pattern) {
  if (pattern != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  pattern_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pattern);
  // @@protoc_insertion_point(field_set_allocated:android.os.PatternMatcherProto.pattern)
}

// optional .android.os.PatternMatcherProto.Type type = 2;
inline bool PatternMatcherProto::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PatternMatcherProto::clear_type() {
  type_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::android::os::PatternMatcherProto_Type PatternMatcherProto::type() const {
  // @@protoc_insertion_point(field_get:android.os.PatternMatcherProto.type)
  return static_cast< ::android::os::PatternMatcherProto_Type >(type_);
}
inline void PatternMatcherProto::set_type(::android::os::PatternMatcherProto_Type value) {
  assert(::android::os::PatternMatcherProto_Type_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  type_ = value;
  // @@protoc_insertion_point(field_set:android.os.PatternMatcherProto.type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace os
}  // namespace android

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::android::os::PatternMatcherProto_Type> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fpatternmatcher_2eproto
