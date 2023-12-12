package android.hardware.radio.V1_5;


public final class DataProfileInfo {
    /**
     * ID of the data profile.
     */
    public int profileId = 0;
    /**
     * The APN name.
     */
    public String apn = new String();
    /**
     * PDP_type values.
     */
    public int protocol = 0;
    /**
     * PDP_type values used on roaming network.
     */
    public int roamingProtocol = 0;
    /**
     * APN authentication type.
     */
    public int authType = 0;
    /**
     * The username for APN, or empty string.
     */
    public String user = new String();
    /**
     * The password for APN, or empty string.
     */
    public String password = new String();
    /**
     * Data profile technology type.
     */
    public int type = 0;
    /**
     * The period in seconds to limit the maximum connections.
     */
    public int maxConnsTime = 0;
    /**
     * The maximum connections during maxConnsTime.
     */
    public int maxConns = 0;
    /**
     * The required wait time in seconds after a successful UE initiated disconnect of a given PDN
     * connection before the device can send a new PDN connection request for that given PDN.
     */
    public int waitTime = 0;
    /**
     * True to enable the profile, false to disable.
     */
    public boolean enabled = false;
    /**
     * Supported APN types bitmap. See ApnTypes for the value of each bit.
     */
    public int supportedApnTypesBitmap;
    /**
     * The bearer bitmap. See RadioAccessFamily for the value of each bit.
     */
    public int bearerBitmap;
    /**
     * Maximum transmission unit (MTU) size in bytes for IPv4.
     */
    public int mtuV4 = 0;
    /**
     * Maximum transmission unit (MTU) size in bytes for IPv6.
     */
    public int mtuV6 = 0;
    /**
     * True if this data profile was used to bring up the last default (i.e internet) data
     * connection successfully.
     */
    public boolean preferred = false;
    /**
     * If true, modem must persist this data profile and profileId must not be
     * set to DataProfileId.INVALID. If the same data profile exists, this data profile must
     * overwrite it.
     */
    public boolean persistent = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.DataProfileInfo.class) {
            return false;
        }
        android.hardware.radio.V1_5.DataProfileInfo other = (android.hardware.radio.V1_5.DataProfileInfo)otherObject;
        if (this.profileId != other.profileId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.apn, other.apn)) {
            return false;
        }
        if (this.protocol != other.protocol) {
            return false;
        }
        if (this.roamingProtocol != other.roamingProtocol) {
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
        if (this.mtuV4 != other.mtuV4) {
            return false;
        }
        if (this.mtuV6 != other.mtuV6) {
            return false;
        }
        if (this.preferred != other.preferred) {
            return false;
        }
        if (this.persistent != other.persistent) {
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
                android.os.HidlSupport.deepHashCode(this.mtuV4), 
                android.os.HidlSupport.deepHashCode(this.mtuV6), 
                android.os.HidlSupport.deepHashCode(this.preferred), 
                android.os.HidlSupport.deepHashCode(this.persistent));
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
        builder.append(android.hardware.radio.V1_4.PdpProtocolType.toString(this.protocol));
        builder.append(", .roamingProtocol = ");
        builder.append(android.hardware.radio.V1_4.PdpProtocolType.toString(this.roamingProtocol));
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
        builder.append(android.hardware.radio.V1_5.ApnTypes.dumpBitfield(this.supportedApnTypesBitmap));
        builder.append(", .bearerBitmap = ");
        builder.append(android.hardware.radio.V1_4.RadioAccessFamily.dumpBitfield(this.bearerBitmap));
        builder.append(", .mtuV4 = ");
        builder.append(this.mtuV4);
        builder.append(", .mtuV6 = ");
        builder.append(this.mtuV6);
        builder.append(", .preferred = ");
        builder.append(this.preferred);
        builder.append(", .persistent = ");
        builder.append(this.persistent);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<DataProfileInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<DataProfileInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.DataProfileInfo _hidl_vec_element = new android.hardware.radio.V1_5.DataProfileInfo();
                ((android.hardware.radio.V1_5.DataProfileInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
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

        protocol = _hidl_blob.getInt32(_hidl_offset + 24);
        roamingProtocol = _hidl_blob.getInt32(_hidl_offset + 28);
        authType = _hidl_blob.getInt32(_hidl_offset + 32);
        user = _hidl_blob.getString(_hidl_offset + 40);

        parcel.readEmbeddedBuffer(
                ((String) user).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        password = _hidl_blob.getString(_hidl_offset + 56);

        parcel.readEmbeddedBuffer(
                ((String) password).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 56 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        type = _hidl_blob.getInt32(_hidl_offset + 72);
        maxConnsTime = _hidl_blob.getInt32(_hidl_offset + 76);
        maxConns = _hidl_blob.getInt32(_hidl_offset + 80);
        waitTime = _hidl_blob.getInt32(_hidl_offset + 84);
        enabled = _hidl_blob.getBool(_hidl_offset + 88);
        supportedApnTypesBitmap = _hidl_blob.getInt32(_hidl_offset + 92);
        bearerBitmap = _hidl_blob.getInt32(_hidl_offset + 96);
        mtuV4 = _hidl_blob.getInt32(_hidl_offset + 100);
        mtuV6 = _hidl_blob.getInt32(_hidl_offset + 104);
        preferred = _hidl_blob.getBool(_hidl_offset + 108);
        persistent = _hidl_blob.getBool(_hidl_offset + 109);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
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
        _hidl_blob.putInt32(_hidl_offset + 0, profileId);
        _hidl_blob.putString(_hidl_offset + 8, apn);
        _hidl_blob.putInt32(_hidl_offset + 24, protocol);
        _hidl_blob.putInt32(_hidl_offset + 28, roamingProtocol);
        _hidl_blob.putInt32(_hidl_offset + 32, authType);
        _hidl_blob.putString(_hidl_offset + 40, user);
        _hidl_blob.putString(_hidl_offset + 56, password);
        _hidl_blob.putInt32(_hidl_offset + 72, type);
        _hidl_blob.putInt32(_hidl_offset + 76, maxConnsTime);
        _hidl_blob.putInt32(_hidl_offset + 80, maxConns);
        _hidl_blob.putInt32(_hidl_offset + 84, waitTime);
        _hidl_blob.putBool(_hidl_offset + 88, enabled);
        _hidl_blob.putInt32(_hidl_offset + 92, supportedApnTypesBitmap);
        _hidl_blob.putInt32(_hidl_offset + 96, bearerBitmap);
        _hidl_blob.putInt32(_hidl_offset + 100, mtuV4);
        _hidl_blob.putInt32(_hidl_offset + 104, mtuV6);
        _hidl_blob.putBool(_hidl_offset + 108, preferred);
        _hidl_blob.putBool(_hidl_offset + 109, persistent);
    }
};

