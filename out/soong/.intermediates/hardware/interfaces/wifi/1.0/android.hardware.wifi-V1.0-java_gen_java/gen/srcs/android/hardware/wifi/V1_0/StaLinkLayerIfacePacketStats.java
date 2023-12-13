package android.hardware.wifi.V1_0;


public final class StaLinkLayerIfacePacketStats {
    /**
     * Number of received unicast data packets.
     */
    public long rxMpdu = 0L;
    /**
     * Number of successfully transmitted unicast data pkts (ACK rcvd).
     */
    public long txMpdu = 0L;
    /**
     * Number of transmitted unicast data pkt losses (no ACK).
     */
    public long lostMpdu = 0L;
    /**
     * Number of transmitted unicast data retry pkts.
     */
    public long retries = 0L;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats other = (android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats)otherObject;
        if (this.rxMpdu != other.rxMpdu) {
            return false;
        }
        if (this.txMpdu != other.txMpdu) {
            return false;
        }
        if (this.lostMpdu != other.lostMpdu) {
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
                android.os.HidlSupport.deepHashCode(this.rxMpdu), 
                android.os.HidlSupport.deepHashCode(this.txMpdu), 
                android.os.HidlSupport.deepHashCode(this.lostMpdu), 
                android.os.HidlSupport.deepHashCode(this.retries));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".rxMpdu = ");
        builder.append(this.rxMpdu);
        builder.append(", .txMpdu = ");
        builder.append(this.txMpdu);
        builder.append(", .lostMpdu = ");
        builder.append(this.lostMpdu);
        builder.append(", .retries = ");
        builder.append(this.retries);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaLinkLayerIfacePacketStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaLinkLayerIfacePacketStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats _hidl_vec_element = new android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats();
                ((android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        rxMpdu = _hidl_blob.getInt64(_hidl_offset + 0);
        txMpdu = _hidl_blob.getInt64(_hidl_offset + 8);
        lostMpdu = _hidl_blob.getInt64(_hidl_offset + 16);
        retries = _hidl_blob.getInt64(_hidl_offset + 24);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaLinkLayerIfacePacketStats> _hidl_vec) {
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
        _hidl_blob.putInt64(_hidl_offset + 0, rxMpdu);
        _hidl_blob.putInt64(_hidl_offset + 8, txMpdu);
        _hidl_blob.putInt64(_hidl_offset + 16, lostMpdu);
        _hidl_blob.putInt64(_hidl_offset + 24, retries);
    }
};

