package android.hardware.radio.V1_0;


public final class CdmaSmsAddress {
    public int digitMode = 0;
    public int numberMode = 0;
    public int numberType = 0;
    public int numberPlan = 0;
    public java.util.ArrayList<Byte> digits = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaSmsAddress.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaSmsAddress other = (android.hardware.radio.V1_0.CdmaSmsAddress)otherObject;
        if (this.digitMode != other.digitMode) {
            return false;
        }
        if (this.numberMode != other.numberMode) {
            return false;
        }
        if (this.numberType != other.numberType) {
            return false;
        }
        if (this.numberPlan != other.numberPlan) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.digits, other.digits)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.digitMode), 
                android.os.HidlSupport.deepHashCode(this.numberMode), 
                android.os.HidlSupport.deepHashCode(this.numberType), 
                android.os.HidlSupport.deepHashCode(this.numberPlan), 
                android.os.HidlSupport.deepHashCode(this.digits));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".digitMode = ");
        builder.append(android.hardware.radio.V1_0.CdmaSmsDigitMode.toString(this.digitMode));
        builder.append(", .numberMode = ");
        builder.append(android.hardware.radio.V1_0.CdmaSmsNumberMode.toString(this.numberMode));
        builder.append(", .numberType = ");
        builder.append(android.hardware.radio.V1_0.CdmaSmsNumberType.toString(this.numberType));
        builder.append(", .numberPlan = ");
        builder.append(android.hardware.radio.V1_0.CdmaSmsNumberPlan.toString(this.numberPlan));
        builder.append(", .digits = ");
        builder.append(this.digits);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaSmsAddress> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaSmsAddress> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaSmsAddress _hidl_vec_element = new android.hardware.radio.V1_0.CdmaSmsAddress();
                ((android.hardware.radio.V1_0.CdmaSmsAddress) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        digitMode = _hidl_blob.getInt32(_hidl_offset + 0);
        numberMode = _hidl_blob.getInt32(_hidl_offset + 4);
        numberType = _hidl_blob.getInt32(_hidl_offset + 8);
        numberPlan = _hidl_blob.getInt32(_hidl_offset + 12);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) digits).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) digits).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaSmsAddress> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, digitMode);
        _hidl_blob.putInt32(_hidl_offset + 4, numberMode);
        _hidl_blob.putInt32(_hidl_offset + 8, numberType);
        _hidl_blob.putInt32(_hidl_offset + 12, numberPlan);
        {
            int _hidl_vec_size = digits.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, digits.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

