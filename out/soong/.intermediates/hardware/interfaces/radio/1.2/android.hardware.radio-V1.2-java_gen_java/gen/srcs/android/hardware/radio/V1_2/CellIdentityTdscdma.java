package android.hardware.radio.V1_2;


public final class CellIdentityTdscdma {
    public android.hardware.radio.V1_0.CellIdentityTdscdma base = new android.hardware.radio.V1_0.CellIdentityTdscdma();
    /**
     * 16-bit UMTS Absolute RF Channel Number defined in TS 25.102 5.4.4; this value must be valid.
     */
    public int uarfcn = 0;
    public android.hardware.radio.V1_2.CellIdentityOperatorNames operatorNames = new android.hardware.radio.V1_2.CellIdentityOperatorNames();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.CellIdentityTdscdma.class) {
            return false;
        }
        android.hardware.radio.V1_2.CellIdentityTdscdma other = (android.hardware.radio.V1_2.CellIdentityTdscdma)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.base, other.base)) {
            return false;
        }
        if (this.uarfcn != other.uarfcn) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.operatorNames, other.operatorNames)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.base), 
                android.os.HidlSupport.deepHashCode(this.uarfcn), 
                android.os.HidlSupport.deepHashCode(this.operatorNames));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".base = ");
        builder.append(this.base);
        builder.append(", .uarfcn = ");
        builder.append(this.uarfcn);
        builder.append(", .operatorNames = ");
        builder.append(this.operatorNames);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentityTdscdma> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentityTdscdma> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityTdscdma _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityTdscdma();
                ((android.hardware.radio.V1_2.CellIdentityTdscdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_0.CellIdentityTdscdma) base).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        uarfcn = _hidl_blob.getInt32(_hidl_offset + 48);
        ((android.hardware.radio.V1_2.CellIdentityOperatorNames) operatorNames).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentityTdscdma> _hidl_vec) {
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
        base.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 48, uarfcn);
        operatorNames.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 56);
    }
};

