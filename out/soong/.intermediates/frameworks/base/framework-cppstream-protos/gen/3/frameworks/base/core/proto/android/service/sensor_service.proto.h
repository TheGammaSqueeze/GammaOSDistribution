// Generated by protoc-gen-cppstream. DO NOT MODIFY.
// source: frameworks/base/core/proto/android/service/sensor_service.proto

#ifndef ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_SERVICE_SENSOR_SERVICE_PROTO_STREAM_H
#define ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_SERVICE_SENSOR_SERVICE_PROTO_STREAM_H

namespace android {
namespace service {

// message SensorServiceProto
namespace SensorServiceProto {
    // enum OperatingModeEnum
    const int OP_MODE_UNKNOWN = 0;
    const int OP_MODE_NORMAL = 1;
    const int OP_MODE_RESTRICTED = 2;
    const int OP_MODE_DATA_INJECTION = 3;
    static const int _ENUM_OPERATING_MODE_ENUM_COUNT = 4;
    static const char* _ENUM_OPERATING_MODE_ENUM_NAMES[4] = {
        "OP_MODE_UNKNOWN",
        "OP_MODE_NORMAL",
        "OP_MODE_RESTRICTED",
        "OP_MODE_DATA_INJECTION",
    };
    static const int _ENUM_OPERATING_MODE_ENUM_VALUES[4] = {
        OP_MODE_UNKNOWN,
        OP_MODE_NORMAL,
        OP_MODE_RESTRICTED,
        OP_MODE_DATA_INJECTION,
    };

    // optional sint32 init_status = 16;
    const uint64_t INIT_STATUS = 0x0000011100000010LL;

    // optional int64 current_time_ms = 1;
    const uint64_t CURRENT_TIME_MS = 0x0000010300000001LL;

    // optional .android.service.SensorDeviceProto sensor_device = 2;
    const uint64_t SENSOR_DEVICE = 0x0000010b00000002LL;

    // optional .android.service.SensorListProto sensors = 3;
    const uint64_t SENSORS = 0x0000010b00000003LL;

    // optional .android.service.SensorFusionProto fusion_state = 4;
    const uint64_t FUSION_STATE = 0x0000010b00000004LL;

    // optional .android.service.SensorEventsProto sensor_events = 5;
    const uint64_t SENSOR_EVENTS = 0x0000010b00000005LL;

    // repeated .android.service.ActiveSensorProto active_sensors = 6;
    const uint64_t ACTIVE_SENSORS = 0x0000020b00000006LL;

    // optional int32 socket_buffer_size = 7;
    const uint64_t SOCKET_BUFFER_SIZE = 0x0000010500000007LL;

    // optional int32 socket_buffer_size_in_events = 8;
    const uint64_t SOCKET_BUFFER_SIZE_IN_EVENTS = 0x0000010500000008LL;

    // optional bool wake_lock_acquired = 9;
    const uint64_t WAKE_LOCK_ACQUIRED = 0x0000010800000009LL;

    // optional .android.service.SensorServiceProto.OperatingModeEnum operating_mode = 10;
    const uint64_t OPERATING_MODE = 0x0000010e0000000aLL;

    // optional string whitelisted_package = 11;
    const uint64_t WHITELISTED_PACKAGE = 0x000001090000000bLL;

    // optional bool sensor_privacy = 12;
    const uint64_t SENSOR_PRIVACY = 0x000001080000000cLL;

    // repeated .android.service.SensorEventConnectionProto active_connections = 13;
    const uint64_t ACTIVE_CONNECTIONS = 0x0000020b0000000dLL;

    // repeated .android.service.SensorDirectConnectionProto direct_connections = 14;
    const uint64_t DIRECT_CONNECTIONS = 0x0000020b0000000eLL;

    // repeated .android.service.SensorRegistrationInfoProto previous_registrations = 15;
    const uint64_t PREVIOUS_REGISTRATIONS = 0x0000020b0000000fLL;

