package android.hardware.wifi.V1_0;


public final class WifiDebugHostWakeReasonStats {
    /**
     * Total count of cmd/event wakes.
     * These must account for all wakeups due to WLAN management
     * commands/events received over the air.
     */
    public int totalCmdEventWakeCnt = 0;
    /**
     * Vector of wake counts per cmd/event type.
     * The number of command types and their meaning is only understood by the
     * vendor.
     */
    public java.util.ArrayList<Integer> cmdEventWakeCntPerType = new java.util.ArrayList<Integer>();
    /**
     * Total count of drive/fw wakes.
     * These must account for all wakeups due to local driver/firmware
     * interactions. These include all vendor implementation specific
     * interactions like any heart-beat monitoring, Bus management, etc.
     */
    public int totalDriverFwLocalWakeCnt = 0;
    /**
     * Vector of wake counts per driver/firmware interaction type.
     * The number of command types and their meaning is only understood by the
     * vendor.
     */
    public java.util.ArrayList<Integer> driverFwLocalWakeCntPerType = new java.util.ArrayList<Integer>();
    /**
     * Total data rx packets, that woke up host.
     */
    public int totalRxPacketWakeCnt = 0;
    public android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxPacketDetails rxPktWakeDetails = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxPacketDetails();
    public android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxMulticastPacketDetails rxMulticastPkWakeDetails = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxMulticastPacketDetails();
    public android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails rxIcmpPkWakeDetails = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats.class) {
            return false;
        }
        android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats other = (android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats)otherObject;
        if (this.totalCmdEventWakeCnt != other.totalCmdEventWakeCnt) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cmdEventWakeCntPerType, other.cmdEventWakeCntPerType)) {
            return false;
        }
        if (this.totalDriverFwLocalWakeCnt != other.totalDriverFwLocalWakeCnt) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.driverFwLocalWakeCntPerType, other.driverFwLocalWakeCntPerType)) {
            return false;
        }
        if (this.totalRxPacketWakeCnt != other.totalRxPacketWakeCnt) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rxPktWakeDetails, other.rxPktWakeDetails)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rxMulticastPkWakeDetails, other.rxMulticastPkWakeDetails)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rxIcmpPkWakeDetails, other.rxIcmpPkWakeDetails)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.totalCmdEventWakeCnt), 
                android.os.HidlSupport.deepHashCode(this.cmdEventWakeCntPerType), 
                android.os.HidlSupport.deepHashCode(this.totalDriverFwLocalWakeCnt), 
                android.os.HidlSupport.deepHashCode(this.driverFwLocalWakeCntPerType), 
                android.os.HidlSupport.deepHashCode(this.totalRxPacketWakeCnt), 
                android.os.HidlSupport.deepHashCode(this.rxPktWakeDetails), 
                android.os.HidlSupport.deepHashCode(this.rxMulticastPkWakeDetails), 
                android.os.HidlSupport.deepHashCode(this.rxIcmpPkWakeDetails));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".totalCmdEventWakeCnt = ");
        builder.append(this.totalCmdEventWakeCnt);
        builder.append(", .cmdEventWakeCntPerType = ");
        builder.append(this.cmdEventWakeCntPerType);
        builder.append(", .totalDriverFwLocalWakeCnt = ");
        builder.append(this.totalDriverFwLocalWakeCnt);
        builder.append(", .driverFwLocalWakeCntPerType = ");
        builder.append(this.driverFwLocalWakeCntPerType);
        builder.append(", .totalRxPacketWakeCnt = ");
        builder.append(this.totalRxPacketWakeCnt);
        builder.append(", .rxPktWakeDetails = ");
        builder.append(this.rxPktWakeDetails);
        builder.append(", .rxMulticastPkWakeDetails = ");
        builder.append(this.rxMulticastPkWakeDetails);
        builder.append(", .rxIcmpPkWakeDetails = ");
        builder.append(this.rxIcmpPkWakeDetails);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(96 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiDebugHostWakeReasonStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiDebugHostWakeReasonStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats _hidl_vec_element = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats();
                ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        totalCmdEventWakeCnt = _hidl_blob.getInt32(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) cmdEventWakeCntPerType).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) cmdEventWakeCntPerType).add(_hidl_vec_element);
            }
        }
        totalDriverFwLocalWakeCnt = _hidl_blob.getInt32(_hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) driverFwLocalWakeCntPerType).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) driverFwLocalWakeCntPerType).add(_hidl_vec_element);
            }
        }
        totalRxPacketWakeCnt = _hidl_blob.getInt32(_hidl_offset + 48);
        ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxPacketDetails) rxPktWakeDetails).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 52);
        ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxMulticastPacketDetails) rxMulticastPkWakeDetails).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 64);
        ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails) rxIcmpPkWakeDetails).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 76);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(96 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiDebugHostWakeReasonStats> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, totalCmdEventWakeCnt);
        {
            int _hidl_vec_size = cmdEventWakeCntPerType.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, cmdEventWakeCntPerType.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, totalDriverFwLocalWakeCnt);
        {
            int _hidl_vec_size = driverFwLocalWakeCntPerType.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, driverFwLocalWakeCntPerType.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 48, totalRxPacketWakeCnt);
        rxPktWakeDetails.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 52);
        rxMulticastPkWakeDetails.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 64);
        rxIcmpPkWakeDetails.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 76);
    }
};

