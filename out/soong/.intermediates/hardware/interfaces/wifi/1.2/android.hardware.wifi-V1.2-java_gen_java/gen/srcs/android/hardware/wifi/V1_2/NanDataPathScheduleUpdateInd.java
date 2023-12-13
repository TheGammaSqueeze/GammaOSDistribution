package android.hardware.wifi.V1_2;


public final class NanDataPathScheduleUpdateInd {
    /**
     * The discovery address (NMI) of the peer to which the NDP is connected.
     */
    public byte[/* 6 */] peerDiscoveryAddress = new byte[6];
    /**
     * The updated channel(s) information.
     */
    public java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo> channelInfo = new java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>();
    /**
     * The list of NDPs to which this update applies.
     */
    public java.util.ArrayList<Integer> ndpInstanceIds = new java.util.ArrayList<Integer>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd.class) {
            return false;
        }
        android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd other = (android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.peerDiscoveryAddress, other.peerDiscoveryAddress)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.channelInfo, other.channelInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ndpInstanceIds, other.ndpInstanceIds)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.peerDiscoveryAddress), 
                android.os.HidlSupport.deepHashCode(this.channelInfo), 
                android.os.HidlSupport.deepHashCode(this.ndpInstanceIds));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".peerDiscoveryAddress = ");
        builder.append(java.util.Arrays.toString(this.peerDiscoveryAddress));
        builder.append(", .channelInfo = ");
        builder.append(this.channelInfo);
        builder.append(", .ndpInstanceIds = ");
        builder.append(this.ndpInstanceIds);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDataPathScheduleUpdateInd> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDataPathScheduleUpdateInd> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd _hidl_vec_element = new android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd();
                ((android.hardware.wifi.V1_2.NanDataPathScheduleUpdateInd) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) peerDiscoveryAddress, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>) channelInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanDataPathChannelInfo _hidl_vec_element = new android.hardware.wifi.V1_2.NanDataPathChannelInfo();
                ((android.hardware.wifi.V1_2.NanDataPathChannelInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                ((java.util.ArrayList<android.hardware.wifi.V1_2.NanDataPathChannelInfo>) channelInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) ndpInstanceIds).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) ndpInstanceIds).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDataPathScheduleUpdateInd> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            long _hidl_array_offset_0 = _hidl_offset + 0;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) peerDiscoveryAddress;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        {
            int _hidl_vec_size = channelInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                channelInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = ndpInstanceIds.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, ndpInstanceIds.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

