package android.hardware.wifi.V1_0;


public final class NanMatchInd {
    /**
     * Publish or subscribe discovery session ID of an existing discovery session.
     * NAN Spec: Service Descriptor Attribute (SDA) / Instance ID
     */
    public byte discoverySessionId = 0;
    /**
     * A unique ID of the peer. Can be subsequently used in |IWifiNanIface.transmitFollowupRequest| or
     * to set up a data-path.
     */
    public int peerId = 0;
    /**
     * The NAN Discovery (management) MAC address of the peer.
     */
    public byte[/* 6 */] addr = new byte[6];
    /**
     * The arbitrary information contained in the |NanDiscoveryCommonConfig.serviceSpecificInfo| of
     * the peer's discovery session configuration.
     * Max length: |NanCapabilities.maxServiceSpecificInfoLen|.
     * NAN Spec: Service Descriptor Attribute (SDA) / Service Info
     */
    public java.util.ArrayList<Byte> serviceSpecificInfo = new java.util.ArrayList<Byte>();
    /**
     * Arbitrary information communicated in discovery packets - there is no semantic meaning to these
     * bytes. They are passed-through from publisher to subscriber as-is with no parsing.
     * Max length: |NanCapabilities.maxExtendedServiceSpecificInfoLen|.
     * Spec: Service Descriptor Extension Attribute (SDEA) / Service Info
     */
    public java.util.ArrayList<Byte> extendedServiceSpecificInfo = new java.util.ArrayList<Byte>();
    /**
     * The match filter from the discovery packet (publish or subscribe) which caused service
     * discovery. Matches the |NanDiscoveryCommonConfig.txMatchFilter| of the peer's Unsolicited
     * publish message or of the local device's Active subscribe message.
     * Max length: |NanCapabilities.maxMatchFilterLen|.
     * NAN Spec: Service Descriptor Attribute (SDA) / Matching Filter
     */
    public java.util.ArrayList<Byte> matchFilter = new java.util.ArrayList<Byte>();
    /**
     * Indicates the type of discovery: true if match occurred on a Beacon frame, false if the match
     * occurred on a Service Discovery Frames (SDF).
     */
    public boolean matchOccuredInBeaconFlag = false;
    /**
     * Flag to indicate firmware is out of resource and that it can no longer track this Service Name.
     * Indicates that while |IWifiNanIfaceEventCallback.eventMatch| will be received, the
     * |NanDiscoveryCommonConfig.discoveryMatchIndicator| configuration will not be honored.
     */
    public boolean outOfResourceFlag = false;
    /**
     * If RSSI filtering was enabled using |NanDiscoveryCommonConfig.useRssiThreshold| in discovery
     * session setup then this field contains the received RSSI value. It will contain 0 if RSSI
     * filtering was not enabled.
     * RSSI values are returned without sign, e.g. -70dBm will be returned as 70.
     */
    public byte rssiValue = 0;
    /**
     * Cipher type for data-paths constructed in the context of this discovery session. Valid if
     * |peerRequiresSecurityEnabledInNdp| is true.
     */
    public int peerCipherType = 0;
    /**
     * Indicates whether or not the peer requires security enabled in any data-path (NDP) constructed
     * in the context of this discovery session. The |cipherType| specifies the cipher type for such
     * data-paths.
     * NAN Spec: Service Discovery Extension Attribute (SDEA) / Control / Security Required
     */
    public boolean peerRequiresSecurityEnabledInNdp = false;
    /**
     * Indicates whether or not the peer requires (and hence allows) ranging in the context of this
     * discovery session.
     * Note that ranging is only performed if all other match criteria with the peer are met.
     * NAN Spec: Service Discovery Extension Attribute (SDEA) / Control / Ranging Require.
     */
    public boolean peerRequiresRanging = false;
    /**
     * Ranging indication supersedes the NanMatchAlg specification.
     * Ex: If NanMatchAlg is MATCH_ONCE, but ranging indications is continuous then continuous
     * match notifications will be received (with ranging information).
     * Ranging indication data is provided if Ranging required is enabled in the discovery
     * specification and:
     *   1) continuous ranging specified.
     *   2) ingress/egress specified and:
     *       - notify once for ingress >= ingress_distance and egress <= egress_distance,
     *       - same for ingress_egress_both
     * If the Awake DW intervals are larger than the ranging intervals then priority is given to the
     * device DW intervals.
     *
     * If ranging was required and executed contains the distance to the peer in CM. The
     * |rangingIndicationType| field specifies the event which triggered ranging.
     */
    public int rangingMeasurementInCm = 0;
    /**
     * The ranging event(s) which triggered the ranging. E.g. can indicate that continuous ranging was
     * requested, or else that an ingress event occurred.
     */
    public int rangingIndicationType;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanMatchInd.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanMatchInd other = (android.hardware.wifi.V1_0.NanMatchInd)otherObject;
        if (this.discoverySessionId != other.discoverySessionId) {
            return false;
        }
        if (this.peerId != other.peerId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.addr, other.addr)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serviceSpecificInfo, other.serviceSpecificInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.extendedServiceSpecificInfo, other.extendedServiceSpecificInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.matchFilter, other.matchFilter)) {
            return false;
        }
        if (this.matchOccuredInBeaconFlag != other.matchOccuredInBeaconFlag) {
            return false;
        }
        if (this.outOfResourceFlag != other.outOfResourceFlag) {
            return false;
        }
        if (this.rssiValue != other.rssiValue) {
            return false;
        }
        if (this.peerCipherType != other.peerCipherType) {
            return false;
        }
        if (this.peerRequiresSecurityEnabledInNdp != other.peerRequiresSecurityEnabledInNdp) {
            return false;
        }
        if (this.peerRequiresRanging != other.peerRequiresRanging) {
            return false;
        }
        if (this.rangingMeasurementInCm != other.rangingMeasurementInCm) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rangingIndicationType, other.rangingIndicationType)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.discoverySessionId), 
                android.os.HidlSupport.deepHashCode(this.peerId), 
                android.os.HidlSupport.deepHashCode(this.addr), 
                android.os.HidlSupport.deepHashCode(this.serviceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.extendedServiceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.matchFilter), 
                android.os.HidlSupport.deepHashCode(this.matchOccuredInBeaconFlag), 
                android.os.HidlSupport.deepHashCode(this.outOfResourceFlag), 
                android.os.HidlSupport.deepHashCode(this.rssiValue), 
                android.os.HidlSupport.deepHashCode(this.peerCipherType), 
                android.os.HidlSupport.deepHashCode(this.peerRequiresSecurityEnabledInNdp), 
                android.os.HidlSupport.deepHashCode(this.peerRequiresRanging), 
                android.os.HidlSupport.deepHashCode(this.rangingMeasurementInCm), 
                android.os.HidlSupport.deepHashCode(this.rangingIndicationType));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".discoverySessionId = ");
        builder.append(this.discoverySessionId);
        builder.append(", .peerId = ");
        builder.append(this.peerId);
        builder.append(", .addr = ");
        builder.append(java.util.Arrays.toString(this.addr));
        builder.append(", .serviceSpecificInfo = ");
        builder.append(this.serviceSpecificInfo);
        builder.append(", .extendedServiceSpecificInfo = ");
        builder.append(this.extendedServiceSpecificInfo);
        builder.append(", .matchFilter = ");
        builder.append(this.matchFilter);
        builder.append(", .matchOccuredInBeaconFlag = ");
        builder.append(this.matchOccuredInBeaconFlag);
        builder.append(", .outOfResourceFlag = ");
        builder.append(this.outOfResourceFlag);
        builder.append(", .rssiValue = ");
        builder.append(this.rssiValue);
        builder.append(", .peerCipherType = ");
        builder.append(android.hardware.wifi.V1_0.NanCipherSuiteType.toString(this.peerCipherType));
        builder.append(", .peerRequiresSecurityEnabledInNdp = ");
        builder.append(this.peerRequiresSecurityEnabledInNdp);
        builder.append(", .peerRequiresRanging = ");
        builder.append(this.peerRequiresRanging);
        builder.append(", .rangingMeasurementInCm = ");
        builder.append(this.rangingMeasurementInCm);
        builder.append(", .rangingIndicationType = ");
        builder.append(android.hardware.wifi.V1_0.NanRangingIndication.dumpBitfield(this.rangingIndicationType));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanMatchInd> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanMatchInd> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanMatchInd _hidl_vec_element = new android.hardware.wifi.V1_0.NanMatchInd();
                ((android.hardware.wifi.V1_0.NanMatchInd) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        discoverySessionId = _hidl_blob.getInt8(_hidl_offset + 0);
        peerId = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) addr, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) serviceSpecificInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) serviceSpecificInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) extendedServiceSpecificInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) extendedServiceSpecificInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) matchFilter).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) matchFilter).add(_hidl_vec_element);
            }
        }
        matchOccuredInBeaconFlag = _hidl_blob.getBool(_hidl_offset + 64);
        outOfResourceFlag = _hidl_blob.getBool(_hidl_offset + 65);
        rssiValue = _hidl_blob.getInt8(_hidl_offset + 66);
        peerCipherType = _hidl_blob.getInt32(_hidl_offset + 68);
        peerRequiresSecurityEnabledInNdp = _hidl_blob.getBool(_hidl_offset + 72);
        peerRequiresRanging = _hidl_blob.getBool(_hidl_offset + 73);
        rangingMeasurementInCm = _hidl_blob.getInt32(_hidl_offset + 76);
        rangingIndicationType = _hidl_blob.getInt32(_hidl_offset + 80);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanMatchInd> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, discoverySessionId);
        _hidl_blob.putInt32(_hidl_offset + 4, peerId);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) addr;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = serviceSpecificInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, serviceSpecificInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = extendedServiceSpecificInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, extendedServiceSpecificInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = matchFilter.size();
            _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, matchFilter.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putBool(_hidl_offset + 64, matchOccuredInBeaconFlag);
        _hidl_blob.putBool(_hidl_offset + 65, outOfResourceFlag);
        _hidl_blob.putInt8(_hidl_offset + 66, rssiValue);
        _hidl_blob.putInt32(_hidl_offset + 68, peerCipherType);
        _hidl_blob.putBool(_hidl_offset + 72, peerRequiresSecurityEnabledInNdp);
        _hidl_blob.putBool(_hidl_offset + 73, peerRequiresRanging);
        _hidl_blob.putInt32(_hidl_offset + 76, rangingMeasurementInCm);
        _hidl_blob.putInt32(_hidl_offset + 80, rangingIndicationType);
    }
};

