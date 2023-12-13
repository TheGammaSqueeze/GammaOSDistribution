package android.hardware.wifi.V1_5;


public final class StaPeerInfo {
    /**
     * Station count: The total number of stations currently associated with the peer.
     */
    public short staCount = 0;
    /**
     * Channel utilization: The percentage of time (normalized to 255, i.e., x% corresponds to
     * (int) x * 255 / 100) that the medium is sensed as busy measured by either physical or
     * virtual carrier sense (CS) mechanism.
     */
    public short chanUtil = 0;
    /**
     * Per rate statistics
     */
    public java.util.ArrayList<android.hardware.wifi.V1_5.StaRateStat> rateStats = new java.util.ArrayList<android.hardware.wifi.V1_5.StaRateStat>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_5.StaPeerInfo.class) {
            return false;
        }
        android.hardware.wifi.V1_5.StaPeerInfo other = (android.hardware.wifi.V1_5.StaPeerInfo)otherObject;
        if (this.staCount != other.staCount) {
            return false;
        }
        if (this.chanUtil != other.chanUtil) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rateStats, other.rateStats)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.staCount), 
                android.os.HidlSupport.deepHashCode(this.chanUtil), 
                android.os.HidlSupport.deepHashCode(this.rateStats));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".staCount = ");
        builder.append(this.staCount);
        builder.append(", .chanUtil = ");
        builder.append(this.chanUtil);
        builder.append(", .rateStats = ");
        builder.append(this.rateStats);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaPeerInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaPeerInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.StaPeerInfo _hidl_vec_element = new android.hardware.wifi.V1_5.StaPeerInfo();
                ((android.hardware.wifi.V1_5.StaPeerInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        staCount = _hidl_blob.getInt16(_hidl_offset + 0);
        chanUtil = _hidl_blob.getInt16(_hidl_offset + 2);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 36,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_5.StaRateStat>) rateStats).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.StaRateStat _hidl_vec_element = new android.hardware.wifi.V1_5.StaRateStat();
                ((android.hardware.wifi.V1_5.StaRateStat) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 36);
                ((java.util.ArrayList<android.hardware.wifi.V1_5.StaRateStat>) rateStats).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaPeerInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt16(_hidl_offset + 0, staCount);
        _hidl_blob.putInt16(_hidl_offset + 2, chanUtil);
        {
            int _hidl_vec_size = rateStats.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 36));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                rateStats.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 36);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

