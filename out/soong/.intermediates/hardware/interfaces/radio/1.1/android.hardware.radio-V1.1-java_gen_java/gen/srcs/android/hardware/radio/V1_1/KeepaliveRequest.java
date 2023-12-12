package android.hardware.radio.V1_1;


public final class KeepaliveRequest {
    public int type = 0;
    public java.util.ArrayList<Byte> sourceAddress = new java.util.ArrayList<Byte>();
    public int sourcePort = 0;
    public java.util.ArrayList<Byte> destinationAddress = new java.util.ArrayList<Byte>();
    public int destinationPort = 0;
    public int maxKeepaliveIntervalMillis = 0;
    public int cid = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_1.KeepaliveRequest.class) {
            return false;
        }
        android.hardware.radio.V1_1.KeepaliveRequest other = (android.hardware.radio.V1_1.KeepaliveRequest)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.sourceAddress, other.sourceAddress)) {
            return false;
        }
        if (this.sourcePort != other.sourcePort) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.destinationAddress, other.destinationAddress)) {
            return false;
        }
        if (this.destinationPort != other.destinationPort) {
            return false;
        }
        if (this.maxKeepaliveIntervalMillis != other.maxKeepaliveIntervalMillis) {
            return false;
        }
        if (this.cid != other.cid) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.sourceAddress), 
                android.os.HidlSupport.deepHashCode(this.sourcePort), 
                android.os.HidlSupport.deepHashCode(this.destinationAddress), 
                android.os.HidlSupport.deepHashCode(this.destinationPort), 
                android.os.HidlSupport.deepHashCode(this.maxKeepaliveIntervalMillis), 
                android.os.HidlSupport.deepHashCode(this.cid));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.radio.V1_1.KeepaliveType.toString(this.type));
        builder.append(", .sourceAddress = ");
        builder.append(this.sourceAddress);
        builder.append(", .sourcePort = ");
        builder.append(this.sourcePort);
        builder.append(", .destinationAddress = ");
        builder.append(this.destinationAddress);
        builder.append(", .destinationPort = ");
        builder.append(this.destinationPort);
        builder.append(", .maxKeepaliveIntervalMillis = ");
        builder.append(this.maxKeepaliveIntervalMillis);
        builder.append(", .cid = ");
        builder.append(this.cid);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<KeepaliveRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<KeepaliveRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_1.KeepaliveRequest _hidl_vec_element = new android.hardware.radio.V1_1.KeepaliveRequest();
                ((android.hardware.radio.V1_1.KeepaliveRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        type = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) sourceAddress).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) sourceAddress).add(_hidl_vec_element);
            }
        }
        sourcePort = _hidl_blob.getInt32(_hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) destinationAddress).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) destinationAddress).add(_hidl_vec_element);
            }
        }
        destinationPort = _hidl_blob.getInt32(_hidl_offset + 48);
        maxKeepaliveIntervalMillis = _hidl_blob.getInt32(_hidl_offset + 52);
        cid = _hidl_blob.getInt32(_hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<KeepaliveRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        {
            int _hidl_vec_size = sourceAddress.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, sourceAddress.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, sourcePort);
        {
            int _hidl_vec_size = destinationAddress.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, destinationAddress.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 48, destinationPort);
        _hidl_blob.putInt32(_hidl_offset + 52, maxKeepaliveIntervalMillis);
        _hidl_blob.putInt32(_hidl_offset + 56, cid);
    }
};

