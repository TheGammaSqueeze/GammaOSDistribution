package android.hardware.radio.V1_6;


public final class NrVopsInfo {
    /**
     * This indicates if the camped network supports VoNR services, and what kind of services
     * it supports. This information is received from NR network during NR NAS registration
     * procedure through NR REGISTRATION ACCEPT.
     * Refer 3GPP 24.501 EPS 5GS network feature support -> IMS VoPS
     */
    public byte vopsSupported = 0;
    /**
     * This indicates if the camped network supports VoNR emergency service. This information
     * is received from NR network through two sources:
     * a. During NR NAS registration procedure through NR REGISTRATION ACCEPT.
     *    Refer 3GPP 24.501 EPS 5GS network feature support -> EMC
     * b. In case the device is not registered on the network.
     *    Refer 3GPP 38.331 SIB1 : ims-EmergencySupport
     *    If device is registered on NR, then this field indicates whether the cell
     *    supports IMS emergency bearer services for UEs in limited service mode.
     */
    public byte emcSupported = 0;
    /**
     * This indicates if the camped network supports VoNR emergency service fallback. This
     * information is received from NR network during NR NAS registration procedure through
     * NR REGISTRATION ACCEPT.
     * Refer 3GPP 24.501 EPS 5GS network feature support -> EMF
     */
    public byte emfSupported = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.NrVopsInfo.class) {
            return false;
        }
        android.hardware.radio.V1_6.NrVopsInfo other = (android.hardware.radio.V1_6.NrVopsInfo)otherObject;
        if (this.vopsSupported != other.vopsSupported) {
            return false;
        }
        if (this.emcSupported != other.emcSupported) {
            return false;
        }
        if (this.emfSupported != other.emfSupported) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.vopsSupported), 
                android.os.HidlSupport.deepHashCode(this.emcSupported), 
                android.os.HidlSupport.deepHashCode(this.emfSupported));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".vopsSupported = ");
        builder.append(android.hardware.radio.V1_6.VopsIndicator.toString(this.vopsSupported));
        builder.append(", .emcSupported = ");
        builder.append(android.hardware.radio.V1_6.EmcIndicator.toString(this.emcSupported));
        builder.append(", .emfSupported = ");
        builder.append(android.hardware.radio.V1_6.EmfIndicator.toString(this.emfSupported));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(3 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NrVopsInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NrVopsInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 3,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.NrVopsInfo _hidl_vec_element = new android.hardware.radio.V1_6.NrVopsInfo();
                ((android.hardware.radio.V1_6.NrVopsInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 3);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        vopsSupported = _hidl_blob.getInt8(_hidl_offset + 0);
        emcSupported = _hidl_blob.getInt8(_hidl_offset + 1);
        emfSupported = _hidl_blob.getInt8(_hidl_offset + 2);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(3 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NrVopsInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 3));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 3);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, vopsSupported);
        _hidl_blob.putInt8(_hidl_offset + 1, emcSupported);
        _hidl_blob.putInt8(_hidl_offset + 2, emfSupported);
    }
};

