#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_1_BNHWSAP_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_1_BNHWSAP_H

#include <android/hardware/radio/1.1/IHwSap.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_1 {

struct BnHwSap : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwSap(const ::android::sp<ISap> &_hidl_impl);
    explicit BnHwSap(const ::android::sp<ISap> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwSap();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ISap Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ISap> getImpl() { return _hidl_mImpl; }

private:
    // Methods from ::android::hardware::radio::V1_0::ISap follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ISap> _hidl_mImpl;
};

}  // namespace V1_1
}  // namespace radio
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_1_BNHWSAP_H
