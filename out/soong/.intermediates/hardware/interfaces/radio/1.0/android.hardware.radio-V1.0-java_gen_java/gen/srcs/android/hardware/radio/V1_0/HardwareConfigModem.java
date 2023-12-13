package android.hardware.radio.V1_0;


public final class HardwareConfigModem {
    public int rilModel = 0;
    public int rat = 0;
    public int maxVoice = 0;
    public int maxData = 0;
    public int maxStandby = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.HardwareConfigModem.class) {
            return false;
        }
        android.hardware.radio.V1_0.HardwareConfigModem other = (android.hardware.radio.V1_0.HardwareConfigModem)otherObject;
        if (this.rilModel != other.rilModel) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (this.maxVoice != other.maxVoice) {
            return false;
        }
        if (this.maxData != other.maxData) {
            return false;
        }
        if (this.maxStandby != other.maxStandby) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.rilModel), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.maxVoice), 
                android.os.HidlSupport.deepHashCode(this.maxData), 
                android.os.HidlSupport.deepHashCode(this.maxStandby));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".rilModel = ");
        builder.append(this.rilModel);
        builder.append(", .rat = ");
        builder.append(this.rat);
        builder.append(", .maxVoice = ");
        builder.append(this.maxVoice);
        builder.append(", .maxData = ");
        builder.append(this.maxData);
        builder.append(", .maxStandby = ");
        builder.append(this.maxStandby);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HardwareConfigModem> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HardwareConfigModem> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.HardwareConfigModem _hidl_vec_element = new android.hardware.radio.V1_0.HardwareConfigModem();
                ((android.hardware.radio.V1_0.HardwareConfigModem) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        rilModel = _hidl_blob.getInt32(_hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 4);
        maxVoice = _hidl_blob.getInt32(_hidl_offset + 8);
        maxData = _hidl_blob.getInt32(_hidl_offset + 12);
        maxStandby = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<HardwareConfigModem> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, rilModel);
        _hidl_blob.putInt32(_hidl_offset + 4, rat);
        _hidl_blob.putInt32(_hidl_offset + 8, maxVoice);
        _hidl_blob.putInt32(_hidl_offset + 12, maxData);
        _hidl_blob.putInt32(_hidl_offset + 16, maxStandby);
    }
};

