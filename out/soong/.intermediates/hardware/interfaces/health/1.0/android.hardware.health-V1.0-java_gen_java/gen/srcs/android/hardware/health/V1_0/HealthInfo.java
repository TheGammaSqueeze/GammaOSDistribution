package android.hardware.health.V1_0;


public final class HealthInfo {
    /**
     * AC charger state - 'true' if online
     */
    public boolean chargerAcOnline = false;
    /**
     * USB charger state - 'true' if online
     */
    public boolean chargerUsbOnline = false;
    /**
     * Wireless charger state - 'true' if online
     */
    public boolean chargerWirelessOnline = false;
    /**
     * Maximum charging current supported by charger in uA
     */
    public int maxChargingCurrent = 0;
    /**
     * Maximum charging voltage supported by charger in uV
     */
    public int maxChargingVoltage = 0;
    public int batteryStatus = 0;
    public int batteryHealth = 0;
    /**
     * 'true' if battery is present
     */
    public boolean batteryPresent = false;
    /**
     * Remaining battery capacity in percent
     */
    public int batteryLevel = 0;
    /**
     * Instantaneous battery voltage in millivolts (mV).
     *
     * Historically, the unit of this field is microvolts (uV), but all
     * clients and implementations uses millivolts in practice, making it
     * the de-facto standard.
     */
    public int batteryVoltage = 0;
    /**
     * Instantaneous battery temperature in tenths of degree celcius
     */
    public int batteryTemperature = 0;
    /**
     * Instantaneous battery current in uA
     */
    public int batteryCurrent = 0;
    /**
     * Battery charge cycle count
     */
    public int batteryCycleCount = 0;
    /**
     * Battery charge value when it is considered to be "full" in uA-h
     */
    public int batteryFullCharge = 0;
    /**
     * Instantaneous battery capacity in uA-h
     */
    public int batteryChargeCounter = 0;
    /**
     * Battery technology, e.g. "Li-ion, Li-Poly" etc.
     */
    public String batteryTechnology = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V1_0.HealthInfo.class) {
            return false;
        }
        android.hardware.health.V1_0.HealthInfo other = (android.hardware.health.V1_0.HealthInfo)otherObject;
        if (this.chargerAcOnline != other.chargerAcOnline) {
            return false;
        }
        if (this.chargerUsbOnline != other.chargerUsbOnline) {
            return false;
        }
        if (this.chargerWirelessOnline != other.chargerWirelessOnline) {
            return false;
        }
        if (this.maxChargingCurrent != other.maxChargingCurrent) {
            return false;
        }
        if (this.maxChargingVoltage != other.maxChargingVoltage) {
            return false;
        }
        if (this.batteryStatus != other.batteryStatus) {
            return false;
        }
        if (this.batteryHealth != other.batteryHealth) {
            return false;
        }
        if (this.batteryPresent != other.batteryPresent) {
            return false;
        }
        if (this.batteryLevel != other.batteryLevel) {
            return false;
        }
        if (this.batteryVoltage != other.batteryVoltage) {
            return false;
        }
        if (this.batteryTemperature != other.batteryTemperature) {
            return false;
        }
        if (this.batteryCurrent != other.batteryCurrent) {
            return false;
        }
        if (this.batteryCycleCount != other.batteryCycleCount) {
            return false;
        }
        if (this.batteryFullCharge != other.batteryFullCharge) {
            return false;
        }
        if (this.batteryChargeCounter != other.batteryChargeCounter) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.batteryTechnology, other.batteryTechnology)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.chargerAcOnline), 
                android.os.HidlSupport.deepHashCode(this.chargerUsbOnline), 
                android.os.HidlSupport.deepHashCode(this.chargerWirelessOnline), 
                android.os.HidlSupport.deepHashCode(this.maxChargingCurrent), 
                android.os.HidlSupport.deepHashCode(this.maxChargingVoltage), 
                android.os.HidlSupport.deepHashCode(this.batteryStatus), 
                android.os.HidlSupport.deepHashCode(this.batteryHealth), 
                android.os.HidlSupport.deepHashCode(this.batteryPresent), 
                android.os.HidlSupport.deepHashCode(this.batteryLevel), 
                android.os.HidlSupport.deepHashCode(this.batteryVoltage), 
                android.os.HidlSupport.deepHashCode(this.batteryTemperature), 
                android.os.HidlSupport.deepHashCode(this.batteryCurrent), 
                android.os.HidlSupport.deepHashCode(this.batteryCycleCount), 
                android.os.HidlSupport.deepHashCode(this.batteryFullCharge), 
                android.os.HidlSupport.deepHashCode(this.batteryChargeCounter), 
                android.os.HidlSupport.deepHashCode(this.batteryTechnology));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".chargerAcOnline = ");
        builder.append(this.chargerAcOnline);
        builder.append(", .chargerUsbOnline = ");
        builder.append(this.chargerUsbOnline);
        builder.append(", .chargerWirelessOnline = ");
        builder.append(this.chargerWirelessOnline);
        builder.append(", .maxChargingCurrent = ");
        builder.append(this.maxChargingCurrent);
        builder.append(", .maxChargingVoltage = ");
        builder.append(this.maxChargingVoltage);
        builder.append(", .batteryStatus = ");
        builder.append(android.hardware.health.V1_0.BatteryStatus.toString(this.batteryStatus));
        builder.append(", .batteryHealth = ");
        builder.append(android.hardware.health.V1_0.BatteryHealth.toString(this.batteryHealth));
        builder.append(", .batteryPresent = ");
        builder.append(this.batteryPresent);
        builder.append(", .batteryLevel = ");
        builder.append(this.batteryLevel);
        builder.append(", .batteryVoltage = ");
        builder.append(this.batteryVoltage);
        builder.append(", .batteryTemperature = ");
        builder.append(this.batteryTemperature);
        builder.append(", .batteryCurrent = ");
        builder.append(this.batteryCurrent);
        builder.append(", .batteryCycleCount = ");
        builder.append(this.batteryCycleCount);
        builder.append(", .batteryFullCharge = ");
        builder.append(this.batteryFullCharge);
        builder.append(", .batteryChargeCounter = ");
        builder.append(this.batteryChargeCounter);
        builder.append(", .batteryTechnology = ");
        builder.append(this.batteryTechnology);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HealthInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HealthInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V1_0.HealthInfo _hidl_vec_element = new android.hardware.health.V1_0.HealthInfo();
                ((android.hardware.health.V1_0.HealthInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        chargerAcOnline = _hidl_blob.getBool(_hidl_offset + 0);
        chargerUsbOnline = _hidl_blob.getBool(_hidl_offset + 1);
        chargerWirelessOnline = _hidl_blob.getBool(_hidl_offset + 2);
        maxChargingCurrent = _hidl_blob.getInt32(_hidl_offset + 4);
        maxChargingVoltage = _hidl_blob.getInt32(_hidl_offset + 8);
        batteryStatus = _hidl_blob.getInt32(_hidl_offset + 12);
        batteryHealth = _hidl_blob.getInt32(_hidl_offset + 16);
        batteryPresent = _hidl_blob.getBool(_hidl_offset + 20);
        batteryLevel = _hidl_blob.getInt32(_hidl_offset + 24);
        batteryVoltage = _hidl_blob.getInt32(_hidl_offset + 28);
        batteryTemperature = _hidl_blob.getInt32(_hidl_offset + 32);
        batteryCurrent = _hidl_blob.getInt32(_hidl_offset + 36);
        batteryCycleCount = _hidl_blob.getInt32(_hidl_offset + 40);
        batteryFullCharge = _hidl_blob.getInt32(_hidl_offset + 44);
        batteryChargeCounter = _hidl_blob.getInt32(_hidl_offset + 48);
        batteryTechnology = _hidl_blob.getString(_hidl_offset + 56);

        parcel.readEmbeddedBuffer(
                ((String) batteryTechnology).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 56 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, chargerAcOnline);
        _hidl_blob.putBool(_hidl_offset + 1, chargerUsbOnline);
        _hidl_blob.putBool(_hidl_offset + 2, chargerWirelessOnline);
        _hidl_blob.putInt32(_hidl_offset + 4, maxChargingCurrent);
        _hidl_blob.putInt32(_hidl_offset + 8, maxChargingVoltage);
        _hidl_blob.putInt32(_hidl_offset + 12, batteryStatus);
        _hidl_blob.putInt32(_hidl_offset + 16, batteryHealth);
        _hidl_blob.putBool(_hidl_offset + 20, batteryPresent);
        _hidl_blob.putInt32(_hidl_offset + 24, batteryLevel);
        _hidl_blob.putInt32(_hidl_offset + 28, batteryVoltage);
        _hidl_blob.putInt32(_hidl_offset + 32, batteryTemperature);
        _hidl_blob.putInt32(_hidl_offset + 36, batteryCurrent);
        _hidl_blob.putInt32(_hidl_offset + 40, batteryCycleCount);
        _hidl_blob.putInt32(_hidl_offset + 44, batteryFullCharge);
        _hidl_blob.putInt32(_hidl_offset + 48, batteryChargeCounter);
        _hidl_blob.putString(_hidl_offset + 56, batteryTechnology);
    }
};

