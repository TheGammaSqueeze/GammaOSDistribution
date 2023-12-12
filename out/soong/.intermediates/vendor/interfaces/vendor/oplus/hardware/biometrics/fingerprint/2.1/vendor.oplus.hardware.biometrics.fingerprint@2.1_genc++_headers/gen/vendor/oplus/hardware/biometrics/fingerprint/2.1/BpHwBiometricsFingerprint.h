#ifndef HIDL_GENERATED_VENDOR_OPLUS_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWBIOMETRICSFINGERPRINT_H
#define HIDL_GENERATED_VENDOR_OPLUS_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWBIOMETRICSFINGERPRINT_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/oplus/hardware/biometrics/fingerprint/2.1/IHwBiometricsFingerprint.h>

namespace vendor {
namespace oplus {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

struct BpHwBiometricsFingerprint : public ::android::hardware::BpInterface<IBiometricsFingerprint>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBiometricsFingerprint(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBiometricsFingerprint Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::oplus::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
    static ::android::hardware::Return<uint64_t>  _hidl_setNotify(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback);
    static ::android::hardware::Return<uint64_t>  _hidl_preEnroll(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_enroll(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_postEnroll(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<uint64_t>  _hidl_getAuthenticatorId(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_cancel(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_enumerate(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_remove(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t gid, uint32_t fid);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_setActiveGroup(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t gid, const ::android::hardware::hidl_string& storePath);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_authenticate(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationId, uint32_t gid);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_authenticateAsType(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t auth, uint32_t type, ::vendor::oplus::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_cleanUp(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_pauseEnroll(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_continueEnroll(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_setTouchEventListener(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_dynamicallyConfigLog(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t log);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_pauseIdentify(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_continueIdentify(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_getAlikeyStatus(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_getEnrollmentTotalTimes(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_setScreenState(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::vendor::oplus::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_getEngineeringInfo(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t info);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_touchDown(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_touchUp(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus>  _hidl_sendFingerprintCmd(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t cmd, const ::android::hardware::hidl_vec<int8_t>& CmdId);

    // Methods from ::vendor::oplus::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprint follow.
    ::android::hardware::Return<uint64_t> setNotify(const ::android::sp<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& clientCallback) override;
    ::android::hardware::Return<uint64_t> preEnroll() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> enroll(const ::android::hardware::hidl_array<uint8_t, 69>& hat, uint32_t gid, uint32_t timeoutSec) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> postEnroll() override;
    ::android::hardware::Return<uint64_t> getAuthenticatorId() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> cancel() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> enumerate() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> remove(uint32_t gid, uint32_t fid) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> setActiveGroup(uint32_t gid, const ::android::hardware::hidl_string& storePath) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> authenticate(uint64_t operationId, uint32_t gid) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> authenticateAsType(uint64_t auth, uint32_t type, ::vendor::oplus::hardware::biometrics::fingerprint::V2_1::FingerprintAuthType AuthType) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> cleanUp() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> pauseEnroll() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> continueEnroll() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> setTouchEventListener() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> dynamicallyConfigLog(uint32_t log) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> pauseIdentify() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> continueIdentify() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> getAlikeyStatus() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> getEnrollmentTotalTimes() override;
    ::android::hardware::Return<void> setScreenState(::vendor::oplus::hardware::biometrics::fingerprint::V2_1::FingerprintScreenState ScreenState) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> getEngineeringInfo(uint32_t info) override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> touchDown() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> touchUp() override;
    ::android::hardware::Return<::vendor::oplus::hardware::biometrics::fingerprint::V2_1::RequestStatus> sendFingerprintCmd(int32_t cmd, const ::android::hardware::hidl_vec<int8_t>& CmdId) override;

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

}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace oplus
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_OPLUS_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWBIOMETRICSFINGERPRINT_H
