package android.hardware.wifi.V1_3;


public final class WifiChannelStats {
    /**
     * Channel information.
     */
    public android.hardware.wifi.V1_0.WifiChannelInfo channel = new android.hardware.wifi.V1_0.WifiChannelInfo();
    /**
     * Total time for which the radio is awake on this channel.
     */
    public int onTimeInMs = 0;
    /**
     * Total time for which CCA is held busy on this channel.
     */
    public int ccaBusyTimeInMs = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_3.WifiChannelStats.class) {
            return false;
        }
        android.hardware.wifi.V1_3.WifiChannelStats other = (android.hardware.wifi.V1_3.WifiChannelStats)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.channel, other.channel)) {
            return false;
        }
        if (this.onTimeInMs != other.onTimeInMs) {
            return false;
        }
        if (this.ccaBusyTimeInMs != other.ccaBusyTimeInMs) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.channel), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMs), 
                android.os.HidlSupport.deepHashCode(this.ccaBusyTimeInMs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".channel = ");
        builder.append(this.channel);
        builder.append(", .onTimeInMs = ");
        builder.append(this.onTimeInMs);
        builder.append(", .ccaBusyTimeInMs = ");
        builder.append(this.ccaBusyTimeInMs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiChannelStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiChannelStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_3.WifiChannelStats _hidl_vec_element = new android.hardware.wifi.V1_3.WifiChannelStats();
                ((android.hardware.wifi.V1_3.WifiChannelStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.WifiChannelInfo) channel).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        onTimeInMs = _hidl_blob.getInt32(_hidl_offset + 16);
        ccaBusyTimeInMs = _hidl_blob.getInt32(_hidl_offset + 20);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiChannelStats> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        channel.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 16, onTimeInMs);
        _hidl_blob.putInt32(_hidl_offset + 20, ccaBusyTimeInMs);
    }
};

