package android.hardware.broadcastradio.V2_0;


public final class AmFmRegionConfig {
    /**
     * All supported or configured AM/FM bands.
     *
     * AM/FM bands are identified by frequency value
     * (see IdentifierType::AMFM_FREQUENCY).
     *
     * With typical configuration, it's expected to have two frequency ranges
     * for capabilities check (AM and FM) and four ranges for specific region
     * configuration (AM LW, AM MW, AM SW, FM).
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.AmFmBandRange> ranges = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.AmFmBandRange>();
    /**
     * De-emphasis filter supported/configured.
     */
    public byte fmDeemphasis;
    /**
     * RDS/RBDS variant supported/configured.
     */
    public byte fmRds;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.AmFmRegionConfig.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.AmFmRegionConfig other = (android.hardware.broadcastradio.V2_0.AmFmRegionConfig)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.ranges, other.ranges)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.fmDeemphasis, other.fmDeemphasis)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.fmRds, other.fmRds)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.ranges), 
                android.os.HidlSupport.deepHashCode(this.fmDeemphasis), 
                android.os.HidlSupport.deepHashCode(this.fmRds));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".ranges = ");
        builder.append(this.ranges);
        builder.append(", .fmDeemphasis = ");
        builder.append(android.hardware.broadcastradio.V2_0.Deemphasis.dumpBitfield(this.fmDeemphasis));
        builder.append(", .fmRds = ");
        builder.append(android.hardware.broadcastradio.V2_0.Rds.dumpBitfield(this.fmRds));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AmFmRegionConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AmFmRegionConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.AmFmRegionConfig _hidl_vec_element = new android.hardware.broadcastradio.V2_0.AmFmRegionConfig();
                ((android.hardware.broadcastradio.V2_0.AmFmRegionConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
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
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.AmFmBandRange>) ranges).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.AmFmBandRange _hidl_vec_element = new android.hardware.broadcastradio.V2_0.AmFmBandRange();
                ((android.hardware.broadcastradio.V2_0.AmFmBandRange) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.AmFmBandRange>) ranges).add(_hidl_vec_element);
            }
        }
        fmDeemphasis = _hidl_blob.getInt8(_hidl_offset + 16);
        fmRds = _hidl_blob.getInt8(_hidl_offset + 17);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AmFmRegionConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = ranges.size();
            _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                ranges.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt8(_hidl_offset + 16, fmDeemphasis);
        _hidl_blob.putInt8(_hidl_offset + 17, fmRds);
    }
};

