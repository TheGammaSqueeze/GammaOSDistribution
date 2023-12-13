package android.hardware.wifi.V1_0;


public final class WifiDebugHostWakeReasonRxIcmpPacketDetails {
    /**
     * Wake icmp packet count.
     */
    public int icmpPkt = 0;
    /**
     * Wake icmp6 packet count.
     */
    public int icmp6Pkt = 0;
    /**
     * Wake icmp6 RA packet count.
     */
    public int icmp6Ra = 0;
    /**
     * Wake icmp6 NA packet count.
     */
    public int icmp6Na = 0;
    /**
     * Wake icmp6 NS packet count.
     */
    public int icmp6Ns = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails.class) {
            return false;
        }
        android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails other = (android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails)otherObject;
        if (this.icmpPkt != other.icmpPkt) {
            return false;
        }
        if (this.icmp6Pkt != other.icmp6Pkt) {
            return false;
        }
        if (this.icmp6Ra != other.icmp6Ra) {
            return false;
        }
        if (this.icmp6Na != other.icmp6Na) {
            return false;
        }
        if (this.icmp6Ns != other.icmp6Ns) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.icmpPkt), 
                android.os.HidlSupport.deepHashCode(this.icmp6Pkt), 
                android.os.HidlSupport.deepHashCode(this.icmp6Ra), 
                android.os.HidlSupport.deepHashCode(this.icmp6Na), 
                android.os.HidlSupport.deepHashCode(this.icmp6Ns));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".icmpPkt = ");
        builder.append(this.icmpPkt);
        builder.append(", .icmp6Pkt = ");
        builder.append(this.icmp6Pkt);
        builder.append(", .icmp6Ra = ");
        builder.append(this.icmp6Ra);
        builder.append(", .icmp6Na = ");
        builder.append(this.icmp6Na);
        builder.append(", .icmp6Ns = ");
        builder.append(this.icmp6Ns);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<WifiDebugHostWakeReasonRxIcmpPacketDetails> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<WifiDebugHostWakeReasonRxIcmpPacketDetails> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails _hidl_vec_element = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails();
                ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonRxIcmpPacketDetails) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        icmpPkt = _hidl_blob.getInt32(_hidl_offset + 0);
        icmp6Pkt = _hidl_blob.getInt32(_hidl_offset + 4);
        icmp6Ra = _hidl_blob.getInt32(_hidl_offset + 8);
        icmp6Na = _hidl_blob.getInt32(_hidl_offset + 12);
        icmp6Ns = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<WifiDebugHostWakeReasonRxIcmpPacketDetails> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, icmpPkt);
        _hidl_blob.putInt32(_hidl_offset + 4, icmp6Pkt);
        _hidl_blob.putInt32(_hidl_offset + 8, icmp6Ra);
        _hidl_blob.putInt32(_hidl_offset + 12, icmp6Na);
        _hidl_blob.putInt32(_hidl_offset + 16, icmp6Ns);
    }
};

