package android.hardware.radio.V1_5;


public final class CellInfoLte {
    public android.hardware.radio.V1_5.CellIdentityLte cellIdentityLte = new android.hardware.radio.V1_5.CellIdentityLte();
    public android.hardware.radio.V1_0.LteSignalStrength signalStrengthLte = new android.hardware.radio.V1_0.LteSignalStrength();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.CellInfoLte.class) {
            return false;
        }
        android.hardware.radio.V1_5.CellInfoLte other = (android.hardware.radio.V1_5.CellInfoLte)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityLte, other.cellIdentityLte)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalStrengthLte, other.signalStrengthLte)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellIdentityLte), 
                android.os.HidlSupport.deepHashCode(this.signalStrengthLte));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellIdentityLte = ");
        builder.append(this.cellIdentityLte);
        builder.append(", .signalStrengthLte = ");
        builder.append(this.signalStrengthLte);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(184 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfoLte> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfoLte> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 184,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.CellInfoLte _hidl_vec_element = new android.hardware.radio.V1_5.CellInfoLte();
                ((android.hardware.radio.V1_5.CellInfoLte) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 184);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_5.CellIdentityLte) cellIdentityLte).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_0.LteSignalStrength) signalStrengthLte).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 160);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(184 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfoLte> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 184));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 184);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellIdentityLte.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        signalStrengthLte.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 160);
    }
};

