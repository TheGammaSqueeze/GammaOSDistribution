package android.hardware.wifi.V1_0;


public final class NanDataPathConfirmInd {
    /**
     * ID of the data-path.
     */
    public int ndpInstanceId = 0;
    /**
     * Indicates whether the data-path setup succeeded (true) or failed (false).
     */
    public boolean dataPathSetupSuccess = false;
    /**
     * MAC address of the peer's data-interface (not it's management/discovery interface).
     */
    public byte[/* 6 */] peerNdiMacAddr = new byte[6];
    /**
     * Arbitrary information communicated from the peer as part of the data-path setup process - there
     * is no semantic meaning to these bytes. They are passed-through from sender to receiver as-is
     * with no parsing.
     * Max length: |NanCapabilities.maxAppInfoLen|.
     * NAN Spec: Data Path Attributes / NDP Attribute / NDP Specific Info
     */
    public java.util.ArrayList<Byte> appInfo = new java.util.ArrayList<Byte>();
    /**
     * Failure reason if |dataPathSetupSuccess| is false.
     */
    public android.hardware.wifi.V1_0.WifiNanStatus status = new android.hardware.wifi.V1_0.WifiNanStatus();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanDataPathConfirmInd.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanDataPathConfirmInd other = (android.hardware.wifi.V1_0.NanDataPathConfirmInd)otherObject;
        if (this.ndpInstanceId != other.ndpInstanceId) {
            return false;
        }
        if (this.dataPathSetupSuccess != other.dataPathSetupSuccess) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.peerNdiMacAddr, other.peerNdiMacAddr)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.appInfo, other.appInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.status, other.status)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.ndpInstanceId), 
                android.os.HidlSupport.deepHashCode(this.dataPathSetupSuccess), 
                android.os.HidlSupport.deepHashCode(this.peerNdiMacAddr), 
                android.os.HidlSupport.deepHashCode(this.appInfo), 
                android.os.HidlSupport.deepHashCode(this.status));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".ndpInstanceId = ");
        builder.append(this.ndpInstanceId);
        builder.append(", .dataPathSetupSuccess = ");
        builder.append(this.dataPathSetupSuccess);
        builder.append(", .peerNdiMacAddr = ");
        builder.append(java.util.Arrays.toString(this.peerNdiMacAddr));
        builder.append(", .appInfo = ");
        builder.append(this.appInfo);
        builder.append(", .status = ");
        builder.append(this.status);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDataPathConfirmInd> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDataPathConfirmInd> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanDataPathConfirmInd _hidl_vec_element = new android.hardware.wifi.V1_0.NanDataPathConfirmInd();
                ((android.hardware.wifi.V1_0.NanDataPathConfirmInd) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ndpInstanceId = _hidl_blob.getInt32(_hidl_offset + 0);
        dataPathSetupSuccess = _hidl_blob.getBool(_hidl_offset + 4);
        {
            long _hidl_array_offset_0 = _hidl_offset + 5;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerNdiMacAddr, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) appInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) appInfo).add(_hidl_vec_element);
            }
        }
        ((android.hardware.wifi.V1_0.WifiNanStatus) status).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDataPathConfirmInd> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, ndpInstanceId);
        _hidl_blob.putBool(_hidl_offset + 4, dataPathSetupSuccess);
        {
            long _hidl_array_offset_0 = _hidl_offset + 5;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerNdiMacAddr;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = appInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, appInfo.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        status.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
    }
};

