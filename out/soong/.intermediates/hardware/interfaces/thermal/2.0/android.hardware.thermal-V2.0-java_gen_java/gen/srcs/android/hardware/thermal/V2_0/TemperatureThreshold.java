package android.hardware.thermal.V2_0;


public final class TemperatureThreshold {
    /**
     * This temperature's type.
     */
    public int type = 0;
    /**
     * Name of this temperature matching the Temperature struct.
     * All temperatures of the same "type" must have a different "name",
     * e.g., cpu0, battery. Clients use it to match Temperature struct.
     */
    public String name = new String();
    /**
     * Hot throttling temperature constant for this temperature sensor in
     * level defined in ThrottlingSeverity including shutdown. Throttling
     * happens when temperature >= threshold. If not available, set to NAN.
     * Unit is same as Temperature's value.
     */
    public float[/* ThrottlingSeverity#len */] hotThrottlingThresholds = new float[7 /* ThrottlingSeverity#len */];
    /**
     * Cold throttling temperature constant for this temperature sensor in
     * level defined in ThrottlingSeverity including shutdown. Throttling
     * happens when temperature <= threshold. If not available, set to NAN.
     * Unit is same as Temperature's value.
     */
    public float[/* ThrottlingSeverity#len */] coldThrottlingThresholds = new float[7 /* ThrottlingSeverity#len */];
    /**
     * Threshold temperature above which the VR mode clockrate minimums cannot
     * be maintained for this device. If not available, set by HAL to NAN.
     * Unit is same as Temperature's value.
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
        if (otherObject.getClass() != android.hardware.thermal.V2_0.TemperatureThreshold.class) {
            return false;
        }
        android.hardware.thermal.V2_0.TemperatureThreshold other = (android.hardware.thermal.V2_0.TemperatureThreshold)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.hotThrottlingThresholds, other.hotThrottlingThresholds)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.coldThrottlingThresholds, other.coldThrottlingThresholds)) {
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
                android.os.HidlSupport.deepHashCode(this.hotThrottlingThresholds), 
                android.os.HidlSupport.deepHashCode(this.coldThrottlingThresholds), 
                android.os.HidlSupport.deepHashCode(this.vrThrottlingThreshold));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.thermal.V2_0.TemperatureType.toString(this.type));
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .hotThrottlingThresholds = ");
        builder.append(java.util.Arrays.toString(this.hotThrottlingThresholds));
        builder.append(", .coldThrottlingThresholds = ");
        builder.append(java.util.Arrays.toString(this.coldThrottlingThresholds));
        builder.append(", .vrThrottlingThreshold = ");
        builder.append(this.vrThrottlingThreshold);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<TemperatureThreshold> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<TemperatureThreshold> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.thermal.V2_0.TemperatureThreshold _hidl_vec_element = new android.hardware.thermal.V2_0.TemperatureThreshold();
                ((android.hardware.thermal.V2_0.TemperatureThreshold) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
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

        {
            long _hidl_array_offset_0 = _hidl_offset + 24;
            _hidl_blob.copyToFloatArray(_hidl_array_offset_0, (float[/* ThrottlingSeverity#len */]) hotThrottlingThresholds, 7 /* ThrottlingSeverity#len */ /* size */);
            _hidl_array_offset_0 += 7 /* ThrottlingSeverity#len */ * 4;
        }
        {
            long _hidl_array_offset_0 = _hidl_offset + 52;
            _hidl_blob.copyToFloatArray(_hidl_array_offset_0, (float[/* ThrottlingSeverity#len */]) coldThrottlingThresholds, 7 /* ThrottlingSeverity#len */ /* size */);
            _hidl_array_offset_0 += 7 /* ThrottlingSeverity#len */ * 4;
        }
        vrThrottlingThreshold = _hidl_blob.getFloat(_hidl_offset + 80);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<TemperatureThreshold> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        _hidl_blob.putString(_hidl_offset + 8, name);
        {
            long _hidl_array_offset_0 = _hidl_offset + 24;
            float[] _hidl_array_item_0 = (float[/* ThrottlingSeverity#len */]) hotThrottlingThresholds;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 7 /* ThrottlingSeverity#len */) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putFloatArray(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 7 /* ThrottlingSeverity#len */ * 4;
        }
        {
            long _hidl_array_offset_0 = _hidl_offset + 52;
            float[] _hidl_array_item_0 = (float[/* ThrottlingSeverity#len */]) coldThrottlingThresholds;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 7 /* ThrottlingSeverity#len */) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putFloatArray(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 7 /* ThrottlingSeverity#len */ * 4;
        }
        _hidl_blob.putFloat(_hidl_offset + 80, vrThrottlingThreshold);
    }
};

