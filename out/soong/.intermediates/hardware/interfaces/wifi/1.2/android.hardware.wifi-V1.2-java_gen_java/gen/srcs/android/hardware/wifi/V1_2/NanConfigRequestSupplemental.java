package android.hardware.wifi.V1_2;


public final class NanConfigRequestSupplemental {
    /**
     * Specify the Discovery Beacon interval in ms. Specification only applicable if the device
     * transmits Discovery Beacons (based on the Wi-Fi Aware protocol selection criteria). The value
     * can be increased to reduce power consumption (on devices which would transmit Discovery
     * Beacons), however - cluster synchronization time will likely increase.
     * Values are:
     *  - A value of 0 indicates that the HAL sets the interval to a default (implementation specific)
     *  - A positive value
     */
    public int discoveryBeaconIntervalMs = 0;
    /**
     * The number of spatial streams to be used for transmitting NAN management frames (does NOT apply
     * to data-path packets). A small value may reduce power consumption for small discovery packets.
     * Values are:
     *  - A value of 0 indicates that the HAL sets the number to a default (implementation specific)
     *  - A positive value
     */
    public int numberOfSpatialStreamsInDiscovery = 0;
    /**
     * Controls whether the device may terminate listening on a Discovery Window (DW) earlier than the
     * DW termination (16ms) if no information is received. Enabling the feature will result in
     * lower power consumption, but may result in some missed messages and hence increased latency.
     */
    public boolean enableDiscoveryWindowEarlyTermination = false;
    /**
     * Controls whether NAN RTT (ranging) is permitted. Global flag on any NAN RTT operations are
     * allowed. Controls ranging in the context of discovery as well as direct RTT.
     */
    public boolean enableRanging = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_2.NanConfigRequestSupplemental.class) {
            return false;
        }
        android.hardware.wifi.V1_2.NanConfigRequestSupplemental other = (android.hardware.wifi.V1_2.NanConfigRequestSupplemental)otherObject;
        if (this.discoveryBeaconIntervalMs != other.discoveryBeaconIntervalMs) {
            return false;
        }
        if (this.numberOfSpatialStreamsInDiscovery != other.numberOfSpatialStreamsInDiscovery) {
            return false;
        }
        if (this.enableDiscoveryWindowEarlyTermination != other.enableDiscoveryWindowEarlyTermination) {
            return false;
        }
        if (this.enableRanging != other.enableRanging) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.discoveryBeaconIntervalMs), 
                android.os.HidlSupport.deepHashCode(this.numberOfSpatialStreamsInDiscovery), 
                android.os.HidlSupport.deepHashCode(this.enableDiscoveryWindowEarlyTermination), 
                android.os.HidlSupport.deepHashCode(this.enableRanging));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".discoveryBeaconIntervalMs = ");
        builder.append(this.discoveryBeaconIntervalMs);
        builder.append(", .numberOfSpatialStreamsInDiscovery = ");
        builder.append(this.numberOfSpatialStreamsInDiscovery);
        builder.append(", .enableDiscoveryWindowEarlyTermination = ");
        builder.append(this.enableDiscoveryWindowEarlyTermination);
        builder.append(", .enableRanging = ");
        builder.append(this.enableRanging);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanConfigRequestSupplemental> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanConfigRequestSupplemental> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_2.NanConfigRequestSupplemental _hidl_vec_element = new android.hardware.wifi.V1_2.NanConfigRequestSupplemental();
                ((android.hardware.wifi.V1_2.NanConfigRequestSupplemental) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        discoveryBeaconIntervalMs = _hidl_blob.getInt32(_hidl_offset + 0);
        numberOfSpatialStreamsInDiscovery = _hidl_blob.getInt32(_hidl_offset + 4);
        enableDiscoveryWindowEarlyTermination = _hidl_blob.getBool(_hidl_offset + 8);
        enableRanging = _hidl_blob.getBool(_hidl_offset + 9);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanConfigRequestSupplemental> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, discoveryBeaconIntervalMs);
        _hidl_blob.putInt32(_hidl_offset + 4, numberOfSpatialStreamsInDiscovery);
        _hidl_blob.putBool(_hidl_offset + 8, enableDiscoveryWindowEarlyTermination);
        _hidl_blob.putBool(_hidl_offset + 9, enableRanging);
    }
};

