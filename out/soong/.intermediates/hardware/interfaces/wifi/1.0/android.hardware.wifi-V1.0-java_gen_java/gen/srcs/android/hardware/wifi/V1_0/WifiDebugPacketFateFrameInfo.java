package android.hardware.wifi.V1_0;


public final class WifiDebugPacketFateFrameInfo {
    /**
     * The type of MAC-layer frame that this frame_info holds.
     * - For data frames, use FRAME_TYPE_ETHERNET_II.
     * - For management frames, use FRAME_TYPE_80211_MGMT.
     * - If the type of the frame is unknown, use FRAME_TYPE_UNKNOWN.
     */
    public int frameType = 0;
    /**
     * The number of bytes included in |frameContent|.
     * If the frame  contents are missing (e.g. RX frame dropped in firmware),
     * |frameLen| must be set to 0.
     */
    public long frameLen = 0L;
    /**
     * Host clock when this frame was received by the driver (either  outbound
     * from the host network stack, or inbound from the firmware).
     * - The timestamp must be taken from a clock which includes time the host
     *   spent suspended (e.g. ktime_get_boottime()).
     * - If no host timestamp is available (e.g. RX frame was dropped in firmware),
     *   this field must be set to 0.
     */
    public long driverTimestampUsec = 0L;
    /**
     * Firmware clock when this frame was received by the firmware
     * (either outbound from the host, or inbound from a remote  station).
     * - The timestamp must be taken from a clock which includes time firmware
     *   spent suspended (if applicable).
     * - If no firmware timestamp is available (e.g. TX frame was dropped by
     *   driver), this field must be set to 0.
     * - Consumers of |frameInfo| must not assume any synchronization between
     *   driver and firmware clocks.
     */
    public long firmwareTimestampUsec = 0L;
    /**
     * Actual frame content. This is the raw bytes of the corresponding packet.
     * - Should be provided for TX frames originated by the host.
     * - Should be provided for RX frames received by the driver.
     * - Optionally provided for TX frames originated by firmware.
     *   (At discretion of HAL implementation.)
     * - Optionally provided for RX frames dropped in firmware.
     *   (At discretion of HAL implementation.)
     * - If frame content is not provided, |frameLen| must be set to 0.
     */
    public java.util.ArrayList<Byte> frameContent = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo.class) {
            return false;
        }
        android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo other = (android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo)otherObject;
        if (this.frameType != other.frameType) {
            return false;
        }
        if (this.frameLen != other.frameLen) {
            return false;
        }
        if (this.driverTimestampUsec != other.driverTimestampUsec) {
            return false;
        }
        if (this.firmwareTimestampUsec != other.firmwareTimestampUsec) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.frameContent, other.frameContent)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.frameType), 
                android.os.HidlSupport.deepHashCode(this.frameLen), 
                android.os.HidlSupport.deepHashCode(this.driverTimestampUsec), 
                android.os.HidlSupport.deepHashCode(this.firmwareTimestampUsec), 
                android.os.HidlSupport.deepHashCode(this.frameContent));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".frameType = ");
        builder.append(android.hardware.wifi.V1_0.WifiDebugPacketFateFrameType.toString(this.frameType));
        builder.append(", .frameLen = ");
        builder.append(this.frameLen);
        builder.append(", .driverTimestampUsec = ");
        builder.append(this.driverTimestampUsec);
        builder.append(", .firmwareTimestampUsec = ");
        builder.append(this.firmwareTimestampUsec);
        builder.append(", .frameContent = ");
        builder.append(this.frameContent);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiDebugPacketFateFrameInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiDebugPacketFateFrameInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo _hidl_vec_element = new android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo();
                ((android.hardware.wifi.V1_0.WifiDebugPacketFateFrameInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        frameType = _hidl_blob.getInt32(_hidl_offset + 0);
        frameLen = _hidl_blob.getInt64(_hidl_offset + 8);
        driverTimestampUsec = _hidl_blob.getInt64(_hidl_offset + 16);
        firmwareTimestampUsec = _hidl_blob.getInt64(_hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) frameContent).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) frameContent).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiDebugPacketFateFrameInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, frameType);
        _hidl_blob.putInt64(_hidl_offset + 8, frameLen);
        _hidl_blob.putInt64(_hidl_offset + 16, driverTimestampUsec);
        _hidl_blob.putInt64(_hidl_offset + 24, firmwareTimestampUsec);
        {
            int _hidl_vec_size = frameContent.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, frameContent.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

