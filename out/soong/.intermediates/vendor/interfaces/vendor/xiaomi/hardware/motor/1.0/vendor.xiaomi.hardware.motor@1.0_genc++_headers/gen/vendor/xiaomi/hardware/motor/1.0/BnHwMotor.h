#ifndef HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BNHWMOTOR_H
#define HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BNHWMOTOR_H

#include <vendor/xiaomi/hardware/motor/1.0/IHwMotor.h>

namespace vendor {
namespace xiaomi {
namespace hardware {
namespace motor {
namespace V1_0 {

struct BnHwMotor : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwMotor(const ::android::sp<IMotor> &_hidl_impl);
    explicit BnHwMotor(const ::android::sp<IMotor> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwMotor();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IMotor Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IMotor> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotor follow.
    static ::android::status_t _hidl_popupMotor(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_takebackMotor(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_setMotorCallback(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_init(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_release(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_getMotorStatus(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_calibration(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_takebackMotorShortly(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotor follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IMotor> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace motor
}  // namespace hardware
}  // namespace xiaomi
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BNHWMOTOR_H
