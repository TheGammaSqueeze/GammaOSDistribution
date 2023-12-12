package android.hardware.radio.V1_5;


public final class SetupDataCallResult {
    /**
     * Data call fail cause. DataCallFailCause.NONE if no error.
     */
    public int cause = 0;
    /**
     * If status != DataCallFailCause.NONE, this field indicates the suggested retry back-off timer
     * value RIL wants to override the one pre-configured in FW. The unit is milliseconds.
     * The value < 0 means no value is suggested.
     * The value 0 means retry must be done ASAP.
     * The value of INT_MAX(0x7fffffff) means no retry.
     */
    public int suggestedRetryTime = 0;
    /**
     * Context ID, uniquely identifies this call.
     */
    public int cid = 0;
    /**
     * Data connection active status.
     */
    public int active = 0;
    /**
     * PDP_type values. If cause is DataCallFailCause.ONLY_SINGLE_BEARER_ALLOWED, this is the type
     * supported such as "IP" or "IPV6".
     */
    public int type = 0;
    /**
     * The network interface name.
     */
    public String ifname = new String();
    /**
     * List of link address.
     */
    public java.util.ArrayList<android.hardware.radio.V1_5.LinkAddress> addresses = new java.util.ArrayList<android.hardware.radio.V1_5.LinkAddress>();
    /**
     * List of DNS server addresses, e.g., "192.0.1.3" or "192.0.1.11 2001:db8::1". Empty if no dns
     * server addresses returned.
     */
    public java.util.ArrayList<String> dnses = new java.util.ArrayList<String>();
    /**
     * List of default gateway addresses, e.g., "192.0.1.3" or "192.0.1.11 2001:db8::1".
     * When empty, the addresses represent point to point connections.
     */
    public java.util.ArrayList<String> gateways = new java.util.ArrayList<String>();
    /**
     * List of P-CSCF(Proxy Call State Control Function) addresses via PCO(Protocol Configuration
     * Option), e.g., "2001:db8::1 2001:db8::2 2001:db8::3". Empty if not IMS client.
     */
    public java.util.ArrayList<String> pcscf = new java.util.ArrayList<String>();
    /**
     * MTU received from network for IPv4.
     * Value <= 0 means network has either not sent a value or sent an invalid value.
     */
    public int mtuV4 = 0;
    /**
     * MTU received from network for IPv6.
     * Value <= 0 means network has either not sent a value or sent an invalid value.
     */
    public int mtuV6 = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.SetupDataCallResult.class) {
            return false;
        }
        android.hardware.radio.V1_5.SetupDataCallResult other = (android.hardware.radio.V1_5.SetupDataCallResult)otherObject;
        if (this.cause != other.cause) {
            return false;
        }
        if (this.suggestedRetryTime != other.suggestedRetryTime) {
            return false;
        }
        if (this.cid != other.cid) {
            return false;
        }
        if (this.active != other.active) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ifname, other.ifname)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.addresses, other.addresses)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.dnses, other.dnses)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.gateways, other.gateways)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.pcscf, other.pcscf)) {
            return false;
        }
        if (this.mtuV4 != other.mtuV4) {
            return false;
        }
        if (this.mtuV6 != other.mtuV6) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cause), 
                android.os.HidlSupport.deepHashCode(this.suggestedRetryTime), 
                android.os.HidlSupport.deepHashCode(this.cid), 
                android.os.HidlSupport.deepHashCode(this.active), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.ifname), 
                android.os.HidlSupport.deepHashCode(this.addresses), 
                android.os.HidlSupport.deepHashCode(this.dnses), 
                android.os.HidlSupport.deepHashCode(this.gateways), 
                android.os.HidlSupport.deepHashCode(this.pcscf), 
                android.os.HidlSupport.deepHashCode(this.mtuV4), 
                android.os.HidlSupport.deepHashCode(this.mtuV6));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cause = ");
        builder.append(android.hardware.radio.V1_4.DataCallFailCause.toString(this.cause));
        builder.append(", .suggestedRetryTime = ");
        builder.append(this.suggestedRetryTime);
        builder.append(", .cid = ");
        builder.append(this.cid);
        builder.append(", .active = ");
        builder.append(android.hardware.radio.V1_4.DataConnActiveStatus.toString(this.active));
        builder.append(", .type = ");
        builder.append(android.hardware.radio.V1_4.PdpProtocolType.toString(this.type));
        builder.append(", .ifname = ");
        builder.append(this.ifname);
        builder.append(", .addresses = ");
        builder.append(this.addresses);
        builder.append(", .dnses = ");
        builder.append(this.dnses);
        builder.append(", .gateways = ");
        builder.append(this.gateways);
        builder.append(", .pcscf = ");
        builder.append(this.pcscf);
        builder.append(", .mtuV4 = ");
        builder.append(this.mtuV4);
        builder.append(", .mtuV6 = ");
        builder.append(this.mtuV6);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SetupDataCallResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SetupDataCallResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.SetupDataCallResult _hidl_vec_element = new android.hardware.radio.V1_5.SetupDataCallResult();
                ((android.hardware.radio.V1_5.SetupDataCallResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cause = _hidl_blob.getInt32(_hidl_offset + 0);
        suggestedRetryTime = _hidl_blob.getInt32(_hidl_offset + 4);
        cid = _hidl_blob.getInt32(_hidl_offset + 8);
        active = _hidl_blob.getInt32(_hidl_offset + 12);
        type = _hidl_blob.getInt32(_hidl_offset + 16);
        ifname = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) ifname).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_5.LinkAddress>) addresses).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.LinkAddress _hidl_vec_element = new android.hardware.radio.V1_5.LinkAddress();
                ((android.hardware.radio.V1_5.LinkAddress) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                ((java.util.ArrayList<android.hardware.radio.V1_5.LinkAddress>) addresses).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) dnses).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) dnses).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) gateways).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) gateways).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) pcscf).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) pcscf).add(_hidl_vec_element);
            }
        }
        mtuV4 = _hidl_blob.getInt32(_hidl_offset + 104);
        mtuV6 = _hidl_blob.getInt32(_hidl_offset + 108);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SetupDataCallResult> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, cause);
        _hidl_blob.putInt32(_hidl_offset + 4, suggestedRetryTime);
        _hidl_blob.putInt32(_hidl_offset + 8, cid);
        _hidl_blob.putInt32(_hidl_offset + 12, active);
        _hidl_blob.putInt32(_hidl_offset + 16, type);
        _hidl_blob.putString(_hidl_offset + 24, ifname);
        {
            int _hidl_vec_size = addresses.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                addresses.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = dnses.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, dnses.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = gateways.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, gateways.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = pcscf.size();
            _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, pcscf.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 104, mtuV4);
        _hidl_blob.putInt32(_hidl_offset + 108, mtuV6);
    }
};

