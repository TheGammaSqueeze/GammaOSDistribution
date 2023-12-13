package android.hardware.health.V2_0;


public final class StorageInfo {
    /**
     * Attributes of the storage device whose info is contained by the struct.
     */
    public android.hardware.health.V2_0.StorageAttribute attr = new android.hardware.health.V2_0.StorageAttribute();
    /**
     * pre-eol (end of life) information. Follows JEDEC standard No.84-B50.
     */
    public short eol = 0;
    /**
     * device life time estimation (type A). Follows JEDEC standard No.84-B50.
     */
    public short lifetimeA = 0;
    /**
     * device life time estimation (type B). Follows JEDEC standard No.84-B50.
     */
    public short lifetimeB = 0;
    /**
     * version string
     */
    public String version = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V2_0.StorageInfo.class) {
            return false;
        }
        android.hardware.health.V2_0.StorageInfo other = (android.hardware.health.V2_0.StorageInfo)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.attr, other.attr)) {
            return false;
        }
        if (this.eol != other.eol) {
            return false;
        }
        if (this.lifetimeA != other.lifetimeA) {
            return false;
        }
        if (this.lifetimeB != other.lifetimeB) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.version, other.version)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.attr), 
                android.os.HidlSupport.deepHashCode(this.eol), 
                android.os.HidlSupport.deepHashCode(this.lifetimeA), 
                android.os.HidlSupport.deepHashCode(this.lifetimeB), 
                android.os.HidlSupport.deepHashCode(this.version));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".attr = ");
        builder.append(this.attr);
        builder.append(", .eol = ");
        builder.append(this.eol);
        builder.append(", .lifetimeA = ");
        builder.append(this.lifetimeA);
        builder.append(", .lifetimeB = ");
        builder.append(this.lifetimeB);
        builder.append(", .version = ");
        builder.append(this.version);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StorageInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StorageInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_0.StorageInfo _hidl_vec_element = new android.hardware.health.V2_0.StorageInfo();
                ((android.hardware.health.V2_0.StorageInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.health.V2_0.StorageAttribute) attr).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        eol = _hidl_blob.getInt16(_hidl_offset + 24);
        lifetimeA = _hidl_blob.getInt16(_hidl_offset + 26);
        lifetimeB = _hidl_blob.getInt16(_hidl_offset + 28);
        version = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) version).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StorageInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        attr.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt16(_hidl_offset + 24, eol);
        _hidl_blob.putInt16(_hidl_offset + 26, lifetimeA);
        _hidl_blob.putInt16(_hidl_offset + 28, lifetimeB);
        _hidl_blob.putString(_hidl_offset + 32, version);
    }
};

