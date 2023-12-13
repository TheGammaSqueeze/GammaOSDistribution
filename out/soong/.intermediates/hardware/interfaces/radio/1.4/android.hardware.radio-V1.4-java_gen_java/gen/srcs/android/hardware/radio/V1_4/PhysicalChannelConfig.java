package android.hardware.radio.V1_4;


public final class PhysicalChannelConfig {
    public android.hardware.radio.V1_2.PhysicalChannelConfig base = new android.hardware.radio.V1_2.PhysicalChannelConfig();
    /**
     * The radio technology for this physical channel.
     */
    public int rat = 0;
    /**
     * The radio frequency info.
     */
    public android.hardware.radio.V1_4.RadioFrequencyInfo rfInfo = new android.hardware.radio.V1_4.RadioFrequencyInfo();
    /**
     * A list of data calls mapped to this physical channel. The context id must match the cid of
     * @1.4::SetupDataCallResult. An empty list means the physical channel has no data call mapped
     * to it.
     */
    public java.util.ArrayList<Integer> contextIds = new java.util.ArrayList<Integer>();
    /**
     * The physical cell identifier for this cell.
     *
     * In UTRAN, this value is primary scrambling code. The range is [0, 511].
     * Reference: 3GPP TS 25.213 section 5.2.2.
     *
     * In EUTRAN, this value is physical layer cell identity. The range is [0, 503].
     * Reference: 3GPP TS 36.211 section 6.11.
     *
     * In 5G RAN, this value is physical layer cell identity. The range is [0, 1008].
     * Reference: 3GPP TS 38.211 section 7.4.2.1.
     */
    public int physicalCellId = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.PhysicalChannelConfig.class) {
            return false;
        }
        android.hardware.radio.V1_4.PhysicalChannelConfig other = (android.hardware.radio.V1_4.PhysicalChannelConfig)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.base, other.base)) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.rfInfo, other.rfInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.contextIds, other.contextIds)) {
            return false;
        }
        if (this.physicalCellId != other.physicalCellId) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.base), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.rfInfo), 
                android.os.HidlSupport.deepHashCode(this.contextIds), 
                android.os.HidlSupport.deepHashCode(this.physicalCellId));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".base = ");
        builder.append(this.base);
        builder.append(", .rat = ");
        builder.append(android.hardware.radio.V1_4.RadioTechnology.toString(this.rat));
        builder.append(", .rfInfo = ");
        builder.append(this.rfInfo);
        builder.append(", .contextIds = ");
        builder.append(this.contextIds);
        builder.append(", .physicalCellId = ");
        builder.append(this.physicalCellId);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhysicalChannelConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhysicalChannelConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.PhysicalChannelConfig _hidl_vec_element = new android.hardware.radio.V1_4.PhysicalChannelConfig();
                ((android.hardware.radio.V1_4.PhysicalChannelConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_2.PhysicalChannelConfig) base).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 8);
        ((android.hardware.radio.V1_4.RadioFrequencyInfo) rfInfo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 12);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) contextIds).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) contextIds).add(_hidl_vec_element);
            }
        }
        physicalCellId = _hidl_blob.getInt32(_hidl_offset + 40);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhysicalChannelConfig> _hidl_vec) {
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
        base.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putInt32(_hidl_offset + 8, rat);
        rfInfo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 12);
        {
            int _hidl_vec_size = contextIds.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, contextIds.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 40, physicalCellId);
    }
};

