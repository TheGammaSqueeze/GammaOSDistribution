package android.hardware.wifi.V1_5;


public final class WifiUsableChannel {
    /**
     * Wifi channel freqeuncy in MHz.
     */
    public int channel = 0;
    /**
     * Wifi channel bandwidth in MHz.
     */
    public int channelBandwidth = 0;
    /**
     * Iface modes feasible on this channel.
     */
    public int ifaceModeMask;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_5.WifiUsableChannel.class) {
            return false;
        }
        android.hardware.wifi.V1_5.WifiUsableChannel other = (android.hardware.wifi.V1_5.WifiUsableChannel)otherObject;
        if (this.channel != other.channel) {
            return false;
        }
        if (this.channelBandwidth != other.channelBandwidth) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ifaceModeMask, other.ifaceModeMask)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.channel), 
                android.os.HidlSupport.deepHashCode(this.channelBandwidth), 
                android.os.HidlSupport.deepHashCode(this.ifaceModeMask));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".channel = ");
        builder.append(this.channel);
        builder.append(", .channelBandwidth = ");
        builder.append(android.hardware.wifi.V1_0.WifiChannelWidthInMhz.toString(this.channelBandwidth));
        builder.append(", .ifaceModeMask = ");
        builder.append(android.hardware.wifi.V1_5.WifiIfaceMode.dumpBitfield(this.ifaceModeMask));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiUsableChannel> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiUsableChannel> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_5.WifiUsableChannel _hidl_vec_element = new android.hardware.wifi.V1_5.WifiUsableChannel();
                ((android.hardware.wifi.V1_5.WifiUsableChannel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        channel = _hidl_blob.getInt32(_hidl_offset + 0);
        channelBandwidth = _hidl_blob.getInt32(_hidl_offset + 4);
        ifaceModeMask = _hidl_blob.getInt32(_hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiUsableChannel> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, channel);
        _hidl_blob.putInt32(_hidl_offset + 4, channelBandwidth);
        _hidl_blob.putInt32(_hidl_offset + 8, ifaceModeMask);
    }
};