    static const int _FIELD_COUNT = 16;
    static const char* _FIELD_NAMES[16] = {
        "init_status",
        "current_time_ms",
        "sensor_device",
        "sensors",
        "fusion_state",
        "sensor_events",
        "active_sensors",
        "socket_buffer_size",
        "socket_buffer_size_in_events",
        "wake_lock_acquired",
        "operating_mode",
        "whitelisted_package",
        "sensor_privacy",
        "active_connections",
        "direct_connections",
        "previous_registrations",
    };
    static const uint64_t _FIELD_IDS[16] = {
        INIT_STATUS,
        CURRENT_TIME_MS,
        SENSOR_DEVICE,
        SENSORS,
        FUSION_STATE,
        SENSOR_EVENTS,
        ACTIVE_SENSORS,
        SOCKET_BUFFER_SIZE,
        SOCKET_BUFFER_SIZE_IN_EVENTS,
        WAKE_LOCK_ACQUIRED,
        OPERATING_MODE,
        WHITELISTED_PACKAGE,
        SENSOR_PRIVACY,
        ACTIVE_CONNECTIONS,
        DIRECT_CONNECTIONS,
        PREVIOUS_REGISTRATIONS,
    };

} //SensorServiceProto

// message SensorDeviceProto
namespace SensorDeviceProto {
    // message SensorProto
    namespace SensorProto {
        // optional int32 handle = 1;
        const uint64_t HANDLE = 0x0000010500000001LL;

        // optional int32 active_count = 2;
        const uint64_t ACTIVE_COUNT = 0x0000010500000002LL;

        // repeated float sampling_period_ms = 3;
        const uint64_t SAMPLING_PERIOD_MS = 0x0000020200000003LL;

        // optional float sampling_period_selected = 4;
        const uint64_t SAMPLING_PERIOD_SELECTED = 0x0000010200000004LL;

        // repeated float batching_period_ms = 5;
        const uint64_t BATCHING_PERIOD_MS = 0x0000020200000005LL;

        // optional float batching_period_selected = 6;
        const uint64_t BATCHING_PERIOD_SELECTED = 0x0000010200000006LL;

        static const int _FIELD_COUNT = 6;
        static const char* _FIELD_NAMES[6] = {
            "handle",
            "active_count",
            "sampling_period_ms",
            "sampling_period_selected",
            "batching_period_ms",
            "batching_period_selected",
        };
        static const uint64_t _FIELD_IDS[6] = {
            HANDLE,
            ACTIVE_COUNT,
            SAMPLING_PERIOD_MS,
            SAMPLING_PERIOD_SELECTED,
            BATCHING_PERIOD_MS,
            BATCHING_PERIOD_SELECTED,
        };

    } //SensorProto

    // optional bool initialized = 1;
    const uint64_t INITIALIZED = 0x0000010800000001LL;

    // optional int32 total_sensors = 2;
    const uint64_t TOTAL_SENSORS = 0x0000010500000002LL;

    // optional int32 active_sensors = 3;
    const uint64_t ACTIVE_SENSORS = 0x0000010500000003LL;

    // repeated .android.service.SensorDeviceProto.SensorProto sensors = 4;
    const uint64_t SENSORS = 0x0000020b00000004LL;

    static const int _FIELD_COUNT = 4;
    static const char* _FIELD_NAMES[4] = {
        "initialized",
        "total_sensors",
        "active_sensors",
        "sensors",
    };
    static const uint64_t _FIELD_IDS[4] = {
        INITIALIZED,
        TOTAL_SENSORS,
        ACTIVE_SENSORS,
        SENSORS,
    };

} //SensorDeviceProto

// message SensorListProto
namespace SensorListProto {
    // enum ReportingModeEnum
    const int RM_UNKNOWN = 0;
    const int RM_CONTINUOUS = 1;
    const int RM_ON_CHANGE = 2;
    const int RM_ONE_SHOT = 3;
    const int RM_SPECIAL_TRIGGER = 4;
    static const int _ENUM_REPORTING_MODE_ENUM_COUNT = 5;
    static const char* _ENUM_REPORTING_MODE_ENUM_NAMES[5] = {
        "RM_UNKNOWN",
        "RM_CONTINUOUS",
        "RM_ON_CHANGE",
        "RM_ONE_SHOT",
        "RM_SPECIAL_TRIGGER",
    };
    static const int _ENUM_REPORTING_MODE_ENUM_VALUES[5] = {
        RM_UNKNOWN,
        RM_CONTINUOUS,
        RM_ON_CHANGE,
        RM_ONE_SHOT,
        RM_SPECIAL_TRIGGER,
    };

