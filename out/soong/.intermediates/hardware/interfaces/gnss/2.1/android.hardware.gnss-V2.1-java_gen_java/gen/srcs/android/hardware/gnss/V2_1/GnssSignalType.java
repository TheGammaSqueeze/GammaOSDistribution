package android.hardware.gnss.V2_1;


public final class GnssSignalType {
    /**
     * Constellation type of the SV that transmits the signal.
     */
    public byte constellation = 0;
    /**
     * Carrier frequency in Hz of the signal.
     */
    public double carrierFrequencyHz = 0.0d;
    /**
     * The type of code of the GNSS signal.
     *
     * This is used to specify the observation descriptor defined in GNSS Observation Data File
     * Header Section Description in the RINEX standard (Version 3.XX). In RINEX Version 3.03,
     * in Appendix Table A2 Attributes are listed as uppercase letters (for instance, "A" for
     * "A channel").
     *
     * See the comment of @2.0::IGnssMeasurementCallback.GnssMeasurement.codeType for more details.
     */
    public String codeType = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.V2_1.GnssSignalType.class) {
            return false;
        }
        android.hardware.gnss.V2_1.GnssSignalType other = (android.hardware.gnss.V2_1.GnssSignalType)otherObject;
        if (this.constellation != other.constellation) {
            return false;
        }
        if (this.carrierFrequencyHz != other.carrierFrequencyHz) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.codeType, other.codeType)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.constellation), 
                android.os.HidlSupport.deepHashCode(this.carrierFrequencyHz), 
                android.os.HidlSupport.deepHashCode(this.codeType));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".constellation = ");
        builder.append(android.hardware.gnss.V2_0.GnssConstellationType.toString(this.constellation));
        builder.append(", .carrierFrequencyHz = ");
        builder.append(this.carrierFrequencyHz);
        builder.append(", .codeType = ");
        builder.append(this.codeType);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<GnssSignalType> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<GnssSignalType> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.V2_1.GnssSignalType _hidl_vec_element = new android.hardware.gnss.V2_1.GnssSignalType();
                ((android.hardware.gnss.V2_1.GnssSignalType) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        constellation = _hidl_blob.getInt8(_hidl_offset + 0);
        carrierFrequencyHz = _hidl_blob.getDouble(_hidl_offset + 8);
        codeType = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) codeType).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<GnssSignalType> _hidl_vec) {
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
        _hidl_blob.putInt8(_hidl_offset + 0, constellation);
        _hidl_blob.putDouble(_hidl_offset + 8, carrierFrequencyHz);
        _hidl_blob.putString(_hidl_offset + 16, codeType);
    }
};

