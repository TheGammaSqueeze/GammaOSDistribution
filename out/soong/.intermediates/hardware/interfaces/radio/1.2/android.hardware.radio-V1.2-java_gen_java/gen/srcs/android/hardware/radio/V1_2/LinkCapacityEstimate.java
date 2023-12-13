package android.hardware.radio.V1_2;


public final class LinkCapacityEstimate {
    /**
     * Estimated downlink capacity in kbps. This bandwidth estimate shall be the estimated
     * maximum sustainable link bandwidth (as would be measured at the Upper PDCP or SNDCP SAP).
     * If the DL Aggregate Maximum Bit Rate is known, this value shall not exceed the DL-AMBR
     * for the Internet PDN connection.
     */
    public int downlinkCapacityKbps = 0;
    /**
     * Estimated uplink capacity in kbps. This bandwidth estimate shall be the estimated
     * maximum sustainable link bandwidth (as would be measured at the Upper PDCP or SNDCP SAP).
     * If the UL Aggregate Maximum Bit Rate is known, this value shall not exceed the UL-AMBR
     * for the Internet PDN connection.
     */
    public int uplinkCapacityKbps = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.LinkCapacityEstimate.class) {
            return false;
        }
        android.hardware.radio.V1_2.LinkCapacityEstimate other = (android.hardware.radio.V1_2.LinkCapacityEstimate)otherObject;
        if (this.downlinkCapacityKbps != other.downlinkCapacityKbps) {
            return false;
        }
        if (this.uplinkCapacityKbps != other.uplinkCapacityKbps) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.downlinkCapacityKbps), 
                android.os.HidlSupport.deepHashCode(this.uplinkCapacityKbps));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".downlinkCapacityKbps = ");
        builder.append(this.downlinkCapacityKbps);
        builder.append(", .uplinkCapacityKbps = ");
        builder.append(this.uplinkCapacityKbps);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(8 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<LinkCapacityEstimate> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<LinkCapacityEstimate> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 8,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.LinkCapacityEstimate _hidl_vec_element = new android.hardware.radio.V1_2.LinkCapacityEstimate();
                ((android.hardware.radio.V1_2.LinkCapacityEstimate) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        downlinkCapacityKbps = _hidl_blob.getInt32(_hidl_offset + 0);
        uplinkCapacityKbps = _hidl_blob.getInt32(_hidl_offset + 4);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<LinkCapacityEstimate> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, downlinkCapacityKbps);
        _hidl_blob.putInt32(_hidl_offset + 4, uplinkCapacityKbps);
    }
};

