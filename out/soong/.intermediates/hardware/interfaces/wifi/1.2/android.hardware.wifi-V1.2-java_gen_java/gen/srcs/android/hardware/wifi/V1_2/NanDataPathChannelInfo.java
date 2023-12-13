package android.hardware.wifi.V1_2;


public final class NanDataPathChannelInfo {
    /**
     * Channel frequency in MHz.
     */
    public int channelFreq = 0;
    /**
     * Channel bandwidth in MHz.
     */
    public int channelBandwidth = 0;
    /**
     * Number of spatial streams used in the channel.
     */
    public int numSpatialStreams = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_2.NanDataPathChannelInfo.class) {
            return false;
        }
        android.hardware.wifi.V1_2.NanDataPathChannelInfo other = (android.hardware.wifi.V1_2.NanDataPathChannelInfo)otherObject;
        if (this.channelFreq != other.channelFreq) {
            return false;
        }
        if (this.channelBandwidth != other.channelBandwidth) {
            return false;
        }
        if (this.numSpatialStreams != other.numSpatialStreams) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.channelFreq), 
                android.os.HidlSupport.deepHashCode(this.channelBandwidth), 
                android.os.HidlSupport.deepHashCode(this.numSpatialStreams));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".channelFreq = ");
        builder.append(this.channelFreq);
        builder.append(", .channelBandwidth = ");
        builder.append(android.hardware.wifi.V1_0.WifiChannelWidthInMhz.toString(this.channelBandwidth));
        builder.append(", .numSpatialStreams = ");
        builder.append(this.numSpatialStreams);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDataPathChannelInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDataPathChannelInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanDataPathChannelInfo _hidl_vec_element = new android.hardware.wifi.V1_2.NanDataPathChannelInfo();
                ((android.hardware.wifi.V1_2.NanDataPathChannelInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        channelFreq = _hidl_blob.getInt32(_hidl_offset + 0);
        channelBandwidth = _hidl_blob.getInt32(_hidl_offset + 4);
        numSpatialStreams = _hidl_blob.getInt32(_hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDataPathChannelInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, channelFreq);
        _hidl_blob.putInt32(_hidl_offset + 4, channelBandwidth);
        _hidl_blob.putInt32(_hidl_offset + 8, numSpatialStreams);
    }
};

