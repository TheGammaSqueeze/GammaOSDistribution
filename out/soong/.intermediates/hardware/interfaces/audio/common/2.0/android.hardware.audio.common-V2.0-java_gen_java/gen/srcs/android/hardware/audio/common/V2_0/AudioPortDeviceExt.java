package android.hardware.audio.common.V2_0;


public final class AudioPortDeviceExt {
    public int hwModule = 0;
    public int type = 0;
    public byte[/* 32 */] address = new byte[32];

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioPortDeviceExt.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioPortDeviceExt other = (android.hardware.audio.common.V2_0.AudioPortDeviceExt)otherObject;
        if (this.hwModule != other.hwModule) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.address, other.address)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.hwModule), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.address));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".hwModule = ");
        builder.append(this.hwModule);
        builder.append(", .type = ");
        builder.append(android.hardware.audio.common.V2_0.AudioDevice.toString(this.type));
        builder.append(", .address = ");
        builder.append(java.util.Arrays.toString(this.address));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioPortDeviceExt> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioPortDeviceExt> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioPortDeviceExt _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioPortDeviceExt();
                ((android.hardware.audio.common.V2_0.AudioPortDeviceExt) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        hwModule = _hidl_blob.getInt32(_hidl_offset + 0);
        type = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 32 */]) address, 32 /* size */);
            _hidl_array_offset_0 += 32 * 1;
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioPortDeviceExt> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, hwModule);
        _hidl_blob.putInt32(_hidl_offset + 4, type);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            byte[] _hidl_array_item_0 = (byte[/* 32 */]) address;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 32) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 32 * 1;
        }
    }
};

