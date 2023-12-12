package android.hardware.radio.V1_0;


public final class DataProfileInfo {
    public int profileId = 0;
    public String apn = new String();
    public String protocol = new String();
    public String roamingProtocol = new String();
    public int authType = 0;
    public String user = new String();
    public String password = new String();
    public int type = 0;
    public int maxConnsTime = 0;
    public int maxConns = 0;
    public int waitTime = 0;
    public boolean enabled = false;
    public int supportedApnTypesBitmap;
    public int bearerBitmap;
    public int mtu = 0;
    public int mvnoType = 0;
    public String mvnoMatchData = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.DataProfileInfo.class) {
            return false;
        }
        android.hardware.radio.V1_0.DataProfileInfo other = (android.hardware.radio.V1_0.DataProfileInfo)otherObject;
        if (this.profileId != other.profileId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.apn, other.apn)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.protocol, other.protocol)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.roamingProtocol, other.roamingProtocol)) {
            return false;
        }
        if (this.authType != other.authType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.user, other.user)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.password, other.password)) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (this.maxConnsTime != other.maxConnsTime) {
            return false;
        }
        if (this.maxConns != other.maxConns) {
            return false;
        }
        if (this.waitTime != other.waitTime) {
            return false;
        }
        if (this.enabled != other.enabled) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedApnTypesBitmap, other.supportedApnTypesBitmap)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bearerBitmap, other.bearerBitmap)) {
            return false;
        }
        if (this.mtu != other.mtu) {
            return false;
        }
        if (this.mvnoType != other.mvnoType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mvnoMatchData, other.mvnoMatchData)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.profileId), 
                android.os.HidlSupport.deepHashCode(this.apn), 
                android.os.HidlSupport.deepHashCode(this.protocol), 
                android.os.HidlSupport.deepHashCode(this.roamingProtocol), 
                android.os.HidlSupport.deepHashCode(this.authType), 
                android.os.HidlSupport.deepHashCode(this.user), 
                android.os.HidlSupport.deepHashCode(this.password), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.maxConnsTime), 
                android.os.HidlSupport.deepHashCode(this.maxConns), 
                android.os.HidlSupport.deepHashCode(this.waitTime), 
                android.os.HidlSupport.deepHashCode(this.enabled), 
                android.os.HidlSupport.deepHashCode(this.supportedApnTypesBitmap), 
                android.os.HidlSupport.deepHashCode(this.bearerBitmap), 
                android.os.HidlSupport.deepHashCode(this.mtu), 
                android.os.HidlSupport.deepHashCode(this.mvnoType), 
                android.os.HidlSupport.deepHashCode(this.mvnoMatchData));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".profileId = ");
        builder.append(android.hardware.radio.V1_0.DataProfileId.toString(this.profileId));
        builder.append(", .apn = ");
        builder.append(this.apn);
        builder.append(", .protocol = ");
        builder.append(this.protocol);
        builder.append(", .roamingProtocol = ");
        builder.append(this.roamingProtocol);
        builder.append(", .authType = ");
        builder.append(android.hardware.radio.V1_0.ApnAuthType.toString(this.authType));
        builder.append(", .user = ");
        builder.append(this.user);
        builder.append(", .password = ");
        builder.append(this.password);
        builder.append(", .type = ");
        builder.append(android.hardware.radio.V1_0.DataProfileInfoType.toString(this.type));
        builder.append(", .maxConnsTime = ");
        builder.append(this.maxConnsTime);
        builder.append(", .maxConns = ");
        builder.append(this.maxConns);
        builder.append(", .waitTime = ");
        builder.append(this.waitTime);
        builder.append(", .enabled = ");
        builder.append(this.enabled);
        builder.append(", .supportedApnTypesBitmap = ");
        builder.append(android.hardware.radio.V1_0.ApnTypes.dumpBitfield(this.supportedApnTypesBitmap));
        builder.append(", .bearerBitmap = ");
        builder.append(android.hardware.radio.V1_0.RadioAccessFamily.dumpBitfield(this.bearerBitmap));
        builder.append(", .mtu = ");
        builder.append(this.mtu);
        builder.append(", .mvnoType = ");
        builder.append(android.hardware.radio.V1_0.MvnoType.toString(this.mvnoType));
        builder.append(", .mvnoMatchData = ");
        builder.append(this.mvnoMatchData);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(152 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<DataProfileInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<DataProfileInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 152,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.DataProfileInfo _hidl_vec_element = new android.hardware.radio.V1_0.DataProfileInfo();
                ((android.hardware.radio.V1_0.DataProfileInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 152);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        profileId = _hidl_blob.getInt32(_hidl_offset + 0);
        apn = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) apn).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        protocol = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) protocol).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        roamingProtocol = _hidl_blob.getString(_hidl_offset + 40);

        parcel.readEmbeddedBuffer(
                ((String) roamingProtocol).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        authType = _hidl_blob.getInt32(_hidl_offset + 56);
        user = _hidl_blob.getString(_hidl_offset + 64);

        parcel.readEmbeddedBuffer(
                ((String) user).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 64 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        password = _hidl_blob.getString(_hidl_offset + 80);

        parcel.readEmbeddedBuffer(
                ((String) password).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 80 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        type = _hidl_blob.getInt32(_hidl_offset + 96);
        maxConnsTime = _hidl_blob.getInt32(_hidl_offset + 100);
        maxConns = _hidl_blob.getInt32(_hidl_offset + 104);
        waitTime = _hidl_blob.getInt32(_hidl_offset + 108);
        enabled = _hidl_blob.getBool(_hidl_offset + 112);
        supportedApnTypesBitmap = _hidl_blob.getInt32(_hidl_offset + 116);
        bearerBitmap = _hidl_blob.getInt32(_hidl_offset + 120);
        mtu = _hidl_blob.getInt32(_hidl_offset + 124);
        mvnoType = _hidl_blob.getInt32(_hidl_offset + 128);
        mvnoMatchData = _hidl_blob.getString(_hidl_offset + 136);

        parcel.readEmbeddedBuffer(
                ((String) mvnoMatchData).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 136 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(152 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<DataProfileInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 152));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 152);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, profileId);
        _hidl_blob.putString(_hidl_offset + 8, apn);
        _hidl_blob.putString(_hidl_offset + 24, protocol);
        _hidl_blob.putString(_hidl_offset + 40, roamingProtocol);
        _hidl_blob.putInt32(_hidl_offset + 56, authType);
        _hidl_blob.putString(_hidl_offset + 64, user);
        _hidl_blob.putString(_hidl_offset + 80, password);
        _hidl_blob.putInt32(_hidl_offset + 96, type);
        _hidl_blob.putInt32(_hidl_offset + 100, maxConnsTime);
        _hidl_blob.putInt32(_hidl_offset + 104, maxConns);
        _hidl_blob.putInt32(_hidl_offset + 108, waitTime);
        _hidl_blob.putBool(_hidl_offset + 112, enabled);
        _hidl_blob.putInt32(_hidl_offset + 116, supportedApnTypesBitmap);
        _hidl_blob.putInt32(_hidl_offset + 120, bearerBitmap);
        _hidl_blob.putInt32(_hidl_offset + 124, mtu);
        _hidl_blob.putInt32(_hidl_offset + 128, mvnoType);
        _hidl_blob.putString(_hidl_offset + 136, mvnoMatchData);
    }
};

