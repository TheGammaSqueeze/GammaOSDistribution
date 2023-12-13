package android.hardware.wifi.V1_0;


public final class StaScanData {
    /**
     * Bitset containing |ScanDataFlagMask| values.
     */
    public int flags;
    /**
     * Bitset where each bit indicates if the bucket with that index (starting at
     * 0) was scanned.
     */
    public int bucketsScanned = 0;
    /**
     * List of scan results.
     */
    public java.util.ArrayList<android.hardware.wifi.V1_0.StaScanResult> results = new java.util.ArrayList<android.hardware.wifi.V1_0.StaScanResult>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaScanData.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaScanData other = (android.hardware.wifi.V1_0.StaScanData)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.flags, other.flags)) {
            return false;
        }
        if (this.bucketsScanned != other.bucketsScanned) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.results, other.results)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.flags), 
                android.os.HidlSupport.deepHashCode(this.bucketsScanned), 
                android.os.HidlSupport.deepHashCode(this.results));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".flags = ");
        builder.append(android.hardware.wifi.V1_0.StaScanDataFlagMask.dumpBitfield(this.flags));
        builder.append(", .bucketsScanned = ");
        builder.append(this.bucketsScanned);
        builder.append(", .results = ");
        builder.append(this.results);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaScanData> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaScanData> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaScanData _hidl_vec_element = new android.hardware.wifi.V1_0.StaScanData();
                ((android.hardware.wifi.V1_0.StaScanData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        flags = _hidl_blob.getInt32(_hidl_offset + 0);
        bucketsScanned = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_0.StaScanResult>) results).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaScanResult _hidl_vec_element = new android.hardware.wifi.V1_0.StaScanResult();
                ((android.hardware.wifi.V1_0.StaScanResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                ((java.util.ArrayList<android.hardware.wifi.V1_0.StaScanResult>) results).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaScanData> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, flags);
        _hidl_blob.putInt32(_hidl_offset + 4, bucketsScanned);
        {
            int _hidl_vec_size = results.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                results.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

