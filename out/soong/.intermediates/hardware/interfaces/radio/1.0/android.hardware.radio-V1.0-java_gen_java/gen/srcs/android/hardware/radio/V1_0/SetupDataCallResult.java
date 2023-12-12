package android.hardware.radio.V1_0;


public final class SetupDataCallResult {
    public int status = 0;
    public int suggestedRetryTime = 0;
    public int cid = 0;
    public int active = 0;
    public String type = new String();
    public String ifname = new String();
    public String addresses = new String();
    public String dnses = new String();
    public String gateways = new String();
    public String pcscf = new String();
    public int mtu = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.SetupDataCallResult.class) {
            return false;
        }
        android.hardware.radio.V1_0.SetupDataCallResult other = (android.hardware.radio.V1_0.SetupDataCallResult)otherObject;
        if (this.status != other.status) {
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
        if (!android.os.HidlSupport.deepEquals(this.type, other.type)) {
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
        if (this.mtu != other.mtu) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.status), 
                android.os.HidlSupport.deepHashCode(this.suggestedRetryTime), 
                android.os.HidlSupport.deepHashCode(this.cid), 
                android.os.HidlSupport.deepHashCode(this.active), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.ifname), 
                android.os.HidlSupport.deepHashCode(this.addresses), 
                android.os.HidlSupport.deepHashCode(this.dnses), 
                android.os.HidlSupport.deepHashCode(this.gateways), 
                android.os.HidlSupport.deepHashCode(this.pcscf), 
                android.os.HidlSupport.deepHashCode(this.mtu));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".status = ");
        builder.append(android.hardware.radio.V1_0.DataCallFailCause.toString(this.status));
        builder.append(", .suggestedRetryTime = ");
        builder.append(this.suggestedRetryTime);
        builder.append(", .cid = ");
        builder.append(this.cid);
        builder.append(", .active = ");
        builder.append(this.active);
        builder.append(", .type = ");
        builder.append(this.type);
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
        builder.append(", .mtu = ");
        builder.append(this.mtu);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SetupDataCallResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SetupDataCallResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.SetupDataCallResult _hidl_vec_element = new android.hardware.radio.V1_0.SetupDataCallResult();
                ((android.hardware.radio.V1_0.SetupDataCallResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        status = _hidl_blob.getInt32(_hidl_offset + 0);
        suggestedRetryTime = _hidl_blob.getInt32(_hidl_offset + 4);
        cid = _hidl_blob.getInt32(_hidl_offset + 8);
        active = _hidl_blob.getInt32(_hidl_offset + 12);
        type = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) type).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ifname = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) ifname).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        addresses = _hidl_blob.getString(_hidl_offset + 48);

        parcel.readEmbeddedBuffer(
                ((String) addresses).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 48 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        dnses = _hidl_blob.getString(_hidl_offset + 64);

        parcel.readEmbeddedBuffer(
                ((String) dnses).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 64 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        gateways = _hidl_blob.getString(_hidl_offset + 80);

        parcel.readEmbeddedBuffer(
                ((String) gateways).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 80 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        pcscf = _hidl_blob.getString(_hidl_offset + 96);

        parcel.readEmbeddedBuffer(
                ((String) pcscf).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 96 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        mtu = _hidl_blob.getInt32(_hidl_offset + 112);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
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
        _hidl_blob.putInt32(_hidl_offset + 0, status);
        _hidl_blob.putInt32(_hidl_offset + 4, suggestedRetryTime);
        _hidl_blob.putInt32(_hidl_offset + 8, cid);
        _hidl_blob.putInt32(_hidl_offset + 12, active);
        _hidl_blob.putString(_hidl_offset + 16, type);
        _hidl_blob.putString(_hidl_offset + 32, ifname);
        _hidl_blob.putString(_hidl_offset + 48, addresses);
        _hidl_blob.putString(_hidl_offset + 64, dnses);
        _hidl_blob.putString(_hidl_offset + 80, gateways);
        _hidl_blob.putString(_hidl_offset + 96, pcscf);
        _hidl_blob.putInt32(_hidl_offset + 112, mtu);
    }
};

