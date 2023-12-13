package android.hardware.thermal.V1_0;


public final class Temperature {
    /**
     * This temperature's type.
     */
    public int type = 0;
    /**
     * Name of this temperature.
     * All temperatures of the same "type" must have a different "name",
     * e.g., cpu0, battery.
     */
    public String name = new String();
    /**
     * Current temperature in Celsius. If not available set by HAL to NAN.
     * Current temperature can be in any units if type=UNKNOWN.
     */
    public float currentValue = 0.0f;
    /**
     * Throttling temperature constant for this temperature.
     * If not available, set by HAL to NAN.
     */
    public float throttlingThreshold = 0.0f;
    /**
     * Shutdown temperature constant for this temperature.
     * If not available, set by HAL to NAN.
     */
    public float shutdownThreshold = 0.0f;
    /**
     * Threshold temperature above which the VR mode clockrate minimums cannot
     * be maintained for this device.
     * If not available, set by HAL to NAN.
     */
    public float vrThrottlingThreshold = 0.0f;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.thermal.V1_0.Temperature.class) {
            return false;
        }
        android.hardware.thermal.V1_0.Temperature other = (android.hardware.thermal.V1_0.Temperature)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (this.currentValue != other.currentValue) {
            return false;
        }
        if (this.throttlingThreshold != other.throttlingThreshold) {
            return false;
        }
        if (this.shutdownThreshold != other.shutdownThreshold) {
            return false;
        }
        if (this.vrThrottlingThreshold != other.vrThrottlingThreshold) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.currentValue), 
                android.os.HidlSupport.deepHashCode(this.throttlingThreshold), 
                android.os.HidlSupport.deepHashCode(this.shutdownThreshold), 
                android.os.HidlSupport.deepHashCode(this.vrThrottlingThreshold));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.thermal.V1_0.TemperatureType.toString(this.type));
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .currentValue = ");
        builder.append(this.currentValue);
        builder.append(", .throttlingThreshold = ");
        builder.append(this.throttlingThreshold);
        builder.append(", .shutdownThreshold = ");
        builder.append(this.shutdownThreshold);
        builder.append(", .vrThrottlingThreshold = ");
        builder.append(this.vrThrottlingThreshold);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Temperature> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Temperature> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.thermal.V1_0.Temperature _hidl_vec_element = new android.hardware.thermal.V1_0.Temperature();
                ((android.hardware.thermal.V1_0.Temperature) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
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

        currentValue = _hidl_blob.getFloat(_hidl_offset + 24);
        throttlingThreshold = _hidl_blob.getFloat(_hidl_offset + 28);
        shutdownThreshold = _hidl_blob.getFloat(_hidl_offset + 32);
        vrThrottlingThreshold = _hidl_blob.getFloat(_hidl_offset + 36);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
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
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        _hidl_blob.putString(_hidl_offset + 8, name);
        _hidl_blob.putFloat(_hidl_offset + 24, currentValue);
        _hidl_blob.putFloat(_hidl_offset + 28, throttlingThreshold);
        _hidl_blob.putFloat(_hidl_offset + 32, shutdownThreshold);
        _hidl_blob.putFloat(_hidl_offset + 36, vrThrottlingThreshold);
    }
};

