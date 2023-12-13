package android.hardware.radio.V1_2;


public final class CellInfoTdscdma {
    public android.hardware.radio.V1_2.CellIdentityTdscdma cellIdentityTdscdma = new android.hardware.radio.V1_2.CellIdentityTdscdma();
    public android.hardware.radio.V1_2.TdscdmaSignalStrength signalStrengthTdscdma = new android.hardware.radio.V1_2.TdscdmaSignalStrength();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.CellInfoTdscdma.class) {
            return false;
        }
        android.hardware.radio.V1_2.CellInfoTdscdma other = (android.hardware.radio.V1_2.CellInfoTdscdma)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityTdscdma, other.cellIdentityTdscdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalStrengthTdscdma, other.signalStrengthTdscdma)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellIdentityTdscdma), 
                android.os.HidlSupport.deepHashCode(this.signalStrengthTdscdma));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellIdentityTdscdma = ");
        builder.append(this.cellIdentityTdscdma);
        builder.append(", .signalStrengthTdscdma = ");
        builder.append(this.signalStrengthTdscdma);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(104 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfoTdscdma> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfoTdscdma> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 104,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoTdscdma _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoTdscdma();
                ((android.hardware.radio.V1_2.CellInfoTdscdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 104);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_2.CellIdentityTdscdma) cellIdentityTdscdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_2.TdscdmaSignalStrength) signalStrengthTdscdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 88);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(104 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfoTdscdma> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 104));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 104);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellIdentityTdscdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        signalStrengthTdscdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 88);
    }
};

