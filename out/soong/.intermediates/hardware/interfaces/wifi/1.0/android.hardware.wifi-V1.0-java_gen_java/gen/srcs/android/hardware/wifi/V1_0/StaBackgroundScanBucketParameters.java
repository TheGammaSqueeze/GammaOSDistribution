package android.hardware.wifi.V1_0;


public final class StaBackgroundScanBucketParameters {
    /**
     * Bucket index. This index is used to report results in
     * |StaScanData.bucketsScanned|.
     */
    public int bucketIdx = 0;
    /**
     * Bands to scan or |BAND_UNSPECIFIED| if frequencies list must be used
     * instead.
     */
    public int band = 0;
    /**
     * Channel frequencies (in Mhz) to scan if |band| is set to
     * |BAND_UNSPECIFIED|.
     * Max length: |StaScanLimits.MAX_CHANNELS|.
     */
    public java.util.ArrayList<Integer> frequencies = new java.util.ArrayList<Integer>();
    /**
     * Period at which this bucket must be scanned (in milliseconds). Must be an integer
     * multiple of the |basePeriodInMs| specified in the BackgroundScanParameters.
     */
    public int periodInMs = 0;
    /**
     * Bitset of |StaBackgroundScanBucketEventReportSchemeMask| values controlling
     * when events for this bucket must be reported.
     */
    public int eventReportScheme;
    /**
     * For exponential back off. If |exponentialMaxPeriodInMs| is non zero or
     * different than period, then this bucket is an exponential backoff bucket
     * and the scan period must grow exponentially as per formula:
     *   actual_period(N) = period * (base ^ (N/step_count))
     * to this maximum period (in milliseconds).
     */
    public int exponentialMaxPeriodInMs = 0;
    /**
     * For exponential back off. multiplier: new_period=old_period * base
     */
    public int exponentialBase = 0;
    /**
     * For exponential back off. Number of scans to perform for a given
     * period.
     */
    public int exponentialStepCount = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters other = (android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters)otherObject;
        if (this.bucketIdx != other.bucketIdx) {
            return false;
        }
        if (this.band != other.band) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.frequencies, other.frequencies)) {
            return false;
        }
        if (this.periodInMs != other.periodInMs) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.eventReportScheme, other.eventReportScheme)) {
            return false;
        }
        if (this.exponentialMaxPeriodInMs != other.exponentialMaxPeriodInMs) {
            return false;
        }
        if (this.exponentialBase != other.exponentialBase) {
            return false;
        }
        if (this.exponentialStepCount != other.exponentialStepCount) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.bucketIdx), 
                android.os.HidlSupport.deepHashCode(this.band), 
                android.os.HidlSupport.deepHashCode(this.frequencies), 
                android.os.HidlSupport.deepHashCode(this.periodInMs), 
                android.os.HidlSupport.deepHashCode(this.eventReportScheme), 
                android.os.HidlSupport.deepHashCode(this.exponentialMaxPeriodInMs), 
                android.os.HidlSupport.deepHashCode(this.exponentialBase), 
                android.os.HidlSupport.deepHashCode(this.exponentialStepCount));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".bucketIdx = ");
        builder.append(this.bucketIdx);
        builder.append(", .band = ");
        builder.append(android.hardware.wifi.V1_0.WifiBand.toString(this.band));
        builder.append(", .frequencies = ");
        builder.append(this.frequencies);
        builder.append(", .periodInMs = ");
        builder.append(this.periodInMs);
        builder.append(", .eventReportScheme = ");
        builder.append(android.hardware.wifi.V1_0.StaBackgroundScanBucketEventReportSchemeMask.dumpBitfield(this.eventReportScheme));
        builder.append(", .exponentialMaxPeriodInMs = ");
        builder.append(this.exponentialMaxPeriodInMs);
        builder.append(", .exponentialBase = ");
        builder.append(this.exponentialBase);
        builder.append(", .exponentialStepCount = ");
        builder.append(this.exponentialStepCount);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaBackgroundScanBucketParameters> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaBackgroundScanBucketParameters> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters _hidl_vec_element = new android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters();
                ((android.hardware.wifi.V1_0.StaBackgroundScanBucketParameters) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        bucketIdx = _hidl_blob.getInt32(_hidl_offset + 0);
        band = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) frequencies).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) frequencies).add(_hidl_vec_element);
            }
        }
        periodInMs = _hidl_blob.getInt32(_hidl_offset + 24);
        eventReportScheme = _hidl_blob.getInt32(_hidl_offset + 28);
        exponentialMaxPeriodInMs = _hidl_blob.getInt32(_hidl_offset + 32);
        exponentialBase = _hidl_blob.getInt32(_hidl_offset + 36);
        exponentialStepCount = _hidl_blob.getInt32(_hidl_offset + 40);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaBackgroundScanBucketParameters> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, bucketIdx);
        _hidl_blob.putInt32(_hidl_offset + 4, band);
        {
            int _hidl_vec_size = frequencies.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, frequencies.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, periodInMs);
        _hidl_blob.putInt32(_hidl_offset + 28, eventReportScheme);
        _hidl_blob.putInt32(_hidl_offset + 32, exponentialMaxPeriodInMs);
        _hidl_blob.putInt32(_hidl_offset + 36, exponentialBase);
        _hidl_blob.putInt32(_hidl_offset + 40, exponentialStepCount);
    }
};

