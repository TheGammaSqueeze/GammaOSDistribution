package android.hardware.radio.V1_0;


public final class PcoDataInfo {
    public int cid = 0;
    public String bearerProto = new String();
    public int pcoId = 0;
    public java.util.ArrayList<Byte> contents = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.PcoDataInfo.class) {
            return false;
        }
        android.hardware.radio.V1_0.PcoDataInfo other = (android.hardware.radio.V1_0.PcoDataInfo)otherObject;
        if (this.cid != other.cid) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bearerProto, other.bearerProto)) {
            return false;
        }
        if (this.pcoId != other.pcoId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.contents, other.contents)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cid), 
                android.os.HidlSupport.deepHashCode(this.bearerProto), 
                android.os.HidlSupport.deepHashCode(this.pcoId), 
                android.os.HidlSupport.deepHashCode(this.contents));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cid = ");
        builder.append(this.cid);
        builder.append(", .bearerProto = ");
        builder.append(this.bearerProto);
        builder.append(", .pcoId = ");
        builder.append(this.pcoId);
        builder.append(", .contents = ");
        builder.append(this.contents);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PcoDataInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PcoDataInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.PcoDataInfo _hidl_vec_element = new android.hardware.radio.V1_0.PcoDataInfo();
                ((android.hardware.radio.V1_0.PcoDataInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cid = _hidl_blob.getInt32(_hidl_offset + 0);
        bearerProto = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) bearerProto).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        pcoId = _hidl_blob.getInt32(_hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) contents).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) contents).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PcoDataInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, cid);
        _hidl_blob.putString(_hidl_offset + 8, bearerProto);
        _hidl_blob.putInt32(_hidl_offset + 24, pcoId);
        {
            int _hidl_vec_size = contents.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, contents.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

