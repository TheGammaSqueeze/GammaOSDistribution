package android.hardware.wifi.V1_0;


public final class RttLciInformation {
    /**
     * latitude in degrees * 2^25 , 2's complement.
     */
    public long latitude = 0L;
    /**
     * longitude in degrees * 2^25 , 2's complement.
     */
    public long longitude = 0L;
    /**
     * Altitude in units of 1/256 m.
     */
    public int altitude = 0;
    /**
     * As defined in Section 2.3.2 of IETF RFC 6225.
     */
    public byte latitudeUnc = 0;
    /**
     * As defined in Section 2.3.2 of IETF RFC 6225.
     */
    public byte longitudeUnc = 0;
    /**
     * As defined in Section 2.4.5 from IETF RFC 6225.
     */
    public byte altitudeUnc = 0;
    /**
     * Following element for configuring the Z subelement.
     *
     *
     * Motion pattern type.
     */
    public int motionPattern = 0;
    /**
     * Floor in units of 1/16th of floor. 0x80000000 if unknown.
     */
    public int floor = 0;
    /**
     * in units of 1/64 m.
     */
    public int heightAboveFloor = 0;
    /**
     * in units of 1/64 m. 0 if unknown
     */
    public int heightUnc = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.RttLciInformation.class) {
            return false;
        }
        android.hardware.wifi.V1_0.RttLciInformation other = (android.hardware.wifi.V1_0.RttLciInformation)otherObject;
        if (this.latitude != other.latitude) {
            return false;
        }
        if (this.longitude != other.longitude) {
            return false;
        }
        if (this.altitude != other.altitude) {
            return false;
        }
        if (this.latitudeUnc != other.latitudeUnc) {
            return false;
        }
        if (this.longitudeUnc != other.longitudeUnc) {
            return false;
        }
        if (this.altitudeUnc != other.altitudeUnc) {
            return false;
        }
        if (this.motionPattern != other.motionPattern) {
            return false;
        }
        if (this.floor != other.floor) {
            return false;
        }
        if (this.heightAboveFloor != other.heightAboveFloor) {
            return false;
        }
        if (this.heightUnc != other.heightUnc) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.latitude), 
                android.os.HidlSupport.deepHashCode(this.longitude), 
                android.os.HidlSupport.deepHashCode(this.altitude), 
                android.os.HidlSupport.deepHashCode(this.latitudeUnc), 
                android.os.HidlSupport.deepHashCode(this.longitudeUnc), 
                android.os.HidlSupport.deepHashCode(this.altitudeUnc), 
                android.os.HidlSupport.deepHashCode(this.motionPattern), 
                android.os.HidlSupport.deepHashCode(this.floor), 
                android.os.HidlSupport.deepHashCode(this.heightAboveFloor), 
                android.os.HidlSupport.deepHashCode(this.heightUnc));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".latitude = ");
        builder.append(this.latitude);
        builder.append(", .longitude = ");
        builder.append(this.longitude);
        builder.append(", .altitude = ");
        builder.append(this.altitude);
        builder.append(", .latitudeUnc = ");
        builder.append(this.latitudeUnc);
        builder.append(", .longitudeUnc = ");
        builder.append(this.longitudeUnc);
        builder.append(", .altitudeUnc = ");
        builder.append(this.altitudeUnc);
        builder.append(", .motionPattern = ");
        builder.append(android.hardware.wifi.V1_0.RttMotionPattern.toString(this.motionPattern));
        builder.append(", .floor = ");
        builder.append(this.floor);
        builder.append(", .heightAboveFloor = ");
        builder.append(this.heightAboveFloor);
        builder.append(", .heightUnc = ");
        builder.append(this.heightUnc);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RttLciInformation> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RttLciInformation> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.RttLciInformation _hidl_vec_element = new android.hardware.wifi.V1_0.RttLciInformation();
                ((android.hardware.wifi.V1_0.RttLciInformation) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        latitude = _hidl_blob.getInt64(_hidl_offset + 0);
        longitude = _hidl_blob.getInt64(_hidl_offset + 8);
        altitude = _hidl_blob.getInt32(_hidl_offset + 16);
        latitudeUnc = _hidl_blob.getInt8(_hidl_offset + 20);
        longitudeUnc = _hidl_blob.getInt8(_hidl_offset + 21);
        altitudeUnc = _hidl_blob.getInt8(_hidl_offset + 22);
        motionPattern = _hidl_blob.getInt32(_hidl_offset + 24);
        floor = _hidl_blob.getInt32(_hidl_offset + 28);
        heightAboveFloor = _hidl_blob.getInt32(_hidl_offset + 32);
        heightUnc = _hidl_blob.getInt32(_hidl_offset + 36);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RttLciInformation> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt64(_hidl_offset + 0, latitude);
        _hidl_blob.putInt64(_hidl_offset + 8, longitude);
        _hidl_blob.putInt32(_hidl_offset + 16, altitude);
        _hidl_blob.putInt8(_hidl_offset + 20, latitudeUnc);
        _hidl_blob.putInt8(_hidl_offset + 21, longitudeUnc);
        _hidl_blob.putInt8(_hidl_offset + 22, altitudeUnc);
        _hidl_blob.putInt32(_hidl_offset + 24, motionPattern);
        _hidl_blob.putInt32(_hidl_offset + 28, floor);
        _hidl_blob.putInt32(_hidl_offset + 32, heightAboveFloor);
        _hidl_blob.putInt32(_hidl_offset + 36, heightUnc);
    }
};

