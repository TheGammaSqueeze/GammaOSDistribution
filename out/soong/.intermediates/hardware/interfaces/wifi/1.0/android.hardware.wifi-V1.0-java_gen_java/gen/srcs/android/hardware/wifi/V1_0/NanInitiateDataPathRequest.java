package android.hardware.wifi.V1_0;


public final class NanInitiateDataPathRequest {
    /**
     * ID of the peer. Obtained as part of an earlier |IWifiNanIfaceEventCallback.eventMatch| or
     * |IWifiNanIfaceEventCallback.eventFollowupReceived|.
     */
    public int peerId = 0;
    /**
     * NAN management interface MAC address of the peer. Obtained as part of an earlier
     * |IWifiNanIfaceEventCallback.eventMatch| or |IWifiNanIfaceEventCallback.eventFollowupReceived|.
     */
    public byte[/* 6 */] peerDiscMacAddr = new byte[6];
    /**
     * Config flag for channel request.
     */
    public int channelRequestType = 0;
    /**
     * Channel frequency in MHz to start data-path. Not relevant if |channelRequestType| is
     * |NanDataPathChannelCfg.CHANNEL_NOT_REQUESTED|.
     */
    public int channel = 0;
    /**
     * NAN data interface name on which this data-path session is to be initiated.
     * This must be an interface created using |IWifiNanIface.createDataInterfaceRequest|.
     */
    public String ifaceName = new String();
    /**
     * Security configuration of the requested data-path.
     */
    public android.hardware.wifi.V1_0.NanDataPathSecurityConfig securityConfig = new android.hardware.wifi.V1_0.NanDataPathSecurityConfig();
    /**
     * Arbitrary information communicated to the peer as part of the data-path setup process - there
     * is no semantic meaning to these bytes. They are passed-through from sender to receiver as-is
     * with no parsing.
     * Max length: |NanCapabilities.maxAppInfoLen|.
     * NAN Spec: Data Path Attributes / NDP Attribute / NDP Specific Info
     */
    public java.util.ArrayList<Byte> appInfo = new java.util.ArrayList<Byte>();
    /**
     * A service name to be used with |passphrase| to construct a Pairwise Master Key (PMK) for the
     * data-path. Only relevant when a data-path is requested which is not associated with a NAN
     * discovery session - e.g. using out-of-band discovery.
     * Constraints: same as |NanDiscoveryCommonConfig.serviceName|
     * NAN Spec: Appendix: Mapping pass-phrase to PMK for NCS-SK Cipher Suites
     */
    public java.util.ArrayList<Byte> serviceNameOutOfBand = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanInitiateDataPathRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanInitiateDataPathRequest other = (android.hardware.wifi.V1_0.NanInitiateDataPathRequest)otherObject;
        if (this.peerId != other.peerId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.peerDiscMacAddr, other.peerDiscMacAddr)) {
            return false;
        }
        if (this.channelRequestType != other.channelRequestType) {
            return false;
        }
        if (this.channel != other.channel) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ifaceName, other.ifaceName)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.securityConfig, other.securityConfig)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.appInfo, other.appInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serviceNameOutOfBand, other.serviceNameOutOfBand)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.peerId), 
                android.os.HidlSupport.deepHashCode(this.peerDiscMacAddr), 
                android.os.HidlSupport.deepHashCode(this.channelRequestType), 
                android.os.HidlSupport.deepHashCode(this.channel), 
                android.os.HidlSupport.deepHashCode(this.ifaceName), 
                android.os.HidlSupport.deepHashCode(this.securityConfig), 
                android.os.HidlSupport.deepHashCode(this.appInfo), 
                android.os.HidlSupport.deepHashCode(this.serviceNameOutOfBand));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".peerId = ");
        builder.append(this.peerId);
        builder.append(", .peerDiscMacAddr = ");
        builder.append(java.util.Arrays.toString(this.peerDiscMacAddr));
        builder.append(", .channelRequestType = ");
        builder.append(android.hardware.wifi.V1_0.NanDataPathChannelCfg.toString(this.channelRequestType));
        builder.append(", .channel = ");
        builder.append(this.channel);
        builder.append(", .ifaceName = ");
        builder.append(this.ifaceName);
        builder.append(", .securityConfig = ");
        builder.append(this.securityConfig);
        builder.append(", .appInfo = ");
        builder.append(this.appInfo);
        builder.append(", .serviceNameOutOfBand = ");
        builder.append(this.serviceNameOutOfBand);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(128 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanInitiateDataPathRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanInitiateDataPathRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 128,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanInitiateDataPathRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanInitiateDataPathRequest();
                ((android.hardware.wifi.V1_0.NanInitiateDataPathRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 128);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        peerId = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            long _hidl_array_offset_0 = _hidl_offset + 4;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerDiscMacAddr, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        channelRequestType = _hidl_blob.getInt32(_hidl_offset + 12);
        channel = _hidl_blob.getInt32(_hidl_offset + 16);
        ifaceName = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) ifaceName).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ((android.hardware.wifi.V1_0.NanDataPathSecurityConfig) securityConfig).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 40);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) appInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) appInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 112 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 112 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) serviceNameOutOfBand).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) serviceNameOutOfBand).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(128 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanInitiateDataPathRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 128));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 128);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, peerId);
        {
            long _hidl_array_offset_0 = _hidl_offset + 4;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerDiscMacAddr;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        _hidl_blob.putInt32(_hidl_offset + 12, channelRequestType);
        _hidl_blob.putInt32(_hidl_offset + 16, channel);
        _hidl_blob.putString(_hidl_offset + 24, ifaceName);
        securityConfig.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 40);
        {
            int _hidl_vec_size = appInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 96 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, appInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = serviceNameOutOfBand.size();
            _hidl_blob.putInt32(_hidl_offset + 112 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 112 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, serviceNameOutOfBand.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 112 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

