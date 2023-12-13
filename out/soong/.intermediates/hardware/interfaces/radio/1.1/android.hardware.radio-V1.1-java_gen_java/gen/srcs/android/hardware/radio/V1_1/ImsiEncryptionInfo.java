package android.hardware.radio.V1_1;


public final class ImsiEncryptionInfo {
    public String mcc = new String();
    public String mnc = new String();
    public java.util.ArrayList<Byte> carrierKey = new java.util.ArrayList<Byte>();
    public String keyIdentifier = new String();
    public long expirationTime = 0L;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_1.ImsiEncryptionInfo.class) {
            return false;
        }
        android.hardware.radio.V1_1.ImsiEncryptionInfo other = (android.hardware.radio.V1_1.ImsiEncryptionInfo)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.mcc, other.mcc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mnc, other.mnc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.carrierKey, other.carrierKey)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.keyIdentifier, other.keyIdentifier)) {
            return false;
        }
        if (this.expirationTime != other.expirationTime) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.mcc), 
                android.os.HidlSupport.deepHashCode(this.mnc), 
                android.os.HidlSupport.deepHashCode(this.carrierKey), 
                android.os.HidlSupport.deepHashCode(this.keyIdentifier), 
                android.os.HidlSupport.deepHashCode(this.expirationTime));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".mcc = ");
        builder.append(this.mcc);
        builder.append(", .mnc = ");
        builder.append(this.mnc);
        builder.append(", .carrierKey = ");
        builder.append(this.carrierKey);
        builder.append(", .keyIdentifier = ");
        builder.append(this.keyIdentifier);
        builder.append(", .expirationTime = ");
        builder.append(this.expirationTime);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ImsiEncryptionInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ImsiEncryptionInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_1.ImsiEncryptionInfo _hidl_vec_element = new android.hardware.radio.V1_1.ImsiEncryptionInfo();
                ((android.hardware.radio.V1_1.ImsiEncryptionInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        mcc = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) mcc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        mnc = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) mnc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) carrierKey).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) carrierKey).add(_hidl_vec_element);
            }
        }
        keyIdentifier = _hidl_blob.getString(_hidl_offset + 48);

        parcel.readEmbeddedBuffer(
                ((String) keyIdentifier).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 48 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        expirationTime = _hidl_blob.getInt64(_hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ImsiEncryptionInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, mcc);
        _hidl_blob.putString(_hidl_offset + 16, mnc);
        {
            int _hidl_vec_size = carrierKey.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, carrierKey.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putString(_hidl_offset + 48, keyIdentifier);
        _hidl_blob.putInt64(_hidl_offset + 64, expirationTime);
    }
};

