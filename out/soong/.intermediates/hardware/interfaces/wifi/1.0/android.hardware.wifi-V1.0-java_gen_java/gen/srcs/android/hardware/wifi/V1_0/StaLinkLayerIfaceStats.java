package android.hardware.wifi.V1_0;


public final class StaLinkLayerIfaceStats {
    /**
     * Number beacons received from the connected AP.
     */
    public int beaconRx = 0;
    /**
     * Access Point Beacon and Management frames RSSI (averaged).
     */
    public int avgRssiMgmt = 0;
    /**
     * WME Best Effort Access Category packet counters.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats wmeBePktStats = new android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats();
    /**
     * WME Background Access Category packet counters.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats wmeBkPktStats = new android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats();
    /**
     * WME Video Access Category packet counters.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats wmeViPktStats = new android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats();
    /**
     * WME Voice Access Category packet counters.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats wmeVoPktStats = new android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaLinkLayerIfaceStats.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaLinkLayerIfaceStats other = (android.hardware.wifi.V1_0.StaLinkLayerIfaceStats)otherObject;
        if (this.beaconRx != other.beaconRx) {
            return false;
        }
        if (this.avgRssiMgmt != other.avgRssiMgmt) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeBePktStats, other.wmeBePktStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeBkPktStats, other.wmeBkPktStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeViPktStats, other.wmeViPktStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeVoPktStats, other.wmeVoPktStats)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.beaconRx), 
                android.os.HidlSupport.deepHashCode(this.avgRssiMgmt), 
                android.os.HidlSupport.deepHashCode(this.wmeBePktStats), 
                android.os.HidlSupport.deepHashCode(this.wmeBkPktStats), 
                android.os.HidlSupport.deepHashCode(this.wmeViPktStats), 
                android.os.HidlSupport.deepHashCode(this.wmeVoPktStats));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".beaconRx = ");
        builder.append(this.beaconRx);
        builder.append(", .avgRssiMgmt = ");
        builder.append(this.avgRssiMgmt);
        builder.append(", .wmeBePktStats = ");
        builder.append(this.wmeBePktStats);
        builder.append(", .wmeBkPktStats = ");
        builder.append(this.wmeBkPktStats);
        builder.append(", .wmeViPktStats = ");
        builder.append(this.wmeViPktStats);
        builder.append(", .wmeVoPktStats = ");
        builder.append(this.wmeVoPktStats);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(136 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaLinkLayerIfaceStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaLinkLayerIfaceStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 136,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaLinkLayerIfaceStats _hidl_vec_element = new android.hardware.wifi.V1_0.StaLinkLayerIfaceStats();
                ((android.hardware.wifi.V1_0.StaLinkLayerIfaceStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 136);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        beaconRx = _hidl_blob.getInt32(_hidl_offset + 0);
        avgRssiMgmt = _hidl_blob.getInt32(_hidl_offset + 4);
        ((android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats) wmeBePktStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
        ((android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats) wmeBkPktStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 40);
        ((android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats) wmeViPktStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 72);
        ((android.hardware.wifi.V1_0.StaLinkLayerIfacePacketStats) wmeVoPktStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 104);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(136 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaLinkLayerIfaceStats> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 136));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 136);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, beaconRx);
        _hidl_blob.putInt32(_hidl_offset + 4, avgRssiMgmt);
        wmeBePktStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
        wmeBkPktStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 40);
        wmeViPktStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 72);
        wmeVoPktStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 104);
    }
};

