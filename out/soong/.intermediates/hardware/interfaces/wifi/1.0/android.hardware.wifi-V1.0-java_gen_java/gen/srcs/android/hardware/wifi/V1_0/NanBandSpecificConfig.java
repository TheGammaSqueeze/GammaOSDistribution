package android.hardware.wifi.V1_0;


public final class NanBandSpecificConfig {
    /**
     * RSSI values controlling clustering behavior per spec. RSSI values are specified without a sign,
     * e.g. a value of -65dBm would be specified as 65.
     */
    public byte rssiClose = 0;
    public byte rssiMiddle = 0;
    /**
     * RSSI value determining whether discovery is near (used if enabled in discovery by
     * |NanDiscoveryCommonConfig.useRssiThreshold|).
     * RSSI values are specified without a sign, e.g. a value of -65dBm would be specified as 65.
     * NAN Spec: RSSI_close_proximity
     */
    public byte rssiCloseProximity = 0;
    /**
     * Dwell time of each discovery channel in milliseconds. If set to 0 then the firmware determines
     * the dwell time to use.
     */
    public byte dwellTimeMs = 0;
    /**
     * Scan period of each discovery channel in seconds. If set to 0 then the firmware determines
     * the scan period to use.
     */
    public short scanPeriodSec = 0;
    /**
     * Specifies the discovery window interval for Sync beacons and SDF's.
     * Valid values of DW Interval are: 1, 2, 3, 4 and 5 corresponding to 1, 2, 4, 8, and 16 DWs.
     * Value of 0:
     *  - reserved in 2.4GHz band
     *  - no wakeup at all in 5GHz band
     * The publish/subscribe period values don't override this device level configurations if
     * it is specified.
     * Configuration is only used only if |validDiscoveryWindowIntervalVal| is set to true.
     * NAN Spec: Device Capability Attribute / 2.4 GHz DW, Device Capability Attribute / 5 GHz DW
     */
    public boolean validDiscoveryWindowIntervalVal = false;
    public byte discoveryWindowIntervalVal = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanBandSpecificConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanBandSpecificConfig other = (android.hardware.wifi.V1_0.NanBandSpecificConfig)otherObject;
        if (this.rssiClose != other.rssiClose) {
            return false;
        }
        if (this.rssiMiddle != other.rssiMiddle) {
            return false;
        }
        if (this.rssiCloseProximity != other.rssiCloseProximity) {
            return false;
        }
        if (this.dwellTimeMs != other.dwellTimeMs) {
            return false;
        }
        if (this.scanPeriodSec != other.scanPeriodSec) {
            return false;
        }
        if (this.validDiscoveryWindowIntervalVal != other.validDiscoveryWindowIntervalVal) {
            return false;
        }
        if (this.discoveryWindowIntervalVal != other.discoveryWindowIntervalVal) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.rssiClose), 
                android.os.HidlSupport.deepHashCode(this.rssiMiddle), 
                android.os.HidlSupport.deepHashCode(this.rssiCloseProximity), 
                android.os.HidlSupport.deepHashCode(this.dwellTimeMs), 
                android.os.HidlSupport.deepHashCode(this.scanPeriodSec), 
                android.os.HidlSupport.deepHashCode(this.validDiscoveryWindowIntervalVal), 
                android.os.HidlSupport.deepHashCode(this.discoveryWindowIntervalVal));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".rssiClose = ");
        builder.append(this.rssiClose);
        builder.append(", .rssiMiddle = ");
        builder.append(this.rssiMiddle);
        builder.append(", .rssiCloseProximity = ");
        builder.append(this.rssiCloseProximity);
        builder.append(", .dwellTimeMs = ");
        builder.append(this.dwellTimeMs);
        builder.append(", .scanPeriodSec = ");
        builder.append(this.scanPeriodSec);
        builder.append(", .validDiscoveryWindowIntervalVal = ");
        builder.append(this.validDiscoveryWindowIntervalVal);
        builder.append(", .discoveryWindowIntervalVal = ");
        builder.append(this.discoveryWindowIntervalVal);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(8 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanBandSpecificConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanBandSpecificConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 8,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanBandSpecificConfig _hidl_vec_element = new android.hardware.wifi.V1_0.NanBandSpecificConfig();
                ((android.hardware.wifi.V1_0.NanBandSpecificConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        rssiClose = _hidl_blob.getInt8(_hidl_offset + 0);
        rssiMiddle = _hidl_blob.getInt8(_hidl_offset + 1);
        rssiCloseProximity = _hidl_blob.getInt8(_hidl_offset + 2);
        dwellTimeMs = _hidl_blob.getInt8(_hidl_offset + 3);
        scanPeriodSec = _hidl_blob.getInt16(_hidl_offset + 4);
        validDiscoveryWindowIntervalVal = _hidl_blob.getBool(_hidl_offset + 6);
        discoveryWindowIntervalVal = _hidl_blob.getInt8(_hidl_offset + 7);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanBandSpecificConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, rssiClose);
        _hidl_blob.putInt8(_hidl_offset + 1, rssiMiddle);
        _hidl_blob.putInt8(_hidl_offset + 2, rssiCloseProximity);
        _hidl_blob.putInt8(_hidl_offset + 3, dwellTimeMs);
        _hidl_blob.putInt16(_hidl_offset + 4, scanPeriodSec);
        _hidl_blob.putBool(_hidl_offset + 6, validDiscoveryWindowIntervalVal);
        _hidl_blob.putInt8(_hidl_offset + 7, discoveryWindowIntervalVal);
    }
};

