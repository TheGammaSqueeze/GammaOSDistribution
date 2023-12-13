#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERCLIENT_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERCLIENT_H

#include <hidl/HidlTransportSupport.h>

#include <android/frameworks/bufferhub/1.0/IHwBufferClient.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {

struct BpHwBufferClient : public ::android::hardware::BpInterface<IBufferClient>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBufferClient(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBufferClient Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferClient follow.
    static ::android::hardware::Return<void>  _hidl_duplicate(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, duplicate_cb _hidl_cb);
    static ::android::hardware::Return<::android::frameworks::bufferhub::V1_0::BufferHubStatus>  _hidl_close(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferClient follow.
    ::android::hardware::Return<void> duplicate(duplicate_cb _hidl_cb) override;
    ::android::hardware::Return<::android::frameworks::bufferhub::V1_0::BufferHubStatus> close() override;

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
}  // namespace bufferhub
}  // namespace frameworks
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERCLIENT_H
