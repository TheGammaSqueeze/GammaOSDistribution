package android.hardware.wifi.supplicant.V1_4;


public final class ConnectionCapabilities {
    /**
     * Baseline information as defined in HAL 1.3.
     */
    public android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities V1_3 = new android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities();
    /**
     * detailed network mode for legacy network
     */
    public int legacyMode = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities.class) {
            return false;
        }
        android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities other = (android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.V1_3, other.V1_3)) {
            return false;
        }
        if (this.legacyMode != other.legacyMode) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.V1_3), 
                android.os.HidlSupport.deepHashCode(this.legacyMode));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".V1_3 = ");
        builder.append(this.V1_3);
        builder.append(", .legacyMode = ");
        builder.append(android.hardware.wifi.supplicant.V1_4.LegacyMode.toString(this.legacyMode));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ConnectionCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ConnectionCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities _hidl_vec_element = new android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities();
                ((android.hardware.wifi.supplicant.V1_4.ConnectionCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.supplicant.V1_3.ConnectionCapabilities) V1_3).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        legacyMode = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ConnectionCapabilities> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        V1_3.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 16, legacyMode);
    }
};

