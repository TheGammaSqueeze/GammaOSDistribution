package android.hardware.wifi.V1_0;


public final class RttLcrInformation {
    /**
     * Country code symbol.
     */
    public byte[/* 2 */] countryCode = new byte[2];
    /**
     * Civic info to be copied in FTM frame.
     */
    public String civicInfo = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.RttLcrInformation.class) {
            return false;
        }
        android.hardware.wifi.V1_0.RttLcrInformation other = (android.hardware.wifi.V1_0.RttLcrInformation)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.countryCode, other.countryCode)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.civicInfo, other.civicInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.countryCode), 
                android.os.HidlSupport.deepHashCode(this.civicInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".countryCode = ");
        builder.append(java.util.Arrays.toString(this.countryCode));
        builder.append(", .civicInfo = ");
        builder.append(this.civicInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RttLcrInformation> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RttLcrInformation> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.RttLcrInformation _hidl_vec_element = new android.hardware.wifi.V1_0.RttLcrInformation();
                ((android.hardware.wifi.V1_0.RttLcrInformation) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 2 */]) countryCode, 2 /* size */);
            _hidl_array_offset_0 += 2 * 1;
        }
        civicInfo = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) civicInfo).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RttLcrInformation> _hidl_vec) {
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
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            byte[] _hidl_array_item_0 = (byte[/* 2 */]) countryCode;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 2) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 2 * 1;
        }
        _hidl_blob.putString(_hidl_offset + 8, civicInfo);
    }
};

