package android.hardware.radio.V1_2;


public final class CellIdentity {
    /**
     * Cell type for selecting from union CellInfo.
     * Only one of the below vectors must be of size 1 based on a
     * valid CellInfoType and others must be of size 0.
     * If cell info type is NONE, then all the vectors must be of size 0.
     */
    public int cellInfoType = 0;
    public java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityGsm> cellIdentityGsm = new java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityGsm>();
    public java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityWcdma> cellIdentityWcdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityWcdma>();
    public java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityCdma> cellIdentityCdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityCdma>();
    public java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityLte> cellIdentityLte = new java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityLte>();
    public java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityTdscdma> cellIdentityTdscdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityTdscdma>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.CellIdentity.class) {
            return false;
        }
        android.hardware.radio.V1_2.CellIdentity other = (android.hardware.radio.V1_2.CellIdentity)otherObject;
        if (this.cellInfoType != other.cellInfoType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityGsm, other.cellIdentityGsm)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityWcdma, other.cellIdentityWcdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityCdma, other.cellIdentityCdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityLte, other.cellIdentityLte)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentityTdscdma, other.cellIdentityTdscdma)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellInfoType), 
                android.os.HidlSupport.deepHashCode(this.cellIdentityGsm), 
                android.os.HidlSupport.deepHashCode(this.cellIdentityWcdma), 
                android.os.HidlSupport.deepHashCode(this.cellIdentityCdma), 
                android.os.HidlSupport.deepHashCode(this.cellIdentityLte), 
                android.os.HidlSupport.deepHashCode(this.cellIdentityTdscdma));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellInfoType = ");
        builder.append(android.hardware.radio.V1_0.CellInfoType.toString(this.cellInfoType));
        builder.append(", .cellIdentityGsm = ");
        builder.append(this.cellIdentityGsm);
        builder.append(", .cellIdentityWcdma = ");
        builder.append(this.cellIdentityWcdma);
        builder.append(", .cellIdentityCdma = ");
        builder.append(this.cellIdentityCdma);
        builder.append(", .cellIdentityLte = ");
        builder.append(this.cellIdentityLte);
        builder.append(", .cellIdentityTdscdma = ");
        builder.append(this.cellIdentityTdscdma);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentity> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentity> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentity _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentity();
                ((android.hardware.radio.V1_2.CellIdentity) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellInfoType = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 80,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityGsm>) cellIdentityGsm).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityGsm _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityGsm();
                ((android.hardware.radio.V1_2.CellIdentityGsm) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityGsm>) cellIdentityGsm).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 80,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityWcdma>) cellIdentityWcdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityWcdma _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityWcdma();
                ((android.hardware.radio.V1_2.CellIdentityWcdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityWcdma>) cellIdentityWcdma).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityCdma>) cellIdentityCdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityCdma _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityCdma();
                ((android.hardware.radio.V1_2.CellIdentityCdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityCdma>) cellIdentityCdma).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityLte>) cellIdentityLte).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityLte _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityLte();
                ((android.hardware.radio.V1_2.CellIdentityLte) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityLte>) cellIdentityLte).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityTdscdma>) cellIdentityTdscdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellIdentityTdscdma _hidl_vec_element = new android.hardware.radio.V1_2.CellIdentityTdscdma();
                ((android.hardware.radio.V1_2.CellIdentityTdscdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellIdentityTdscdma>) cellIdentityTdscdma).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentity> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, cellInfoType);
        {
            int _hidl_vec_size = cellIdentityGsm.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cellIdentityGsm.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = cellIdentityWcdma.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cellIdentityWcdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = cellIdentityCdma.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cellIdentityCdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = cellIdentityLte.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cellIdentityLte.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = cellIdentityTdscdma.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cellIdentityTdscdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

