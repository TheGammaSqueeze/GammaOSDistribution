package android.hardware.radio.V1_4;


public final class CellIdentityNr {
    /**
     * 3-digit Mobile Country Code, in range[0, 999]; This value must be valid for registered or
     *  camped cells; INT_MAX means invalid/unreported.
     */
    public String mcc = new String();
    /**
     * 2 or 3-digit Mobile Network Code, in range [0, 999], This value must be valid for
     * registered or camped cells; INT_MAX means invalid/unreported.
     */
    public String mnc = new String();
    /**
     * NR Cell Identity in range [0, 68719476735] (36 bits) described in 3GPP TS 38.331, which
     * unambiguously identifies a cell within a PLMN. This value must be valid for registered or
     * camped cells; LONG_MAX (2^63-1) means invalid/unreported.
     */
    public long nci = 0L;
    /**
     * Physical cell id in range [0, 1007] described in 3GPP TS 38.331. This value must be valid.
     */
    public int pci = 0;
    /**
     * 16-bit tracking area code, INT_MAX means invalid/unreported.
     */
    public int tac = 0;
    /**
     * NR Absolute Radio Frequency Channel Number, in range [0, 3279165].
     * Reference: 3GPP TS 38.101-1 and 3GPP TS 38.101-2 section 5.4.2.1.
     * This value must be valid.
     */
    public int nrarfcn = 0;
    public android.hardware.radio.V1_2.CellIdentityOperatorNames operatorNames = new android.hardware.radio.V1_2.CellIdentityOperatorNames();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.CellIdentityNr.class) {
            return false;
        }
        android.hardware.radio.V1_4.CellIdentityNr other = (android.hardware.radio.V1_4.CellIdentityNr)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.mcc, other.mcc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mnc, other.mnc)) {
            return false;
        }
        if (this.nci != other.nci) {
            return false;
        }
        if (this.pci != other.pci) {
            return false;
        }
        if (this.tac != other.tac) {
            return false;
        }
        if (this.nrarfcn != other.nrarfcn) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.operatorNames, other.operatorNames)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.mcc), 
                android.os.HidlSupport.deepHashCode(this.mnc), 
                android.os.HidlSupport.deepHashCode(this.nci), 
                android.os.HidlSupport.deepHashCode(this.pci), 
                android.os.HidlSupport.deepHashCode(this.tac), 
                android.os.HidlSupport.deepHashCode(this.nrarfcn), 
                android.os.HidlSupport.deepHashCode(this.operatorNames));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".mcc = ");
        builder.append(this.mcc);
        builder.append(", .mnc = ");
        builder.append(this.mnc);
        builder.append(", .nci = ");
        builder.append(this.nci);
        builder.append(", .pci = ");
        builder.append(this.pci);
        builder.append(", .tac = ");
        builder.append(this.tac);
        builder.append(", .nrarfcn = ");
        builder.append(this.nrarfcn);
        builder.append(", .operatorNames = ");
        builder.append(this.operatorNames);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentityNr> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentityNr> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.CellIdentityNr _hidl_vec_element = new android.hardware.radio.V1_4.CellIdentityNr();
                ((android.hardware.radio.V1_4.CellIdentityNr) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
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

        nci = _hidl_blob.getInt64(_hidl_offset + 32);
        pci = _hidl_blob.getInt32(_hidl_offset + 40);
        tac = _hidl_blob.getInt32(_hidl_offset + 44);
        nrarfcn = _hidl_blob.getInt32(_hidl_offset + 48);
        ((android.hardware.radio.V1_2.CellIdentityOperatorNames) operatorNames).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentityNr> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, mcc);
        _hidl_blob.putString(_hidl_offset + 16, mnc);
        _hidl_blob.putInt64(_hidl_offset + 32, nci);
        _hidl_blob.putInt32(_hidl_offset + 40, pci);
        _hidl_blob.putInt32(_hidl_offset + 44, tac);
        _hidl_blob.putInt32(_hidl_offset + 48, nrarfcn);
        operatorNames.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 56);
    }
};

