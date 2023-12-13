package android.hardware.wifi.V1_2;


public final class NanDataPathConfirmInd {
    /**
     * Baseline information as defined in HAL 1.0.
     */
    public android.hardware.wifi.V1_0.NanDataPathConfirmInd V1_0 = new android.hardware.wifi.V1_0.NanDataPathConfirmInd();
    /**
     * The channel(s) on which the NDP is scheduled to operate.
     * Updates to the operational channels are provided using the |eventDataPathScheduleUpdate|
     * event.
     */
    public java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo> channelInfo = new java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_2.NanDataPathConfirmInd.class) {
            return false;
        }
        android.hardware.wifi.V1_2.NanDataPathConfirmInd other = (android.hardware.wifi.V1_2.NanDataPathConfirmInd)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.V1_0, other.V1_0)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.channelInfo, other.channelInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.V1_0), 
                android.os.HidlSupport.deepHashCode(this.channelInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".V1_0 = ");
        builder.append(this.V1_0);
        builder.append(", .channelInfo = ");
        builder.append(this.channelInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDataPathConfirmInd> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDataPathConfirmInd> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanDataPathConfirmInd _hidl_vec_element = new android.hardware.wifi.V1_2.NanDataPathConfirmInd();
                ((android.hardware.wifi.V1_2.NanDataPathConfirmInd) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.NanDataPathConfirmInd) V1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>) channelInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanDataPathChannelInfo _hidl_vec_element = new android.hardware.wifi.V1_2.NanDataPathChannelInfo();
                ((android.hardware.wifi.V1_2.NanDataPathChannelInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                ((java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>) channelInfo).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDataPathConfirmInd> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        V1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = channelInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                channelInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

