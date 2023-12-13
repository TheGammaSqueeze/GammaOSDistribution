package android.hardware.wifi.V1_0;


public final class StaLinkLayerRadioStats {
    /**
     * Time for which the radio is awake.
     */
    public int onTimeInMs = 0;
    /**
     * Total time for which the radio is in active transmission.
     */
    public int txTimeInMs = 0;
    /**
     * Time for which the radio is in active tranmission per tx level.
     */
    public java.util.ArrayList<Integer> txTimeInMsPerLevel = new java.util.ArrayList<Integer>();
    /**
     * Time for which the radio is in active receive.
     */
    public int rxTimeInMs = 0;
    /**
     *  Total time for which the radio is awake due to scan.
     */
    public int onTimeInMsForScan = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaLinkLayerRadioStats.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaLinkLayerRadioStats other = (android.hardware.wifi.V1_0.StaLinkLayerRadioStats)otherObject;
        if (this.onTimeInMs != other.onTimeInMs) {
            return false;
        }
        if (this.txTimeInMs != other.txTimeInMs) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.txTimeInMsPerLevel, other.txTimeInMsPerLevel)) {
            return false;
        }
        if (this.rxTimeInMs != other.rxTimeInMs) {
            return false;
        }
        if (this.onTimeInMsForScan != other.onTimeInMsForScan) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.onTimeInMs), 
                android.os.HidlSupport.deepHashCode(this.txTimeInMs), 
                android.os.HidlSupport.deepHashCode(this.txTimeInMsPerLevel), 
                android.os.HidlSupport.deepHashCode(this.rxTimeInMs), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForScan));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".onTimeInMs = ");
        builder.append(this.onTimeInMs);
        builder.append(", .txTimeInMs = ");
        builder.append(this.txTimeInMs);
        builder.append(", .txTimeInMsPerLevel = ");
        builder.append(this.txTimeInMsPerLevel);
        builder.append(", .rxTimeInMs = ");
        builder.append(this.rxTimeInMs);
        builder.append(", .onTimeInMsForScan = ");
        builder.append(this.onTimeInMsForScan);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaLinkLayerRadioStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaLinkLayerRadioStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaLinkLayerRadioStats _hidl_vec_element = new android.hardware.wifi.V1_0.StaLinkLayerRadioStats();
                ((android.hardware.wifi.V1_0.StaLinkLayerRadioStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        onTimeInMs = _hidl_blob.getInt32(_hidl_offset + 0);
        txTimeInMs = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) txTimeInMsPerLevel).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) txTimeInMsPerLevel).add(_hidl_vec_element);
            }
        }
        rxTimeInMs = _hidl_blob.getInt32(_hidl_offset + 24);
        onTimeInMsForScan = _hidl_blob.getInt32(_hidl_offset + 28);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaLinkLayerRadioStats> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, onTimeInMs);
        _hidl_blob.putInt32(_hidl_offset + 4, txTimeInMs);
        {
            int _hidl_vec_size = txTimeInMsPerLevel.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, txTimeInMsPerLevel.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, rxTimeInMs);
        _hidl_blob.putInt32(_hidl_offset + 28, onTimeInMsForScan);
    }
};

