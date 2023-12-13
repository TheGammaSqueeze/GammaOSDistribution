package android.hardware.broadcastradio.V2_0;


public final class ProgramSelector {
    /**
     * Primary program identifier.
     *
     * This identifier uniquely identifies a station and can be used for
     * equality check.
     *
     * It can hold only a subset of identifier types, one per each
     * radio technology:
     *  - analogue AM/FM: AMFM_FREQUENCY;
     *  - FM RDS: RDS_PI;
     *  - HD Radio: HD_STATION_ID_EXT;
     *  - DAB: DAB_SID_EXT;
     *  - Digital Radio Mondiale: DRMO_SERVICE_ID;
     *  - SiriusXM: SXM_SERVICE_ID;
     *  - vendor-specific: VENDOR_START..VENDOR_END.
     *
     * The list may change in future versions, so the implementation must obey,
     * but not rely on it.
     */
    public android.hardware.broadcastradio.V2_0.ProgramIdentifier primaryId = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
    /**
     * Secondary program identifiers.
     *
     * These identifiers are supplementary and can speed up tuning process,
     * but the primary ID must be sufficient (i.e. RDS PI is enough to select
     * a station from the list after a full band scan).
     *
     * Two selectors with different secondary IDs, but the same primary ID are
     * considered equal. In particular, secondary IDs vector may get updated for
     * an entry on the program list (ie. when a better frequency for a given
     * station is found).
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier> secondaryIds = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.ProgramSelector.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.ProgramSelector other = (android.hardware.broadcastradio.V2_0.ProgramSelector)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.primaryId, other.primaryId)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.secondaryIds, other.secondaryIds)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.primaryId), 
                android.os.HidlSupport.deepHashCode(this.secondaryIds));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".primaryId = ");
        builder.append(this.primaryId);
        builder.append(", .secondaryIds = ");
        builder.append(this.secondaryIds);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ProgramSelector> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ProgramSelector> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramSelector _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramSelector();
                ((android.hardware.broadcastradio.V2_0.ProgramSelector) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) primaryId).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) secondaryIds).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramIdentifier _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
                ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) secondaryIds).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ProgramSelector> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        primaryId.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        {
            int _hidl_vec_size = secondaryIds.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                secondaryIds.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

