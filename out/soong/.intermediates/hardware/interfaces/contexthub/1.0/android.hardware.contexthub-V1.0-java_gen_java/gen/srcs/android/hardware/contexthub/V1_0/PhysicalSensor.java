package android.hardware.contexthub.V1_0;


public final class PhysicalSensor {
    public int sensorType = 0;
    public String type = new String();
    public String name = new String();
    public String vendor = new String();
    public int version = 0;
    public int fifoReservedCount = 0;
    public int fifoMaxCount = 0;
    public long minDelayMs = 0L;
    public long maxDelayMs = 0L;
    public float peakPowerMw = 0.0f;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.contexthub.V1_0.PhysicalSensor.class) {
            return false;
        }
        android.hardware.contexthub.V1_0.PhysicalSensor other = (android.hardware.contexthub.V1_0.PhysicalSensor)otherObject;
        if (this.sensorType != other.sensorType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.type, other.type)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.vendor, other.vendor)) {
            return false;
        }
        if (this.version != other.version) {
            return false;
        }
        if (this.fifoReservedCount != other.fifoReservedCount) {
            return false;
        }
        if (this.fifoMaxCount != other.fifoMaxCount) {
            return false;
        }
        if (this.minDelayMs != other.minDelayMs) {
            return false;
        }
        if (this.maxDelayMs != other.maxDelayMs) {
            return false;
        }
        if (this.peakPowerMw != other.peakPowerMw) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sensorType), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.vendor), 
                android.os.HidlSupport.deepHashCode(this.version), 
                android.os.HidlSupport.deepHashCode(this.fifoReservedCount), 
                android.os.HidlSupport.deepHashCode(this.fifoMaxCount), 
                android.os.HidlSupport.deepHashCode(this.minDelayMs), 
                android.os.HidlSupport.deepHashCode(this.maxDelayMs), 
                android.os.HidlSupport.deepHashCode(this.peakPowerMw));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sensorType = ");
        builder.append(android.hardware.contexthub.V1_0.SensorType.toString(this.sensorType));
        builder.append(", .type = ");
        builder.append(this.type);
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .vendor = ");
        builder.append(this.vendor);
        builder.append(", .version = ");
        builder.append(this.version);
        builder.append(", .fifoReservedCount = ");
        builder.append(this.fifoReservedCount);
        builder.append(", .fifoMaxCount = ");
        builder.append(this.fifoMaxCount);
        builder.append(", .minDelayMs = ");
        builder.append(this.minDelayMs);
        builder.append(", .maxDelayMs = ");
        builder.append(this.maxDelayMs);
        builder.append(", .peakPowerMw = ");
        builder.append(this.peakPowerMw);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(96 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhysicalSensor> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhysicalSensor> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.contexthub.V1_0.PhysicalSensor _hidl_vec_element = new android.hardware.contexthub.V1_0.PhysicalSensor();
                ((android.hardware.contexthub.V1_0.PhysicalSensor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sensorType = _hidl_blob.getInt32(_hidl_offset + 0);
        type = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) type).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        name = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        vendor = _hidl_blob.getString(_hidl_offset + 40);

        parcel.readEmbeddedBuffer(
                ((String) vendor).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        version = _hidl_blob.getInt32(_hidl_offset + 56);
        fifoReservedCount = _hidl_blob.getInt32(_hidl_offset + 60);
        fifoMaxCount = _hidl_blob.getInt32(_hidl_offset + 64);
        minDelayMs = _hidl_blob.getInt64(_hidl_offset + 72);
        maxDelayMs = _hidl_blob.getInt64(_hidl_offset + 80);
        peakPowerMw = _hidl_blob.getFloat(_hidl_offset + 88);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(96 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhysicalSensor> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, sensorType);
        _hidl_blob.putString(_hidl_offset + 8, type);
        _hidl_blob.putString(_hidl_offset + 24, name);
        _hidl_blob.putString(_hidl_offset + 40, vendor);
        _hidl_blob.putInt32(_hidl_offset + 56, version);
        _hidl_blob.putInt32(_hidl_offset + 60, fifoReservedCount);
        _hidl_blob.putInt32(_hidl_offset + 64, fifoMaxCount);
        _hidl_blob.putInt64(_hidl_offset + 72, minDelayMs);
        _hidl_blob.putInt64(_hidl_offset + 80, maxDelayMs);
        _hidl_blob.putFloat(_hidl_offset + 88, peakPowerMw);
    }
};

