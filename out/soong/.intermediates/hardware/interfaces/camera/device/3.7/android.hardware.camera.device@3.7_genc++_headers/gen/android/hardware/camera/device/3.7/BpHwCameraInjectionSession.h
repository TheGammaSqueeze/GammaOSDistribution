#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_BPHWCAMERAINJECTIONSESSION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_BPHWCAMERAINJECTIONSESSION_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/camera/device/3.7/IHwCameraInjectionSession.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_7 {

struct BpHwCameraInjectionSession : public ::android::hardware::BpInterface<ICameraInjectionSession>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwCameraInjectionSession(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ICameraInjectionSession Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::camera::device::V3_7::ICameraInjectionSession follow.
    static ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status>  _hidl_configureInjectionStreams(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::camera::device::V3_7::StreamConfiguration& requestedConfiguration, const ::android::hardware::hidl_vec<uint8_t>& characteristics);

    // Methods from ::android::hardware::camera::device::V3_2::ICameraDeviceSession follow.
    ::android::hardware::Return<void> constructDefaultRequestSettings(::android::hardware::camera::device::V3_2::RequestTemplate type, constructDefaultRequestSettings_cb _hidl_cb) override;
    ::android::hardware::Return<void> configureStreams(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_cb _hidl_cb) override;
    ::android::hardware::Return<void> processCaptureRequest(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureRequest>& requests, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::BufferCache>& cachesToRemove, processCaptureRequest_cb _hidl_cb) override;
    ::android::hardware::Return<void> getCaptureRequestMetadataQueue(getCaptureRequestMetadataQueue_cb _hidl_cb) override;
    ::android::hardware::Return<void> getCaptureResultMetadataQueue(getCaptureResultMetadataQueue_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> flush() override;
    ::android::hardware::Return<void> close() override;

    // Methods from ::android::hardware::camera::device::V3_3::ICameraDeviceSession follow.
    ::android::hardware::Return<void> configureStreams_3_3(const ::android::hardware::camera::device::V3_2::StreamConfiguration& requestedConfiguration, configureStreams_3_3_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::device::V3_4::ICameraDeviceSession follow.
    ::android::hardware::Return<void> configureStreams_3_4(const ::android::hardware::camera::device::V3_4::StreamConfiguration& requestedConfiguration, configureStreams_3_4_cb _hidl_cb) override;
    ::android::hardware::Return<void> processCaptureRequest_3_4(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::CaptureRequest>& requests, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::BufferCache>& cachesToRemove, processCaptureRequest_3_4_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::device::V3_5::ICameraDeviceSession follow.
    ::android::hardware::Return<void> configureStreams_3_5(const ::android::hardware::camera::device::V3_5::StreamConfiguration& requestedConfiguration, configureStreams_3_5_cb _hidl_cb) override;
    ::android::hardware::Return<void> signalStreamFlush(const ::android::hardware::hidl_vec<int32_t>& streamIds, uint32_t streamConfigCounter) override;
    ::android::hardware::Return<void> isReconfigurationRequired(const ::android::hardware::hidl_vec<uint8_t>& oldSessionParams, const ::android::hardware::hidl_vec<uint8_t>& newSessionParams, isReconfigurationRequired_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::device::V3_6::ICameraDeviceSession follow.
    ::android::hardware::Return<void> configureStreams_3_6(const ::android::hardware::camera::device::V3_5::StreamConfiguration& requestedConfiguration, configureStreams_3_6_cb _hidl_cb) override;
    ::android::hardware::Return<void> switchToOffline(const ::android::hardware::hidl_vec<int32_t>& streamsToKeep, switchToOffline_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::device::V3_7::ICameraDeviceSession follow.
    ::android::hardware::Return<void> configureStreams_3_7(const ::android::hardware::camera::device::V3_7::StreamConfiguration& requestedConfiguration, configureStreams_3_7_cb _hidl_cb) override;
    ::android::hardware::Return<void> processCaptureRequest_3_7(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_7::CaptureRequest>& requests, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::BufferCache>& cachesToRemove, processCaptureRequest_3_7_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::device::V3_7::ICameraInjectionSession follow.
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> configureInjectionStreams(const ::android::hardware::camera::device::V3_7::StreamConfiguration& requestedConfiguration, const ::android::hardware::hidl_vec<uint8_t>& characteristics) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V3_7
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_7_BPHWCAMERAINJECTIONSESSION_H