    // message SensorProto
    namespace SensorProto {
        // optional int32 handle = 1;
        const uint64_t HANDLE = 0x0000010500000001LL;

        // optional string name = 2;
        const uint64_t NAME = 0x0000010900000002LL;

        // optional string vendor = 3;
        const uint64_t VENDOR = 0x0000010900000003LL;

        // optional int32 version = 4;
        const uint64_t VERSION = 0x0000010500000004LL;

        // optional string string_type = 5;
        const uint64_t STRING_TYPE = 0x0000010900000005LL;

        // optional int32 type = 6;
        const uint64_t TYPE = 0x0000010500000006LL;

        // optional string required_permission = 7;
        const uint64_t REQUIRED_PERMISSION = 0x0000010900000007LL;

        // optional int32 flags = 8;
        const uint64_t FLAGS = 0x0000010500000008LL;

        // optional .android.service.SensorListProto.ReportingModeEnum reporting_mode = 9;
        const uint64_t REPORTING_MODE = 0x0000010e00000009LL;

        // optional int32 max_delay_us = 10;
        const uint64_t MAX_DELAY_US = 0x000001050000000aLL;

        // optional int32 min_delay_us = 11;
        const uint64_t MIN_DELAY_US = 0x000001050000000bLL;

        // optional int32 fifo_max_event_count = 12;
        const uint64_t FIFO_MAX_EVENT_COUNT = 0x000001050000000cLL;

        // optional int32 fifo_reserved_event_count = 13;
        const uint64_t FIFO_RESERVED_EVENT_COUNT = 0x000001050000000dLL;

        // optional bool is_wakeup = 14;
        const uint64_t IS_WAKEUP = 0x000001080000000eLL;

        // optional bool data_injection_supported = 15;
        const uint64_t DATA_INJECTION_SUPPORTED = 0x000001080000000fLL;

        // optional bool is_dynamic = 16;
        const uint64_t IS_DYNAMIC = 0x0000010800000010LL;

        // optional bool has_additional_info = 17;
        const uint64_t HAS_ADDITIONAL_INFO = 0x0000010800000011LL;

        // optional int32 highest_rate_level = 18;
        const uint64_t HIGHEST_RATE_LEVEL = 0x0000010500000012LL;

        // optional bool ashmem = 19;
        const uint64_t ASHMEM = 0x0000010800000013LL;

        // optional bool gralloc = 20;
        const uint64_t GRALLOC = 0x0000010800000014LL;

        // optional float min_value = 21;
        const uint64_t MIN_VALUE = 0x0000010200000015LL;

        // optional float max_value = 22;
        const uint64_t MAX_VALUE = 0x0000010200000016LL;

        // optional float resolution = 23;
        const uint64_t RESOLUTION = 0x0000010200000017LL;

        // optional float power_usage = 24;
        const uint64_t POWER_USAGE = 0x0000010200000018LL;

