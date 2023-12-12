package android.hardware.wifi.V1_0;


public final class NanConfigRequest {
    /**
     * Master preference of this device.
     * NAN Spec: Master Indication Attribute / Master Preference
     */
    public byte masterPref = 0;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventClusterEvent| will be delivered
     * for |NanClusterEventType.DISCOVERY_MAC_ADDRESS_CHANGED|.
     */
    public boolean disableDiscoveryAddressChangeIndication = false;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventClusterEvent| will be delivered
     * for |NanClusterEventType.STARTED_CLUSTER|.
     */
    public boolean disableStartedClusterIndication = false;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventClusterEvent| will be delivered
     * for |NanClusterEventType.JOINED_CLUSTER|.
     */
    public boolean disableJoinedClusterIndication = false;
    /**
     * Control whether publish service IDs are included in Sync/Discovery beacons.
     * NAN Spec: Service ID List Attribute
     */
    public boolean includePublishServiceIdsInBeacon = false;
    /**
     * If |includePublishServiceIdsInBeacon| is true then specifies the number of publish service IDs
     * to include in the Sync/Discovery beacons:
     *  Value = 0: include as many service IDs as will fit into the maximum allowed beacon frame size.
     *  Value must fit within 7 bits - i.e. <= 127.
     */
    public byte numberOfPublishServiceIdsInBeacon = 0;
    /**
     * Control whether subscribe service IDs are included in Sync/Discovery beacons.
     * Spec: Subscribe Service ID List Attribute
     */
    public boolean includeSubscribeServiceIdsInBeacon = false;
    /**
     * If |includeSubscribeServiceIdsInBeacon| is true then specifies the number of subscribe service
     * IDs to include in the Sync/Discovery beacons:
     *  Value = 0: include as many service IDs as will fit into the maximum allowed beacon frame size.
     *  Value must fit within 7 bits - i.e. <= 127.
     */
    public byte numberOfSubscribeServiceIdsInBeacon = 0;
    /**
     * Number of samples used to calculate RSSI.
     */
    public short rssiWindowSize = 0;
    /**
     * Specifies the interval in seconds that the NAN management interface MAC address is randomized.
     * A value of 0 is used to disable the MAC address randomization
     */
    public int macAddressRandomizationIntervalSec = 0;
    /**
     * Additional configuration provided per band: indexed by |NanBandIndex|.
     */
    public android.hardware.wifi.V1_0.NanBandSpecificConfig[/* 2 */] bandSpecificConfig = new android.hardware.wifi.V1_0.NanBandSpecificConfig[2];

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanConfigRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanConfigRequest other = (android.hardware.wifi.V1_0.NanConfigRequest)otherObject;
        if (this.masterPref != other.masterPref) {
            return false;
        }
        if (this.disableDiscoveryAddressChangeIndication != other.disableDiscoveryAddressChangeIndication) {
            return false;
        }
        if (this.disableStartedClusterIndication != other.disableStartedClusterIndication) {
            return false;
        }
        if (this.disableJoinedClusterIndication != other.disableJoinedClusterIndication) {
            return false;
        }
        if (this.includePublishServiceIdsInBeacon != other.includePublishServiceIdsInBeacon) {
            return false;
        }
        if (this.numberOfPublishServiceIdsInBeacon != other.numberOfPublishServiceIdsInBeacon) {
            return false;
        }
        if (this.includeSubscribeServiceIdsInBeacon != other.includeSubscribeServiceIdsInBeacon) {
            return false;
        }
        if (this.numberOfSubscribeServiceIdsInBeacon != other.numberOfSubscribeServiceIdsInBeacon) {
            return false;
        }
        if (this.rssiWindowSize != other.rssiWindowSize) {
            return false;
        }
        if (this.macAddressRandomizationIntervalSec != other.macAddressRandomizationIntervalSec) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bandSpecificConfig, other.bandSpecificConfig)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.masterPref), 
                android.os.HidlSupport.deepHashCode(this.disableDiscoveryAddressChangeIndication), 
                android.os.HidlSupport.deepHashCode(this.disableStartedClusterIndication), 
                android.os.HidlSupport.deepHashCode(this.disableJoinedClusterIndication), 
                android.os.HidlSupport.deepHashCode(this.includePublishServiceIdsInBeacon), 
                android.os.HidlSupport.deepHashCode(this.numberOfPublishServiceIdsInBeacon), 
                android.os.HidlSupport.deepHashCode(this.includeSubscribeServiceIdsInBeacon), 
                android.os.HidlSupport.deepHashCode(this.numberOfSubscribeServiceIdsInBeacon), 
                android.os.HidlSupport.deepHashCode(this.rssiWindowSize), 
                android.os.HidlSupport.deepHashCode(this.macAddressRandomizationIntervalSec), 
                android.os.HidlSupport.deepHashCode(this.bandSpecificConfig));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".masterPref = ");
        builder.append(this.masterPref);
        builder.append(", .disableDiscoveryAddressChangeIndication = ");
        builder.append(this.disableDiscoveryAddressChangeIndication);
        builder.append(", .disableStartedClusterIndication = ");
        builder.append(this.disableStartedClusterIndication);
        builder.append(", .disableJoinedClusterIndication = ");
        builder.append(this.disableJoinedClusterIndication);
        builder.append(", .includePublishServiceIdsInBeacon = ");
        builder.append(this.includePublishServiceIdsInBeacon);
        builder.append(", .numberOfPublishServiceIdsInBeacon = ");
        builder.append(this.numberOfPublishServiceIdsInBeacon);
        builder.append(", .includeSubscribeServiceIdsInBeacon = ");
        builder.append(this.includeSubscribeServiceIdsInBeacon);
        builder.append(", .numberOfSubscribeServiceIdsInBeacon = ");
        builder.append(this.numberOfSubscribeServiceIdsInBeacon);
        builder.append(", .rssiWindowSize = ");
        builder.append(this.rssiWindowSize);
        builder.append(", .macAddressRandomizationIntervalSec = ");
        builder.append(this.macAddressRandomizationIntervalSec);
        builder.append(", .bandSpecificConfig = ");
        builder.append(java.util.Arrays.toString(this.bandSpecificConfig));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanConfigRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanConfigRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanConfigRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanConfigRequest();
                ((android.hardware.wifi.V1_0.NanConfigRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        masterPref = _hidl_blob.getInt8(_hidl_offset + 0);
        disableDiscoveryAddressChangeIndication = _hidl_blob.getBool(_hidl_offset + 1);
        disableStartedClusterIndication = _hidl_blob.getBool(_hidl_offset + 2);
        disableJoinedClusterIndication = _hidl_blob.getBool(_hidl_offset + 3);
        includePublishServiceIdsInBeacon = _hidl_blob.getBool(_hidl_offset + 4);
        numberOfPublishServiceIdsInBeacon = _hidl_blob.getInt8(_hidl_offset + 5);
        includeSubscribeServiceIdsInBeacon = _hidl_blob.getBool(_hidl_offset + 6);
        numberOfSubscribeServiceIdsInBeacon = _hidl_blob.getInt8(_hidl_offset + 7);
        rssiWindowSize = _hidl_blob.getInt16(_hidl_offset + 8);
        macAddressRandomizationIntervalSec = _hidl_blob.getInt32(_hidl_offset + 12);
        {
            long _hidl_array_offset_0 = _hidl_offset + 16;
            for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 2; ++_hidl_index_0_0) {
                ((android.hardware.wifi.V1_0.NanBandSpecificConfig[/* 2 */]) bandSpecificConfig)[_hidl_index_0_0] = new android.hardware.wifi.V1_0.NanBandSpecificConfig();
                ((android.hardware.wifi.V1_0.NanBandSpecificConfig) ((android.hardware.wifi.V1_0.NanBandSpecificConfig[/* 2 */]) bandSpecificConfig)[_hidl_index_0_0]).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_array_offset_0);
                _hidl_array_offset_0 += 8;
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanConfigRequest> _hidl_vec) {
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
        _hidl_blob.putInt8(_hidl_offset + 0, masterPref);
        _hidl_blob.putBool(_hidl_offset + 1, disableDiscoveryAddressChangeIndication);
        _hidl_blob.putBool(_hidl_offset + 2, disableStartedClusterIndication);
        _hidl_blob.putBool(_hidl_offset + 3, disableJoinedClusterIndication);
        _hidl_blob.putBool(_hidl_offset + 4, includePublishServiceIdsInBeacon);
        _hidl_blob.putInt8(_hidl_offset + 5, numberOfPublishServiceIdsInBeacon);
        _hidl_blob.putBool(_hidl_offset + 6, includeSubscribeServiceIdsInBeacon);
        _hidl_blob.putInt8(_hidl_offset + 7, numberOfSubscribeServiceIdsInBeacon);
        _hidl_blob.putInt16(_hidl_offset + 8, rssiWindowSize);
        _hidl_blob.putInt32(_hidl_offset + 12, macAddressRandomizationIntervalSec);
        {
            long _hidl_array_offset_0 = _hidl_offset + 16;
            for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 2; ++_hidl_index_0_0) {
                ((android.hardware.wifi.V1_0.NanBandSpecificConfig[/* 2 */]) bandSpecificConfig)[_hidl_index_0_0].writeEmbeddedToBlob(_hidl_blob, _hidl_array_offset_0);
                _hidl_array_offset_0 += 8;
            }
        }
    }
};

