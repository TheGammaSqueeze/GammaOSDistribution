package android.hardware.radio.V1_0;


public final class SuppSvcNotification {
    public boolean isMT = false;
    public int code = 0;
    public int index = 0;
    public int type = 0;
    public String number = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.SuppSvcNotification.class) {
            return false;
        }
        android.hardware.radio.V1_0.SuppSvcNotification other = (android.hardware.radio.V1_0.SuppSvcNotification)otherObject;
        if (this.isMT != other.isMT) {
            return false;
        }
        if (this.code != other.code) {
            return false;
        }
        if (this.index != other.index) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.isMT), 
                android.os.HidlSupport.deepHashCode(this.code), 
                android.os.HidlSupport.deepHashCode(this.index), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.number));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".isMT = ");
        builder.append(this.isMT);
        builder.append(", .code = ");
        builder.append(this.code);
        builder.append(", .index = ");
        builder.append(this.index);
        builder.append(", .type = ");
        builder.append(this.type);
        builder.append(", .number = ");
        builder.append(this.number);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SuppSvcNotification> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SuppSvcNotification> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.SuppSvcNotification _hidl_vec_element = new android.hardware.radio.V1_0.SuppSvcNotification();
                ((android.hardware.radio.V1_0.SuppSvcNotification) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        isMT = _hidl_blob.getBool(_hidl_offset + 0);
        code = _hidl_blob.getInt32(_hidl_offset + 4);
        index = _hidl_blob.getInt32(_hidl_offset + 8);
        type = _hidl_blob.getInt32(_hidl_offset + 12);
        number = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) number).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SuppSvcNotification> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, isMT);
        _hidl_blob.putInt32(_hidl_offset + 4, code);
        _hidl_blob.putInt32(_hidl_offset + 8, index);
        _hidl_blob.putInt32(_hidl_offset + 12, type);
        _hidl_blob.putString(_hidl_offset + 16, number);
    }
};

