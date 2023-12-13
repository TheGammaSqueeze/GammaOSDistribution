package android.hardware.radio.V1_4;


public final class LteVopsInfo {
    /**
     * This indicates if camped network support VoLTE services. This information is received
     * from LTE network during LTE NAS registration procedure through LTE ATTACH ACCEPT/TAU
     * ACCEPT. Refer 3GPP 24.301 EPS network feature support -> IMS VoPS
     */
    public boolean isVopsSupported = false;
    /**
     * This indicates if camped network support VoLTE emergency bearers. This information
     * is received from LTE network through two sources:
     * a. During LTE NAS registration procedure through LTE ATTACH ACCEPT/TAU ACCEPT. Refer
     *    3GPP 24.301 EPS network feature support -> EMC BS
     * b. In case device is not registered on network. Refer 3GPP 25.331 LTE RRC
     *    SIB1 : ims-EmergencySupport-r9
     * If device is registered on LTE, then this field indicates (a).
     * In case of limited service on LTE this field indicates (b).
     */
    public boolean isEmcBearerSupported = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.LteVopsInfo.class) {
            return false;
        }
        android.hardware.radio.V1_4.LteVopsInfo other = (android.hardware.radio.V1_4.LteVopsInfo)otherObject;
        if (this.isVopsSupported != other.isVopsSupported) {
            return false;
        }
        if (this.isEmcBearerSupported != other.isEmcBearerSupported) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.isVopsSupported), 
                android.os.HidlSupport.deepHashCode(this.isEmcBearerSupported));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".isVopsSupported = ");
        builder.append(this.isVopsSupported);
        builder.append(", .isEmcBearerSupported = ");
        builder.append(this.isEmcBearerSupported);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(2 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<LteVopsInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<LteVopsInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 2,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.LteVopsInfo _hidl_vec_element = new android.hardware.radio.V1_4.LteVopsInfo();
                ((android.hardware.radio.V1_4.LteVopsInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 2);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        isVopsSupported = _hidl_blob.getBool(_hidl_offset + 0);
        isEmcBearerSupported = _hidl_blob.getBool(_hidl_offset + 1);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<LteVopsInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 2));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 2);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, isVopsSupported);
        _hidl_blob.putBool(_hidl_offset + 1, isEmcBearerSupported);
    }
};

