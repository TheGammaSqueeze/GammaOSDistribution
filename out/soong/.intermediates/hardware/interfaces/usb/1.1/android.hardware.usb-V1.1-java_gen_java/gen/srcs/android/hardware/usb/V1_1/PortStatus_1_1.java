package android.hardware.usb.V1_1;


public final class PortStatus_1_1 {
    /*
     * The supportedModes and the currentMode fields of the status
     * object should be set to NONE.
     */
    public android.hardware.usb.V1_0.PortStatus status = new android.hardware.usb.V1_0.PortStatus();
    /*
     * Identifies the modes supported by the port.
     * Refer to PortMode_1_1 for the significance of the individual bits.
     */
    public int supportedModes;
    /*
     * Indicates the current mode in which the port is operating.
     */
    public int currentMode = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.usb.V1_1.PortStatus_1_1.class) {
            return false;
        }
        android.hardware.usb.V1_1.PortStatus_1_1 other = (android.hardware.usb.V1_1.PortStatus_1_1)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.status, other.status)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedModes, other.supportedModes)) {
            return false;
        }
        if (this.currentMode != other.currentMode) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.status), 
                android.os.HidlSupport.deepHashCode(this.supportedModes), 
                android.os.HidlSupport.deepHashCode(this.currentMode));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".status = ");
        builder.append(this.status);
        builder.append(", .supportedModes = ");
        builder.append(android.hardware.usb.V1_1.PortMode_1_1.dumpBitfield(this.supportedModes));
        builder.append(", .currentMode = ");
        builder.append(android.hardware.usb.V1_1.PortMode_1_1.toString(this.currentMode));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PortStatus_1_1> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PortStatus_1_1> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.usb.V1_1.PortStatus_1_1 _hidl_vec_element = new android.hardware.usb.V1_1.PortStatus_1_1();
                ((android.hardware.usb.V1_1.PortStatus_1_1) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.usb.V1_0.PortStatus) status).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        supportedModes = _hidl_blob.getInt32(_hidl_offset + 40);
        currentMode = _hidl_blob.getInt32(_hidl_offset + 44);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PortStatus_1_1> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        status.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 40, supportedModes);
        _hidl_blob.putInt32(_hidl_offset + 44, currentMode);
    }
};

