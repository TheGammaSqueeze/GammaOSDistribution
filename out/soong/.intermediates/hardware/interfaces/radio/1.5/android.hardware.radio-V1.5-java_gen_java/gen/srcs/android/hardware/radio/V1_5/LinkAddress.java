package android.hardware.radio.V1_5;


public final class LinkAddress {
    /**
     * The format is IP address with optional "/"
     * prefix length (The format is defined in RFC-4291 section 2.3). For example, "192.0.1.3",
     * "192.0.1.11/16", or "2001:db8::1/64". Typically one IPv4 or one IPv6 or one of each. If
     * the prefix length is absent, then the addresses are assumed to be point to point with
     * IPv4 with prefix length 32 or IPv6 with prefix length 128.
     */
    public String address = new String();
    /**
     * The properties of the link address
     */
    public int properties;
    /**
     * The time, as reported by SystemClock.elapsedRealtime(), when this link address will be or
     * was deprecated. -1 indicates this information is not available. At the time existing
     * connections can still use this address until it expires, but new connections should use the
     * new address. LONG_MAX(0x7FFFFFFFFFFFFFFF) indicates this link address will never be
     * deprecated.
     */
    public long deprecationTime = 0L;
    /**
     * The time, as reported by SystemClock.elapsedRealtime(), when this link address will expire
     * and be removed from the interface. -1 indicates this information is not available.
     * LONG_MAX(0x7FFFFFFFFFFFFFFF) indicates this link address will never expire.
     */
    public long expirationTime = 0L;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.LinkAddress.class) {
            return false;
        }
        android.hardware.radio.V1_5.LinkAddress other = (android.hardware.radio.V1_5.LinkAddress)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.address, other.address)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.properties, other.properties)) {
            return false;
        }
        if (this.deprecationTime != other.deprecationTime) {
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
                android.os.HidlSupport.deepHashCode(this.address), 
                android.os.HidlSupport.deepHashCode(this.properties), 
                android.os.HidlSupport.deepHashCode(this.deprecationTime), 
                android.os.HidlSupport.deepHashCode(this.expirationTime));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".address = ");
        builder.append(this.address);
        builder.append(", .properties = ");
        builder.append(android.hardware.radio.V1_5.AddressProperty.dumpBitfield(this.properties));
        builder.append(", .deprecationTime = ");
        builder.append(this.deprecationTime);
        builder.append(", .expirationTime = ");
        builder.append(this.expirationTime);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<LinkAddress> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<LinkAddress> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.LinkAddress _hidl_vec_element = new android.hardware.radio.V1_5.LinkAddress();
                ((android.hardware.radio.V1_5.LinkAddress) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        address = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) address).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        properties = _hidl_blob.getInt32(_hidl_offset + 16);
        deprecationTime = _hidl_blob.getInt64(_hidl_offset + 24);
        expirationTime = _hidl_blob.getInt64(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<LinkAddress> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, address);
        _hidl_blob.putInt32(_hidl_offset + 16, properties);
        _hidl_blob.putInt64(_hidl_offset + 24, deprecationTime);
        _hidl_blob.putInt64(_hidl_offset + 32, expirationTime);
    }
};

