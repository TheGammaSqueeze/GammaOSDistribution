// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/base/core/proto/android/os/cpufreq.proto

#include "frameworks/base/core/proto/android/os/cpufreq.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto;
namespace android {
namespace os {
class CpuFreqProto_Stats_TimeInStateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CpuFreqProto_Stats_TimeInState> _instance;
} _CpuFreqProto_Stats_TimeInState_default_instance_;
class CpuFreqProto_StatsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CpuFreqProto_Stats> _instance;
} _CpuFreqProto_Stats_default_instance_;
class CpuFreqProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CpuFreqProto> _instance;
} _CpuFreqProto_default_instance_;
}  // namespace os
}  // namespace android
static void InitDefaultsscc_info_CpuFreqProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::os::_CpuFreqProto_default_instance_;
    new (ptr) ::android::os::CpuFreqProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::os::CpuFreqProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_CpuFreqProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_CpuFreqProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto}, {
      &scc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base,}};

static void InitDefaultsscc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::os::_CpuFreqProto_Stats_default_instance_;
    new (ptr) ::android::os::CpuFreqProto_Stats();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::os::CpuFreqProto_Stats::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto}, {
      &scc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base,}};

static void InitDefaultsscc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::android::os::_CpuFreqProto_Stats_TimeInState_default_instance_;
    new (ptr) ::android::os::CpuFreqProto_Stats_TimeInState();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::android::os::CpuFreqProto_Stats_TimeInState::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto}, {}};

namespace android {
namespace os {

// ===================================================================

void CpuFreqProto_Stats_TimeInState::InitAsDefaultInstance() {
}
class CpuFreqProto_Stats_TimeInState::_Internal {
 public:
  using HasBits = decltype(std::declval<CpuFreqProto_Stats_TimeInState>()._has_bits_);
  static void set_has_state_khz(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_time_jiffy(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CpuFreqProto_Stats_TimeInState::CpuFreqProto_Stats_TimeInState()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.os.CpuFreqProto.Stats.TimeInState)
}
CpuFreqProto_Stats_TimeInState::CpuFreqProto_Stats_TimeInState(const CpuFreqProto_Stats_TimeInState& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&time_jiffy_, &from.time_jiffy_,
    static_cast<size_t>(reinterpret_cast<char*>(&state_khz_) -
    reinterpret_cast<char*>(&time_jiffy_)) + sizeof(state_khz_));
  // @@protoc_insertion_point(copy_constructor:android.os.CpuFreqProto.Stats.TimeInState)
}

void CpuFreqProto_Stats_TimeInState::SharedCtor() {
  ::memset(&time_jiffy_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&state_khz_) -
      reinterpret_cast<char*>(&time_jiffy_)) + sizeof(state_khz_));
}

CpuFreqProto_Stats_TimeInState::~CpuFreqProto_Stats_TimeInState() {
  // @@protoc_insertion_point(destructor:android.os.CpuFreqProto.Stats.TimeInState)
  SharedDtor();
}

void CpuFreqProto_Stats_TimeInState::SharedDtor() {
}

void CpuFreqProto_Stats_TimeInState::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CpuFreqProto_Stats_TimeInState& CpuFreqProto_Stats_TimeInState::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CpuFreqProto_Stats_TimeInState_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base);
  return *internal_default_instance();
}


void CpuFreqProto_Stats_TimeInState::Clear() {
// @@protoc_insertion_point(message_clear_start:android.os.CpuFreqProto.Stats.TimeInState)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    ::memset(&time_jiffy_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&state_khz_) -
        reinterpret_cast<char*>(&time_jiffy_)) + sizeof(state_khz_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CpuFreqProto_Stats_TimeInState::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 state_khz = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_state_khz(&has_bits);
          state_khz_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 time_jiffy = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_time_jiffy(&has_bits);
          time_jiffy_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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
bool CpuFreqProto_Stats_TimeInState::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.os.CpuFreqProto.Stats.TimeInState)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 state_khz = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          _Internal::set_has_state_khz(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &state_khz_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int64 time_jiffy = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {
          _Internal::set_has_time_jiffy(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int64, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT64>(
                 input, &time_jiffy_)));
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
  // @@protoc_insertion_point(parse_success:android.os.CpuFreqProto.Stats.TimeInState)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.os.CpuFreqProto.Stats.TimeInState)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CpuFreqProto_Stats_TimeInState::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.os.CpuFreqProto.Stats.TimeInState)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 state_khz = 1;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(1, this->state_khz(), output);
  }

  // optional int64 time_jiffy = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64(2, this->time_jiffy(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.os.CpuFreqProto.Stats.TimeInState)
}

