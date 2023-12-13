package android.hardware.radio.config.V1_1;


public final class PhoneCapability {
    /**
     * maxActiveData defines how many logical modems can have
     * PS attached simultaneously. For example, for L+L modem it
     * should be 2.
     */
    public byte maxActiveData = 0;
    /**
     * maxActiveData defines how many logical modems can have
     * internet PDN connections simultaneously. For example, for L+L
     * DSDS modem it’s 1, and for DSDA modem it’s 2.
     */
    public byte maxActiveInternetData = 0;
    /**
     * Whether modem supports both internet PDN up so
     * that we can do ping test before tearing down the
     * other one.
     */
    public boolean isInternetLingeringSupported = false;
    /**
     * List of logical modem information.
     */
    public java.util.ArrayList<android.hardware.radio.config.V1_1.ModemInfo> logicalModemList = new java.util.ArrayList<android.hardware.radio.config.V1_1.ModemInfo>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.config.V1_1.PhoneCapability.class) {
            return false;
        }
        android.hardware.radio.config.V1_1.PhoneCapability other = (android.hardware.radio.config.V1_1.PhoneCapability)otherObject;
        if (this.maxActiveData != other.maxActiveData) {
            return false;
        }
        if (this.maxActiveInternetData != other.maxActiveInternetData) {
            return false;
        }
        if (this.isInternetLingeringSupported != other.isInternetLingeringSupported) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.logicalModemList, other.logicalModemList)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maxActiveData), 
                android.os.HidlSupport.deepHashCode(this.maxActiveInternetData), 
                android.os.HidlSupport.deepHashCode(this.isInternetLingeringSupported), 
                android.os.HidlSupport.deepHashCode(this.logicalModemList));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maxActiveData = ");
        builder.append(this.maxActiveData);
        builder.append(", .maxActiveInternetData = ");
        builder.append(this.maxActiveInternetData);
        builder.append(", .isInternetLingeringSupported = ");
        builder.append(this.isInternetLingeringSupported);
        builder.append(", .logicalModemList = ");
        builder.append(this.logicalModemList);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhoneCapability> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhoneCapability> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.config.V1_1.PhoneCapability _hidl_vec_element = new android.hardware.radio.config.V1_1.PhoneCapability();
                ((android.hardware.radio.config.V1_1.PhoneCapability) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maxActiveData = _hidl_blob.getInt8(_hidl_offset + 0);
        maxActiveInternetData = _hidl_blob.getInt8(_hidl_offset + 1);
        isInternetLingeringSupported = _hidl_blob.getBool(_hidl_offset + 2);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.config.V1_1.ModemInfo>) logicalModemList).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.config.V1_1.ModemInfo _hidl_vec_element = new android.hardware.radio.config.V1_1.ModemInfo();
                ((android.hardware.radio.config.V1_1.ModemInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 1);
                ((java.util.ArrayList<android.hardware.radio.config.V1_1.ModemInfo>) logicalModemList).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhoneCapability> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, maxActiveData);
        _hidl_blob.putInt8(_hidl_offset + 1, maxActiveInternetData);
        _hidl_blob.putBool(_hidl_offset + 2, isInternetLingeringSupported);
        {
            int _hidl_vec_size = logicalModemList.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                logicalModemList.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 1);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

