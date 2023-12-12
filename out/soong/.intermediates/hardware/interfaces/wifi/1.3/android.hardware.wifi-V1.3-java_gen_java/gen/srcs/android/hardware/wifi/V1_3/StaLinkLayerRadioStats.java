package android.hardware.wifi.V1_3;


public final class StaLinkLayerRadioStats {
    /**
     * Baseline information as defined in HAL 1.0.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerRadioStats V1_0 = new android.hardware.wifi.V1_0.StaLinkLayerRadioStats();
    /**
     * Total time for which the radio is awake due to NAN scan since boot or crash.
     */
    public int onTimeInMsForNanScan = 0;
    /**
     * Total time for which the radio is awake due to background scan since boot or crash.
     */
    public int onTimeInMsForBgScan = 0;
    /**
     * Total time for which the radio is awake due to roam scan since boot or crash.
     */
    public int onTimeInMsForRoamScan = 0;
    /**
     * Total time for which the radio is awake due to PNO scan since boot or crash.
     */
    public int onTimeInMsForPnoScan = 0;
    /**
     * Total time for which the radio is awake due to Hotspot 2.0 scans and GAS exchange since boot
     * or crash.
     */
    public int onTimeInMsForHs20Scan = 0;
    /**
     * List of channel stats associated with this radio
     */
    public java.util.ArrayList<android.hardware.wifi.V1_3.WifiChannelStats> channelStats = new java.util.ArrayList<android.hardware.wifi.V1_3.WifiChannelStats>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_3.StaLinkLayerRadioStats.class) {
            return false;
        }
        android.hardware.wifi.V1_3.StaLinkLayerRadioStats other = (android.hardware.wifi.V1_3.StaLinkLayerRadioStats)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.V1_0, other.V1_0)) {
            return false;
        }
        if (this.onTimeInMsForNanScan != other.onTimeInMsForNanScan) {
            return false;
        }
        if (this.onTimeInMsForBgScan != other.onTimeInMsForBgScan) {
            return false;
        }
        if (this.onTimeInMsForRoamScan != other.onTimeInMsForRoamScan) {
            return false;
        }
        if (this.onTimeInMsForPnoScan != other.onTimeInMsForPnoScan) {
            return false;
        }
        if (this.onTimeInMsForHs20Scan != other.onTimeInMsForHs20Scan) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.channelStats, other.channelStats)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.V1_0), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForNanScan), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForBgScan), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForRoamScan), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForPnoScan), 
                android.os.HidlSupport.deepHashCode(this.onTimeInMsForHs20Scan), 
                android.os.HidlSupport.deepHashCode(this.channelStats));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".V1_0 = ");
        builder.append(this.V1_0);
        builder.append(", .onTimeInMsForNanScan = ");
        builder.append(this.onTimeInMsForNanScan);
        builder.append(", .onTimeInMsForBgScan = ");
        builder.append(this.onTimeInMsForBgScan);
        builder.append(", .onTimeInMsForRoamScan = ");
        builder.append(this.onTimeInMsForRoamScan);
        builder.append(", .onTimeInMsForPnoScan = ");
        builder.append(this.onTimeInMsForPnoScan);
        builder.append(", .onTimeInMsForHs20Scan = ");
        builder.append(this.onTimeInMsForHs20Scan);
        builder.append(", .channelStats = ");
        builder.append(this.channelStats);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaLinkLayerRadioStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaLinkLayerRadioStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_3.StaLinkLayerRadioStats _hidl_vec_element = new android.hardware.wifi.V1_3.StaLinkLayerRadioStats();
                ((android.hardware.wifi.V1_3.StaLinkLayerRadioStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.StaLinkLayerRadioStats) V1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        onTimeInMsForNanScan = _hidl_blob.getInt32(_hidl_offset + 32);
        onTimeInMsForBgScan = _hidl_blob.getInt32(_hidl_offset + 36);
        onTimeInMsForRoamScan = _hidl_blob.getInt32(_hidl_offset + 40);
        onTimeInMsForPnoScan = _hidl_blob.getInt32(_hidl_offset + 44);
        onTimeInMsForHs20Scan = _hidl_blob.getInt32(_hidl_offset + 48);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_3.WifiChannelStats>) channelStats).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_3.WifiChannelStats _hidl_vec_element = new android.hardware.wifi.V1_3.WifiChannelStats();
                ((android.hardware.wifi.V1_3.WifiChannelStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                ((java.util.ArrayList<android.hardware.wifi.V1_3.WifiChannelStats>) channelStats).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaLinkLayerRadioStats> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        V1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 32, onTimeInMsForNanScan);
        _hidl_blob.putInt32(_hidl_offset + 36, onTimeInMsForBgScan);
        _hidl_blob.putInt32(_hidl_offset + 40, onTimeInMsForRoamScan);
        _hidl_blob.putInt32(_hidl_offset + 44, onTimeInMsForPnoScan);
        _hidl_blob.putInt32(_hidl_offset + 48, onTimeInMsForHs20Scan);
        {
            int _hidl_vec_size = channelStats.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                channelStats.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

