package android.hardware.radio.V1_0;


public final class CdmaLineControlInfoRecord {
    public byte lineCtrlPolarityIncluded = 0;
    public byte lineCtrlToggle = 0;
    public byte lineCtrlReverse = 0;
    public byte lineCtrlPowerDenial = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaLineControlInfoRecord.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaLineControlInfoRecord other = (android.hardware.radio.V1_0.CdmaLineControlInfoRecord)otherObject;
        if (this.lineCtrlPolarityIncluded != other.lineCtrlPolarityIncluded) {
            return false;
        }
        if (this.lineCtrlToggle != other.lineCtrlToggle) {
            return false;
        }
        if (this.lineCtrlReverse != other.lineCtrlReverse) {
            return false;
        }
        if (this.lineCtrlPowerDenial != other.lineCtrlPowerDenial) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.lineCtrlPolarityIncluded), 
                android.os.HidlSupport.deepHashCode(this.lineCtrlToggle), 
                android.os.HidlSupport.deepHashCode(this.lineCtrlReverse), 
                android.os.HidlSupport.deepHashCode(this.lineCtrlPowerDenial));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".lineCtrlPolarityIncluded = ");
        builder.append(this.lineCtrlPolarityIncluded);
        builder.append(", .lineCtrlToggle = ");
        builder.append(this.lineCtrlToggle);
        builder.append(", .lineCtrlReverse = ");
        builder.append(this.lineCtrlReverse);
        builder.append(", .lineCtrlPowerDenial = ");
        builder.append(this.lineCtrlPowerDenial);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(4 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaLineControlInfoRecord> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaLineControlInfoRecord> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaLineControlInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaLineControlInfoRecord();
                ((android.hardware.radio.V1_0.CdmaLineControlInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 4);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        lineCtrlPolarityIncluded = _hidl_blob.getInt8(_hidl_offset + 0);
        lineCtrlToggle = _hidl_blob.getInt8(_hidl_offset + 1);
        lineCtrlReverse = _hidl_blob.getInt8(_hidl_offset + 2);
        lineCtrlPowerDenial = _hidl_blob.getInt8(_hidl_offset + 3);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(4 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaLineControlInfoRecord> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 4);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, lineCtrlPolarityIncluded);
        _hidl_blob.putInt8(_hidl_offset + 1, lineCtrlToggle);
        _hidl_blob.putInt8(_hidl_offset + 2, lineCtrlReverse);
        _hidl_blob.putInt8(_hidl_offset + 3, lineCtrlPowerDenial);
    }
};

