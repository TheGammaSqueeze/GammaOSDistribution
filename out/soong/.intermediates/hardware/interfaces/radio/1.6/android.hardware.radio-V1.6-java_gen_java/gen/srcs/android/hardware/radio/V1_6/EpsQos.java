package android.hardware.radio.V1_6;


public final class EpsQos {
    /**
     * Quality of Service Class Identifier (QCI), see 3GPP TS 23.203 and 29.212.
     * The allowed values are standard values(1-9, 65-68, 69-70, 75, 79-80, 82-85)
     * defined in the spec and operator specific values in the range 128-254.
     */
    public short qci = 0;
    public android.hardware.radio.V1_6.QosBandwidth downlink = new android.hardware.radio.V1_6.QosBandwidth();
    public android.hardware.radio.V1_6.QosBandwidth uplink = new android.hardware.radio.V1_6.QosBandwidth();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.EpsQos.class) {
            return false;
        }
        android.hardware.radio.V1_6.EpsQos other = (android.hardware.radio.V1_6.EpsQos)otherObject;
        if (this.qci != other.qci) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.downlink, other.downlink)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.uplink, other.uplink)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.qci), 
                android.os.HidlSupport.deepHashCode(this.downlink), 
                android.os.HidlSupport.deepHashCode(this.uplink));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".qci = ");
        builder.append(this.qci);
        builder.append(", .downlink = ");
        builder.append(this.downlink);
        builder.append(", .uplink = ");
        builder.append(this.uplink);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<EpsQos> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<EpsQos> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.EpsQos _hidl_vec_element = new android.hardware.radio.V1_6.EpsQos();
                ((android.hardware.radio.V1_6.EpsQos) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        qci = _hidl_blob.getInt16(_hidl_offset + 0);
        ((android.hardware.radio.V1_6.QosBandwidth) downlink).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
        ((android.hardware.radio.V1_6.QosBandwidth) uplink).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<EpsQos> _hidl_vec) {
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
        _hidl_blob.putInt16(_hidl_offset + 0, qci);
        downlink.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
        uplink.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 12);
    }
};