        static const int _FIELD_COUNT = 24;
        static const char* _FIELD_NAMES[24] = {
            "handle",
            "name",
            "vendor",
            "version",
            "string_type",
            "type",
            "required_permission",
            "flags",
            "reporting_mode",
            "max_delay_us",
            "min_delay_us",
            "fifo_max_event_count",
            "fifo_reserved_event_count",
            "is_wakeup",
            "data_injection_supported",
            "is_dynamic",
            "has_additional_info",
            "highest_rate_level",
            "ashmem",
            "gralloc",
            "min_value",
            "max_value",
            "resolution",
            "power_usage",
        };
        static const uint64_t _FIELD_IDS[24] = {
            HANDLE,
            NAME,
            VENDOR,
            VERSION,
            STRING_TYPE,
            TYPE,
            REQUIRED_PERMISSION,
            FLAGS,
            REPORTING_MODE,
            MAX_DELAY_US,
            MIN_DELAY_US,
            FIFO_MAX_EVENT_COUNT,
            FIFO_RESERVED_EVENT_COUNT,
            IS_WAKEUP,
            DATA_INJECTION_SUPPORTED,
            IS_DYNAMIC,
            HAS_ADDITIONAL_INFO,
            HIGHEST_RATE_LEVEL,
            ASHMEM,
            GRALLOC,
            MIN_VALUE,
            MAX_VALUE,
            RESOLUTION,
            POWER_USAGE,
        };

    } //SensorProto

    // repeated .android.service.SensorListProto.SensorProto sensors = 1;
    const uint64_t SENSORS = 0x0000020b00000001LL;

    static const int _FIELD_COUNT = 1;
    static const char* _FIELD_NAMES[1] = {
        "sensors",
    };
    static const uint64_t _FIELD_IDS[1] = {
        SENSORS,
    };

} //SensorListProto

// message SensorFusionProto
namespace SensorFusionProto {
    // message FusionProto
    namespace FusionProto {
        // optional bool enabled = 1;
        const uint64_t ENABLED = 0x0000010800000001LL;

        // optional int32 num_clients = 2;
        const uint64_t NUM_CLIENTS = 0x0000010500000002LL;

        // optional float estimated_gyro_rate = 3;
        const uint64_t ESTIMATED_GYRO_RATE = 0x0000010200000003LL;

        // optional float attitude_x = 4;
        const uint64_t ATTITUDE_X = 0x0000010200000004LL;

        // optional float attitude_y = 5;
        const uint64_t ATTITUDE_Y = 0x0000010200000005LL;

        // optional float attitude_z = 6;
        const uint64_t ATTITUDE_Z = 0x0000010200000006LL;

        // optional float attitude_w = 7;
        const uint64_t ATTITUDE_W = 0x0000010200000007LL;

        // optional float attitude_length = 8;
        const uint64_t ATTITUDE_LENGTH = 0x0000010200000008LL;

        // optional float bias_x = 9;
        const uint64_t BIAS_X = 0x0000010200000009LL;

        // optional float bias_y = 10;
        const uint64_t BIAS_Y = 0x000001020000000aLL;

        // optional float bias_z = 11;
        const uint64_t BIAS_Z = 0x000001020000000bLL;

        static const int _FIELD_COUNT = 11;
        static const char* _FIELD_NAMES[11] = {
            "enabled",
            "num_clients",
            "estimated_gyro_rate",
            "attitude_x",
            "attitude_y",
            "attitude_z",
            "attitude_w",
            "attitude_length",
            "bias_x",
            "bias_y",
            "bias_z",
        };
        static const uint64_t _FIELD_IDS[11] = {
            ENABLED,
            NUM_CLIENTS,
            ESTIMATED_GYRO_RATE,
            ATTITUDE_X,
            ATTITUDE_Y,
            ATTITUDE_Z,
            ATTITUDE_W,
            ATTITUDE_LENGTH,
            BIAS_X,
            BIAS_Y,
            BIAS_Z,
        };

    } //FusionProto

    // optional .android.service.SensorFusionProto.FusionProto fusion_9axis = 1;
    const uint64_t FUSION_9AXIS = 0x0000010b00000001LL;

    // optional .android.service.SensorFusionProto.FusionProto fusion_nomag = 2;
    const uint64_t FUSION_NOMAG = 0x0000010b00000002LL;

