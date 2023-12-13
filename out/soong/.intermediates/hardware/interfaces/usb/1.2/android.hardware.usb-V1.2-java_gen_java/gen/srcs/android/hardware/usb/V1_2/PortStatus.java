package android.hardware.usb.V1_2;


public final class PortStatus {
    public android.hardware.usb.V1_1.PortStatus_1_1 status_1_1 = new android.hardware.usb.V1_1.PortStatus_1_1();
    /**
     * Contaminant presence protection modes supported by the port.
     */
    public int supportedContaminantProtectionModes;
    /**
     * Client can enable/disable contaminant presence protection through
     * enableContaminantPresenceProtection when true.
     */
    public boolean supportsEnableContaminantPresenceProtection = false;
    /**
     * Contaminant presence protection modes currently active for the port.
     */
    public int contaminantProtectionStatus = 0;
    /**
     * Client can enable/disable contaminant presence detection through
     * enableContaminantPresenceDetection when true.
     */
    public boolean supportsEnableContaminantPresenceDetection = false;
    /**
     * Current status of contaminant detection algorithm.
     */
    public int contaminantDetectionStatus = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.usb.V1_2.PortStatus.class) {
            return false;
        }
        android.hardware.usb.V1_2.PortStatus other = (android.hardware.usb.V1_2.PortStatus)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.status_1_1, other.status_1_1)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedContaminantProtectionModes, other.supportedContaminantProtectionModes)) {
            return false;
        }
        if (this.supportsEnableContaminantPresenceProtection != other.supportsEnableContaminantPresenceProtection) {
            return false;
        }
        if (this.contaminantProtectionStatus != other.contaminantProtectionStatus) {
            return false;
        }
        if (this.supportsEnableContaminantPresenceDetection != other.supportsEnableContaminantPresenceDetection) {
            return false;
        }
        if (this.contaminantDetectionStatus != other.contaminantDetectionStatus) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.status_1_1), 
                android.os.HidlSupport.deepHashCode(this.supportedContaminantProtectionModes), 
                android.os.HidlSupport.deepHashCode(this.supportsEnableContaminantPresenceProtection), 
                android.os.HidlSupport.deepHashCode(this.contaminantProtectionStatus), 
                android.os.HidlSupport.deepHashCode(this.supportsEnableContaminantPresenceDetection), 
                android.os.HidlSupport.deepHashCode(this.contaminantDetectionStatus));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".status_1_1 = ");
        builder.append(this.status_1_1);
        builder.append(", .supportedContaminantProtectionModes = ");
        builder.append(android.hardware.usb.V1_2.ContaminantProtectionMode.dumpBitfield(this.supportedContaminantProtectionModes));
        builder.append(", .supportsEnableContaminantPresenceProtection = ");
        builder.append(this.supportsEnableContaminantPresenceProtection);
        builder.append(", .contaminantProtectionStatus = ");
        builder.append(android.hardware.usb.V1_2.ContaminantProtectionStatus.toString(this.contaminantProtectionStatus));
        builder.append(", .supportsEnableContaminantPresenceDetection = ");
        builder.append(this.supportsEnableContaminantPresenceDetection);
        builder.append(", .contaminantDetectionStatus = ");
        builder.append(android.hardware.usb.V1_2.ContaminantDetectionStatus.toString(this.contaminantDetectionStatus));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PortStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PortStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.usb.V1_2.PortStatus _hidl_vec_element = new android.hardware.usb.V1_2.PortStatus();
                ((android.hardware.usb.V1_2.PortStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.usb.V1_1.PortStatus_1_1) status_1_1).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        supportedContaminantProtectionModes = _hidl_blob.getInt32(_hidl_offset + 48);
        supportsEnableContaminantPresenceProtection = _hidl_blob.getBool(_hidl_offset + 52);
        contaminantProtectionStatus = _hidl_blob.getInt32(_hidl_offset + 56);
        supportsEnableContaminantPresenceDetection = _hidl_blob.getBool(_hidl_offset + 60);
        contaminantDetectionStatus = _hidl_blob.getInt32(_hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
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
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        status_1_1.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 48, supportedContaminantProtectionModes);
        _hidl_blob.putBool(_hidl_offset + 52, supportsEnableContaminantPresenceProtection);
        _hidl_blob.putInt32(_hidl_offset + 56, contaminantProtectionStatus);
        _hidl_blob.putBool(_hidl_offset + 60, supportsEnableContaminantPresenceDetection);
        _hidl_blob.putInt32(_hidl_offset + 64, contaminantDetectionStatus);
    }
};

