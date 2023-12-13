package android.hardware.wifi.V1_0;


public final class StaRoamingConfig {
    /**
     * List of BSSID's that are blacklisted for roaming.
     */
    public java.util.ArrayList<byte[/* 6 */]> bssidBlacklist = new java.util.ArrayList<byte[/* 6 */]>();
    /**
     * List of SSID's that are whitelisted for roaming.
     */
    public java.util.ArrayList<byte[/* 32 */]> ssidWhitelist = new java.util.ArrayList<byte[/* 32 */]>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaRoamingConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaRoamingConfig other = (android.hardware.wifi.V1_0.StaRoamingConfig)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.bssidBlacklist, other.bssidBlacklist)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ssidWhitelist, other.ssidWhitelist)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.bssidBlacklist), 
                android.os.HidlSupport.deepHashCode(this.ssidWhitelist));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".bssidBlacklist = ");
        builder.append(this.bssidBlacklist);
        builder.append(", .ssidWhitelist = ");
        builder.append(this.ssidWhitelist);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaRoamingConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaRoamingConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaRoamingConfig _hidl_vec_element = new android.hardware.wifi.V1_0.StaRoamingConfig();
                ((android.hardware.wifi.V1_0.StaRoamingConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 6,_hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<byte[/* 6 */]>) bssidBlacklist).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte[/* 6 */] _hidl_vec_element = new byte[6];
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 6;
                    childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 6 */]) _hidl_vec_element, 6 /* size */);
                    _hidl_array_offset_1 += 6 * 1;
                }
                ((java.util.ArrayList<byte[/* 6 */]>) bssidBlacklist).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<byte[/* 32 */]>) ssidWhitelist).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte[/* 32 */] _hidl_vec_element = new byte[32];
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                    childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 32 */]) _hidl_vec_element, 32 /* size */);
                    _hidl_array_offset_1 += 32 * 1;
                }
                ((java.util.ArrayList<byte[/* 32 */]>) ssidWhitelist).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaRoamingConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = bssidBlacklist.size();
            _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 6));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 6;
                    byte[] _hidl_array_item_1 = (byte[/* 6 */]) bssidBlacklist.get(_hidl_index_0);

                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                    _hidl_array_offset_1 += 6 * 1;
                }
            }
            _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = ssidWhitelist.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                    byte[] _hidl_array_item_1 = (byte[/* 32 */]) ssidWhitelist.get(_hidl_index_0);

                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 32) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                    _hidl_array_offset_1 += 32 * 1;
                }
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

