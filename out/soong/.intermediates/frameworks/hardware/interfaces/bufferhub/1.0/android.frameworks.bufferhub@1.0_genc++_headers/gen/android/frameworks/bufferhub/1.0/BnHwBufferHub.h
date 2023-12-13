#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BNHWBUFFERHUB_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BNHWBUFFERHUB_H

#include <android/frameworks/bufferhub/1.0/IHwBufferHub.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {

struct BnHwBufferHub : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwBufferHub(const ::android::sp<IBufferHub> &_hidl_impl);
    explicit BnHwBufferHub(const ::android::sp<IBufferHub> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwBufferHub();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IBufferHub Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IBufferHub> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferHub follow.
    static ::android::status_t _hidl_allocateBuffer(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_importBuffer(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferHub follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IBufferHub> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace bufferhub
}  // namespace frameworks
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BNHWBUFFERHUB_H
