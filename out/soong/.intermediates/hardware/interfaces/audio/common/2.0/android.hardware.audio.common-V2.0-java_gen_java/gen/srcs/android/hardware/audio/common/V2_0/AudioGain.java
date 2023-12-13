package android.hardware.audio.common.V2_0;


public final class AudioGain {
    public int mode = 0;
    public int channelMask = 0;
    public int minValue = 0;
    public int maxValue = 0;
    public int defaultValue = 0;
    public int stepValue = 0;
    public int minRampMs = 0;
    public int maxRampMs = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioGain.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioGain other = (android.hardware.audio.common.V2_0.AudioGain)otherObject;
        if (this.mode != other.mode) {
            return false;
        }
        if (this.channelMask != other.channelMask) {
            return false;
        }
        if (this.minValue != other.minValue) {
            return false;
        }
        if (this.maxValue != other.maxValue) {
            return false;
        }
        if (this.defaultValue != other.defaultValue) {
            return false;
        }
        if (this.stepValue != other.stepValue) {
            return false;
        }
        if (this.minRampMs != other.minRampMs) {
            return false;
        }
        if (this.maxRampMs != other.maxRampMs) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.mode), 
                android.os.HidlSupport.deepHashCode(this.channelMask), 
                android.os.HidlSupport.deepHashCode(this.minValue), 
                android.os.HidlSupport.deepHashCode(this.maxValue), 
                android.os.HidlSupport.deepHashCode(this.defaultValue), 
                android.os.HidlSupport.deepHashCode(this.stepValue), 
                android.os.HidlSupport.deepHashCode(this.minRampMs), 
                android.os.HidlSupport.deepHashCode(this.maxRampMs));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".mode = ");
        builder.append(android.hardware.audio.common.V2_0.AudioGainMode.toString(this.mode));
        builder.append(", .channelMask = ");
        builder.append(android.hardware.audio.common.V2_0.AudioChannelMask.toString(this.channelMask));
        builder.append(", .minValue = ");
        builder.append(this.minValue);
        builder.append(", .maxValue = ");
        builder.append(this.maxValue);
        builder.append(", .defaultValue = ");
        builder.append(this.defaultValue);
        builder.append(", .stepValue = ");
        builder.append(this.stepValue);
        builder.append(", .minRampMs = ");
        builder.append(this.minRampMs);
        builder.append(", .maxRampMs = ");
        builder.append(this.maxRampMs);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioGain> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioGain> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioGain _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioGain();
                ((android.hardware.audio.common.V2_0.AudioGain) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        mode = _hidl_blob.getInt32(_hidl_offset + 0);
        channelMask = _hidl_blob.getInt32(_hidl_offset + 4);
        minValue = _hidl_blob.getInt32(_hidl_offset + 8);
        maxValue = _hidl_blob.getInt32(_hidl_offset + 12);
        defaultValue = _hidl_blob.getInt32(_hidl_offset + 16);
        stepValue = _hidl_blob.getInt32(_hidl_offset + 20);
        minRampMs = _hidl_blob.getInt32(_hidl_offset + 24);
        maxRampMs = _hidl_blob.getInt32(_hidl_offset + 28);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioGain> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, mode);
        _hidl_blob.putInt32(_hidl_offset + 4, channelMask);
        _hidl_blob.putInt32(_hidl_offset + 8, minValue);
        _hidl_blob.putInt32(_hidl_offset + 12, maxValue);
        _hidl_blob.putInt32(_hidl_offset + 16, defaultValue);
        _hidl_blob.putInt32(_hidl_offset + 20, stepValue);
        _hidl_blob.putInt32(_hidl_offset + 24, minRampMs);
        _hidl_blob.putInt32(_hidl_offset + 28, maxRampMs);
    }
};

