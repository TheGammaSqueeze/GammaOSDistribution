#ifndef HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_5_BNHWRADIO_H
#define HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_5_BNHWRADIO_H

#include <vendor/mediatek/hardware/radio/2.5/IHwRadio.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_5 {

struct BnHwRadio : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwRadio(const ::android::sp<IRadio> &_hidl_impl);
    explicit BnHwRadio(const ::android::sp<IRadio> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwRadio();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IRadio Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IRadio> getImpl() { return _hidl_mImpl; }
    // Methods from ::vendor::mediatek::hardware::radio::V2_5::IRadio follow.
    static ::android::status_t _hidl_setResponseFunctionsSubsidyLock(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_sendSubsidyLockRequest(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::radio::V1_0::IRadio follow.

    // Methods from ::android::hardware::radio::V1_1::IRadio follow.

    // Methods from ::vendor::mediatek::hardware::radio::V2_0::IRadio follow.

    // Methods from ::vendor::mediatek::hardware::radio::V2_3::IRadio follow.

    // Methods from ::vendor::mediatek::hardware::radio::V2_4::IRadio follow.

    // Methods from ::vendor::mediatek::hardware::radio::V2_5::IRadio follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IRadio> _hidl_mImpl;
};

}  // namespace V2_5
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_5_BNHWRADIO_H
