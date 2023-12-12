package android.hardware.health.V2_0;


public final class HealthInfo {
    /**
     * V1.0 HealthInfo.
     * If a member is unsupported, it is filled with:
     * - 0 (for integers);
     * - false (for booleans);
     * - empty string (for strings);
     * - UNKNOWN (for BatteryStatus and BatteryHealth).
     */
    public android.hardware.health.V1_0.HealthInfo legacy = new android.hardware.health.V1_0.HealthInfo();
    /**
     * Average battery current in uA. Will be 0 if unsupported.
     */
    public int batteryCurrentAverage = 0;
    /**
     * Disk Statistics. Will be an empty vector if unsupported.
     */
    public java.util.ArrayList<android.hardware.health.V2_0.DiskStats> diskStats = new java.util.ArrayList<android.hardware.health.V2_0.DiskStats>();
    /**
     * Information on storage devices. Will be an empty vector if
     * unsupported.
     */
    public java.util.ArrayList<android.hardware.health.V2_0.StorageInfo> storageInfos = new java.util.ArrayList<android.hardware.health.V2_0.StorageInfo>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V2_0.HealthInfo.class) {
            return false;
        }
        android.hardware.health.V2_0.HealthInfo other = (android.hardware.health.V2_0.HealthInfo)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.legacy, other.legacy)) {
            return false;
        }
        if (this.batteryCurrentAverage != other.batteryCurrentAverage) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.diskStats, other.diskStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.storageInfos, other.storageInfos)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.legacy), 
                android.os.HidlSupport.deepHashCode(this.batteryCurrentAverage), 
                android.os.HidlSupport.deepHashCode(this.diskStats), 
                android.os.HidlSupport.deepHashCode(this.storageInfos));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".legacy = ");
        builder.append(this.legacy);
        builder.append(", .batteryCurrentAverage = ");
        builder.append(this.batteryCurrentAverage);
        builder.append(", .diskStats = ");
        builder.append(this.diskStats);
        builder.append(", .storageInfos = ");
        builder.append(this.storageInfos);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HealthInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HealthInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_0.HealthInfo _hidl_vec_element = new android.hardware.health.V2_0.HealthInfo();
                ((android.hardware.health.V2_0.HealthInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.health.V1_0.HealthInfo) legacy).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        batteryCurrentAverage = _hidl_blob.getInt32(_hidl_offset + 72);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.health.V2_0.DiskStats>) diskStats).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_0.DiskStats _hidl_vec_element = new android.hardware.health.V2_0.DiskStats();
                ((android.hardware.health.V2_0.DiskStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                ((java.util.ArrayList<android.hardware.health.V2_0.DiskStats>) diskStats).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    _hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.health.V2_0.StorageInfo>) storageInfos).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_0.StorageInfo _hidl_vec_element = new android.hardware.health.V2_0.StorageInfo();
                ((android.hardware.health.V2_0.StorageInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                ((java.util.ArrayList<android.hardware.health.V2_0.StorageInfo>) storageInfos).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        legacy.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 72, batteryCurrentAverage);
        {
            int _hidl_vec_size = diskStats.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                diskStats.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = storageInfos.size();
            _hidl_blob.putInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 96 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                storageInfos.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(_hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

