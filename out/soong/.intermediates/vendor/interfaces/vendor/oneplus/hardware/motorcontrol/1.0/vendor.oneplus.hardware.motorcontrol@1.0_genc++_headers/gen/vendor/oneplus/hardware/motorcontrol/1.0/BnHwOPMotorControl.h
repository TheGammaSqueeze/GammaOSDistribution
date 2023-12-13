#ifndef HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BNHWOPMOTORCONTROL_H
#define HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BNHWOPMOTORCONTROL_H

#include <vendor/oneplus/hardware/motorcontrol/1.0/IHwOPMotorControl.h>

namespace vendor {
namespace oneplus {
namespace hardware {
namespace motorcontrol {
namespace V1_0 {

struct BnHwOPMotorControl : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwOPMotorControl(const ::android::sp<IOPMotorControl> &_hidl_impl);
    explicit BnHwOPMotorControl(const ::android::sp<IOPMotorControl> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwOPMotorControl();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IOPMotorControl Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IOPMotorControl> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::oneplus::hardware::motorcontrol::V1_0::IOPMotorControl follow.
    static ::android::status_t _hidl_readMotorData(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_writeMotorData(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_writeFlashData(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_writeCalibData(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::vendor::oneplus::hardware::motorcontrol::V1_0::IOPMotorControl follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IOPMotorControl> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace motorcontrol
}  // namespace hardware
}  // namespace oneplus
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BNHWOPMOTORCONTROL_H
