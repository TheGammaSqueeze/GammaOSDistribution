package android.hardware.radio.V1_5;


public final class ClosedSubscriberGroupInfo {
    /**
     * Indicates whether the cell is restricted to only CSG members. A cell not broadcasting the
     * CSG Indication but reporting CSG information is considered a Hybrid Cell.
     * Refer to the "csg-Indication" field in 3GPP TS 36.331 section 6.2.2
     * SystemInformationBlockType1.
     * Also refer to "CSG Indicator" in 3GPP TS 25.331 section 10.2.48.8.1 and TS 25.304.
     */
    public boolean csgIndication = false;
    /**
     * The human-readable name of the closed subscriber group operating this cell.
     * Refer to "hnb-Name" in TS 36.331 section 6.2.2 SystemInformationBlockType9.
     * Also refer to "HNB Name" in 3GPP TS25.331 section 10.2.48.8.23 and TS 23.003 section 4.8.
     */
    public String homeNodebName = new String();
    /**
     * The identity of the closed subscriber group that the cell belongs to.
     * Refer to "CSG-Identity" in TS 36.336 section 6.3.4.
     * Also refer to "CSG Identity" in 3GPP TS 25.331 section 10.3.2.8 and TS 23.003 section 4.7.
     */
    public int csgIdentity = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.ClosedSubscriberGroupInfo.class) {
            return false;
        }
        android.hardware.radio.V1_5.ClosedSubscriberGroupInfo other = (android.hardware.radio.V1_5.ClosedSubscriberGroupInfo)otherObject;
        if (this.csgIndication != other.csgIndication) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.homeNodebName, other.homeNodebName)) {
            return false;
        }
        if (this.csgIdentity != other.csgIdentity) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.csgIndication), 
                android.os.HidlSupport.deepHashCode(this.homeNodebName), 
                android.os.HidlSupport.deepHashCode(this.csgIdentity));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".csgIndication = ");
        builder.append(this.csgIndication);
        builder.append(", .homeNodebName = ");
        builder.append(this.homeNodebName);
        builder.append(", .csgIdentity = ");
        builder.append(this.csgIdentity);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ClosedSubscriberGroupInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ClosedSubscriberGroupInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.ClosedSubscriberGroupInfo _hidl_vec_element = new android.hardware.radio.V1_5.ClosedSubscriberGroupInfo();
                ((android.hardware.radio.V1_5.ClosedSubscriberGroupInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        csgIndication = _hidl_blob.getBool(_hidl_offset + 0);
        homeNodebName = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) homeNodebName).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        csgIdentity = _hidl_blob.getInt32(_hidl_offset + 24);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ClosedSubscriberGroupInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, csgIndication);
        _hidl_blob.putString(_hidl_offset + 8, homeNodebName);
        _hidl_blob.putInt32(_hidl_offset + 24, csgIdentity);
    }
};

