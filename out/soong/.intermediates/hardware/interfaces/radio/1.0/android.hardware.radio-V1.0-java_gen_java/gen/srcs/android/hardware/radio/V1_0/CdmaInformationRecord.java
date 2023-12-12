package android.hardware.radio.V1_0;


public final class CdmaInformationRecord {
    public int name = 0;
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaDisplayInfoRecord> display = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaDisplayInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaNumberInfoRecord> number = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaNumberInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaSignalInfoRecord> signal = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaSignalInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord> redir = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaLineControlInfoRecord> lineCtrl = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaLineControlInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53ClirInfoRecord> clir = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53ClirInfoRecord>();
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord> audioCtrl = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaInformationRecord.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaInformationRecord other = (android.hardware.radio.V1_0.CdmaInformationRecord)otherObject;
        if (this.name != other.name) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.display, other.display)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.signal, other.signal)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.redir, other.redir)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.lineCtrl, other.lineCtrl)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.clir, other.clir)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.audioCtrl, other.audioCtrl)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.display), 
                android.os.HidlSupport.deepHashCode(this.number), 
                android.os.HidlSupport.deepHashCode(this.signal), 
                android.os.HidlSupport.deepHashCode(this.redir), 
                android.os.HidlSupport.deepHashCode(this.lineCtrl), 
                android.os.HidlSupport.deepHashCode(this.clir), 
                android.os.HidlSupport.deepHashCode(this.audioCtrl));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".name = ");
        builder.append(android.hardware.radio.V1_0.CdmaInfoRecName.toString(this.name));
        builder.append(", .display = ");
        builder.append(this.display);
        builder.append(", .number = ");
        builder.append(this.number);
        builder.append(", .signal = ");
        builder.append(this.signal);
        builder.append(", .redir = ");
        builder.append(this.redir);
        builder.append(", .lineCtrl = ");
        builder.append(this.lineCtrl);
        builder.append(", .clir = ");
        builder.append(this.clir);
        builder.append(", .audioCtrl = ");
        builder.append(this.audioCtrl);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaInformationRecord> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaInformationRecord> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaInformationRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaInformationRecord();
                ((android.hardware.radio.V1_0.CdmaInformationRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        name = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaDisplayInfoRecord>) display).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaDisplayInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaDisplayInfoRecord();
                ((android.hardware.radio.V1_0.CdmaDisplayInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaDisplayInfoRecord>) display).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaNumberInfoRecord>) number).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaNumberInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaNumberInfoRecord();
                ((android.hardware.radio.V1_0.CdmaNumberInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaNumberInfoRecord>) number).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaSignalInfoRecord>) signal).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaSignalInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaSignalInfoRecord();
                ((android.hardware.radio.V1_0.CdmaSignalInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 4);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaSignalInfoRecord>) signal).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord>) redir).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord();
                ((android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaRedirectingNumberInfoRecord>) redir).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaLineControlInfoRecord>) lineCtrl).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaLineControlInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaLineControlInfoRecord();
                ((android.hardware.radio.V1_0.CdmaLineControlInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 4);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaLineControlInfoRecord>) lineCtrl).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53ClirInfoRecord>) clir).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaT53ClirInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaT53ClirInfoRecord();
                ((android.hardware.radio.V1_0.CdmaT53ClirInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 1);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53ClirInfoRecord>) clir).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 2,_hidl_blob.handle(),
                    _hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord>) audioCtrl).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord _hidl_vec_element = new android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord();
                ((android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 2);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaT53AudioControlInfoRecord>) audioCtrl).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaInformationRecord> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, name);
        {
            int _hidl_vec_size = display.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                display.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = number.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                number.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = signal.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                signal.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 4);
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = redir.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                redir.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = lineCtrl.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                lineCtrl.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 4);
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = clir.size();
            _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                clir.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 1);
            }
            _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = audioCtrl.size();
            _hidl_blob.putInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 104 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 2));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                audioCtrl.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 2);
            }
            _hidl_blob.putBlob(_hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

