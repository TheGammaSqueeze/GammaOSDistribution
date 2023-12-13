#ifndef HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTORCALLBACK_H
#define HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTORCALLBACK_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/xiaomi/hardware/motor/1.0/IHwMotorCallback.h>

namespace vendor {
namespace xiaomi {
namespace hardware {
namespace motor {
namespace V1_0 {

struct BpHwMotorCallback : public ::android::hardware::BpInterface<IMotorCallback>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwMotorCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IMotorCallback Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotorCallback follow.
    static ::android::hardware::Return<void>  _hidl_onNotify(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& event);

    // Methods from ::vendor::xiaomi::hardware::motor::V1_0::IMotorCallback follow.
    ::android::hardware::Return<void> onNotify(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& event) override;

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

#endif  // HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_BPHWMOTORCALLBACK_H
