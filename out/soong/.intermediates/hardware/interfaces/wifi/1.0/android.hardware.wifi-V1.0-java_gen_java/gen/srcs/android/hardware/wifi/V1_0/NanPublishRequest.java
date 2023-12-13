package android.hardware.wifi.V1_0;


public final class NanPublishRequest {
    /**
     * Common configuration of discovery sessions.
     */
    public android.hardware.wifi.V1_0.NanDiscoveryCommonConfig baseConfigs = new android.hardware.wifi.V1_0.NanDiscoveryCommonConfig();
    /**
     * The type of the publish discovery session.
     */
    public int publishType = 0;
    /**
     * For publishType of |NanPublishType.SOLICITED| or |NanPublishType.UNSOLICITED_SOLICITED|
     * specifies the type of transmission used for responding to the probing subscribe discovery
     * peer.
     */
    public int txType = 0;
    /**
     * Specifies whether data-path requests |IWifiNanIfaceEventCallback.eventDataPathRequest| (in
     * the context of this discovery session) are automatically accepted (if true) - in which case
     * the Responder must not call the |IWifiNanIface.respondToDataPathIndicationRequest| method and
     * the device must automatically accept the data-path request and complete the negotiation.
     */
    public boolean autoAcceptDataPathRequests = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanPublishRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanPublishRequest other = (android.hardware.wifi.V1_0.NanPublishRequest)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.baseConfigs, other.baseConfigs)) {
            return false;
        }
        if (this.publishType != other.publishType) {
            return false;
        }
        if (this.txType != other.txType) {
            return false;
        }
        if (this.autoAcceptDataPathRequests != other.autoAcceptDataPathRequests) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.baseConfigs), 
                android.os.HidlSupport.deepHashCode(this.publishType), 
                android.os.HidlSupport.deepHashCode(this.txType), 
                android.os.HidlSupport.deepHashCode(this.autoAcceptDataPathRequests));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".baseConfigs = ");
        builder.append(this.baseConfigs);
        builder.append(", .publishType = ");
        builder.append(android.hardware.wifi.V1_0.NanPublishType.toString(this.publishType));
        builder.append(", .txType = ");
        builder.append(android.hardware.wifi.V1_0.NanTxType.toString(this.txType));
        builder.append(", .autoAcceptDataPathRequests = ");
        builder.append(this.autoAcceptDataPathRequests);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(192 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanPublishRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanPublishRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 192,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanPublishRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanPublishRequest();
                ((android.hardware.wifi.V1_0.NanPublishRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 192);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.NanDiscoveryCommonConfig) baseConfigs).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        publishType = _hidl_blob.getInt32(_hidl_offset + 176);
        txType = _hidl_blob.getInt32(_hidl_offset + 180);
        autoAcceptDataPathRequests = _hidl_blob.getBool(_hidl_offset + 184);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(192 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanPublishRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 192));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 192);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        baseConfigs.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 176, publishType);
        _hidl_blob.putInt32(_hidl_offset + 180, txType);
        _hidl_blob.putBool(_hidl_offset + 184, autoAcceptDataPathRequests);
    }
};

