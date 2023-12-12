package android.hardware.radio.V1_5;


public final class NetworkScanRequest {
    public int type = 0;
    /**
     * Time interval in seconds between the completion of one scan and the start of
     * a subsequent scan.
     * Implementations may ignore this field unless the 'type' is 'PERIODIC'.
     * Range: ScanIntervalRange:MIN to ScanIntervalRange:MAX
     */
    public int interval = 0;
    /**
     * Networks with bands/channels to scan
     * Maximum length of the vector is RadioConst:RADIO_ACCESS_SPECIFIER_MAX_SIZE
     */
    public java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier> specifiers = new java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier>();
    /**
     * Maximum duration of the periodic search (in seconds).
     * If the search lasts maxSearchTime, it must be terminated.
     * Range: MaxSearchTimeRange:MIN to MaxSearchTimeRange:MAX
     */
    public int maxSearchTime = 0;
    /**
     * Indicates whether the modem must report incremental results of the network scan
     * to the client.
     * FALSE – Incremental results must not be reported.
     * TRUE  – Incremental must be reported.
     */
    public boolean incrementalResults = false;
    /**
     * Indicates the periodicity with which the modem must report incremental results to
     * the client (in seconds).
     * Implementations may ignore this value if the incremental results are not requested.
     * This value must be less than or equal to maxSearchTime.
     * Range: IncrementalResultsPeriodicityRange:MIN to IncrementalResultsPeriodicityRange:MAX
     */
    public int incrementalResultsPeriodicity = 0;
    /**
     * Describes the List of PLMN ids (MCC-MNC)
     * If any PLMN of this list is found, search must end at that point and results with all
     * PLMN found until that point should be sent as response.
     * If the list is not sent, search to be completed until end and all PLMNs found to be
     * reported.
     */
    public java.util.ArrayList<String> mccMncs = new java.util.ArrayList<String>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.NetworkScanRequest.class) {
            return false;
        }
        android.hardware.radio.V1_5.NetworkScanRequest other = (android.hardware.radio.V1_5.NetworkScanRequest)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (this.interval != other.interval) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.specifiers, other.specifiers)) {
            return false;
        }
        if (this.maxSearchTime != other.maxSearchTime) {
            return false;
        }
        if (this.incrementalResults != other.incrementalResults) {
            return false;
        }
        if (this.incrementalResultsPeriodicity != other.incrementalResultsPeriodicity) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.mccMncs, other.mccMncs)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.interval), 
                android.os.HidlSupport.deepHashCode(this.specifiers), 
                android.os.HidlSupport.deepHashCode(this.maxSearchTime), 
                android.os.HidlSupport.deepHashCode(this.incrementalResults), 
                android.os.HidlSupport.deepHashCode(this.incrementalResultsPeriodicity), 
                android.os.HidlSupport.deepHashCode(this.mccMncs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.radio.V1_1.ScanType.toString(this.type));
        builder.append(", .interval = ");
        builder.append(this.interval);
        builder.append(", .specifiers = ");
        builder.append(this.specifiers);
        builder.append(", .maxSearchTime = ");
        builder.append(this.maxSearchTime);
        builder.append(", .incrementalResults = ");
        builder.append(this.incrementalResults);
        builder.append(", .incrementalResultsPeriodicity = ");
        builder.append(this.incrementalResultsPeriodicity);
        builder.append(", .mccMncs = ");
        builder.append(this.mccMncs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<NetworkScanRequest> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<NetworkScanRequest> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.NetworkScanRequest _hidl_vec_element = new android.hardware.radio.V1_5.NetworkScanRequest();
                ((android.hardware.radio.V1_5.NetworkScanRequest) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        type = _hidl_blob.getInt32(_hidl_offset + 0);
        interval = _hidl_blob.getInt32(_hidl_offset + 4);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier>) specifiers).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.RadioAccessSpecifier _hidl_vec_element = new android.hardware.radio.V1_5.RadioAccessSpecifier();
                ((android.hardware.radio.V1_5.RadioAccessSpecifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                ((java.util.ArrayList<android.hardware.radio.V1_5.RadioAccessSpecifier>) specifiers).add(_hidl_vec_element);
            }
        }
        maxSearchTime = _hidl_blob.getInt32(_hidl_offset + 24);
        incrementalResults = _hidl_blob.getBool(_hidl_offset + 28);
        incrementalResultsPeriodicity = _hidl_blob.getInt32(_hidl_offset + 32);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) mccMncs).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) mccMncs).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<NetworkScanRequest> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        _hidl_blob.putInt32(_hidl_offset + 4, interval);
        {
            int _hidl_vec_size = specifiers.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                specifiers.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 24, maxSearchTime);
        _hidl_blob.putBool(_hidl_offset + 28, incrementalResults);
        _hidl_blob.putInt32(_hidl_offset + 32, incrementalResultsPeriodicity);
        {
            int _hidl_vec_size = mccMncs.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, mccMncs.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

