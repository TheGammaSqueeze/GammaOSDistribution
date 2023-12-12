package android.hardware.wifi.V1_0;


public final class NanCapabilities {
    /**
     * Maximum number of clusters which the device can join concurrently.
     */
    public int maxConcurrentClusters = 0;
    /**
     * Maximum number of concurrent publish discovery sessions.
     */
    public int maxPublishes = 0;
    /**
     * Maximum number of concurrent subscribe discovery sessions.
     */
    public int maxSubscribes = 0;
    /**
     * Maximum length (in bytes) of service name.
     */
    public int maxServiceNameLen = 0;
    /**
     * Maximum length (in bytes) of individual match filters.
     */
    public int maxMatchFilterLen = 0;
    /**
     * Maximum length (in bytes) of aggregate match filters across all active sessions.
     */
    public int maxTotalMatchFilterLen = 0;
    /**
     * Maximum length (in bytes) of the service specific info field.
     */
    public int maxServiceSpecificInfoLen = 0;
    /**
     * Maximum length (in bytes) of the extended service specific info field.
     */
    public int maxExtendedServiceSpecificInfoLen = 0;
    /**
     * Maximum number of data interfaces (NDI) which can be created concurrently on the device.
     */
    public int maxNdiInterfaces = 0;
    /**
     * Maximum number of data paths (NDP) which can be created concurrently on the device, across all
     * data interfaces (NDI).
     */
    public int maxNdpSessions = 0;
    /**
     * Maximum length (in bytes) of application info field (used in data-path negotiations).
     */
    public int maxAppInfoLen = 0;
    /**
     * Maximum number of transmitted followup messages which can be queued by the firmware.
     */
    public int maxQueuedTransmitFollowupMsgs = 0;
    /**
     * Maximum number MAC interface addresses which can be specified to a subscribe discovery session.
     */
    public int maxSubscribeInterfaceAddresses = 0;
    /**
     * The set of supported Cipher suites. The |NanCipherSuiteType| bit fields are used.
     */
    public int supportedCipherSuites;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.wifi.V1_0.NanCapabilities.class) {
            return false;
        }
        android.hardware.wifi.V1_0.NanCapabilities other = (android.hardware.wifi.V1_0.NanCapabilities)otherObject;
        if (this.maxConcurrentClusters != other.maxConcurrentClusters) {
            return false;
        }
        if (this.maxPublishes != other.maxPublishes) {
            return false;
        }
        if (this.maxSubscribes != other.maxSubscribes) {
            return false;
        }
        if (this.maxServiceNameLen != other.maxServiceNameLen) {
            return false;
        }
        if (this.maxMatchFilterLen != other.maxMatchFilterLen) {
            return false;
        }
        if (this.maxTotalMatchFilterLen != other.maxTotalMatchFilterLen) {
            return false;
        }
        if (this.maxServiceSpecificInfoLen != other.maxServiceSpecificInfoLen) {
            return false;
        }
        if (this.maxExtendedServiceSpecificInfoLen != other.maxExtendedServiceSpecificInfoLen) {
            return false;
        }
        if (this.maxNdiInterfaces != other.maxNdiInterfaces) {
            return false;
        }
        if (this.maxNdpSessions != other.maxNdpSessions) {
            return false;
        }
        if (this.maxAppInfoLen != other.maxAppInfoLen) {
            return false;
        }
        if (this.maxQueuedTransmitFollowupMsgs != other.maxQueuedTransmitFollowupMsgs) {
            return false;
        }
        if (this.maxSubscribeInterfaceAddresses != other.maxSubscribeInterfaceAddresses) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedCipherSuites, other.supportedCipherSuites)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.maxConcurrentClusters), 
                android.os.HidlSupport.deepHashCode(this.maxPublishes), 
                android.os.HidlSupport.deepHashCode(this.maxSubscribes), 
                android.os.HidlSupport.deepHashCode(this.maxServiceNameLen), 
                android.os.HidlSupport.deepHashCode(this.maxMatchFilterLen), 
                android.os.HidlSupport.deepHashCode(this.maxTotalMatchFilterLen), 
                android.os.HidlSupport.deepHashCode(this.maxServiceSpecificInfoLen), 
                android.os.HidlSupport.deepHashCode(this.maxExtendedServiceSpecificInfoLen), 
                android.os.HidlSupport.deepHashCode(this.maxNdiInterfaces), 
                android.os.HidlSupport.deepHashCode(this.maxNdpSessions), 
                android.os.HidlSupport.deepHashCode(this.maxAppInfoLen), 
                android.os.HidlSupport.deepHashCode(this.maxQueuedTransmitFollowupMsgs), 
                android.os.HidlSupport.deepHashCode(this.maxSubscribeInterfaceAddresses), 
                android.os.HidlSupport.deepHashCode(this.supportedCipherSuites));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".maxConcurrentClusters = ");
        builder.append(this.maxConcurrentClusters);
        builder.append(", .maxPublishes = ");
        builder.append(this.maxPublishes);
        builder.append(", .maxSubscribes = ");
        builder.append(this.maxSubscribes);
        builder.append(", .maxServiceNameLen = ");
        builder.append(this.maxServiceNameLen);
        builder.append(", .maxMatchFilterLen = ");
        builder.append(this.maxMatchFilterLen);
        builder.append(", .maxTotalMatchFilterLen = ");
        builder.append(this.maxTotalMatchFilterLen);
        builder.append(", .maxServiceSpecificInfoLen = ");
        builder.append(this.maxServiceSpecificInfoLen);
        builder.append(", .maxExtendedServiceSpecificInfoLen = ");
        builder.append(this.maxExtendedServiceSpecificInfoLen);
        builder.append(", .maxNdiInterfaces = ");
        builder.append(this.maxNdiInterfaces);
        builder.append(", .maxNdpSessions = ");
        builder.append(this.maxNdpSessions);
        builder.append(", .maxAppInfoLen = ");
        builder.append(this.maxAppInfoLen);
        builder.append(", .maxQueuedTransmitFollowupMsgs = ");
        builder.append(this.maxQueuedTransmitFollowupMsgs);
        builder.append(", .maxSubscribeInterfaceAddresses = ");
        builder.append(this.maxSubscribeInterfaceAddresses);
        builder.append(", .supportedCipherSuites = ");
        builder.append(android.hardware.wifi.V1_0.NanCipherSuiteType.dumpBitfield(this.supportedCipherSuites));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NanCapabilities> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NanCapabilities> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.wifi.V1_0.NanCapabilities _hidl_vec_element = new android.hardware.wifi.V1_0.NanCapabilities();
                ((android.hardware.wifi.V1_0.NanCapabilities) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        maxConcurrentClusters = _hidl_blob.getInt32(_hidl_offset + 0);
        maxPublishes = _hidl_blob.getInt32(_hidl_offset + 4);
        maxSubscribes = _hidl_blob.getInt32(_hidl_offset + 8);
        maxServiceNameLen = _hidl_blob.getInt32(_hidl_offset + 12);
        maxMatchFilterLen = _hidl_blob.getInt32(_hidl_offset + 16);
        maxTotalMatchFilterLen = _hidl_blob.getInt32(_hidl_offset + 20);
        maxServiceSpecificInfoLen = _hidl_blob.getInt32(_hidl_offset + 24);
        maxExtendedServiceSpecificInfoLen = _hidl_blob.getInt32(_hidl_offset + 28);
        maxNdiInterfaces = _hidl_blob.getInt32(_hidl_offset + 32);
        maxNdpSessions = _hidl_blob.getInt32(_hidl_offset + 36);
        maxAppInfoLen = _hidl_blob.getInt32(_hidl_offset + 40);
        maxQueuedTransmitFollowupMsgs = _hidl_blob.getInt32(_hidl_offset + 44);
        maxSubscribeInterfaceAddresses = _hidl_blob.getInt32(_hidl_offset + 48);
        supportedCipherSuites = _hidl_blob.getInt32(_hidl_offset + 52);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NanCapabilities> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, maxConcurrentClusters);
        _hidl_blob.putInt32(_hidl_offset + 4, maxPublishes);
        _hidl_blob.putInt32(_hidl_offset + 8, maxSubscribes);
        _hidl_blob.putInt32(_hidl_offset + 12, maxServiceNameLen);
        _hidl_blob.putInt32(_hidl_offset + 16, maxMatchFilterLen);
        _hidl_blob.putInt32(_hidl_offset + 20, maxTotalMatchFilterLen);
        _hidl_blob.putInt32(_hidl_offset + 24, maxServiceSpecificInfoLen);
        _hidl_blob.putInt32(_hidl_offset + 28, maxExtendedServiceSpecificInfoLen);
        _hidl_blob.putInt32(_hidl_offset + 32, maxNdiInterfaces);
        _hidl_blob.putInt32(_hidl_offset + 36, maxNdpSessions);
        _hidl_blob.putInt32(_hidl_offset + 40, maxAppInfoLen);
        _hidl_blob.putInt32(_hidl_offset + 44, maxQueuedTransmitFollowupMsgs);
        _hidl_blob.putInt32(_hidl_offset + 48, maxSubscribeInterfaceAddresses);
        _hidl_blob.putInt32(_hidl_offset + 52, supportedCipherSuites);
    }
};

