package android.hardware.wifi.V1_0;


public final class NanDataPathSecurityConfig {
    /**
     * Security configuration of the data-path (NDP). Security is required if not equal to
     * |NanDataPathSecurityType.OPEN|.
     * NAN Spec: Service Discovery Extension Attribute (SDEA) / Control / Security Required
     */
    public int securityType = 0;
    /**
     * Cipher type for data-paths. If |securityType| is |NanDataPathSecurityType.OPEN| then must
     * be set to |NanCipherSuiteType.NONE|, otherwise a non-|NanCipherSuiteType.NONE| cipher suite
     * must be specified.
     */
    public int cipherType = 0;
    /**
     * Optional Pairwise Master Key (PMK). Must be specified (and is only used) if |securityType| is
     * set to |NanDataPathSecurityType.PMK|.
     * Ref: IEEE 802.11i
     */
    public byte[/* 32 */] pmk = new byte[32];
    /**
     * Optional Passphrase. Must be specified (and is only used) if |securityType| is set to
     * |NanDataPathSecurityType.PASSPHRASE|.
     * Min length: |MIN_PASSPHRASE_LENGTH|
     * Max length: |MAX_PASSPHRASE_LENGTH|
     * NAN Spec: Appendix: Mapping pass-phrase to PMK for NCS-SK Cipher Suites
     */
    public java.util.ArrayList<Byte> passphrase = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanDataPathSecurityConfig.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanDataPathSecurityConfig other = (android.hardware.wifi.V1_0.NanDataPathSecurityConfig)otherObject;
        if (this.securityType != other.securityType) {
            return false;
        }
        if (this.cipherType != other.cipherType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.pmk, other.pmk)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.passphrase, other.passphrase)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.securityType), 
                android.os.HidlSupport.deepHashCode(this.cipherType), 
                android.os.HidlSupport.deepHashCode(this.pmk), 
                android.os.HidlSupport.deepHashCode(this.passphrase));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".securityType = ");
        builder.append(android.hardware.wifi.V1_0.NanDataPathSecurityType.toString(this.securityType));
        builder.append(", .cipherType = ");
        builder.append(android.hardware.wifi.V1_0.NanCipherSuiteType.toString(this.cipherType));
        builder.append(", .pmk = ");
        builder.append(java.util.Arrays.toString(this.pmk));
        builder.append(", .passphrase = ");
        builder.append(this.passphrase);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanDataPathSecurityConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanDataPathSecurityConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanDataPathSecurityConfig _hidl_vec_element = new android.hardware.wifi.V1_0.NanDataPathSecurityConfig();
                ((android.hardware.wifi.V1_0.NanDataPathSecurityConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        securityType = _hidl_blob.getInt32(_hidl_offset + 0);
        cipherType = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 32 */]) pmk, 32 /* size */);
            _hidl_array_offset_0 += 32 * 1;
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) passphrase).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) passphrase).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanDataPathSecurityConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, securityType);
        _hidl_blob.putInt32(_hidl_offset + 4, cipherType);
        {
            long _hidl_array_offset_0 = _hidl_offset + 8;
            byte[] _hidl_array_item_0 = (byte[/* 32 */]) pmk;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 32) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 32 * 1;
        }
        {
            int _hidl_vec_size = passphrase.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, passphrase.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

