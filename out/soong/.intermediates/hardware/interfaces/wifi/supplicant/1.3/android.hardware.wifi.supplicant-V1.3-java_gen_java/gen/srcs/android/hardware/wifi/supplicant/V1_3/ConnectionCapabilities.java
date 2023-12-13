package android.hardware.wifi.supplicant.V1_3;


public final class ConnectionCapabilities {
    /**
     * Wifi Technology
     */
    public int technology = 0;
    /**
     * channel bandwidth
     */
    public int channelBandwidth = 0;
    /**
     * max number of Tx spatial streams
     */
    public int maxNumberTxSpatialStreams = 0;
    /**
     * max number of Rx spatial streams
     */
    public int maxNumberRxSpatialStreams = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities.class) {
            return false;
        }
        android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities other = (android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities)otherObject;
        if (this.technology != other.technology) {
            return false;
        }
        if (this.channelBandwidth != other.channelBandwidth) {
            return false;
        }
        if (this.maxNumberTxSpatialStreams != other.maxNumberTxSpatialStreams) {
            return false;
        }
        if (this.maxNumberRxSpatialStreams != other.maxNumberRxSpatialStreams) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.technology), 
                android.os.HidlSupport.deepHashCode(this.channelBandwidth), 
                android.os.HidlSupport.deepHashCode(this.maxNumberTxSpatialStreams), 
                android.os.HidlSupport.deepHashCode(this.maxNumberRxSpatialStreams));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".technology = ");
        builder.append(android.hardware.wifi.supplicant.V1_3.WifiTechnology.toString(this.technology));
        builder.append(", .channelBandwidth = ");
        builder.append(android.hardware.wifi.V1_0.WifiChannelWidthInMhz.toString(this.channelBandwidth));
        builder.append(", .maxNumberTxSpatialStreams = ");
        builder.append(this.maxNumberTxSpatialStreams);
        builder.append(", .maxNumberRxSpatialStreams = ");
        builder.append(this.maxNumberRxSpatialStreams);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ConnectionCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ConnectionCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities _hidl_vec_element = new android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities();
                ((android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        technology = _hidl_blob.getInt32(_hidl_offset + 0);
        channelBandwidth = _hidl_blob.getInt32(_hidl_offset + 4);
        maxNumberTxSpatialStreams = _hidl_blob.getInt32(_hidl_offset + 8);
        maxNumberRxSpatialStreams = _hidl_blob.getInt32(_hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ConnectionCapabilities> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, technology);
        _hidl_blob.putInt32(_hidl_offset + 4, channelBandwidth);
        _hidl_blob.putInt32(_hidl_offset + 8, maxNumberTxSpatialStreams);
        _hidl_blob.putInt32(_hidl_offset + 12, maxNumberRxSpatialStreams);
    }
};

