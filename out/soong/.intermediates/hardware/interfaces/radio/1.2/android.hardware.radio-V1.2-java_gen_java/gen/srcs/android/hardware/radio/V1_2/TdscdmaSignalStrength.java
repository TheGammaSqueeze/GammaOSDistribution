package android.hardware.radio.V1_2;


public final class TdscdmaSignalStrength {
    /**
     * UTRA carrier RSSI as defined in TS 25.225 5.1.4
     * Valid values are (0-31, 99) as defined in TS 27.007 8.5
     * INT_MAX denotes that the value is invalid/unreported.
     */
    public int signalStrength = 0;
    /**
     * Transport Channel BER as defined in TS 25.225 5.2.5
     * Valid values are (0-7, 99) as defined in TS 27.007 8.5
     * INT_MAX denotes that the value is invalid/unreported.
     */
    public int bitErrorRate = 0;
    /**
     * P-CCPCH RSCP as defined in TS 25.225 5.1.1
     * Valid values are (0-96, 255) as defined in TS 27.007 8.69
     * INT_MAX denotes that the value is invalid/unreported.
     */
    public int rscp = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.TdscdmaSignalStrength.class) {
            return false;
        }
        android.hardware.radio.V1_2.TdscdmaSignalStrength other = (android.hardware.radio.V1_2.TdscdmaSignalStrength)otherObject;
        if (this.signalStrength != other.signalStrength) {
            return false;
        }
        if (this.bitErrorRate != other.bitErrorRate) {
            return false;
        }
        if (this.rscp != other.rscp) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.signalStrength), 
                android.os.HidlSupport.deepHashCode(this.bitErrorRate), 
                android.os.HidlSupport.deepHashCode(this.rscp));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".signalStrength = ");
        builder.append(this.signalStrength);
        builder.append(", .bitErrorRate = ");
        builder.append(this.bitErrorRate);
        builder.append(", .rscp = ");
        builder.append(this.rscp);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<TdscdmaSignalStrength> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<TdscdmaSignalStrength> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.TdscdmaSignalStrength _hidl_vec_element = new android.hardware.radio.V1_2.TdscdmaSignalStrength();
                ((android.hardware.radio.V1_2.TdscdmaSignalStrength) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        signalStrength = _hidl_blob.getInt32(_hidl_offset + 0);
        bitErrorRate = _hidl_blob.getInt32(_hidl_offset + 4);
        rscp = _hidl_blob.getInt32(_hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<TdscdmaSignalStrength> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, signalStrength);
        _hidl_blob.putInt32(_hidl_offset + 4, bitErrorRate);
        _hidl_blob.putInt32(_hidl_offset + 8, rscp);
    }
};

