// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/proto_logging/stats/enums/debug/enums.proto

#include "frameworks/proto_logging/stats/enums/debug/enums.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace android {
namespace debug {
}  // namespace debug
}  // namespace android
namespace android {
namespace debug {
bool AdbConnectionStateEnum_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> AdbConnectionStateEnum_strings[8] = {};

static const char AdbConnectionStateEnum_names[] =
  "AUTOMATICALLY_ALLOWED"
  "AWAITING_USER_APPROVAL"
  "DENIED_INVALID_KEY"
  "DENIED_VOLD_DECRYPT"
  "DISCONNECTED"
  "UNKNOWN"
  "USER_ALLOWED"
  "USER_DENIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry AdbConnectionStateEnum_entries[] = {
  { {AdbConnectionStateEnum_names + 0, 21}, 4 },
  { {AdbConnectionStateEnum_names + 21, 22}, 1 },
  { {AdbConnectionStateEnum_names + 43, 18}, 5 },
  { {AdbConnectionStateEnum_names + 61, 19}, 6 },
  { {AdbConnectionStateEnum_names + 80, 12}, 7 },
  { {AdbConnectionStateEnum_names + 92, 7}, 0 },
  { {AdbConnectionStateEnum_names + 99, 12}, 2 },
  { {AdbConnectionStateEnum_names + 111, 11}, 3 },
};

static const int AdbConnectionStateEnum_entries_by_number[] = {
  5, // 0 -> UNKNOWN
  1, // 1 -> AWAITING_USER_APPROVAL
  6, // 2 -> USER_ALLOWED
  7, // 3 -> USER_DENIED
  0, // 4 -> AUTOMATICALLY_ALLOWED
  2, // 5 -> DENIED_INVALID_KEY
  3, // 6 -> DENIED_VOLD_DECRYPT
  4, // 7 -> DISCONNECTED
};

const std::string& AdbConnectionStateEnum_Name(
    AdbConnectionStateEnum value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          AdbConnectionStateEnum_entries,
          AdbConnectionStateEnum_entries_by_number,
          8, AdbConnectionStateEnum_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      AdbConnectionStateEnum_entries,
      AdbConnectionStateEnum_entries_by_number,
      8, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     AdbConnectionStateEnum_strings[idx].get();
}
bool AdbConnectionStateEnum_Parse(
    const std::string& name, AdbConnectionStateEnum* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      AdbConnectionStateEnum_entries, 8, name, &int_value);
  if (success) {
    *value = static_cast<AdbConnectionStateEnum>(int_value);
  }
  return success;
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace debug
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
