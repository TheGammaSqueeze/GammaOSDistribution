package android.hardware.radio.V1_4;


public final class NrIndicators {
    /**
     * Indicates that if E-UTRA-NR Dual Connectivity (EN-DC) is supported by the primary serving
     * cell.
     *
     * True the primary serving cell is LTE cell and the plmn-InfoList-r15 is present in SIB2 and
     * at least one bit in this list is true, otherwise this value should be false.
     *
     * Reference: 3GPP TS 36.331 v15.2.2 6.3.1 System information blocks.
     */
    public boolean isEndcAvailable = false;
    /**
     * True if use of dual connectivity with NR is restricted.
     * Reference: 3GPP TS 24.301 v15.03 section 9.3.3.12A.
     */
    public boolean isDcNrRestricted = false;
    /**
     * True if the bit N is in the PLMN-InfoList-r15 is true and the selected PLMN is present in
     * plmn-IdentityList at position N.
     * Reference: 3GPP TS 36.331 v15.2.2 section 6.3.1 PLMN-InfoList-r15.
     *            3GPP TS 36.331 v15.2.2 section 6.2.2 SystemInformationBlockType1 message.
     */
    public boolean isNrAvailable = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.NrIndicators.class) {
            return false;
        }
        android.hardware.radio.V1_4.NrIndicators other = (android.hardware.radio.V1_4.NrIndicators)otherObject;
        if (this.isEndcAvailable != other.isEndcAvailable) {
            return false;
        }
        if (this.isDcNrRestricted != other.isDcNrRestricted) {
            return false;
        }
        if (this.isNrAvailable != other.isNrAvailable) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.isEndcAvailable), 
                android.os.HidlSupport.deepHashCode(this.isDcNrRestricted), 
                android.os.HidlSupport.deepHashCode(this.isNrAvailable));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".isEndcAvailable = ");
        builder.append(this.isEndcAvailable);
        builder.append(", .isDcNrRestricted = ");
        builder.append(this.isDcNrRestricted);
        builder.append(", .isNrAvailable = ");
        builder.append(this.isNrAvailable);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(3 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NrIndicators> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NrIndicators> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 3,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.NrIndicators _hidl_vec_element = new android.hardware.radio.V1_4.NrIndicators();
                ((android.hardware.radio.V1_4.NrIndicators) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 3);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        isEndcAvailable = _hidl_blob.getBool(_hidl_offset + 0);
        isDcNrRestricted = _hidl_blob.getBool(_hidl_offset + 1);
        isNrAvailable = _hidl_blob.getBool(_hidl_offset + 2);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(3 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NrIndicators> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 3));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 3);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, isEndcAvailable);
        _hidl_blob.putBool(_hidl_offset + 1, isDcNrRestricted);
        _hidl_blob.putBool(_hidl_offset + 2, isNrAvailable);
    }
};

