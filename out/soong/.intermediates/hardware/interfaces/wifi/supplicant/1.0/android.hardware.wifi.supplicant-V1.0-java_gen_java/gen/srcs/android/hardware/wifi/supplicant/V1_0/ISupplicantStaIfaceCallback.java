package android.hardware.wifi.supplicant.V1_0;

/**
 * Callback Interface exposed by the supplicant service
 * for each station mode interface (ISupplicantStaIface).
 *
 * Clients need to host an instance of this HIDL interface object and
 * pass a reference of the object to the supplicant via the
 * corresponding |ISupplicantStaIface.registerCallback| method.
 */
public interface ISupplicantStaIfaceCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.supplicant@1.0::ISupplicantStaIfaceCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISupplicantStaIfaceCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISupplicantStaIfaceCallback)) {
            return (ISupplicantStaIfaceCallback)iface;
        }

        ISupplicantStaIfaceCallback proxy = new ISupplicantStaIfaceCallback.Proxy(binder);

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
    public static ISupplicantStaIfaceCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISupplicantStaIfaceCallback.asInterface(iface.asBinder());
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
    public static ISupplicantStaIfaceCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISupplicantStaIfaceCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.0::ISupplicantStaIfaceCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISupplicantStaIfaceCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIfaceCallback getService(String serviceName) throws android.os.RemoteException {
        return ISupplicantStaIfaceCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.0::ISupplicantStaIfaceCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIfaceCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Various states of the interface reported by |onStateChanged|.
     */
    public static final class State {
        /**
         * This state indicates that client is not associated, but is likely to
         * start looking for an access point. This state is entered when a
         * connection is lost.
         */
        public static final int DISCONNECTED = 0;
        /**
         * This state is entered if the network interface is disabled, e.g.,
         * due to rfkill. the supplicant refuses any new operations that would
         * use the radio until the interface has been enabled.
         */
        public static final int IFACE_DISABLED = 1;
        /**
         * This state is entered if there are no enabled networks in the
         * configuration. the supplicant is not trying to associate with a new
         * network and external interaction (e.g., ctrl_iface call to add or
         * enable a network) is needed to start association.
         */
        public static final int INACTIVE = 2;
        /**
         * This state is entered when the supplicant starts scanning for a
         * network.
         */
        public static final int SCANNING = 3;
        /**
         * This state is entered when the supplicant has found a suitable BSS
         * to authenticate with and the driver is configured to try to
         * authenticate with this BSS. This state is used only with drivers
         * that use the supplicant as the SME.
         */
        public static final int AUTHENTICATING = 4;
        /**
         * This state is entered when the supplicant has found a suitable BSS
         * to associate with and the driver is configured to try to associate
         * with this BSS in ap_scan=1 mode. When using ap_scan=2 mode, this
         * state is entered when the driver is configured to try to associate
         * with a network using the configured SSID and security policy.
         */
        public static final int ASSOCIATING = 5;
        /**
         * This state is entered when the driver reports that association has
         * been successfully completed with an AP. If IEEE 802.1X is used
         * (with or without WPA/WPA2), the supplicant remains in this state
         * until the IEEE 802.1X/EAPOL authentication has been completed.
         */
        public static final int ASSOCIATED = 6;
        /**
         * This state is entered when WPA/WPA2 4-Way Handshake is started. In
         * case of WPA-PSK, this happens when receiving the first EAPOL-Key
         * frame after association. In case of WPA-EAP, this state is entered
         * when the IEEE 802.1X/EAPOL authentication has been completed.
         */
        public static final int FOURWAY_HANDSHAKE = 7;
        /**
         * This state is entered when 4-Way Key Handshake has been completed
         * (i.e., when the supplicant sends out message 4/4) and when Group
         * Key rekeying is started by the AP (i.e., when supplicant receives
         * message 1/2).
         */
        public static final int GROUP_HANDSHAKE = 8;
        /**
         * This state is entered when the full authentication process is
         * completed. In case of WPA2, this happens when the 4-Way Handshake is
         * successfully completed. With WPA, this state is entered after the
         * Group Key Handshake; with IEEE 802.1X (non-WPA) connection is
         * completed after dynamic keys are received (or if not used, after
         * the EAP authentication has been completed). With static WEP keys and
         * plaintext connections, this state is entered when an association
         * has been completed.
         *
         * This state indicates that the supplicant has completed its
         * processing for the association phase and that data connection is
         * fully configured.
         */
        public static final int COMPLETED = 9;
        public static final String toString(int o) {
            if (o == DISCONNECTED) {
                return "DISCONNECTED";
            }
            if (o == IFACE_DISABLED) {
                return "IFACE_DISABLED";
            }
            if (o == INACTIVE) {
                return "INACTIVE";
            }
            if (o == SCANNING) {
                return "SCANNING";
            }
            if (o == AUTHENTICATING) {
                return "AUTHENTICATING";
            }
            if (o == ASSOCIATING) {
                return "ASSOCIATING";
            }
            if (o == ASSOCIATED) {
                return "ASSOCIATED";
            }
            if (o == FOURWAY_HANDSHAKE) {
                return "FOURWAY_HANDSHAKE";
            }
            if (o == GROUP_HANDSHAKE) {
                return "GROUP_HANDSHAKE";
            }
            if (o == COMPLETED) {
                return "COMPLETED";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("DISCONNECTED"); // DISCONNECTED == 0
            if ((o & IFACE_DISABLED) == IFACE_DISABLED) {
                list.add("IFACE_DISABLED");
                flipped |= IFACE_DISABLED;
            }
            if ((o & INACTIVE) == INACTIVE) {
                list.add("INACTIVE");
                flipped |= INACTIVE;
            }
            if ((o & SCANNING) == SCANNING) {
                list.add("SCANNING");
                flipped |= SCANNING;
            }
            if ((o & AUTHENTICATING) == AUTHENTICATING) {
                list.add("AUTHENTICATING");
                flipped |= AUTHENTICATING;
            }
            if ((o & ASSOCIATING) == ASSOCIATING) {
                list.add("ASSOCIATING");
                flipped |= ASSOCIATING;
            }
            if ((o & ASSOCIATED) == ASSOCIATED) {
                list.add("ASSOCIATED");
                flipped |= ASSOCIATED;
            }
            if ((o & FOURWAY_HANDSHAKE) == FOURWAY_HANDSHAKE) {
                list.add("FOURWAY_HANDSHAKE");
                flipped |= FOURWAY_HANDSHAKE;
            }
            if ((o & GROUP_HANDSHAKE) == GROUP_HANDSHAKE) {
                list.add("GROUP_HANDSHAKE");
                flipped |= GROUP_HANDSHAKE;
            }
            if ((o & COMPLETED) == COMPLETED) {
                list.add("COMPLETED");
                flipped |= COMPLETED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * OSU Method. Refer to section 4.8.1.3 of the Hotspot 2.0 spec.
     */
    public static final class OsuMethod {
        public static final byte OMA_DM = 0;
        public static final byte SOAP_XML_SPP = 1;
        public static final String toString(byte o) {
            if (o == OMA_DM) {
                return "OMA_DM";
            }
            if (o == SOAP_XML_SPP) {
                return "SOAP_XML_SPP";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("OMA_DM"); // OMA_DM == 0
            if ((o & SOAP_XML_SPP) == SOAP_XML_SPP) {
                list.add("SOAP_XML_SPP");
                flipped |= SOAP_XML_SPP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * ANQP data for IEEE Std 802.11u-2011.
     * The format of the data within these elements follows the IEEE
     * Std 802.11u-2011 standard.
     */
    public final static class AnqpData {
        public java.util.ArrayList<Byte> venueName = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> roamingConsortium = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> ipAddrTypeAvailability = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> naiRealm = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> anqp3gppCellularNetwork = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> domainName = new java.util.ArrayList<Byte>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData.class) {
                return false;
            }
            android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData other = (android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.venueName, other.venueName)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.roamingConsortium, other.roamingConsortium)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.ipAddrTypeAvailability, other.ipAddrTypeAvailability)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.naiRealm, other.naiRealm)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.anqp3gppCellularNetwork, other.anqp3gppCellularNetwork)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.domainName, other.domainName)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.venueName), 
                    android.os.HidlSupport.deepHashCode(this.roamingConsortium), 
                    android.os.HidlSupport.deepHashCode(this.ipAddrTypeAvailability), 
                    android.os.HidlSupport.deepHashCode(this.naiRealm), 
                    android.os.HidlSupport.deepHashCode(this.anqp3gppCellularNetwork), 
                    android.os.HidlSupport.deepHashCode(this.domainName));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".venueName = ");
            builder.append(this.venueName);
            builder.append(", .roamingConsortium = ");
            builder.append(this.roamingConsortium);
            builder.append(", .ipAddrTypeAvailability = ");
            builder.append(this.ipAddrTypeAvailability);
            builder.append(", .naiRealm = ");
            builder.append(this.naiRealm);
            builder.append(", .anqp3gppCellularNetwork = ");
            builder.append(this.anqp3gppCellularNetwork);
            builder.append(", .domainName = ");
            builder.append(this.domainName);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(96 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<AnqpData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<AnqpData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 96,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData _hidl_vec_element = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) venueName).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) venueName).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) roamingConsortium).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) roamingConsortium).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) ipAddrTypeAvailability).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) ipAddrTypeAvailability).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) naiRealm).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) naiRealm).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) anqp3gppCellularNetwork).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) anqp3gppCellularNetwork).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) domainName).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) domainName).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(96 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<AnqpData> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = venueName.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, venueName.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = roamingConsortium.size();
                _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, roamingConsortium.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = ipAddrTypeAvailability.size();
                _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, ipAddrTypeAvailability.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = naiRealm.size();
                _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, naiRealm.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = anqp3gppCellularNetwork.size();
                _hidl_blob.putInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 64 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, anqp3gppCellularNetwork.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = domainName.size();
                _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, domainName.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * ANQP data for Hotspot 2.0.
     * The format of the data within these elements follows the Hotspot 2.0
     * standard.
     */
    public final static class Hs20AnqpData {
        public java.util.ArrayList<Byte> operatorFriendlyName = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> wanMetrics = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> connectionCapability = new java.util.ArrayList<Byte>();
        public java.util.ArrayList<Byte> osuProvidersList = new java.util.ArrayList<Byte>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData.class) {
                return false;
            }
            android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData other = (android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.operatorFriendlyName, other.operatorFriendlyName)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.wanMetrics, other.wanMetrics)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.connectionCapability, other.connectionCapability)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.osuProvidersList, other.osuProvidersList)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.operatorFriendlyName), 
                    android.os.HidlSupport.deepHashCode(this.wanMetrics), 
                    android.os.HidlSupport.deepHashCode(this.connectionCapability), 
                    android.os.HidlSupport.deepHashCode(this.osuProvidersList));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".operatorFriendlyName = ");
            builder.append(this.operatorFriendlyName);
            builder.append(", .wanMetrics = ");
            builder.append(this.wanMetrics);
            builder.append(", .connectionCapability = ");
            builder.append(this.connectionCapability);
            builder.append(", .osuProvidersList = ");
            builder.append(this.osuProvidersList);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Hs20AnqpData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Hs20AnqpData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 64,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData _hidl_vec_element = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) operatorFriendlyName).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) operatorFriendlyName).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) wanMetrics).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) wanMetrics).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) connectionCapability).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) connectionCapability).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) osuProvidersList).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) osuProvidersList).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Hs20AnqpData> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = operatorFriendlyName.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, operatorFriendlyName.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = wanMetrics.size();
                _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, wanMetrics.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = connectionCapability.size();
                _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, connectionCapability.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = osuProvidersList.size();
                _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, osuProvidersList.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * WPS Configuration Error.
     */
    public static final class WpsConfigError {
        public static final short NO_ERROR = 0;
        public static final short OOB_IFACE_READ_ERROR = 1;
        public static final short DECRYPTION_CRC_FAILURE = 2;
        public static final short CHAN_24_NOT_SUPPORTED = 3;
        public static final short CHAN_50_NOT_SUPPORTED = 4;
        public static final short SIGNAL_TOO_WEAK = 5;
        public static final short NETWORK_AUTH_FAILURE = 6;
        public static final short NETWORK_ASSOC_FAILURE = 7;
        public static final short NO_DHCP_RESPONSE = 8;
        public static final short FAILED_DHCP_CONFIG = 9;
        public static final short IP_ADDR_CONFLICT = 10;
        public static final short NO_CONN_TO_REGISTRAR = 11;
        public static final short MULTIPLE_PBC_DETECTED = 12;
        public static final short ROGUE_SUSPECTED = 13;
        public static final short DEVICE_BUSY = 14;
        public static final short SETUP_LOCKED = 15;
        public static final short MSG_TIMEOUT = 16;
        public static final short REG_SESS_TIMEOUT = 17;
        public static final short DEV_PASSWORD_AUTH_FAILURE = 18;
        public static final short CHAN_60G_NOT_SUPPORTED = 19;
        public static final short PUBLIC_KEY_HASH_MISMATCH = 20;
        public static final String toString(short o) {
            if (o == NO_ERROR) {
                return "NO_ERROR";
            }
            if (o == OOB_IFACE_READ_ERROR) {
                return "OOB_IFACE_READ_ERROR";
            }
            if (o == DECRYPTION_CRC_FAILURE) {
                return "DECRYPTION_CRC_FAILURE";
            }
            if (o == CHAN_24_NOT_SUPPORTED) {
                return "CHAN_24_NOT_SUPPORTED";
            }
            if (o == CHAN_50_NOT_SUPPORTED) {
                return "CHAN_50_NOT_SUPPORTED";
            }
            if (o == SIGNAL_TOO_WEAK) {
                return "SIGNAL_TOO_WEAK";
            }
            if (o == NETWORK_AUTH_FAILURE) {
                return "NETWORK_AUTH_FAILURE";
            }
            if (o == NETWORK_ASSOC_FAILURE) {
                return "NETWORK_ASSOC_FAILURE";
            }
            if (o == NO_DHCP_RESPONSE) {
                return "NO_DHCP_RESPONSE";
            }
            if (o == FAILED_DHCP_CONFIG) {
                return "FAILED_DHCP_CONFIG";
            }
            if (o == IP_ADDR_CONFLICT) {
                return "IP_ADDR_CONFLICT";
            }
            if (o == NO_CONN_TO_REGISTRAR) {
                return "NO_CONN_TO_REGISTRAR";
            }
            if (o == MULTIPLE_PBC_DETECTED) {
                return "MULTIPLE_PBC_DETECTED";
            }
            if (o == ROGUE_SUSPECTED) {
                return "ROGUE_SUSPECTED";
            }
            if (o == DEVICE_BUSY) {
                return "DEVICE_BUSY";
            }
            if (o == SETUP_LOCKED) {
                return "SETUP_LOCKED";
            }
            if (o == MSG_TIMEOUT) {
                return "MSG_TIMEOUT";
            }
            if (o == REG_SESS_TIMEOUT) {
                return "REG_SESS_TIMEOUT";
            }
            if (o == DEV_PASSWORD_AUTH_FAILURE) {
                return "DEV_PASSWORD_AUTH_FAILURE";
            }
            if (o == CHAN_60G_NOT_SUPPORTED) {
                return "CHAN_60G_NOT_SUPPORTED";
            }
            if (o == PUBLIC_KEY_HASH_MISMATCH) {
                return "PUBLIC_KEY_HASH_MISMATCH";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            list.add("NO_ERROR"); // NO_ERROR == 0
            if ((o & OOB_IFACE_READ_ERROR) == OOB_IFACE_READ_ERROR) {
                list.add("OOB_IFACE_READ_ERROR");
                flipped |= OOB_IFACE_READ_ERROR;
            }
            if ((o & DECRYPTION_CRC_FAILURE) == DECRYPTION_CRC_FAILURE) {
                list.add("DECRYPTION_CRC_FAILURE");
                flipped |= DECRYPTION_CRC_FAILURE;
            }
            if ((o & CHAN_24_NOT_SUPPORTED) == CHAN_24_NOT_SUPPORTED) {
                list.add("CHAN_24_NOT_SUPPORTED");
                flipped |= CHAN_24_NOT_SUPPORTED;
            }
            if ((o & CHAN_50_NOT_SUPPORTED) == CHAN_50_NOT_SUPPORTED) {
                list.add("CHAN_50_NOT_SUPPORTED");
                flipped |= CHAN_50_NOT_SUPPORTED;
            }
            if ((o & SIGNAL_TOO_WEAK) == SIGNAL_TOO_WEAK) {
                list.add("SIGNAL_TOO_WEAK");
                flipped |= SIGNAL_TOO_WEAK;
            }
            if ((o & NETWORK_AUTH_FAILURE) == NETWORK_AUTH_FAILURE) {
                list.add("NETWORK_AUTH_FAILURE");
                flipped |= NETWORK_AUTH_FAILURE;
            }
            if ((o & NETWORK_ASSOC_FAILURE) == NETWORK_ASSOC_FAILURE) {
                list.add("NETWORK_ASSOC_FAILURE");
                flipped |= NETWORK_ASSOC_FAILURE;
            }
            if ((o & NO_DHCP_RESPONSE) == NO_DHCP_RESPONSE) {
                list.add("NO_DHCP_RESPONSE");
                flipped |= NO_DHCP_RESPONSE;
            }
            if ((o & FAILED_DHCP_CONFIG) == FAILED_DHCP_CONFIG) {
                list.add("FAILED_DHCP_CONFIG");
                flipped |= FAILED_DHCP_CONFIG;
            }
            if ((o & IP_ADDR_CONFLICT) == IP_ADDR_CONFLICT) {
                list.add("IP_ADDR_CONFLICT");
                flipped |= IP_ADDR_CONFLICT;
            }
            if ((o & NO_CONN_TO_REGISTRAR) == NO_CONN_TO_REGISTRAR) {
                list.add("NO_CONN_TO_REGISTRAR");
                flipped |= NO_CONN_TO_REGISTRAR;
            }
            if ((o & MULTIPLE_PBC_DETECTED) == MULTIPLE_PBC_DETECTED) {
                list.add("MULTIPLE_PBC_DETECTED");
                flipped |= MULTIPLE_PBC_DETECTED;
            }
            if ((o & ROGUE_SUSPECTED) == ROGUE_SUSPECTED) {
                list.add("ROGUE_SUSPECTED");
                flipped |= ROGUE_SUSPECTED;
            }
            if ((o & DEVICE_BUSY) == DEVICE_BUSY) {
                list.add("DEVICE_BUSY");
                flipped |= DEVICE_BUSY;
            }
            if ((o & SETUP_LOCKED) == SETUP_LOCKED) {
                list.add("SETUP_LOCKED");
                flipped |= SETUP_LOCKED;
            }
            if ((o & MSG_TIMEOUT) == MSG_TIMEOUT) {
                list.add("MSG_TIMEOUT");
                flipped |= MSG_TIMEOUT;
            }
            if ((o & REG_SESS_TIMEOUT) == REG_SESS_TIMEOUT) {
                list.add("REG_SESS_TIMEOUT");
                flipped |= REG_SESS_TIMEOUT;
            }
            if ((o & DEV_PASSWORD_AUTH_FAILURE) == DEV_PASSWORD_AUTH_FAILURE) {
                list.add("DEV_PASSWORD_AUTH_FAILURE");
                flipped |= DEV_PASSWORD_AUTH_FAILURE;
            }
            if ((o & CHAN_60G_NOT_SUPPORTED) == CHAN_60G_NOT_SUPPORTED) {
                list.add("CHAN_60G_NOT_SUPPORTED");
                flipped |= CHAN_60G_NOT_SUPPORTED;
            }
            if ((o & PUBLIC_KEY_HASH_MISMATCH) == PUBLIC_KEY_HASH_MISMATCH) {
                list.add("PUBLIC_KEY_HASH_MISMATCH");
                flipped |= PUBLIC_KEY_HASH_MISMATCH;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Vendor specific Error Indication for WPS event messages.
     */
    public static final class WpsErrorIndication {
        public static final short NO_ERROR = 0;
        public static final short SECURITY_TKIP_ONLY_PROHIBITED = 1;
        public static final short SECURITY_WEP_PROHIBITED = 2;
        public static final short AUTH_FAILURE = 3;
        public static final String toString(short o) {
            if (o == NO_ERROR) {
                return "NO_ERROR";
            }
            if (o == SECURITY_TKIP_ONLY_PROHIBITED) {
                return "SECURITY_TKIP_ONLY_PROHIBITED";
            }
            if (o == SECURITY_WEP_PROHIBITED) {
                return "SECURITY_WEP_PROHIBITED";
            }
            if (o == AUTH_FAILURE) {
                return "AUTH_FAILURE";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            list.add("NO_ERROR"); // NO_ERROR == 0
            if ((o & SECURITY_TKIP_ONLY_PROHIBITED) == SECURITY_TKIP_ONLY_PROHIBITED) {
                list.add("SECURITY_TKIP_ONLY_PROHIBITED");
                flipped |= SECURITY_TKIP_ONLY_PROHIBITED;
            }
            if ((o & SECURITY_WEP_PROHIBITED) == SECURITY_WEP_PROHIBITED) {
                list.add("SECURITY_WEP_PROHIBITED");
                flipped |= SECURITY_WEP_PROHIBITED;
            }
            if ((o & AUTH_FAILURE) == AUTH_FAILURE) {
                list.add("AUTH_FAILURE");
                flipped |= AUTH_FAILURE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Status codes (IEEE Std 802.11-2016, 9.4.1.9, Table 9-46).
     */
    public static final class StatusCode {
        public static final int SUCCESS = 0;
        public static final int UNSPECIFIED_FAILURE = 1;
        public static final int TDLS_WAKEUP_ALTERNATE = 2;
        public static final int TDLS_WAKEUP_REJECT = 3;
        public static final int SECURITY_DISABLED = 5;
        public static final int UNACCEPTABLE_LIFETIME = 6;
        public static final int NOT_IN_SAME_BSS = 7;
        public static final int CAPS_UNSUPPORTED = 10;
        public static final int REASSOC_NO_ASSOC = 11;
        public static final int ASSOC_DENIED_UNSPEC = 12;
        public static final int NOT_SUPPORTED_AUTH_ALG = 13;
        public static final int UNKNOWN_AUTH_TRANSACTION = 14;
        public static final int CHALLENGE_FAIL = 15;
        public static final int AUTH_TIMEOUT = 16;
        public static final int AP_UNABLE_TO_HANDLE_NEW_STA = 17;
        public static final int ASSOC_DENIED_RATES = 18;
        public static final int ASSOC_DENIED_NOSHORT = 19;
        public static final int SPEC_MGMT_REQUIRED = 22;
        public static final int PWR_CAPABILITY_NOT_VALID = 23;
        public static final int SUPPORTED_CHANNEL_NOT_VALID = 24;
        public static final int ASSOC_DENIED_NO_SHORT_SLOT_TIME = 25;
        public static final int ASSOC_DENIED_NO_HT = 27;
        public static final int R0KH_UNREACHABLE = 28;
        public static final int ASSOC_DENIED_NO_PCO = 29;
        public static final int ASSOC_REJECTED_TEMPORARILY = 30;
        public static final int ROBUST_MGMT_FRAME_POLICY_VIOLATION = 31;
        public static final int UNSPECIFIED_QOS_FAILURE = 32;
        public static final int DENIED_INSUFFICIENT_BANDWIDTH = 33;
        public static final int DENIED_POOR_CHANNEL_CONDITIONS = 34;
        public static final int DENIED_QOS_NOT_SUPPORTED = 35;
        public static final int REQUEST_DECLINED = 37;
        public static final int INVALID_PARAMETERS = 38;
        public static final int REJECTED_WITH_SUGGESTED_CHANGES = 39;
        public static final int INVALID_IE = 40;
        public static final int GROUP_CIPHER_NOT_VALID = 41;
        public static final int PAIRWISE_CIPHER_NOT_VALID = 42;
        public static final int AKMP_NOT_VALID = 43;
        public static final int UNSUPPORTED_RSN_IE_VERSION = 44;
        public static final int INVALID_RSN_IE_CAPAB = 45;
        public static final int CIPHER_REJECTED_PER_POLICY = 46;
        public static final int TS_NOT_CREATED = 47;
        public static final int DIRECT_LINK_NOT_ALLOWED = 48;
        public static final int DEST_STA_NOT_PRESENT = 49;
        public static final int DEST_STA_NOT_QOS_STA = 50;
        public static final int ASSOC_DENIED_LISTEN_INT_TOO_LARGE = 51;
        public static final int INVALID_FT_ACTION_FRAME_COUNT = 52;
        public static final int INVALID_PMKID = 53;
        public static final int INVALID_MDIE = 54;
        public static final int INVALID_FTIE = 55;
        public static final int REQUESTED_TCLAS_NOT_SUPPORTED = 56;
        public static final int INSUFFICIENT_TCLAS_PROCESSING_RESOURCES = 57;
        public static final int TRY_ANOTHER_BSS = 58;
        public static final int GAS_ADV_PROTO_NOT_SUPPORTED = 59;
        public static final int NO_OUTSTANDING_GAS_REQ = 60;
        public static final int GAS_RESP_NOT_RECEIVED = 61;
        public static final int STA_TIMED_OUT_WAITING_FOR_GAS_RESP = 62;
        public static final int GAS_RESP_LARGER_THAN_LIMIT = 63;
        public static final int REQ_REFUSED_HOME = 64;
        public static final int ADV_SRV_UNREACHABLE = 65;
        public static final int REQ_REFUSED_SSPN = 67;
        public static final int REQ_REFUSED_UNAUTH_ACCESS = 68;
        public static final int INVALID_RSNIE = 72;
        public static final int U_APSD_COEX_NOT_SUPPORTED = 73;
        public static final int U_APSD_COEX_MODE_NOT_SUPPORTED = 74;
        public static final int BAD_INTERVAL_WITH_U_APSD_COEX = 75;
        public static final int ANTI_CLOGGING_TOKEN_REQ = 76;
        public static final int FINITE_CYCLIC_GROUP_NOT_SUPPORTED = 77;
        public static final int CANNOT_FIND_ALT_TBTT = 78;
        public static final int TRANSMISSION_FAILURE = 79;
        public static final int REQ_TCLAS_NOT_SUPPORTED = 80;
        public static final int TCLAS_RESOURCES_EXCHAUSTED = 81;
        public static final int REJECTED_WITH_SUGGESTED_BSS_TRANSITION = 82;
        public static final int REJECT_WITH_SCHEDULE = 83;
        public static final int REJECT_NO_WAKEUP_SPECIFIED = 84;
        public static final int SUCCESS_POWER_SAVE_MODE = 85;
        public static final int PENDING_ADMITTING_FST_SESSION = 86;
        public static final int PERFORMING_FST_NOW = 87;
        public static final int PENDING_GAP_IN_BA_WINDOW = 88;
        public static final int REJECT_U_PID_SETTING = 89;
        public static final int REFUSED_EXTERNAL_REASON = 92;
        public static final int REFUSED_AP_OUT_OF_MEMORY = 93;
        public static final int REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED = 94;
        public static final int QUERY_RESP_OUTSTANDING = 95;
        public static final int REJECT_DSE_BAND = 96;
        public static final int TCLAS_PROCESSING_TERMINATED = 97;
        public static final int TS_SCHEDULE_CONFLICT = 98;
        public static final int DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL = 99;
        public static final int MCCAOP_RESERVATION_CONFLICT = 100;
        public static final int MAF_LIMIT_EXCEEDED = 101;
        public static final int MCCA_TRACK_LIMIT_EXCEEDED = 102;
        public static final int DENIED_DUE_TO_SPECTRUM_MANAGEMENT = 103;
        public static final int ASSOC_DENIED_NO_VHT = 104;
        public static final int ENABLEMENT_DENIED = 105;
        public static final int RESTRICTION_FROM_AUTHORIZED_GDB = 106;
        public static final int AUTHORIZATION_DEENABLED = 107;
        public static final int FILS_AUTHENTICATION_FAILURE = 112;
        public static final int UNKNOWN_AUTHENTICATION_SERVER = 113;
        public static final String toString(int o) {
            if (o == SUCCESS) {
                return "SUCCESS";
            }
            if (o == UNSPECIFIED_FAILURE) {
                return "UNSPECIFIED_FAILURE";
            }
            if (o == TDLS_WAKEUP_ALTERNATE) {
                return "TDLS_WAKEUP_ALTERNATE";
            }
            if (o == TDLS_WAKEUP_REJECT) {
                return "TDLS_WAKEUP_REJECT";
            }
            if (o == SECURITY_DISABLED) {
                return "SECURITY_DISABLED";
            }
            if (o == UNACCEPTABLE_LIFETIME) {
                return "UNACCEPTABLE_LIFETIME";
            }
            if (o == NOT_IN_SAME_BSS) {
                return "NOT_IN_SAME_BSS";
            }
            if (o == CAPS_UNSUPPORTED) {
                return "CAPS_UNSUPPORTED";
            }
            if (o == REASSOC_NO_ASSOC) {
                return "REASSOC_NO_ASSOC";
            }
            if (o == ASSOC_DENIED_UNSPEC) {
                return "ASSOC_DENIED_UNSPEC";
            }
            if (o == NOT_SUPPORTED_AUTH_ALG) {
                return "NOT_SUPPORTED_AUTH_ALG";
            }
            if (o == UNKNOWN_AUTH_TRANSACTION) {
                return "UNKNOWN_AUTH_TRANSACTION";
            }
            if (o == CHALLENGE_FAIL) {
                return "CHALLENGE_FAIL";
            }
            if (o == AUTH_TIMEOUT) {
                return "AUTH_TIMEOUT";
            }
            if (o == AP_UNABLE_TO_HANDLE_NEW_STA) {
                return "AP_UNABLE_TO_HANDLE_NEW_STA";
            }
            if (o == ASSOC_DENIED_RATES) {
                return "ASSOC_DENIED_RATES";
            }
            if (o == ASSOC_DENIED_NOSHORT) {
                return "ASSOC_DENIED_NOSHORT";
            }
            if (o == SPEC_MGMT_REQUIRED) {
                return "SPEC_MGMT_REQUIRED";
            }
            if (o == PWR_CAPABILITY_NOT_VALID) {
                return "PWR_CAPABILITY_NOT_VALID";
            }
            if (o == SUPPORTED_CHANNEL_NOT_VALID) {
                return "SUPPORTED_CHANNEL_NOT_VALID";
            }
            if (o == ASSOC_DENIED_NO_SHORT_SLOT_TIME) {
                return "ASSOC_DENIED_NO_SHORT_SLOT_TIME";
            }
            if (o == ASSOC_DENIED_NO_HT) {
                return "ASSOC_DENIED_NO_HT";
            }
            if (o == R0KH_UNREACHABLE) {
                return "R0KH_UNREACHABLE";
            }
            if (o == ASSOC_DENIED_NO_PCO) {
                return "ASSOC_DENIED_NO_PCO";
            }
            if (o == ASSOC_REJECTED_TEMPORARILY) {
                return "ASSOC_REJECTED_TEMPORARILY";
            }
            if (o == ROBUST_MGMT_FRAME_POLICY_VIOLATION) {
                return "ROBUST_MGMT_FRAME_POLICY_VIOLATION";
            }
            if (o == UNSPECIFIED_QOS_FAILURE) {
                return "UNSPECIFIED_QOS_FAILURE";
            }
            if (o == DENIED_INSUFFICIENT_BANDWIDTH) {
                return "DENIED_INSUFFICIENT_BANDWIDTH";
            }
            if (o == DENIED_POOR_CHANNEL_CONDITIONS) {
                return "DENIED_POOR_CHANNEL_CONDITIONS";
            }
            if (o == DENIED_QOS_NOT_SUPPORTED) {
                return "DENIED_QOS_NOT_SUPPORTED";
            }
            if (o == REQUEST_DECLINED) {
                return "REQUEST_DECLINED";
            }
            if (o == INVALID_PARAMETERS) {
                return "INVALID_PARAMETERS";
            }
            if (o == REJECTED_WITH_SUGGESTED_CHANGES) {
                return "REJECTED_WITH_SUGGESTED_CHANGES";
            }
            if (o == INVALID_IE) {
                return "INVALID_IE";
            }
            if (o == GROUP_CIPHER_NOT_VALID) {
                return "GROUP_CIPHER_NOT_VALID";
            }
            if (o == PAIRWISE_CIPHER_NOT_VALID) {
                return "PAIRWISE_CIPHER_NOT_VALID";
            }
            if (o == AKMP_NOT_VALID) {
                return "AKMP_NOT_VALID";
            }
            if (o == UNSUPPORTED_RSN_IE_VERSION) {
                return "UNSUPPORTED_RSN_IE_VERSION";
            }
            if (o == INVALID_RSN_IE_CAPAB) {
                return "INVALID_RSN_IE_CAPAB";
            }
            if (o == CIPHER_REJECTED_PER_POLICY) {
                return "CIPHER_REJECTED_PER_POLICY";
            }
            if (o == TS_NOT_CREATED) {
                return "TS_NOT_CREATED";
            }
            if (o == DIRECT_LINK_NOT_ALLOWED) {
                return "DIRECT_LINK_NOT_ALLOWED";
            }
            if (o == DEST_STA_NOT_PRESENT) {
                return "DEST_STA_NOT_PRESENT";
            }
            if (o == DEST_STA_NOT_QOS_STA) {
                return "DEST_STA_NOT_QOS_STA";
            }
            if (o == ASSOC_DENIED_LISTEN_INT_TOO_LARGE) {
                return "ASSOC_DENIED_LISTEN_INT_TOO_LARGE";
            }
            if (o == INVALID_FT_ACTION_FRAME_COUNT) {
                return "INVALID_FT_ACTION_FRAME_COUNT";
            }
            if (o == INVALID_PMKID) {
                return "INVALID_PMKID";
            }
            if (o == INVALID_MDIE) {
                return "INVALID_MDIE";
            }
            if (o == INVALID_FTIE) {
                return "INVALID_FTIE";
            }
            if (o == REQUESTED_TCLAS_NOT_SUPPORTED) {
                return "REQUESTED_TCLAS_NOT_SUPPORTED";
            }
            if (o == INSUFFICIENT_TCLAS_PROCESSING_RESOURCES) {
                return "INSUFFICIENT_TCLAS_PROCESSING_RESOURCES";
            }
            if (o == TRY_ANOTHER_BSS) {
                return "TRY_ANOTHER_BSS";
            }
            if (o == GAS_ADV_PROTO_NOT_SUPPORTED) {
                return "GAS_ADV_PROTO_NOT_SUPPORTED";
            }
            if (o == NO_OUTSTANDING_GAS_REQ) {
                return "NO_OUTSTANDING_GAS_REQ";
            }
            if (o == GAS_RESP_NOT_RECEIVED) {
                return "GAS_RESP_NOT_RECEIVED";
            }
            if (o == STA_TIMED_OUT_WAITING_FOR_GAS_RESP) {
                return "STA_TIMED_OUT_WAITING_FOR_GAS_RESP";
            }
            if (o == GAS_RESP_LARGER_THAN_LIMIT) {
                return "GAS_RESP_LARGER_THAN_LIMIT";
            }
            if (o == REQ_REFUSED_HOME) {
                return "REQ_REFUSED_HOME";
            }
            if (o == ADV_SRV_UNREACHABLE) {
                return "ADV_SRV_UNREACHABLE";
            }
            if (o == REQ_REFUSED_SSPN) {
                return "REQ_REFUSED_SSPN";
            }
            if (o == REQ_REFUSED_UNAUTH_ACCESS) {
                return "REQ_REFUSED_UNAUTH_ACCESS";
            }
            if (o == INVALID_RSNIE) {
                return "INVALID_RSNIE";
            }
            if (o == U_APSD_COEX_NOT_SUPPORTED) {
                return "U_APSD_COEX_NOT_SUPPORTED";
            }
            if (o == U_APSD_COEX_MODE_NOT_SUPPORTED) {
                return "U_APSD_COEX_MODE_NOT_SUPPORTED";
            }
            if (o == BAD_INTERVAL_WITH_U_APSD_COEX) {
                return "BAD_INTERVAL_WITH_U_APSD_COEX";
            }
            if (o == ANTI_CLOGGING_TOKEN_REQ) {
                return "ANTI_CLOGGING_TOKEN_REQ";
            }
            if (o == FINITE_CYCLIC_GROUP_NOT_SUPPORTED) {
                return "FINITE_CYCLIC_GROUP_NOT_SUPPORTED";
            }
            if (o == CANNOT_FIND_ALT_TBTT) {
                return "CANNOT_FIND_ALT_TBTT";
            }
            if (o == TRANSMISSION_FAILURE) {
                return "TRANSMISSION_FAILURE";
            }
            if (o == REQ_TCLAS_NOT_SUPPORTED) {
                return "REQ_TCLAS_NOT_SUPPORTED";
            }
            if (o == TCLAS_RESOURCES_EXCHAUSTED) {
                return "TCLAS_RESOURCES_EXCHAUSTED";
            }
            if (o == REJECTED_WITH_SUGGESTED_BSS_TRANSITION) {
                return "REJECTED_WITH_SUGGESTED_BSS_TRANSITION";
            }
            if (o == REJECT_WITH_SCHEDULE) {
                return "REJECT_WITH_SCHEDULE";
            }
            if (o == REJECT_NO_WAKEUP_SPECIFIED) {
                return "REJECT_NO_WAKEUP_SPECIFIED";
            }
            if (o == SUCCESS_POWER_SAVE_MODE) {
                return "SUCCESS_POWER_SAVE_MODE";
            }
            if (o == PENDING_ADMITTING_FST_SESSION) {
                return "PENDING_ADMITTING_FST_SESSION";
            }
            if (o == PERFORMING_FST_NOW) {
                return "PERFORMING_FST_NOW";
            }
            if (o == PENDING_GAP_IN_BA_WINDOW) {
                return "PENDING_GAP_IN_BA_WINDOW";
            }
            if (o == REJECT_U_PID_SETTING) {
                return "REJECT_U_PID_SETTING";
            }
            if (o == REFUSED_EXTERNAL_REASON) {
                return "REFUSED_EXTERNAL_REASON";
            }
            if (o == REFUSED_AP_OUT_OF_MEMORY) {
                return "REFUSED_AP_OUT_OF_MEMORY";
            }
            if (o == REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED) {
                return "REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED";
            }
            if (o == QUERY_RESP_OUTSTANDING) {
                return "QUERY_RESP_OUTSTANDING";
            }
            if (o == REJECT_DSE_BAND) {
                return "REJECT_DSE_BAND";
            }
            if (o == TCLAS_PROCESSING_TERMINATED) {
                return "TCLAS_PROCESSING_TERMINATED";
            }
            if (o == TS_SCHEDULE_CONFLICT) {
                return "TS_SCHEDULE_CONFLICT";
            }
            if (o == DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL) {
                return "DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL";
            }
            if (o == MCCAOP_RESERVATION_CONFLICT) {
                return "MCCAOP_RESERVATION_CONFLICT";
            }
            if (o == MAF_LIMIT_EXCEEDED) {
                return "MAF_LIMIT_EXCEEDED";
            }
            if (o == MCCA_TRACK_LIMIT_EXCEEDED) {
                return "MCCA_TRACK_LIMIT_EXCEEDED";
            }
            if (o == DENIED_DUE_TO_SPECTRUM_MANAGEMENT) {
                return "DENIED_DUE_TO_SPECTRUM_MANAGEMENT";
            }
            if (o == ASSOC_DENIED_NO_VHT) {
                return "ASSOC_DENIED_NO_VHT";
            }
            if (o == ENABLEMENT_DENIED) {
                return "ENABLEMENT_DENIED";
            }
            if (o == RESTRICTION_FROM_AUTHORIZED_GDB) {
                return "RESTRICTION_FROM_AUTHORIZED_GDB";
            }
            if (o == AUTHORIZATION_DEENABLED) {
                return "AUTHORIZATION_DEENABLED";
            }
            if (o == FILS_AUTHENTICATION_FAILURE) {
                return "FILS_AUTHENTICATION_FAILURE";
            }
            if (o == UNKNOWN_AUTHENTICATION_SERVER) {
                return "UNKNOWN_AUTHENTICATION_SERVER";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("SUCCESS"); // SUCCESS == 0
            if ((o & UNSPECIFIED_FAILURE) == UNSPECIFIED_FAILURE) {
                list.add("UNSPECIFIED_FAILURE");
                flipped |= UNSPECIFIED_FAILURE;
            }
            if ((o & TDLS_WAKEUP_ALTERNATE) == TDLS_WAKEUP_ALTERNATE) {
                list.add("TDLS_WAKEUP_ALTERNATE");
                flipped |= TDLS_WAKEUP_ALTERNATE;
            }
            if ((o & TDLS_WAKEUP_REJECT) == TDLS_WAKEUP_REJECT) {
                list.add("TDLS_WAKEUP_REJECT");
                flipped |= TDLS_WAKEUP_REJECT;
            }
            if ((o & SECURITY_DISABLED) == SECURITY_DISABLED) {
                list.add("SECURITY_DISABLED");
                flipped |= SECURITY_DISABLED;
            }
            if ((o & UNACCEPTABLE_LIFETIME) == UNACCEPTABLE_LIFETIME) {
                list.add("UNACCEPTABLE_LIFETIME");
                flipped |= UNACCEPTABLE_LIFETIME;
            }
            if ((o & NOT_IN_SAME_BSS) == NOT_IN_SAME_BSS) {
                list.add("NOT_IN_SAME_BSS");
                flipped |= NOT_IN_SAME_BSS;
            }
            if ((o & CAPS_UNSUPPORTED) == CAPS_UNSUPPORTED) {
                list.add("CAPS_UNSUPPORTED");
                flipped |= CAPS_UNSUPPORTED;
            }
            if ((o & REASSOC_NO_ASSOC) == REASSOC_NO_ASSOC) {
                list.add("REASSOC_NO_ASSOC");
                flipped |= REASSOC_NO_ASSOC;
            }
            if ((o & ASSOC_DENIED_UNSPEC) == ASSOC_DENIED_UNSPEC) {
                list.add("ASSOC_DENIED_UNSPEC");
                flipped |= ASSOC_DENIED_UNSPEC;
            }
            if ((o & NOT_SUPPORTED_AUTH_ALG) == NOT_SUPPORTED_AUTH_ALG) {
                list.add("NOT_SUPPORTED_AUTH_ALG");
                flipped |= NOT_SUPPORTED_AUTH_ALG;
            }
            if ((o & UNKNOWN_AUTH_TRANSACTION) == UNKNOWN_AUTH_TRANSACTION) {
                list.add("UNKNOWN_AUTH_TRANSACTION");
                flipped |= UNKNOWN_AUTH_TRANSACTION;
            }
            if ((o & CHALLENGE_FAIL) == CHALLENGE_FAIL) {
                list.add("CHALLENGE_FAIL");
                flipped |= CHALLENGE_FAIL;
            }
            if ((o & AUTH_TIMEOUT) == AUTH_TIMEOUT) {
                list.add("AUTH_TIMEOUT");
                flipped |= AUTH_TIMEOUT;
            }
            if ((o & AP_UNABLE_TO_HANDLE_NEW_STA) == AP_UNABLE_TO_HANDLE_NEW_STA) {
                list.add("AP_UNABLE_TO_HANDLE_NEW_STA");
                flipped |= AP_UNABLE_TO_HANDLE_NEW_STA;
            }
            if ((o & ASSOC_DENIED_RATES) == ASSOC_DENIED_RATES) {
                list.add("ASSOC_DENIED_RATES");
                flipped |= ASSOC_DENIED_RATES;
            }
            if ((o & ASSOC_DENIED_NOSHORT) == ASSOC_DENIED_NOSHORT) {
                list.add("ASSOC_DENIED_NOSHORT");
                flipped |= ASSOC_DENIED_NOSHORT;
            }
            if ((o & SPEC_MGMT_REQUIRED) == SPEC_MGMT_REQUIRED) {
                list.add("SPEC_MGMT_REQUIRED");
                flipped |= SPEC_MGMT_REQUIRED;
            }
            if ((o & PWR_CAPABILITY_NOT_VALID) == PWR_CAPABILITY_NOT_VALID) {
                list.add("PWR_CAPABILITY_NOT_VALID");
                flipped |= PWR_CAPABILITY_NOT_VALID;
            }
            if ((o & SUPPORTED_CHANNEL_NOT_VALID) == SUPPORTED_CHANNEL_NOT_VALID) {
                list.add("SUPPORTED_CHANNEL_NOT_VALID");
                flipped |= SUPPORTED_CHANNEL_NOT_VALID;
            }
            if ((o & ASSOC_DENIED_NO_SHORT_SLOT_TIME) == ASSOC_DENIED_NO_SHORT_SLOT_TIME) {
                list.add("ASSOC_DENIED_NO_SHORT_SLOT_TIME");
                flipped |= ASSOC_DENIED_NO_SHORT_SLOT_TIME;
            }
            if ((o & ASSOC_DENIED_NO_HT) == ASSOC_DENIED_NO_HT) {
                list.add("ASSOC_DENIED_NO_HT");
                flipped |= ASSOC_DENIED_NO_HT;
            }
            if ((o & R0KH_UNREACHABLE) == R0KH_UNREACHABLE) {
                list.add("R0KH_UNREACHABLE");
                flipped |= R0KH_UNREACHABLE;
            }
            if ((o & ASSOC_DENIED_NO_PCO) == ASSOC_DENIED_NO_PCO) {
                list.add("ASSOC_DENIED_NO_PCO");
                flipped |= ASSOC_DENIED_NO_PCO;
            }
            if ((o & ASSOC_REJECTED_TEMPORARILY) == ASSOC_REJECTED_TEMPORARILY) {
                list.add("ASSOC_REJECTED_TEMPORARILY");
                flipped |= ASSOC_REJECTED_TEMPORARILY;
            }
            if ((o & ROBUST_MGMT_FRAME_POLICY_VIOLATION) == ROBUST_MGMT_FRAME_POLICY_VIOLATION) {
                list.add("ROBUST_MGMT_FRAME_POLICY_VIOLATION");
                flipped |= ROBUST_MGMT_FRAME_POLICY_VIOLATION;
            }
            if ((o & UNSPECIFIED_QOS_FAILURE) == UNSPECIFIED_QOS_FAILURE) {
                list.add("UNSPECIFIED_QOS_FAILURE");
                flipped |= UNSPECIFIED_QOS_FAILURE;
            }
            if ((o & DENIED_INSUFFICIENT_BANDWIDTH) == DENIED_INSUFFICIENT_BANDWIDTH) {
                list.add("DENIED_INSUFFICIENT_BANDWIDTH");
                flipped |= DENIED_INSUFFICIENT_BANDWIDTH;
            }
            if ((o & DENIED_POOR_CHANNEL_CONDITIONS) == DENIED_POOR_CHANNEL_CONDITIONS) {
                list.add("DENIED_POOR_CHANNEL_CONDITIONS");
                flipped |= DENIED_POOR_CHANNEL_CONDITIONS;
            }
            if ((o & DENIED_QOS_NOT_SUPPORTED) == DENIED_QOS_NOT_SUPPORTED) {
                list.add("DENIED_QOS_NOT_SUPPORTED");
                flipped |= DENIED_QOS_NOT_SUPPORTED;
            }
            if ((o & REQUEST_DECLINED) == REQUEST_DECLINED) {
                list.add("REQUEST_DECLINED");
                flipped |= REQUEST_DECLINED;
            }
            if ((o & INVALID_PARAMETERS) == INVALID_PARAMETERS) {
                list.add("INVALID_PARAMETERS");
                flipped |= INVALID_PARAMETERS;
            }
            if ((o & REJECTED_WITH_SUGGESTED_CHANGES) == REJECTED_WITH_SUGGESTED_CHANGES) {
                list.add("REJECTED_WITH_SUGGESTED_CHANGES");
                flipped |= REJECTED_WITH_SUGGESTED_CHANGES;
            }
            if ((o & INVALID_IE) == INVALID_IE) {
                list.add("INVALID_IE");
                flipped |= INVALID_IE;
            }
            if ((o & GROUP_CIPHER_NOT_VALID) == GROUP_CIPHER_NOT_VALID) {
                list.add("GROUP_CIPHER_NOT_VALID");
                flipped |= GROUP_CIPHER_NOT_VALID;
            }
            if ((o & PAIRWISE_CIPHER_NOT_VALID) == PAIRWISE_CIPHER_NOT_VALID) {
                list.add("PAIRWISE_CIPHER_NOT_VALID");
                flipped |= PAIRWISE_CIPHER_NOT_VALID;
            }
            if ((o & AKMP_NOT_VALID) == AKMP_NOT_VALID) {
                list.add("AKMP_NOT_VALID");
                flipped |= AKMP_NOT_VALID;
            }
            if ((o & UNSUPPORTED_RSN_IE_VERSION) == UNSUPPORTED_RSN_IE_VERSION) {
                list.add("UNSUPPORTED_RSN_IE_VERSION");
                flipped |= UNSUPPORTED_RSN_IE_VERSION;
            }
            if ((o & INVALID_RSN_IE_CAPAB) == INVALID_RSN_IE_CAPAB) {
                list.add("INVALID_RSN_IE_CAPAB");
                flipped |= INVALID_RSN_IE_CAPAB;
            }
            if ((o & CIPHER_REJECTED_PER_POLICY) == CIPHER_REJECTED_PER_POLICY) {
                list.add("CIPHER_REJECTED_PER_POLICY");
                flipped |= CIPHER_REJECTED_PER_POLICY;
            }
            if ((o & TS_NOT_CREATED) == TS_NOT_CREATED) {
                list.add("TS_NOT_CREATED");
                flipped |= TS_NOT_CREATED;
            }
            if ((o & DIRECT_LINK_NOT_ALLOWED) == DIRECT_LINK_NOT_ALLOWED) {
                list.add("DIRECT_LINK_NOT_ALLOWED");
                flipped |= DIRECT_LINK_NOT_ALLOWED;
            }
            if ((o & DEST_STA_NOT_PRESENT) == DEST_STA_NOT_PRESENT) {
                list.add("DEST_STA_NOT_PRESENT");
                flipped |= DEST_STA_NOT_PRESENT;
            }
            if ((o & DEST_STA_NOT_QOS_STA) == DEST_STA_NOT_QOS_STA) {
                list.add("DEST_STA_NOT_QOS_STA");
                flipped |= DEST_STA_NOT_QOS_STA;
            }
            if ((o & ASSOC_DENIED_LISTEN_INT_TOO_LARGE) == ASSOC_DENIED_LISTEN_INT_TOO_LARGE) {
                list.add("ASSOC_DENIED_LISTEN_INT_TOO_LARGE");
                flipped |= ASSOC_DENIED_LISTEN_INT_TOO_LARGE;
            }
            if ((o & INVALID_FT_ACTION_FRAME_COUNT) == INVALID_FT_ACTION_FRAME_COUNT) {
                list.add("INVALID_FT_ACTION_FRAME_COUNT");
                flipped |= INVALID_FT_ACTION_FRAME_COUNT;
            }
            if ((o & INVALID_PMKID) == INVALID_PMKID) {
                list.add("INVALID_PMKID");
                flipped |= INVALID_PMKID;
            }
            if ((o & INVALID_MDIE) == INVALID_MDIE) {
                list.add("INVALID_MDIE");
                flipped |= INVALID_MDIE;
            }
            if ((o & INVALID_FTIE) == INVALID_FTIE) {
                list.add("INVALID_FTIE");
                flipped |= INVALID_FTIE;
            }
            if ((o & REQUESTED_TCLAS_NOT_SUPPORTED) == REQUESTED_TCLAS_NOT_SUPPORTED) {
                list.add("REQUESTED_TCLAS_NOT_SUPPORTED");
                flipped |= REQUESTED_TCLAS_NOT_SUPPORTED;
            }
            if ((o & INSUFFICIENT_TCLAS_PROCESSING_RESOURCES) == INSUFFICIENT_TCLAS_PROCESSING_RESOURCES) {
                list.add("INSUFFICIENT_TCLAS_PROCESSING_RESOURCES");
                flipped |= INSUFFICIENT_TCLAS_PROCESSING_RESOURCES;
            }
            if ((o & TRY_ANOTHER_BSS) == TRY_ANOTHER_BSS) {
                list.add("TRY_ANOTHER_BSS");
                flipped |= TRY_ANOTHER_BSS;
            }
            if ((o & GAS_ADV_PROTO_NOT_SUPPORTED) == GAS_ADV_PROTO_NOT_SUPPORTED) {
                list.add("GAS_ADV_PROTO_NOT_SUPPORTED");
                flipped |= GAS_ADV_PROTO_NOT_SUPPORTED;
            }
            if ((o & NO_OUTSTANDING_GAS_REQ) == NO_OUTSTANDING_GAS_REQ) {
                list.add("NO_OUTSTANDING_GAS_REQ");
                flipped |= NO_OUTSTANDING_GAS_REQ;
            }
            if ((o & GAS_RESP_NOT_RECEIVED) == GAS_RESP_NOT_RECEIVED) {
                list.add("GAS_RESP_NOT_RECEIVED");
                flipped |= GAS_RESP_NOT_RECEIVED;
            }
            if ((o & STA_TIMED_OUT_WAITING_FOR_GAS_RESP) == STA_TIMED_OUT_WAITING_FOR_GAS_RESP) {
                list.add("STA_TIMED_OUT_WAITING_FOR_GAS_RESP");
                flipped |= STA_TIMED_OUT_WAITING_FOR_GAS_RESP;
            }
            if ((o & GAS_RESP_LARGER_THAN_LIMIT) == GAS_RESP_LARGER_THAN_LIMIT) {
                list.add("GAS_RESP_LARGER_THAN_LIMIT");
                flipped |= GAS_RESP_LARGER_THAN_LIMIT;
            }
            if ((o & REQ_REFUSED_HOME) == REQ_REFUSED_HOME) {
                list.add("REQ_REFUSED_HOME");
                flipped |= REQ_REFUSED_HOME;
            }
            if ((o & ADV_SRV_UNREACHABLE) == ADV_SRV_UNREACHABLE) {
                list.add("ADV_SRV_UNREACHABLE");
                flipped |= ADV_SRV_UNREACHABLE;
            }
            if ((o & REQ_REFUSED_SSPN) == REQ_REFUSED_SSPN) {
                list.add("REQ_REFUSED_SSPN");
                flipped |= REQ_REFUSED_SSPN;
            }
            if ((o & REQ_REFUSED_UNAUTH_ACCESS) == REQ_REFUSED_UNAUTH_ACCESS) {
                list.add("REQ_REFUSED_UNAUTH_ACCESS");
                flipped |= REQ_REFUSED_UNAUTH_ACCESS;
            }
            if ((o & INVALID_RSNIE) == INVALID_RSNIE) {
                list.add("INVALID_RSNIE");
                flipped |= INVALID_RSNIE;
            }
            if ((o & U_APSD_COEX_NOT_SUPPORTED) == U_APSD_COEX_NOT_SUPPORTED) {
                list.add("U_APSD_COEX_NOT_SUPPORTED");
                flipped |= U_APSD_COEX_NOT_SUPPORTED;
            }
            if ((o & U_APSD_COEX_MODE_NOT_SUPPORTED) == U_APSD_COEX_MODE_NOT_SUPPORTED) {
                list.add("U_APSD_COEX_MODE_NOT_SUPPORTED");
                flipped |= U_APSD_COEX_MODE_NOT_SUPPORTED;
            }
            if ((o & BAD_INTERVAL_WITH_U_APSD_COEX) == BAD_INTERVAL_WITH_U_APSD_COEX) {
                list.add("BAD_INTERVAL_WITH_U_APSD_COEX");
                flipped |= BAD_INTERVAL_WITH_U_APSD_COEX;
            }
            if ((o & ANTI_CLOGGING_TOKEN_REQ) == ANTI_CLOGGING_TOKEN_REQ) {
                list.add("ANTI_CLOGGING_TOKEN_REQ");
                flipped |= ANTI_CLOGGING_TOKEN_REQ;
            }
            if ((o & FINITE_CYCLIC_GROUP_NOT_SUPPORTED) == FINITE_CYCLIC_GROUP_NOT_SUPPORTED) {
                list.add("FINITE_CYCLIC_GROUP_NOT_SUPPORTED");
                flipped |= FINITE_CYCLIC_GROUP_NOT_SUPPORTED;
            }
            if ((o & CANNOT_FIND_ALT_TBTT) == CANNOT_FIND_ALT_TBTT) {
                list.add("CANNOT_FIND_ALT_TBTT");
                flipped |= CANNOT_FIND_ALT_TBTT;
            }
            if ((o & TRANSMISSION_FAILURE) == TRANSMISSION_FAILURE) {
                list.add("TRANSMISSION_FAILURE");
                flipped |= TRANSMISSION_FAILURE;
            }
            if ((o & REQ_TCLAS_NOT_SUPPORTED) == REQ_TCLAS_NOT_SUPPORTED) {
                list.add("REQ_TCLAS_NOT_SUPPORTED");
                flipped |= REQ_TCLAS_NOT_SUPPORTED;
            }
            if ((o & TCLAS_RESOURCES_EXCHAUSTED) == TCLAS_RESOURCES_EXCHAUSTED) {
                list.add("TCLAS_RESOURCES_EXCHAUSTED");
                flipped |= TCLAS_RESOURCES_EXCHAUSTED;
            }
            if ((o & REJECTED_WITH_SUGGESTED_BSS_TRANSITION) == REJECTED_WITH_SUGGESTED_BSS_TRANSITION) {
                list.add("REJECTED_WITH_SUGGESTED_BSS_TRANSITION");
                flipped |= REJECTED_WITH_SUGGESTED_BSS_TRANSITION;
            }
            if ((o & REJECT_WITH_SCHEDULE) == REJECT_WITH_SCHEDULE) {
                list.add("REJECT_WITH_SCHEDULE");
                flipped |= REJECT_WITH_SCHEDULE;
            }
            if ((o & REJECT_NO_WAKEUP_SPECIFIED) == REJECT_NO_WAKEUP_SPECIFIED) {
                list.add("REJECT_NO_WAKEUP_SPECIFIED");
                flipped |= REJECT_NO_WAKEUP_SPECIFIED;
            }
            if ((o & SUCCESS_POWER_SAVE_MODE) == SUCCESS_POWER_SAVE_MODE) {
                list.add("SUCCESS_POWER_SAVE_MODE");
                flipped |= SUCCESS_POWER_SAVE_MODE;
            }
            if ((o & PENDING_ADMITTING_FST_SESSION) == PENDING_ADMITTING_FST_SESSION) {
                list.add("PENDING_ADMITTING_FST_SESSION");
                flipped |= PENDING_ADMITTING_FST_SESSION;
            }
            if ((o & PERFORMING_FST_NOW) == PERFORMING_FST_NOW) {
                list.add("PERFORMING_FST_NOW");
                flipped |= PERFORMING_FST_NOW;
            }
            if ((o & PENDING_GAP_IN_BA_WINDOW) == PENDING_GAP_IN_BA_WINDOW) {
                list.add("PENDING_GAP_IN_BA_WINDOW");
                flipped |= PENDING_GAP_IN_BA_WINDOW;
            }
            if ((o & REJECT_U_PID_SETTING) == REJECT_U_PID_SETTING) {
                list.add("REJECT_U_PID_SETTING");
                flipped |= REJECT_U_PID_SETTING;
            }
            if ((o & REFUSED_EXTERNAL_REASON) == REFUSED_EXTERNAL_REASON) {
                list.add("REFUSED_EXTERNAL_REASON");
                flipped |= REFUSED_EXTERNAL_REASON;
            }
            if ((o & REFUSED_AP_OUT_OF_MEMORY) == REFUSED_AP_OUT_OF_MEMORY) {
                list.add("REFUSED_AP_OUT_OF_MEMORY");
                flipped |= REFUSED_AP_OUT_OF_MEMORY;
            }
            if ((o & REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED) == REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED) {
                list.add("REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED");
                flipped |= REJECTED_EMERGENCY_SERVICE_NOT_SUPPORTED;
            }
            if ((o & QUERY_RESP_OUTSTANDING) == QUERY_RESP_OUTSTANDING) {
                list.add("QUERY_RESP_OUTSTANDING");
                flipped |= QUERY_RESP_OUTSTANDING;
            }
            if ((o & REJECT_DSE_BAND) == REJECT_DSE_BAND) {
                list.add("REJECT_DSE_BAND");
                flipped |= REJECT_DSE_BAND;
            }
            if ((o & TCLAS_PROCESSING_TERMINATED) == TCLAS_PROCESSING_TERMINATED) {
                list.add("TCLAS_PROCESSING_TERMINATED");
                flipped |= TCLAS_PROCESSING_TERMINATED;
            }
            if ((o & TS_SCHEDULE_CONFLICT) == TS_SCHEDULE_CONFLICT) {
                list.add("TS_SCHEDULE_CONFLICT");
                flipped |= TS_SCHEDULE_CONFLICT;
            }
            if ((o & DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL) == DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL) {
                list.add("DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL");
                flipped |= DENIED_WITH_SUGGESTED_BAND_AND_CHANNEL;
            }
            if ((o & MCCAOP_RESERVATION_CONFLICT) == MCCAOP_RESERVATION_CONFLICT) {
                list.add("MCCAOP_RESERVATION_CONFLICT");
                flipped |= MCCAOP_RESERVATION_CONFLICT;
            }
            if ((o & MAF_LIMIT_EXCEEDED) == MAF_LIMIT_EXCEEDED) {
                list.add("MAF_LIMIT_EXCEEDED");
                flipped |= MAF_LIMIT_EXCEEDED;
            }
            if ((o & MCCA_TRACK_LIMIT_EXCEEDED) == MCCA_TRACK_LIMIT_EXCEEDED) {
                list.add("MCCA_TRACK_LIMIT_EXCEEDED");
                flipped |= MCCA_TRACK_LIMIT_EXCEEDED;
            }
            if ((o & DENIED_DUE_TO_SPECTRUM_MANAGEMENT) == DENIED_DUE_TO_SPECTRUM_MANAGEMENT) {
                list.add("DENIED_DUE_TO_SPECTRUM_MANAGEMENT");
                flipped |= DENIED_DUE_TO_SPECTRUM_MANAGEMENT;
            }
            if ((o & ASSOC_DENIED_NO_VHT) == ASSOC_DENIED_NO_VHT) {
                list.add("ASSOC_DENIED_NO_VHT");
                flipped |= ASSOC_DENIED_NO_VHT;
            }
            if ((o & ENABLEMENT_DENIED) == ENABLEMENT_DENIED) {
                list.add("ENABLEMENT_DENIED");
                flipped |= ENABLEMENT_DENIED;
            }
            if ((o & RESTRICTION_FROM_AUTHORIZED_GDB) == RESTRICTION_FROM_AUTHORIZED_GDB) {
                list.add("RESTRICTION_FROM_AUTHORIZED_GDB");
                flipped |= RESTRICTION_FROM_AUTHORIZED_GDB;
            }
            if ((o & AUTHORIZATION_DEENABLED) == AUTHORIZATION_DEENABLED) {
                list.add("AUTHORIZATION_DEENABLED");
                flipped |= AUTHORIZATION_DEENABLED;
            }
            if ((o & FILS_AUTHENTICATION_FAILURE) == FILS_AUTHENTICATION_FAILURE) {
                list.add("FILS_AUTHENTICATION_FAILURE");
                flipped |= FILS_AUTHENTICATION_FAILURE;
            }
            if ((o & UNKNOWN_AUTHENTICATION_SERVER) == UNKNOWN_AUTHENTICATION_SERVER) {
                list.add("UNKNOWN_AUTHENTICATION_SERVER");
                flipped |= UNKNOWN_AUTHENTICATION_SERVER;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Reason codes (IEEE Std 802.11-2016, 9.4.1.7, Table 9-45).
     */
    public static final class ReasonCode {
        public static final int UNSPECIFIED = 1;
        public static final int PREV_AUTH_NOT_VALID = 2;
        public static final int DEAUTH_LEAVING = 3;
        public static final int DISASSOC_DUE_TO_INACTIVITY = 4;
        public static final int DISASSOC_AP_BUSY = 5;
        public static final int CLASS2_FRAME_FROM_NONAUTH_STA = 6;
        public static final int CLASS3_FRAME_FROM_NONASSOC_STA = 7;
        public static final int DISASSOC_STA_HAS_LEFT = 8;
        public static final int STA_REQ_ASSOC_WITHOUT_AUTH = 9;
        public static final int PWR_CAPABILITY_NOT_VALID = 10;
        public static final int SUPPORTED_CHANNEL_NOT_VALID = 11;
        public static final int BSS_TRANSITION_DISASSOC = 12;
        public static final int INVALID_IE = 13;
        public static final int MICHAEL_MIC_FAILURE = 14;
        public static final int FOURWAY_HANDSHAKE_TIMEOUT = 15;
        public static final int GROUP_KEY_UPDATE_TIMEOUT = 16;
        public static final int IE_IN_4WAY_DIFFERS = 17;
        public static final int GROUP_CIPHER_NOT_VALID = 18;
        public static final int PAIRWISE_CIPHER_NOT_VALID = 19;
        public static final int AKMP_NOT_VALID = 20;
        public static final int UNSUPPORTED_RSN_IE_VERSION = 21;
        public static final int INVALID_RSN_IE_CAPAB = 22;
        public static final int IEEE_802_1X_AUTH_FAILED = 23;
        public static final int CIPHER_SUITE_REJECTED = 24;
        public static final int TDLS_TEARDOWN_UNREACHABLE = 25;
        public static final int TDLS_TEARDOWN_UNSPECIFIED = 26;
        public static final int SSP_REQUESTED_DISASSOC = 27;
        public static final int NO_SSP_ROAMING_AGREEMENT = 28;
        public static final int BAD_CIPHER_OR_AKM = 29;
        public static final int NOT_AUTHORIZED_THIS_LOCATION = 30;
        public static final int SERVICE_CHANGE_PRECLUDES_TS = 31;
        public static final int UNSPECIFIED_QOS_REASON = 32;
        public static final int NOT_ENOUGH_BANDWIDTH = 33;
        public static final int DISASSOC_LOW_ACK = 34;
        public static final int EXCEEDED_TXOP = 35;
        public static final int STA_LEAVING = 36;
        public static final int END_TS_BA_DLS = 37;
        public static final int UNKNOWN_TS_BA = 38;
        public static final int TIMEOUT = 39;
        public static final int PEERKEY_MISMATCH = 45;
        public static final int AUTHORIZED_ACCESS_LIMIT_REACHED = 46;
        public static final int EXTERNAL_SERVICE_REQUIREMENTS = 47;
        public static final int INVALID_FT_ACTION_FRAME_COUNT = 48;
        public static final int INVALID_PMKID = 49;
        public static final int INVALID_MDE = 50;
        public static final int INVALID_FTE = 51;
        public static final int MESH_PEERING_CANCELLED = 52;
        public static final int MESH_MAX_PEERS = 53;
        public static final int MESH_CONFIG_POLICY_VIOLATION = 54;
        public static final int MESH_CLOSE_RCVD = 55;
        public static final int MESH_MAX_RETRIES = 56;
        public static final int MESH_CONFIRM_TIMEOUT = 57;
        public static final int MESH_INVALID_GTK = 58;
        public static final int MESH_INCONSISTENT_PARAMS = 59;
        public static final int MESH_INVALID_SECURITY_CAP = 60;
        public static final int MESH_PATH_ERROR_NO_PROXY_INFO = 61;
        public static final int MESH_PATH_ERROR_NO_FORWARDING_INFO = 62;
        public static final int MESH_PATH_ERROR_DEST_UNREACHABLE = 63;
        public static final int MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS = 64;
        public static final int MESH_CHANNEL_SWITCH_REGULATORY_REQ = 65;
        public static final int MESH_CHANNEL_SWITCH_UNSPECIFIED = 66;
        public static final String toString(int o) {
            if (o == UNSPECIFIED) {
                return "UNSPECIFIED";
            }
            if (o == PREV_AUTH_NOT_VALID) {
                return "PREV_AUTH_NOT_VALID";
            }
            if (o == DEAUTH_LEAVING) {
                return "DEAUTH_LEAVING";
            }
            if (o == DISASSOC_DUE_TO_INACTIVITY) {
                return "DISASSOC_DUE_TO_INACTIVITY";
            }
            if (o == DISASSOC_AP_BUSY) {
                return "DISASSOC_AP_BUSY";
            }
            if (o == CLASS2_FRAME_FROM_NONAUTH_STA) {
                return "CLASS2_FRAME_FROM_NONAUTH_STA";
            }
            if (o == CLASS3_FRAME_FROM_NONASSOC_STA) {
                return "CLASS3_FRAME_FROM_NONASSOC_STA";
            }
            if (o == DISASSOC_STA_HAS_LEFT) {
                return "DISASSOC_STA_HAS_LEFT";
            }
            if (o == STA_REQ_ASSOC_WITHOUT_AUTH) {
                return "STA_REQ_ASSOC_WITHOUT_AUTH";
            }
            if (o == PWR_CAPABILITY_NOT_VALID) {
                return "PWR_CAPABILITY_NOT_VALID";
            }
            if (o == SUPPORTED_CHANNEL_NOT_VALID) {
                return "SUPPORTED_CHANNEL_NOT_VALID";
            }
            if (o == BSS_TRANSITION_DISASSOC) {
                return "BSS_TRANSITION_DISASSOC";
            }
            if (o == INVALID_IE) {
                return "INVALID_IE";
            }
            if (o == MICHAEL_MIC_FAILURE) {
                return "MICHAEL_MIC_FAILURE";
            }
            if (o == FOURWAY_HANDSHAKE_TIMEOUT) {
                return "FOURWAY_HANDSHAKE_TIMEOUT";
            }
            if (o == GROUP_KEY_UPDATE_TIMEOUT) {
                return "GROUP_KEY_UPDATE_TIMEOUT";
            }
            if (o == IE_IN_4WAY_DIFFERS) {
                return "IE_IN_4WAY_DIFFERS";
            }
            if (o == GROUP_CIPHER_NOT_VALID) {
                return "GROUP_CIPHER_NOT_VALID";
            }
            if (o == PAIRWISE_CIPHER_NOT_VALID) {
                return "PAIRWISE_CIPHER_NOT_VALID";
            }
            if (o == AKMP_NOT_VALID) {
                return "AKMP_NOT_VALID";
            }
            if (o == UNSUPPORTED_RSN_IE_VERSION) {
                return "UNSUPPORTED_RSN_IE_VERSION";
            }
            if (o == INVALID_RSN_IE_CAPAB) {
                return "INVALID_RSN_IE_CAPAB";
            }
            if (o == IEEE_802_1X_AUTH_FAILED) {
                return "IEEE_802_1X_AUTH_FAILED";
            }
            if (o == CIPHER_SUITE_REJECTED) {
                return "CIPHER_SUITE_REJECTED";
            }
            if (o == TDLS_TEARDOWN_UNREACHABLE) {
                return "TDLS_TEARDOWN_UNREACHABLE";
            }
            if (o == TDLS_TEARDOWN_UNSPECIFIED) {
                return "TDLS_TEARDOWN_UNSPECIFIED";
            }
            if (o == SSP_REQUESTED_DISASSOC) {
                return "SSP_REQUESTED_DISASSOC";
            }
            if (o == NO_SSP_ROAMING_AGREEMENT) {
                return "NO_SSP_ROAMING_AGREEMENT";
            }
            if (o == BAD_CIPHER_OR_AKM) {
                return "BAD_CIPHER_OR_AKM";
            }
            if (o == NOT_AUTHORIZED_THIS_LOCATION) {
                return "NOT_AUTHORIZED_THIS_LOCATION";
            }
            if (o == SERVICE_CHANGE_PRECLUDES_TS) {
                return "SERVICE_CHANGE_PRECLUDES_TS";
            }
            if (o == UNSPECIFIED_QOS_REASON) {
                return "UNSPECIFIED_QOS_REASON";
            }
            if (o == NOT_ENOUGH_BANDWIDTH) {
                return "NOT_ENOUGH_BANDWIDTH";
            }
            if (o == DISASSOC_LOW_ACK) {
                return "DISASSOC_LOW_ACK";
            }
            if (o == EXCEEDED_TXOP) {
                return "EXCEEDED_TXOP";
            }
            if (o == STA_LEAVING) {
                return "STA_LEAVING";
            }
            if (o == END_TS_BA_DLS) {
                return "END_TS_BA_DLS";
            }
            if (o == UNKNOWN_TS_BA) {
                return "UNKNOWN_TS_BA";
            }
            if (o == TIMEOUT) {
                return "TIMEOUT";
            }
            if (o == PEERKEY_MISMATCH) {
                return "PEERKEY_MISMATCH";
            }
            if (o == AUTHORIZED_ACCESS_LIMIT_REACHED) {
                return "AUTHORIZED_ACCESS_LIMIT_REACHED";
            }
            if (o == EXTERNAL_SERVICE_REQUIREMENTS) {
                return "EXTERNAL_SERVICE_REQUIREMENTS";
            }
            if (o == INVALID_FT_ACTION_FRAME_COUNT) {
                return "INVALID_FT_ACTION_FRAME_COUNT";
            }
            if (o == INVALID_PMKID) {
                return "INVALID_PMKID";
            }
            if (o == INVALID_MDE) {
                return "INVALID_MDE";
            }
            if (o == INVALID_FTE) {
                return "INVALID_FTE";
            }
            if (o == MESH_PEERING_CANCELLED) {
                return "MESH_PEERING_CANCELLED";
            }
            if (o == MESH_MAX_PEERS) {
                return "MESH_MAX_PEERS";
            }
            if (o == MESH_CONFIG_POLICY_VIOLATION) {
                return "MESH_CONFIG_POLICY_VIOLATION";
            }
            if (o == MESH_CLOSE_RCVD) {
                return "MESH_CLOSE_RCVD";
            }
            if (o == MESH_MAX_RETRIES) {
                return "MESH_MAX_RETRIES";
            }
            if (o == MESH_CONFIRM_TIMEOUT) {
                return "MESH_CONFIRM_TIMEOUT";
            }
            if (o == MESH_INVALID_GTK) {
                return "MESH_INVALID_GTK";
            }
            if (o == MESH_INCONSISTENT_PARAMS) {
                return "MESH_INCONSISTENT_PARAMS";
            }
            if (o == MESH_INVALID_SECURITY_CAP) {
                return "MESH_INVALID_SECURITY_CAP";
            }
            if (o == MESH_PATH_ERROR_NO_PROXY_INFO) {
                return "MESH_PATH_ERROR_NO_PROXY_INFO";
            }
            if (o == MESH_PATH_ERROR_NO_FORWARDING_INFO) {
                return "MESH_PATH_ERROR_NO_FORWARDING_INFO";
            }
            if (o == MESH_PATH_ERROR_DEST_UNREACHABLE) {
                return "MESH_PATH_ERROR_DEST_UNREACHABLE";
            }
            if (o == MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS) {
                return "MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS";
            }
            if (o == MESH_CHANNEL_SWITCH_REGULATORY_REQ) {
                return "MESH_CHANNEL_SWITCH_REGULATORY_REQ";
            }
            if (o == MESH_CHANNEL_SWITCH_UNSPECIFIED) {
                return "MESH_CHANNEL_SWITCH_UNSPECIFIED";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & UNSPECIFIED) == UNSPECIFIED) {
                list.add("UNSPECIFIED");
                flipped |= UNSPECIFIED;
            }
            if ((o & PREV_AUTH_NOT_VALID) == PREV_AUTH_NOT_VALID) {
                list.add("PREV_AUTH_NOT_VALID");
                flipped |= PREV_AUTH_NOT_VALID;
            }
            if ((o & DEAUTH_LEAVING) == DEAUTH_LEAVING) {
                list.add("DEAUTH_LEAVING");
                flipped |= DEAUTH_LEAVING;
            }
            if ((o & DISASSOC_DUE_TO_INACTIVITY) == DISASSOC_DUE_TO_INACTIVITY) {
                list.add("DISASSOC_DUE_TO_INACTIVITY");
                flipped |= DISASSOC_DUE_TO_INACTIVITY;
            }
            if ((o & DISASSOC_AP_BUSY) == DISASSOC_AP_BUSY) {
                list.add("DISASSOC_AP_BUSY");
                flipped |= DISASSOC_AP_BUSY;
            }
            if ((o & CLASS2_FRAME_FROM_NONAUTH_STA) == CLASS2_FRAME_FROM_NONAUTH_STA) {
                list.add("CLASS2_FRAME_FROM_NONAUTH_STA");
                flipped |= CLASS2_FRAME_FROM_NONAUTH_STA;
            }
            if ((o & CLASS3_FRAME_FROM_NONASSOC_STA) == CLASS3_FRAME_FROM_NONASSOC_STA) {
                list.add("CLASS3_FRAME_FROM_NONASSOC_STA");
                flipped |= CLASS3_FRAME_FROM_NONASSOC_STA;
            }
            if ((o & DISASSOC_STA_HAS_LEFT) == DISASSOC_STA_HAS_LEFT) {
                list.add("DISASSOC_STA_HAS_LEFT");
                flipped |= DISASSOC_STA_HAS_LEFT;
            }
            if ((o & STA_REQ_ASSOC_WITHOUT_AUTH) == STA_REQ_ASSOC_WITHOUT_AUTH) {
                list.add("STA_REQ_ASSOC_WITHOUT_AUTH");
                flipped |= STA_REQ_ASSOC_WITHOUT_AUTH;
            }
            if ((o & PWR_CAPABILITY_NOT_VALID) == PWR_CAPABILITY_NOT_VALID) {
                list.add("PWR_CAPABILITY_NOT_VALID");
                flipped |= PWR_CAPABILITY_NOT_VALID;
            }
            if ((o & SUPPORTED_CHANNEL_NOT_VALID) == SUPPORTED_CHANNEL_NOT_VALID) {
                list.add("SUPPORTED_CHANNEL_NOT_VALID");
                flipped |= SUPPORTED_CHANNEL_NOT_VALID;
            }
            if ((o & BSS_TRANSITION_DISASSOC) == BSS_TRANSITION_DISASSOC) {
                list.add("BSS_TRANSITION_DISASSOC");
                flipped |= BSS_TRANSITION_DISASSOC;
            }
            if ((o & INVALID_IE) == INVALID_IE) {
                list.add("INVALID_IE");
                flipped |= INVALID_IE;
            }
            if ((o & MICHAEL_MIC_FAILURE) == MICHAEL_MIC_FAILURE) {
                list.add("MICHAEL_MIC_FAILURE");
                flipped |= MICHAEL_MIC_FAILURE;
            }
            if ((o & FOURWAY_HANDSHAKE_TIMEOUT) == FOURWAY_HANDSHAKE_TIMEOUT) {
                list.add("FOURWAY_HANDSHAKE_TIMEOUT");
                flipped |= FOURWAY_HANDSHAKE_TIMEOUT;
            }
            if ((o & GROUP_KEY_UPDATE_TIMEOUT) == GROUP_KEY_UPDATE_TIMEOUT) {
                list.add("GROUP_KEY_UPDATE_TIMEOUT");
                flipped |= GROUP_KEY_UPDATE_TIMEOUT;
            }
            if ((o & IE_IN_4WAY_DIFFERS) == IE_IN_4WAY_DIFFERS) {
                list.add("IE_IN_4WAY_DIFFERS");
                flipped |= IE_IN_4WAY_DIFFERS;
            }
            if ((o & GROUP_CIPHER_NOT_VALID) == GROUP_CIPHER_NOT_VALID) {
                list.add("GROUP_CIPHER_NOT_VALID");
                flipped |= GROUP_CIPHER_NOT_VALID;
            }
            if ((o & PAIRWISE_CIPHER_NOT_VALID) == PAIRWISE_CIPHER_NOT_VALID) {
                list.add("PAIRWISE_CIPHER_NOT_VALID");
                flipped |= PAIRWISE_CIPHER_NOT_VALID;
            }
            if ((o & AKMP_NOT_VALID) == AKMP_NOT_VALID) {
                list.add("AKMP_NOT_VALID");
                flipped |= AKMP_NOT_VALID;
            }
            if ((o & UNSUPPORTED_RSN_IE_VERSION) == UNSUPPORTED_RSN_IE_VERSION) {
                list.add("UNSUPPORTED_RSN_IE_VERSION");
                flipped |= UNSUPPORTED_RSN_IE_VERSION;
            }
            if ((o & INVALID_RSN_IE_CAPAB) == INVALID_RSN_IE_CAPAB) {
                list.add("INVALID_RSN_IE_CAPAB");
                flipped |= INVALID_RSN_IE_CAPAB;
            }
            if ((o & IEEE_802_1X_AUTH_FAILED) == IEEE_802_1X_AUTH_FAILED) {
                list.add("IEEE_802_1X_AUTH_FAILED");
                flipped |= IEEE_802_1X_AUTH_FAILED;
            }
            if ((o & CIPHER_SUITE_REJECTED) == CIPHER_SUITE_REJECTED) {
                list.add("CIPHER_SUITE_REJECTED");
                flipped |= CIPHER_SUITE_REJECTED;
            }
            if ((o & TDLS_TEARDOWN_UNREACHABLE) == TDLS_TEARDOWN_UNREACHABLE) {
                list.add("TDLS_TEARDOWN_UNREACHABLE");
                flipped |= TDLS_TEARDOWN_UNREACHABLE;
            }
            if ((o & TDLS_TEARDOWN_UNSPECIFIED) == TDLS_TEARDOWN_UNSPECIFIED) {
                list.add("TDLS_TEARDOWN_UNSPECIFIED");
                flipped |= TDLS_TEARDOWN_UNSPECIFIED;
            }
            if ((o & SSP_REQUESTED_DISASSOC) == SSP_REQUESTED_DISASSOC) {
                list.add("SSP_REQUESTED_DISASSOC");
                flipped |= SSP_REQUESTED_DISASSOC;
            }
            if ((o & NO_SSP_ROAMING_AGREEMENT) == NO_SSP_ROAMING_AGREEMENT) {
                list.add("NO_SSP_ROAMING_AGREEMENT");
                flipped |= NO_SSP_ROAMING_AGREEMENT;
            }
            if ((o & BAD_CIPHER_OR_AKM) == BAD_CIPHER_OR_AKM) {
                list.add("BAD_CIPHER_OR_AKM");
                flipped |= BAD_CIPHER_OR_AKM;
            }
            if ((o & NOT_AUTHORIZED_THIS_LOCATION) == NOT_AUTHORIZED_THIS_LOCATION) {
                list.add("NOT_AUTHORIZED_THIS_LOCATION");
                flipped |= NOT_AUTHORIZED_THIS_LOCATION;
            }
            if ((o & SERVICE_CHANGE_PRECLUDES_TS) == SERVICE_CHANGE_PRECLUDES_TS) {
                list.add("SERVICE_CHANGE_PRECLUDES_TS");
                flipped |= SERVICE_CHANGE_PRECLUDES_TS;
            }
            if ((o & UNSPECIFIED_QOS_REASON) == UNSPECIFIED_QOS_REASON) {
                list.add("UNSPECIFIED_QOS_REASON");
                flipped |= UNSPECIFIED_QOS_REASON;
            }
            if ((o & NOT_ENOUGH_BANDWIDTH) == NOT_ENOUGH_BANDWIDTH) {
                list.add("NOT_ENOUGH_BANDWIDTH");
                flipped |= NOT_ENOUGH_BANDWIDTH;
            }
            if ((o & DISASSOC_LOW_ACK) == DISASSOC_LOW_ACK) {
                list.add("DISASSOC_LOW_ACK");
                flipped |= DISASSOC_LOW_ACK;
            }
            if ((o & EXCEEDED_TXOP) == EXCEEDED_TXOP) {
                list.add("EXCEEDED_TXOP");
                flipped |= EXCEEDED_TXOP;
            }
            if ((o & STA_LEAVING) == STA_LEAVING) {
                list.add("STA_LEAVING");
                flipped |= STA_LEAVING;
            }
            if ((o & END_TS_BA_DLS) == END_TS_BA_DLS) {
                list.add("END_TS_BA_DLS");
                flipped |= END_TS_BA_DLS;
            }
            if ((o & UNKNOWN_TS_BA) == UNKNOWN_TS_BA) {
                list.add("UNKNOWN_TS_BA");
                flipped |= UNKNOWN_TS_BA;
            }
            if ((o & TIMEOUT) == TIMEOUT) {
                list.add("TIMEOUT");
                flipped |= TIMEOUT;
            }
            if ((o & PEERKEY_MISMATCH) == PEERKEY_MISMATCH) {
                list.add("PEERKEY_MISMATCH");
                flipped |= PEERKEY_MISMATCH;
            }
            if ((o & AUTHORIZED_ACCESS_LIMIT_REACHED) == AUTHORIZED_ACCESS_LIMIT_REACHED) {
                list.add("AUTHORIZED_ACCESS_LIMIT_REACHED");
                flipped |= AUTHORIZED_ACCESS_LIMIT_REACHED;
            }
            if ((o & EXTERNAL_SERVICE_REQUIREMENTS) == EXTERNAL_SERVICE_REQUIREMENTS) {
                list.add("EXTERNAL_SERVICE_REQUIREMENTS");
                flipped |= EXTERNAL_SERVICE_REQUIREMENTS;
            }
            if ((o & INVALID_FT_ACTION_FRAME_COUNT) == INVALID_FT_ACTION_FRAME_COUNT) {
                list.add("INVALID_FT_ACTION_FRAME_COUNT");
                flipped |= INVALID_FT_ACTION_FRAME_COUNT;
            }
            if ((o & INVALID_PMKID) == INVALID_PMKID) {
                list.add("INVALID_PMKID");
                flipped |= INVALID_PMKID;
            }
            if ((o & INVALID_MDE) == INVALID_MDE) {
                list.add("INVALID_MDE");
                flipped |= INVALID_MDE;
            }
            if ((o & INVALID_FTE) == INVALID_FTE) {
                list.add("INVALID_FTE");
                flipped |= INVALID_FTE;
            }
            if ((o & MESH_PEERING_CANCELLED) == MESH_PEERING_CANCELLED) {
                list.add("MESH_PEERING_CANCELLED");
                flipped |= MESH_PEERING_CANCELLED;
            }
            if ((o & MESH_MAX_PEERS) == MESH_MAX_PEERS) {
                list.add("MESH_MAX_PEERS");
                flipped |= MESH_MAX_PEERS;
            }
            if ((o & MESH_CONFIG_POLICY_VIOLATION) == MESH_CONFIG_POLICY_VIOLATION) {
                list.add("MESH_CONFIG_POLICY_VIOLATION");
                flipped |= MESH_CONFIG_POLICY_VIOLATION;
            }
            if ((o & MESH_CLOSE_RCVD) == MESH_CLOSE_RCVD) {
                list.add("MESH_CLOSE_RCVD");
                flipped |= MESH_CLOSE_RCVD;
            }
            if ((o & MESH_MAX_RETRIES) == MESH_MAX_RETRIES) {
                list.add("MESH_MAX_RETRIES");
                flipped |= MESH_MAX_RETRIES;
            }
            if ((o & MESH_CONFIRM_TIMEOUT) == MESH_CONFIRM_TIMEOUT) {
                list.add("MESH_CONFIRM_TIMEOUT");
                flipped |= MESH_CONFIRM_TIMEOUT;
            }
            if ((o & MESH_INVALID_GTK) == MESH_INVALID_GTK) {
                list.add("MESH_INVALID_GTK");
                flipped |= MESH_INVALID_GTK;
            }
            if ((o & MESH_INCONSISTENT_PARAMS) == MESH_INCONSISTENT_PARAMS) {
                list.add("MESH_INCONSISTENT_PARAMS");
                flipped |= MESH_INCONSISTENT_PARAMS;
            }
            if ((o & MESH_INVALID_SECURITY_CAP) == MESH_INVALID_SECURITY_CAP) {
                list.add("MESH_INVALID_SECURITY_CAP");
                flipped |= MESH_INVALID_SECURITY_CAP;
            }
            if ((o & MESH_PATH_ERROR_NO_PROXY_INFO) == MESH_PATH_ERROR_NO_PROXY_INFO) {
                list.add("MESH_PATH_ERROR_NO_PROXY_INFO");
                flipped |= MESH_PATH_ERROR_NO_PROXY_INFO;
            }
            if ((o & MESH_PATH_ERROR_NO_FORWARDING_INFO) == MESH_PATH_ERROR_NO_FORWARDING_INFO) {
                list.add("MESH_PATH_ERROR_NO_FORWARDING_INFO");
                flipped |= MESH_PATH_ERROR_NO_FORWARDING_INFO;
            }
            if ((o & MESH_PATH_ERROR_DEST_UNREACHABLE) == MESH_PATH_ERROR_DEST_UNREACHABLE) {
                list.add("MESH_PATH_ERROR_DEST_UNREACHABLE");
                flipped |= MESH_PATH_ERROR_DEST_UNREACHABLE;
            }
            if ((o & MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS) == MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS) {
                list.add("MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS");
                flipped |= MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS;
            }
            if ((o & MESH_CHANNEL_SWITCH_REGULATORY_REQ) == MESH_CHANNEL_SWITCH_REGULATORY_REQ) {
                list.add("MESH_CHANNEL_SWITCH_REGULATORY_REQ");
                flipped |= MESH_CHANNEL_SWITCH_REGULATORY_REQ;
            }
            if ((o & MESH_CHANNEL_SWITCH_UNSPECIFIED) == MESH_CHANNEL_SWITCH_UNSPECIFIED) {
                list.add("MESH_CHANNEL_SWITCH_UNSPECIFIED");
                flipped |= MESH_CHANNEL_SWITCH_UNSPECIFIED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * BSSID change Reasons.
     */
    public static final class BssidChangeReason {
        /**
         * Started association with new bssid.
         */
        public static final byte ASSOC_START = 0;
        /**
         * Completed association with new bssid.
         */
        public static final byte ASSOC_COMPLETE = 1;
        /**
         * Dis-association with current bssid.
         */
        public static final byte DISASSOC = 2;
        public static final String toString(byte o) {
            if (o == ASSOC_START) {
                return "ASSOC_START";
            }
            if (o == ASSOC_COMPLETE) {
                return "ASSOC_COMPLETE";
            }
            if (o == DISASSOC) {
                return "DISASSOC";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("ASSOC_START"); // ASSOC_START == 0
            if ((o & ASSOC_COMPLETE) == ASSOC_COMPLETE) {
                list.add("ASSOC_COMPLETE");
                flipped |= ASSOC_COMPLETE;
            }
            if ((o & DISASSOC) == DISASSOC) {
                list.add("DISASSOC");
                flipped |= DISASSOC;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Used to indicate that a new network has been added.
     *
     * @param id Network ID allocated to the corresponding network.
     */
    void onNetworkAdded(int id)
        throws android.os.RemoteException;
    /**
     * Used to indicate that a network has been removed.
     *
     * @param id Network ID allocated to the corresponding network.
     */
    void onNetworkRemoved(int id)
        throws android.os.RemoteException;
    /**
     * Used to indicate a state change event on this particular iface. If this
     * event is triggered by a particular network, the |SupplicantNetworkId|,
     * |ssid|, |bssid| parameters must indicate the parameters of the network/AP
     * which cased this state transition.
     *
     * @param newState New State of the interface. This must be one of the |State|
     *        values above.
     * @param bssid BSSID of the corresponding AP which caused this state
     *        change event. This must be zero'ed if this event is not
     *        specific to a particular network.
     * @param id ID of the corresponding network which caused this
     *        state change event. This must be invalid (UINT32_MAX) if this
     *        event is not specific to a particular network.
     * @param ssid SSID of the corresponding network which caused this state
     *        change event. This must be empty if this event is not specific
     *        to a particular network.
     */
    void onStateChanged(int newState, byte[/* 6 */] bssid, int id, java.util.ArrayList<Byte> ssid)
        throws android.os.RemoteException;
    /**
     * Used to indicate the result of ANQP (either for IEEE 802.11u Interworking
     * or Hotspot 2.0) query.
     *
     * @param bssid BSSID of the access point.
     * @param data ANQP data fetched from the access point.
     *        All the fields in this struct must be empty if the query failed.
     * @param hs20Data ANQP data fetched from the Hotspot 2.0 access point.
     *        All the fields in this struct must be empty if the query failed.
     */
    void onAnqpQueryDone(byte[/* 6 */] bssid, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData data, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData hs20Data)
        throws android.os.RemoteException;
    /**
     * Used to indicate the result of Hotspot 2.0 Icon query.
     *
     * @param bssid BSSID of the access point.
     * @param fileName Name of the file that was requested.
     * @param data Icon data fetched from the access point.
     *        Must be empty if the query failed.
     */
    void onHs20IconQueryDone(byte[/* 6 */] bssid, String fileName, java.util.ArrayList<Byte> data)
        throws android.os.RemoteException;
    /**
     * Used to indicate a Hotspot 2.0 subscription remediation event.
     *
     * @param bssid BSSID of the access point.
     * @param osuMethod OSU method.
     * @param url URL of the server.
     */
    void onHs20SubscriptionRemediation(byte[/* 6 */] bssid, byte osuMethod, String url)
        throws android.os.RemoteException;
    /**
     * Used to indicate a Hotspot 2.0 imminent deauth notice.
     *
     * @param bssid BSSID of the access point.
     * @param reasonCode Code to indicate the deauth reason.
     *        Refer to section 3.2.1.2 of the Hotspot 2.0 spec.
     * @param reAuthDelayInSec Delay before reauthenticating.
     * @param url URL of the server.
     */
    void onHs20DeauthImminentNotice(byte[/* 6 */] bssid, int reasonCode, int reAuthDelayInSec, String url)
        throws android.os.RemoteException;
    /**
     * Used to indicate the disconnection from the currently connected
     * network on this iface.
     *
     * @param bssid BSSID of the AP from which we disconnected.
     * @param locallyGenerated If the disconnect was triggered by
     *        wpa_supplicant.
     * @param reasonCode 802.11 code to indicate the disconnect reason
     *        from access point. Refer to section 8.4.1.7 of IEEE802.11 spec.
     */
    void onDisconnected(byte[/* 6 */] bssid, boolean locallyGenerated, int reasonCode)
        throws android.os.RemoteException;
    /**
     * Used to indicate an association rejection recieved from the AP
     * to which the connection is being attempted.
     *
     * @param bssid BSSID of the corresponding AP which sent this
     *        reject.
     * @param statusCode 802.11 code to indicate the reject reason.
     *        Refer to section 8.4.1.9 of IEEE 802.11 spec.
     * @param timedOut Whether failure is due to timeout rather
     *        than explicit rejection response from the AP.
     */
    void onAssociationRejected(byte[/* 6 */] bssid, int statusCode, boolean timedOut)
        throws android.os.RemoteException;
    /**
     * Used to indicate the timeout of authentication to an AP.
     *
     * @param bssid BSSID of the corresponding AP.
     */
    void onAuthenticationTimeout(byte[/* 6 */] bssid)
        throws android.os.RemoteException;
    /**
     * Used to indicate an EAP authentication failure.
     */
    void onEapFailure()
        throws android.os.RemoteException;
    /**
     * Used to indicate the change of active bssid.
     * This is useful to figure out when the driver/firmware roams to a bssid
     * on its own.
     *
     * @param reason Reason why the bssid changed.
     * @param bssid BSSID of the corresponding AP.
     */
    void onBssidChanged(byte reason, byte[/* 6 */] bssid)
        throws android.os.RemoteException;
    /**
     * Used to indicate the success of a WPS connection attempt.
     */
    void onWpsEventSuccess()
        throws android.os.RemoteException;
    /**
     * Used to indicate the failure of a WPS connection attempt.
     *
     * @param bssid BSSID of the AP to which we initiated WPS
     *        connection.
     * @param configError Configuration error code.
     * @param errorInd Error indication code.
     */
    void onWpsEventFail(byte[/* 6 */] bssid, short configError, short errorInd)
        throws android.os.RemoteException;
    /**
     * Used to indicate the overlap of a WPS PBC connection attempt.
     */
    void onWpsEventPbcOverlap()
        throws android.os.RemoteException;
    /**
     * Used to indicate that the external radio work can start now.
     *
     * @return id Identifier generated for the radio work request.
     */
    void onExtRadioWorkStart(int id)
        throws android.os.RemoteException;
    /**
     * Used to indicate that the external radio work request has timed out.
     *
     * @return id Identifier generated for the radio work request.
     */
    void onExtRadioWorkTimeout(int id)
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

    public static final class Proxy implements ISupplicantStaIfaceCallback {
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
            return "[class or subclass of " + ISupplicantStaIfaceCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback follow.
        @Override
        public void onNetworkAdded(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* onNetworkAdded */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onNetworkRemoved(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* onNetworkRemoved */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onStateChanged(int newState, byte[/* 6 */] bssid, int id, java.util.ArrayList<Byte> ssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(newState);
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
            _hidl_request.writeInt32(id);
            _hidl_request.writeInt8Vector(ssid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* onStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAnqpQueryDone(byte[/* 6 */] bssid, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData data, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData hs20Data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData) data).writeToParcel(_hidl_request);
            ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData) hs20Data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* onAnqpQueryDone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20IconQueryDone(byte[/* 6 */] bssid, String fileName, java.util.ArrayList<Byte> data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeString(fileName);
            _hidl_request.writeInt8Vector(data);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* onHs20IconQueryDone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20SubscriptionRemediation(byte[/* 6 */] bssid, byte osuMethod, String url)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeInt8(osuMethod);
            _hidl_request.writeString(url);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* onHs20SubscriptionRemediation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20DeauthImminentNotice(byte[/* 6 */] bssid, int reasonCode, int reAuthDelayInSec, String url)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeInt32(reasonCode);
            _hidl_request.writeInt32(reAuthDelayInSec);
            _hidl_request.writeString(url);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* onHs20DeauthImminentNotice */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDisconnected(byte[/* 6 */] bssid, boolean locallyGenerated, int reasonCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeBool(locallyGenerated);
            _hidl_request.writeInt32(reasonCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* onDisconnected */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAssociationRejected(byte[/* 6 */] bssid, int statusCode, boolean timedOut)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeInt32(statusCode);
            _hidl_request.writeBool(timedOut);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* onAssociationRejected */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAuthenticationTimeout(byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
                mRemote.transact(10 /* onAuthenticationTimeout */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onEapFailure()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* onEapFailure */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onBssidChanged(byte reason, byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt8(reason);
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
                mRemote.transact(12 /* onBssidChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventSuccess()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* onWpsEventSuccess */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventFail(byte[/* 6 */] bssid, short configError, short errorInd)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
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
            _hidl_request.writeInt16(configError);
            _hidl_request.writeInt16(errorInd);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* onWpsEventFail */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventPbcOverlap()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* onWpsEventPbcOverlap */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onExtRadioWorkStart(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* onExtRadioWorkStart */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onExtRadioWorkTimeout(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* onExtRadioWorkTimeout */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
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

    public static abstract class Stub extends android.os.HwBinder implements ISupplicantStaIfaceCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-41,-127,-56,-41,-25,-77,-2,92,-54,-116,-10,-31,-40,-128,110,119,9,-126,-82,83,88,-57,-127,110,-43,27,15,14,-62,114,-25,13} /* d781c8d7e7b3fe5cca8cf6e1d8806e770982ae5358c7816ed51b0f0ec272e70d */,
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
                case 1 /* onNetworkAdded */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onNetworkAdded(id);
                    break;
                }

                case 2 /* onNetworkRemoved */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onNetworkRemoved(id);
                    break;
                }

                case 3 /* onStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int newState = _hidl_request.readInt32();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int id = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> ssid = _hidl_request.readInt8Vector();
                    onStateChanged(newState, bssid, id, ssid);
                    break;
                }

                case 4 /* onAnqpQueryDone */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData data = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData) data).readFromParcel(_hidl_request);
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData hs20Data = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData) hs20Data).readFromParcel(_hidl_request);
                    onAnqpQueryDone(bssid, data, hs20Data);
                    break;
                }

                case 5 /* onHs20IconQueryDone */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    String fileName = _hidl_request.readString();
                    java.util.ArrayList<Byte> data = _hidl_request.readInt8Vector();
                    onHs20IconQueryDone(bssid, fileName, data);
                    break;
                }

                case 6 /* onHs20SubscriptionRemediation */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    byte osuMethod = _hidl_request.readInt8();
                    String url = _hidl_request.readString();
                    onHs20SubscriptionRemediation(bssid, osuMethod, url);
                    break;
                }

                case 7 /* onHs20DeauthImminentNotice */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int reasonCode = _hidl_request.readInt32();
                    int reAuthDelayInSec = _hidl_request.readInt32();
                    String url = _hidl_request.readString();
                    onHs20DeauthImminentNotice(bssid, reasonCode, reAuthDelayInSec, url);
                    break;
                }

                case 8 /* onDisconnected */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    boolean locallyGenerated = _hidl_request.readBool();
                    int reasonCode = _hidl_request.readInt32();
                    onDisconnected(bssid, locallyGenerated, reasonCode);
                    break;
                }

                case 9 /* onAssociationRejected */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int statusCode = _hidl_request.readInt32();
                    boolean timedOut = _hidl_request.readBool();
                    onAssociationRejected(bssid, statusCode, timedOut);
                    break;
                }

                case 10 /* onAuthenticationTimeout */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    onAuthenticationTimeout(bssid);
                    break;
                }

                case 11 /* onEapFailure */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onEapFailure();
                    break;
                }

                case 12 /* onBssidChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte reason = _hidl_request.readInt8();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    onBssidChanged(reason, bssid);
                    break;
                }

                case 13 /* onWpsEventSuccess */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onWpsEventSuccess();
                    break;
                }

                case 14 /* onWpsEventFail */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    short configError = _hidl_request.readInt16();
                    short errorInd = _hidl_request.readInt16();
                    onWpsEventFail(bssid, configError, errorInd);
                    break;
                }

                case 15 /* onWpsEventPbcOverlap */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onWpsEventPbcOverlap();
                    break;
                }

                case 16 /* onExtRadioWorkStart */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onExtRadioWorkStart(id);
                    break;
                }

                case 17 /* onExtRadioWorkTimeout */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onExtRadioWorkTimeout(id);
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
