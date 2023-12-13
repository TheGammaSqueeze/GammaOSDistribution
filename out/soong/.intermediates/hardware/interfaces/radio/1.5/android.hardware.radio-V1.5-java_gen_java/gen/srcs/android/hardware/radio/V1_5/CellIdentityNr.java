package android.hardware.radio.V1_5;


public final class CellIdentityNr {
    /**
     * The fields "mcc" and "mnc" must contain the PLMN-ID of the primary PLMN of this cell.
     */
    public android.hardware.radio.V1_4.CellIdentityNr base = new android.hardware.radio.V1_4.CellIdentityNr();
    /**
     * Additional PLMN-IDs beyond the primary PLMN broadcast for this cell
     */
    public java.util.ArrayList<String> additionalPlmns = new java.util.ArrayList<String>();
    /**
     * Bands used by the cell.
     */
    public java.util.ArrayList<Integer> bands = new java.util.ArrayList<Integer>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.CellIdentityNr.class) {
            return false;
        }
        android.hardware.radio.V1_5.CellIdentityNr other = (android.hardware.radio.V1_5.CellIdentityNr)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.base, other.base)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.additionalPlmns, other.additionalPlmns)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bands, other.bands)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.base), 
                android.os.HidlSupport.deepHashCode(this.additionalPlmns), 
                android.os.HidlSupport.deepHashCode(this.bands));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".base = ");
        builder.append(this.base);
        builder.append(", .additionalPlmns = ");
        builder.append(this.additionalPlmns);
        builder.append(", .bands = ");
        builder.append(this.bands);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentityNr> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentityNr> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.CellIdentityNr _hidl_vec_element = new android.hardware.radio.V1_5.CellIdentityNr();
                ((android.hardware.radio.V1_5.CellIdentityNr) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_4.CellIdentityNr) base).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) additionalPlmns).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) additionalPlmns).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) bands).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) bands).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
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
        base.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = additionalPlmns.size();
            _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, additionalPlmns.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = bands.size();
            _hidl_blob.putInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 104 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, bands.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

