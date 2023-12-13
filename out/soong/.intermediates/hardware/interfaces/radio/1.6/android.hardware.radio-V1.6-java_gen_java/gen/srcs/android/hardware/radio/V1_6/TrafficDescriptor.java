package android.hardware.radio.V1_6;


public final class TrafficDescriptor {
    /**
     * DNN stands for Data Network Name and represents an APN as defined in
     * 3GPP TS 23.003.
     */
    public android.hardware.radio.V1_6.OptionalDnn dnn = new android.hardware.radio.V1_6.OptionalDnn();
    /**
     * Indicates the OsId + OsAppId (used as category in Android).
     */
    public android.hardware.radio.V1_6.OptionalOsAppId osAppId = new android.hardware.radio.V1_6.OptionalOsAppId();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.TrafficDescriptor.class) {
            return false;
        }
        android.hardware.radio.V1_6.TrafficDescriptor other = (android.hardware.radio.V1_6.TrafficDescriptor)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.dnn, other.dnn)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.osAppId, other.osAppId)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.dnn), 
                android.os.HidlSupport.deepHashCode(this.osAppId));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".dnn = ");
        builder.append(this.dnn);
        builder.append(", .osAppId = ");
        builder.append(this.osAppId);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<TrafficDescriptor> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<TrafficDescriptor> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.TrafficDescriptor _hidl_vec_element = new android.hardware.radio.V1_6.TrafficDescriptor();
                ((android.hardware.radio.V1_6.TrafficDescriptor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_6.OptionalDnn) dnn).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_6.OptionalOsAppId) osAppId).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 24);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<TrafficDescriptor> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        dnn.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        osAppId.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 24);
    }
};

