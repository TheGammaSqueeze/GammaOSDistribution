package android.hardware.radio.V1_0;


public final class SimApdu {
    public int sessionId = 0;
    public int cla = 0;
    public int instruction = 0;
    public int p1 = 0;
    public int p2 = 0;
    public int p3 = 0;
    public String data = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.SimApdu.class) {
            return false;
        }
        android.hardware.radio.V1_0.SimApdu other = (android.hardware.radio.V1_0.SimApdu)otherObject;
        if (this.sessionId != other.sessionId) {
            return false;
        }
        if (this.cla != other.cla) {
            return false;
        }
        if (this.instruction != other.instruction) {
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
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sessionId), 
                android.os.HidlSupport.deepHashCode(this.cla), 
                android.os.HidlSupport.deepHashCode(this.instruction), 
                android.os.HidlSupport.deepHashCode(this.p1), 
                android.os.HidlSupport.deepHashCode(this.p2), 
                android.os.HidlSupport.deepHashCode(this.p3), 
                android.os.HidlSupport.deepHashCode(this.data));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sessionId = ");
        builder.append(this.sessionId);
        builder.append(", .cla = ");
        builder.append(this.cla);
        builder.append(", .instruction = ");
        builder.append(this.instruction);
        builder.append(", .p1 = ");
        builder.append(this.p1);
        builder.append(", .p2 = ");
        builder.append(this.p2);
        builder.append(", .p3 = ");
        builder.append(this.p3);
        builder.append(", .data = ");
        builder.append(this.data);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SimApdu> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SimApdu> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.SimApdu _hidl_vec_element = new android.hardware.radio.V1_0.SimApdu();
                ((android.hardware.radio.V1_0.SimApdu) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sessionId = _hidl_blob.getInt32(_hidl_offset + 0);
        cla = _hidl_blob.getInt32(_hidl_offset + 4);
        instruction = _hidl_blob.getInt32(_hidl_offset + 8);
        p1 = _hidl_blob.getInt32(_hidl_offset + 12);
        p2 = _hidl_blob.getInt32(_hidl_offset + 16);
        p3 = _hidl_blob.getInt32(_hidl_offset + 20);
        data = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) data).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SimApdu> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, sessionId);
        _hidl_blob.putInt32(_hidl_offset + 4, cla);
        _hidl_blob.putInt32(_hidl_offset + 8, instruction);
        _hidl_blob.putInt32(_hidl_offset + 12, p1);
        _hidl_blob.putInt32(_hidl_offset + 16, p2);
        _hidl_blob.putInt32(_hidl_offset + 20, p3);
        _hidl_blob.putString(_hidl_offset + 24, data);
    }
};

