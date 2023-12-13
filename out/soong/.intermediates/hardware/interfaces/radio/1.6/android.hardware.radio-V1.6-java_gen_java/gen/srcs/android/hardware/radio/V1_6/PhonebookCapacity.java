package android.hardware.radio.V1_6;


public final class PhonebookCapacity {
    /**
     * Maximum number of ADN records possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxAdnRecords = 0;
    /**
     * Used ADN records in the SIM phonebook
     * Needs to be non-negative
     */
    public int usedAdnRecords = 0;
    /**
     * Maximum email records possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxEmailRecords = 0;
    /**
     * Used email records in the SIM phonebook
     * Needs to be non-negative
     */
    public int usedEmailRecords = 0;
    /**
     * Maximum additional number records possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxAdditionalNumberRecords = 0;
    /**
     * Used additional number records in the SIM phonebook
     * Needs to be non-negative
     */
    public int usedAdditionalNumberRecords = 0;
    /**
     * Maximum name length possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxNameLen = 0;
    /**
     * Maximum number length possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxNumberLen = 0;
    /**
     * Maximum email length possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxEmailLen = 0;
    /**
     * Maximum additional number length possible in the SIM phonebook
     * Needs to be non-negative
     */
    public int maxAdditionalNumberLen = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.PhonebookCapacity.class) {
            return false;
        }
        android.hardware.radio.V1_6.PhonebookCapacity other = (android.hardware.radio.V1_6.PhonebookCapacity)otherObject;
        if (this.maxAdnRecords != other.maxAdnRecords) {
            return false;
        }
        if (this.usedAdnRecords != other.usedAdnRecords) {
            return false;
        }
        if (this.maxEmailRecords != other.maxEmailRecords) {
            return false;
        }
        if (this.usedEmailRecords != other.usedEmailRecords) {
            return false;
        }
        if (this.maxAdditionalNumberRecords != other.maxAdditionalNumberRecords) {
            return false;
        }
        if (this.usedAdditionalNumberRecords != other.usedAdditionalNumberRecords) {
            return false;
        }
        if (this.maxNameLen != other.maxNameLen) {
            return false;
        }
        if (this.maxNumberLen != other.maxNumberLen) {
            return false;
        }
        if (this.maxEmailLen != other.maxEmailLen) {
            return false;
        }
        if (this.maxAdditionalNumberLen != other.maxAdditionalNumberLen) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maxAdnRecords), 
                android.os.HidlSupport.deepHashCode(this.usedAdnRecords), 
                android.os.HidlSupport.deepHashCode(this.maxEmailRecords), 
                android.os.HidlSupport.deepHashCode(this.usedEmailRecords), 
                android.os.HidlSupport.deepHashCode(this.maxAdditionalNumberRecords), 
                android.os.HidlSupport.deepHashCode(this.usedAdditionalNumberRecords), 
                android.os.HidlSupport.deepHashCode(this.maxNameLen), 
                android.os.HidlSupport.deepHashCode(this.maxNumberLen), 
                android.os.HidlSupport.deepHashCode(this.maxEmailLen), 
                android.os.HidlSupport.deepHashCode(this.maxAdditionalNumberLen));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maxAdnRecords = ");
        builder.append(this.maxAdnRecords);
        builder.append(", .usedAdnRecords = ");
        builder.append(this.usedAdnRecords);
        builder.append(", .maxEmailRecords = ");
        builder.append(this.maxEmailRecords);
        builder.append(", .usedEmailRecords = ");
        builder.append(this.usedEmailRecords);
        builder.append(", .maxAdditionalNumberRecords = ");
        builder.append(this.maxAdditionalNumberRecords);
        builder.append(", .usedAdditionalNumberRecords = ");
        builder.append(this.usedAdditionalNumberRecords);
        builder.append(", .maxNameLen = ");
        builder.append(this.maxNameLen);
        builder.append(", .maxNumberLen = ");
        builder.append(this.maxNumberLen);
        builder.append(", .maxEmailLen = ");
        builder.append(this.maxEmailLen);
        builder.append(", .maxAdditionalNumberLen = ");
        builder.append(this.maxAdditionalNumberLen);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhonebookCapacity> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhonebookCapacity> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.PhonebookCapacity _hidl_vec_element = new android.hardware.radio.V1_6.PhonebookCapacity();
                ((android.hardware.radio.V1_6.PhonebookCapacity) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maxAdnRecords = _hidl_blob.getInt32(_hidl_offset + 0);
        usedAdnRecords = _hidl_blob.getInt32(_hidl_offset + 4);
        maxEmailRecords = _hidl_blob.getInt32(_hidl_offset + 8);
        usedEmailRecords = _hidl_blob.getInt32(_hidl_offset + 12);
        maxAdditionalNumberRecords = _hidl_blob.getInt32(_hidl_offset + 16);
        usedAdditionalNumberRecords = _hidl_blob.getInt32(_hidl_offset + 20);
        maxNameLen = _hidl_blob.getInt32(_hidl_offset + 24);
        maxNumberLen = _hidl_blob.getInt32(_hidl_offset + 28);
        maxEmailLen = _hidl_blob.getInt32(_hidl_offset + 32);
        maxAdditionalNumberLen = _hidl_blob.getInt32(_hidl_offset + 36);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhonebookCapacity> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, maxAdnRecords);
        _hidl_blob.putInt32(_hidl_offset + 4, usedAdnRecords);
        _hidl_blob.putInt32(_hidl_offset + 8, maxEmailRecords);
        _hidl_blob.putInt32(_hidl_offset + 12, usedEmailRecords);
        _hidl_blob.putInt32(_hidl_offset + 16, maxAdditionalNumberRecords);
        _hidl_blob.putInt32(_hidl_offset + 20, usedAdditionalNumberRecords);
        _hidl_blob.putInt32(_hidl_offset + 24, maxNameLen);
        _hidl_blob.putInt32(_hidl_offset + 28, maxNumberLen);
        _hidl_blob.putInt32(_hidl_offset + 32, maxEmailLen);
        _hidl_blob.putInt32(_hidl_offset + 36, maxAdditionalNumberLen);
    }
};

