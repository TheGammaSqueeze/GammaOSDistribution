package android.hardware.radio.V1_2;


public final class WcdmaSignalStrength {
    public android.hardware.radio.V1_0.WcdmaSignalStrength base = new android.hardware.radio.V1_0.WcdmaSignalStrength();
    /**
     * CPICH RSCP as defined in TS 25.215 5.1.1
     * Valid values are (0-96, 255) as defined in TS 27.007 8.69
     * INT_MAX denotes that the value is invalid/unreported.
     */
    public int rscp = 0;
    /**
     * Ec/No value as defined in TS 25.215 5.1.5
     * Valid values are (0-49, 255) as defined in TS 27.007 8.69
     * INT_MAX denotes that the value is invalid/unreported.
     */
    public int ecno = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.WcdmaSignalStrength.class) {
            return false;
        }
        android.hardware.radio.V1_2.WcdmaSignalStrength other = (android.hardware.radio.V1_2.WcdmaSignalStrength)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.base, other.base)) {
            return false;
        }
        if (this.rscp != other.rscp) {
            return false;
        }
        if (this.ecno != other.ecno) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.base), 
                android.os.HidlSupport.deepHashCode(this.rscp), 
                android.os.HidlSupport.deepHashCode(this.ecno));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".base = ");
        builder.append(this.base);
        builder.append(", .rscp = ");
        builder.append(this.rscp);
        builder.append(", .ecno = ");
        builder.append(this.ecno);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WcdmaSignalStrength> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WcdmaSignalStrength> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.WcdmaSignalStrength _hidl_vec_element = new android.hardware.radio.V1_2.WcdmaSignalStrength();
                ((android.hardware.radio.V1_2.WcdmaSignalStrength) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_0.WcdmaSignalStrength) base).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        rscp = _hidl_blob.getInt32(_hidl_offset + 8);
        ecno = _hidl_blob.getInt32(_hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WcdmaSignalStrength> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        base.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 8, rscp);
        _hidl_blob.putInt32(_hidl_offset + 12, ecno);
    }
};

