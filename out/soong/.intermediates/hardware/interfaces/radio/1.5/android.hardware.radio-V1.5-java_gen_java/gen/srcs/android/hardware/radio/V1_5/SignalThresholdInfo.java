package android.hardware.radio.V1_5;


public final class SignalThresholdInfo {
    /**
     * Signal Measurement Type
     */
    public int signalMeasurement = 0;
    /**
     * A hysteresis time in milliseconds to prevent flapping. A value of 0 disables hysteresis.
     */
    public int hysteresisMs = 0;
    /**
     * An interval in dB defining the required magnitude change between reports.
     * hysteresisDb must be smaller than the smallest threshold delta.
     * An interval value of 0 disables hysteresis.
     */
    public int hysteresisDb = 0;
    /**
     * List of threshold values.
     * Range and unit must reference specific @1.5::SignalMeasurementType.
     * The threshold values for which to apply criteria.
     * A vector size of 0 disables the use of thresholds for reporting.
     */
    public java.util.ArrayList<Integer> thresholds = new java.util.ArrayList<Integer>();
    /**
     * Indicates whether the reporting criteria of the corresponding measurement is enabled
     * (isEnabled==true) or disabled (isEnabled==false).
     *
     * If enabled, modem must trigger the report based on the criteria.
     * If disabled, modem must not trigger the report based on the criteria.
     */
    public boolean isEnabled = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.SignalThresholdInfo.class) {
            return false;
        }
        android.hardware.radio.V1_5.SignalThresholdInfo other = (android.hardware.radio.V1_5.SignalThresholdInfo)otherObject;
        if (this.signalMeasurement != other.signalMeasurement) {
            return false;
        }
        if (this.hysteresisMs != other.hysteresisMs) {
            return false;
        }
        if (this.hysteresisDb != other.hysteresisDb) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.thresholds, other.thresholds)) {
            return false;
        }
        if (this.isEnabled != other.isEnabled) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.signalMeasurement), 
                android.os.HidlSupport.deepHashCode(this.hysteresisMs), 
                android.os.HidlSupport.deepHashCode(this.hysteresisDb), 
                android.os.HidlSupport.deepHashCode(this.thresholds), 
                android.os.HidlSupport.deepHashCode(this.isEnabled));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".signalMeasurement = ");
        builder.append(android.hardware.radio.V1_5.SignalMeasurementType.toString(this.signalMeasurement));
        builder.append(", .hysteresisMs = ");
        builder.append(this.hysteresisMs);
        builder.append(", .hysteresisDb = ");
        builder.append(this.hysteresisDb);
        builder.append(", .thresholds = ");
        builder.append(this.thresholds);
        builder.append(", .isEnabled = ");
        builder.append(this.isEnabled);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SignalThresholdInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SignalThresholdInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.SignalThresholdInfo _hidl_vec_element = new android.hardware.radio.V1_5.SignalThresholdInfo();
                ((android.hardware.radio.V1_5.SignalThresholdInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        signalMeasurement = _hidl_blob.getInt32(_hidl_offset + 0);
        hysteresisMs = _hidl_blob.getInt32(_hidl_offset + 4);
        hysteresisDb = _hidl_blob.getInt32(_hidl_offset + 8);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) thresholds).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) thresholds).add(_hidl_vec_element);
            }
        }
        isEnabled = _hidl_blob.getBool(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SignalThresholdInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, signalMeasurement);
        _hidl_blob.putInt32(_hidl_offset + 4, hysteresisMs);
        _hidl_blob.putInt32(_hidl_offset + 8, hysteresisDb);
        {
            int _hidl_vec_size = thresholds.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, thresholds.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putBool(_hidl_offset + 32, isEnabled);
    }
};

