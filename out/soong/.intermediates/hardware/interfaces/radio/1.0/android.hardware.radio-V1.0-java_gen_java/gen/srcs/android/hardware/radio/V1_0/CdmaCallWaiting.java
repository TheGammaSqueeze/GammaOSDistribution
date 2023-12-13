package android.hardware.radio.V1_0;


public final class CdmaCallWaiting {
    public String number = new String();
    public int numberPresentation = 0;
    public String name = new String();
    public android.hardware.radio.V1_0.CdmaSignalInfoRecord signalInfoRecord = new android.hardware.radio.V1_0.CdmaSignalInfoRecord();
    public int numberType = 0;
    public int numberPlan = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaCallWaiting.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaCallWaiting other = (android.hardware.radio.V1_0.CdmaCallWaiting)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        if (this.numberPresentation != other.numberPresentation) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signalInfoRecord, other.signalInfoRecord)) {
            return false;
        }
        if (this.numberType != other.numberType) {
            return false;
        }
        if (this.numberPlan != other.numberPlan) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.number), 
                android.os.HidlSupport.deepHashCode(this.numberPresentation), 
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.signalInfoRecord), 
                android.os.HidlSupport.deepHashCode(this.numberType), 
                android.os.HidlSupport.deepHashCode(this.numberPlan));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".number = ");
        builder.append(this.number);
        builder.append(", .numberPresentation = ");
        builder.append(android.hardware.radio.V1_0.CdmaCallWaitingNumberPresentation.toString(this.numberPresentation));
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .signalInfoRecord = ");
        builder.append(this.signalInfoRecord);
        builder.append(", .numberType = ");
        builder.append(android.hardware.radio.V1_0.CdmaCallWaitingNumberType.toString(this.numberType));
        builder.append(", .numberPlan = ");
        builder.append(android.hardware.radio.V1_0.CdmaCallWaitingNumberPlan.toString(this.numberPlan));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaCallWaiting> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaCallWaiting> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaCallWaiting _hidl_vec_element = new android.hardware.radio.V1_0.CdmaCallWaiting();
                ((android.hardware.radio.V1_0.CdmaCallWaiting) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
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

        numberPresentation = _hidl_blob.getInt32(_hidl_offset + 16);
        name = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ((android.hardware.radio.V1_0.CdmaSignalInfoRecord) signalInfoRecord).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 40);
        numberType = _hidl_blob.getInt32(_hidl_offset + 44);
        numberPlan = _hidl_blob.getInt32(_hidl_offset + 48);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaCallWaiting> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, number);
        _hidl_blob.putInt32(_hidl_offset + 16, numberPresentation);
        _hidl_blob.putString(_hidl_offset + 24, name);
        signalInfoRecord.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 40);
        _hidl_blob.putInt32(_hidl_offset + 44, numberType);
        _hidl_blob.putInt32(_hidl_offset + 48, numberPlan);
    }
};