    // optional .android.service.SensorFusionProto.FusionProto fusion_nogyro = 3;
    const uint64_t FUSION_NOGYRO = 0x0000010b00000003LL;

    static const int _FIELD_COUNT = 3;
    static const char* _FIELD_NAMES[3] = {
        "fusion_9axis",
        "fusion_nomag",
        "fusion_nogyro",
    };
    static const uint64_t _FIELD_IDS[3] = {
        FUSION_9AXIS,
        FUSION_NOMAG,
        FUSION_NOGYRO,
    };

} //SensorFusionProto

// message SensorEventsProto
namespace SensorEventsProto {
    // message Event
    namespace Event {
        // optional float timestamp_sec = 1;
        const uint64_t TIMESTAMP_SEC = 0x0000010200000001LL;

        // optional int64 wall_timestamp_ms = 2;
        const uint64_t WALL_TIMESTAMP_MS = 0x0000010300000002LL;

        // optional bool masked = 3;
        const uint64_t MASKED = 0x0000010800000003LL;

        // optional int64 int64_data = 4;
        const uint64_t INT64_DATA = 0x0000010300000004LL;

        // repeated float float_array = 5;
        const uint64_t FLOAT_ARRAY = 0x0000020200000005LL;

        static const int _FIELD_COUNT = 5;
        static const char* _FIELD_NAMES[5] = {
            "timestamp_sec",
            "wall_timestamp_ms",
            "masked",
            "int64_data",
            "float_array",
        };
        static const uint64_t _FIELD_IDS[5] = {
            TIMESTAMP_SEC,
            WALL_TIMESTAMP_MS,
            MASKED,
            INT64_DATA,
            FLOAT_ARRAY,
        };

    } //Event

    // message RecentEventsLog
    namespace RecentEventsLog {
        // optional string name = 1;
        const uint64_t NAME = 0x0000010900000001LL;

        // optional int32 recent_events_count = 2;
        const uint64_t RECENT_EVENTS_COUNT = 0x0000010500000002LL;

        // repeated .android.service.SensorEventsProto.Event events = 3;
        const uint64_t EVENTS = 0x0000020b00000003LL;

        static const int _FIELD_COUNT = 3;
        static const char* _FIELD_NAMES[3] = {
            "name",
            "recent_events_count",
            "events",
        };
        static const uint64_t _FIELD_IDS[3] = {
            NAME,
            RECENT_EVENTS_COUNT,
            EVENTS,
        };

    } //RecentEventsLog

    // repeated .android.service.SensorEventsProto.RecentEventsLog recent_events_logs = 1;
    const uint64_t RECENT_EVENTS_LOGS = 0x0000020b00000001LL;

    static const int _FIELD_COUNT = 1;
    static const char* _FIELD_NAMES[1] = {
        "recent_events_logs",
    };
    static const uint64_t _FIELD_IDS[1] = {
        RECENT_EVENTS_LOGS,
    };

} //SensorEventsProto

// message ActiveSensorProto
namespace ActiveSensorProto {
    // optional string name = 1;
    const uint64_t NAME = 0x0000010900000001LL;

    // optional int32 handle = 2;
    const uint64_t HANDLE = 0x0000010500000002LL;

    // optional int32 num_connections = 3;
    const uint64_t NUM_CONNECTIONS = 0x0000010500000003LL;

    static const int _FIELD_COUNT = 3;
    static const char* _FIELD_NAMES[3] = {
        "name",
        "handle",
        "num_connections",
    };
    static const uint64_t _FIELD_IDS[3] = {
        NAME,
        HANDLE,
        NUM_CONNECTIONS,
    };

} //ActiveSensorProto

// message SensorDirectConnectionProto
namespace SensorDirectConnectionProto {
    // message SensorProto
    namespace SensorProto {
        // optional int32 sensor = 1;
        const uint64_t SENSOR = 0x0000010500000001LL;

        // optional int32 rate = 2;
        const uint64_t RATE = 0x0000010500000002LL;

