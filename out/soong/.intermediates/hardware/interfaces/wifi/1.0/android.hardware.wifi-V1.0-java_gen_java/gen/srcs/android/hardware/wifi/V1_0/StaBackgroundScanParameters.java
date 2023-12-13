package android.hardware.wifi.V1_0;


public final class StaBackgroundScanParameters {
    /**
     * GCD of all bucket periods (in milliseconds).
     */
    public int basePeriodInMs = 0;
    /**
     * Maximum number of APs that must be stored for each scan. If the maximum
     * is reached the highest RSSI results must be returned.
     * Max length: |StaScanLimits.MAX_AP_CACHE_PER_SCAN|.
     */
    public int maxApPerScan = 0;
    /**
     * % cache buffer filled threshold at which the host must be notified of
     * batched scan results.
     */
    public int reportThresholdPercent = 0;
    /**
     * Threshold at which the AP must be woken up, in number of scans.
     */
    public int reportThresholdNumScans = 0;
    /**
     * List of buckets to be scheduled.
     * Max length: |StaScanLimits.MAX_BUCKETS|.
     */
    public java.util.ArrayList<android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters> buckets = new java.util.ArrayList<android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaBackgroundScanParameters.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaBackgroundScanParameters other = (android.hardware.wifi.V1_0.StaBackgroundScanParameters)otherObject;
        if (this.basePeriodInMs != other.basePeriodInMs) {
            return false;
        }
        if (this.maxApPerScan != other.maxApPerScan) {
            return false;
        }
        if (this.reportThresholdPercent != other.reportThresholdPercent) {
            return false;
        }
        if (this.reportThresholdNumScans != other.reportThresholdNumScans) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.buckets, other.buckets)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.basePeriodInMs), 
                android.os.HidlSupport.deepHashCode(this.maxApPerScan), 
                android.os.HidlSupport.deepHashCode(this.reportThresholdPercent), 
                android.os.HidlSupport.deepHashCode(this.reportThresholdNumScans), 
                android.os.HidlSupport.deepHashCode(this.buckets));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".basePeriodInMs = ");
        builder.append(this.basePeriodInMs);
        builder.append(", .maxApPerScan = ");
        builder.append(this.maxApPerScan);
        builder.append(", .reportThresholdPercent = ");
        builder.append(this.reportThresholdPercent);
        builder.append(", .reportThresholdNumScans = ");
        builder.append(this.reportThresholdNumScans);
        builder.append(", .buckets = ");
        builder.append(this.buckets);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaBackgroundScanParameters> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaBackgroundScanParameters> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaBackgroundScanParameters _hidl_vec_element = new android.hardware.wifi.V1_0.StaBackgroundScanParameters();
                ((android.hardware.wifi.V1_0.StaBackgroundScanParameters) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        basePeriodInMs = _hidl_blob.getInt32(_hidl_offset + 0);
        maxApPerScan = _hidl_blob.getInt32(_hidl_offset + 4);
        reportThresholdPercent = _hidl_blob.getInt32(_hidl_offset + 8);
        reportThresholdNumScans = _hidl_blob.getInt32(_hidl_offset + 12);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters>) buckets).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters _hidl_vec_element = new android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters();
                ((android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                ((java.util.ArrayList<android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters>) buckets).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaBackgroundScanParameters> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, basePeriodInMs);
        _hidl_blob.putInt32(_hidl_offset + 4, maxApPerScan);
        _hidl_blob.putInt32(_hidl_offset + 8, reportThresholdPercent);
        _hidl_blob.putInt32(_hidl_offset + 12, reportThresholdNumScans);
        {
            int _hidl_vec_size = buckets.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                buckets.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

