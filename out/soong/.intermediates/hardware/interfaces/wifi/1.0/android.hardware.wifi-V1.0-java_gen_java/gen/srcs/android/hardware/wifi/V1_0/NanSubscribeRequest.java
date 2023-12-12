package android.hardware.wifi.V1_0;


public final class NanSubscribeRequest {
    /**
     * Common configuration of discovery sessions.
     */
    public android.hardware.wifi.V1_0.NanDiscoveryCommonConfig baseConfigs = new android.hardware.wifi.V1_0.NanDiscoveryCommonConfig();
    /**
     * The type of the subscribe discovery session.
     */
    public int subscribeType = 0;
    /**
     * For |NanSubscribeType.ACTIVE| subscribe discovery sessions specify how the Service Response
     * Filter (SRF) attribute is populated. Relevant only if |shouldUseSrf| is set to true.
     * NAN Spec: Service Descriptor Attribute (SDA) / Service Response Filter / SRF Control / SRF Type
     */
    public int srfType = 0;
    /**
     * Configure whether inclusion of an address in |intfAddr| indicates that those devices should
     * respond or the reverse. Relevant only if |shouldUseSrf| is set to true and |srfType| is set to
     * |NanSrfType.PARTIAL_MAC_ADDR|.
     * NAN Spec: Service Descriptor Attribute (SDA) / Service Response Filter / SRF Control / Include
     */
    public boolean srfRespondIfInAddressSet = false;
    /**
     * Control whether the Service Response Filter (SRF) is used.
     * NAN Spec: Service Descriptor Attribute (SDA) / Service Control /
     *           Service Response Filter Present
     */
    public boolean shouldUseSrf = false;
    /**
     * Control whether the presence of |NanDiscoveryCommonConfig.serviceSpecificInfo| data is needed
     * in the publisher in order to trigger service discovery, i.e. a
     * |IWifiNanIfaceEventCallback.eventMatch|. The test is for presence of data - not for the
     * specific contents of the data.
     */
    public boolean isSsiRequiredForMatch = false;
    /**
     * NAN Interface Addresses constituting the Service Response Filter (SRF).
     * Max length (number of addresses): |NanCapabilities.maxSubscribeInterfaceAddresses|.
     * NAN Spec: Service Descriptor Attribute (SDA) / Service Response Filter / Address Set
     */
    public java.util.ArrayList<byte[/* 6 */]> intfAddr = new java.util.ArrayList<byte[/* 6 */]>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanSubscribeRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanSubscribeRequest other = (android.hardware.wifi.V1_0.NanSubscribeRequest)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.baseConfigs, other.baseConfigs)) {
            return false;
        }
        if (this.subscribeType != other.subscribeType) {
            return false;
        }
        if (this.srfType != other.srfType) {
            return false;
        }
        if (this.srfRespondIfInAddressSet != other.srfRespondIfInAddressSet) {
            return false;
        }
        if (this.shouldUseSrf != other.shouldUseSrf) {
            return false;
        }
        if (this.isSsiRequiredForMatch != other.isSsiRequiredForMatch) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.intfAddr, other.intfAddr)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.baseConfigs), 
                android.os.HidlSupport.deepHashCode(this.subscribeType), 
                android.os.HidlSupport.deepHashCode(this.srfType), 
                android.os.HidlSupport.deepHashCode(this.srfRespondIfInAddressSet), 
                android.os.HidlSupport.deepHashCode(this.shouldUseSrf), 
                android.os.HidlSupport.deepHashCode(this.isSsiRequiredForMatch), 
                android.os.HidlSupport.deepHashCode(this.intfAddr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".baseConfigs = ");
        builder.append(this.baseConfigs);
        builder.append(", .subscribeType = ");
        builder.append(android.hardware.wifi.V1_0.NanSubscribeType.toString(this.subscribeType));
        builder.append(", .srfType = ");
        builder.append(android.hardware.wifi.V1_0.NanSrfType.toString(this.srfType));
        builder.append(", .srfRespondIfInAddressSet = ");
        builder.append(this.srfRespondIfInAddressSet);
        builder.append(", .shouldUseSrf = ");
        builder.append(this.shouldUseSrf);
        builder.append(", .isSsiRequiredForMatch = ");
        builder.append(this.isSsiRequiredForMatch);
        builder.append(", .intfAddr = ");
        builder.append(this.intfAddr);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(208 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanSubscribeRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanSubscribeRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 208,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanSubscribeRequest _hidl_vec_element = new android.hardware.wifi.V1_0.NanSubscribeRequest();
                ((android.hardware.wifi.V1_0.NanSubscribeRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 208);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.wifi.V1_0.NanDiscoveryCommonConfig) baseConfigs).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        subscribeType = _hidl_blob.getInt32(_hidl_offset + 176);
        srfType = _hidl_blob.getInt32(_hidl_offset + 180);
        srfRespondIfInAddressSet = _hidl_blob.getBool(_hidl_offset + 184);
        shouldUseSrf = _hidl_blob.getBool(_hidl_offset + 185);
        isSsiRequiredForMatch = _hidl_blob.getBool(_hidl_offset + 186);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 192 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 6,_hidl_blob.handle(),
                    _hidl_offset + 192 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<byte[/* 6 */]>) intfAddr).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte[/* 6 */] _hidl_vec_element = new byte[6];
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 6;
                    childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 6 */]) _hidl_vec_element, 6 /* size */);
                    _hidl_array_offset_1 += 6 * 1;
                }
                ((java.util.ArrayList<byte[/* 6 */]>) intfAddr).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(208 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanSubscribeRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 208));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 208);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        baseConfigs.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 176, subscribeType);
        _hidl_blob.putInt32(_hidl_offset + 180, srfType);
        _hidl_blob.putBool(_hidl_offset + 184, srfRespondIfInAddressSet);
        _hidl_blob.putBool(_hidl_offset + 185, shouldUseSrf);
        _hidl_blob.putBool(_hidl_offset + 186, isSsiRequiredForMatch);
        {
            int _hidl_vec_size = intfAddr.size();
            _hidl_blob.putInt32(_hidl_offset + 192 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 192 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 6));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                {
                    long _hidl_array_offset_1 = _hidl_index_0 * 6;
                    byte[] _hidl_array_item_1 = (byte[/* 6 */]) intfAddr.get(_hidl_index_0);

                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                    _hidl_array_offset_1 += 6 * 1;
                }
            }
            _hidl_blob.putBlob(_hidl_offset + 192 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

