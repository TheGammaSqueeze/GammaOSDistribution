package android.hardware.wifi.V1_5;


public final class StaRateStat {
    /**
     * Wifi rate information: preamble, number of spatial streams, bandwidth, MCS, etc.
     */
    public android.hardware.wifi.V1_4.WifiRateInfo rateInfo = new android.hardware.wifi.V1_4.WifiRateInfo();
    /**
     * Number of successfully transmitted data packets (ACK received)
     */
    public int txMpdu = 0;
    /**
     * Number of received data packets
     */
    public int rxMpdu = 0;
    /**
     * Number of data packet losses (no ACK)
     */
    public int mpduLost = 0;
    /**
     * Number of data packet retries
     */
    public int retries = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_5.StaRateStat.class) {
            return false;
        }
        android.hardware.wifi.V1_5.StaRateStat other = (android.hardware.wifi.V1_5.StaRateStat)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.rateInfo, other.rateInfo)) {
            return false;
        }
        if (this.txMpdu != other.txMpdu) {
            return false;
        }
        if (this.rxMpdu != other.rxMpdu) {
            return false;
        }
        if (this.mpduLost != other.mpduLost) {
            return false;
        }
        if (this.retries != other.retries) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.rateInfo), 
                android.os.HidlSupport.deepHashCode(this.txMpdu), 
                android.os.HidlSupport.deepHashCode(this.rxMpdu), 
                android.os.HidlSupport.deepHashCode(this.mpduLost), 
                android.os.HidlSupport.deepHashCode(this.retries));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".rateInfo = ");
        builder.append(this.rateInfo);
        builder.append(", .txMpdu = ");
        builder.append(this.txMpdu);
        builder.append(", .rxMpdu = ");
        builder.append(this.rxMpdu);
        builder.append(", .mpduLost = ");
        builder.append(this.mpduLost);
        builder.append(", .retries = ");
        builder.append(this.retries);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(36 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaRateStat> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaRateStat> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 36,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.StaRateStat _hidl_vec_element = new android.hardware.wifi.V1_5.StaRateStat();
                ((android.hardware.wifi.V1_5.StaRateStat) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 36);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_4.WifiRateInfo) rateInfo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        txMpdu = _hidl_blob.getInt32(_hidl_offset + 20);
        rxMpdu = _hidl_blob.getInt32(_hidl_offset + 24);
        mpduLost = _hidl_blob.getInt32(_hidl_offset + 28);
        retries = _hidl_blob.getInt32(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(36 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaRateStat> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 36));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 36);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        rateInfo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 20, txMpdu);
        _hidl_blob.putInt32(_hidl_offset + 24, rxMpdu);
        _hidl_blob.putInt32(_hidl_offset + 28, mpduLost);
        _hidl_blob.putInt32(_hidl_offset + 32, retries);
    }
};

