package android.hardware.wifi.V1_0;


public final class StaRoamingCapabilities {
    /**
     * Maximum number of BSSID's that may be blacklisted.
     */
    public int maxBlacklistSize = 0;
    /**
     * Maximum number of SSID's that may be whitelisted.
     */
    public int maxWhitelistSize = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaRoamingCapabilities.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaRoamingCapabilities other = (android.hardware.wifi.V1_0.StaRoamingCapabilities)otherObject;
        if (this.maxBlacklistSize != other.maxBlacklistSize) {
            return false;
        }
        if (this.maxWhitelistSize != other.maxWhitelistSize) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maxBlacklistSize), 
                android.os.HidlSupport.deepHashCode(this.maxWhitelistSize));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maxBlacklistSize = ");
        builder.append(this.maxBlacklistSize);
        builder.append(", .maxWhitelistSize = ");
        builder.append(this.maxWhitelistSize);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(8 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaRoamingCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaRoamingCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 8,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaRoamingCapabilities _hidl_vec_element = new android.hardware.wifi.V1_0.StaRoamingCapabilities();
                ((android.hardware.wifi.V1_0.StaRoamingCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maxBlacklistSize = _hidl_blob.getInt32(_hidl_offset + 0);
        maxWhitelistSize = _hidl_blob.getInt32(_hidl_offset + 4);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaRoamingCapabilities> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, maxBlacklistSize);
        _hidl_blob.putInt32(_hidl_offset + 4, maxWhitelistSize);
    }
};

