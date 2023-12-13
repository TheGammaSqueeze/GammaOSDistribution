package android.hardware.radio.V1_6;


public final class SliceInfo {
    /**
     * The type of service provided by the slice.
     *
     * see: 3GPP TS 24.501 Section 9.11.2.8.
     */
    public byte sst = 0;
    /**
     * Slice differentiator is the identifier of a slice that has
     * SliceServiceType as SST. A value of -1 indicates that there is
     * no corresponding SliceInfo of the HPLMN.
     *
     * see: 3GPP TS 24.501 Section 9.11.2.8.
     */
    public int sliceDifferentiator = 0;
    /**
     * This SST corresponds to a SliceInfo (S-NSSAI) of the HPLMN; the SST is
     * mapped to this value.
     *
     * see: 3GPP TS 24.501 Section 9.11.2.8.
     */
    public byte mappedHplmnSst = 0;
    /**
     * Present only if both sliceDifferentiator and mappedHplmnSst are also
     * present. This SD corresponds to a SliceInfo (S-NSSAI) of the HPLMN;
     * sliceDifferentiator is mapped to this value. A value of -1 indicates that
     * there is no corresponding SliceInfo of the HPLMN.
     *
     * see: 3GPP TS 24.501 Section 9.11.2.8.
     */
    public int mappedHplmnSD = 0;
    /**
     * Field to indicate the current status of the slice.
     */
    public byte status = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.SliceInfo.class) {
            return false;
        }
        android.hardware.radio.V1_6.SliceInfo other = (android.hardware.radio.V1_6.SliceInfo)otherObject;
        if (this.sst != other.sst) {
            return false;
        }
        if (this.sliceDifferentiator != other.sliceDifferentiator) {
            return false;
        }
        if (this.mappedHplmnSst != other.mappedHplmnSst) {
            return false;
        }
        if (this.mappedHplmnSD != other.mappedHplmnSD) {
            return false;
        }
        if (this.status != other.status) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sst), 
                android.os.HidlSupport.deepHashCode(this.sliceDifferentiator), 
                android.os.HidlSupport.deepHashCode(this.mappedHplmnSst), 
                android.os.HidlSupport.deepHashCode(this.mappedHplmnSD), 
                android.os.HidlSupport.deepHashCode(this.status));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sst = ");
        builder.append(android.hardware.radio.V1_6.SliceServiceType.toString(this.sst));
        builder.append(", .sliceDifferentiator = ");
        builder.append(this.sliceDifferentiator);
        builder.append(", .mappedHplmnSst = ");
        builder.append(android.hardware.radio.V1_6.SliceServiceType.toString(this.mappedHplmnSst));
        builder.append(", .mappedHplmnSD = ");
        builder.append(this.mappedHplmnSD);
        builder.append(", .status = ");
        builder.append(android.hardware.radio.V1_6.SliceStatus.toString(this.status));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SliceInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SliceInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.SliceInfo _hidl_vec_element = new android.hardware.radio.V1_6.SliceInfo();
                ((android.hardware.radio.V1_6.SliceInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sst = _hidl_blob.getInt8(_hidl_offset + 0);
        sliceDifferentiator = _hidl_blob.getInt32(_hidl_offset + 4);
        mappedHplmnSst = _hidl_blob.getInt8(_hidl_offset + 8);
        mappedHplmnSD = _hidl_blob.getInt32(_hidl_offset + 12);
        status = _hidl_blob.getInt8(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SliceInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, sst);
        _hidl_blob.putInt32(_hidl_offset + 4, sliceDifferentiator);
        _hidl_blob.putInt8(_hidl_offset + 8, mappedHplmnSst);
        _hidl_blob.putInt32(_hidl_offset + 12, mappedHplmnSD);
        _hidl_blob.putInt8(_hidl_offset + 16, status);
    }
};

