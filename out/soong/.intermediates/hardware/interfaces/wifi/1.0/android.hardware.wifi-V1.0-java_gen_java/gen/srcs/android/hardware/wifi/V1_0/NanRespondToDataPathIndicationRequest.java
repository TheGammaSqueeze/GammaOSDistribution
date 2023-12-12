package android.hardware.wifi.V1_0;


public final class NanRespondToDataPathIndicationRequest {
    /**
     * Accept (true) or reject (false) the request.
     * NAN Spec: Data Path Attributes / NDP Attribute / Type and Status
     */
    public boolean acceptRequest = false;
    /**
     * ID of the data-path (NDP) for which we're responding - obtained as part of the request in
     * |IWifiNanIfaceEventCallback.eventDataPathRequest|.
     */
    public int ndpInstanceId = 0;
    /**
     * NAN data interface name on which this data-path session is to be started.
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
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest other = (android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest)otherObject;
        if (this.acceptRequest != other.acceptRequest) {
            return false;
        }
        if (this.ndpInstanceId != other.ndpInstanceId) {
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
                android.os.HidlSupport.deepHashCode(this.acceptRequest), 
                android.os.HidlSupport.deepHashCode(this.ndpInstanceId), 
                android.os.HidlSupport.deepHashCode(this.ifaceName), 
                android.os.HidlSupport.deepHashCode(this.securityConfig), 
                android.os.HidlSupport.deepHashCode(this.appInfo), 
                android.os.HidlSupport.deepHashCode(this.serviceNameOutOfBand));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".acceptRequest = ");
        builder.append(this.acceptRequest);
        builder.append(", .ndpInstanceId = ");
        builder.append(this.ndpInstanceId);
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
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanRespondToDataPathIndicationRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanRespondToDataPathIndicationRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest();
                ((android.hardware.wifi.V1_0.NanRespondToDataPathIndicationRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        acceptRequest = _hidl_blob.getBool(_hidl_offset + 0);
        ndpInstanceId = _hidl_blob.getInt32(_hidl_offset + 4);
        ifaceName = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) ifaceName).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ((android.hardware.wifi.V1_0.NanDataPathSecurityConfig) securityConfig).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) appInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) appInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) serviceNameOutOfBand).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) serviceNameOutOfBand).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanRespondToDataPathIndicationRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, acceptRequest);
        _hidl_blob.putInt32(_hidl_offset + 4, ndpInstanceId);
        _hidl_blob.putString(_hidl_offset + 8, ifaceName);
        securityConfig.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 24);
        {
            int _hidl_vec_size = appInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, appInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = serviceNameOutOfBand.size();
            _hidl_blob.putInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 96 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, serviceNameOutOfBand.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

