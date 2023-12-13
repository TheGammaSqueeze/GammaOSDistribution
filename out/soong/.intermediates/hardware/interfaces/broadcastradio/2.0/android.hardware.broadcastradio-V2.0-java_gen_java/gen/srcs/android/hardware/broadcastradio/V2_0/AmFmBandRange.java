package android.hardware.broadcastradio.V2_0;


public final class AmFmBandRange {
    /**
     * The frequency (in kHz) of the first channel within the range.
     */
    public int lowerBound = 0;
    /**
     * The frequency (in kHz) of the last channel within the range.
     */
    public int upperBound = 0;
    /**
     * Channel grid resolution (in kHz), how far apart are the channels.
     */
    public int spacing = 0;
    /**
     * Channel spacing (in kHz) used to speed up seeking to the next station
     * via the ITunerSession::scan() operation.
     *
     * It must be a multiple of channel grid resolution.
     *
     * Tuner may first quickly check every n-th channel and if it detects echo
     * from a station, it fine-tunes to find the exact frequency.
     *
     * It's ignored for capabilities check (with full=true when calling
     * getAmFmRegionConfig).
     */
    public int scanSpacing = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.AmFmBandRange.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.AmFmBandRange other = (android.hardware.broadcastradio.V2_0.AmFmBandRange)otherObject;
        if (this.lowerBound != other.lowerBound) {
            return false;
        }
        if (this.upperBound != other.upperBound) {
            return false;
        }
        if (this.spacing != other.spacing) {
            return false;
        }
        if (this.scanSpacing != other.scanSpacing) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.lowerBound), 
                android.os.HidlSupport.deepHashCode(this.upperBound), 
                android.os.HidlSupport.deepHashCode(this.spacing), 
                android.os.HidlSupport.deepHashCode(this.scanSpacing));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".lowerBound = ");
        builder.append(this.lowerBound);
        builder.append(", .upperBound = ");
        builder.append(this.upperBound);
        builder.append(", .spacing = ");
        builder.append(this.spacing);
        builder.append(", .scanSpacing = ");
        builder.append(this.scanSpacing);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AmFmBandRange> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AmFmBandRange> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.AmFmBandRange _hidl_vec_element = new android.hardware.broadcastradio.V2_0.AmFmBandRange();
                ((android.hardware.broadcastradio.V2_0.AmFmBandRange) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        lowerBound = _hidl_blob.getInt32(_hidl_offset + 0);
        upperBound = _hidl_blob.getInt32(_hidl_offset + 4);
        spacing = _hidl_blob.getInt32(_hidl_offset + 8);
        scanSpacing = _hidl_blob.getInt32(_hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AmFmBandRange> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, lowerBound);
        _hidl_blob.putInt32(_hidl_offset + 4, upperBound);
        _hidl_blob.putInt32(_hidl_offset + 8, spacing);
        _hidl_blob.putInt32(_hidl_offset + 12, scanSpacing);
    }
};

