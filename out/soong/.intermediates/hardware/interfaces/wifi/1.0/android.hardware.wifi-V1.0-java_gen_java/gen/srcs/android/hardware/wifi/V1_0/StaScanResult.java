package android.hardware.wifi.V1_0;


public final class StaScanResult {
    public long timeStampInUs = 0L;
    public java.util.ArrayList<Byte> ssid = new java.util.ArrayList<Byte>();
    public byte[/* 6 */] bssid = new byte[6];
    public int rssi = 0;
    public int frequency = 0;
    public short beaconPeriodInMs = 0;
    public short capability = 0;
    public java.util.ArrayList<android.hardware.wifi.V1_0.WifiInformationElement> informationElements = new java.util.ArrayList<android.hardware.wifi.V1_0.WifiInformationElement>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.StaScanResult.class) {
            return false;
        }
        android.hardware.wifi.V1_0.StaScanResult other = (android.hardware.wifi.V1_0.StaScanResult)otherObject;
        if (this.timeStampInUs != other.timeStampInUs) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.ssid, other.ssid)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bssid, other.bssid)) {
            return false;
        }
        if (this.rssi != other.rssi) {
            return false;
        }
        if (this.frequency != other.frequency) {
            return false;
        }
        if (this.beaconPeriodInMs != other.beaconPeriodInMs) {
            return false;
        }
        if (this.capability != other.capability) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.informationElements, other.informationElements)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.timeStampInUs), 
                android.os.HidlSupport.deepHashCode(this.ssid), 
                android.os.HidlSupport.deepHashCode(this.bssid), 
                android.os.HidlSupport.deepHashCode(this.rssi), 
                android.os.HidlSupport.deepHashCode(this.frequency), 
                android.os.HidlSupport.deepHashCode(this.beaconPeriodInMs), 
                android.os.HidlSupport.deepHashCode(this.capability), 
                android.os.HidlSupport.deepHashCode(this.informationElements));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".timeStampInUs = ");
        builder.append(this.timeStampInUs);
        builder.append(", .ssid = ");
        builder.append(this.ssid);
        builder.append(", .bssid = ");
        builder.append(java.util.Arrays.toString(this.bssid));
        builder.append(", .rssi = ");
        builder.append(this.rssi);
        builder.append(", .frequency = ");
        builder.append(this.frequency);
        builder.append(", .beaconPeriodInMs = ");
        builder.append(this.beaconPeriodInMs);
        builder.append(", .capability = ");
        builder.append(this.capability);
        builder.append(", .informationElements = ");
        builder.append(this.informationElements);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<StaScanResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<StaScanResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.StaScanResult _hidl_vec_element = new android.hardware.wifi.V1_0.StaScanResult();
                ((android.hardware.wifi.V1_0.StaScanResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        timeStampInUs = _hidl_blob.getInt64(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) ssid).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) ssid).add(_hidl_vec_element);
            }
        }
        {
            long _hidl_array_offset_0 = _hidl_offset + 24;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
            _hidl_array_offset_0 += 6 * 1;
        }
        rssi = _hidl_blob.getInt32(_hidl_offset + 32);
        frequency = _hidl_blob.getInt32(_hidl_offset + 36);
        beaconPeriodInMs = _hidl_blob.getInt16(_hidl_offset + 40);
        capability = _hidl_blob.getInt16(_hidl_offset + 42);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    _hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.wifi.V1_0.WifiInformationElement>) informationElements).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.WifiInformationElement _hidl_vec_element = new android.hardware.wifi.V1_0.WifiInformationElement();
                ((android.hardware.wifi.V1_0.WifiInformationElement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                ((java.util.ArrayList<android.hardware.wifi.V1_0.WifiInformationElement>) informationElements).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<StaScanResult> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt64(_hidl_offset + 0, timeStampInUs);
        {
            int _hidl_vec_size = ssid.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, ssid.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            long _hidl_array_offset_0 = _hidl_offset + 24;
            byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 6 * 1;
        }
        _hidl_blob.putInt32(_hidl_offset + 32, rssi);
        _hidl_blob.putInt32(_hidl_offset + 36, frequency);
        _hidl_blob.putInt16(_hidl_offset + 40, beaconPeriodInMs);
        _hidl_blob.putInt16(_hidl_offset + 42, capability);
        {
            int _hidl_vec_size = informationElements.size();
            _hidl_blob.putInt32(_hidl_offset + 48 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 48 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                informationElements.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(_hidl_offset + 48 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

