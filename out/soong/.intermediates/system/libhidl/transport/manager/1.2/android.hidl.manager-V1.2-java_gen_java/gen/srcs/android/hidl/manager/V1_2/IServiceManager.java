package android.hidl.manager.V1_2;

public interface IServiceManager extends android.hidl.manager.V1_1.IServiceManager {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hidl.manager@1.2::IServiceManager";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IServiceManager asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IServiceManager)) {
            return (IServiceManager)iface;
        }

        IServiceManager proxy = new IServiceManager.Proxy(binder);

        try {
            for (String descriptor : proxy.interfaceChain()) {
                if (descriptor.equals(kInterfaceName)) {
                    return proxy;
                }
            }
        } catch (android.os.RemoteException e) {
        }

        return null;
    }

    /**
     * Does a checked conversion from any interface to this class.
     */
    public static IServiceManager castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IServiceManager.asInterface(iface.asBinder());
    }

    @Override
    public android.os.IHwBinder asBinder();

    /**
     * This will invoke the equivalent of the C++ getService(std::string) if retry is
     * true or tryGetService(std::string) if retry is false. If the service is
     * available on the device and retry is true, this will wait for the service to
     * start.
     *
     * @throws NoSuchElementException if this service is not available
     */
    public static IServiceManager getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IServiceManager.asInterface(android.os.HwBinder.getService("android.hidl.manager@1.2::IServiceManager", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IServiceManager getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IServiceManager getService(String serviceName) throws android.os.RemoteException {
        return IServiceManager.asInterface(android.os.HwBinder.getService("android.hidl.manager@1.2::IServiceManager", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IServiceManager getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Adds a callback that must be called when the specified server has no clients.
     *
     * If the service has clients at the time of registration, the callback is called with
     * hasClients true. After that, it is called based on the changes in clientele.
     *
     * @param fqName Fully-qualified interface name (used to register)
     * @param name Instance name (of the registered service)
     * @param server non-null service waiting to have no clients (previously registered)
     * @param cb non-null callback to call when there are no clients
     * @return success
     *     true on success
     *     false if either
     *      - the server or cb parameters are null
     *      - this is called by a process other than the server process
     */
    boolean registerClientCallback(String fqName, String name, android.hidl.base.V1_0.IBase server, android.hidl.manager.V1_2.IClientCallback cb)
        throws android.os.RemoteException;
    /**
     * Removes a callback previously registered with registerClientCallback.
     *
     * If server is null, then this must remove the cb from all matching services.
     *
     * @param server service registered with registerClientCallback
     * @param cb non-null callback to remove
     * @return success
     *     true if the server(s) have been removed
     *     false if cb is null or if the client callback or server could not be found
     */
    boolean unregisterClientCallback(android.hidl.base.V1_0.IBase server, android.hidl.manager.V1_2.IClientCallback cb)
        throws android.os.RemoteException;
    /**
     * Exactly the same as @1.0::IServiceManager.add, but the interfaceChain of the service is
     * provided in the same call.
     *
     * @param name Instance name. Must also be used to retrieve service.
     * @param service Handle to registering service.
     * @param chain service->interfaceChain
     *
     * @return success Whether or not the service was registered.
     */
    boolean addWithChain(String name, android.hidl.base.V1_0.IBase service, java.util.ArrayList<String> chain)
        throws android.os.RemoteException;
    /**
     * List all instances of a particular service from the manifest. Must be sorted. These HALs
     * may not be started if they are lazy.
     *
     * See also @1.0::IServiceManager's listByInterface function.
     *
     * @param fqName Fully-qualified interface name.
     *
     * @return instanceNames List of instance names running the particular service.
     */
    java.util.ArrayList<String> listManifestByInterface(String fqName)
        throws android.os.RemoteException;
    /**
     * Unregisters a service if there are no clients for it. This must only unregister the
     * service if it is called from the same process that registered the service.
     *
     * This unregisters all instances of the service, even if they are under a different instance
     * name.
     *
     * Recommended usage is when creating a lazy process, try unregistering when IClientCallback's
     * onClients(*, false) is called. If this unregister is successful, then it is safe to exit. If
     * it is unsuccessful, then you can assume a client re-associated with the server. If a process
     * has multiple servers, and only some succeed in unregistration, then the unregistered services
     * can be re-registered.
     *
     * See also addWithChain and @1.0::IServiceManager's add.
     *
     * @param fqName Fully-qualified interface name.
     * @param name Instance name.
     * @param service Handle to registering service.
     *
     * @return success Whether the service was successfully unregistered.
     */
    boolean tryUnregister(String fqName, String name, android.hidl.base.V1_0.IBase service)
        throws android.os.RemoteException;
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
    java.util.ArrayList<String> interfaceChain()
        throws android.os.RemoteException;
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
    void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
        throws android.os.RemoteException;
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
    String interfaceDescriptor()
        throws android.os.RemoteException;
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
    java.util.ArrayList<byte[/* 32 */]> getHashChain()
        throws android.os.RemoteException;
    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    void setHALInstrumentation()
        throws android.os.RemoteException;
    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
        throws android.os.RemoteException;
    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    void ping()
        throws android.os.RemoteException;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    android.hidl.base.V1_0.DebugInfo getDebugInfo()
        throws android.os.RemoteException;
    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    void notifySyspropsChanged()
        throws android.os.RemoteException;
    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
        throws android.os.RemoteException;

    public static final class Proxy implements IServiceManager {
        private android.os.IHwBinder mRemote;

        public Proxy(android.os.IHwBinder remote) {
            mRemote = java.util.Objects.requireNonNull(remote);
        }

        @Override
        public android.os.IHwBinder asBinder() {
            return mRemote;
        }

        @Override
        public String toString() {
            try {
                return this.interfaceDescriptor() + "@Proxy";
            } catch (android.os.RemoteException ex) {
                /* ignored; handled below. */
            }
            return "[class or subclass of " + IServiceManager.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hidl::manager::V1_0::IServiceManager follow.
        @Override
        public android.hidl.base.V1_0.IBase get(String fqName, String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* get */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hidl.base.V1_0.IBase _hidl_out_service = android.hidl.base.V1_0.IBase.asInterface(_hidl_reply.readStrongBinder());
                return _hidl_out_service;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean add(String name, android.hidl.base.V1_0.IBase service)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(service == null ? null : service.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* add */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public byte getTransport(String fqName, String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getTransport */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                byte _hidl_out_transport = _hidl_reply.readInt8();
                return _hidl_out_transport;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<String> list()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* list */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_fqInstanceNames = _hidl_reply.readStringVector();
                return _hidl_out_fqInstanceNames;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<String> listByInterface(String fqName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* listByInterface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_instanceNames = _hidl_reply.readStringVector();
                return _hidl_out_instanceNames;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean registerForNotifications(String fqName, String name, android.hidl.manager.V1_0.IServiceNotification callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* registerForNotifications */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<android.hidl.manager.V1_0.IServiceManager.InstanceDebugInfo> debugDump()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* debugDump */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<android.hidl.manager.V1_0.IServiceManager.InstanceDebugInfo> _hidl_out_info = android.hidl.manager.V1_0.IServiceManager.InstanceDebugInfo.readVectorFromParcel(_hidl_reply);
                return _hidl_out_info;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void registerPassthroughClient(String fqName, String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* registerPassthroughClient */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::manager::V1_1::IServiceManager follow.
        @Override
        public boolean unregisterForNotifications(String fqName, String name, android.hidl.manager.V1_0.IServiceNotification callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_1.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* unregisterForNotifications */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::manager::V1_2::IServiceManager follow.
        @Override
        public boolean registerClientCallback(String fqName, String name, android.hidl.base.V1_0.IBase server, android.hidl.manager.V1_2.IClientCallback cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(server == null ? null : server.asBinder());
            _hidl_request.writeStrongBinder(cb == null ? null : cb.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* registerClientCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean unregisterClientCallback(android.hidl.base.V1_0.IBase server, android.hidl.manager.V1_2.IClientCallback cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);
            _hidl_request.writeStrongBinder(server == null ? null : server.asBinder());
            _hidl_request.writeStrongBinder(cb == null ? null : cb.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* unregisterClientCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean addWithChain(String name, android.hidl.base.V1_0.IBase service, java.util.ArrayList<String> chain)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(service == null ? null : service.asBinder());
            _hidl_request.writeStringVector(chain);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* addWithChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<String> listManifestByInterface(String fqName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* listManifestByInterface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_instanceNames = _hidl_reply.readStringVector();
                return _hidl_out_instanceNames;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean tryUnregister(String fqName, String name, android.hidl.base.V1_0.IBase service)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);
            _hidl_request.writeString(fqName);
            _hidl_request.writeString(name);
            _hidl_request.writeStrongBinder(service == null ? null : service.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* tryUnregister */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                boolean _hidl_out_success = _hidl_reply.readBool();
                return _hidl_out_success;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::base::V1_0::IBase follow.
        @Override
        public java.util.ArrayList<String> interfaceChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256067662 /* interfaceChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_descriptors = _hidl_reply.readStringVector();
                return _hidl_out_descriptors;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);
            _hidl_request.writeNativeHandle(fd);
            _hidl_request.writeStringVector(options);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256131655 /* debug */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public String interfaceDescriptor()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256136003 /* interfaceDescriptor */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                String _hidl_out_descriptor = _hidl_reply.readString();
                return _hidl_out_descriptor;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<byte[/* 32 */]> getHashChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256398152 /* getHashChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain =  new java.util.ArrayList<byte[/* 32 */]>();
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(16 /* size */);
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = _hidl_reply.readEmbeddedBuffer(
                                _hidl_vec_size * 32,_hidl_blob.handle(),
                                0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            byte[/* 32 */] _hidl_vec_element = new byte[32];
                            {
                                long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 32 */]) _hidl_vec_element, 32 /* size */);
                                _hidl_array_offset_1 += 32 * 1;
                            }
                            ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).add(_hidl_vec_element);
                        }
                    }
                }
                return _hidl_out_hashchain;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setHALInstrumentation()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256462420 /* setHALInstrumentation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
                throws android.os.RemoteException {
            return mRemote.linkToDeath(recipient, cookie);
        }
        @Override
        public void ping()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256921159 /* ping */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hidl.base.V1_0.DebugInfo getDebugInfo()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257049926 /* getDebugInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hidl.base.V1_0.DebugInfo _hidl_out_info = new android.hidl.base.V1_0.DebugInfo();
                ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).readFromParcel(_hidl_reply);
                return _hidl_out_info;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifySyspropsChanged()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257120595 /* notifySyspropsChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
                throws android.os.RemoteException {
            return mRemote.unlinkToDeath(recipient);
        }
    }

    public static abstract class Stub extends android.os.HwBinder implements IServiceManager {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hidl.manager.V1_2.IServiceManager.kInterfaceName,
                    android.hidl.manager.V1_1.IServiceManager.kInterfaceName,
                    android.hidl.manager.V1_0.IServiceManager.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hidl.manager.V1_2.IServiceManager.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{111,58,-118,63,-44,-65,-67,2,-28,-26,28,115,45,45,-10,22,-1,105,67,74,30,-40,60,-38,51,115,3,-83,-58,-41,20,-33} /* 6f3a8a3fd4bfbd02e4e61c732d2df616ff69434a1ed83cda337303adc6d714df */,
                    new byte[/* 32 */]{11,-108,-36,-121,111,116,-98,-46,74,-104,-10,28,65,-44,106,-41,90,39,81,17,99,-15,-106,-118,8,66,19,-93,60,104,78,-10} /* 0b94dc876f749ed24a98f61c41d46ad75a27511163f1968a084213a33c684ef6 */,
                    new byte[/* 32 */]{-123,57,79,-118,13,21,-25,-5,46,-28,92,82,-47,-5,-117,-113,-45,-63,60,51,62,99,-57,-116,74,-95,-1,-122,-124,12,-10,-36} /* 85394f8a0d15e7fb2ee45c52d1fb8b8fd3c13c333e63c78c4aa1ff86840cf6dc */,
                    new byte[/* 32 */]{-20,127,-41,-98,-48,45,-6,-123,-68,73,-108,38,-83,-82,62,-66,35,-17,5,36,-13,-51,105,87,19,-109,36,-72,59,24,-54,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */));

        }

        @Override
        public final void setHALInstrumentation() {

        }

        @Override
        public final boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie) {
            return true;

        }

        @Override
        public final void ping() {
            return;

        }

        @Override
        public final android.hidl.base.V1_0.DebugInfo getDebugInfo() {
            android.hidl.base.V1_0.DebugInfo info = new android.hidl.base.V1_0.DebugInfo();
            info.pid = android.os.HidlSupport.getPidIfSharable();
            info.ptr = 0;
            info.arch = android.hidl.base.V1_0.DebugInfo.Architecture.UNKNOWN;
            return info;

        }

        @Override
        public final void notifySyspropsChanged() {
            android.os.HwBinder.enableInstrumentation();

        }

        @Override
        public final boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient) {
            return true;

        }

        @Override
        public android.os.IHwInterface queryLocalInterface(String descriptor) {
            if (kInterfaceName.equals(descriptor)) {
                return this;
            }
            return null;
        }

        public void registerAsService(String serviceName) throws android.os.RemoteException {
            registerService(serviceName);
        }

        @Override
        public String toString() {
            return this.interfaceDescriptor() + "@Stub";
        }

        @Override
        public void onTransact(int _hidl_code, android.os.HwParcel _hidl_request, final android.os.HwParcel _hidl_reply, int _hidl_flags)
                throws android.os.RemoteException {
            switch (_hidl_code) {
                case 1 /* get */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    android.hidl.base.V1_0.IBase _hidl_out_service = get(fqName, name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStrongBinder(_hidl_out_service == null ? null : _hidl_out_service.asBinder());
                    _hidl_reply.send();
                    break;
                }

                case 2 /* add */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String name = _hidl_request.readString();
                    android.hidl.base.V1_0.IBase service = android.hidl.base.V1_0.IBase.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = add(name, service);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* getTransport */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    byte _hidl_out_transport = getTransport(fqName, name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt8(_hidl_out_transport);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* list */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    java.util.ArrayList<String> _hidl_out_fqInstanceNames = list();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_fqInstanceNames);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* listByInterface */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    java.util.ArrayList<String> _hidl_out_instanceNames = listByInterface(fqName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_instanceNames);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* registerForNotifications */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    android.hidl.manager.V1_0.IServiceNotification callback = android.hidl.manager.V1_0.IServiceNotification.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = registerForNotifications(fqName, name, callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* debugDump */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    java.util.ArrayList<android.hidl.manager.V1_0.IServiceManager.InstanceDebugInfo> _hidl_out_info = debugDump();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    android.hidl.manager.V1_0.IServiceManager.InstanceDebugInfo.writeVectorToParcel(_hidl_reply, _hidl_out_info);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* registerPassthroughClient */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_0.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    registerPassthroughClient(fqName, name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* unregisterForNotifications */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_1.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    android.hidl.manager.V1_0.IServiceNotification callback = android.hidl.manager.V1_0.IServiceNotification.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = unregisterForNotifications(fqName, name, callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* registerClientCallback */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    android.hidl.base.V1_0.IBase server = android.hidl.base.V1_0.IBase.asInterface(_hidl_request.readStrongBinder());
                    android.hidl.manager.V1_2.IClientCallback cb = android.hidl.manager.V1_2.IClientCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = registerClientCallback(fqName, name, server, cb);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* unregisterClientCallback */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);

                    android.hidl.base.V1_0.IBase server = android.hidl.base.V1_0.IBase.asInterface(_hidl_request.readStrongBinder());
                    android.hidl.manager.V1_2.IClientCallback cb = android.hidl.manager.V1_2.IClientCallback.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = unregisterClientCallback(server, cb);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* addWithChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);

                    String name = _hidl_request.readString();
                    android.hidl.base.V1_0.IBase service = android.hidl.base.V1_0.IBase.asInterface(_hidl_request.readStrongBinder());
                    java.util.ArrayList<String> chain = _hidl_request.readStringVector();
                    boolean _hidl_out_success = addWithChain(name, service, chain);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* listManifestByInterface */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    java.util.ArrayList<String> _hidl_out_instanceNames = listManifestByInterface(fqName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_instanceNames);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* tryUnregister */:
                {
                    _hidl_request.enforceInterface(android.hidl.manager.V1_2.IServiceManager.kInterfaceName);

                    String fqName = _hidl_request.readString();
                    String name = _hidl_request.readString();
                    android.hidl.base.V1_0.IBase service = android.hidl.base.V1_0.IBase.asInterface(_hidl_request.readStrongBinder());
                    boolean _hidl_out_success = tryUnregister(fqName, name, service);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeBool(_hidl_out_success);
                    _hidl_reply.send();
                    break;
                }

                case 256067662 /* interfaceChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<String> _hidl_out_descriptors = interfaceChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_descriptors);
                    _hidl_reply.send();
                    break;
                }

                case 256131655 /* debug */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.os.NativeHandle fd = _hidl_request.readNativeHandle();
                    java.util.ArrayList<String> options = _hidl_request.readStringVector();
                    debug(fd, options);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256136003 /* interfaceDescriptor */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    String _hidl_out_descriptor = interfaceDescriptor();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeString(_hidl_out_descriptor);
                    _hidl_reply.send();
                    break;
                }

                case 256398152 /* getHashChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain = getHashChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    {
                        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
                        {
                            int _hidl_vec_size = _hidl_out_hashchain.size();
                            _hidl_blob.putInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                            _hidl_blob.putBool(0 /* offset */ + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                                {
                                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                    byte[] _hidl_array_item_1 = (byte[/* 32 */]) _hidl_out_hashchain.get(_hidl_index_0);

                                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 32) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                                    _hidl_array_offset_1 += 32 * 1;
                                }
                            }
                            _hidl_blob.putBlob(0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                        }
                        _hidl_reply.writeBuffer(_hidl_blob);
                    }
                    _hidl_reply.send();
                    break;
                }

                case 256462420 /* setHALInstrumentation */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    setHALInstrumentation();
                    break;
                }

                case 256660548 /* linkToDeath */:
                {
                break;
                }

                case 256921159 /* ping */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    ping();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 257049926 /* getDebugInfo */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.hidl.base.V1_0.DebugInfo _hidl_out_info = getDebugInfo();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 257120595 /* notifySyspropsChanged */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    notifySyspropsChanged();
                    break;
                }

                case 257250372 /* unlinkToDeath */:
                {
                break;
                }

            }
        }
    }
}
