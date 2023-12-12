package android.hardware.wifi.V1_0;


public final class NanDiscoveryCommonConfig {
    /**
     * The ID of the discovery session being configured. A value of 0 specifies a request to create
     * a new discovery session. The new discovery session ID is returned with
     * |IWifiNanIfaceEventCallback.notifyStartPublishResponse| or
     * |IWifiNanIfaceEventCallback.notifyStartSubscribeResponse|.
     * NAN Spec: Service Descriptor Attribute (SDA) / Instance ID
     */
    public byte sessionId = 0;
    /**
     * The lifetime of the discovery session in seconds. A value of 0 means run forever or until
     * canceled using |IWifiIface.stopPublishRequest| or |IWifiIface.stopSubscribeRequest|.
     */
    public short ttlSec = 0;
    /**
     * Indicates the interval between two Discovery Windows in which the device supporting the
     * service is awake to transmit or receive the Service Discovery frames. Valid values of Awake
     * DW Interval are: 1, 2, 4, 8 and 16. A value of 0 will default to 1. Does not override
     * |NanBandSpecificConfig.discoveryWindowIntervalVal| configurations if those are specified.
     */
    public short discoveryWindowPeriod = 0;
    /**
     * The lifetime of the discovery session in number of transmitted SDF discovery packets. A value
     * of 0 means forever or until canceled using |IWifiIface.stopPublishRequest| or
     * |IWifiIface.stopSubscribeRequest|.
     */
    public byte discoveryCount = 0;
    /**
     * UTF-8 encoded string identifying the service.
     * Max length: |NanCapabilities.maxServiceNameLen|.
     * NAN Spec: The only acceptable single-byte UTF-8 symbols for a Service Name are alphanumeric
     * values (A-Z, a-z, 0-9), the hyphen ('-'), and the period ('.'). All valid multi-byte UTF-8
     * characters are acceptable in a Service Name.
     */
    public java.util.ArrayList<Byte> serviceName = new java.util.ArrayList<Byte>();
    /**
     * Specifies how often to trigger |IWifiNanIfaceEventCallback.eventMatch| when continuously
     * discovering the same discovery session (with no changes).
     */
    public int discoveryMatchIndicator = 0;
    /**
     * Arbitrary information communicated in discovery packets - there is no semantic meaning to these
     * bytes. They are passed-through from publisher to subscriber as-is with no parsing.
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
     * Ordered sequence of <length, value> pairs (|length| uses 1 byte and contains the number of
     * bytes in the |value| field) which specify further match criteria (beyond the service name).
     * The match behavior is specified in details in the NAN spec.
     * Publisher: used in SOLICITED or SOLICITED_UNSOLICITED sessions.
     * Subscriber: used in ACTIVE or PASSIVE sessions.
     * Max length: |NanCapabilities.maxMatchFilterLen|.
     * NAN Spec: matching_filter_rx
     */
    public java.util.ArrayList<Byte> rxMatchFilter = new java.util.ArrayList<Byte>();
    /**
     * Ordered sequence of <length, value> pairs (|length| uses 1 byte and contains the number of
     * bytes in the |value| field) which specify further match criteria (beyond the service name).
     * The match behavior is specified in details in the NAN spec.
     * Publisher: used if provided.
     * Subscriber: used (if provided) only in ACTIVE sessions.
     * Max length: |NanCapabilities.maxMatchFilterLen|.
     * NAN Spec: matching_filter_tx and Service Descriptor Attribute (SDA) / Matching Filter
     */
    public java.util.ArrayList<Byte> txMatchFilter = new java.util.ArrayList<Byte>();
    /**
     * Specifies whether or not the discovery session uses the
     * |NanBandSpecificConfig.rssiCloseProximity| value (configured in enable/configure requests) to
     * filter out matched discovered peers.
     * NAN Spec: Service Descriptor Attribute / Service Control / Discovery Range Limited.
     */
    public boolean useRssiThreshold = false;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventPublishTerminated| (for publish
     * discovery sessions) or |IWifiNanIfaceEventCallback.eventSubscribeTerminated| (for subscribe
     * discovery sessions) will be delivered.
     */
    public boolean disableDiscoveryTerminationIndication = false;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventMatchExpired| will be delivered.
     */
    public boolean disableMatchExpirationIndication = false;
    /**
     * Controls whether or not the |IWifiNanIfaceEventCallback.eventFollowupReceived| will be
     * delivered.
     */
    public boolean disableFollowupReceivedIndication = false;
    /**
     * Security configuration of data-paths created in the context of this discovery session. Security
     * parameters can be overridden during the actual construction of the data-path - allowing
     * individual data-paths to have unique PMKs or Passphrases.
     */
    public android.hardware.wifi.V1_0.NanDataPathSecurityConfig securityConfig = new android.hardware.wifi.V1_0.NanDataPathSecurityConfig();
    /**
     * Specifies whether or not there is a ranging requirement in this discovery session.
     * Ranging is only performed if all other match criteria with the peer are met. Ranging must
     * be performed if both peers in the discovery session (publisher and subscriber) set this
     * flag to true. Otherwise, if either peer sets this flag to false, ranging must not be performed
     * and must not impact discovery decisions.
     * Note: specifying that ranging is required also implies that this device must automatically
     * accept ranging requests from peers.
     * NAN Spec: Service Discovery Extension Attribute (SDEA) / Control / Ranging Require.
     */
    public boolean rangingRequired = false;
    /**
     * Interval in msec between two ranging measurements. Only relevant if |rangingRequired| is true.
     * If the Awake DW interval specified either in |discoveryWindowPeriod| or in
     * |NanBandSpecificConfig.discoveryWindowIntervalVal| is larger than the ranging interval then
     * priority is given to Awake DW interval.
     */
    public int rangingIntervalMsec = 0;
    /**
     * The type of ranging feedback to be provided by discovery session matches
     * |IWifiNanIfaceEventCallback.eventMatch|. Only relevant if |rangingRequired| is true.
     */
    public int configRangingIndications;
    /**
     * The ingress and egress distance in cm. If ranging is enabled (|rangingEnabled| is true) then
     * |configRangingIndications| is used to determine whether ingress and/or egress (or neither)
     * are used to determine whether a match has occurred.
     * NAN Spec: Service Discovery Extension Attribute (SDEA) / Ingress & Egress Range Limit
     */
    public short distanceIngressCm = 0;
    public short distanceEgressCm = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanDiscoveryCommonConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanDiscoveryCommonConfig other = (android.hardware.wifi.V1_0.NanDiscoveryCommonConfig)otherObject;
        if (this.sessionId != other.sessionId) {
            return false;
        }
        if (this.ttlSec != other.ttlSec) {
            return false;
        }
        if (this.discoveryWindowPeriod != other.discoveryWindowPeriod) {
            return false;
        }
        if (this.discoveryCount != other.discoveryCount) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serviceName, other.serviceName)) {
            return false;
        }
        if (this.discoveryMatchIndicator != other.discoveryMatchIndicator) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serviceSpecificInfo, other.serviceSpecificInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.extendedServiceSpecificInfo, other.extendedServiceSpecificInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rxMatchFilter, other.rxMatchFilter)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.txMatchFilter, other.txMatchFilter)) {
            return false;
        }
        if (this.useRssiThreshold != other.useRssiThreshold) {
            return false;
        }
        if (this.disableDiscoveryTerminationIndication != other.disableDiscoveryTerminationIndication) {
            return false;
        }
        if (this.disableMatchExpirationIndication != other.disableMatchExpirationIndication) {
            return false;
        }
        if (this.disableFollowupReceivedIndication != other.disableFollowupReceivedIndication) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.securityConfig, other.securityConfig)) {
            return false;
        }
        if (this.rangingRequired != other.rangingRequired) {
            return false;
        }
        if (this.rangingIntervalMsec != other.rangingIntervalMsec) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.configRangingIndications, other.configRangingIndications)) {
            return false;
        }
        if (this.distanceIngressCm != other.distanceIngressCm) {
            return false;
        }
        if (this.distanceEgressCm != other.distanceEgressCm) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sessionId), 
                android.os.HidlSupport.deepHashCode(this.ttlSec), 
                android.os.HidlSupport.deepHashCode(this.discoveryWindowPeriod), 
                android.os.HidlSupport.deepHashCode(this.discoveryCount), 
                android.os.HidlSupport.deepHashCode(this.serviceName), 
                android.os.HidlSupport.deepHashCode(this.discoveryMatchIndicator), 
                android.os.HidlSupport.deepHashCode(this.serviceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.extendedServiceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.rxMatchFilter), 
                android.os.HidlSupport.deepHashCode(this.txMatchFilter), 
                android.os.HidlSupport.deepHashCode(this.useRssiThreshold), 
                android.os.HidlSupport.deepHashCode(this.disableDiscoveryTerminationIndication), 
                android.os.HidlSupport.deepHashCode(this.disableMatchExpirationIndication), 
                android.os.HidlSupport.deepHashCode(this.disableFollowupReceivedIndication), 
                android.os.HidlSupport.deepHashCode(this.securityConfig), 
                android.os.HidlSupport.deepHashCode(this.rangingRequired), 
                android.os.HidlSupport.deepHashCode(this.rangingIntervalMsec), 
                android.os.HidlSupport.deepHashCode(this.configRangingIndications), 
                android.os.HidlSupport.deepHashCode(this.distanceIngressCm), 
                android.os.HidlSupport.deepHashCode(this.distanceEgressCm));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sessionId = ");
        builder.append(this.sessionId);
        builder.append(", .ttlSec = ");
        builder.append(this.ttlSec);
        builder.append(", .discoveryWindowPeriod = ");
        builder.append(this.discoveryWindowPeriod);
        builder.append(", .discoveryCount = ");
        builder.append(this.discoveryCount);
        builder.append(", .serviceName = ");
        builder.append(this.serviceName);
        builder.append(", .discoveryMatchIndicator = ");
        builder.append(android.hardware.wifi.V1_0.NanMatchAlg.toString(this.discoveryMatchIndicator));
        builder.append(", .serviceSpecificInfo = ");
        builder.append(this.serviceSpecificInfo);
        builder.append(", .extendedServiceSpecificInfo = ");
        builder.append(this.extendedServiceSpecificInfo);
        builder.append(", .rxMatchFilter = ");
        builder.append(this.rxMatchFilter);
        builder.append(", .txMatchFilter = ");
        builder.append(this.txMatchFilter);
        builder.append(", .useRssiThreshold = ");
        builder.append(this.useRssiThreshold);
        builder.append(", .disableDiscoveryTerminationIndication = ");
        builder.append(this.disableDiscoveryTerminationIndication);
        builder.append(", .disableMatchExpirationIndication = ");
        builder.append(this.disableMatchExpirationIndication);
        builder.append(", .disableFollowupReceivedIndication = ");
        builder.append(this.disableFollowupReceivedIndication);
        builder.append(", .securityConfig = ");
        builder.append(this.securityConfig);
        builder.append(", .rangingRequired = ");
        builder.append(this.rangingRequired);
        builder.append(", .rangingIntervalMsec = ");
        builder.append(this.rangingIntervalMsec);
        builder.append(", .configRangingIndications = ");
        builder.append(android.hardware.wifi.V1_0.NanRangingIndication.dumpBitfield(this.configRangingIndications));
        builder.append(", .distanceIngressCm = ");
        builder.append(this.distanceIngressCm);
        builder.append(", .distanceEgressCm = ");
        builder.append(this.distanceEgressCm);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(176 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDiscoveryCommonConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDiscoveryCommonConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 176,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanDiscoveryCommonConfig _hidl_vec_element = new android.hardware.wifi.V1_0.NanDiscoveryCommonConfig();
                ((android.hardware.wifi.V1_0.NanDiscoveryCommonConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 176);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sessionId = _hidl_blob.getInt8(_hidl_offset + 0);
        ttlSec = _hidl_blob.getInt16(_hidl_offset + 2);
        discoveryWindowPeriod = _hidl_blob.getInt16(_hidl_offset + 4);
        discoveryCount = _hidl_blob.getInt8(_hidl_offset + 6);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) serviceName).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) serviceName).add(_hidl_vec_element);
            }
        }
        discoveryMatchIndicator = _hidl_blob.getInt32(_hidl_offset + 24);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) serviceSpecificInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) serviceSpecificInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) extendedServiceSpecificInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) extendedServiceSpecificInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) rxMatchFilter).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) rxMatchFilter).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) txMatchFilter).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) txMatchFilter).add(_hidl_vec_element);
            }
        }
        useRssiThreshold = _hidl_blob.getBool(_hidl_offset + 96);
        disableDiscoveryTerminationIndication = _hidl_blob.getBool(_hidl_offset + 97);
        disableMatchExpirationIndication = _hidl_blob.getBool(_hidl_offset + 98);
        disableFollowupReceivedIndication = _hidl_blob.getBool(_hidl_offset + 99);
        ((android.hardware.wifi.V1_0.NanDataPathSecurityConfig) securityConfig).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 104);
        rangingRequired = _hidl_blob.getBool(_hidl_offset + 160);
        rangingIntervalMsec = _hidl_blob.getInt32(_hidl_offset + 164);
        configRangingIndications = _hidl_blob.getInt32(_hidl_offset + 168);
        distanceIngressCm = _hidl_blob.getInt16(_hidl_offset + 172);
        distanceEgressCm = _hidl_blob.getInt16(_hidl_offset + 174);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(176 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDiscoveryCommonConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 176));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 176);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, sessionId);
        _hidl_blob.putInt16(_hidl_offset + 2, ttlSec);
        _hidl_blob.putInt16(_hidl_offset + 4, discoveryWindowPeriod);
        _hidl_blob.putInt8(_hidl_offset + 6, discoveryCount);
        {
            int _hidl_vec_size = serviceName.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, serviceName.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, discoveryMatchIndicator);
        {
            int _hidl_vec_size = serviceSpecificInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, serviceSpecificInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = extendedServiceSpecificInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, extendedServiceSpecificInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = rxMatchFilter.size();
            _hidl_blob.putInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 64 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, rxMatchFilter.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = txMatchFilter.size();
            _hidl_blob.putInt32(_hidl_offset + 80 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 80 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, txMatchFilter.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 80 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putBool(_hidl_offset + 96, useRssiThreshold);
        _hidl_blob.putBool(_hidl_offset + 97, disableDiscoveryTerminationIndication);
        _hidl_blob.putBool(_hidl_offset + 98, disableMatchExpirationIndication);
        _hidl_blob.putBool(_hidl_offset + 99, disableFollowupReceivedIndication);
        securityConfig.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 104);
        _hidl_blob.putBool(_hidl_offset + 160, rangingRequired);
        _hidl_blob.putInt32(_hidl_offset + 164, rangingIntervalMsec);
        _hidl_blob.putInt32(_hidl_offset + 168, configRangingIndications);
        _hidl_blob.putInt16(_hidl_offset + 172, distanceIngressCm);
        _hidl_blob.putInt16(_hidl_offset + 174, distanceEgressCm);
    }
};

