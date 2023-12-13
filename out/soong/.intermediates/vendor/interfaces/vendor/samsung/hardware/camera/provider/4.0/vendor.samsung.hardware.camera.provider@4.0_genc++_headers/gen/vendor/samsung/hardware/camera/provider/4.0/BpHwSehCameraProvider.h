#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_PROVIDER_V4_0_BPHWSEHCAMERAPROVIDER_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_PROVIDER_V4_0_BPHWSEHCAMERAPROVIDER_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/samsung/hardware/camera/provider/4.0/IHwSehCameraProvider.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace camera {
namespace provider {
namespace V4_0 {

struct BpHwSehCameraProvider : public ::android::hardware::BpInterface<ISehCameraProvider>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwSehCameraProvider(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ISehCameraProvider Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::samsung::hardware::camera::provider::V4_0::ISehCameraProvider follow.
    static ::android::hardware::Return<void>  _hidl_sehGetCameraIdList(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, sehGetCameraIdList_cb _hidl_cb);

    // Methods from ::android::hardware::camera::provider::V2_4::ICameraProvider follow.
    ::android::hardware::Return<::android::hardware::camera::common::V1_0::Status> setCallback(const ::android::sp<::android::hardware::camera::provider::V2_4::ICameraProviderCallback>& callback) override;
    ::android::hardware::Return<void> getVendorTags(getVendorTags_cb _hidl_cb) override;
    ::android::hardware::Return<void> getCameraIdList(getCameraIdList_cb _hidl_cb) override;
    ::android::hardware::Return<void> isSetTorchModeSupported(isSetTorchModeSupported_cb _hidl_cb) override;
    ::android::hardware::Return<void> getCameraDeviceInterface_V1_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V1_x_cb _hidl_cb) override;
    ::android::hardware::Return<void> getCameraDeviceInterface_V3_x(const ::android::hardware::hidl_string& cameraDeviceName, getCameraDeviceInterface_V3_x_cb _hidl_cb) override;

    // Methods from ::android::hardware::camera::provider::V2_5::ICameraProvider follow.
    ::android::hardware::Return<void> notifyDeviceStateChange(::android::hardware::hidl_bitfield<::android::hardware::camera::provider::V2_5::DeviceState> newState) override;

    // Methods from ::android::hardware::camera::provider::V2_6::ICameraProvider follow.
    ::android::hardware::Return<void> getConcurrentStreamingCameraIds(getConcurrentStreamingCameraIds_cb _hidl_cb) override;
    ::android::hardware::Return<void> isConcurrentStreamCombinationSupported(const ::android::hardware::hidl_vec<::android::hardware::camera::provider::V2_6::CameraIdAndStreamCombination>& configs, isConcurrentStreamCombinationSupported_cb _hidl_cb) override;

    // Methods from ::vendor::samsung::hardware::camera::provider::V4_0::ISehCameraProvider follow.
    ::android::hardware::Return<void> sehGetCameraIdList(sehGetCameraIdList_cb _hidl_cb) override;

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

}  // namespace V4_0
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_PROVIDER_V4_0_BPHWSEHCAMERAPROVIDER_H
