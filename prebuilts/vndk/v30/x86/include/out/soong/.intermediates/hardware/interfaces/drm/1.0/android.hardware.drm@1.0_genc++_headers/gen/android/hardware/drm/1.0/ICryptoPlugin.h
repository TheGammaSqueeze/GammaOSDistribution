#ifndef HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_0_ICRYPTOPLUGIN_H
#define HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_0_ICRYPTOPLUGIN_H

#include <android/hardware/drm/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_0 {

/**
 * Ref: frameworks/native/include/media/hardware/CryptoAPI.h:CryptoPlugin
 *
 * ICryptoPlugin is the HAL for vendor-provided crypto plugins.
 * It allows crypto sessions to be opened and operated on, to
 * load crypto keys for a codec to decrypt protected video content.
 */
struct ICryptoPlugin : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.drm@1.0::ICryptoPlugin"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Check if the specified mime-type requires a secure decoder
     * component.
     *
     * @param mime The content mime-type
     * @return secureRequired must be true only if a secure decoder is required
     * for the specified mime-type
     */
    virtual ::android::hardware::Return<bool> requiresSecureDecoderComponent(const ::android::hardware::hidl_string& mime) = 0;

    /**
     * Notify a plugin of the currently configured resolution
     *
     * @param width - the display resolutions's width
     * @param height - the display resolution's height
     */
    virtual ::android::hardware::Return<void> notifyResolution(uint32_t width, uint32_t height) = 0;

    /**
     * Associate a mediadrm session with this crypto session
     *
     * @param sessionId the MediaDrm session ID to associate with this crypto
     * session
     * @return status the status of the call, status must be
     * ERROR_DRM_SESSION_NOT_OPENED if the session is not opened, or
     * ERROR_DRM_CANNOT_HANDLE if the operation is not supported by the drm
     * scheme.
     */
    virtual ::android::hardware::Return<::android::hardware::drm::V1_0::Status> setMediaDrmSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId) = 0;

    /**
     * Set a shared memory base for subsequent decrypt operations. The buffer
     * base is a hidl_memory which maps shared memory in the HAL module.
     * After the shared buffer base is established, the decrypt() method
     * receives SharedBuffer instances which specify the buffer address range
     * for decrypt source and destination addresses.
     *
     * There can be multiple shared buffers per crypto plugin. The buffers
     * are distinguished by the bufferId.
     *
     * @param base the base IMemory of the memory buffer identified by
     * bufferId
     * @param bufferId identifies the specific shared buffer for which
     * the base is being set.
     */
    virtual ::android::hardware::Return<void> setSharedBufferBase(const ::android::hardware::hidl_memory& base, uint32_t bufferId) = 0;

    /**
     * Return callback for decrypt
     */
    using decrypt_cb = std::function<void(::android::hardware::drm::V1_0::Status status, uint32_t bytesWritten, const ::android::hardware::hidl_string& detailedError)>;
    /**
     * Decrypt an array of subsamples from the source memory buffer to the
     * destination memory buffer.
     *
     * @param secure a flag to indicate if a secure decoder is being used. This
     * enables the plugin to configure buffer modes to work consistently with
     * a secure decoder.
     * @param the keyId for the key that should be used to do the
     * the decryption. The keyId refers to a key in the associated
     * MediaDrm instance.
     * @param iv the initialization vector to use
     * @param mode the crypto mode to use
     * @param pattern the crypto pattern to use
     * @param subSamples a vector of subsamples indicating the number
     * of clear and encrypted bytes to process. This allows the decrypt
     * call to operate on a range of subsamples in a single call
     * @param source the input buffer for the decryption
     * @param offset the offset of the first byte of encrypted data from
     * the base of the source buffer
     * @param destination the output buffer for the decryption
     * @return status the status of the call. The status must be OK or one of
     * the following errors: ERROR_DRM_NO_LICENSE if no license keys have been
     * loaded, ERROR_DRM_LICENSE_EXPIRED if the license keys have expired,
     * ERROR_DRM_RESOURCE_BUSY if the resources required to perform the
     * decryption are not available, ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION
     * if required output protections are not active,
     * ERROR_DRM_SESSION_NOT_OPENED if the decrypt session is not opened,
     * ERROR_DRM_DECRYPT if the decrypt operation fails, and
     * ERROR_DRM_CANNOT_HANDLE in other failure cases.
     * @return bytesWritten the number of bytes output from the decryption
     * @return detailedError if the error is a vendor-specific error, the
     * vendor's crypto HAL may provide a detailed error string to help
     * describe the error.
     */
    virtual ::android::hardware::Return<void> decrypt(bool secure, const ::android::hardware::hidl_array<uint8_t, 16>& keyId, const ::android::hardware::hidl_array<uint8_t, 16>& iv, ::android::hardware::drm::V1_0::Mode mode, const ::android::hardware::drm::V1_0::Pattern& pattern, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::SubSample>& subSamples, const ::android::hardware::drm::V1_0::SharedBuffer& source, uint64_t offset, const ::android::hardware::drm::V1_0::DestinationBuffer& destination, decrypt_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>> castFrom(const ::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ICryptoPlugin> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICryptoPlugin> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICryptoPlugin> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICryptoPlugin> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ICryptoPlugin> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICryptoPlugin> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICryptoPlugin> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICryptoPlugin> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_0::ICryptoPlugin>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::drm::V1_0::ICryptoPlugin::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace drm
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_0_ICRYPTOPLUGIN_H
