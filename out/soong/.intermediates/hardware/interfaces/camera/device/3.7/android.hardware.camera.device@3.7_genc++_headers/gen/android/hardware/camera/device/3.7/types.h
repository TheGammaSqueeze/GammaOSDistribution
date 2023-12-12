#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_TYPES_H

#include <android/hardware/camera/device/3.2/types.h>
#include <android/hardware/camera/device/3.4/types.h>
#include <android/hardware/camera/metadata/3.6/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_7 {

// Forward declaration for forward reference support:
struct Stream;
struct StreamConfiguration;
struct CaptureRequest;

/**
 * Stream:
 *
 * A descriptor for a single camera input or output stream. A stream is defined
 * by the framework by its buffer resolution and format, and additionally by the
 * HAL with the gralloc usage flags and the maximum in-flight buffer count.
 *
 * This version extends the @3.4 Stream with the multi-resolution output surface
 * group Id field.
 */
struct Stream final {
    /**
     * The definition of Stream from the prior version.
     */
    ::android::hardware::camera::device::V3_4::Stream v3_4 __attribute__ ((aligned(8)));
    /**
     * The surface group id used for multi-resolution output streams.
     *
     * This works similar to the surfaceGroupId of OutputConfiguration in the
     * public API, with the exception that this is for multi-resolution image
     * reader and is used by the camera HAL to choose a target stream within
     * the same group to which images are written. All streams in the same group
     * will have the same image format, data space, and usage flag.
     *
     * The framework must only call processCaptureRequest on at most one of the
     * streams within a surface group. Depending on current active physical
     * camera backing the logical multi-camera, or the pixel mode the camera is
     * running in, the HAL can choose to request and return a buffer from any
     * stream within the same group. -1 means that this stream is an input
     * stream, or is an output stream which doesn't belong to any group.
     *
     * Streams with the same non-negative group id must have the same format and
     * usage flag.
     */
    int32_t groupId __attribute__ ((aligned(4)));
    /**
     *  The sensor pixel modes used by this stream. This can assist the camera
     *  HAL in decision making about stream combination support.
     *  If this is empty, the HAL must assume that this stream will only be used
     *  with ANDROID_SENSOR_PIXEL_MODE set to ANDROID_SENSOR_PIXEL_MODE_DEFAULT.
     */
    ::android::hardware::hidl_vec<::android::hardware::camera::metadata::V3_6::CameraMetadataEnumAndroidSensorPixelMode> sensorPixelModesUsed __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_7::Stream, v3_4) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::Stream, groupId) == 64, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::Stream, sensorPixelModesUsed) == 72, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_7::Stream) == 88, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_7::Stream) == 8, "wrong alignment");

/**
 * StreamConfiguration:
 *
 * Identical to @3.5::StreamConfiguration, except that the streams
 * vector contains @3.7::Stream.
 */
struct StreamConfiguration final {
    /**
     * An array of camera stream pointers, defining the input/output
     * configuration for the camera HAL device.
     */
    ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_7::Stream> streams __attribute__ ((aligned(8)));
    /**
     * The definition of operation mode from prior version.
     *
     */
    ::android::hardware::camera::device::V3_2::StreamConfigurationMode operationMode __attribute__ ((aligned(4)));
    /**
     * The definition of session parameters from prior version.
     */
    ::android::hardware::hidl_vec<uint8_t> sessionParams __attribute__ ((aligned(8)));
    /**
     * The definition of stream configuration counter from prior version.
     */
    uint32_t streamConfigCounter __attribute__ ((aligned(4)));
    /**
     * If an input stream is configured, whether the input stream is expected to
     * receive variable resolution images.
     *
     * This flag can only be set to true if the camera device supports
     * multi-resolution input streams by advertising input stream configurations in
     * physicalCameraMultiResolutionStreamConfigurations in its physical cameras'
     * characteristics.
     *
     * When this flag is set to true, the input stream's width and height can be
     * any one of the supported multi-resolution input stream sizes.
     */
    bool multiResolutionInputImage __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_7::StreamConfiguration, streams) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::StreamConfiguration, operationMode) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::StreamConfiguration, sessionParams) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::StreamConfiguration, streamConfigCounter) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::StreamConfiguration, multiResolutionInputImage) == 44, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_7::StreamConfiguration) == 48, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_7::StreamConfiguration) == 8, "wrong alignment");

/**
 * CaptureRequest:
 *
 * This version extends 3.4::CaptureRequest with the input buffer's width and
 * height.
 */
