package android.hardware.wifi.V1_5;


public final class NanCapabilities {
    /**
     * Baseline information as defined in HAL 1.0.
     */
    public android.hardware.wifi.V1_0.NanCapabilities V1_0 = new android.hardware.wifi.V1_0.NanCapabilities();
    /**
     * Flag to indicate id instant communication mode is supported.
     */
    public boolean instantCommunicationModeSupportFlag = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_5.NanCapabilities.class) {
            return false;
        }
        android.hardware.wifi.V1_5.NanCapabilities other = (android.hardware.wifi.V1_5.NanCapabilities)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.V1_0, other.V1_0)) {
            return false;
        }
        if (this.instantCommunicationModeSupportFlag != other.instantCommunicationModeSupportFlag) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.V1_0), 
                android.os.HidlSupport.deepHashCode(this.instantCommunicationModeSupportFlag));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".V1_0 = ");
        builder.append(this.V1_0);
        builder.append(", .instantCommunicationModeSupportFlag = ");
        builder.append(this.instantCommunicationModeSupportFlag);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(60 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 60,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.NanCapabilities _hidl_vec_element = new android.hardware.wifi.V1_5.NanCapabilities();
                ((android.hardware.wifi.V1_5.NanCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 60);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.NanCapabilities) V1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        instantCommunicationModeSupportFlag = _hidl_blob.getBool(_hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(60 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanCapabilities> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 60));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 60);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        V1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putBool(_hidl_offset + 56, instantCommunicationModeSupportFlag);
    }
};

