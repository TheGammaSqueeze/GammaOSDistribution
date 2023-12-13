package android.hardware.audio.common.V2_0;


public final class AudioConfig {
    public int sampleRateHz = 0;
    public int channelMask = 0;
    public int format = 0;
    public android.hardware.audio.common.V2_0.AudioOffloadInfo offloadInfo = new android.hardware.audio.common.V2_0.AudioOffloadInfo();
    public long frameCount = 0L;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioConfig.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioConfig other = (android.hardware.audio.common.V2_0.AudioConfig)otherObject;
        if (this.sampleRateHz != other.sampleRateHz) {
            return false;
        }
        if (this.channelMask != other.channelMask) {
            return false;
        }
        if (this.format != other.format) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.offloadInfo, other.offloadInfo)) {
            return false;
        }
        if (this.frameCount != other.frameCount) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.sampleRateHz), 
                android.os.HidlSupport.deepHashCode(this.channelMask), 
                android.os.HidlSupport.deepHashCode(this.format), 
                android.os.HidlSupport.deepHashCode(this.offloadInfo), 
                android.os.HidlSupport.deepHashCode(this.frameCount));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".sampleRateHz = ");
        builder.append(this.sampleRateHz);
        builder.append(", .channelMask = ");
        builder.append(android.hardware.audio.common.V2_0.AudioChannelMask.toString(this.channelMask));
        builder.append(", .format = ");
        builder.append(android.hardware.audio.common.V2_0.AudioFormat.toString(this.format));
        builder.append(", .offloadInfo = ");
        builder.append(this.offloadInfo);
        builder.append(", .frameCount = ");
        builder.append(this.frameCount);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 72,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioConfig _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioConfig();
                ((android.hardware.audio.common.V2_0.AudioConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        sampleRateHz = _hidl_blob.getInt32(_hidl_offset + 0);
        channelMask = _hidl_blob.getInt32(_hidl_offset + 4);
        format = _hidl_blob.getInt32(_hidl_offset + 8);
        ((android.hardware.audio.common.V2_0.AudioOffloadInfo) offloadInfo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
        frameCount = _hidl_blob.getInt64(_hidl_offset + 64);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioConfig> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, sampleRateHz);
        _hidl_blob.putInt32(_hidl_offset + 4, channelMask);
        _hidl_blob.putInt32(_hidl_offset + 8, format);
        offloadInfo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
        _hidl_blob.putInt64(_hidl_offset + 64, frameCount);
    }
};

