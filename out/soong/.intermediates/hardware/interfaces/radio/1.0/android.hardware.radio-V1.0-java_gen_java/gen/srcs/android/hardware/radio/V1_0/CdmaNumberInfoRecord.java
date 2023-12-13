package android.hardware.radio.V1_0;


public final class CdmaNumberInfoRecord {
    public String number = new String();
    public byte numberType = 0;
    public byte numberPlan = 0;
    public byte pi = 0;
    public byte si = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaNumberInfoRecord.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaNumberInfoRecord other = (android.hardware.radio.V1_0.CdmaNumberInfoRecord)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        if (this.numberType != other.numberType) {
            return false;
        }
        if (this.numberPlan != other.numberPlan) {
            return false;
        }
        if (this.pi != other.pi) {
            return false;
        }
        if (this.si != other.si) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.number), 
                android.os.HidlSupport.deepHashCode(this.numberType), 
                android.os.HidlSupport.deepHashCode(this.numberPlan), 
                android.os.HidlSupport.deepHashCode(this.pi), 
                android.os.HidlSupport.deepHashCode(this.si));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".number = ");
        builder.append(this.number);
        builder.append(", .numberType = ");
        builder.append(this.numberType);
        builder.append(", .numberPlan = ");
        builder.append(this.numberPlan);
        builder.append(", .pi = ");
        builder.append(this.pi);
        builder.append(", .si = ");
        builder.append(this.si);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaNumberInfoRecord> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaNumberInfoRecord> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaNumberInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaNumberInfoRecord();
                ((android.hardware.radio.V1_0.CdmaNumberInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        number = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) number).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        numberType = _hidl_blob.getInt8(_hidl_offset + 16);
        numberPlan = _hidl_blob.getInt8(_hidl_offset + 17);
        pi = _hidl_blob.getInt8(_hidl_offset + 18);
        si = _hidl_blob.getInt8(_hidl_offset + 19);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaNumberInfoRecord> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, number);
        _hidl_blob.putInt8(_hidl_offset + 16, numberType);
        _hidl_blob.putInt8(_hidl_offset + 17, numberPlan);
        _hidl_blob.putInt8(_hidl_offset + 18, pi);
        _hidl_blob.putInt8(_hidl_offset + 19, si);
    }
};

