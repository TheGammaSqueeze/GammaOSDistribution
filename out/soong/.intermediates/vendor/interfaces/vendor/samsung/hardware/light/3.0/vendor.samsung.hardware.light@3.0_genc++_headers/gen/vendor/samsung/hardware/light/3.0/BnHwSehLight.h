#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_BNHWSEHLIGHT_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_BNHWSEHLIGHT_H

#include <vendor/samsung/hardware/light/3.0/IHwSehLight.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace light {
namespace V3_0 {

struct BnHwSehLight : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwSehLight(const ::android::sp<ISehLight> &_hidl_impl);
    explicit BnHwSehLight(const ::android::sp<ISehLight> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwSehLight();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ISehLight Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ISehLight> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.
    static ::android::status_t _hidl_sehSetLight(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::light::V2_0::ILight follow.

    // Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ISehLight> _hidl_mImpl;
};

}  // namespace V3_0
}  // namespace light
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_BNHWSEHLIGHT_H
