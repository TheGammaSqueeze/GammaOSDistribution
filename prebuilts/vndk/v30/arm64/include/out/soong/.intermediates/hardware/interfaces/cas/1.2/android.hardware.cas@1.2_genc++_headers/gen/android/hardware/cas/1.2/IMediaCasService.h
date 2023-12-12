#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_IMEDIACASSERVICE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_IMEDIACASSERVICE_H

#include <android/hardware/cas/1.1/IMediaCasService.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace cas {
namespace V1_2 {

/**
 * IMediaCasService is the main entry point for interacting with a vendor's
 * cas HAL to create cas and descrambler plugin instances. A cas plugin instance
 * opens cas sessions which are used to obtain keys for a descrambler session,
 * which can in turn be used to descramble protected video content.
 *
 * The 1.2 must always create 1.2 ICas interfaces, which are
 * returned via the 1.1 createPluginExt method.
 *
 * To use 1.2 features the caller must cast the returned interface to a
 * 1.2 HAL, using V1_2::ICas::castFrom().
 */
struct IMediaCasService : public ::android::hardware::cas::V1_1::IMediaCasService {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.cas@1.2::IMediaCasService"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for enumeratePlugins
     */
    using enumeratePlugins_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::cas::V1_0::HidlCasPluginDescriptor>& descriptors)>;
    /**
     * List all available CA systems on the device.
     *
     * @return descriptors an array of descriptors for the available CA systems.
     */
    virtual ::android::hardware::Return<void> enumeratePlugins(enumeratePlugins_cb _hidl_cb) = 0;

    /**
     * Query if a certain CA system is supported on this device.
     *
     * @param CA_system_id the id of the CA system.
     * @return result whether the specified CA system is supported on this device.
     */
    virtual ::android::hardware::Return<bool> isSystemIdSupported(int32_t CA_system_id) = 0;

    /**
     * Construct a new instance of a CasPlugin given a CA_system_id.
     *
     * @param CA_system_id the id of the CA system.
     * @param listener the event listener to receive events coming from the CasPlugin.
     * @return cas the newly created CasPlugin interface.
     */
    virtual ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_0::ICas>> createPlugin(int32_t CA_system_id, const ::android::sp<::android::hardware::cas::V1_0::ICasListener>& listener) = 0;

    /**
     * Query if the descrambling scheme for a CA system is supported on this device.
     *
     * @param CA_system_id the id of the CA system.
     * @return result whether the specified descrambling scheme is supported on this device.
     */
    virtual ::android::hardware::Return<bool> isDescramblerSupported(int32_t CA_system_id) = 0;

    /**
     * Construct a new instance of a DescramblerPlugin given a CA_system_id.
     *
     * @param CA_system_id the id of the CA system.
     * @return descrambler the newly created plugin interface.
     */
    virtual ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_0::IDescramblerBase>> createDescrambler(int32_t CA_system_id) = 0;

    /**
     * Construct a new instance of a @1.1 ICAS CasPlugin given a CA_system_id.
     *
     * @param caSystemId the id of the CA system.
     * @param listener the event listener to receive events coming from the CasPlugin.
     * @return cas the newly created CasPlugin interface.
     */
    virtual ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_1::ICas>> createPluginExt(int32_t caSystemId, const ::android::sp<::android::hardware::cas::V1_1::ICasListener>& listener) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_2::IMediaCasService>> castFrom(const ::android::sp<::android::hardware::cas::V1_2::IMediaCasService>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_2::IMediaCasService>> castFrom(const ::android::sp<::android::hardware::cas::V1_1::IMediaCasService>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_2::IMediaCasService>> castFrom(const ::android::sp<::android::hardware::cas::V1_0::IMediaCasService>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::cas::V1_2::IMediaCasService>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IMediaCasService> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMediaCasService> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMediaCasService> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMediaCasService> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IMediaCasService> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMediaCasService> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMediaCasService> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMediaCasService> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::cas::V1_2::IMediaCasService>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::cas::V1_2::IMediaCasService>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::cas::V1_2::IMediaCasService::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_2
}  // namespace cas
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAS_V1_2_IMEDIACASSERVICE_H
