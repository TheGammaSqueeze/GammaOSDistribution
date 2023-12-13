package android.hardware.radio.V1_0;


public final class ActivityStatsInfo {
    public int sleepModeTimeMs = 0;
    public int idleModeTimeMs = 0;
    public int[/* RadioConst:NUM_TX_POWER_LEVELS */] txmModetimeMs = new int[5 /* RadioConst:NUM_TX_POWER_LEVELS */];
    public int rxModeTimeMs = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.ActivityStatsInfo.class) {
            return false;
        }
        android.hardware.radio.V1_0.ActivityStatsInfo other = (android.hardware.radio.V1_0.ActivityStatsInfo)otherObject;
        if (this.sleepModeTimeMs != other.sleepModeTimeMs) {
            return false;
        }
        if (this.idleModeTimeMs != other.idleModeTimeMs) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.txmModetimeMs, other.txmModetimeMs)) {
            return false;
        }
        if (this.rxModeTimeMs != other.rxModeTimeMs) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sleepModeTimeMs), 
                android.os.HidlSupport.deepHashCode(this.idleModeTimeMs), 
                android.os.HidlSupport.deepHashCode(this.txmModetimeMs), 
                android.os.HidlSupport.deepHashCode(this.rxModeTimeMs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sleepModeTimeMs = ");
        builder.append(this.sleepModeTimeMs);
        builder.append(", .idleModeTimeMs = ");
        builder.append(this.idleModeTimeMs);
        builder.append(", .txmModetimeMs = ");
        builder.append(java.util.Arrays.toString(this.txmModetimeMs));
        builder.append(", .rxModeTimeMs = ");
        builder.append(this.rxModeTimeMs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ActivityStatsInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ActivityStatsInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.ActivityStatsInfo _hidl_vec_element = new android.hardware.radio.V1_0.ActivityStatsInfo();
                ((android.hardware.radio.V1_0.ActivityStatsInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sleepModeTimeMs = _hidl_blob.getInt32(_hidl_offset + 0);
        idleModeTimeMs = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            _hidl_blob.copyToInt32Array(_hidl_array_offset_0, (int[/* RadioConst:NUM_TX_POWER_LEVELS */]) txmModetimeMs, 5 /* RadioConst:NUM_TX_POWER_LEVELS */ /* size */);
            _hidl_array_offset_0 += 5 /* RadioConst:NUM_TX_POWER_LEVELS */ * 4;
        }
        rxModeTimeMs = _hidl_blob.getInt32(_hidl_offset + 28);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ActivityStatsInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, sleepModeTimeMs);
        _hidl_blob.putInt32(_hidl_offset + 4, idleModeTimeMs);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            int[] _hidl_array_item_0 = (int[/* RadioConst:NUM_TX_POWER_LEVELS */]) txmModetimeMs;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 5 /* RadioConst:NUM_TX_POWER_LEVELS */) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt32Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 5 /* RadioConst:NUM_TX_POWER_LEVELS */ * 4;
        }
        _hidl_blob.putInt32(_hidl_offset + 28, rxModeTimeMs);
    }
};

