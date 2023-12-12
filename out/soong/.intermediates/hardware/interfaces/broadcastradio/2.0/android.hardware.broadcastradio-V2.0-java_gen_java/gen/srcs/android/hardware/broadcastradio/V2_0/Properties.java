package android.hardware.broadcastradio.V2_0;


public final class Properties {
    /**
     * A company name who made the radio module. Must be a valid, registered
     * name of the company itself.
     *
     * It must be opaque to the Android framework.
     */
    public String maker = new String();
    /**
     * A product name. Must be unique within the company.
     *
     * It must be opaque to the Android framework.
     */
    public String product = new String();
    /**
     * Version of the hardware module.
     *
     * It must be opaque to the Android framework.
     */
    public String version = new String();
    /**
     * Hardware serial number (for subscription services).
     *
     * It must be opaque to the Android framework.
     */
    public String serial = new String();
    /**
     * A list of supported IdentifierType values.
     *
     * If an identifier is supported by radio module, it means it can use it for
     * tuning to ProgramSelector with either primary or secondary Identifier of
     * a given type.
     *
     * Support for VENDOR identifier type does not guarantee compatibility, as
     * other module properties (implementor, product, version) must be checked.
     */
    public java.util.ArrayList<Integer> supportedIdentifierTypes = new java.util.ArrayList<Integer>();
    /**
     * Vendor-specific information.
     *
     * It may be used for extra features, not supported by the platform,
     * for example: com.me.preset-slots=6; com.me.ultra-hd-capable=false.
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> vendorInfo = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.Properties.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.Properties other = (android.hardware.broadcastradio.V2_0.Properties)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.maker, other.maker)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.product, other.product)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.version, other.version)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serial, other.serial)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedIdentifierTypes, other.supportedIdentifierTypes)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.vendorInfo, other.vendorInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maker), 
                android.os.HidlSupport.deepHashCode(this.product), 
                android.os.HidlSupport.deepHashCode(this.version), 
                android.os.HidlSupport.deepHashCode(this.serial), 
                android.os.HidlSupport.deepHashCode(this.supportedIdentifierTypes), 
                android.os.HidlSupport.deepHashCode(this.vendorInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maker = ");
        builder.append(this.maker);
        builder.append(", .product = ");
        builder.append(this.product);
        builder.append(", .version = ");
        builder.append(this.version);
        builder.append(", .serial = ");
        builder.append(this.serial);
        builder.append(", .supportedIdentifierTypes = ");
        builder.append(this.supportedIdentifierTypes);
        builder.append(", .vendorInfo = ");
        builder.append(this.vendorInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(96 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Properties> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Properties> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.Properties _hidl_vec_element = new android.hardware.broadcastradio.V2_0.Properties();
                ((android.hardware.broadcastradio.V2_0.Properties) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maker = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) maker).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        product = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) product).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        version = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) version).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        serial = _hidl_blob.getString(_hidl_offset + 48);

        parcel.readEmbeddedBuffer(
                ((String) serial).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 48 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) supportedIdentifierTypes).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) supportedIdentifierTypes).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>) vendorInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.VendorKeyValue _hidl_vec_element = new android.hardware.broadcastradio.V2_0.VendorKeyValue();
                ((android.hardware.broadcastradio.V2_0.VendorKeyValue) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>) vendorInfo).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(96 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<Properties> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, maker);
        _hidl_blob.putString(_hidl_offset + 16, product);
        _hidl_blob.putString(_hidl_offset + 32, version);
        _hidl_blob.putString(_hidl_offset + 48, serial);
        {
            int _hidl_vec_size = supportedIdentifierTypes.size();
            _hidl_blob.putInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 64 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, supportedIdentifierTypes.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = vendorInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                vendorInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

