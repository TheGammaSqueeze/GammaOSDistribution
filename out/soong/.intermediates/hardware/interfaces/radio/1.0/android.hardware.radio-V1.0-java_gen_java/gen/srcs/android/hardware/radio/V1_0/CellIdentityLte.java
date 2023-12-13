package android.hardware.radio.V1_0;


public final class CellIdentityLte {
    public String mcc = new String();
    public String mnc = new String();
    public int ci = 0;
    public int pci = 0;
    public int tac = 0;
    public int earfcn = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CellIdentityLte.class) {
            return false;
        }
        android.hardware.radio.V1_0.CellIdentityLte other = (android.hardware.radio.V1_0.CellIdentityLte)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.mcc, other.mcc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mnc, other.mnc)) {
            return false;
        }
        if (this.ci != other.ci) {
            return false;
        }
        if (this.pci != other.pci) {
            return false;
        }
        if (this.tac != other.tac) {
            return false;
        }
        if (this.earfcn != other.earfcn) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.mcc), 
                android.os.HidlSupport.deepHashCode(this.mnc), 
                android.os.HidlSupport.deepHashCode(this.ci), 
                android.os.HidlSupport.deepHashCode(this.pci), 
                android.os.HidlSupport.deepHashCode(this.tac), 
                android.os.HidlSupport.deepHashCode(this.earfcn));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".mcc = ");
        builder.append(this.mcc);
        builder.append(", .mnc = ");
        builder.append(this.mnc);
        builder.append(", .ci = ");
        builder.append(this.ci);
        builder.append(", .pci = ");
        builder.append(this.pci);
        builder.append(", .tac = ");
        builder.append(this.tac);
        builder.append(", .earfcn = ");
        builder.append(this.earfcn);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentityLte> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentityLte> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CellIdentityLte _hidl_vec_element = new android.hardware.radio.V1_0.CellIdentityLte();
                ((android.hardware.radio.V1_0.CellIdentityLte) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        mcc = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) mcc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        mnc = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) mnc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ci = _hidl_blob.getInt32(_hidl_offset + 32);
        pci = _hidl_blob.getInt32(_hidl_offset + 36);
        tac = _hidl_blob.getInt32(_hidl_offset + 40);
        earfcn = _hidl_blob.getInt32(_hidl_offset + 44);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentityLte> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, mcc);
        _hidl_blob.putString(_hidl_offset + 16, mnc);
        _hidl_blob.putInt32(_hidl_offset + 32, ci);
        _hidl_blob.putInt32(_hidl_offset + 36, pci);
        _hidl_blob.putInt32(_hidl_offset + 40, tac);
        _hidl_blob.putInt32(_hidl_offset + 44, earfcn);
    }
};

