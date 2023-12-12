package android.hardware.wifi.V1_0;


public final class RttResult {
    /**
     * Peer device mac address.
     */
    public byte[/* 6 */] addr = new byte[6];
    /**
     * Burst number in a multi-burst request.
     */
    public int burstNum = 0;
    /**
     * Total RTT measurement frames attempted.
     */
    public int measurementNumber = 0;
    /**
     * Total successful RTT measurement frames.
     */
    public int successNumber = 0;
    /**
     * Maximum number of "FTM frames per burst" supported by
     * the responder STA. Applies to 2-sided RTT only.
     * If reponder overrides with larger value:
     * - for single-burst request initiator will truncate the
     * larger value and send a TMR_STOP after receiving as
     * many frames as originally requested.
     * - for multi-burst request, initiator will return
     * failure right away.
     */
    public byte numberPerBurstPeer = 0;
    /**
     * Ranging status.
     */
    public int status = 0;
    /**
     * When status == RTT_STATUS_FAIL_BUSY_TRY_LATER,
     * this will be the time provided by the responder as to
     * when the request can be tried again. Applies to 2-sided
     * RTT only. In sec, 1-31sec.
     */
    public byte retryAfterDuration = 0;
    /**
     * RTT type.
     */
    public int type = 0;
    /**
     * Average rssi in 0.5 dB steps e.g. 143 implies -71.5 dB.
     */
    public int rssi = 0;
    /**
     * Rssi spread in 0.5 dB steps e.g. 5 implies 2.5 dB spread (optional).
     */
    public int rssiSpread = 0;
    /**
     * 1-sided RTT: TX rate of RTT frame.
     * 2-sided RTT: TX rate of initiator's Ack in response to FTM frame.
     */
    public android.hardware.wifi.V1_0.WifiRateInfo txRate = new android.hardware.wifi.V1_0.WifiRateInfo();
    /**
     * 1-sided RTT: TX rate of Ack from other side.
     * 2-sided RTT: TX rate of FTM frame coming from responder.
     */
    public android.hardware.wifi.V1_0.WifiRateInfo rxRate = new android.hardware.wifi.V1_0.WifiRateInfo();
    /**
     * Round trip time in picoseconds
     */
    public long rtt = 0L;
    /**
     * Rtt standard deviation in picoseconds.
     */
    public long rttSd = 0L;
    /**
     * Difference between max and min rtt times recorded in picoseconds.
     */
    public long rttSpread = 0L;
    /**
     * Distance in mm (optional).
     */
    public int distanceInMm = 0;
    /**
     * Standard deviation in mm (optional).
     */
    public int distanceSdInMm = 0;
    /**
     * Difference between max and min distance recorded in mm (optional).
     */
    public int distanceSpreadInMm = 0;
    /**
     * Time of the measurement (in microseconds since boot).
     */
    public long timeStampInUs = 0L;
    /**
     * in ms, actual time taken by the FW to finish one burst
     * measurement. Applies to 1-sided and 2-sided RTT.
     */
    public int burstDurationInMs = 0;
    /**
     * Number of bursts allowed by the responder. Applies
     * to 2-sided RTT only.
     */
    public int negotiatedBurstNum = 0;
    /**
     * for 11mc only.
     */
    public android.hardware.wifi.V1_0.WifiInformationElement lci = new android.hardware.wifi.V1_0.WifiInformationElement();
    /**
     * for 11mc only.
     */
    public android.hardware.wifi.V1_0.WifiInformationElement lcr = new android.hardware.wifi.V1_0.WifiInformationElement();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.RttResult.class) {
            return false;
        }
        android.hardware.wifi.V1_0.RttResult other = (android.hardware.wifi.V1_0.RttResult)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.addr, other.addr)) {
            return false;
        }
        if (this.burstNum != other.burstNum) {
            return false;
        }
        if (this.measurementNumber != other.measurementNumber) {
            return false;
        }
        if (this.successNumber != other.successNumber) {
            return false;
        }
        if (this.numberPerBurstPeer != other.numberPerBurstPeer) {
            return false;
        }
        if (this.status != other.status) {
            return false;
        }
        if (this.retryAfterDuration != other.retryAfterDuration) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        if (this.rssi != other.rssi) {
            return false;
        }
        if (this.rssiSpread != other.rssiSpread) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.txRate, other.txRate)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rxRate, other.rxRate)) {
            return false;
        }
        if (this.rtt != other.rtt) {
            return false;
        }
        if (this.rttSd != other.rttSd) {
            return false;
        }
        if (this.rttSpread != other.rttSpread) {
            return false;
        }
        if (this.distanceInMm != other.distanceInMm) {
            return false;
        }
        if (this.distanceSdInMm != other.distanceSdInMm) {
            return false;
        }
        if (this.distanceSpreadInMm != other.distanceSpreadInMm) {
            return false;
        }
        if (this.timeStampInUs != other.timeStampInUs) {
            return false;
        }
        if (this.burstDurationInMs != other.burstDurationInMs) {
            return false;
        }
        if (this.negotiatedBurstNum != other.negotiatedBurstNum) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.lci, other.lci)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.lcr, other.lcr)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.addr), 
                android.os.HidlSupport.deepHashCode(this.burstNum), 
                android.os.HidlSupport.deepHashCode(this.measurementNumber), 
                android.os.HidlSupport.deepHashCode(this.successNumber), 
                android.os.HidlSupport.deepHashCode(this.numberPerBurstPeer), 
                android.os.HidlSupport.deepHashCode(this.status), 
                android.os.HidlSupport.deepHashCode(this.retryAfterDuration), 
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.rssi), 
                android.os.HidlSupport.deepHashCode(this.rssiSpread), 
                android.os.HidlSupport.deepHashCode(this.txRate), 
                android.os.HidlSupport.deepHashCode(this.rxRate), 
                android.os.HidlSupport.deepHashCode(this.rtt), 
                android.os.HidlSupport.deepHashCode(this.rttSd), 
                android.os.HidlSupport.deepHashCode(this.rttSpread), 
                android.os.HidlSupport.deepHashCode(this.distanceInMm), 
                android.os.HidlSupport.deepHashCode(this.distanceSdInMm), 
                android.os.HidlSupport.deepHashCode(this.distanceSpreadInMm), 
                android.os.HidlSupport.deepHashCode(this.timeStampInUs), 
                android.os.HidlSupport.deepHashCode(this.burstDurationInMs), 
                android.os.HidlSupport.deepHashCode(this.negotiatedBurstNum), 
                android.os.HidlSupport.deepHashCode(this.lci), 
                android.os.HidlSupport.deepHashCode(this.lcr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".addr = ");
        builder.append(java.util.Arrays.toString(this.addr));
        builder.append(", .burstNum = ");
        builder.append(this.burstNum);
        builder.append(", .measurementNumber = ");
        builder.append(this.measurementNumber);
        builder.append(", .successNumber = ");
        builder.append(this.successNumber);
        builder.append(", .numberPerBurstPeer = ");
        builder.append(this.numberPerBurstPeer);
        builder.append(", .status = ");
        builder.append(android.hardware.wifi.V1_0.RttStatus.toString(this.status));
        builder.append(", .retryAfterDuration = ");
        builder.append(this.retryAfterDuration);
        builder.append(", .type = ");
        builder.append(android.hardware.wifi.V1_0.RttType.toString(this.type));
        builder.append(", .rssi = ");
        builder.append(this.rssi);
        builder.append(", .rssiSpread = ");
        builder.append(this.rssiSpread);
        builder.append(", .txRate = ");
        builder.append(this.txRate);
        builder.append(", .rxRate = ");
        builder.append(this.rxRate);
        builder.append(", .rtt = ");
        builder.append(this.rtt);
        builder.append(", .rttSd = ");
        builder.append(this.rttSd);
        builder.append(", .rttSpread = ");
        builder.append(this.rttSpread);
        builder.append(", .distanceInMm = ");
        builder.append(this.distanceInMm);
        builder.append(", .distanceSdInMm = ");
        builder.append(this.distanceSdInMm);
        builder.append(", .distanceSpreadInMm = ");
        builder.append(this.distanceSpreadInMm);
        builder.append(", .timeStampInUs = ");
        builder.append(this.timeStampInUs);
        builder.append(", .burstDurationInMs = ");
        builder.append(this.burstDurationInMs);
        builder.append(", .negotiatedBurstNum = ");
        builder.append(this.negotiatedBurstNum);
        builder.append(", .lci = ");
        builder.append(this.lci);
        builder.append(", .lcr = ");
        builder.append(this.lcr);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(192 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RttResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RttResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 192,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.RttResult _hidl_vec_element = new android.hardware.wifi.V1_0.RttResult();
                ((android.hardware.wifi.V1_0.RttResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 192);
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
        burstNum = _hidl_blob.getInt32(_hidl_offset + 8);
        measurementNumber = _hidl_blob.getInt32(_hidl_offset + 12);
        successNumber = _hidl_blob.getInt32(_hidl_offset + 16);
        numberPerBurstPeer = _hidl_blob.getInt8(_hidl_offset + 20);
        status = _hidl_blob.getInt32(_hidl_offset + 24);
        retryAfterDuration = _hidl_blob.getInt8(_hidl_offset + 28);
        type = _hidl_blob.getInt32(_hidl_offset + 32);
        rssi = _hidl_blob.getInt32(_hidl_offset + 36);
        rssiSpread = _hidl_blob.getInt32(_hidl_offset + 40);
        ((android.hardware.wifi.V1_0.WifiRateInfo) txRate).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 44);
        ((android.hardware.wifi.V1_0.WifiRateInfo) rxRate).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 64);
        rtt = _hidl_blob.getInt64(_hidl_offset + 88);
        rttSd = _hidl_blob.getInt64(_hidl_offset + 96);
        rttSpread = _hidl_blob.getInt64(_hidl_offset + 104);
        distanceInMm = _hidl_blob.getInt32(_hidl_offset + 112);
        distanceSdInMm = _hidl_blob.getInt32(_hidl_offset + 116);
        distanceSpreadInMm = _hidl_blob.getInt32(_hidl_offset + 120);
        timeStampInUs = _hidl_blob.getInt64(_hidl_offset + 128);
        burstDurationInMs = _hidl_blob.getInt32(_hidl_offset + 136);
        negotiatedBurstNum = _hidl_blob.getInt32(_hidl_offset + 140);
        ((android.hardware.wifi.V1_0.WifiInformationElement) lci).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 144);
        ((android.hardware.wifi.V1_0.WifiInformationElement) lcr).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 168);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(192 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RttResult> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 192));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 192);
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
        _hidl_blob.putInt32(_hidl_offset + 8, burstNum);
        _hidl_blob.putInt32(_hidl_offset + 12, measurementNumber);
        _hidl_blob.putInt32(_hidl_offset + 16, successNumber);
        _hidl_blob.putInt8(_hidl_offset + 20, numberPerBurstPeer);
        _hidl_blob.putInt32(_hidl_offset + 24, status);
        _hidl_blob.putInt8(_hidl_offset + 28, retryAfterDuration);
        _hidl_blob.putInt32(_hidl_offset + 32, type);
        _hidl_blob.putInt32(_hidl_offset + 36, rssi);
        _hidl_blob.putInt32(_hidl_offset + 40, rssiSpread);
        txRate.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 44);
        rxRate.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 64);
        _hidl_blob.putInt64(_hidl_offset + 88, rtt);
        _hidl_blob.putInt64(_hidl_offset + 96, rttSd);
        _hidl_blob.putInt64(_hidl_offset + 104, rttSpread);
        _hidl_blob.putInt32(_hidl_offset + 112, distanceInMm);
        _hidl_blob.putInt32(_hidl_offset + 116, distanceSdInMm);
        _hidl_blob.putInt32(_hidl_offset + 120, distanceSpreadInMm);
        _hidl_blob.putInt64(_hidl_offset + 128, timeStampInUs);
        _hidl_blob.putInt32(_hidl_offset + 136, burstDurationInMs);
        _hidl_blob.putInt32(_hidl_offset + 140, negotiatedBurstNum);
        lci.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 144);
        lcr.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 168);
    }
};

