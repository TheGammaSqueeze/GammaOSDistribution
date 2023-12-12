package android.hardware.gnss.measurement_corrections.V1_0;


public final class MeasurementCorrections {
    /**
     * Represents latitude in degrees at which the corrections are computed..
     */
    public double latitudeDegrees = 0.0d;
    /**
     * Represents longitude in degrees at which the corrections are computed..
     */
    public double longitudeDegrees = 0.0d;
    /**
     * Represents altitude in meters above the WGS 84 reference ellipsoid at which the corrections
     * are computed.
     */
    public double altitudeMeters = 0.0d;
    /**
     * Represents the horizontal uncertainty (63% to 68% confidence) in meters on the device
     * position at which the corrections are provided.
     *
     * This value is useful for example to judge how accurate the provided corrections are.
     */
    public double horizontalPositionUncertaintyMeters = 0.0d;
    /**
     * Represents the vertical uncertainty (63% to 68% confidence) in meters on the device position
     * at which the corrections are provided.
     *
     * This value is useful for example to judge how accurate the provided corrections are.
     */
    public double verticalPositionUncertaintyMeters = 0.0d;
    /**
     * Time Of Applicability, GPS time of week in nanoseconds.
     */
    public long toaGpsNanosecondsOfWeek = 0L;
    /**
     * A set of SingleSatCorrection each containing measurement corrections for a satellite in view
     */
    public java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection> satCorrections = new java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections.class) {
            return false;
        }
        android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections other = (android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections)otherObject;
        if (this.latitudeDegrees != other.latitudeDegrees) {
            return false;
        }
        if (this.longitudeDegrees != other.longitudeDegrees) {
            return false;
        }
        if (this.altitudeMeters != other.altitudeMeters) {
            return false;
        }
        if (this.horizontalPositionUncertaintyMeters != other.horizontalPositionUncertaintyMeters) {
            return false;
        }
        if (this.verticalPositionUncertaintyMeters != other.verticalPositionUncertaintyMeters) {
            return false;
        }
        if (this.toaGpsNanosecondsOfWeek != other.toaGpsNanosecondsOfWeek) {
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
                android.os.HidlSupport.deepHashCode(this.latitudeDegrees), 
                android.os.HidlSupport.deepHashCode(this.longitudeDegrees), 
                android.os.HidlSupport.deepHashCode(this.altitudeMeters), 
                android.os.HidlSupport.deepHashCode(this.horizontalPositionUncertaintyMeters), 
                android.os.HidlSupport.deepHashCode(this.verticalPositionUncertaintyMeters), 
                android.os.HidlSupport.deepHashCode(this.toaGpsNanosecondsOfWeek), 
                android.os.HidlSupport.deepHashCode(this.satCorrections));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".latitudeDegrees = ");
        builder.append(this.latitudeDegrees);
        builder.append(", .longitudeDegrees = ");
        builder.append(this.longitudeDegrees);
        builder.append(", .altitudeMeters = ");
        builder.append(this.altitudeMeters);
        builder.append(", .horizontalPositionUncertaintyMeters = ");
        builder.append(this.horizontalPositionUncertaintyMeters);
        builder.append(", .verticalPositionUncertaintyMeters = ");
        builder.append(this.verticalPositionUncertaintyMeters);
        builder.append(", .toaGpsNanosecondsOfWeek = ");
        builder.append(this.toaGpsNanosecondsOfWeek);
        builder.append(", .satCorrections = ");
        builder.append(this.satCorrections);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<MeasurementCorrections> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<MeasurementCorrections> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections();
                ((android.hardware.gnss.measurement_corrections.V1_0.MeasurementCorrections) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        latitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 0);
        longitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 8);
        altitudeMeters = _hidl_blob.getDouble(_hidl_offset + 16);
        horizontalPositionUncertaintyMeters = _hidl_blob.getDouble(_hidl_offset + 24);
        verticalPositionUncertaintyMeters = _hidl_blob.getDouble(_hidl_offset + 32);
        toaGpsNanosecondsOfWeek = _hidl_blob.getInt64(_hidl_offset + 40);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection>) satCorrections).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection();
                ((android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                ((java.util.ArrayList<android.hardware.gnss.measurement_corrections.V1_0.SingleSatCorrection>) satCorrections).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putDouble(_hidl_offset + 0, latitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 8, longitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 16, altitudeMeters);
        _hidl_blob.putDouble(_hidl_offset + 24, horizontalPositionUncertaintyMeters);
        _hidl_blob.putDouble(_hidl_offset + 32, verticalPositionUncertaintyMeters);
        _hidl_blob.putInt64(_hidl_offset + 40, toaGpsNanosecondsOfWeek);
        {
            int _hidl_vec_size = satCorrections.size();
            _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                satCorrections.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

