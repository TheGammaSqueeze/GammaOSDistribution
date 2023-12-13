#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_CAMERASERVICE_DEVICE_V2_1_BNHWCAMERADEVICEUSER_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_CAMERASERVICE_DEVICE_V2_1_BNHWCAMERADEVICEUSER_H

#include <android/frameworks/cameraservice/device/2.1/IHwCameraDeviceUser.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace device {
namespace V2_1 {

struct BnHwCameraDeviceUser : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwCameraDeviceUser(const ::android::sp<ICameraDeviceUser> &_hidl_impl);
    explicit BnHwCameraDeviceUser(const ::android::sp<ICameraDeviceUser> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwCameraDeviceUser();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ICameraDeviceUser Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ICameraDeviceUser> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::frameworks::cameraservice::device::V2_1::ICameraDeviceUser follow.
    static ::android::status_t _hidl_endConfigure_2_1(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::frameworks::cameraservice::device::V2_0::ICameraDeviceUser follow.

    // Methods from ::android::frameworks::cameraservice::device::V2_1::ICameraDeviceUser follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ICameraDeviceUser> _hidl_mImpl;
};

}  // namespace V2_1
}  // namespace device
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_CAMERASERVICE_DEVICE_V2_1_BNHWCAMERADEVICEUSER_H
