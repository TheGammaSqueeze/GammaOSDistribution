package android.hardware.wifi.V1_4;


public final class NanDebugConfig {
    /**
     * Specification of the lower 2 bytes of the cluster ID. The cluster ID is 50-60-9a-01-00-00 to
     * 50-60-9a-01-FF-FF. Configuration of the bottom and top values of the range (which defaults to
     * 0x0000 and 0xFFFF respectively).
     * Configuration is only used if |validClusterIdVals| is set to true.
     */
    public boolean validClusterIdVals = false;
    public short clusterIdBottomRangeVal = 0;
    public short clusterIdTopRangeVal = 0;
    /**
     * NAN management interface address, if specified (|validIntfAddrVal| is true) then overrides any
     * other configuration (specifically the default randomization configured by
     * |NanConfigRequest.macAddressRandomizationIntervalSec|).
     */
    public boolean validIntfAddrVal = false;
    public byte[/* 6 */] intfAddrVal = new byte[6];
    /**
     * Combination of the 24 bit Organizationally Unique ID (OUI) and the 8 bit OUI Type.
     * Used if |validOuiVal| is set to true.
     */
    public boolean validOuiVal = false;
    public int ouiVal = 0;
    /**
     * Force the Random Factor to the specified value for all transmitted Sync/Discovery beacons.
     * Used if |validRandomFactorForceVal| is set to true.
     * NAN Spec: Master Indication Attribute / Random Factor
     */
    public boolean validRandomFactorForceVal = false;
    public byte randomFactorForceVal = 0;
    /**
     * Forces the hop-count for all transmitted Sync and Discovery Beacons NO matter the real
     * hop-count being received over the air. Used if the |validHopCountForceVal}| flag is set to
     * true.
     * NAN Spec: Cluster Attribute / Anchor Master Information / Hop Count to Anchor Master
     */
    public boolean validHopCountForceVal = false;
    public byte hopCountForceVal = 0;
    /**
     * Frequency in MHz to of the discovery channel in the specified band. Indexed by |NanBandIndex|.
     * Used if the |validDiscoveryChannelVal| is set to true.
     */
    public boolean validDiscoveryChannelVal = false;
    public int[/* 3 */] discoveryChannelMhzVal = new int[3];
    /**
     * Specifies whether sync/discovery beacons are transmitted in the specified band. Indexed by
     * |NanBandIndex|. Used if the |validUseBeaconsInBandVal| is set to true.
     */
    public boolean validUseBeaconsInBandVal = false;
    public boolean[/* 3 */] useBeaconsInBandVal = new boolean[3];
    /**
     * Specifies whether SDF (service discovery frames) are transmitted in the specified band. Indexed
     * by |NanBandIndex|. Used if the |validUseSdfInBandVal| is set to true.
     */
    public boolean validUseSdfInBandVal = false;
    public boolean[/* 3 */] useSdfInBandVal = new boolean[3];

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_4.NanDebugConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_4.NanDebugConfig other = (android.hardware.wifi.V1_4.NanDebugConfig)otherObject;
        if (this.validClusterIdVals != other.validClusterIdVals) {
            return false;
        }
        if (this.clusterIdBottomRangeVal != other.clusterIdBottomRangeVal) {
            return false;
        }
        if (this.clusterIdTopRangeVal != other.clusterIdTopRangeVal) {
            return false;
        }
        if (this.validIntfAddrVal != other.validIntfAddrVal) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.intfAddrVal, other.intfAddrVal)) {
            return false;
        }
        if (this.validOuiVal != other.validOuiVal) {
            return false;
        }
        if (this.ouiVal != other.ouiVal) {
            return false;
        }
        if (this.validRandomFactorForceVal != other.validRandomFactorForceVal) {
            return false;
        }
        if (this.randomFactorForceVal != other.randomFactorForceVal) {
            return false;
        }
        if (this.validHopCountForceVal != other.validHopCountForceVal) {
            return false;
        }
        if (this.hopCountForceVal != other.hopCountForceVal) {
            return false;
        }
        if (this.validDiscoveryChannelVal != other.validDiscoveryChannelVal) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.discoveryChannelMhzVal, other.discoveryChannelMhzVal)) {
            return false;
        }
        if (this.validUseBeaconsInBandVal != other.validUseBeaconsInBandVal) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.useBeaconsInBandVal, other.useBeaconsInBandVal)) {
            return false;
        }
        if (this.validUseSdfInBandVal != other.validUseSdfInBandVal) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.useSdfInBandVal, other.useSdfInBandVal)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.validClusterIdVals), 
                android.os.HidlSupport.deepHashCode(this.clusterIdBottomRangeVal), 
                android.os.HidlSupport.deepHashCode(this.clusterIdTopRangeVal), 
                android.os.HidlSupport.deepHashCode(this.validIntfAddrVal), 
                android.os.HidlSupport.deepHashCode(this.intfAddrVal), 
                android.os.HidlSupport.deepHashCode(this.validOuiVal), 
                android.os.HidlSupport.deepHashCode(this.ouiVal), 
                android.os.HidlSupport.deepHashCode(this.validRandomFactorForceVal), 
                android.os.HidlSupport.deepHashCode(this.randomFactorForceVal), 
                android.os.HidlSupport.deepHashCode(this.validHopCountForceVal), 
                android.os.HidlSupport.deepHashCode(this.hopCountForceVal), 
                android.os.HidlSupport.deepHashCode(this.validDiscoveryChannelVal), 
                android.os.HidlSupport.deepHashCode(this.discoveryChannelMhzVal), 
                android.os.HidlSupport.deepHashCode(this.validUseBeaconsInBandVal), 
                android.os.HidlSupport.deepHashCode(this.useBeaconsInBandVal), 
                android.os.HidlSupport.deepHashCode(this.validUseSdfInBandVal), 
                android.os.HidlSupport.deepHashCode(this.useSdfInBandVal));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".validClusterIdVals = ");
        builder.append(this.validClusterIdVals);
        builder.append(", .clusterIdBottomRangeVal = ");
        builder.append(this.clusterIdBottomRangeVal);
        builder.append(", .clusterIdTopRangeVal = ");
        builder.append(this.clusterIdTopRangeVal);
        builder.append(", .validIntfAddrVal = ");
        builder.append(this.validIntfAddrVal);
        builder.append(", .intfAddrVal = ");
        builder.append(java.util.Arrays.toString(this.intfAddrVal));
        builder.append(", .validOuiVal = ");
        builder.append(this.validOuiVal);
        builder.append(", .ouiVal = ");
        builder.append(this.ouiVal);
        builder.append(", .validRandomFactorForceVal = ");
        builder.append(this.validRandomFactorForceVal);
        builder.append(", .randomFactorForceVal = ");
        builder.append(this.randomFactorForceVal);
        builder.append(", .validHopCountForceVal = ");
        builder.append(this.validHopCountForceVal);
        builder.append(", .hopCountForceVal = ");
        builder.append(this.hopCountForceVal);
        builder.append(", .validDiscoveryChannelVal = ");
        builder.append(this.validDiscoveryChannelVal);
        builder.append(", .discoveryChannelMhzVal = ");
        builder.append(java.util.Arrays.toString(this.discoveryChannelMhzVal));
        builder.append(", .validUseBeaconsInBandVal = ");
        builder.append(this.validUseBeaconsInBandVal);
        builder.append(", .useBeaconsInBandVal = ");
        builder.append(java.util.Arrays.toString(this.useBeaconsInBandVal));
        builder.append(", .validUseSdfInBandVal = ");
        builder.append(this.validUseSdfInBandVal);
        builder.append(", .useSdfInBandVal = ");
        builder.append(java.util.Arrays.toString(this.useSdfInBandVal));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDebugConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDebugConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_4.NanDebugConfig _hidl_vec_element = new android.hardware.wifi.V1_4.NanDebugConfig();
                ((android.hardware.wifi.V1_4.NanDebugConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        validClusterIdVals = _hidl_blob.getBool(_hidl_offset + 0);
        clusterIdBottomRangeVal = _hidl_blob.getInt16(_hidl_offset + 2);
        clusterIdTopRangeVal = _hidl_blob.getInt16(_hidl_offset + 4);
        validIntfAddrVal = _hidl_blob.getBool(_hidl_offset + 6);
        {
            long _hidl_array_offset_0 = _hidl_offset + 7;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) intfAddrVal, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        validOuiVal = _hidl_blob.getBool(_hidl_offset + 13);
        ouiVal = _hidl_blob.getInt32(_hidl_offset + 16);
        validRandomFactorForceVal = _hidl_blob.getBool(_hidl_offset + 20);
        randomFactorForceVal = _hidl_blob.getInt8(_hidl_offset + 21);
        validHopCountForceVal = _hidl_blob.getBool(_hidl_offset + 22);
        hopCountForceVal = _hidl_blob.getInt8(_hidl_offset + 23);
        validDiscoveryChannelVal = _hidl_blob.getBool(_hidl_offset + 24);
        {
            long _hidl_array_offset_0 = _hidl_offset + 28;
            _hidl_blob.copyToInt32Array(_hidl_array_offset_0, (int[/* 3 */]) discoveryChannelMhzVal, 3 /* size */);
            _hidl_array_offset_0 += 3 * 4;
        }
        validUseBeaconsInBandVal = _hidl_blob.getBool(_hidl_offset + 40);
        {
            long _hidl_array_offset_0 = _hidl_offset + 41;
            _hidl_blob.copyToBoolArray(_hidl_array_offset_0, (boolean[/* 3 */]) useBeaconsInBandVal, 3 /* size */);
            _hidl_array_offset_0 += 3 * 1;
        }
        validUseSdfInBandVal = _hidl_blob.getBool(_hidl_offset + 44);
        {
            long _hidl_array_offset_0 = _hidl_offset + 45;
            _hidl_blob.copyToBoolArray(_hidl_array_offset_0, (boolean[/* 3 */]) useSdfInBandVal, 3 /* size */);
            _hidl_array_offset_0 += 3 * 1;
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDebugConfig> _hidl_vec) {
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
        _hidl_blob.putBool(_hidl_offset + 0, validClusterIdVals);
        _hidl_blob.putInt16(_hidl_offset + 2, clusterIdBottomRangeVal);
        _hidl_blob.putInt16(_hidl_offset + 4, clusterIdTopRangeVal);
        _hidl_blob.putBool(_hidl_offset + 6, validIntfAddrVal);
        {
            long _hidl_array_offset_0 = _hidl_offset + 7;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) intfAddrVal;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        _hidl_blob.putBool(_hidl_offset + 13, validOuiVal);
        _hidl_blob.putInt32(_hidl_offset + 16, ouiVal);
        _hidl_blob.putBool(_hidl_offset + 20, validRandomFactorForceVal);
        _hidl_blob.putInt8(_hidl_offset + 21, randomFactorForceVal);
        _hidl_blob.putBool(_hidl_offset + 22, validHopCountForceVal);
        _hidl_blob.putInt8(_hidl_offset + 23, hopCountForceVal);
        _hidl_blob.putBool(_hidl_offset + 24, validDiscoveryChannelVal);
        {
            long _hidl_array_offset_0 = _hidl_offset + 28;
            int[] _hidl_array_item_0 = (int[/* 3 */]) discoveryChannelMhzVal;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 3) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt32Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 3 * 4;
        }
        _hidl_blob.putBool(_hidl_offset + 40, validUseBeaconsInBandVal);
        {
            long _hidl_array_offset_0 = _hidl_offset + 41;
            boolean[] _hidl_array_item_0 = (boolean[/* 3 */]) useBeaconsInBandVal;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 3) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putBoolArray(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 3 * 1;
        }
        _hidl_blob.putBool(_hidl_offset + 44, validUseSdfInBandVal);
        {
            long _hidl_array_offset_0 = _hidl_offset + 45;
            boolean[] _hidl_array_item_0 = (boolean[/* 3 */]) useSdfInBandVal;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 3) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putBoolArray(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 3 * 1;
        }
    }
};

