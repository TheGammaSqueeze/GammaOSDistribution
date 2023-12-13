#ifndef HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTOR_H
#define HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTOR_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/xiaomi/hardware/motor/1.0/IHwMotor.h>

namespace vendor {
namespace xiaomi {
namespace hardware {
namespace motor {
namespace V1_0 {

struct BpHwMotor : public ::android::hardware::BpInterface<IMotor>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwMotor(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IMotor Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotor follow.
    static ::android::hardware::Return<void>  _hidl_popupMotor(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t cookie);
    static ::android::hardware::Return<void>  _hidl_takebackMotor(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t cookie);
    static ::android::hardware::Return<void>  _hidl_setMotorCallback(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::vendor::xiaomi::hardware::motor::V1_0::IMotorCallback>& motorcallback);
    static ::android::hardware::Return<void>  _hidl_init(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_release(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<int32_t>  _hidl_getMotorStatus(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_calibration(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_takebackMotorShortly(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotor follow.
    ::android::hardware::Return<void> popupMotor(int32_t cookie) override;
    ::android::hardware::Return<void> takebackMotor(int32_t cookie) override;
    ::android::hardware::Return<void> setMotorCallback(const ::android::sp<::vendor::xiaomi::hardware::motor::V1_0::IMotorCallback>& motorcallback) override;
    ::android::hardware::Return<void> init() override;
    ::android::hardware::Return<void> release() override;
    ::android::hardware::Return<int32_t> getMotorStatus() override;
    ::android::hardware::Return<void> calibration() override;
    ::android::hardware::Return<void> takebackMotorShortly() override;

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

}  // namespace V1_0
}  // namespace motor
}  // namespace hardware
}  // namespace xiaomi
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTOR_H
