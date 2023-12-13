#ifndef HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BPHWOPMOTORCONTROL_H
#define HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BPHWOPMOTORCONTROL_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/oneplus/hardware/motorcontrol/1.0/IHwOPMotorControl.h>

namespace vendor {
namespace oneplus {
namespace hardware {
namespace motorcontrol {
namespace V1_0 {

struct BpHwOPMotorControl : public ::android::hardware::BpInterface<IOPMotorControl>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwOPMotorControl(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IOPMotorControl Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::oneplus::hardware::motorcontrol::V1_0::IOPMotorControl follow.
    static ::android::hardware::Return<int32_t>  _hidl_readMotorData(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t id, int32_t size);
    static ::android::hardware::Return<int32_t>  _hidl_writeMotorData(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t id, int32_t direction, int32_t enable);
    static ::android::hardware::Return<int32_t>  _hidl_writeFlashData(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t id, int32_t enable);
    static ::android::hardware::Return<int32_t>  _hidl_writeCalibData(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t id, const ::android::hardware::hidl_string& value);

    // Methods from ::vendor::oneplus::hardware::motorcontrol::V1_0::IOPMotorControl follow.
    ::android::hardware::Return<int32_t> readMotorData(int32_t id, int32_t size) override;
    ::android::hardware::Return<int32_t> writeMotorData(int32_t id, int32_t direction, int32_t enable) override;
    ::android::hardware::Return<int32_t> writeFlashData(int32_t id, int32_t enable) override;
    ::android::hardware::Return<int32_t> writeCalibData(int32_t id, const ::android::hardware::hidl_string& value) override;

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
}  // namespace motorcontrol
}  // namespace hardware
}  // namespace oneplus
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_ONEPLUS_HARDWARE_MOTORCONTROL_V1_0_BPHWOPMOTORCONTROL_H
