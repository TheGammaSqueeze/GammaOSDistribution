package android.hardware.usb.V1_0;


public final class PortStatus {
    /**
     * Name of the port.
     * Used as the port's id by the caller.
     */
    public String portName = new String();
    /**
     * Data role of the port.
     */
    public int currentDataRole = 0;
    /**
     * Power Role of thte port.
     */
    public int currentPowerRole = 0;
    /**
     * Mode in which the port is connected.
     * Can be UFP or DFP.
     */
    public int currentMode = 0;
    /**
     * True indicates that the port's mode can
     * be changed. False otherwise.
     */
    public boolean canChangeMode = false;
    /**
     * True indicates that the port's data role
     * can be changed. False otherwise.
     * For example, true if Type-C PD PD_SWAP
     * is supported.
     */
    public boolean canChangeDataRole = false;
    /**
     * True indicates that the port's power role
     * can be changed. False otherwise.
     * For example, true if Type-C PD PR_SWAP
     * is supported.
     */
    public boolean canChangePowerRole = false;
    /**
     * Identifies the type of the local port.
     *
     * UFP - Indicates that port can only act as device for
     *       data and sink for power.
     * DFP - Indicates the port can only act as host for data
     *       and source for power.
     * DRP - Indicates can either act as UFP or DFP at a
     *       given point of time.
     */
    public int supportedModes = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.usb.V1_0.PortStatus.class) {
            return false;
        }
        android.hardware.usb.V1_0.PortStatus other = (android.hardware.usb.V1_0.PortStatus)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.portName, other.portName)) {
            return false;
        }
        if (this.currentDataRole != other.currentDataRole) {
            return false;
        }
        if (this.currentPowerRole != other.currentPowerRole) {
            return false;
        }
        if (this.currentMode != other.currentMode) {
            return false;
        }
        if (this.canChangeMode != other.canChangeMode) {
            return false;
        }
        if (this.canChangeDataRole != other.canChangeDataRole) {
            return false;
        }
        if (this.canChangePowerRole != other.canChangePowerRole) {
            return false;
        }
        if (this.supportedModes != other.supportedModes) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.portName), 
                android.os.HidlSupport.deepHashCode(this.currentDataRole), 
                android.os.HidlSupport.deepHashCode(this.currentPowerRole), 
                android.os.HidlSupport.deepHashCode(this.currentMode), 
                android.os.HidlSupport.deepHashCode(this.canChangeMode), 
                android.os.HidlSupport.deepHashCode(this.canChangeDataRole), 
                android.os.HidlSupport.deepHashCode(this.canChangePowerRole), 
                android.os.HidlSupport.deepHashCode(this.supportedModes));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".portName = ");
        builder.append(this.portName);
        builder.append(", .currentDataRole = ");
        builder.append(android.hardware.usb.V1_0.PortDataRole.toString(this.currentDataRole));
        builder.append(", .currentPowerRole = ");
        builder.append(android.hardware.usb.V1_0.PortPowerRole.toString(this.currentPowerRole));
        builder.append(", .currentMode = ");
        builder.append(android.hardware.usb.V1_0.PortMode.toString(this.currentMode));
        builder.append(", .canChangeMode = ");
        builder.append(this.canChangeMode);
        builder.append(", .canChangeDataRole = ");
        builder.append(this.canChangeDataRole);
        builder.append(", .canChangePowerRole = ");
        builder.append(this.canChangePowerRole);
        builder.append(", .supportedModes = ");
        builder.append(android.hardware.usb.V1_0.PortMode.toString(this.supportedModes));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PortStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PortStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.usb.V1_0.PortStatus _hidl_vec_element = new android.hardware.usb.V1_0.PortStatus();
                ((android.hardware.usb.V1_0.PortStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        portName = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) portName).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        currentDataRole = _hidl_blob.getInt32(_hidl_offset + 16);
        currentPowerRole = _hidl_blob.getInt32(_hidl_offset + 20);
        currentMode = _hidl_blob.getInt32(_hidl_offset + 24);
        canChangeMode = _hidl_blob.getBool(_hidl_offset + 28);
        canChangeDataRole = _hidl_blob.getBool(_hidl_offset + 29);
        canChangePowerRole = _hidl_blob.getBool(_hidl_offset + 30);
        supportedModes = _hidl_blob.getInt32(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PortStatus> _hidl_vec) {
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
        _hidl_blob.putString(_hidl_offset + 0, portName);
        _hidl_blob.putInt32(_hidl_offset + 16, currentDataRole);
        _hidl_blob.putInt32(_hidl_offset + 20, currentPowerRole);
        _hidl_blob.putInt32(_hidl_offset + 24, currentMode);
        _hidl_blob.putBool(_hidl_offset + 28, canChangeMode);
        _hidl_blob.putBool(_hidl_offset + 29, canChangeDataRole);
        _hidl_blob.putBool(_hidl_offset + 30, canChangePowerRole);
        _hidl_blob.putInt32(_hidl_offset + 32, supportedModes);
    }
};

