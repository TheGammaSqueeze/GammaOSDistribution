package android.hardware.wifi.V1_0;


public final class NanClusterEventInd {
    /**
     * Event type causing the cluster event indication to be triggered.
     */
    public int eventType = 0;
    /**
     * MAC Address associated with the corresponding event.
     */
    public byte[/* 6 */] addr = new byte[6];

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanClusterEventInd.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanClusterEventInd other = (android.hardware.wifi.V1_0.NanClusterEventInd)otherObject;
        if (this.eventType != other.eventType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.addr, other.addr)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.eventType), 
                android.os.HidlSupport.deepHashCode(this.addr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".eventType = ");
        builder.append(android.hardware.wifi.V1_0.NanClusterEventType.toString(this.eventType));
        builder.append(", .addr = ");
        builder.append(java.util.Arrays.toString(this.addr));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanClusterEventInd> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanClusterEventInd> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanClusterEventInd _hidl_vec_element = new android.hardware.wifi.V1_0.NanClusterEventInd();
                ((android.hardware.wifi.V1_0.NanClusterEventInd) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        eventType = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            long _hidl_array_offset_0 = _hidl_offset + 4;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) addr, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanClusterEventInd> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, eventType);
        {
            long _hidl_array_offset_0 = _hidl_offset + 4;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) addr;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
    }
};

