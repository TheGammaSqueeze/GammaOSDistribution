package android.hardware.contexthub.V1_0;


public final class ContextHub {
    public String name = new String();
    public String vendor = new String();
    public String toolchain = new String();
    public int platformVersion = 0;
    public int toolchainVersion = 0;
    public int hubId = 0;
    public float peakMips = 0.0f;
    public float stoppedPowerDrawMw = 0.0f;
    public float sleepPowerDrawMw = 0.0f;
    public float peakPowerDrawMw = 0.0f;
    public java.util.ArrayList<android.hardware.contexthub.V1_0.PhysicalSensor> connectedSensors = new java.util.ArrayList<android.hardware.contexthub.V1_0.PhysicalSensor>();
    public int maxSupportedMsgLen = 0;
    public long chrePlatformId = 0L;
    public byte chreApiMajorVersion = 0;
    public byte chreApiMinorVersion = 0;
    public short chrePatchVersion = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.contexthub.V1_0.ContextHub.class) {
            return false;
        }
        android.hardware.contexthub.V1_0.ContextHub other = (android.hardware.contexthub.V1_0.ContextHub)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.vendor, other.vendor)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.toolchain, other.toolchain)) {
            return false;
        }
        if (this.platformVersion != other.platformVersion) {
            return false;
        }
        if (this.toolchainVersion != other.toolchainVersion) {
            return false;
        }
        if (this.hubId != other.hubId) {
            return false;
        }
        if (this.peakMips != other.peakMips) {
            return false;
        }
        if (this.stoppedPowerDrawMw != other.stoppedPowerDrawMw) {
            return false;
        }
        if (this.sleepPowerDrawMw != other.sleepPowerDrawMw) {
            return false;
        }
        if (this.peakPowerDrawMw != other.peakPowerDrawMw) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.connectedSensors, other.connectedSensors)) {
            return false;
        }
        if (this.maxSupportedMsgLen != other.maxSupportedMsgLen) {
            return false;
        }
        if (this.chrePlatformId != other.chrePlatformId) {
            return false;
        }
        if (this.chreApiMajorVersion != other.chreApiMajorVersion) {
            return false;
        }
        if (this.chreApiMinorVersion != other.chreApiMinorVersion) {
            return false;
        }
        if (this.chrePatchVersion != other.chrePatchVersion) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.vendor), 
                android.os.HidlSupport.deepHashCode(this.toolchain), 
                android.os.HidlSupport.deepHashCode(this.platformVersion), 
                android.os.HidlSupport.deepHashCode(this.toolchainVersion), 
                android.os.HidlSupport.deepHashCode(this.hubId), 
                android.os.HidlSupport.deepHashCode(this.peakMips), 
                android.os.HidlSupport.deepHashCode(this.stoppedPowerDrawMw), 
                android.os.HidlSupport.deepHashCode(this.sleepPowerDrawMw), 
                android.os.HidlSupport.deepHashCode(this.peakPowerDrawMw), 
                android.os.HidlSupport.deepHashCode(this.connectedSensors), 
                android.os.HidlSupport.deepHashCode(this.maxSupportedMsgLen), 
                android.os.HidlSupport.deepHashCode(this.chrePlatformId), 
                android.os.HidlSupport.deepHashCode(this.chreApiMajorVersion), 
                android.os.HidlSupport.deepHashCode(this.chreApiMinorVersion), 
                android.os.HidlSupport.deepHashCode(this.chrePatchVersion));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".name = ");
        builder.append(this.name);
        builder.append(", .vendor = ");
        builder.append(this.vendor);
        builder.append(", .toolchain = ");
        builder.append(this.toolchain);
        builder.append(", .platformVersion = ");
        builder.append(this.platformVersion);
        builder.append(", .toolchainVersion = ");
        builder.append(this.toolchainVersion);
        builder.append(", .hubId = ");
        builder.append(this.hubId);
        builder.append(", .peakMips = ");
        builder.append(this.peakMips);
        builder.append(", .stoppedPowerDrawMw = ");
        builder.append(this.stoppedPowerDrawMw);
        builder.append(", .sleepPowerDrawMw = ");
        builder.append(this.sleepPowerDrawMw);
        builder.append(", .peakPowerDrawMw = ");
        builder.append(this.peakPowerDrawMw);
        builder.append(", .connectedSensors = ");
        builder.append(this.connectedSensors);
        builder.append(", .maxSupportedMsgLen = ");
        builder.append(this.maxSupportedMsgLen);
        builder.append(", .chrePlatformId = ");
        builder.append(this.chrePlatformId);
        builder.append(", .chreApiMajorVersion = ");
        builder.append(this.chreApiMajorVersion);
        builder.append(", .chreApiMinorVersion = ");
        builder.append(this.chreApiMinorVersion);
        builder.append(", .chrePatchVersion = ");
        builder.append(this.chrePatchVersion);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ContextHub> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ContextHub> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.contexthub.V1_0.ContextHub _hidl_vec_element = new android.hardware.contexthub.V1_0.ContextHub();
                ((android.hardware.contexthub.V1_0.ContextHub) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        name = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        vendor = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) vendor).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        toolchain = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) toolchain).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        platformVersion = _hidl_blob.getInt32(_hidl_offset + 48);
        toolchainVersion = _hidl_blob.getInt32(_hidl_offset + 52);
        hubId = _hidl_blob.getInt32(_hidl_offset + 56);
        peakMips = _hidl_blob.getFloat(_hidl_offset + 60);
        stoppedPowerDrawMw = _hidl_blob.getFloat(_hidl_offset + 64);
        sleepPowerDrawMw = _hidl_blob.getFloat(_hidl_offset + 68);
        peakPowerDrawMw = _hidl_blob.getFloat(_hidl_offset + 72);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.contexthub.V1_0.PhysicalSensor>) connectedSensors).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.contexthub.V1_0.PhysicalSensor _hidl_vec_element = new android.hardware.contexthub.V1_0.PhysicalSensor();
                ((android.hardware.contexthub.V1_0.PhysicalSensor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                ((java.util.ArrayList<android.hardware.contexthub.V1_0.PhysicalSensor>) connectedSensors).add(_hidl_vec_element);
            }
        }
        maxSupportedMsgLen = _hidl_blob.getInt32(_hidl_offset + 96);
        chrePlatformId = _hidl_blob.getInt64(_hidl_offset + 104);
        chreApiMajorVersion = _hidl_blob.getInt8(_hidl_offset + 112);
        chreApiMinorVersion = _hidl_blob.getInt8(_hidl_offset + 113);
        chrePatchVersion = _hidl_blob.getInt16(_hidl_offset + 114);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ContextHub> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, name);
        _hidl_blob.putString(_hidl_offset + 16, vendor);
        _hidl_blob.putString(_hidl_offset + 32, toolchain);
        _hidl_blob.putInt32(_hidl_offset + 48, platformVersion);
        _hidl_blob.putInt32(_hidl_offset + 52, toolchainVersion);
        _hidl_blob.putInt32(_hidl_offset + 56, hubId);
        _hidl_blob.putFloat(_hidl_offset + 60, peakMips);
        _hidl_blob.putFloat(_hidl_offset + 64, stoppedPowerDrawMw);
        _hidl_blob.putFloat(_hidl_offset + 68, sleepPowerDrawMw);
        _hidl_blob.putFloat(_hidl_offset + 72, peakPowerDrawMw);
        {
            int _hidl_vec_size = connectedSensors.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                connectedSensors.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 96, maxSupportedMsgLen);
        _hidl_blob.putInt64(_hidl_offset + 104, chrePlatformId);
        _hidl_blob.putInt8(_hidl_offset + 112, chreApiMajorVersion);
        _hidl_blob.putInt8(_hidl_offset + 113, chreApiMinorVersion);
        _hidl_blob.putInt16(_hidl_offset + 114, chrePatchVersion);
    }
};

