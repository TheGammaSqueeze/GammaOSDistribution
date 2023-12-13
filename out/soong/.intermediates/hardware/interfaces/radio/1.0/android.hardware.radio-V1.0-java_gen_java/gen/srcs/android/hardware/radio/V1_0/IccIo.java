package android.hardware.radio.V1_0;


public final class IccIo {
    public int command = 0;
    public int fileId = 0;
    public String path = new String();
    public int p1 = 0;
    public int p2 = 0;
    public int p3 = 0;
    public String data = new String();
    public String pin2 = new String();
    public String aid = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.IccIo.class) {
            return false;
        }
        android.hardware.radio.V1_0.IccIo other = (android.hardware.radio.V1_0.IccIo)otherObject;
        if (this.command != other.command) {
            return false;
        }
        if (this.fileId != other.fileId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.path, other.path)) {
            return false;
        }
        if (this.p1 != other.p1) {
            return false;
        }
        if (this.p2 != other.p2) {
            return false;
        }
        if (this.p3 != other.p3) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.data, other.data)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.pin2, other.pin2)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.aid, other.aid)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.command), 
                android.os.HidlSupport.deepHashCode(this.fileId), 
                android.os.HidlSupport.deepHashCode(this.path), 
                android.os.HidlSupport.deepHashCode(this.p1), 
                android.os.HidlSupport.deepHashCode(this.p2), 
                android.os.HidlSupport.deepHashCode(this.p3), 
                android.os.HidlSupport.deepHashCode(this.data), 
                android.os.HidlSupport.deepHashCode(this.pin2), 
                android.os.HidlSupport.deepHashCode(this.aid));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".command = ");
        builder.append(this.command);
        builder.append(", .fileId = ");
        builder.append(this.fileId);
        builder.append(", .path = ");
        builder.append(this.path);
        builder.append(", .p1 = ");
        builder.append(this.p1);
        builder.append(", .p2 = ");
        builder.append(this.p2);
        builder.append(", .p3 = ");
        builder.append(this.p3);
        builder.append(", .data = ");
        builder.append(this.data);
        builder.append(", .pin2 = ");
        builder.append(this.pin2);
        builder.append(", .aid = ");
        builder.append(this.aid);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<IccIo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<IccIo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.IccIo _hidl_vec_element = new android.hardware.radio.V1_0.IccIo();
                ((android.hardware.radio.V1_0.IccIo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        command = _hidl_blob.getInt32(_hidl_offset + 0);
        fileId = _hidl_blob.getInt32(_hidl_offset + 4);
        path = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) path).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        p1 = _hidl_blob.getInt32(_hidl_offset + 24);
        p2 = _hidl_blob.getInt32(_hidl_offset + 28);
        p3 = _hidl_blob.getInt32(_hidl_offset + 32);
        data = _hidl_blob.getString(_hidl_offset + 40);

        parcel.readEmbeddedBuffer(
                ((String) data).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        pin2 = _hidl_blob.getString(_hidl_offset + 56);

        parcel.readEmbeddedBuffer(
                ((String) pin2).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 56 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        aid = _hidl_blob.getString(_hidl_offset + 72);

        parcel.readEmbeddedBuffer(
                ((String) aid).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 72 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<IccIo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, command);
        _hidl_blob.putInt32(_hidl_offset + 4, fileId);
        _hidl_blob.putString(_hidl_offset + 8, path);
        _hidl_blob.putInt32(_hidl_offset + 24, p1);
        _hidl_blob.putInt32(_hidl_offset + 28, p2);
        _hidl_blob.putInt32(_hidl_offset + 32, p3);
        _hidl_blob.putString(_hidl_offset + 40, data);
        _hidl_blob.putString(_hidl_offset + 56, pin2);
        _hidl_blob.putString(_hidl_offset + 72, aid);
    }
};

