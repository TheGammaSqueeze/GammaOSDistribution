#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V3_0_BPHWMAPPER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V3_0_BPHWMAPPER_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/graphics/mapper/3.0/IHwMapper.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V3_0 {

struct BpHwMapper : public ::android::hardware::BpInterface<IMapper>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwMapper(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IMapper Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
    static ::android::hardware::Return<void>  _hidl_createDescriptor(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, createDescriptor_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_importBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>  _hidl_freeBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer);
    static ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error>  _hidl_validateBufferSize(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, uint32_t stride);
    static ::android::hardware::Return<void>  _hidl_getTransportSize(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, getTransportSize_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_lock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_lockYCbCr(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_unlock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, unlock_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_isSupported(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, isSupported_cb _hidl_cb);

    // Methods from ::android::hardware::graphics::mapper::V3_0::IMapper follow.
    ::android::hardware::Return<void> createDescriptor(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, createDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> freeBuffer(void* buffer) override;
    ::android::hardware::Return<::android::hardware::graphics::mapper::V3_0::Error> validateBufferSize(void* buffer, const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, uint32_t stride) override;
    ::android::hardware::Return<void> getTransportSize(void* buffer, getTransportSize_cb _hidl_cb) override;
    ::android::hardware::Return<void> lock(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb) override;
    ::android::hardware::Return<void> lockYCbCr(void* buffer, uint64_t cpuUsage, const ::android::hardware::graphics::mapper::V3_0::IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb) override;
    ::android::hardware::Return<void> unlock(void* buffer, unlock_cb _hidl_cb) override;
    ::android::hardware::Return<void> isSupported(const ::android::hardware::graphics::mapper::V3_0::IMapper::BufferDescriptorInfo& description, isSupported_cb _hidl_cb) override;

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

}  // namespace V3_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V3_0_BPHWMAPPER_H
