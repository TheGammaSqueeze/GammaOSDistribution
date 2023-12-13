package android.hardware.gnss.V2_0;


public final class GnssLocation {
    public android.hardware.gnss.V1_0.GnssLocation v1_0 = new android.hardware.gnss.V1_0.GnssLocation();
    /**
     * Timing information of the GNSS location synchronized with SystemClock.elapsedRealtimeNanos()
     * clock.
     *
     * This clock information can be obtained from SystemClock.elapsedRealtimeNanos(), when the GNSS
     * is attached straight to the AP/SOC. When it is attached to a separate module the timestamp
     * needs to be estimated by syncing the notion of time via PTP or some other mechanism.
     */
    public android.hardware.gnss.V2_0.ElapsedRealtime elapsedRealtime = new android.hardware.gnss.V2_0.ElapsedRealtime();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.gnss.V2_0.GnssLocation.class) {
            return false;
        }
        android.hardware.gnss.V2_0.GnssLocation other = (android.hardware.gnss.V2_0.GnssLocation)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.v1_0, other.v1_0)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.elapsedRealtime, other.elapsedRealtime)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.v1_0), 
                android.os.HidlSupport.deepHashCode(this.elapsedRealtime));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".v1_0 = ");
        builder.append(this.v1_0);
        builder.append(", .elapsedRealtime = ");
        builder.append(this.elapsedRealtime);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<GnssLocation> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<GnssLocation> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.gnss.V2_0.GnssLocation _hidl_vec_element = new android.hardware.gnss.V2_0.GnssLocation();
                ((android.hardware.gnss.V2_0.GnssLocation) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.gnss.V1_0.GnssLocation) v1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.gnss.V2_0.ElapsedRealtime) elapsedRealtime).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        v1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        elapsedRealtime.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 64);
    }
};

