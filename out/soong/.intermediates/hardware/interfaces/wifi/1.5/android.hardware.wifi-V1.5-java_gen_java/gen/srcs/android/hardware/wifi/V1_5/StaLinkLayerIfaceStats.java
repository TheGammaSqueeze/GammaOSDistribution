package android.hardware.wifi.V1_5;


public final class StaLinkLayerIfaceStats {
    /**
     * Baseline information as defined in HAL 1.0.
     */
    public android.hardware.wifi.V1_0.StaLinkLayerIfaceStats V1_0 = new android.hardware.wifi.V1_0.StaLinkLayerIfaceStats();
    /**
     * Duty cycle for the iface.
     * if this iface is being served using time slicing on a radio with one or more ifaces
     * (i.e MCC), then the duty cycle assigned to this iface in %.
     * If not using time slicing (i.e SCC or DBS), set to 100.
     */
    public byte timeSliceDutyCycleInPercent = 0;
    /**
     * WME Best Effort (BE) Access Category (AC) contention time statistics.
     */
    public android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats wmeBeContentionTimeStats = new android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats();
    /**
     * WME Background (BK) Access Category (AC) contention time statistics.
     */
    public android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats wmeBkContentionTimeStats = new android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats();
    /**
     * WME Video (VI) Access Category (AC) contention time statistics.
     */
    public android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats wmeViContentionTimeStats = new android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats();
    /**
     * WME Voice (VO) Access Category (AC) contention time statistics.
     */
    public android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats wmeVoContentionTimeStats = new android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats();
    /**
     * Per peer statistics.
     */
    public java.util.ArrayList<android.hardware.wifi.V1_5.StaPeerInfo> peers = new java.util.ArrayList<android.hardware.wifi.V1_5.StaPeerInfo>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_5.StaLinkLayerIfaceStats.class) {
            return false;
        }
        android.hardware.wifi.V1_5.StaLinkLayerIfaceStats other = (android.hardware.wifi.V1_5.StaLinkLayerIfaceStats)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.V1_0, other.V1_0)) {
            return false;
        }
        if (this.timeSliceDutyCycleInPercent != other.timeSliceDutyCycleInPercent) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeBeContentionTimeStats, other.wmeBeContentionTimeStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeBkContentionTimeStats, other.wmeBkContentionTimeStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeViContentionTimeStats, other.wmeViContentionTimeStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wmeVoContentionTimeStats, other.wmeVoContentionTimeStats)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.peers, other.peers)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.V1_0), 
                android.os.HidlSupport.deepHashCode(this.timeSliceDutyCycleInPercent), 
                android.os.HidlSupport.deepHashCode(this.wmeBeContentionTimeStats), 
                android.os.HidlSupport.deepHashCode(this.wmeBkContentionTimeStats), 
                android.os.HidlSupport.deepHashCode(this.wmeViContentionTimeStats), 
                android.os.HidlSupport.deepHashCode(this.wmeVoContentionTimeStats), 
                android.os.HidlSupport.deepHashCode(this.peers));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".V1_0 = ");
        builder.append(this.V1_0);
        builder.append(", .timeSliceDutyCycleInPercent = ");
        builder.append(this.timeSliceDutyCycleInPercent);
        builder.append(", .wmeBeContentionTimeStats = ");
        builder.append(this.wmeBeContentionTimeStats);
        builder.append(", .wmeBkContentionTimeStats = ");
        builder.append(this.wmeBkContentionTimeStats);
        builder.append(", .wmeViContentionTimeStats = ");
        builder.append(this.wmeViContentionTimeStats);
        builder.append(", .wmeVoContentionTimeStats = ");
        builder.append(this.wmeVoContentionTimeStats);
        builder.append(", .peers = ");
        builder.append(this.peers);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(224 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaLinkLayerIfaceStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaLinkLayerIfaceStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 224,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.StaLinkLayerIfaceStats _hidl_vec_element = new android.hardware.wifi.V1_5.StaLinkLayerIfaceStats();
                ((android.hardware.wifi.V1_5.StaLinkLayerIfaceStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 224);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.StaLinkLayerIfaceStats) V1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        timeSliceDutyCycleInPercent = _hidl_blob.getInt8(_hidl_offset + 136);
        ((android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats) wmeBeContentionTimeStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 140);
        ((android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats) wmeBkContentionTimeStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 156);
        ((android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats) wmeViContentionTimeStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 172);
        ((android.hardware.wifi.V1_5.StaLinkLayerIfaceContentionTimeStats) wmeVoContentionTimeStats).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 188);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 208 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    _hidl_offset + 208 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_5.StaPeerInfo>) peers).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.StaPeerInfo _hidl_vec_element = new android.hardware.wifi.V1_5.StaPeerInfo();
                ((android.hardware.wifi.V1_5.StaPeerInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                ((java.util.ArrayList<android.hardware.wifi.V1_5.StaPeerInfo>) peers).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(224 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 224));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 224);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        V1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt8(_hidl_offset + 136, timeSliceDutyCycleInPercent);
        wmeBeContentionTimeStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 140);
        wmeBkContentionTimeStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 156);
        wmeViContentionTimeStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 172);
        wmeVoContentionTimeStats.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 188);
        {
            int _hidl_vec_size = peers.size();
            _hidl_blob.putInt32(_hidl_offset + 208 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 208 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                peers.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(_hidl_offset + 208 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

