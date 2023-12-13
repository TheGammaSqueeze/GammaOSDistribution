package android.hardware.radio.V1_2;


public final class CellInfoCdma {
    public android.hardware.radio.V1_2.CellIdentityCdma cellIdentityCdma = new android.hardware.radio.V1_2.CellIdentityCdma();
    public android.hardware.radio.V1_0.CdmaSignalStrength signalStrengthCdma = new android.hardware.radio.V1_0.CdmaSignalStrength();
    public android.hardware.radio.V1_0.EvdoSignalStrength signalStrengthEvdo = new android.hardware.radio.V1_0.EvdoSignalStrength();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.CellInfoCdma.class) {
            return false;
        }
        android.hardware.radio.V1_2.CellInfoCdma other = (android.hardware.radio.V1_2.CellInfoCdma)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityCdma, other.cellIdentityCdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalStrengthCdma, other.signalStrengthCdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalStrengthEvdo, other.signalStrengthEvdo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellIdentityCdma), 
                android.os.HidlSupport.deepHashCode(this.signalStrengthCdma), 
                android.os.HidlSupport.deepHashCode(this.signalStrengthEvdo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellIdentityCdma = ");
        builder.append(this.cellIdentityCdma);
        builder.append(", .signalStrengthCdma = ");
        builder.append(this.signalStrengthCdma);
        builder.append(", .signalStrengthEvdo = ");
        builder.append(this.signalStrengthEvdo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(80 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfoCdma> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfoCdma> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 80,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoCdma _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoCdma();
                ((android.hardware.radio.V1_2.CellInfoCdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_2.CellIdentityCdma) cellIdentityCdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_0.CdmaSignalStrength) signalStrengthCdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 56);
        ((android.hardware.radio.V1_0.EvdoSignalStrength) signalStrengthEvdo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(80 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfoCdma> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellIdentityCdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        signalStrengthCdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 56);
        signalStrengthEvdo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 64);
    }
};

