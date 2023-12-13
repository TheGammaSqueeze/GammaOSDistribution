package android.hardware.audio.common.V2_0;


public final class AudioGainConfig {
    public int index = 0;
    public int mode = 0;
    public int channelMask = 0;
    /**
     * 4 = sizeof(AudioChannelMask),
     * 8 is not "FCC_8", so it won't need to be changed for > 8 channels.
     * Gain values in millibels for each channel ordered from LSb to MSb in
     * channel mask. The number of values is 1 in joint mode or
     * popcount(channel_mask).
     */
    public int[/* 4 * 8 */] values = new int[32 /* 4 * 8 */];
    public int rampDurationMs = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioGainConfig.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioGainConfig other = (android.hardware.audio.common.V2_0.AudioGainConfig)otherObject;
        if (this.index != other.index) {
            return false;
        }
        if (this.mode != other.mode) {
            return false;
        }
        if (this.channelMask != other.channelMask) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.values, other.values)) {
            return false;
        }
        if (this.rampDurationMs != other.rampDurationMs) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.index), 
                android.os.HidlSupport.deepHashCode(this.mode), 
                android.os.HidlSupport.deepHashCode(this.channelMask), 
                android.os.HidlSupport.deepHashCode(this.values), 
                android.os.HidlSupport.deepHashCode(this.rampDurationMs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".index = ");
        builder.append(this.index);
        builder.append(", .mode = ");
        builder.append(android.hardware.audio.common.V2_0.AudioGainMode.toString(this.mode));
        builder.append(", .channelMask = ");
        builder.append(android.hardware.audio.common.V2_0.AudioChannelMask.toString(this.channelMask));
        builder.append(", .values = ");
        builder.append(java.util.Arrays.toString(this.values));
        builder.append(", .rampDurationMs = ");
        builder.append(this.rampDurationMs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(144 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioGainConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioGainConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 144,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioGainConfig _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioGainConfig();
                ((android.hardware.audio.common.V2_0.AudioGainConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 144);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        index = _hidl_blob.getInt32(_hidl_offset + 0);
        mode = _hidl_blob.getInt32(_hidl_offset + 4);
        channelMask = _hidl_blob.getInt32(_hidl_offset + 8);
        {
            long _hidl_array_offset_0 = _hidl_offset + 12;
            _hidl_blob.copyToInt32Array(_hidl_array_offset_0, (int[/* 4 * 8 */]) values, 32 /* 4 * 8 */ /* size */);
            _hidl_array_offset_0 += 32 /* 4 * 8 */ * 4;
        }
        rampDurationMs = _hidl_blob.getInt32(_hidl_offset + 140);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(144 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioGainConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 144));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 144);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, index);
        _hidl_blob.putInt32(_hidl_offset + 4, mode);
        _hidl_blob.putInt32(_hidl_offset + 8, channelMask);
        {
            long _hidl_array_offset_0 = _hidl_offset + 12;
            int[] _hidl_array_item_0 = (int[/* 4 * 8 */]) values;

            if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 32 /* 4 * 8 */) {
                throw new IllegalArgumentException("Array element is not of the expected length");
            }

            _hidl_blob.putInt32Array(_hidl_array_offset_0, _hidl_array_item_0);
            _hidl_array_offset_0 += 32 /* 4 * 8 */ * 4;
        }
        _hidl_blob.putInt32(_hidl_offset + 140, rampDurationMs);
    }
};

