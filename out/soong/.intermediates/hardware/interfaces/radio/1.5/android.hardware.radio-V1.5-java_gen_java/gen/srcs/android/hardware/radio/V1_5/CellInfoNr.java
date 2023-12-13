package android.hardware.radio.V1_5;


public final class CellInfoNr {
    public android.hardware.radio.V1_5.CellIdentityNr cellIdentityNr = new android.hardware.radio.V1_5.CellIdentityNr();
    public android.hardware.radio.V1_4.NrSignalStrength signalStrengthNr = new android.hardware.radio.V1_4.NrSignalStrength();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.CellInfoNr.class) {
            return false;
        }
        android.hardware.radio.V1_5.CellInfoNr other = (android.hardware.radio.V1_5.CellInfoNr)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityNr, other.cellIdentityNr)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalStrengthNr, other.signalStrengthNr)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellIdentityNr), 
                android.os.HidlSupport.deepHashCode(this.signalStrengthNr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellIdentityNr = ");
        builder.append(this.cellIdentityNr);
        builder.append(", .signalStrengthNr = ");
        builder.append(this.signalStrengthNr);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(144 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfoNr> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfoNr> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 144,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.CellInfoNr _hidl_vec_element = new android.hardware.radio.V1_5.CellInfoNr();
                ((android.hardware.radio.V1_5.CellInfoNr) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 144);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_5.CellIdentityNr) cellIdentityNr).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_4.NrSignalStrength) signalStrengthNr).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 120);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(144 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfoNr> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 144));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 144);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellIdentityNr.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        signalStrengthNr.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 120);
    }
};

