package android.hardware.radio.V1_4;


public final class NrSignalStrength {
    /**
     * SS reference signal received power, multipled by -1.
     *
     * Reference: 3GPP TS 38.215.
     *
     * Range [44, 140], INT_MAX means invalid/unreported.
     */
    public int ssRsrp = 0;
    /**
     * SS reference signal received quality, multipled by -1.
     *
     * Reference: 3GPP TS 38.215, 3GPP TS 38.133 section 10.
     *
     * Range [-20 dB, 43 dB], INT_MAX means invalid/unreported.
     */
    public int ssRsrq = 0;
    /**
     * SS signal-to-noise and interference ratio.
     *
     * Reference: 3GPP TS 38.215 section 5.1.*, 3GPP TS 38.133 section 10.1.16.1.
     *
     * Range [-23, 40], INT_MAX means invalid/unreported.
     */
    public int ssSinr = 0;
    /**
     * CSI reference signal received power, multipled by -1.
     *
     * Reference: 3GPP TS 38.215.
     *
     * Range [44, 140], INT_MAX means invalid/unreported.
     */
    public int csiRsrp = 0;
    /**
     * CSI reference signal received quality, multipled by -1.
     *
     * Reference: 3GPP TS 38.215.
     *
     * Range [3, 20], INT_MAX means invalid/unreported.
     */
    public int csiRsrq = 0;
    /**
     * CSI signal-to-noise and interference ratio.
     *
     * Reference: 3GPP TS 138.215 section 5.1.*, 3GPP TS 38.133 section 10.1.16.1.
     *
     * Range [-23, 40], INT_MAX means invalid/unreported.
     */
    public int csiSinr = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.NrSignalStrength.class) {
            return false;
        }
        android.hardware.radio.V1_4.NrSignalStrength other = (android.hardware.radio.V1_4.NrSignalStrength)otherObject;
        if (this.ssRsrp != other.ssRsrp) {
            return false;
        }
        if (this.ssRsrq != other.ssRsrq) {
            return false;
        }
        if (this.ssSinr != other.ssSinr) {
            return false;
        }
        if (this.csiRsrp != other.csiRsrp) {
            return false;
        }
        if (this.csiRsrq != other.csiRsrq) {
            return false;
        }
        if (this.csiSinr != other.csiSinr) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.ssRsrp), 
                android.os.HidlSupport.deepHashCode(this.ssRsrq), 
                android.os.HidlSupport.deepHashCode(this.ssSinr), 
                android.os.HidlSupport.deepHashCode(this.csiRsrp), 
                android.os.HidlSupport.deepHashCode(this.csiRsrq), 
                android.os.HidlSupport.deepHashCode(this.csiSinr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".ssRsrp = ");
        builder.append(this.ssRsrp);
        builder.append(", .ssRsrq = ");
        builder.append(this.ssRsrq);
        builder.append(", .ssSinr = ");
        builder.append(this.ssSinr);
        builder.append(", .csiRsrp = ");
        builder.append(this.csiRsrp);
        builder.append(", .csiRsrq = ");
        builder.append(this.csiRsrq);
        builder.append(", .csiSinr = ");
        builder.append(this.csiSinr);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NrSignalStrength> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NrSignalStrength> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.NrSignalStrength _hidl_vec_element = new android.hardware.radio.V1_4.NrSignalStrength();
                ((android.hardware.radio.V1_4.NrSignalStrength) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ssRsrp = _hidl_blob.getInt32(_hidl_offset + 0);
        ssRsrq = _hidl_blob.getInt32(_hidl_offset + 4);
        ssSinr = _hidl_blob.getInt32(_hidl_offset + 8);
        csiRsrp = _hidl_blob.getInt32(_hidl_offset + 12);
        csiRsrq = _hidl_blob.getInt32(_hidl_offset + 16);
        csiSinr = _hidl_blob.getInt32(_hidl_offset + 20);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NrSignalStrength> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, ssRsrp);
        _hidl_blob.putInt32(_hidl_offset + 4, ssRsrq);
        _hidl_blob.putInt32(_hidl_offset + 8, ssSinr);
        _hidl_blob.putInt32(_hidl_offset + 12, csiRsrp);
        _hidl_blob.putInt32(_hidl_offset + 16, csiRsrq);
        _hidl_blob.putInt32(_hidl_offset + 20, csiSinr);
    }
};

