package android.hardware.thermal.V1_0;


public final class CpuUsage {
    /**
     * Name of this CPU.
     * All CPUs must have a different "name".
     */
    public String name = new String();
    /**
     * Active time since the last boot in ms.
     */
    public long active = 0L;
    /**
     * Total time since the last boot in ms.
     */
    public long total = 0L;
    /**
     * Is set to true when a core is online.
     * If the core is offline, all other members except |name| should be ignored.
     */
    public boolean isOnline = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.thermal.V1_0.CpuUsage.class) {
            return false;
        }
        android.hardware.thermal.V1_0.CpuUsage other = (android.hardware.thermal.V1_0.CpuUsage)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (this.active != other.active) {
            return false;
        }
        if (this.total != other.total) {
            return false;
        }
        if (this.isOnline != other.isOnline) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.active), 
                android.os.HidlSupport.deepHashCode(this.total), 
                android.os.HidlSupport.deepHashCode(this.isOnline));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".name = ");
        builder.append(this.name);
        builder.append(", .active = ");
        builder.append(this.active);
        builder.append(", .total = ");
        builder.append(this.total);
        builder.append(", .isOnline = ");
        builder.append(this.isOnline);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CpuUsage> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CpuUsage> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.thermal.V1_0.CpuUsage _hidl_vec_element = new android.hardware.thermal.V1_0.CpuUsage();
                ((android.hardware.thermal.V1_0.CpuUsage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
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

        active = _hidl_blob.getInt64(_hidl_offset + 16);
        total = _hidl_blob.getInt64(_hidl_offset + 24);
        isOnline = _hidl_blob.getBool(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CpuUsage> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, name);
        _hidl_blob.putInt64(_hidl_offset + 16, active);
        _hidl_blob.putInt64(_hidl_offset + 24, total);
        _hidl_blob.putBool(_hidl_offset + 32, isOnline);
    }
};

