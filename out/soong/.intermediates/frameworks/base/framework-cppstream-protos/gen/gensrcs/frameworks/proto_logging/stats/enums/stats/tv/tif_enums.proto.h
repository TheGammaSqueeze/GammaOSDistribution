// Generated by protoc-gen-cppstream. DO NOT MODIFY.
// source: frameworks/proto_logging/stats/enums/stats/tv/tif_enums.proto

#ifndef ANDROID_FRAMEWORKS_PROTO_LOGGING_STATS_ENUMS_STATS_TV_TIF_ENUMS_PROTO_STREAM_H
#define ANDROID_FRAMEWORKS_PROTO_LOGGING_STATS_ENUMS_STATS_TV_TIF_ENUMS_PROTO_STREAM_H

namespace android {
namespace stats {
namespace tv {

// enum TifTuneState
const int TIF_TUNE_STATE_UNKNOWN = 0;
const int CREATED = 1;
const int SURFACE_ATTACHED = 2;
const int SURFACE_DETACHED = 3;
const int RELEASED = 4;
const int TUNE_STARTED = 5;
const int VIDEO_AVAILABLE = 6;
const int VIDEO_UNAVAILABLE_REASON_UNKNOWN = 100;
const int VIDEO_UNAVAILABLE_REASON_TUNING = 101;
const int VIDEO_UNAVAILABLE_REASON_WEAK_SIGNAL = 102;
const int VIDEO_UNAVAILABLE_REASON_BUFFERING = 103;
const int VIDEO_UNAVAILABLE_REASON_AUDIO_ONLY = 104;
const int VIDEO_UNAVAILABLE_REASON_NOT_CONNECTED = 105;
const int VIDEO_UNAVAILABLE_REASON_INSUFFICIENT_RESOURCE = 106;
const int VIDEO_UNAVAILABLE_REASON_CAS_INSUFFICIENT_OUTPUT_PROTECTION = 107;
const int VIDEO_UNAVAILABLE_REASON_CAS_PVR_RECORDING_NOT_ALLOWED = 108;
const int VIDEO_UNAVAILABLE_REASON_CAS_NO_LICENSE = 109;
const int VIDEO_UNAVAILABLE_REASON_CAS_LICENSE_EXPIRED = 110;
const int VIDEO_UNAVAILABLE_REASON_CAS_NEED_ACTIVATION = 111;
const int VIDEO_UNAVAILABLE_REASON_CAS_NEED_PAIRING = 112;
const int VIDEO_UNAVAILABLE_REASON_CAS_NO_CARD = 113;
const int VIDEO_UNAVAILABLE_REASON_CAS_CARD_MUTE = 114;
const int VIDEO_UNAVAILABLE_REASON_CAS_CARD_INVALID = 115;
const int VIDEO_UNAVAILABLE_REASON_CAS_BLACKOUT = 116;
const int VIDEO_UNAVAILABLE_REASON_CAS_REBOOTING = 117;
const int VIDEO_UNAVAILABLE_REASON_CAS_UNKNOWN = 118;
static const int _ENUM_TIF_TUNE_STATE_COUNT = 26;
static const char* _ENUM_TIF_TUNE_STATE_NAMES[26] = {
    "UNKNOWN",
    "CREATED",
    "SURFACE_ATTACHED",
    "SURFACE_DETACHED",
    "RELEASED",
    "TUNE_STARTED",
    "VIDEO_AVAILABLE",
    "VIDEO_UNAVAILABLE_REASON_UNKNOWN",
    "VIDEO_UNAVAILABLE_REASON_TUNING",
    "VIDEO_UNAVAILABLE_REASON_WEAK_SIGNAL",
    "VIDEO_UNAVAILABLE_REASON_BUFFERING",
    "VIDEO_UNAVAILABLE_REASON_AUDIO_ONLY",
    "VIDEO_UNAVAILABLE_REASON_NOT_CONNECTED",
    "VIDEO_UNAVAILABLE_REASON_INSUFFICIENT_RESOURCE",
    "VIDEO_UNAVAILABLE_REASON_CAS_INSUFFICIENT_OUTPUT_PROTECTION",
    "VIDEO_UNAVAILABLE_REASON_CAS_PVR_RECORDING_NOT_ALLOWED",
    "VIDEO_UNAVAILABLE_REASON_CAS_NO_LICENSE",
    "VIDEO_UNAVAILABLE_REASON_CAS_LICENSE_EXPIRED",
    "VIDEO_UNAVAILABLE_REASON_CAS_NEED_ACTIVATION",
    "VIDEO_UNAVAILABLE_REASON_CAS_NEED_PAIRING",
    "VIDEO_UNAVAILABLE_REASON_CAS_NO_CARD",
    "VIDEO_UNAVAILABLE_REASON_CAS_CARD_MUTE",
    "VIDEO_UNAVAILABLE_REASON_CAS_CARD_INVALID",
    "VIDEO_UNAVAILABLE_REASON_CAS_BLACKOUT",
    "VIDEO_UNAVAILABLE_REASON_CAS_REBOOTING",
    "VIDEO_UNAVAILABLE_REASON_CAS_UNKNOWN",
};
static const int _ENUM_TIF_TUNE_STATE_VALUES[26] = {
    TIF_TUNE_STATE_UNKNOWN,
    CREATED,
    SURFACE_ATTACHED,
    SURFACE_DETACHED,
    RELEASED,
    TUNE_STARTED,
    VIDEO_AVAILABLE,
    VIDEO_UNAVAILABLE_REASON_UNKNOWN,
    VIDEO_UNAVAILABLE_REASON_TUNING,
    VIDEO_UNAVAILABLE_REASON_WEAK_SIGNAL,
    VIDEO_UNAVAILABLE_REASON_BUFFERING,
    VIDEO_UNAVAILABLE_REASON_AUDIO_ONLY,
    VIDEO_UNAVAILABLE_REASON_NOT_CONNECTED,
    VIDEO_UNAVAILABLE_REASON_INSUFFICIENT_RESOURCE,
    VIDEO_UNAVAILABLE_REASON_CAS_INSUFFICIENT_OUTPUT_PROTECTION,
    VIDEO_UNAVAILABLE_REASON_CAS_PVR_RECORDING_NOT_ALLOWED,
    VIDEO_UNAVAILABLE_REASON_CAS_NO_LICENSE,
    VIDEO_UNAVAILABLE_REASON_CAS_LICENSE_EXPIRED,
    VIDEO_UNAVAILABLE_REASON_CAS_NEED_ACTIVATION,
    VIDEO_UNAVAILABLE_REASON_CAS_NEED_PAIRING,
    VIDEO_UNAVAILABLE_REASON_CAS_NO_CARD,
    VIDEO_UNAVAILABLE_REASON_CAS_CARD_MUTE,
    VIDEO_UNAVAILABLE_REASON_CAS_CARD_INVALID,
    VIDEO_UNAVAILABLE_REASON_CAS_BLACKOUT,
    VIDEO_UNAVAILABLE_REASON_CAS_REBOOTING,
    VIDEO_UNAVAILABLE_REASON_CAS_UNKNOWN,
};

// enum TifInputType
const int TIF_INPUT_TYPE_UNKNOWN = 0;
const int TUNER = 1;
const int OTHER = 1000;
const int COMPOSITE = 1001;
const int SVIDEO = 1002;
const int SCART = 1003;
const int COMPONENT = 1004;
const int VGA = 1005;
const int DVI = 1006;
const int HDMI = 1007;
const int DISPLAY_PORT = 1008;
static const int _ENUM_TIF_INPUT_TYPE_COUNT = 11;
static const char* _ENUM_TIF_INPUT_TYPE_NAMES[11] = {
    "UNKNOWN",
    "TUNER",
    "OTHER",
    "COMPOSITE",
    "SVIDEO",
    "SCART",
    "COMPONENT",
    "VGA",
    "DVI",
    "HDMI",
    "DISPLAY_PORT",
};
static const int _ENUM_TIF_INPUT_TYPE_VALUES[11] = {
    TIF_INPUT_TYPE_UNKNOWN,
    TUNER,
    OTHER,
    COMPOSITE,
    SVIDEO,
    SCART,
    COMPONENT,
    VGA,
    DVI,
    HDMI,
    DISPLAY_PORT,
};

} // tv
} // stats
} // android

#endif // ANDROID_FRAMEWORKS_PROTO_LOGGING_STATS_ENUMS_STATS_TV_TIF_ENUMS_PROTO_STREAM_H
