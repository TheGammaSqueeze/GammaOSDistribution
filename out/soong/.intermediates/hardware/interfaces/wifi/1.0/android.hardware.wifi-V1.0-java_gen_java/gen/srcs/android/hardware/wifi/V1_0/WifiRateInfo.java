package android.hardware.wifi.V1_0;


public final class WifiRateInfo {
    /**
     * Preamble used for RTT measurements.
     */
    public int preamble = 0;
    /**
     * Number of spatial streams.
     */
    public int nss = 0;
    /**
     * Bandwidth of channel.
     */
    public int bw = 0;
    /**
     * OFDM/CCK rate code would be as per ieee std in the units of 0.5mbps.
     * HT/VHT it would be mcs index.
     */
    public byte rateMcsIdx = 0;
    /**
     * Bitrate in units of 100 Kbps.
     */
    public int bitRateInKbps = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.WifiRateInfo.class) {
            return false;
        }
        android.hardware.wifi.V1_0.WifiRateInfo other = (android.hardware.wifi.V1_0.WifiRateInfo)otherObject;
        if (this.preamble != other.preamble) {
            return false;
        }
        if (this.nss != other.nss) {
            return false;
        }
        if (this.bw != other.bw) {
            return false;
        }
        if (this.rateMcsIdx != other.rateMcsIdx) {
            return false;
        }
        if (this.bitRateInKbps != other.bitRateInKbps) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.preamble), 
                android.os.HidlSupport.deepHashCode(this.nss), 
                android.os.HidlSupport.deepHashCode(this.bw), 
                android.os.HidlSupport.deepHashCode(this.rateMcsIdx), 
                android.os.HidlSupport.deepHashCode(this.bitRateInKbps));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".preamble = ");
        builder.append(android.hardware.wifi.V1_0.WifiRatePreamble.toString(this.preamble));
        builder.append(", .nss = ");
        builder.append(android.hardware.wifi.V1_0.WifiRateNss.toString(this.nss));
        builder.append(", .bw = ");
        builder.append(android.hardware.wifi.V1_0.WifiChannelWidthInMhz.toString(this.bw));
        builder.append(", .rateMcsIdx = ");
        builder.append(this.rateMcsIdx);
        builder.append(", .bitRateInKbps = ");
        builder.append(this.bitRateInKbps);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiRateInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiRateInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiRateInfo _hidl_vec_element = new android.hardware.wifi.V1_0.WifiRateInfo();
                ((android.hardware.wifi.V1_0.WifiRateInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        preamble = _hidl_blob.getInt32(_hidl_offset + 0);
        nss = _hidl_blob.getInt32(_hidl_offset + 4);
        bw = _hidl_blob.getInt32(_hidl_offset + 8);
        rateMcsIdx = _hidl_blob.getInt8(_hidl_offset + 12);
        bitRateInKbps = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiRateInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, preamble);
        _hidl_blob.putInt32(_hidl_offset + 4, nss);
        _hidl_blob.putInt32(_hidl_offset + 8, bw);
        _hidl_blob.putInt8(_hidl_offset + 12, rateMcsIdx);
        _hidl_blob.putInt32(_hidl_offset + 16, bitRateInKbps);
    }
};