size_t CpuFreqProto_Stats_TimeInState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.os.CpuFreqProto.Stats.TimeInState)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional int64 time_jiffy = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->time_jiffy());
    }

    // optional int32 state_khz = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->state_khz());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CpuFreqProto_Stats_TimeInState::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CpuFreqProto_Stats_TimeInState*>(
      &from));
}

void CpuFreqProto_Stats_TimeInState::MergeFrom(const CpuFreqProto_Stats_TimeInState& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.os.CpuFreqProto.Stats.TimeInState)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      time_jiffy_ = from.time_jiffy_;
    }
    if (cached_has_bits & 0x00000002u) {
      state_khz_ = from.state_khz_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void CpuFreqProto_Stats_TimeInState::CopyFrom(const CpuFreqProto_Stats_TimeInState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.os.CpuFreqProto.Stats.TimeInState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CpuFreqProto_Stats_TimeInState::IsInitialized() const {
  return true;
}

void CpuFreqProto_Stats_TimeInState::InternalSwap(CpuFreqProto_Stats_TimeInState* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(time_jiffy_, other->time_jiffy_);
  swap(state_khz_, other->state_khz_);
}

std::string CpuFreqProto_Stats_TimeInState::GetTypeName() const {
  return "android.os.CpuFreqProto.Stats.TimeInState";
}


// ===================================================================

void CpuFreqProto_Stats::InitAsDefaultInstance() {
}
class CpuFreqProto_Stats::_Internal {
 public:
  using HasBits = decltype(std::declval<CpuFreqProto_Stats>()._has_bits_);
  static void set_has_cpu_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CpuFreqProto_Stats::CpuFreqProto_Stats()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.os.CpuFreqProto.Stats)
}
CpuFreqProto_Stats::CpuFreqProto_Stats(const CpuFreqProto_Stats& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      times_(from.times_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  cpu_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_cpu_name()) {
    cpu_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cpu_name_);
  }
  // @@protoc_insertion_point(copy_constructor:android.os.CpuFreqProto.Stats)
}

void CpuFreqProto_Stats::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base);
  cpu_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CpuFreqProto_Stats::~CpuFreqProto_Stats() {
  // @@protoc_insertion_point(destructor:android.os.CpuFreqProto.Stats)
  SharedDtor();
}

void CpuFreqProto_Stats::SharedDtor() {
  cpu_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CpuFreqProto_Stats::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CpuFreqProto_Stats& CpuFreqProto_Stats::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CpuFreqProto_Stats_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base);
  return *internal_default_instance();
}


void CpuFreqProto_Stats::Clear() {
// @@protoc_insertion_point(message_clear_start:android.os.CpuFreqProto.Stats)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  times_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    cpu_name_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CpuFreqProto_Stats::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string cpu_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_cpu_name(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .android.os.CpuFreqProto.Stats.TimeInState times = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(add_times(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 18);
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
bool CpuFreqProto_Stats::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.os.CpuFreqProto.Stats)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string cpu_name = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_cpu_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .android.os.CpuFreqProto.Stats.TimeInState times = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
                input, add_times()));
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
  // @@protoc_insertion_point(parse_success:android.os.CpuFreqProto.Stats)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.os.CpuFreqProto.Stats)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CpuFreqProto_Stats::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.os.CpuFreqProto.Stats)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string cpu_name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->cpu_name(), output);
  }

  // repeated .android.os.CpuFreqProto.Stats.TimeInState times = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->times_size()); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessage(
      2,
      this->times(static_cast<int>(i)),
      output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.os.CpuFreqProto.Stats)
}

size_t CpuFreqProto_Stats::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.os.CpuFreqProto.Stats)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .android.os.CpuFreqProto.Stats.TimeInState times = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->times_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          this->times(static_cast<int>(i)));
    }
  }

  // optional string cpu_name = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->cpu_name());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CpuFreqProto_Stats::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CpuFreqProto_Stats*>(
      &from));
}

void CpuFreqProto_Stats::MergeFrom(const CpuFreqProto_Stats& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.os.CpuFreqProto.Stats)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  times_.MergeFrom(from.times_);
  if (from.has_cpu_name()) {
    _has_bits_[0] |= 0x00000001u;
    cpu_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.cpu_name_);
  }
}

