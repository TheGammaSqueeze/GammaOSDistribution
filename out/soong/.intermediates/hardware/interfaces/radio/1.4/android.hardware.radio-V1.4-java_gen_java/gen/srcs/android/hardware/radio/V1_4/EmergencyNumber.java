package android.hardware.radio.V1_4;


public final class EmergencyNumber {
    /**
     * The emergency number. The character in the number string should only be the dial pad
     * character('0'-'9', '*', or '#'). For example: 911.
     */
    public String number = new String();
    /**
     * 3-digit Mobile Country Code, 0..999. Empty string if not applicable.
     */
    public String mcc = new String();
    /**
     * 2 or 3-digit Mobile Network Code, 0..999. Empty string if not applicable.
     */
    public String mnc = new String();
    /**
     * The bitfield of @1.4::EmergencyServiceCategory(s). See @1.4::EmergencyServiceCategory for
     * the value of each bit.
     */
    public int categories;
    /**
     * The list of emergency Uniform Resource Names (URN).
     */
    public java.util.ArrayList<String> urns = new java.util.ArrayList<String>();
    /**
     * The bitfield of @1.4::EmergencyNumberSource(s). See @1.4::EmergencyNumberSource for the
     * value of each bit.
     */
    public int sources;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.EmergencyNumber.class) {
            return false;
        }
        android.hardware.radio.V1_4.EmergencyNumber other = (android.hardware.radio.V1_4.EmergencyNumber)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mcc, other.mcc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mnc, other.mnc)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.categories, other.categories)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.urns, other.urns)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.sources, other.sources)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.number), 
                android.os.HidlSupport.deepHashCode(this.mcc), 
                android.os.HidlSupport.deepHashCode(this.mnc), 
                android.os.HidlSupport.deepHashCode(this.categories), 
                android.os.HidlSupport.deepHashCode(this.urns), 
                android.os.HidlSupport.deepHashCode(this.sources));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".number = ");
        builder.append(this.number);
        builder.append(", .mcc = ");
        builder.append(this.mcc);
        builder.append(", .mnc = ");
        builder.append(this.mnc);
        builder.append(", .categories = ");
        builder.append(android.hardware.radio.V1_4.EmergencyServiceCategory.dumpBitfield(this.categories));
        builder.append(", .urns = ");
        builder.append(this.urns);
        builder.append(", .sources = ");
        builder.append(android.hardware.radio.V1_4.EmergencyNumberSource.dumpBitfield(this.sources));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(80 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<EmergencyNumber> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<EmergencyNumber> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 80,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.EmergencyNumber _hidl_vec_element = new android.hardware.radio.V1_4.EmergencyNumber();
                ((android.hardware.radio.V1_4.EmergencyNumber) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
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

        mcc = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) mcc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        mnc = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) mnc).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        categories = _hidl_blob.getInt32(_hidl_offset + 48);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) urns).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) urns).add(_hidl_vec_element);
            }
        }
        sources = _hidl_blob.getInt32(_hidl_offset + 72);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(80 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<EmergencyNumber> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, number);
        _hidl_blob.putString(_hidl_offset + 16, mcc);
        _hidl_blob.putString(_hidl_offset + 32, mnc);
        _hidl_blob.putInt32(_hidl_offset + 48, categories);
        {
            int _hidl_vec_size = urns.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, urns.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 72, sources);
    }
};

