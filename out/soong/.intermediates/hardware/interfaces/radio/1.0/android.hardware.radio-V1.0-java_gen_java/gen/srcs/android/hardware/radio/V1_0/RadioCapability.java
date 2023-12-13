package android.hardware.radio.V1_0;


public final class RadioCapability {
    public int session = 0;
    public int phase = 0;
    public int raf;
    public String logicalModemUuid = new String();
    public int status = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.RadioCapability.class) {
            return false;
        }
        android.hardware.radio.V1_0.RadioCapability other = (android.hardware.radio.V1_0.RadioCapability)otherObject;
        if (this.session != other.session) {
            return false;
        }
        if (this.phase != other.phase) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.raf, other.raf)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.logicalModemUuid, other.logicalModemUuid)) {
            return false;
        }
        if (this.status != other.status) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.session), 
                android.os.HidlSupport.deepHashCode(this.phase), 
                android.os.HidlSupport.deepHashCode(this.raf), 
                android.os.HidlSupport.deepHashCode(this.logicalModemUuid), 
                android.os.HidlSupport.deepHashCode(this.status));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".session = ");
        builder.append(this.session);
        builder.append(", .phase = ");
        builder.append(android.hardware.radio.V1_0.RadioCapabilityPhase.toString(this.phase));
        builder.append(", .raf = ");
        builder.append(android.hardware.radio.V1_0.RadioAccessFamily.dumpBitfield(this.raf));
        builder.append(", .logicalModemUuid = ");
        builder.append(this.logicalModemUuid);
        builder.append(", .status = ");
        builder.append(android.hardware.radio.V1_0.RadioCapabilityStatus.toString(this.status));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RadioCapability> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RadioCapability> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.RadioCapability _hidl_vec_element = new android.hardware.radio.V1_0.RadioCapability();
                ((android.hardware.radio.V1_0.RadioCapability) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        session = _hidl_blob.getInt32(_hidl_offset + 0);
        phase = _hidl_blob.getInt32(_hidl_offset + 4);
        raf = _hidl_blob.getInt32(_hidl_offset + 8);
        logicalModemUuid = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) logicalModemUuid).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        status = _hidl_blob.getInt32(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RadioCapability> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, session);
        _hidl_blob.putInt32(_hidl_offset + 4, phase);
        _hidl_blob.putInt32(_hidl_offset + 8, raf);
        _hidl_blob.putString(_hidl_offset + 16, logicalModemUuid);
        _hidl_blob.putInt32(_hidl_offset + 32, status);
    }
};

