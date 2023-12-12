package android.hardware.wifi.V1_4;


public final class RttConfig {
    /**
     * Peer device mac address.
     */
    public byte[/* 6 */] addr = new byte[6];
    /**
     * 1-sided or 2-sided RTT.
     */
    public int type = 0;
    /**
     * Optional - peer device hint (STA, P2P, AP).
     */
    public int peer = 0;
    /**
     * Required for STA-AP mode, optional for P2P, NBD etc.
     */
    public android.hardware.wifi.V1_0.WifiChannelInfo channel = new android.hardware.wifi.V1_0.WifiChannelInfo();
    /**
     * Time interval between bursts (units: 100 ms).
     * Applies to 1-sided and 2-sided RTT multi-burst requests.
     * Range: 0-31, 0: no preference by initiator (2-sided RTT).
     */
    public int burstPeriod = 0;
    /**
     * Total number of RTT bursts to be executed. It will be
     * specified in the same way as the parameter "Number of
     * Burst Exponent" found in the FTM frame format. It
     * applies to both: 1-sided RTT and 2-sided RTT. Valid
     * values are 0 to 15 as defined in 802.11mc std.
     * 0 means single shot
     * The implication of this parameter on the maximum
     * number of RTT results is the following:
     * for 1-sided RTT: max num of RTT results = (2^num_burst)*(num_frames_per_burst)
     * for 2-sided RTT: max num of RTT results = (2^num_burst)*(num_frames_per_burst - 1)
     */
    public int numBurst = 0;
    /**
     * Num of frames per burst.
     * Minimum value = 1, Maximum value = 31
     * For 2-sided this equals the number of FTM frames
     * to be attempted in a single burst. This also
     * equals the number of FTM frames that the
     * initiator will request that the responder send
     * in a single frame.
     */
    public int numFramesPerBurst = 0;
    /**
     * Number of retries for a failed RTT frame.
     * Applies to 1-sided RTT only. Minimum value = 0, Maximum value = 3
     */
    public int numRetriesPerRttFrame = 0;
    /**
     * Following fields are only valid for 2-side RTT.
     *
     *
     * Maximum number of retries that the initiator can
     * retry an FTMR frame.
     * Minimum value = 0, Maximum value = 3
     */
    public int numRetriesPerFtmr = 0;
    /**
     * Whether to request location civic info or not.
     */
    public boolean mustRequestLci = false;
    /**
     * Whether to request location civic records or not.
     */
    public boolean mustRequestLcr = false;
    /**
     * Applies to 1-sided and 2-sided RTT. Valid values will
     * be 2-11 and 15 as specified by the 802.11mc std for
     * the FTM parameter burst duration. In a multi-burst
     * request, if responder overrides with larger value,
     * the initiator will return failure. In a single-burst
     * request if responder overrides with larger value,
     * the initiator will sent TMR_STOP to terminate RTT
     * at the end of the burst_duration it requested.
     */
    public int burstDuration = 0;
    /**
     * RTT preamble to be used in the RTT frames.
     */
    public int preamble = 0;
    /**
     * RTT BW to be used in the RTT frames.
     */
    public int bw = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_4.RttConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_4.RttConfig other = (android.hardware.wifi.V1_4.RttConfig)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.addr, other.addr)) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (this.peer != other.peer) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.channel, other.channel)) {
            return false;
        }
        if (this.burstPeriod != other.burstPeriod) {
            return false;
        }
        if (this.numBurst != other.numBurst) {
            return false;
        }
        if (this.numFramesPerBurst != other.numFramesPerBurst) {
            return false;
        }
        if (this.numRetriesPerRttFrame != other.numRetriesPerRttFrame) {
            return false;
        }
        if (this.numRetriesPerFtmr != other.numRetriesPerFtmr) {
            return false;
        }
        if (this.mustRequestLci != other.mustRequestLci) {
            return false;
        }
        if (this.mustRequestLcr != other.mustRequestLcr) {
            return false;
        }
        if (this.burstDuration != other.burstDuration) {
            return false;
        }
        if (this.preamble != other.preamble) {
            return false;
        }
        if (this.bw != other.bw) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.addr), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.peer), 
                android.os.HidlSupport.deepHashCode(this.channel), 
                android.os.HidlSupport.deepHashCode(this.burstPeriod), 
                android.os.HidlSupport.deepHashCode(this.numBurst), 
                android.os.HidlSupport.deepHashCode(this.numFramesPerBurst), 
                android.os.HidlSupport.deepHashCode(this.numRetriesPerRttFrame), 
                android.os.HidlSupport.deepHashCode(this.numRetriesPerFtmr), 
                android.os.HidlSupport.deepHashCode(this.mustRequestLci), 
                android.os.HidlSupport.deepHashCode(this.mustRequestLcr), 
                android.os.HidlSupport.deepHashCode(this.burstDuration), 
                android.os.HidlSupport.deepHashCode(this.preamble), 
                android.os.HidlSupport.deepHashCode(this.bw));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".addr = ");
        builder.append(java.util.Arrays.toString(this.addr));
        builder.append(", .type = ");
        builder.append(android.hardware.wifi.V1_0.RttType.toString(this.type));
        builder.append(", .peer = ");
        builder.append(android.hardware.wifi.V1_0.RttPeerType.toString(this.peer));
        builder.append(", .channel = ");
        builder.append(this.channel);
        builder.append(", .burstPeriod = ");
        builder.append(this.burstPeriod);
        builder.append(", .numBurst = ");
        builder.append(this.numBurst);
        builder.append(", .numFramesPerBurst = ");
        builder.append(this.numFramesPerBurst);
        builder.append(", .numRetriesPerRttFrame = ");
        builder.append(this.numRetriesPerRttFrame);
        builder.append(", .numRetriesPerFtmr = ");
        builder.append(this.numRetriesPerFtmr);
        builder.append(", .mustRequestLci = ");
        builder.append(this.mustRequestLci);
        builder.append(", .mustRequestLcr = ");
        builder.append(this.mustRequestLcr);
        builder.append(", .burstDuration = ");
        builder.append(this.burstDuration);
        builder.append(", .preamble = ");
        builder.append(android.hardware.wifi.V1_4.RttPreamble.toString(this.preamble));
        builder.append(", .bw = ");
        builder.append(android.hardware.wifi.V1_0.RttBw.toString(this.bw));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(68 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RttConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RttConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 68,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_4.RttConfig _hidl_vec_element = new android.hardware.wifi.V1_4.RttConfig();
                ((android.hardware.wifi.V1_4.RttConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 68);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) addr, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        type = _hidl_blob.getInt32(_hidl_offset + 8);
        peer = _hidl_blob.getInt32(_hidl_offset + 12);
        ((android.hardware.wifi.V1_0.WifiChannelInfo) channel).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
        burstPeriod = _hidl_blob.getInt32(_hidl_offset + 32);
        numBurst = _hidl_blob.getInt32(_hidl_offset + 36);
        numFramesPerBurst = _hidl_blob.getInt32(_hidl_offset + 40);
        numRetriesPerRttFrame = _hidl_blob.getInt32(_hidl_offset + 44);
        numRetriesPerFtmr = _hidl_blob.getInt32(_hidl_offset + 48);
        mustRequestLci = _hidl_blob.getBool(_hidl_offset + 52);
        mustRequestLcr = _hidl_blob.getBool(_hidl_offset + 53);
        burstDuration = _hidl_blob.getInt32(_hidl_offset + 56);
        preamble = _hidl_blob.getInt32(_hidl_offset + 60);
        bw = _hidl_blob.getInt32(_hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(68 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RttConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 68));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 68);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) addr;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        _hidl_blob.putInt32(_hidl_offset + 8, type);
        _hidl_blob.putInt32(_hidl_offset + 12, peer);
        channel.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
        _hidl_blob.putInt32(_hidl_offset + 32, burstPeriod);
        _hidl_blob.putInt32(_hidl_offset + 36, numBurst);
        _hidl_blob.putInt32(_hidl_offset + 40, numFramesPerBurst);
        _hidl_blob.putInt32(_hidl_offset + 44, numRetriesPerRttFrame);
        _hidl_blob.putInt32(_hidl_offset + 48, numRetriesPerFtmr);
        _hidl_blob.putBool(_hidl_offset + 52, mustRequestLci);
        _hidl_blob.putBool(_hidl_offset + 53, mustRequestLcr);
        _hidl_blob.putInt32(_hidl_offset + 56, burstDuration);
        _hidl_blob.putInt32(_hidl_offset + 60, preamble);
        _hidl_blob.putInt32(_hidl_offset + 64, bw);
    }
};

