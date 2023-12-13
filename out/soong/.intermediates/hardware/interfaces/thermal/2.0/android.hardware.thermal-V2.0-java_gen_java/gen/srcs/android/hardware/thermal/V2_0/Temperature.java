package android.hardware.thermal.V2_0;


public final class Temperature {
    /**
     * This temperature's type.
     */
    public int type = 0;
    /**
     * Name of this temperature matching the TemperatureThreshold.
     * All temperatures of the same "type" must have a different "name",
     * e.g., cpu0, battery. Clients use it to match with TemperatureThreshold
     * struct.
     */
    public String name = new String();
    /**
     * For BCL, this is the current reading of the virtual sensor and the unit is
     * millivolt, milliamp, percentage for BCL_VOLTAGE, BCL_CURRENT and BCL_PERCENTAGE
     * respectively. For everything else, this is the current temperature in Celsius.
     * If not available set by HAL to NAN.
     */
    public float value = 0.0f;
    /**
     * The current throttling level of the sensor.
     */
    public int throttlingStatus = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.thermal.V2_0.Temperature.class) {
            return false;
        }
        android.hardware.thermal.V2_0.Temperature other = (android.hardware.thermal.V2_0.Temperature)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (this.value != other.value) {
            return false;
        }
        if (this.throttlingStatus != other.throttlingStatus) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.value), 
                android.os.HidlSupport.deepHashCode(this.throttlingStatus));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.thermal.V2_0.TemperatureType.toString(this.type));
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .value = ");
        builder.append(this.value);
        builder.append(", .throttlingStatus = ");
        builder.append(android.hardware.thermal.V2_0.ThrottlingSeverity.toString(this.throttlingStatus));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Temperature> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Temperature> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.thermal.V2_0.Temperature _hidl_vec_element = new android.hardware.thermal.V2_0.Temperature();
                ((android.hardware.thermal.V2_0.Temperature) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        type = _hidl_blob.getInt32(_hidl_offset + 0);
        name = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        value = _hidl_blob.getFloat(_hidl_offset + 24);
        throttlingStatus = _hidl_blob.getInt32(_hidl_offset + 28);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<Temperature> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        _hidl_blob.putString(_hidl_offset + 8, name);
        _hidl_blob.putFloat(_hidl_offset + 24, value);
        _hidl_blob.putInt32(_hidl_offset + 28, throttlingStatus);
    }
};

