package android.hardware.wifi.V1_4;


public final class NanEnableRequest {
    /**
     * Enable operation in a specific band: indexed by |NanBandIndex|.
     */
    public boolean[/* 3 */] operateInBand = new boolean[3];
    /**
     * Specify extent of cluster by specifying the max hop count.
     */
    public byte hopCountMax = 0;
    /**
     * Configurations of NAN cluster operation. Can also be modified at run-time using
     * |IWifiNanIface.configRequest|.
     */
    public android.hardware.wifi.V1_4.NanConfigRequest configParams = new android.hardware.wifi.V1_4.NanConfigRequest();
    /**
     * Non-standard configurations of NAN cluster operation - useful for debugging operations.
     */
    public android.hardware.wifi.V1_4.NanDebugConfig debugConfigs = new android.hardware.wifi.V1_4.NanDebugConfig();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_4.NanEnableRequest.class) {
            return false;
        }
        android.hardware.wifi.V1_4.NanEnableRequest other = (android.hardware.wifi.V1_4.NanEnableRequest)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.operateInBand, other.operateInBand)) {
            return false;
        }
        if (this.hopCountMax != other.hopCountMax) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.configParams, other.configParams)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.debugConfigs, other.debugConfigs)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.operateInBand), 
                android.os.HidlSupport.deepHashCode(this.hopCountMax), 
                android.os.HidlSupport.deepHashCode(this.configParams), 
                android.os.HidlSupport.deepHashCode(this.debugConfigs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".operateInBand = ");
        builder.append(java.util.Arrays.toString(this.operateInBand));
        builder.append(", .hopCountMax = ");
        builder.append(this.hopCountMax);
        builder.append(", .configParams = ");
        builder.append(this.configParams);
        builder.append(", .debugConfigs = ");
        builder.append(this.debugConfigs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(92 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanEnableRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanEnableRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 92,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_4.NanEnableRequest _hidl_vec_element = new android.hardware.wifi.V1_4.NanEnableRequest();
                ((android.hardware.wifi.V1_4.NanEnableRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 92);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            _hidl_blob.copyToBoolArray(_hidl_array_offset_0, (boolean[/* 3 */]) operateInBand, 3 /* size */);
            _hidl_array_offset_0 += 3 * 1;
        }
        hopCountMax = _hidl_blob.getInt8(_hidl_offset + 3);
        ((android.hardware.wifi.V1_4.NanConfigRequest) configParams).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
        ((android.hardware.wifi.V1_4.NanDebugConfig) debugConfigs).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 44);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(92 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanEnableRequest> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 92));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 92);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            boolean[] _hidl_array_item_0 = (boolean[/* 3 */]) operateInBand;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 3) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putBoolArray(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 3 * 1;
        }
        _hidl_blob.putInt8(_hidl_offset + 3, hopCountMax);
        configParams.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
        debugConfigs.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 44);
    }
};

