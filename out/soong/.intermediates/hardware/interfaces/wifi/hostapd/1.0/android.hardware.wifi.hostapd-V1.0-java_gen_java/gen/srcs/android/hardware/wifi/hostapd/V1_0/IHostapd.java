package android.hardware.wifi.hostapd.V1_0;

/**
 * Top-level object for managing SoftAPs.
 */
public interface IHostapd extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.hostapd@1.0::IHostapd";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IHostapd asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IHostapd)) {
            return (IHostapd)iface;
        }

        IHostapd proxy = new IHostapd.Proxy(binder);

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
    public static IHostapd castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IHostapd.asInterface(iface.asBinder());
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
    public static IHostapd getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IHostapd.asInterface(android.os.HwBinder.getService("android.hardware.wifi.hostapd@1.0::IHostapd", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IHostapd getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IHostapd getService(String serviceName) throws android.os.RemoteException {
        return IHostapd.asInterface(android.os.HwBinder.getService("android.hardware.wifi.hostapd@1.0::IHostapd", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IHostapd getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Size limits for some of the params used in this interface.
     */
    public static final class ParamSizeLimits {
        /**
         * Max length of SSID param.
         */
        public static final int SSID_MAX_LEN_IN_BYTES = 32;
        /**
         * Min length of PSK passphrase param.
         */
        public static final int WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES = 8;
        /**
         * Max length of PSK passphrase param.
         */
        public static final int WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES = 63;
        public static final String toString(int o) {
            if (o == SSID_MAX_LEN_IN_BYTES) {
                return "SSID_MAX_LEN_IN_BYTES";
            }
            if (o == WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES) {
                return "WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES";
            }
            if (o == WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES) {
                return "WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & SSID_MAX_LEN_IN_BYTES) == SSID_MAX_LEN_IN_BYTES) {
                list.add("SSID_MAX_LEN_IN_BYTES");
                flipped |= SSID_MAX_LEN_IN_BYTES;
            }
            if ((o & WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES) == WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES) {
                list.add("WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES");
                flipped |= WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES;
            }
            if ((o & WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES) == WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES) {
                list.add("WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES");
                flipped |= WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Possble Security types.
     */
    public static final class EncryptionType {
        public static final int NONE = 0;
        public static final int WPA = 1 /* ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType.NONE implicitly + 1 */;
        public static final int WPA2 = 2 /* ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType.WPA implicitly + 1 */;
        public static final String toString(int o) {
            if (o == NONE) {
                return "NONE";
            }
            if (o == WPA) {
                return "WPA";
            }
            if (o == WPA2) {
                return "WPA2";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("NONE"); // NONE == 0
            if ((o & WPA) == WPA) {
                list.add("WPA");
                flipped |= WPA;
            }
            if ((o & WPA2) == WPA2) {
                list.add("WPA2");
                flipped |= WPA2;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Band to use for the SoftAp operations.
     * When using ACS, special value |BAND_ANY| can be
     * used to indicate that any supported band can be used. This special
     * case is currently supported only with drivers with which
     * offloaded ACS is used.
     */
    public static final class Band {
        public static final int BAND_2_4_GHZ = 0;
        public static final int BAND_5_GHZ = 1 /* ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band.BAND_2_4_GHZ implicitly + 1 */;
        public static final int BAND_ANY = 2 /* ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band.BAND_5_GHZ implicitly + 1 */;
        public static final String toString(int o) {
            if (o == BAND_2_4_GHZ) {
                return "BAND_2_4_GHZ";
            }
            if (o == BAND_5_GHZ) {
                return "BAND_5_GHZ";
            }
            if (o == BAND_ANY) {
                return "BAND_ANY";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("BAND_2_4_GHZ"); // BAND_2_4_GHZ == 0
            if ((o & BAND_5_GHZ) == BAND_5_GHZ) {
                list.add("BAND_5_GHZ");
                flipped |= BAND_5_GHZ;
            }
            if ((o & BAND_ANY) == BAND_ANY) {
                list.add("BAND_ANY");
                flipped |= BAND_ANY;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Parameters to control the HW mode for the interface.
     */
    public final static class HwModeParams {
        /**
         * Whether IEEE 802.11n (HT) is enabled or not.
         * Note: hwMode=G (2.4 GHz) and hwMode=A (5 GHz) is used to specify
         * the band.
         */
        public boolean enable80211N = false;
        /**
         * Whether IEEE 802.11ac (VHT) is enabled or not.
         * Note: hw_mode=a is used to specify that 5 GHz band is used with VHT.
         */
        public boolean enable80211AC = false;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams.class) {
                return false;
            }
            android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams other = (android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams)otherObject;
            if (this.enable80211N != other.enable80211N) {
                return false;
            }
            if (this.enable80211AC != other.enable80211AC) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.enable80211N), 
                    android.os.HidlSupport.deepHashCode(this.enable80211AC));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".enable80211N = ");
            builder.append(this.enable80211N);
            builder.append(", .enable80211AC = ");
            builder.append(this.enable80211AC);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(2 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<HwModeParams> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<HwModeParams> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 2,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams _hidl_vec_element = new android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 2);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            enable80211N = _hidl_blob.getBool(_hidl_offset + 0);
            enable80211AC = _hidl_blob.getBool(_hidl_offset + 1);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<HwModeParams> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 2));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 2);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putBool(_hidl_offset + 0, enable80211N);
            _hidl_blob.putBool(_hidl_offset + 1, enable80211AC);
        }
    };

    /**
     * Parameters to control the channel selection for the interface.
     */
    public final static class ChannelParams {
        /**
         * Whether to enable ACS (Automatic Channel Selection) or not.
         * The channel can be selected automatically at run time by setting
         * this flag, which must enable the ACS survey based algorithm.
         */
        public boolean enableAcs = false;
        /**
         * This option can be used to exclude all DFS channels from the ACS
         * channel list in cases where the driver supports DFS channels.
         */
        public boolean acsShouldExcludeDfs = false;
        /**
         * Channel number (IEEE 802.11) to use for the interface.
         * If ACS is enabled, this field is ignored.
         */
        public int channel = 0;
        /**
         * Band to use for the SoftAp operations.
         */
        public int band = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams.class) {
                return false;
            }
            android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams other = (android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams)otherObject;
            if (this.enableAcs != other.enableAcs) {
                return false;
            }
            if (this.acsShouldExcludeDfs != other.acsShouldExcludeDfs) {
                return false;
            }
            if (this.channel != other.channel) {
                return false;
            }
            if (this.band != other.band) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.enableAcs), 
                    android.os.HidlSupport.deepHashCode(this.acsShouldExcludeDfs), 
                    android.os.HidlSupport.deepHashCode(this.channel), 
                    android.os.HidlSupport.deepHashCode(this.band));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".enableAcs = ");
            builder.append(this.enableAcs);
            builder.append(", .acsShouldExcludeDfs = ");
            builder.append(this.acsShouldExcludeDfs);
            builder.append(", .channel = ");
            builder.append(this.channel);
            builder.append(", .band = ");
            builder.append(android.hardware.wifi.hostapd.V1_0.IHostapd.Band.toString(this.band));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<ChannelParams> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<ChannelParams> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 12,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams _hidl_vec_element = new android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            enableAcs = _hidl_blob.getBool(_hidl_offset + 0);
            acsShouldExcludeDfs = _hidl_blob.getBool(_hidl_offset + 1);
            channel = _hidl_blob.getInt32(_hidl_offset + 4);
            band = _hidl_blob.getInt32(_hidl_offset + 8);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<ChannelParams> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putBool(_hidl_offset + 0, enableAcs);
            _hidl_blob.putBool(_hidl_offset + 1, acsShouldExcludeDfs);
            _hidl_blob.putInt32(_hidl_offset + 4, channel);
            _hidl_blob.putInt32(_hidl_offset + 8, band);
        }
    };

    /**
     * Parameters to use for setting up the access point interface.
     */
    public final static class IfaceParams {
        /**
         * Name of the interface
         */
        public String ifaceName = new String();
        /**
         * Hw mode params for the interface
         */
        public android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams hwModeParams = new android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams();
        /**
         * Chanel params for the interface
         */
        public android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams channelParams = new android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams.class) {
                return false;
            }
            android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams other = (android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.ifaceName, other.ifaceName)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.hwModeParams, other.hwModeParams)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.channelParams, other.channelParams)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.ifaceName), 
                    android.os.HidlSupport.deepHashCode(this.hwModeParams), 
                    android.os.HidlSupport.deepHashCode(this.channelParams));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".ifaceName = ");
            builder.append(this.ifaceName);
            builder.append(", .hwModeParams = ");
            builder.append(this.hwModeParams);
            builder.append(", .channelParams = ");
            builder.append(this.channelParams);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<IfaceParams> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<IfaceParams> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 32,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams _hidl_vec_element = new android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ifaceName = _hidl_blob.getString(_hidl_offset + 0);

            parcel.readEmbeddedBuffer(
                    ((String) ifaceName).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            ((android.hardware.wifi.hostapd.V1_0.IHostapd.HwModeParams) hwModeParams).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
            ((android.hardware.wifi.hostapd.V1_0.IHostapd.ChannelParams) channelParams).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 20);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<IfaceParams> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putString(_hidl_offset + 0, ifaceName);
            hwModeParams.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
            channelParams.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 20);
        }
    };

    /**
     * Parameters to use for setting up the access point network.
     */
    public final static class NetworkParams {
        /**
         * SSID to set for the network
         */
        public java.util.ArrayList<Byte> ssid = new java.util.ArrayList<Byte>();
        /**
         * Whether the network needs to be hidden or not.
         */
        public boolean isHidden = false;
        /**
         * Key management mask for the network.
         */
        public int encryptionType = 0;
        /**
         * Passphrase for WPA_PSK network.
         */
        public String pskPassphrase = new String();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams.class) {
                return false;
            }
            android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams other = (android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.ssid, other.ssid)) {
                return false;
            }
            if (this.isHidden != other.isHidden) {
                return false;
            }
            if (this.encryptionType != other.encryptionType) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.pskPassphrase, other.pskPassphrase)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.ssid), 
                    android.os.HidlSupport.deepHashCode(this.isHidden), 
                    android.os.HidlSupport.deepHashCode(this.encryptionType), 
                    android.os.HidlSupport.deepHashCode(this.pskPassphrase));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".ssid = ");
            builder.append(this.ssid);
            builder.append(", .isHidden = ");
            builder.append(this.isHidden);
            builder.append(", .encryptionType = ");
            builder.append(android.hardware.wifi.hostapd.V1_0.IHostapd.EncryptionType.toString(this.encryptionType));
            builder.append(", .pskPassphrase = ");
            builder.append(this.pskPassphrase);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<NetworkParams> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<NetworkParams> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 40,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams _hidl_vec_element = new android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
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

                ((java.util.ArrayList<Byte>) ssid).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) ssid).add(_hidl_vec_element);
                }
            }
            isHidden = _hidl_blob.getBool(_hidl_offset + 16);
            encryptionType = _hidl_blob.getInt32(_hidl_offset + 20);
            pskPassphrase = _hidl_blob.getString(_hidl_offset + 24);

            parcel.readEmbeddedBuffer(
                    ((String) pskPassphrase).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<NetworkParams> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = ssid.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, ssid.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            _hidl_blob.putBool(_hidl_offset + 16, isHidden);
            _hidl_blob.putInt32(_hidl_offset + 20, encryptionType);
            _hidl_blob.putString(_hidl_offset + 24, pskPassphrase);
        }
    };

    /**
     * Adds a new access point for hostapd to control.
     *
     * This should trigger the setup of an access point with the specified
     * interface and network params.
     *
     * @param ifaceParams AccessPoint Params for the access point.
     * @param nwParams Network Params for the access point.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |HostapdStatusCode.SUCCESS|,
     *         |HostapdStatusCode.FAILURE_ARGS_INVALID|,
     *         |HostapdStatusCode.FAILURE_UNKNOWN|,
     *         |HostapdStatusCode.FAILURE_IFACE_EXISTS|
     */
    android.hardware.wifi.hostapd.V1_0.HostapdStatus addAccessPoint(android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams ifaceParams, android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams nwParams)
        throws android.os.RemoteException;
    /**
     * Removes an existing access point from hostapd.
     *
     * This should bring down the access point previously setup on the
     * interface.
     *
     * @param ifaceName Name of the interface.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |HostapdStatusCode.SUCCESS|,
     *         |HostapdStatusCode.FAILURE_UNKNOWN|,
     *         |HostapdStatusCode.FAILURE_IFACE_UNKNOWN|
     */
    android.hardware.wifi.hostapd.V1_0.HostapdStatus removeAccessPoint(String ifaceName)
        throws android.os.RemoteException;
    /**
     * Terminate the service.
     * This must de-register the service and clear all state. If this HAL
     * supports the lazy HAL protocol, then this may trigger daemon to exit and
     * wait to be restarted.
     */
    void terminate()
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

    public static final class Proxy implements IHostapd {
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
            return "[class or subclass of " + IHostapd.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::hostapd::V1_0::IHostapd follow.
        @Override
        public android.hardware.wifi.hostapd.V1_0.HostapdStatus addAccessPoint(android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams ifaceParams, android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams nwParams)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);
            ((android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams) ifaceParams).writeToParcel(_hidl_request);
            ((android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams) nwParams).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* addAccessPoint */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.hostapd.V1_0.HostapdStatus _hidl_out_status = new android.hardware.wifi.hostapd.V1_0.HostapdStatus();
                ((android.hardware.wifi.hostapd.V1_0.HostapdStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.hostapd.V1_0.HostapdStatus removeAccessPoint(String ifaceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);
            _hidl_request.writeString(ifaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* removeAccessPoint */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.hostapd.V1_0.HostapdStatus _hidl_out_status = new android.hardware.wifi.hostapd.V1_0.HostapdStatus();
                ((android.hardware.wifi.hostapd.V1_0.HostapdStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void terminate()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* terminate */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements IHostapd {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-18,8,40,13,-30,28,-76,30,62,-62,109,110,-42,54,-57,1,-73,-9,5,22,-25,31,-78,47,79,-26,10,19,-26,3,-12,6} /* ee08280de21cb41e3ec26d6ed636c701b7f70516e71fb22f4fe60a13e603f406 */,
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
                case 1 /* addAccessPoint */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);

                    android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams ifaceParams = new android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.IfaceParams) ifaceParams).readFromParcel(_hidl_request);
                    android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams nwParams = new android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams();
                    ((android.hardware.wifi.hostapd.V1_0.IHostapd.NetworkParams) nwParams).readFromParcel(_hidl_request);
                    android.hardware.wifi.hostapd.V1_0.HostapdStatus _hidl_out_status = addAccessPoint(ifaceParams, nwParams);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.hostapd.V1_0.HostapdStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* removeAccessPoint */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);

                    String ifaceName = _hidl_request.readString();
                    android.hardware.wifi.hostapd.V1_0.HostapdStatus _hidl_out_status = removeAccessPoint(ifaceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.hostapd.V1_0.HostapdStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* terminate */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.hostapd.V1_0.IHostapd.kInterfaceName);

                    terminate();
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
