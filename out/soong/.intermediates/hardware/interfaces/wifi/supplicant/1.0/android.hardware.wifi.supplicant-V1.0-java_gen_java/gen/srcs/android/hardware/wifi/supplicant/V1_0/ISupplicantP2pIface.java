package android.hardware.wifi.supplicant.V1_0;

/**
 * Interface exposed by the supplicant for each P2P mode network
 * interface (e.g p2p0) it controls.
 */
public interface ISupplicantP2pIface extends android.hardware.wifi.supplicant.V1_0.ISupplicantIface {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.supplicant@1.0::ISupplicantP2pIface";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISupplicantP2pIface asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISupplicantP2pIface)) {
            return (ISupplicantP2pIface)iface;
        }

        ISupplicantP2pIface proxy = new ISupplicantP2pIface.Proxy(binder);

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
    public static ISupplicantP2pIface castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISupplicantP2pIface.asInterface(iface.asBinder());
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
    public static ISupplicantP2pIface getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISupplicantP2pIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.0::ISupplicantP2pIface", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISupplicantP2pIface getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISupplicantP2pIface getService(String serviceName) throws android.os.RemoteException {
        return ISupplicantP2pIface.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.0::ISupplicantP2pIface", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISupplicantP2pIface getService() throws android.os.RemoteException {
        return getService("default");
    }

    public static final class WpsProvisionMethod {
        /**
         * Push button method.
         */
        public static final int PBC = 0;
        /**
         * Display pin method configuration - pin is generated and displayed on
         * device.
         */
        public static final int DISPLAY = 1 /* ::android::hardware::wifi::supplicant::V1_0::ISupplicantP2pIface::WpsProvisionMethod.PBC implicitly + 1 */;
        /**
         * Keypad pin method configuration - pin is entered on device.
         */
        public static final int KEYPAD = 2 /* ::android::hardware::wifi::supplicant::V1_0::ISupplicantP2pIface::WpsProvisionMethod.DISPLAY implicitly + 1 */;
        public static final String toString(int o) {
            if (o == PBC) {
                return "PBC";
            }
            if (o == DISPLAY) {
                return "DISPLAY";
            }
            if (o == KEYPAD) {
                return "KEYPAD";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("PBC"); // PBC == 0
            if ((o & DISPLAY) == DISPLAY) {
                list.add("DISPLAY");
                flipped |= DISPLAY;
            }
            if ((o & KEYPAD) == KEYPAD) {
                list.add("KEYPAD");
                flipped |= KEYPAD;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Use to specify a range of frequencies.
     * For example: 2412-2432,2462,5000-6000, etc.
     */
    public final static class FreqRange {
        public int min = 0;
        public int max = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange.class) {
                return false;
            }
            android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange other = (android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange)otherObject;
            if (this.min != other.min) {
                return false;
            }
            if (this.max != other.max) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.min), 
                    android.os.HidlSupport.deepHashCode(this.max));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".min = ");
            builder.append(this.min);
            builder.append(", .max = ");
            builder.append(this.max);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(8 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<FreqRange> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<FreqRange> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 8,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange _hidl_vec_element = new android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            min = _hidl_blob.getInt32(_hidl_offset + 0);
            max = _hidl_blob.getInt32(_hidl_offset + 4);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<FreqRange> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, min);
            _hidl_blob.putInt32(_hidl_offset + 4, max);
        }
    };

    /**
     * Enum describing the modes of Miracast supported
     * via driver commands.
     */
    public static final class MiracastMode {
        public static final byte DISABLED = 0;
        /**
         * Operating as source.
         */
        public static final byte SOURCE = 1;
        /**
         * Operating as sink.
         */
        public static final byte SINK = 2;
        public static final String toString(byte o) {
            if (o == DISABLED) {
                return "DISABLED";
            }
            if (o == SOURCE) {
                return "SOURCE";
            }
            if (o == SINK) {
                return "SINK";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("DISABLED"); // DISABLED == 0
            if ((o & SOURCE) == SOURCE) {
                list.add("SOURCE");
                flipped |= SOURCE;
            }
            if ((o & SINK) == SINK) {
                list.add("SINK");
                flipped |= SINK;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Register for callbacks from this interface.
     *
     * These callbacks are invoked for events that are specific to this interface.
     * Registration of multiple callback objects is supported. These objects must
     * be automatically deleted when the corresponding client process is dead or
     * if this interface is removed.
     *
     * @param callback An instance of the |ISupplicantP2pIfaceCallback| HIDL
     *        interface object.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIfaceCallback callback)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getDeviceAddressCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, byte[/* 6 */] deviceAddress);
    }

    /**
     * Gets the MAC address of the device.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return deviceAddress MAC address of the device.
     */
    void getDeviceAddress(getDeviceAddressCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Set the postfix to be used for P2P SSID's.
     *
     * @param postfix String to be appended to SSID.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSsidPostfix(java.util.ArrayList<Byte> postfix)
        throws android.os.RemoteException;
    /**
     * Set the Maximum idle time in seconds for P2P groups.
     * This value controls how long a P2P group is maintained after there
     * is no other members in the group. As a group owner, this means no
     * associated stations in the group. As a P2P client, this means no
     * group owner seen in scan results.
     *
     * @param groupIfName Group interface name to use.
     * @param timeoutInSec Timeout value in seconds.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupIdle(String groupIfName, int timeoutInSec)
        throws android.os.RemoteException;
    /**
     * Turn on/off power save mode for the interface.
     *
     * @param groupIfName Group interface name to use.
     * @param enable Indicate if power save is to be turned on/off.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|,
     *         |SupplicantStatusCode.FAILURE_IFACE_DISABLED|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPowerSave(String groupIfName, boolean enable)
        throws android.os.RemoteException;
    /**
     * Initiate a P2P service discovery with an optional timeout.
     *
     * @param timeoutInSec Max time to be spent is peforming discovery.
     *        Set to 0 to indefinely continue discovery untill and explicit
     *        |stopFind| is sent.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     *         |SupplicantStatusCode.FAILURE_IFACE_DISABLED|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus find(int timeoutInSec)
        throws android.os.RemoteException;
    /**
     * Stop an ongoing P2P service discovery.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     *         |SupplicantStatusCode.FAILURE_IFACE_DISABLED|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus stopFind()
        throws android.os.RemoteException;
    /**
     * Flush P2P peer table and state.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus flush()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface connectCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String generatedPin);
    }

    /**
     * Start P2P group formation with a discovered P2P peer. This includes
     * optional group owner negotiation, group interface setup, provisioning,
     * and establishing data connection.
     *
     * @param peerAddress MAC address of the device to connect to.
     * @method provisionMethod Provisioning method to use.
     * @param preSelectedPin Pin to be used, if |provisionMethod| uses one of the
     *        preselected |PIN*| methods.
     * @param joinExistingGroup Indicates that this is a command to join an
     *        existing group as a client. It skips the group owner negotiation
     *        part. This must send a Provision Discovery Request message to the
     *        target group owner before associating for WPS provisioning.
     * @param persistent Used to request a persistent group to be formed.
     * @param goIntent Used to override the default Intent for this group owner
     *        negotiation (Values from 1-15). Refer to section 4.1.6 in
     *        Wi-Fi Peer-to-Peer (P2P) Technical Specification Version 1.7.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return generatedPin Pin generated, if |provisionMethod| uses one of the
     *         generated |PIN*| methods.
     */
    void connect(byte[/* 6 */] peerAddress, int provisionMethod, String preSelectedPin, boolean joinExistingGroup, boolean persistent, int goIntent, connectCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Cancel an ongoing P2P group formation and joining-a-group related
     * operation. This operation unauthorizes the specific peer device (if any
     * had been authorized to start group formation), stops P2P find (if in
     * progress), stops pending operations for join-a-group, and removes the
     * P2P group interface (if one was used) that is in the WPS provisioning
     * step. If the WPS provisioning step has been completed, the group is not
     * terminated.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NOT_STARTED|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelConnect()
        throws android.os.RemoteException;
    /**
     * Send P2P provision discovery request to the specified peer. The
     * parameters for this command are the P2P device address of the peer and the
     * desired configuration method.
     *
     * @param peerAddress MAC address of the device to send discovery.
     * @method provisionMethod Provisioning method to use.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus provisionDiscovery(byte[/* 6 */] peerAddress, int provisionMethod)
        throws android.os.RemoteException;
    /**
     * Set up a P2P group owner manually (i.e., without group owner
     * negotiation with a specific peer). This is also known as autonomous
     * group owner. Optional |persistentNetworkId| may be used to specify
     * restart of a persistent group.
     *
     * @param persistent Used to request a persistent group to be formed.
     * @param persistentNetworkId Used to specify the restart of a persistent
     *        group. Set to UINT32_MAX for a non-persistent group.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus addGroup(boolean persistent, int persistentNetworkId)
        throws android.os.RemoteException;
    /**
     * Terminate a P2P group. If a new virtual network interface was used for
     * the group, it must also be removed. The network interface name of the
     * group interface is used as a parameter for this command.
     *
     * @param groupIfName Group interface name to use.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeGroup(String groupIfName)
        throws android.os.RemoteException;
    /**
     * Reject connection attempt from a peer (specified with a device
     * address). This is a mechanism to reject a pending group owner negotiation
     * with a peer and request to automatically block any further connection or
     * discovery of the peer.
     *
     * @param peerAddress MAC address of the device to reject.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     *         |SupplicantStatusCode.FAILURE_IFACE_DISABLED|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus reject(byte[/* 6 */] peerAddress)
        throws android.os.RemoteException;
    /**
     * Invite a device to a persistent group.
     * If the peer device is the group owner of the persistent group, the peer
     * parameter is not needed. Otherwise it is used to specify which
     * device to invite. |goDeviceAddress| parameter may be used to override
     * the group owner device address for Invitation Request should it not be
     * known for some reason (this should not be needed in most cases).
     *
     * @param groupIfName Group interface name to use.
     * @param goDeviceAddress MAC address of the group owner device.
     * @param peerAddress MAC address of the device to invite.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus invite(String groupIfName, byte[/* 6 */] goDeviceAddress, byte[/* 6 */] peerAddress)
        throws android.os.RemoteException;
    /**
     * Reinvoke a device from a persistent group.
     *
     * @param persistentNetworkId Used to specify the persistent group.
     * @param peerAddress MAC address of the device to reinvoke.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus reinvoke(int persistentNetworkId, byte[/* 6 */] peerAddress)
        throws android.os.RemoteException;
    /**
     * Configure Extended Listen Timing.
     *
     * If enabled, listen state must be entered every |intervalInMillis| for at
     * least |periodInMillis|. Both values have acceptable range of 1-65535
     * (with interval obviously having to be larger than or equal to duration).
     * If the P2P module is not idle at the time the Extended Listen Timing
     * timeout occurs, the Listen State operation must be skipped.
     *
     * @param periodInMillis Period in milliseconds.
     * @param intervalInMillis Interval in milliseconds.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus configureExtListen(int periodInMillis, int intervalInMillis)
        throws android.os.RemoteException;
    /**
     * Set P2P Listen channel.
     *
     * When specifying a social channel on the 2.4 GHz band (1/6/11) there is no
     * need to specify the operating class since it defaults to 81. When
     * specifying a social channel on the 60 GHz band (2), specify the 60 GHz
     * operating class (180).
     *
     * @param channel Wifi channel. eg, 1, 6, 11.
     * @param operatingClass Operating Class indicates the channel set of the AP
     *        indicated by this BSSID
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setListenChannel(int channel, int operatingClass)
        throws android.os.RemoteException;
    /**
     * Set P2P disallowed frequency ranges.
     *
     * Specify ranges of frequencies that are disallowed for any p2p operations.
     *
     * @param ranges List of ranges which needs to be disallowed.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setDisallowedFrequencies(java.util.ArrayList<android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange> ranges)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getSsidCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> ssid);
    }

    /**
     * Gets the operational SSID of the device.
     *
     * @param peerAddress MAC address of the peer.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return ssid SSID of the device
     */
    void getSsid(byte[/* 6 */] peerAddress, getSsidCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getGroupCapabilityCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int capabilities);
    }

    /**
     * Gets the capability of the group which the device is a
     * member of.
     *
     * @param peerAddress MAC address of the peer.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return capabilityMask Combination of |P2pGroupCapabilityMask| values.
     */
    void getGroupCapability(byte[/* 6 */] peerAddress, getGroupCapabilityCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * This command can be used to add a bonjour service.
     *
     * @param query Hex dump of the query data.
     * @param return Hex dump of the response data.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus addBonjourService(java.util.ArrayList<Byte> query, java.util.ArrayList<Byte> response)
        throws android.os.RemoteException;
    /**
     * This command can be used to remove a bonjour service.
     *
     * @param query Hex dump of the query data.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NOT_STARTED|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeBonjourService(java.util.ArrayList<Byte> query)
        throws android.os.RemoteException;
    /**
     * This command can be used to add a UPNP service.
     *
     * @param version Version to be used.
     * @package serviceName Service name to be used.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus addUpnpService(int version, String serviceName)
        throws android.os.RemoteException;
    /**
     * This command can be used to remove a UPNP service.
     *
     * @param version Version to be used.
     * @package serviceName Service name to be used.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NOT_STARTED|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeUpnpService(int version, String serviceName)
        throws android.os.RemoteException;
    /**
     * This command can be used to flush all services from the
     * device.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus flushServices()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface requestServiceDiscoveryCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, long identifier);
    }

    /**
     * Schedule a P2P service discovery request. The parameters for this command
     * are the device address of the peer device (or 00:00:00:00:00:00 for
     * wildcard query that is sent to every discovered P2P peer that supports
     * service discovery) and P2P Service Query TLV(s) as hexdump.
     *
     * @param peerAddress MAC address of the device to discover.
     * @param query Hex dump of the query data.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return identifier Identifier for the request. Can be used to cancel the
     *         request.
     */
    void requestServiceDiscovery(byte[/* 6 */] peerAddress, java.util.ArrayList<Byte> query, requestServiceDiscoveryCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Cancel a previous service discovery request.
     *
     * @return identifier Identifier for the request to cancel.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NOT_STARTED|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelServiceDiscovery(long identifier)
        throws android.os.RemoteException;
    /**
     * Send driver command to set Miracast mode.
     *
     * @param mode Mode of Miracast.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setMiracastMode(byte mode)
        throws android.os.RemoteException;
    /**
     * Initiate WPS Push Button setup.
     * The PBC operation requires that a button is also pressed at the
     * AP/Registrar at about the same time (2 minute window).
     *
     * @param groupIfName Group interface name to use.
     * @param bssid BSSID of the AP. Use zero'ed bssid to indicate wildcard.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPbc(String groupIfName, byte[/* 6 */] bssid)
        throws android.os.RemoteException;
    /**
     * Initiate WPS Pin Keypad setup.
     *
     * @param groupIfName Group interface name to use.
     * @param pin 8 digit pin to be used.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPinKeypad(String groupIfName, String pin)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface startWpsPinDisplayCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String generatedPin);
    }

    /**
     * Initiate WPS Pin Display setup.
     *
     * @param groupIfName Group interface name to use.
     * @param bssid BSSID of the AP. Use zero'ed bssid to indicate wildcard.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return generatedPin 8 digit pin generated.
     */
    void startWpsPinDisplay(String groupIfName, byte[/* 6 */] bssid, startWpsPinDisplayCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Cancel any ongoing WPS operations.
     *
     * @param groupIfName Group interface name to use.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelWps(String groupIfName)
        throws android.os.RemoteException;
    /**
     * Enable/Disable Wifi Display.
     *
     * @param enable true to enable, false to disable.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableWfd(boolean enable)
        throws android.os.RemoteException;
    /**
     * Set Wifi Display device info.
     *
     * @param info WFD device info as described in section 5.1.2 of WFD technical
     *        specification v1.0.0.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWfdDeviceInfo(byte[/* 6 */] info)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface createNfcHandoverRequestMessageCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> request);
    }

    /**
     * Creates a NFC handover request message.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return request Bytes representing the handover request as specified in
     *         section 3.1.1 of NFC Connection Handover 1.2 Technical
     *         Specification.
     */
    void createNfcHandoverRequestMessage(createNfcHandoverRequestMessageCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface createNfcHandoverSelectMessageCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> select);
    }

    /**
     * Creates a NFC handover select message.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     * @return select Bytes representing the handover select as specified in
     *         section 3.1.2 of NFC Connection Handover 1.2 Technical
     *         Specification.
     */
    void createNfcHandoverSelectMessage(createNfcHandoverSelectMessageCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Report the response of the NFC handover request.
     *
     * @param request Bytes representing the handover request as specified in
     *        section 3.1.1 of NFC Connection Handover 1.2 Technical
     *        Specification.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus reportNfcHandoverResponse(java.util.ArrayList<Byte> request)
        throws android.os.RemoteException;
    /**
     * Report the initiation of the NFC handover select.
     *
     * @param select Bytes representing the handover select as specified in
     *        section 3.1.2 of NFC Connection Handover 1.2 Technical
     *        Specification.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus reportNfcHandoverInitiation(java.util.ArrayList<Byte> select)
        throws android.os.RemoteException;
    /**
     * Persist the current configuration to disk.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus saveConfig()
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

    public static final class Proxy implements ISupplicantP2pIface {
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
            return "[class or subclass of " + ISupplicantP2pIface.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantIface follow.
        @Override
        public void getName(getNameCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_name = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_name);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getType(getTypeCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_type = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_type);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void addNetwork(addNetworkCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* addNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork _hidl_out_network = android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_network);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeNetwork(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* removeNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNetwork(int id, getNetworkCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* getNetwork */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork _hidl_out_network = android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_network);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void listNetworks(listNetworksCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* listNetworks */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Integer> _hidl_out_networkIds = _hidl_reply.readInt32Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_networkIds);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsDeviceName(String name)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(name);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* setWpsDeviceName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsDeviceType(byte[/* 8 */] type)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 8 */]) type;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 8) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 8 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* setWpsDeviceType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsManufacturer(String manufacturer)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(manufacturer);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* setWpsManufacturer */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsModelName(String modelName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(modelName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* setWpsModelName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsModelNumber(String modelNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(modelNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* setWpsModelNumber */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsSerialNumber(String serialNumber)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeString(serialNumber);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* setWpsSerialNumber */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWpsConfigMethods(short configMethods)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);
            _hidl_request.writeInt16(configMethods);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* setWpsConfigMethods */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantP2pIface follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIfaceCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* registerCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDeviceAddress(getDeviceAddressCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* getDeviceAddress */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                byte[/* 6 */] _hidl_out_deviceAddress = new byte[6];
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(6 /* size */);
                    {
                        long _hidl_array_offset_0 = 0 /* offset */;
                        _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) _hidl_out_deviceAddress, 6 /* size */);
                        _hidl_array_offset_0 += 6 * 1;
                    }
                }
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_deviceAddress);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSsidPostfix(java.util.ArrayList<Byte> postfix)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8Vector(postfix);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* setSsidPostfix */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupIdle(String groupIfName, int timeoutInSec)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            _hidl_request.writeInt32(timeoutInSec);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* setGroupIdle */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPowerSave(String groupIfName, boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* setPowerSave */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus find(int timeoutInSec)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(timeoutInSec);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* find */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus stopFind()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* stopFind */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus flush()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* flush */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void connect(byte[/* 6 */] peerAddress, int provisionMethod, String preSelectedPin, boolean joinExistingGroup, boolean persistent, int goIntent, connectCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(provisionMethod);
            _hidl_request.writeString(preSelectedPin);
            _hidl_request.writeBool(joinExistingGroup);
            _hidl_request.writeBool(persistent);
            _hidl_request.writeInt32(goIntent);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* connect */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_generatedPin = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_generatedPin);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelConnect()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* cancelConnect */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus provisionDiscovery(byte[/* 6 */] peerAddress, int provisionMethod)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(provisionMethod);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* provisionDiscovery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus addGroup(boolean persistent, int persistentNetworkId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeBool(persistent);
            _hidl_request.writeInt32(persistentNetworkId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* addGroup */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeGroup(String groupIfName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* removeGroup */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reject(byte[/* 6 */] peerAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* reject */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus invite(String groupIfName, byte[/* 6 */] goDeviceAddress, byte[/* 6 */] peerAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) goDeviceAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* invite */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reinvoke(int persistentNetworkId, byte[/* 6 */] peerAddress)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(persistentNetworkId);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* reinvoke */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus configureExtListen(int periodInMillis, int intervalInMillis)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(periodInMillis);
            _hidl_request.writeInt32(intervalInMillis);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* configureExtListen */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setListenChannel(int channel, int operatingClass)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(channel);
            _hidl_request.writeInt32(operatingClass);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* setListenChannel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setDisallowedFrequencies(java.util.ArrayList<android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange> ranges)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange.writeVectorToParcel(_hidl_request, ranges);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* setDisallowedFrequencies */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSsid(byte[/* 6 */] peerAddress, getSsidCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* getSsid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_ssid = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ssid);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGroupCapability(byte[/* 6 */] peerAddress, getGroupCapabilityCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* getGroupCapability */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_capabilities = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus addBonjourService(java.util.ArrayList<Byte> query, java.util.ArrayList<Byte> response)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8Vector(query);
            _hidl_request.writeInt8Vector(response);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* addBonjourService */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeBonjourService(java.util.ArrayList<Byte> query)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8Vector(query);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* removeBonjourService */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus addUpnpService(int version, String serviceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(version);
            _hidl_request.writeString(serviceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* addUpnpService */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus removeUpnpService(int version, String serviceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt32(version);
            _hidl_request.writeString(serviceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* removeUpnpService */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus flushServices()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* flushServices */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestServiceDiscovery(byte[/* 6 */] peerAddress, java.util.ArrayList<Byte> query, requestServiceDiscoveryCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerAddress;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt8Vector(query);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* requestServiceDiscovery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                long _hidl_out_identifier = _hidl_reply.readInt64();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_identifier);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelServiceDiscovery(long identifier)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt64(identifier);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* cancelServiceDiscovery */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setMiracastMode(byte mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* setMiracastMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPbc(String groupIfName, byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* startWpsPbc */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus startWpsPinKeypad(String groupIfName, String pin)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            _hidl_request.writeString(pin);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* startWpsPinKeypad */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void startWpsPinDisplay(String groupIfName, byte[/* 6 */] bssid, startWpsPinDisplayCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* startWpsPinDisplay */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_generatedPin = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_generatedPin);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus cancelWps(String groupIfName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeString(groupIfName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* cancelWps */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableWfd(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* enableWfd */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWfdDeviceInfo(byte[/* 6 */] info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) info;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* setWfdDeviceInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createNfcHandoverRequestMessage(createNfcHandoverRequestMessageCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* createNfcHandoverRequestMessage */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_request = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_request);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createNfcHandoverSelectMessage(createNfcHandoverSelectMessageCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* createNfcHandoverSelectMessage */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_select = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_select);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reportNfcHandoverResponse(java.util.ArrayList<Byte> request)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8Vector(request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* reportNfcHandoverResponse */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus reportNfcHandoverInitiation(java.util.ArrayList<Byte> select)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);
            _hidl_request.writeInt8Vector(select);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* reportNfcHandoverInitiation */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus saveConfig()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* saveConfig */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
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

    public static abstract class Stub extends android.os.HwBinder implements ISupplicantP2pIface {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{73,7,65,3,56,-59,-24,-37,-18,-60,-75,-19,-62,96,-114,-93,35,-11,86,25,69,-8,-127,10,-8,24,16,-60,123,1,-111,-124} /* 4907410338c5e8dbeec4b5edc2608ea323f5561945f8810af81810c47b019184 */,
                    new byte[/* 32 */]{53,-70,123,-51,-15,-113,36,-88,102,-89,-27,66,-107,72,-16,103,104,-69,32,-94,87,-9,91,16,-93,-105,-60,-40,37,-17,-124,56} /* 35ba7bcdf18f24a866a7e5429548f06768bb20a257f75b10a397c4d825ef8438 */,
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
                case 1 /* getName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    getName(new getNameCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String name) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(name);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* getType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    getType(new getTypeCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int type) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(type);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* addNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    addNetwork(new addNetworkCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork network) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(network == null ? null : network.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* removeNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeNetwork(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* getNetwork */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    getNetwork(id, new getNetworkCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork network) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(network == null ? null : network.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 6 /* listNetworks */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    listNetworks(new listNetworksCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Integer> networkIds) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32Vector(networkIds);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* setWpsDeviceName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String name = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsDeviceName(name);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* setWpsDeviceType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    byte[/* 8 */] type = new byte[8];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(8 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 8 */]) type, 8 /* size */);
                            _hidl_array_offset_0 += 8 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsDeviceType(type);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* setWpsManufacturer */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String manufacturer = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsManufacturer(manufacturer);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* setWpsModelName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String modelName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsModelName(modelName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* setWpsModelNumber */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String modelNumber = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsModelNumber(modelNumber);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* setWpsSerialNumber */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    String serialNumber = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsSerialNumber(serialNumber);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* setWpsConfigMethods */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantIface.kInterfaceName);

                    short configMethods = _hidl_request.readInt16();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWpsConfigMethods(configMethods);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* registerCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIfaceCallback callback = android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIfaceCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* getDeviceAddress */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    getDeviceAddress(new getDeviceAddressCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, byte[/* 6 */] deviceAddress) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            {
                                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                                {
                                    long _hidl_array_offset_0 = 0 /* offset */;
                                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) deviceAddress;

                                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                                    _hidl_array_offset_0 += 6 * 1;
                                }
                                _hidl_reply.writeBuffer(_hidl_blob);
                            }
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 16 /* setSsidPostfix */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<Byte> postfix = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setSsidPostfix(postfix);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 17 /* setGroupIdle */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    int timeoutInSec = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setGroupIdle(groupIfName, timeoutInSec);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* setPowerSave */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPowerSave(groupIfName, enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 19 /* find */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int timeoutInSec = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = find(timeoutInSec);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* stopFind */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = stopFind();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* flush */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = flush();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* connect */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int provisionMethod = _hidl_request.readInt32();
                    String preSelectedPin = _hidl_request.readString();
                    boolean joinExistingGroup = _hidl_request.readBool();
                    boolean persistent = _hidl_request.readBool();
                    int goIntent = _hidl_request.readInt32();
                    connect(peerAddress, provisionMethod, preSelectedPin, joinExistingGroup, persistent, goIntent, new connectCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String generatedPin) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(generatedPin);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 23 /* cancelConnect */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = cancelConnect();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* provisionDiscovery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int provisionMethod = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = provisionDiscovery(peerAddress, provisionMethod);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 25 /* addGroup */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    boolean persistent = _hidl_request.readBool();
                    int persistentNetworkId = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = addGroup(persistent, persistentNetworkId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 26 /* removeGroup */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeGroup(groupIfName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 27 /* reject */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reject(peerAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 28 /* invite */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    byte[/* 6 */] goDeviceAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) goDeviceAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = invite(groupIfName, goDeviceAddress, peerAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 29 /* reinvoke */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int persistentNetworkId = _hidl_request.readInt32();
                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reinvoke(persistentNetworkId, peerAddress);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 30 /* configureExtListen */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int periodInMillis = _hidl_request.readInt32();
                    int intervalInMillis = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = configureExtListen(periodInMillis, intervalInMillis);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 31 /* setListenChannel */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int channel = _hidl_request.readInt32();
                    int operatingClass = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setListenChannel(channel, operatingClass);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 32 /* setDisallowedFrequencies */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange> ranges = android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.FreqRange.readVectorFromParcel(_hidl_request);
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setDisallowedFrequencies(ranges);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 33 /* getSsid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    getSsid(peerAddress, new getSsidCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> ssid) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(ssid);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 34 /* getGroupCapability */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    getGroupCapability(peerAddress, new getGroupCapabilityCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(capabilities);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 35 /* addBonjourService */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<Byte> query = _hidl_request.readInt8Vector();
                    java.util.ArrayList<Byte> response = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = addBonjourService(query, response);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 36 /* removeBonjourService */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<Byte> query = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeBonjourService(query);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 37 /* addUpnpService */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int version = _hidl_request.readInt32();
                    String serviceName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = addUpnpService(version, serviceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 38 /* removeUpnpService */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    int version = _hidl_request.readInt32();
                    String serviceName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = removeUpnpService(version, serviceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 39 /* flushServices */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = flushServices();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 40 /* requestServiceDiscovery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] peerAddress = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerAddress, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    java.util.ArrayList<Byte> query = _hidl_request.readInt8Vector();
                    requestServiceDiscovery(peerAddress, query, new requestServiceDiscoveryCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, long identifier) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt64(identifier);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 41 /* cancelServiceDiscovery */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    long identifier = _hidl_request.readInt64();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = cancelServiceDiscovery(identifier);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 42 /* setMiracastMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte mode = _hidl_request.readInt8();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setMiracastMode(mode);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 43 /* startWpsPbc */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startWpsPbc(groupIfName, bssid);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 44 /* startWpsPinKeypad */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    String pin = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = startWpsPinKeypad(groupIfName, pin);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 45 /* startWpsPinDisplay */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    startWpsPinDisplay(groupIfName, bssid, new startWpsPinDisplayCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String generatedPin) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(generatedPin);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 46 /* cancelWps */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    String groupIfName = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = cancelWps(groupIfName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 47 /* enableWfd */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = enableWfd(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 48 /* setWfdDeviceInfo */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    byte[/* 6 */] info = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) info, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWfdDeviceInfo(info);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 49 /* createNfcHandoverRequestMessage */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    createNfcHandoverRequestMessage(new createNfcHandoverRequestMessageCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> request) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(request);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 50 /* createNfcHandoverSelectMessage */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    createNfcHandoverSelectMessage(new createNfcHandoverSelectMessageCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> select) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(select);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 51 /* reportNfcHandoverResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<Byte> request = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reportNfcHandoverResponse(request);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 52 /* reportNfcHandoverInitiation */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    java.util.ArrayList<Byte> select = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = reportNfcHandoverInitiation(select);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 53 /* saveConfig */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantP2pIface.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = saveConfig();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
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