void CpuFreqProto_Stats::CopyFrom(const CpuFreqProto_Stats& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.os.CpuFreqProto.Stats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CpuFreqProto_Stats::IsInitialized() const {
  return true;
}

void CpuFreqProto_Stats::InternalSwap(CpuFreqProto_Stats* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  CastToBase(&times_)->InternalSwap(CastToBase(&other->times_));
  cpu_name_.Swap(&other->cpu_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

std::string CpuFreqProto_Stats::GetTypeName() const {
  return "android.os.CpuFreqProto.Stats";
}


// ===================================================================

void CpuFreqProto::InitAsDefaultInstance() {
}
class CpuFreqProto::_Internal {
 public:
  using HasBits = decltype(std::declval<CpuFreqProto>()._has_bits_);
  static void set_has_jiffy_hz(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CpuFreqProto::CpuFreqProto()
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:android.os.CpuFreqProto)
}
CpuFreqProto::CpuFreqProto(const CpuFreqProto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      cpu_freqs_(from.cpu_freqs_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  jiffy_hz_ = from.jiffy_hz_;
  // @@protoc_insertion_point(copy_constructor:android.os.CpuFreqProto)
}

void CpuFreqProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CpuFreqProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base);
  jiffy_hz_ = 0;
}

CpuFreqProto::~CpuFreqProto() {
  // @@protoc_insertion_point(destructor:android.os.CpuFreqProto)
  SharedDtor();
}

void CpuFreqProto::SharedDtor() {
}

void CpuFreqProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CpuFreqProto& CpuFreqProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CpuFreqProto_frameworks_2fbase_2fcore_2fproto_2fandroid_2fos_2fcpufreq_2eproto.base);
  return *internal_default_instance();
}


void CpuFreqProto::Clear() {
// @@protoc_insertion_point(message_clear_start:android.os.CpuFreqProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cpu_freqs_.Clear();
  jiffy_hz_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CpuFreqProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 jiffy_hz = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_jiffy_hz(&has_bits);
          jiffy_hz_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .android.os.CpuFreqProto.Stats cpu_freqs = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(add_cpu_freqs(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 18);
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
bool CpuFreqProto::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  ::PROTOBUF_NAMESPACE_ID::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:android.os.CpuFreqProto)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 jiffy_hz = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (8 & 0xFF)) {
          _Internal::set_has_jiffy_hz(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::int32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32>(
                 input, &jiffy_hz_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .android.os.CpuFreqProto.Stats cpu_freqs = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
                input, add_cpu_freqs()));
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
  // @@protoc_insertion_point(parse_success:android.os.CpuFreqProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:android.os.CpuFreqProto)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CpuFreqProto::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:android.os.CpuFreqProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 jiffy_hz = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32(1, this->jiffy_hz(), output);
  }

  // repeated .android.os.CpuFreqProto.Stats cpu_freqs = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->cpu_freqs_size()); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessage(
      2,
      this->cpu_freqs(static_cast<int>(i)),
      output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:android.os.CpuFreqProto)
}

size_t CpuFreqProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:android.os.CpuFreqProto)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .android.os.CpuFreqProto.Stats cpu_freqs = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->cpu_freqs_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          this->cpu_freqs(static_cast<int>(i)));
    }
  }

  // optional int32 jiffy_hz = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->jiffy_hz());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CpuFreqProto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const CpuFreqProto*>(
      &from));
}

void CpuFreqProto::MergeFrom(const CpuFreqProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:android.os.CpuFreqProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cpu_freqs_.MergeFrom(from.cpu_freqs_);
  if (from.has_jiffy_hz()) {
    set_jiffy_hz(from.jiffy_hz());
  }
}

void CpuFreqProto::CopyFrom(const CpuFreqProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:android.os.CpuFreqProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CpuFreqProto::IsInitialized() const {
  return true;
}

void CpuFreqProto::InternalSwap(CpuFreqProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  CastToBase(&cpu_freqs_)->InternalSwap(CastToBase(&other->cpu_freqs_));
  swap(jiffy_hz_, other->jiffy_hz_);
}

std::string CpuFreqProto::GetTypeName() const {
  return "android.os.CpuFreqProto";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace os
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::android::os::CpuFreqProto_Stats_TimeInState* Arena::CreateMaybeMessage< ::android::os::CpuFreqProto_Stats_TimeInState >(Arena* arena) {
  return Arena::CreateInternal< ::android::os::CpuFreqProto_Stats_TimeInState >(arena);
}
template<> PROTOBUF_NOINLINE ::android::os::CpuFreqProto_Stats* Arena::CreateMaybeMessage< ::android::os::CpuFreqProto_Stats >(Arena* arena) {
  return Arena::CreateInternal< ::android::os::CpuFreqProto_Stats >(arena);
}
template<> PROTOBUF_NOINLINE ::android::os::CpuFreqProto* Arena::CreateMaybeMessage< ::android::os::CpuFreqProto >(Arena* arena) {
  return Arena::CreateInternal< ::android::os::CpuFreqProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
