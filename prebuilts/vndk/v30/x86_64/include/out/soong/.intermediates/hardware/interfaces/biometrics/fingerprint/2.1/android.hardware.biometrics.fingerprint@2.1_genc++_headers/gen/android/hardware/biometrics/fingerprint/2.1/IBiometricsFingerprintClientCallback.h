#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_IBIOMETRICSFINGERPRINTCLIENTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_IBIOMETRICSFINGERPRINTCLIENTCALLBACK_H

#include <android/hardware/biometrics/fingerprint/2.1/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

/*
 * This HAL interface communicates asynchronous results from the
 * fingerprint driver in response to user actions on the fingerprint sensor
 */
struct IBiometricsFingerprintClientCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.biometrics.fingerprint@2.1::IBiometricsFingerprintClientCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Sent when one enrollment step is complete.
     * @param deviceId the instance of this fingerprint device
     * @param fingerId the fingerprint templetate being enrolled
     * @param groupId the groupid for the template being enrolled
     * @param remaining the number of remaining steps before enrolllment is complete
     */
    virtual ::android::hardware::Return<void> onEnrollResult(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) = 0;

    /**
     * Sent when a fingerprint image is acquired by the sensor
     * @param deviceId the instance of this fingerprint device
     * @param acquiredInfo a message about the quality of the acquired image
     * @param vendorCode a vendor-specific message about the quality of the image. Only
     *        valid when acquiredInfo == ACQUIRED_VENDOR
     */
    virtual ::android::hardware::Return<void> onAcquired(uint64_t deviceId, ::android::hardware::biometrics::fingerprint::V2_1::FingerprintAcquiredInfo acquiredInfo, int32_t vendorCode) = 0;

    /**
     * Sent when a fingerprint is authenticated
     * @param deviceId the instance of this fingerprint device
     * @param fingerId the fingerprint templetate that was authenticated
     * @param groupId the groupid for the template that was authenticated
     * @param token the hardware authentication token to pass to Keystore.addAuthToken()
     */
    virtual ::android::hardware::Return<void> onAuthenticated(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, const ::android::hardware::hidl_vec<uint8_t>& token) = 0;

    /**
     * Sent when a fingerprint error occurs
     * @param deviceId the instance of this fingerprint device
     * @param error a message about the error that occurred
     * @param vendorCode a vendor-speicifc error message. Only valid
     *        when error == ERROR_VENDOR
     */
    virtual ::android::hardware::Return<void> onError(uint64_t deviceId, ::android::hardware::biometrics::fingerprint::V2_1::FingerprintError error, int32_t vendorCode) = 0;

    /**
     * Sent when one template is removed
     * @param deviceId the instance of this fingerprint device
     * @param fingerId the fingerprint templetate being removed
     * @param groupId the groupid for the template being removed
     * @param remaining the number of remaining templates that will be removed.
     */
    virtual ::android::hardware::Return<void> onRemoved(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) = 0;

    /**
     * Sent when one fingerprint template is enumerated
     * @param deviceId the instance of this fingerprint device
     * @param fingerId the fingerprint for this templetate
     * @param groupId the groupid for this template
     * @param remaining the number of remaining steps before enumeration is complete
     */
    virtual ::android::hardware::Return<void> onEnumerate(uint64_t deviceId, uint32_t fingerId, uint32_t groupId, uint32_t remaining) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>> castFrom(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     *
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFingerprintClientCallback> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::biometrics::fingerprint::V2_1::IBiometricsFingerprintClientCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_IBIOMETRICSFINGERPRINTCLIENTCALLBACK_H
