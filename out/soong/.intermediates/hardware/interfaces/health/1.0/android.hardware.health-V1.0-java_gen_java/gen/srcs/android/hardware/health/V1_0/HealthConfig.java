package android.hardware.health.V1_0;


public final class HealthConfig {
    /**
     * periodicChoresIntervalFast is used while the device is not in
     * suspend, or in suspend and connected to a charger (to watch for battery
     * overheat due to charging)
     */
    public int periodicChoresIntervalFast = 0;
    /**
     * periodicChoresIntervalSlow is used when the device is in suspend and
     * not connected to a charger (to watch for a battery drained to zero
     * remaining capacity).
     */
    public int periodicChoresIntervalSlow = 0;
    /**
     * power_supply sysfs attribute file paths. Set these to specific paths
     * to use for the associated battery parameters. Clients must search
     * for appropriate power_supply attribute files to use, for any paths
     * left empty after the HAL is initialized.
     *
     *
     * batteryStatusPath - file path to read battery charging status.
     * (POWER_SUPPLY_PROP_STATUS)
     */
    public String batteryStatusPath = new String();
    /**
     * batteryHealthPath - file path to read battery health.
     * (POWER_SUPPLY_PROP_HEALTH)
     */
    public String batteryHealthPath = new String();
    /**
     * batteryPresentPath - file path to read battery present status.
     * (POWER_SUPPLY_PROP_PRESENT)
     */
    public String batteryPresentPath = new String();
    /**
     * batteryCapacityPath - file path to read remaining battery capacity.
     * (POWER_SUPPLY_PROP_CAPACITY)
     */
    public String batteryCapacityPath = new String();
    /**
     * batteryVoltagePath - file path to read battery voltage.
     * (POWER_SUPPLY_PROP_VOLTAGE_NOW)
     */
    public String batteryVoltagePath = new String();
    /**
     * batteryTemperaturePath - file path to read battery temperature in tenths
     * of degree celcius. (POWER_SUPPLY_PROP_TEMP)
     */
    public String batteryTemperaturePath = new String();
    /**
     * batteryTechnologyPath - file path to read battery technology.
     * (POWER_SUPPLY_PROP_TECHNOLOGY)
     */
    public String batteryTechnologyPath = new String();
    /**
     * batteryCurrentNowPath - file path to read battery instantaneous current.
     * (POWER_SUPPLY_PROP_CURRENT_NOW)
     */
    public String batteryCurrentNowPath = new String();
    /**
     * batteryCurrentAvgPath - file path to read battery average current.
     * (POWER_SUPPLY_PROP_CURRENT_AVG)
     */
    public String batteryCurrentAvgPath = new String();
    /**
     * batteryChargeCounterPath - file path to read battery accumulated charge.
     * (POWER_SUPPLY_PROP_CHARGE_COUNTER)
     */
    public String batteryChargeCounterPath = new String();
    /**
     * batteryFullChargerPath - file path to read battery charge value when it
     * is considered to be full. (POWER_SUPPLY_PROP_CHARGE_FULL)
     */
    public String batteryFullChargePath = new String();
    /**
     * batteryCycleCountPath - file path to read battery charge cycle count.
     * (POWER_SUPPLY_PROP_CYCLE_COUNT)
     */
    public String batteryCycleCountPath = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V1_0.HealthConfig.class) {
            return false;
        }
        android.hardware.health.V1_0.HealthConfig other = (android.hardware.health.V1_0.HealthConfig)otherObject;
        if (this.periodicChoresIntervalFast != other.periodicChoresIntervalFast) {
            return false;
        }
        if (this.periodicChoresIntervalSlow != other.periodicChoresIntervalSlow) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryStatusPath, other.batteryStatusPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryHealthPath, other.batteryHealthPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryPresentPath, other.batteryPresentPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryCapacityPath, other.batteryCapacityPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryVoltagePath, other.batteryVoltagePath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryTemperaturePath, other.batteryTemperaturePath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryTechnologyPath, other.batteryTechnologyPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryCurrentNowPath, other.batteryCurrentNowPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryCurrentAvgPath, other.batteryCurrentAvgPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryChargeCounterPath, other.batteryChargeCounterPath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryFullChargePath, other.batteryFullChargePath)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryCycleCountPath, other.batteryCycleCountPath)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.periodicChoresIntervalFast), 
                android.os.HidlSupport.deepHashCode(this.periodicChoresIntervalSlow), 
                android.os.HidlSupport.deepHashCode(this.batteryStatusPath), 
                android.os.HidlSupport.deepHashCode(this.batteryHealthPath), 
                android.os.HidlSupport.deepHashCode(this.batteryPresentPath), 
                android.os.HidlSupport.deepHashCode(this.batteryCapacityPath), 
                android.os.HidlSupport.deepHashCode(this.batteryVoltagePath), 
                android.os.HidlSupport.deepHashCode(this.batteryTemperaturePath), 
                android.os.HidlSupport.deepHashCode(this.batteryTechnologyPath), 
                android.os.HidlSupport.deepHashCode(this.batteryCurrentNowPath), 
                android.os.HidlSupport.deepHashCode(this.batteryCurrentAvgPath), 
                android.os.HidlSupport.deepHashCode(this.batteryChargeCounterPath), 
                android.os.HidlSupport.deepHashCode(this.batteryFullChargePath), 
                android.os.HidlSupport.deepHashCode(this.batteryCycleCountPath));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".periodicChoresIntervalFast = ");
        builder.append(this.periodicChoresIntervalFast);
        builder.append(", .periodicChoresIntervalSlow = ");
        builder.append(this.periodicChoresIntervalSlow);
        builder.append(", .batteryStatusPath = ");
        builder.append(this.batteryStatusPath);
        builder.append(", .batteryHealthPath = ");
        builder.append(this.batteryHealthPath);
        builder.append(", .batteryPresentPath = ");
        builder.append(this.batteryPresentPath);
        builder.append(", .batteryCapacityPath = ");
        builder.append(this.batteryCapacityPath);
        builder.append(", .batteryVoltagePath = ");
        builder.append(this.batteryVoltagePath);
        builder.append(", .batteryTemperaturePath = ");
        builder.append(this.batteryTemperaturePath);
        builder.append(", .batteryTechnologyPath = ");
        builder.append(this.batteryTechnologyPath);
        builder.append(", .batteryCurrentNowPath = ");
        builder.append(this.batteryCurrentNowPath);
        builder.append(", .batteryCurrentAvgPath = ");
        builder.append(this.batteryCurrentAvgPath);
        builder.append(", .batteryChargeCounterPath = ");
        builder.append(this.batteryChargeCounterPath);
        builder.append(", .batteryFullChargePath = ");
        builder.append(this.batteryFullChargePath);
        builder.append(", .batteryCycleCountPath = ");
        builder.append(this.batteryCycleCountPath);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(200 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HealthConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HealthConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 200,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V1_0.HealthConfig _hidl_vec_element = new android.hardware.health.V1_0.HealthConfig();
                ((android.hardware.health.V1_0.HealthConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 200);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        periodicChoresIntervalFast = _hidl_blob.getInt32(_hidl_offset + 0);
        periodicChoresIntervalSlow = _hidl_blob.getInt32(_hidl_offset + 4);
        batteryStatusPath = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) batteryStatusPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryHealthPath = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) batteryHealthPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryPresentPath = _hidl_blob.getString(_hidl_offset + 40);

        parcel.readEmbeddedBuffer(
                ((String) batteryPresentPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryCapacityPath = _hidl_blob.getString(_hidl_offset + 56);

        parcel.readEmbeddedBuffer(
                ((String) batteryCapacityPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 56 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryVoltagePath = _hidl_blob.getString(_hidl_offset + 72);

        parcel.readEmbeddedBuffer(
                ((String) batteryVoltagePath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 72 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryTemperaturePath = _hidl_blob.getString(_hidl_offset + 88);

        parcel.readEmbeddedBuffer(
                ((String) batteryTemperaturePath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 88 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryTechnologyPath = _hidl_blob.getString(_hidl_offset + 104);

        parcel.readEmbeddedBuffer(
                ((String) batteryTechnologyPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 104 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryCurrentNowPath = _hidl_blob.getString(_hidl_offset + 120);

        parcel.readEmbeddedBuffer(
                ((String) batteryCurrentNowPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 120 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryCurrentAvgPath = _hidl_blob.getString(_hidl_offset + 136);

        parcel.readEmbeddedBuffer(
                ((String) batteryCurrentAvgPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 136 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryChargeCounterPath = _hidl_blob.getString(_hidl_offset + 152);

        parcel.readEmbeddedBuffer(
                ((String) batteryChargeCounterPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 152 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryFullChargePath = _hidl_blob.getString(_hidl_offset + 168);

        parcel.readEmbeddedBuffer(
                ((String) batteryFullChargePath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 168 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        batteryCycleCountPath = _hidl_blob.getString(_hidl_offset + 184);

        parcel.readEmbeddedBuffer(
                ((String) batteryCycleCountPath).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 184 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(200 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<HealthConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 200));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 200);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, periodicChoresIntervalFast);
        _hidl_blob.putInt32(_hidl_offset + 4, periodicChoresIntervalSlow);
        _hidl_blob.putString(_hidl_offset + 8, batteryStatusPath);
        _hidl_blob.putString(_hidl_offset + 24, batteryHealthPath);
        _hidl_blob.putString(_hidl_offset + 40, batteryPresentPath);
        _hidl_blob.putString(_hidl_offset + 56, batteryCapacityPath);
        _hidl_blob.putString(_hidl_offset + 72, batteryVoltagePath);
        _hidl_blob.putString(_hidl_offset + 88, batteryTemperaturePath);
        _hidl_blob.putString(_hidl_offset + 104, batteryTechnologyPath);
        _hidl_blob.putString(_hidl_offset + 120, batteryCurrentNowPath);
        _hidl_blob.putString(_hidl_offset + 136, batteryCurrentAvgPath);
        _hidl_blob.putString(_hidl_offset + 152, batteryChargeCounterPath);
        _hidl_blob.putString(_hidl_offset + 168, batteryFullChargePath);
        _hidl_blob.putString(_hidl_offset + 184, batteryCycleCountPath);
    }
};

