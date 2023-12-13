#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BNHWSEHMISCPOWER_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BNHWSEHMISCPOWER_H

#include <vendor/samsung/hardware/miscpower/2.0/IHwSehMiscPower.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace miscpower {
namespace V2_0 {

struct BnHwSehMiscPower : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwSehMiscPower(const ::android::sp<ISehMiscPower> &_hidl_impl);
    explicit BnHwSehMiscPower(const ::android::sp<ISehMiscPower> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwSehMiscPower();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ISehMiscPower Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ISehMiscPower> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::samsung::hardware::miscpower::V2_0::ISehMiscPower follow.
    static ::android::status_t _hidl_setInteractiveAsync(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::vendor::samsung::hardware::miscpower::V2_0::ISehMiscPower follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ISehMiscPower> _hidl_mImpl;
};

}  // namespace V2_0
}  // namespace miscpower
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_MISCPOWER_V2_0_BNHWSEHMISCPOWER_H