        static const int _FIELD_COUNT = 2;
        static const char* _FIELD_NAMES[2] = {
            "sensor",
            "rate",
        };
        static const uint64_t _FIELD_IDS[2] = {
            SENSOR,
            RATE,
        };

    } //SensorProto

    // optional string package_name = 1;
    const uint64_t PACKAGE_NAME = 0x0000010900000001LL;

    // optional int32 hal_channel_handle = 2;
    const uint64_t HAL_CHANNEL_HANDLE = 0x0000010500000002LL;

    // optional int32 num_sensor_activated = 3;
    const uint64_t NUM_SENSOR_ACTIVATED = 0x0000010500000003LL;

    // repeated .android.service.SensorDirectConnectionProto.SensorProto sensors = 4;
    const uint64_t SENSORS = 0x0000020b00000004LL;

    static const int _FIELD_COUNT = 4;
    static const char* _FIELD_NAMES[4] = {
        "package_name",
        "hal_channel_handle",
        "num_sensor_activated",
        "sensors",
    };
    static const uint64_t _FIELD_IDS[4] = {
        PACKAGE_NAME,
        HAL_CHANNEL_HANDLE,
        NUM_SENSOR_ACTIVATED,
        SENSORS,
    };

} //SensorDirectConnectionProto

// message SensorEventConnectionProto
namespace SensorEventConnectionProto {
    // enum OperatingModeEnum
    const int OP_MODE_UNKNOWN = 0;
    const int OP_MODE_NORMAL = 1;
    const int OP_MODE_RESTRICTED = 2;
    const int OP_MODE_DATA_INJECTION = 3;
    static const int _ENUM_OPERATING_MODE_ENUM_COUNT = 4;
    static const char* _ENUM_OPERATING_MODE_ENUM_NAMES[4] = {
        "OP_MODE_UNKNOWN",
        "OP_MODE_NORMAL",
        "OP_MODE_RESTRICTED",
        "OP_MODE_DATA_INJECTION",
    };
    static const int _ENUM_OPERATING_MODE_ENUM_VALUES[4] = {
        OP_MODE_UNKNOWN,
        OP_MODE_NORMAL,
        OP_MODE_RESTRICTED,
        OP_MODE_DATA_INJECTION,
    };

    // message FlushInfoProto
    namespace FlushInfoProto {
        // optional string sensor_name = 1;
        const uint64_t SENSOR_NAME = 0x0000010900000001LL;

        // optional int32 sensor_handle = 2;
        const uint64_t SENSOR_HANDLE = 0x0000010500000002LL;

        // optional bool first_flush_pending = 3;
        const uint64_t FIRST_FLUSH_PENDING = 0x0000010800000003LL;

        // optional int32 pending_flush_events_to_send = 4;
        const uint64_t PENDING_FLUSH_EVENTS_TO_SEND = 0x0000010500000004LL;

        static const int _FIELD_COUNT = 4;
        static const char* _FIELD_NAMES[4] = {
            "sensor_name",
            "sensor_handle",
            "first_flush_pending",
            "pending_flush_events_to_send",
        };
        static const uint64_t _FIELD_IDS[4] = {
            SENSOR_NAME,
            SENSOR_HANDLE,
            FIRST_FLUSH_PENDING,
            PENDING_FLUSH_EVENTS_TO_SEND,
        };

    } //FlushInfoProto

    // optional .android.service.SensorEventConnectionProto.OperatingModeEnum operating_mode = 1;
    const uint64_t OPERATING_MODE = 0x0000010e00000001LL;

    // optional string package_name = 2;
    const uint64_t PACKAGE_NAME = 0x0000010900000002LL;

    // optional int32 wake_lock_ref_count = 3;
    const uint64_t WAKE_LOCK_REF_COUNT = 0x0000010500000003LL;

    // optional int32 uid = 4;
    const uint64_t UID = 0x0000010500000004LL;

