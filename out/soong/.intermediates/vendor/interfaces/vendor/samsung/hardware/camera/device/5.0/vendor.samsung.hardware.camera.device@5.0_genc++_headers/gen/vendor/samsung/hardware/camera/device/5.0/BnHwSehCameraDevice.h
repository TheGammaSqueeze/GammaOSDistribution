#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_DEVICE_V5_0_BNHWSEHCAMERADEVICE_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_DEVICE_V5_0_BNHWSEHCAMERADEVICE_H

#include <vendor/samsung/hardware/camera/device/5.0/IHwSehCameraDevice.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace camera {
namespace device {
namespace V5_0 {

struct BnHwSehCameraDevice : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwSehCameraDevice(const ::android::sp<ISehCameraDevice> &_hidl_impl);
    explicit BnHwSehCameraDevice(const ::android::sp<ISehCameraDevice> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwSehCameraDevice();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ISehCameraDevice Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ISehCameraDevice> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::samsung::hardware::camera::device::V5_0::ISehCameraDevice follow.
    static ::android::status_t _hidl_sehSetTorchModeStrength(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::camera::device::V3_2::ICameraDevice follow.

    // Methods from ::android::hardware::camera::device::V3_5::ICameraDevice follow.

    // Methods from ::vendor::samsung::hardware::camera::device::V5_0::ISehCameraDevice follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ISehCameraDevice> _hidl_mImpl;
};

}  // namespace V5_0
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_CAMERA_DEVICE_V5_0_BNHWSEHCAMERADEVICE_H
