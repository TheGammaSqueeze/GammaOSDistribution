package android.hardware.wifi.V1_0;


public final class NanTransmitFollowupRequest {
    /**
     * ID of an active publish or subscribe discovery session. Follow-up message is transmitted in the
     * context of the discovery session.
     * NAN Spec: Service Descriptor Attribute (SDA) / Instance ID
     */
    public byte discoverySessionId = 0;
    /**
     * ID of the peer. Obtained as part of an earlier |IWifiNanIfaceEventCallback.eventMatch| or
     * |IWifiNanIfaceEventCallback.eventFollowupReceived|.
     */
    public int peerId = 0;
    /**
     * MAC address of the peer. Obtained as part of an earlier |IWifiNanIfaceEventCallback.eventMatch|
     * or |IWifiNanIfaceEventCallback.eventFollowupReceived|.
     */
    public byte[/* 6 */] addr = new byte[6];
    /**
     * Should the follow-up message be transmitted with a high priority.
     */
    public boolean isHighPriority = false;
    /**
     * Should the follow-up message be transmitted in a discovery window (true) or a further
     * availability window (false).
     */
    public boolean shouldUseDiscoveryWindow = false;
    /**
     * Arbitrary information communicated to the peer - there is no semantic meaning to these
     * bytes. They are passed-through from sender to receiver as-is with no parsing.
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
     * Disable |IWifiNanIfaceEventCallback.eventTransmitFollowup| - i.e. do not get indication on
     * whether the follow-up was transmitted and received successfully.
     */
    public boolean disableFollowupResultIndication = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanTransmitFollowupRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanTransmitFollowupRequest other = (android.hardware.wifi.V1_0.NanTransmitFollowupRequest)otherObject;
        if (this.discoverySessionId != other.discoverySessionId) {
            return false;
        }
        if (this.peerId != other.peerId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.addr, other.addr)) {
            return false;
        }
        if (this.isHighPriority != other.isHighPriority) {
            return false;
        }
        if (this.shouldUseDiscoveryWindow != other.shouldUseDiscoveryWindow) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.serviceSpecificInfo, other.serviceSpecificInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.extendedServiceSpecificInfo, other.extendedServiceSpecificInfo)) {
            return false;
        }
        if (this.disableFollowupResultIndication != other.disableFollowupResultIndication) {
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
                android.os.HidlSupport.deepHashCode(this.isHighPriority), 
                android.os.HidlSupport.deepHashCode(this.shouldUseDiscoveryWindow), 
                android.os.HidlSupport.deepHashCode(this.serviceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.extendedServiceSpecificInfo), 
                android.os.HidlSupport.deepHashCode(this.disableFollowupResultIndication));
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
        builder.append(", .isHighPriority = ");
        builder.append(this.isHighPriority);
        builder.append(", .shouldUseDiscoveryWindow = ");
        builder.append(this.shouldUseDiscoveryWindow);
        builder.append(", .serviceSpecificInfo = ");
        builder.append(this.serviceSpecificInfo);
        builder.append(", .extendedServiceSpecificInfo = ");
        builder.append(this.extendedServiceSpecificInfo);
        builder.append(", .disableFollowupResultIndication = ");
        builder.append(this.disableFollowupResultIndication);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanTransmitFollowupRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanTransmitFollowupRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanTransmitFollowupRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanTransmitFollowupRequest();
                ((android.hardware.wifi.V1_0.NanTransmitFollowupRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
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
        isHighPriority = _hidl_blob.getBool(_hidl_offset + 14);
        shouldUseDiscoveryWindow = _hidl_blob.getBool(_hidl_offset + 15);
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
        disableFollowupResultIndication = _hidl_blob.getBool(_hidl_offset + 48);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanTransmitFollowupRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
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
        _hidl_blob.putBool(_hidl_offset + 14, isHighPriority);
        _hidl_blob.putBool(_hidl_offset + 15, shouldUseDiscoveryWindow);
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
        _hidl_blob.putBool(_hidl_offset + 48, disableFollowupResultIndication);
    }
};

