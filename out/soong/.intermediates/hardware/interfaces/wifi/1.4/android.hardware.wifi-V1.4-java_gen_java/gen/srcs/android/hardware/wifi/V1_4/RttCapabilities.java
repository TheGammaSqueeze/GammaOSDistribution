package android.hardware.wifi.V1_4;


public final class RttCapabilities {
    /**
     * if 1-sided rtt data collection is supported.
     */
    public boolean rttOneSidedSupported = false;
    /**
     * if ftm rtt data collection is supported.
     */
    public boolean rttFtmSupported = false;
    /**
     * if initiator supports LCI request. Applies to 2-sided RTT.
     */
    public boolean lciSupported = false;
    /**
     * if initiator supports LCR request. Applies to 2-sided RTT.
     */
    public boolean lcrSupported = false;
    /**
     * if 11mc responder mode is supported.
     */
    public boolean responderSupported = false;
    /**
     * Bit mask indicates what preamble is supported by initiator.
     * Combination of |RttPreamble| values.
     */
    public int preambleSupport;
    /**
     * Bit mask indicates what BW is supported by initiator.
     * Combination of |RttBw| values.
     */
    public int bwSupport;
    /**
     * Draft 11mc spec version supported by chip.
     * For instance, version 4.0 must be 40 and version 4.3 must be 43 etc.
     */
    public byte mcVersion = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_4.RttCapabilities.class) {
            return false;
        }
        android.hardware.wifi.V1_4.RttCapabilities other = (android.hardware.wifi.V1_4.RttCapabilities)otherObject;
        if (this.rttOneSidedSupported != other.rttOneSidedSupported) {
            return false;
        }
        if (this.rttFtmSupported != other.rttFtmSupported) {
            return false;
        }
        if (this.lciSupported != other.lciSupported) {
            return false;
        }
        if (this.lcrSupported != other.lcrSupported) {
            return false;
        }
        if (this.responderSupported != other.responderSupported) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.preambleSupport, other.preambleSupport)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bwSupport, other.bwSupport)) {
            return false;
        }
        if (this.mcVersion != other.mcVersion) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.rttOneSidedSupported), 
                android.os.HidlSupport.deepHashCode(this.rttFtmSupported), 
                android.os.HidlSupport.deepHashCode(this.lciSupported), 
                android.os.HidlSupport.deepHashCode(this.lcrSupported), 
                android.os.HidlSupport.deepHashCode(this.responderSupported), 
                android.os.HidlSupport.deepHashCode(this.preambleSupport), 
                android.os.HidlSupport.deepHashCode(this.bwSupport), 
                android.os.HidlSupport.deepHashCode(this.mcVersion));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".rttOneSidedSupported = ");
        builder.append(this.rttOneSidedSupported);
        builder.append(", .rttFtmSupported = ");
        builder.append(this.rttFtmSupported);
        builder.append(", .lciSupported = ");
        builder.append(this.lciSupported);
        builder.append(", .lcrSupported = ");
        builder.append(this.lcrSupported);
        builder.append(", .responderSupported = ");
        builder.append(this.responderSupported);
        builder.append(", .preambleSupport = ");
        builder.append(android.hardware.wifi.V1_4.RttPreamble.dumpBitfield(this.preambleSupport));
        builder.append(", .bwSupport = ");
        builder.append(android.hardware.wifi.V1_0.RttBw.dumpBitfield(this.bwSupport));
        builder.append(", .mcVersion = ");
        builder.append(this.mcVersion);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RttCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RttCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_4.RttCapabilities _hidl_vec_element = new android.hardware.wifi.V1_4.RttCapabilities();
                ((android.hardware.wifi.V1_4.RttCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        rttOneSidedSupported = _hidl_blob.getBool(_hidl_offset + 0);
        rttFtmSupported = _hidl_blob.getBool(_hidl_offset + 1);
        lciSupported = _hidl_blob.getBool(_hidl_offset + 2);
        lcrSupported = _hidl_blob.getBool(_hidl_offset + 3);
        responderSupported = _hidl_blob.getBool(_hidl_offset + 4);
        preambleSupport = _hidl_blob.getInt32(_hidl_offset + 8);
        bwSupport = _hidl_blob.getInt32(_hidl_offset + 12);
        mcVersion = _hidl_blob.getInt8(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RttCapabilities> _hidl_vec) {
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
        _hidl_blob.putBool(_hidl_offset + 0, rttOneSidedSupported);
        _hidl_blob.putBool(_hidl_offset + 1, rttFtmSupported);
        _hidl_blob.putBool(_hidl_offset + 2, lciSupported);
        _hidl_blob.putBool(_hidl_offset + 3, lcrSupported);
        _hidl_blob.putBool(_hidl_offset + 4, responderSupported);
        _hidl_blob.putInt32(_hidl_offset + 8, preambleSupport);
        _hidl_blob.putInt32(_hidl_offset + 12, bwSupport);
        _hidl_blob.putInt8(_hidl_offset + 16, mcVersion);
    }
};