struct CaptureRequest final {
    /**
     * The definition of CaptureRequest from the prior version.
     */
    ::android::hardware::camera::device::V3_4::CaptureRequest v3_4 __attribute__ ((aligned(8)));
    /**
     * The width and height of the input buffer for this capture request.
     *
     * These fields will be [0, 0] if no input buffer exists in the capture
     * request.
     *
     * If the stream configuration contains an input stream and has the
     * multiResolutionInputImage flag set to true, the camera client may submit a
     * reprocessing request with input buffer size different than the
     * configured input stream size. In that case, the inputWith and inputHeight
     * fields will be the actual size of the input image.
     *
     * If the stream configuration contains an input stream and the
     * multiResolutionInputImage flag is false, the inputWidth and inputHeight must
     * match the input stream size.
     */
    uint32_t inputWidth __attribute__ ((aligned(4)));
    uint32_t inputHeight __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::camera::device::V3_7::CaptureRequest, v3_4) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::CaptureRequest, inputWidth) == 136, "wrong offset");
static_assert(offsetof(::android::hardware::camera::device::V3_7::CaptureRequest, inputHeight) == 140, "wrong offset");
static_assert(sizeof(::android::hardware::camera::device::V3_7::CaptureRequest) == 144, "wrong size");
static_assert(__alignof(::android::hardware::camera::device::V3_7::CaptureRequest) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::camera::device::V3_7::Stream& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_7::Stream& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_7::Stream& lhs, const ::android::hardware::camera::device::V3_7::Stream& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_7::Stream& lhs, const ::android::hardware::camera::device::V3_7::Stream& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_7::StreamConfiguration& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_7::StreamConfiguration& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::camera::device::V3_7::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_7::StreamConfiguration& rhs);
static inline bool operator!=(const ::android::hardware::camera::device::V3_7::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_7::StreamConfiguration& rhs);

static inline std::string toString(const ::android::hardware::camera::device::V3_7::CaptureRequest& o);
static inline void PrintTo(const ::android::hardware::camera::device::V3_7::CaptureRequest& o, ::std::ostream*);
// operator== and operator!= are not generated for CaptureRequest

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::camera::device::V3_7::Stream& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_4 = ";
    os += ::android::hardware::camera::device::V3_4::toString(o.v3_4);
    os += ", .groupId = ";
    os += ::android::hardware::toString(o.groupId);
    os += ", .sensorPixelModesUsed = ";
    os += ::android::hardware::toString(o.sensorPixelModesUsed);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_7::Stream& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_7::Stream& lhs, const ::android::hardware::camera::device::V3_7::Stream& rhs) {
    if (lhs.v3_4 != rhs.v3_4) {
        return false;
    }
    if (lhs.groupId != rhs.groupId) {
        return false;
    }
    if (lhs.sensorPixelModesUsed != rhs.sensorPixelModesUsed) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_7::Stream& lhs, const ::android::hardware::camera::device::V3_7::Stream& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_7::StreamConfiguration& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".streams = ";
    os += ::android::hardware::toString(o.streams);
    os += ", .operationMode = ";
    os += ::android::hardware::camera::device::V3_2::toString(o.operationMode);
    os += ", .sessionParams = ";
    os += ::android::hardware::toString(o.sessionParams);
    os += ", .streamConfigCounter = ";
    os += ::android::hardware::toString(o.streamConfigCounter);
    os += ", .multiResolutionInputImage = ";
    os += ::android::hardware::toString(o.multiResolutionInputImage);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_7::StreamConfiguration& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::camera::device::V3_7::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_7::StreamConfiguration& rhs) {
    if (lhs.streams != rhs.streams) {
        return false;
    }
    if (lhs.operationMode != rhs.operationMode) {
        return false;
    }
    if (lhs.sessionParams != rhs.sessionParams) {
        return false;
    }
    if (lhs.streamConfigCounter != rhs.streamConfigCounter) {
        return false;
    }
    if (lhs.multiResolutionInputImage != rhs.multiResolutionInputImage) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::camera::device::V3_7::StreamConfiguration& lhs, const ::android::hardware::camera::device::V3_7::StreamConfiguration& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::camera::device::V3_7::CaptureRequest& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v3_4 = ";
    os += ::android::hardware::camera::device::V3_4::toString(o.v3_4);
    os += ", .inputWidth = ";
    os += ::android::hardware::toString(o.inputWidth);
    os += ", .inputHeight = ";
    os += ::android::hardware::toString(o.inputHeight);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::camera::device::V3_7::CaptureRequest& o, ::std::ostream* os) {
    *os << toString(o);
}

// operator== and operator!= are not generated for CaptureRequest


}  // namespace V3_7
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_TYPES_H
