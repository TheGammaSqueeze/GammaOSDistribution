package android.hardware.audio.common.V2_0;


public final class Uuid {
    public int timeLow = 0;
    public short timeMid = 0;
    public short versionAndTimeHigh = 0;
    public short variantAndClockSeqHigh = 0;
    public byte[/* 6 */] node = new byte[6];

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.Uuid.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.Uuid other = (android.hardware.audio.common.V2_0.Uuid)otherObject;
        if (this.timeLow != other.timeLow) {
            return false;
        }
        if (this.timeMid != other.timeMid) {
            return false;
        }
        if (this.versionAndTimeHigh != other.versionAndTimeHigh) {
            return false;
        }
        if (this.variantAndClockSeqHigh != other.variantAndClockSeqHigh) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.node, other.node)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.timeLow), 
                android.os.HidlSupport.deepHashCode(this.timeMid), 
                android.os.HidlSupport.deepHashCode(this.versionAndTimeHigh), 
                android.os.HidlSupport.deepHashCode(this.variantAndClockSeqHigh), 
                android.os.HidlSupport.deepHashCode(this.node));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".timeLow = ");
        builder.append(this.timeLow);
        builder.append(", .timeMid = ");
        builder.append(this.timeMid);
        builder.append(", .versionAndTimeHigh = ");
        builder.append(this.versionAndTimeHigh);
        builder.append(", .variantAndClockSeqHigh = ");
        builder.append(this.variantAndClockSeqHigh);
        builder.append(", .node = ");
        builder.append(java.util.Arrays.toString(this.node));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Uuid> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Uuid> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.Uuid _hidl_vec_element = new android.hardware.audio.common.V2_0.Uuid();
                ((android.hardware.audio.common.V2_0.Uuid) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        timeLow = _hidl_blob.getInt32(_hidl_offset + 0);
        timeMid = _hidl_blob.getInt16(_hidl_offset + 4);
        versionAndTimeHigh = _hidl_blob.getInt16(_hidl_offset + 6);
        variantAndClockSeqHigh = _hidl_blob.getInt16(_hidl_offset + 8);
        {
            long _hidl_array_offset_0 = _hidl_offset + 10;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) node, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<Uuid> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, timeLow);
        _hidl_blob.putInt16(_hidl_offset + 4, timeMid);
        _hidl_blob.putInt16(_hidl_offset + 6, versionAndTimeHigh);
        _hidl_blob.putInt16(_hidl_offset + 8, variantAndClockSeqHigh);
        {
            long _hidl_array_offset_0 = _hidl_offset + 10;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) node;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
    }
};

