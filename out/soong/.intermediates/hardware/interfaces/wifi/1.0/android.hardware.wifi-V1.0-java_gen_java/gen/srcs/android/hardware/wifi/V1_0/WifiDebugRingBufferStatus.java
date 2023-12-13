package android.hardware.wifi.V1_0;


public final class WifiDebugRingBufferStatus {
    /**
     * Name of this debug ring buffer.
     */
    public String ringName = new String();
    /**
     * Combination of |WifiDebugRingBufferFlags| values.
     */
    public int flags = 0;
    /**
     * Unique integer representing the ring.
     */
    public int ringId = 0;
    /**
     * Total memory size allocated for the buffer.
     */
    public int sizeInBytes = 0;
    /**
     * Amount of free space in the buffer.
     */
    public int freeSizeInBytes = 0;
    /**
     * Verbose level for ring buffer.
     */
    public int verboseLevel = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.WifiDebugRingBufferStatus.class) {
            return false;
        }
        android.hardware.wifi.V1_0.WifiDebugRingBufferStatus other = (android.hardware.wifi.V1_0.WifiDebugRingBufferStatus)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.ringName, other.ringName)) {
            return false;
        }
        if (this.flags != other.flags) {
            return false;
        }
        if (this.ringId != other.ringId) {
            return false;
        }
        if (this.sizeInBytes != other.sizeInBytes) {
            return false;
        }
        if (this.freeSizeInBytes != other.freeSizeInBytes) {
            return false;
        }
        if (this.verboseLevel != other.verboseLevel) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.ringName), 
                android.os.HidlSupport.deepHashCode(this.flags), 
                android.os.HidlSupport.deepHashCode(this.ringId), 
                android.os.HidlSupport.deepHashCode(this.sizeInBytes), 
                android.os.HidlSupport.deepHashCode(this.freeSizeInBytes), 
                android.os.HidlSupport.deepHashCode(this.verboseLevel));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".ringName = ");
        builder.append(this.ringName);
        builder.append(", .flags = ");
        builder.append(this.flags);
        builder.append(", .ringId = ");
        builder.append(this.ringId);
        builder.append(", .sizeInBytes = ");
        builder.append(this.sizeInBytes);
        builder.append(", .freeSizeInBytes = ");
        builder.append(this.freeSizeInBytes);
        builder.append(", .verboseLevel = ");
        builder.append(this.verboseLevel);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiDebugRingBufferStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiDebugRingBufferStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiDebugRingBufferStatus _hidl_vec_element = new android.hardware.wifi.V1_0.WifiDebugRingBufferStatus();
                ((android.hardware.wifi.V1_0.WifiDebugRingBufferStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ringName = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) ringName).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        flags = _hidl_blob.getInt32(_hidl_offset + 16);
        ringId = _hidl_blob.getInt32(_hidl_offset + 20);
        sizeInBytes = _hidl_blob.getInt32(_hidl_offset + 24);
        freeSizeInBytes = _hidl_blob.getInt32(_hidl_offset + 28);
        verboseLevel = _hidl_blob.getInt32(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiDebugRingBufferStatus> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, ringName);
        _hidl_blob.putInt32(_hidl_offset + 16, flags);
        _hidl_blob.putInt32(_hidl_offset + 20, ringId);
        _hidl_blob.putInt32(_hidl_offset + 24, sizeInBytes);
        _hidl_blob.putInt32(_hidl_offset + 28, freeSizeInBytes);
        _hidl_blob.putInt32(_hidl_offset + 32, verboseLevel);
    }
};

