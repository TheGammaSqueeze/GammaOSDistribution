package android.hardware.broadcastradio.V2_0;


public final class ProgramFilter {
    /**
     * List of identifier types that satisfy the filter.
     *
     * If the program list entry contains at least one identifier of the type
     * listed, it satisfies this condition.
     *
     * Empty list means no filtering on identifier type.
     */
    public java.util.ArrayList<Integer> identifierTypes = new java.util.ArrayList<Integer>();
    /**
     * List of identifiers that satisfy the filter.
     *
     * If the program list entry contains at least one listed identifier,
     * it satisfies this condition.
     *
     * Empty list means no filtering on identifier.
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier> identifiers = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>();
    /**
     * Includes non-tunable entries that define tree structure on the
     * program list (i.e. DAB ensembles).
     */
    public boolean includeCategories = false;
    /**
     * Disable updates on entry modifications.
     *
     * If true, 'modified' vector of ProgramListChunk must contain list
     * additions only. Once the program is added to the list, it's not
     * updated anymore.
     */
    public boolean excludeModifications = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.ProgramFilter.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.ProgramFilter other = (android.hardware.broadcastradio.V2_0.ProgramFilter)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.identifierTypes, other.identifierTypes)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.identifiers, other.identifiers)) {
            return false;
        }
        if (this.includeCategories != other.includeCategories) {
            return false;
        }
        if (this.excludeModifications != other.excludeModifications) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.identifierTypes), 
                android.os.HidlSupport.deepHashCode(this.identifiers), 
                android.os.HidlSupport.deepHashCode(this.includeCategories), 
                android.os.HidlSupport.deepHashCode(this.excludeModifications));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".identifierTypes = ");
        builder.append(this.identifierTypes);
        builder.append(", .identifiers = ");
        builder.append(this.identifiers);
        builder.append(", .includeCategories = ");
        builder.append(this.includeCategories);
        builder.append(", .excludeModifications = ");
        builder.append(this.excludeModifications);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ProgramFilter> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ProgramFilter> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramFilter _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramFilter();
                ((android.hardware.broadcastradio.V2_0.ProgramFilter) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) identifierTypes).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) identifierTypes).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) identifiers).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramIdentifier _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
                ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) identifiers).add(_hidl_vec_element);
            }
        }
        includeCategories = _hidl_blob.getBool(_hidl_offset + 32);
        excludeModifications = _hidl_blob.getBool(_hidl_offset + 33);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ProgramFilter> _hidl_vec) {
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
        {
            int _hidl_vec_size = identifierTypes.size();
            _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, identifierTypes.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = identifiers.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                identifiers.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putBool(_hidl_offset + 32, includeCategories);
        _hidl_blob.putBool(_hidl_offset + 33, excludeModifications);
    }
};

