#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BPHWSEHMISCPOWER_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BPHWSEHMISCPOWER_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/samsung/hardware/miscpower/2.0/IHwSehMiscPower.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace miscpower {
namespace V2_0 {

struct BpHwSehMiscPower : public ::android::hardware::BpInterface<ISehMiscPower>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwSehMiscPower(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ISehMiscPower Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::samsung::hardware::miscpower::V2_0::ISehMiscPower follow.
    static ::android::hardware::Return<void>  _hidl_setInteractiveAsync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool interactive, int32_t dualScreenPolicy);

    // Methods from ::vendor::samsung::hardware::miscpower::V2_0::ISehMiscPower follow.
    ::android::hardware::Return<void> setInteractiveAsync(bool interactive, int32_t dualScreenPolicy) override;

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

}  // namespace V2_0
}  // namespace miscpower
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BPHWSEHMISCPOWER_H
