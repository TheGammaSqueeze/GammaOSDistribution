#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERHUB_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERHUB_H

#include <hidl/HidlTransportSupport.h>

#include <android/frameworks/bufferhub/1.0/IHwBufferHub.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {

struct BpHwBufferHub : public ::android::hardware::BpInterface<IBufferHub>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBufferHub(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBufferHub Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferHub follow.
    static ::android::hardware::Return<void>  _hidl_allocateBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<uint32_t, 10>& description, uint32_t userMetadataSize, allocateBuffer_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_importBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& nativeHandle, importBuffer_cb _hidl_cb);

    // Methods from ::android::frameworks::bufferhub::V1_0::IBufferHub follow.
    ::android::hardware::Return<void> allocateBuffer(const ::android::hardware::hidl_array<uint32_t, 10>& description, uint32_t userMetadataSize, allocateBuffer_cb _hidl_cb) override;
    ::android::hardware::Return<void> importBuffer(const ::android::hardware::hidl_handle& nativeHandle, importBuffer_cb _hidl_cb) override;

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

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_BPHWBUFFERHUB_H
