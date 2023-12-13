package android.hardware.radio.V1_6;


public final class NrQos {
    /**
     * 5G QOS Identifier (5QI), see 3GPP TS 24.501 and 23.501.
     * The allowed values are standard values(1-9, 65-68, 69-70, 75, 79-80, 82-85)
     * defined in the spec and operator specific values in the range 128-254.
     */
    public short fiveQi = 0;
    public android.hardware.radio.V1_6.QosBandwidth downlink = new android.hardware.radio.V1_6.QosBandwidth();
    public android.hardware.radio.V1_6.QosBandwidth uplink = new android.hardware.radio.V1_6.QosBandwidth();
    /**
     * QOS flow identifier of the QOS flow description in the
     * range of QosFlowIdRange::MIN to QosFlowIdRange::MAX
     */
    public byte qfi = 0;
    public short averagingWindowMs = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.NrQos.class) {
            return false;
        }
        android.hardware.radio.V1_6.NrQos other = (android.hardware.radio.V1_6.NrQos)otherObject;
        if (this.fiveQi != other.fiveQi) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.downlink, other.downlink)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.uplink, other.uplink)) {
            return false;
        }
        if (this.qfi != other.qfi) {
            return false;
        }
        if (this.averagingWindowMs != other.averagingWindowMs) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.fiveQi), 
                android.os.HidlSupport.deepHashCode(this.downlink), 
                android.os.HidlSupport.deepHashCode(this.uplink), 
                android.os.HidlSupport.deepHashCode(this.qfi), 
                android.os.HidlSupport.deepHashCode(this.averagingWindowMs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".fiveQi = ");
        builder.append(this.fiveQi);
        builder.append(", .downlink = ");
        builder.append(this.downlink);
        builder.append(", .uplink = ");
        builder.append(this.uplink);
        builder.append(", .qfi = ");
        builder.append(this.qfi);
        builder.append(", .averagingWindowMs = ");
        builder.append(this.averagingWindowMs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NrQos> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NrQos> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.NrQos _hidl_vec_element = new android.hardware.radio.V1_6.NrQos();
                ((android.hardware.radio.V1_6.NrQos) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        fiveQi = _hidl_blob.getInt16(_hidl_offset + 0);
        ((android.hardware.radio.V1_6.QosBandwidth) downlink).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
        ((android.hardware.radio.V1_6.QosBandwidth) uplink).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 12);
        qfi = _hidl_blob.getInt8(_hidl_offset + 20);
        averagingWindowMs = _hidl_blob.getInt16(_hidl_offset + 22);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NrQos> _hidl_vec) {
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
        _hidl_blob.putInt16(_hidl_offset + 0, fiveQi);
        downlink.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
        uplink.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 12);
        _hidl_blob.putInt8(_hidl_offset + 20, qfi);
        _hidl_blob.putInt16(_hidl_offset + 22, averagingWindowMs);
    }
};

