package android.hardware.radio.V1_6;


public final class QosSession {
    /**
     * Unique ID of the QoS session within the data call
     */
    public int qosSessionId = 0;
    /**
     * QOS attributes
     */
    public android.hardware.radio.V1_6.Qos qos = new android.hardware.radio.V1_6.Qos();
    /**
     * List of QOS filters associated with this session
     */
    public java.util.ArrayList<android.hardware.radio.V1_6.QosFilter> qosFilters = new java.util.ArrayList<android.hardware.radio.V1_6.QosFilter>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.QosSession.class) {
            return false;
        }
        android.hardware.radio.V1_6.QosSession other = (android.hardware.radio.V1_6.QosSession)otherObject;
        if (this.qosSessionId != other.qosSessionId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.qos, other.qos)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.qosFilters, other.qosFilters)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.qosSessionId), 
                android.os.HidlSupport.deepHashCode(this.qos), 
                android.os.HidlSupport.deepHashCode(this.qosFilters));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".qosSessionId = ");
        builder.append(this.qosSessionId);
        builder.append(", .qos = ");
        builder.append(this.qos);
        builder.append(", .qosFilters = ");
        builder.append(this.qosFilters);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<QosSession> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<QosSession> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.QosSession _hidl_vec_element = new android.hardware.radio.V1_6.QosSession();
                ((android.hardware.radio.V1_6.QosSession) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        qosSessionId = _hidl_blob.getInt32(_hidl_offset + 0);
        ((android.hardware.radio.V1_6.Qos) qos).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_6.QosFilter>) qosFilters).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.QosFilter _hidl_vec_element = new android.hardware.radio.V1_6.QosFilter();
                ((android.hardware.radio.V1_6.QosFilter) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                ((java.util.ArrayList<android.hardware.radio.V1_6.QosFilter>) qosFilters).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<QosSession> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, qosSessionId);
        qos.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
        {
            int _hidl_vec_size = qosFilters.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                qosFilters.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

