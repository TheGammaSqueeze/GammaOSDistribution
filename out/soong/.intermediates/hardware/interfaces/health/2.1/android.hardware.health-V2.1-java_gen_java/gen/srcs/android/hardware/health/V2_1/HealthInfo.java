package android.hardware.health.V2_1;


public final class HealthInfo {
    /**
     * V2.0 HealthInfo.
     * If a member is unsupported, it is filled with:
     * - 0 (for integers);
     * - false (for booleans);
     * - empty string (for strings);
     * - UNKNOWN (for BatteryStatus and BatteryHealth).
     */
    public android.hardware.health.V2_0.HealthInfo legacy = new android.hardware.health.V2_0.HealthInfo();
    /**
     * Battery capacity level. See BatteryCapacityLevel for more details.
     */
    public int batteryCapacityLevel = 0;
    /**
     * Estimated time to fully charge the device (in seconds).
     * Value must be BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED if and
     * only if the implementation is unsupported.
     * Value must be 0 if and only if batteryCapacityLevel is FULL or UNKNOWN.
     * Otherwise, value must be positive.
     */
    public long batteryChargeTimeToFullNowSeconds = 0L;
    /**
     * Estimated battery full charge design capacity (in microamp hours, uAh).
     * Value must be 0 if unknown.
     * Value must be greater than 100 000 uAh if known.
     * Value must be less than 100 000 000 uAh if known.
     */
    public int batteryFullChargeDesignCapacityUah = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V2_1.HealthInfo.class) {
            return false;
        }
        android.hardware.health.V2_1.HealthInfo other = (android.hardware.health.V2_1.HealthInfo)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.legacy, other.legacy)) {
            return false;
        }
        if (this.batteryCapacityLevel != other.batteryCapacityLevel) {
            return false;
        }
        if (this.batteryChargeTimeToFullNowSeconds != other.batteryChargeTimeToFullNowSeconds) {
            return false;
        }
        if (this.batteryFullChargeDesignCapacityUah != other.batteryFullChargeDesignCapacityUah) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.legacy), 
                android.os.HidlSupport.deepHashCode(this.batteryCapacityLevel), 
                android.os.HidlSupport.deepHashCode(this.batteryChargeTimeToFullNowSeconds), 
                android.os.HidlSupport.deepHashCode(this.batteryFullChargeDesignCapacityUah));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".legacy = ");
        builder.append(this.legacy);
        builder.append(", .batteryCapacityLevel = ");
        builder.append(android.hardware.health.V2_1.BatteryCapacityLevel.toString(this.batteryCapacityLevel));
        builder.append(", .batteryChargeTimeToFullNowSeconds = ");
        builder.append(this.batteryChargeTimeToFullNowSeconds);
        builder.append(", .batteryFullChargeDesignCapacityUah = ");
        builder.append(this.batteryFullChargeDesignCapacityUah);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(136 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HealthInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HealthInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 136,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_1.HealthInfo _hidl_vec_element = new android.hardware.health.V2_1.HealthInfo();
                ((android.hardware.health.V2_1.HealthInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 136);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.health.V2_0.HealthInfo) legacy).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        batteryCapacityLevel = _hidl_blob.getInt32(_hidl_offset + 112);
        batteryChargeTimeToFullNowSeconds = _hidl_blob.getInt64(_hidl_offset + 120);
        batteryFullChargeDesignCapacityUah = _hidl_blob.getInt32(_hidl_offset + 128);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(136 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<HealthInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 136));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 136);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        legacy.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 112, batteryCapacityLevel);
        _hidl_blob.putInt64(_hidl_offset + 120, batteryChargeTimeToFullNowSeconds);
        _hidl_blob.putInt32(_hidl_offset + 128, batteryFullChargeDesignCapacityUah);
    }
};

