package android.hardware.gnss.measurement_corrections.V1_0;


public final class ReflectingPlane {
    /**
     * Represents latitude of the reflecting plane in degrees.
     */
    public double latitudeDegrees = 0.0d;
    /**
     * Represents longitude of the reflecting plane in degrees.
     */
    public double longitudeDegrees = 0.0d;
    /**
     * Represents altitude of the reflecting point in the plane in meters above the WGS 84 reference
     * ellipsoid.
     */
    public double altitudeMeters = 0.0d;
    /**
     * Represents azimuth clockwise from north of the reflecting plane in degrees.
     */
    public double azimuthDegrees = 0.0d;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane.class) {
            return false;
        }
        android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane other = (android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane)otherObject;
        if (this.latitudeDegrees != other.latitudeDegrees) {
            return false;
        }
        if (this.longitudeDegrees != other.longitudeDegrees) {
            return false;
        }
        if (this.altitudeMeters != other.altitudeMeters) {
            return false;
        }
        if (this.azimuthDegrees != other.azimuthDegrees) {
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
                android.os.HidlSupport.deepHashCode(this.azimuthDegrees));
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
        builder.append(", .azimuthDegrees = ");
        builder.append(this.azimuthDegrees);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ReflectingPlane> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ReflectingPlane> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane _hidl_vec_element = new android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane();
                ((android.hardware.gnss.measurement_corrections.V1_0.ReflectingPlane) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
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
        azimuthDegrees = _hidl_blob.getDouble(_hidl_offset + 24);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ReflectingPlane> _hidl_vec) {
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
        _hidl_blob.putDouble(_hidl_offset + 0, latitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 8, longitudeDegrees);
        _hidl_blob.putDouble(_hidl_offset + 16, altitudeMeters);
        _hidl_blob.putDouble(_hidl_offset + 24, azimuthDegrees);
    }
};

