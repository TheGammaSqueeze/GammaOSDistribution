// Generated by protoc-gen-cppstream. DO NOT MODIFY.
// source: frameworks/base/core/proto/android/nfc/apdu_service_info.proto

#ifndef ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_NFC_APDU_SERVICE_INFO_PROTO_STREAM_H
#define ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_NFC_APDU_SERVICE_INFO_PROTO_STREAM_H

namespace android {
namespace nfc {
namespace cardemulation {

// message ApduServiceInfoProto
namespace ApduServiceInfoProto {
    // optional .android.content.ComponentNameProto component_name = 1;
    const uint64_t COMPONENT_NAME = 0x0000010b00000001LL;

    // optional string description = 2;
    const uint64_t DESCRIPTION = 0x0000010900000002LL;

    // optional bool on_host = 3;
    const uint64_t ON_HOST = 0x0000010800000003LL;

    // optional string off_host_name = 4;
    const uint64_t OFF_HOST_NAME = 0x0000010900000004LL;

    // optional string static_off_host_name = 5;
    const uint64_t STATIC_OFF_HOST_NAME = 0x0000010900000005LL;

    // repeated .android.nfc.cardemulation.AidGroupProto static_aid_groups = 6;
    const uint64_t STATIC_AID_GROUPS = 0x0000020b00000006LL;

    // repeated .android.nfc.cardemulation.AidGroupProto dynamic_aid_groups = 7;
    const uint64_t DYNAMIC_AID_GROUPS = 0x0000020b00000007LL;

    // optional string settings_activity_name = 8;
    const uint64_t SETTINGS_ACTIVITY_NAME = 0x0000010900000008LL;

    static const int _FIELD_COUNT = 8;
    static const char* _FIELD_NAMES[8] = {
        "component_name",
        "description",
        "on_host",
        "off_host_name",
        "static_off_host_name",
        "static_aid_groups",
        "dynamic_aid_groups",
        "settings_activity_name",
    };
    static const uint64_t _FIELD_IDS[8] = {
        COMPONENT_NAME,
        DESCRIPTION,
        ON_HOST,
        OFF_HOST_NAME,
        STATIC_OFF_HOST_NAME,
        STATIC_AID_GROUPS,
        DYNAMIC_AID_GROUPS,
        SETTINGS_ACTIVITY_NAME,
    };

} //ApduServiceInfoProto

} // cardemulation
} // nfc
} // android

#endif // ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_NFC_APDU_SERVICE_INFO_PROTO_STREAM_H
