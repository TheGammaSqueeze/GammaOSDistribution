package android.hardware.audio.common.V2_0;


public final class AudioPortMixExt {
    public int hwModule = 0;
    public int ioHandle = 0;
    public int latencyClass = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioPortMixExt.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioPortMixExt other = (android.hardware.audio.common.V2_0.AudioPortMixExt)otherObject;
        if (this.hwModule != other.hwModule) {
            return false;
        }
        if (this.ioHandle != other.ioHandle) {
            return false;
        }
        if (this.latencyClass != other.latencyClass) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.hwModule), 
                android.os.HidlSupport.deepHashCode(this.ioHandle), 
                android.os.HidlSupport.deepHashCode(this.latencyClass));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".hwModule = ");
        builder.append(this.hwModule);
        builder.append(", .ioHandle = ");
        builder.append(this.ioHandle);
        builder.append(", .latencyClass = ");
        builder.append(android.hardware.audio.common.V2_0.AudioMixLatencyClass.toString(this.latencyClass));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioPortMixExt> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioPortMixExt> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioPortMixExt _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioPortMixExt();
                ((android.hardware.audio.common.V2_0.AudioPortMixExt) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        hwModule = _hidl_blob.getInt32(_hidl_offset + 0);
        ioHandle = _hidl_blob.getInt32(_hidl_offset + 4);
        latencyClass = _hidl_blob.getInt32(_hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioPortMixExt> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, hwModule);
        _hidl_blob.putInt32(_hidl_offset + 4, ioHandle);
        _hidl_blob.putInt32(_hidl_offset + 8, latencyClass);
    }
};

