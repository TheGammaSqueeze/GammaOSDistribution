package android.hardware.gnss.measurement_corrections.V1_1;


public final class MeasurementCorrections {
    public android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections v1_0 = new android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections();
    /**
     * Boolean indicating if environment bearing is available.
     */
    public boolean hasEnvironmentBearing = false;
    /**
     * Environment bearing in degrees clockwise from true North (0.0 to 360.0], in direction of
     * user motion. Environment bearing is provided when it is known with high probability that
     * velocity is aligned with an environment feature, such as a building or road.
     *
     * If user speed is zero, environmentBearingDegrees represents bearing of most recent speed
     * that was > 0.
     *
     * As position approaches another road, environmentBearingUncertaintyDegrees will grow, and at
     * some stage hasEnvironmentBearing = false.
     *
     * As position moves towards an open area, environmentBearingUncertaintyDegrees will grow, and
     * at some stage hasEnvironmentBearing = false.
     *
     * If the road is curved in the vicinity of the user location, then
     * environmentBearingUncertaintyDegrees will include the amount by which the road direction
     * changes in the area of position uncertainty.
     *
     * hasEnvironmentBearing should be checked to verify the environment bearing is available
     * before calling this method. The value is undefined if hasEnvironmentBearing is false.
     */
    public float environmentBearingDegrees = 0.0f;
    /**
     * Environment bearing uncertainty [0 to 180]. It represents the standard deviation of the
     * physical structure in the circle of position uncertainty. hasEnvironmentBearing becomes false
     * as the uncertainty value passes a predefined threshold depending on the physical structure
     * around the user.
     *
     * hasEnvironmentBearing should be checked to verify the environment bearing is available
     * before calling this method. The value is undefined if hasEnvironmentBearing is false.
     */
    public float environmentBearingUncertaintyDegrees = 0.0f;
    /**
     * A set of SingleSatCorrection each containing measurement corrections for a satellite in view
     */
    public java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection> satCorrections = new java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections.class) {
            return false;
        }
        android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections other = (android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.v1_0, other.v1_0)) {
            return false;
        }
        if (this.hasEnvironmentBearing != other.hasEnvironmentBearing) {
            return false;
        }
        if (this.environmentBearingDegrees != other.environmentBearingDegrees) {
            return false;
        }
        if (this.environmentBearingUncertaintyDegrees != other.environmentBearingUncertaintyDegrees) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.satCorrections, other.satCorrections)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.v1_0), 
                android.os.HidlSupport.deepHashCode(this.hasEnvironmentBearing), 
                android.os.HidlSupport.deepHashCode(this.environmentBearingDegrees), 
                android.os.HidlSupport.deepHashCode(this.environmentBearingUncertaintyDegrees), 
                android.os.HidlSupport.deepHashCode(this.satCorrections));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".v1_0 = ");
        builder.append(this.v1_0);
        builder.append(", .hasEnvironmentBearing = ");
        builder.append(this.hasEnvironmentBearing);
        builder.append(", .environmentBearingDegrees = ");
        builder.append(this.environmentBearingDegrees);
        builder.append(", .environmentBearingUncertaintyDegrees = ");
        builder.append(this.environmentBearingUncertaintyDegrees);
        builder.append(", .satCorrections = ");
        builder.append(this.satCorrections);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(96 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<MeasurementCorrections> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<MeasurementCorrections> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections();
                ((android.hardware.gnss.measurement_corrections.V1_1.MeasurementCorrections) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections) v1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        hasEnvironmentBearing = _hidl_blob.getBool(_hidl_offset + 64);
        environmentBearingDegrees = _hidl_blob.getFloat(_hidl_offset + 68);
        environmentBearingUncertaintyDegrees = _hidl_blob.getFloat(_hidl_offset + 72);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection>) satCorrections).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection();
                ((android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                ((java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_1.SingleSatCorrection>) satCorrections).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(96 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<MeasurementCorrections> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        v1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putBool(_hidl_offset + 64, hasEnvironmentBearing);
        _hidl_blob.putFloat(_hidl_offset + 68, environmentBearingDegrees);
        _hidl_blob.putFloat(_hidl_offset + 72, environmentBearingUncertaintyDegrees);
        {
            int _hidl_vec_size = satCorrections.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                satCorrections.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

