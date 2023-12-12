package android.hardware.gnss.measurement_corrections.V1_0;


public final class SingleSatCorrection {
    /**
     * Contains GnssSingleSatCorrectionFlags bits.
     */
    public short singleSatCorrectionFlags;
    /**
     * Defines the constellation of the given satellite.
     */
    public byte constellation = 0;
    /**
     * Satellite vehicle ID number, as defined in GnssSvInfo::svid
     */
    public short svid = 0;
    /**
     * Carrier frequency of the signal to be corrected, for example it can be the
     * GPS center frequency for L1 = 1,575,420,000 Hz, varying GLO channels, etc.
     *
     * For a receiver with capabilities to track multiple frequencies for the same satellite,
     * multiple corrections for the same satellite may be provided.
     */
    public float carrierFrequencyHz = 0.0f;
    /**
     * The probability that the satellite is estimated to be in Line-of-Sight condition at the given
     * location.
     */
    public float probSatIsLos = 0.0f;
    /**
     * Excess path length to be subtracted from pseudorange before using it in calculating location.
     *
     * Note this value is NOT to be used to adjust the GnssMeasurementCallback outputs.
     */
    public float excessPathLengthMeters = 0.0f;
    /**
     * Error estimate (1-sigma) for the Excess path length estimate
     */
    public float excessPathLengthUncertaintyMeters = 0.0f;
    /**
     * Defines the reflecting plane characteristics such as location and azimuth
     *
     * The value is only valid if HAS_REFLECTING_PLANE flag is set. An invalid reflecting plane
     * means either reflection planes serving is not supported or the satellite signal has gone
     * through multiple reflections.
     */
    public android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane reflectingPlane = new android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection.class) {
            return false;
        }
        android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection other = (android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.singleSatCorrectionFlags, other.singleSatCorrectionFlags)) {
            return false;
        }
        if (this.constellation != other.constellation) {
            return false;
        }
        if (this.svid != other.svid) {
            return false;
        }
        if (this.carrierFrequencyHz != other.carrierFrequencyHz) {
            return false;
        }
        if (this.probSatIsLos != other.probSatIsLos) {
            return false;
        }
        if (this.excessPathLengthMeters != other.excessPathLengthMeters) {
            return false;
        }
        if (this.excessPathLengthUncertaintyMeters != other.excessPathLengthUncertaintyMeters) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.reflectingPlane, other.reflectingPlane)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.singleSatCorrectionFlags), 
                android.os.HidlSupport.deepHashCode(this.constellation), 
                android.os.HidlSupport.deepHashCode(this.svid), 
                android.os.HidlSupport.deepHashCode(this.carrierFrequencyHz), 
                android.os.HidlSupport.deepHashCode(this.probSatIsLos), 
                android.os.HidlSupport.deepHashCode(this.excessPathLengthMeters), 
                android.os.HidlSupport.deepHashCode(this.excessPathLengthUncertaintyMeters), 
                android.os.HidlSupport.deepHashCode(this.reflectingPlane));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".singleSatCorrectionFlags = ");
        builder.append(android.hardware.gnss.measurement_corrections.V1_0.GnssSingleSatCorrectionFlags.dumpBitfield(this.singleSatCorrectionFlags));
        builder.append(", .constellation = ");
        builder.append(android.hardware.gnss.V1_0.GnssConstellationType.toString(this.constellation));
        builder.append(", .svid = ");
        builder.append(this.svid);
        builder.append(", .carrierFrequencyHz = ");
        builder.append(this.carrierFrequencyHz);
        builder.append(", .probSatIsLos = ");
        builder.append(this.probSatIsLos);
        builder.append(", .excessPathLengthMeters = ");
        builder.append(this.excessPathLengthMeters);
        builder.append(", .excessPathLengthUncertaintyMeters = ");
        builder.append(this.excessPathLengthUncertaintyMeters);
        builder.append(", .reflectingPlane = ");
        builder.append(this.reflectingPlane);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SingleSatCorrection> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SingleSatCorrection> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection();
                ((android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        singleSatCorrectionFlags = _hidl_blob.getInt16(_hidl_offset + 0);
        constellation = _hidl_blob.getInt8(_hidl_offset + 2);
        svid = _hidl_blob.getInt16(_hidl_offset + 4);
        carrierFrequencyHz = _hidl_blob.getFloat(_hidl_offset + 8);
        probSatIsLos = _hidl_blob.getFloat(_hidl_offset + 12);
        excessPathLengthMeters = _hidl_blob.getFloat(_hidl_offset + 16);
        excessPathLengthUncertaintyMeters = _hidl_blob.getFloat(_hidl_offset + 20);
        ((android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane) reflectingPlane).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 24);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SingleSatCorrection> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt16(_hidl_offset + 0, singleSatCorrectionFlags);
        _hidl_blob.putInt8(_hidl_offset + 2, constellation);
        _hidl_blob.putInt16(_hidl_offset + 4, svid);
        _hidl_blob.putFloat(_hidl_offset + 8, carrierFrequencyHz);
        _hidl_blob.putFloat(_hidl_offset + 12, probSatIsLos);
        _hidl_blob.putFloat(_hidl_offset + 16, excessPathLengthMeters);
        _hidl_blob.putFloat(_hidl_offset + 20, excessPathLengthUncertaintyMeters);
        reflectingPlane.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 24);
    }
};

