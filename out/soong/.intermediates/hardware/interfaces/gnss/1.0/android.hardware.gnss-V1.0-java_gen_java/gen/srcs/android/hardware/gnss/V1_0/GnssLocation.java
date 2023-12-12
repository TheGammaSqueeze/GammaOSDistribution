package android.hardware.gnss.V1_0;


public final class GnssLocation {
    /**
     * Contains GnssLocationFlags bits.
     */
    public short gnssLocationFlags;
    /**
     * Represents latitude in degrees.
     */
    public double latitudeDegrees = 0.0d;
    /**
     * Represents longitude in degrees.
     */
    public double longitudeDegrees = 0.0d;
    /**
     * Represents altitude in meters above the WGS 84 reference ellipsoid.
     */
    public double altitudeMeters = 0.0d;
    /**
     * Represents speed in meters per second.
     */
    public float speedMetersPerSec = 0.0f;
    /**
     * Represents heading in degrees.
     */
    public float bearingDegrees = 0.0f;
    /**
     * Represents expected horizontal position accuracy, radial, in meters
     * (68% confidence).
     */
    public float horizontalAccuracyMeters = 0.0f;
    /**
     * Represents expected vertical position accuracy in meters
     * (68% confidence).
     */
    public float verticalAccuracyMeters = 0.0f;
    /**
     * Represents expected speed accuracy in meter per seconds
     * (68% confidence).
     */
    public float speedAccuracyMetersPerSecond = 0.0f;
    /**
     * Represents expected bearing accuracy in degrees
     * (68% confidence).
     */
    public float bearingAccuracyDegrees = 0.0f;
    /**
     * Timestamp for the location fix.
     */
    public long timestamp = 0L;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.V1_0.GnssLocation.class) {
            return false;
        }
        android.hardware.gnss.V1_0.GnssLocation other = (android.hardware.gnss.V1_0.GnssLocation)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.gnssLocationFlags, other.gnssLocationFlags)) {
            return false;
        }
        if (this.latitudeDegrees != other.latitudeDegrees) {
            return false;
        }
        if (this.longitudeDegrees != other.longitudeDegrees) {
            return false;
        }
        if (this.altitudeMeters != other.altitudeMeters) {
            return false;
        }
        if (this.speedMetersPerSec != other.speedMetersPerSec) {
            return false;
        }
        if (this.bearingDegrees != other.bearingDegrees) {
            return false;
        }
        if (this.horizontalAccuracyMeters != other.horizontalAccuracyMeters) {
            return false;
        }
        if (this.verticalAccuracyMeters != other.verticalAccuracyMeters) {
            return false;
        }
        if (this.speedAccuracyMetersPerSecond != other.speedAccuracyMetersPerSecond) {
            return false;
        }
        if (this.bearingAccuracyDegrees != other.bearingAccuracyDegrees) {
            return false;
        }
        if (this.timestamp != other.timestamp) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.gnssLocationFlags), 
                android.os.HidlSupport.deepHashCode(this.latitudeDegrees), 
                android.os.HidlSupport.deepHashCode(this.longitudeDegrees), 
                android.os.HidlSupport.deepHashCode(this.altitudeMeters), 
                android.os.HidlSupport.deepHashCode(this.speedMetersPerSec), 
                android.os.HidlSupport.deepHashCode(this.bearingDegrees), 
                android.os.HidlSupport.deepHashCode(this.horizontalAccuracyMeters), 
                android.os.HidlSupport.deepHashCode(this.verticalAccuracyMeters), 
                android.os.HidlSupport.deepHashCode(this.speedAccuracyMetersPerSecond), 
                android.os.HidlSupport.deepHashCode(this.bearingAccuracyDegrees), 
                android.os.HidlSupport.deepHashCode(this.timestamp));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".gnssLocationFlags = ");
        builder.append(android.hardware.gnss.V1_0.GnssLocationFlags.dumpBitfield(this.gnssLocationFlags));
        builder.append(", .latitudeDegrees = ");
        builder.append(this.latitudeDegrees);
        builder.append(", .longitudeDegrees = ");
        builder.append(this.longitudeDegrees);
        builder.append(", .altitudeMeters = ");
        builder.append(this.altitudeMeters);
        builder.append(", .speedMetersPerSec = ");
        builder.append(this.speedMetersPerSec);
        builder.append(", .bearingDegrees = ");
        builder.append(this.bearingDegrees);
        builder.append(", .horizontalAccuracyMeters = ");
        builder.append(this.horizontalAccuracyMeters);
        builder.append(", .verticalAccuracyMeters = ");
        builder.append(this.verticalAccuracyMeters);
        builder.append(", .speedAccuracyMetersPerSecond = ");
        builder.append(this.speedAccuracyMetersPerSecond);
        builder.append(", .bearingAccuracyDegrees = ");
        builder.append(this.bearingAccuracyDegrees);
        builder.append(", .timestamp = ");
        builder.append(this.timestamp);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<GnssLocation> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<GnssLocation> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.V1_0.GnssLocation _hidl_vec_element = new android.hardware.gnss.V1_0.GnssLocation();
                ((android.hardware.gnss.V1_0.GnssLocation) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        gnssLocationFlags = _hidl_blob.getInt16(_hidl_offset + 0);
        latitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 8);
        longitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 16);
        altitudeMeters = _hidl_blob.getDouble(_hidl_offset + 24);
        speedMetersPerSec = _hidl_blob.getFloat(_hidl_offset + 32);
        bearingDegrees = _hidl_blob.getFloat(_hidl_offset + 36);
        horizontalAccuracyMeters = _hidl_blob.getFloat(_hidl_offset + 40);
        verticalAccuracyMeters = _hidl_blob.getFloat(_hidl_offset + 44);
        speedAccuracyMetersPerSecond = _hidl_blob.getFloat(_hidl_offset + 48);
        bearingAccuracyDegrees = _hidl_blob.getFloat(_hidl_offset + 52);
        timestamp = _hidl_blob.getInt64(_hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<GnssLocation> _hidl_vec) {
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
        _hidl_blob.putInt16(_hidl_offset + 0, gnssLocationFlags);
        _hidl_blob.putDouble(_hidl_offset + 8, latitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 16, longitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 24, altitudeMeters);
        _hidl_blob.putFloat(_hidl_offset + 32, speedMetersPerSec);
        _hidl_blob.putFloat(_hidl_offset + 36, bearingDegrees);
        _hidl_blob.putFloat(_hidl_offset + 40, horizontalAccuracyMeters);
        _hidl_blob.putFloat(_hidl_offset + 44, verticalAccuracyMeters);
        _hidl_blob.putFloat(_hidl_offset + 48, speedAccuracyMetersPerSecond);
        _hidl_blob.putFloat(_hidl_offset + 52, bearingAccuracyDegrees);
        _hidl_blob.putInt64(_hidl_offset + 56, timestamp);
    }
};