    // optional int32 cache_size = 5;
    const uint64_t CACHE_SIZE = 0x0000010500000005LL;

    // optional int32 max_cache_size = 6;
    const uint64_t MAX_CACHE_SIZE = 0x0000010500000006LL;

    // repeated .android.service.SensorEventConnectionProto.FlushInfoProto flush_infos = 7;
    const uint64_t FLUSH_INFOS = 0x0000020b00000007LL;

    // optional int32 events_received = 8;
    const uint64_t EVENTS_RECEIVED = 0x0000010500000008LL;

    // optional int32 events_sent = 9;
    const uint64_t EVENTS_SENT = 0x0000010500000009LL;

    // optional int32 events_cache = 10;
    const uint64_t EVENTS_CACHE = 0x000001050000000aLL;

    // optional int32 events_dropped = 11;
    const uint64_t EVENTS_DROPPED = 0x000001050000000bLL;

    // optional int32 total_acks_needed = 12;
    const uint64_t TOTAL_ACKS_NEEDED = 0x000001050000000cLL;

    // optional int32 total_acks_received = 13;
    const uint64_t TOTAL_ACKS_RECEIVED = 0x000001050000000dLL;

    static const int _FIELD_COUNT = 13;
    static const char* _FIELD_NAMES[13] = {
        "operating_mode",
        "package_name",
        "wake_lock_ref_count",
        "uid",
        "cache_size",
        "max_cache_size",
        "flush_infos",
        "events_received",
        "events_sent",
        "events_cache",
        "events_dropped",
        "total_acks_needed",
        "total_acks_received",
    };
    static const uint64_t _FIELD_IDS[13] = {
        OPERATING_MODE,
        PACKAGE_NAME,
        WAKE_LOCK_REF_COUNT,
        UID,
        CACHE_SIZE,
        MAX_CACHE_SIZE,
        FLUSH_INFOS,
        EVENTS_RECEIVED,
        EVENTS_SENT,
        EVENTS_CACHE,
        EVENTS_DROPPED,
        TOTAL_ACKS_NEEDED,
        TOTAL_ACKS_RECEIVED,
    };

} //SensorEventConnectionProto

// message SensorRegistrationInfoProto
namespace SensorRegistrationInfoProto {
    // optional int64 timestamp_sec = 1;
    const uint64_t TIMESTAMP_SEC = 0x0000010300000001LL;

    // optional int32 sensor_handle = 2;
    const uint64_t SENSOR_HANDLE = 0x0000010500000002LL;

    // optional string package_name = 3;
    const uint64_t PACKAGE_NAME = 0x0000010900000003LL;

    // optional int32 pid = 4;
    const uint64_t PID = 0x0000010500000004LL;

    // optional int32 uid = 5;
    const uint64_t UID = 0x0000010500000005LL;

    // optional int64 sampling_rate_us = 6;
    const uint64_t SAMPLING_RATE_US = 0x0000010300000006LL;

    // optional int64 max_report_latency_us = 7;
    const uint64_t MAX_REPORT_LATENCY_US = 0x0000010300000007LL;

    // optional bool activated = 8;
    const uint64_t ACTIVATED = 0x0000010800000008LL;

    static const int _FIELD_COUNT = 8;
    static const char* _FIELD_NAMES[8] = {
        "timestamp_sec",
        "sensor_handle",
        "package_name",
        "pid",
        "uid",
        "sampling_rate_us",
        "max_report_latency_us",
        "activated",
    };
    static const uint64_t _FIELD_IDS[8] = {
        TIMESTAMP_SEC,
        SENSOR_HANDLE,
        PACKAGE_NAME,
        PID,
        UID,
        SAMPLING_RATE_US,
        MAX_REPORT_LATENCY_US,
        ACTIVATED,
    };

} //SensorRegistrationInfoProto

} // service
} // android

#endif // ANDROID_FRAMEWORKS_BASE_CORE_PROTO_ANDROID_SERVICE_SENSOR_SERVICE_PROTO_STREAM_H
