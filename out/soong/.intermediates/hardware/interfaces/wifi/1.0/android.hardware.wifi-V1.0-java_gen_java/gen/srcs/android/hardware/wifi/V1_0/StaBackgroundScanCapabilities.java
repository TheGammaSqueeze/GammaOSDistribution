package android.hardware.wifi.V1_0;


public final class StaBackgroundScanCapabilities {
    /**
     * Maximum number of byte available for cached scan results
     */
    public int maxCacheSize = 0;
    /**
     * Maximum number of buckets that can be supplied for a scan
     */
    public int maxBuckets = 0;
    /**
     * Maximum number of APs that must be stored for each scan.
     */
    public int maxApCachePerScan = 0;
    /**
     * Max reporting number of scans threshold that can be specified in the scan
     * parameters.
     */
    public int maxReportingThreshold = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaBackgroundScanCapabilities.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaBackgroundScanCapabilities other = (android.hardware.wifi.V1_0.StaBackgroundScanCapabilities)otherObject;
        if (this.maxCacheSize != other.maxCacheSize) {
            return false;
        }
        if (this.maxBuckets != other.maxBuckets) {
            return false;
        }
        if (this.maxApCachePerScan != other.maxApCachePerScan) {
            return false;
        }
        if (this.maxReportingThreshold != other.maxReportingThreshold) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maxCacheSize), 
                android.os.HidlSupport.deepHashCode(this.maxBuckets), 
                android.os.HidlSupport.deepHashCode(this.maxApCachePerScan), 
                android.os.HidlSupport.deepHashCode(this.maxReportingThreshold));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maxCacheSize = ");
        builder.append(this.maxCacheSize);
        builder.append(", .maxBuckets = ");
        builder.append(this.maxBuckets);
        builder.append(", .maxApCachePerScan = ");
        builder.append(this.maxApCachePerScan);
        builder.append(", .maxReportingThreshold = ");
        builder.append(this.maxReportingThreshold);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaBackgroundScanCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaBackgroundScanCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaBackgroundScanCapabilities _hidl_vec_element = new android.hardware.wifi.V1_0.StaBackgroundScanCapabilities();
                ((android.hardware.wifi.V1_0.StaBackgroundScanCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maxCacheSize = _hidl_blob.getInt32(_hidl_offset + 0);
        maxBuckets = _hidl_blob.getInt32(_hidl_offset + 4);
        maxApCachePerScan = _hidl_blob.getInt32(_hidl_offset + 8);
        maxReportingThreshold = _hidl_blob.getInt32(_hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaBackgroundScanCapabilities> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, maxCacheSize);
        _hidl_blob.putInt32(_hidl_offset + 4, maxBuckets);
        _hidl_blob.putInt32(_hidl_offset + 8, maxApCachePerScan);
        _hidl_blob.putInt32(_hidl_offset + 12, maxReportingThreshold);
    }
};

