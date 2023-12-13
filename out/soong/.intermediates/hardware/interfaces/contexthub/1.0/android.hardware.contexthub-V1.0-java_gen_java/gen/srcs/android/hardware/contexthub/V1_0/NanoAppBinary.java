package android.hardware.contexthub.V1_0;


public final class NanoAppBinary {
    public long appId = 0L;
    public int appVersion = 0;
    public int flags;
    public byte targetChreApiMajorVersion = 0;
    public byte targetChreApiMinorVersion = 0;
    public java.util.ArrayList<Byte> customBinary = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.contexthub.V1_0.NanoAppBinary.class) {
            return false;
        }
        android.hardware.contexthub.V1_0.NanoAppBinary other = (android.hardware.contexthub.V1_0.NanoAppBinary)otherObject;
        if (this.appId != other.appId) {
            return false;
        }
        if (this.appVersion != other.appVersion) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.flags, other.flags)) {
            return false;
        }
        if (this.targetChreApiMajorVersion != other.targetChreApiMajorVersion) {
            return false;
        }
        if (this.targetChreApiMinorVersion != other.targetChreApiMinorVersion) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.customBinary, other.customBinary)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.appId), 
                android.os.HidlSupport.deepHashCode(this.appVersion), 
                android.os.HidlSupport.deepHashCode(this.flags), 
                android.os.HidlSupport.deepHashCode(this.targetChreApiMajorVersion), 
                android.os.HidlSupport.deepHashCode(this.targetChreApiMinorVersion), 
                android.os.HidlSupport.deepHashCode(this.customBinary));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".appId = ");
        builder.append(this.appId);
        builder.append(", .appVersion = ");
        builder.append(this.appVersion);
        builder.append(", .flags = ");
        builder.append(android.hardware.contexthub.V1_0.NanoAppFlags.dumpBitfield(this.flags));
        builder.append(", .targetChreApiMajorVersion = ");
        builder.append(this.targetChreApiMajorVersion);
        builder.append(", .targetChreApiMinorVersion = ");
        builder.append(this.targetChreApiMinorVersion);
        builder.append(", .customBinary = ");
        builder.append(this.customBinary);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanoAppBinary> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanoAppBinary> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.contexthub.V1_0.NanoAppBinary _hidl_vec_element = new android.hardware.contexthub.V1_0.NanoAppBinary();
                ((android.hardware.contexthub.V1_0.NanoAppBinary) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        appId = _hidl_blob.getInt64(_hidl_offset + 0);
        appVersion = _hidl_blob.getInt32(_hidl_offset + 8);
        flags = _hidl_blob.getInt32(_hidl_offset + 12);
        targetChreApiMajorVersion = _hidl_blob.getInt8(_hidl_offset + 16);
        targetChreApiMinorVersion = _hidl_blob.getInt8(_hidl_offset + 17);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) customBinary).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) customBinary).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanoAppBinary> _hidl_vec) {
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
        _hidl_blob.putInt64(_hidl_offset + 0, appId);
        _hidl_blob.putInt32(_hidl_offset + 8, appVersion);
        _hidl_blob.putInt32(_hidl_offset + 12, flags);
        _hidl_blob.putInt8(_hidl_offset + 16, targetChreApiMajorVersion);
        _hidl_blob.putInt8(_hidl_offset + 17, targetChreApiMinorVersion);
        {
            int _hidl_vec_size = customBinary.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, customBinary.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

