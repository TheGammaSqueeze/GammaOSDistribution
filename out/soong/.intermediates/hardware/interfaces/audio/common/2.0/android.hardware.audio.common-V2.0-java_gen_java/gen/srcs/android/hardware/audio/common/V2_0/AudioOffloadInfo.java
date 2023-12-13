package android.hardware.audio.common.V2_0;


public final class AudioOffloadInfo {
    public int sampleRateHz = 0;
    public int channelMask = 0;
    public int format = 0;
    public int streamType = 0;
    public int bitRatePerSecond = 0;
    public long durationMicroseconds = 0L;
    public boolean hasVideo = false;
    public boolean isStreaming = false;
    public int bitWidth = 0;
    public int bufferSize = 0;
    public int usage = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.audio.common.V2_0.AudioOffloadInfo.class) {
            return false;
        }
        android.hardware.audio.common.V2_0.AudioOffloadInfo other = (android.hardware.audio.common.V2_0.AudioOffloadInfo)otherObject;
        if (this.sampleRateHz != other.sampleRateHz) {
            return false;
        }
        if (this.channelMask != other.channelMask) {
            return false;
        }
        if (this.format != other.format) {
            return false;
        }
        if (this.streamType != other.streamType) {
            return false;
        }
        if (this.bitRatePerSecond != other.bitRatePerSecond) {
            return false;
        }
        if (this.durationMicroseconds != other.durationMicroseconds) {
            return false;
        }
        if (this.hasVideo != other.hasVideo) {
            return false;
        }
        if (this.isStreaming != other.isStreaming) {
            return false;
        }
        if (this.bitWidth != other.bitWidth) {
            return false;
        }
        if (this.bufferSize != other.bufferSize) {
            return false;
        }
        if (this.usage != other.usage) {
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
                android.os.HidlSupport.deepHashCode(this.streamType), 
                android.os.HidlSupport.deepHashCode(this.bitRatePerSecond), 
                android.os.HidlSupport.deepHashCode(this.durationMicroseconds), 
                android.os.HidlSupport.deepHashCode(this.hasVideo), 
                android.os.HidlSupport.deepHashCode(this.isStreaming), 
                android.os.HidlSupport.deepHashCode(this.bitWidth), 
                android.os.HidlSupport.deepHashCode(this.bufferSize), 
                android.os.HidlSupport.deepHashCode(this.usage));
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
        builder.append(", .streamType = ");
        builder.append(android.hardware.audio.common.V2_0.AudioStreamType.toString(this.streamType));
        builder.append(", .bitRatePerSecond = ");
        builder.append(this.bitRatePerSecond);
        builder.append(", .durationMicroseconds = ");
        builder.append(this.durationMicroseconds);
        builder.append(", .hasVideo = ");
        builder.append(this.hasVideo);
        builder.append(", .isStreaming = ");
        builder.append(this.isStreaming);
        builder.append(", .bitWidth = ");
        builder.append(this.bitWidth);
        builder.append(", .bufferSize = ");
        builder.append(this.bufferSize);
        builder.append(", .usage = ");
        builder.append(android.hardware.audio.common.V2_0.AudioUsage.toString(this.usage));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AudioOffloadInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AudioOffloadInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.audio.common.V2_0.AudioOffloadInfo _hidl_vec_element = new android.hardware.audio.common.V2_0.AudioOffloadInfo();
                ((android.hardware.audio.common.V2_0.AudioOffloadInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
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
        streamType = _hidl_blob.getInt32(_hidl_offset + 12);
        bitRatePerSecond = _hidl_blob.getInt32(_hidl_offset + 16);
        durationMicroseconds = _hidl_blob.getInt64(_hidl_offset + 24);
        hasVideo = _hidl_blob.getBool(_hidl_offset + 32);
        isStreaming = _hidl_blob.getBool(_hidl_offset + 33);
        bitWidth = _hidl_blob.getInt32(_hidl_offset + 36);
        bufferSize = _hidl_blob.getInt32(_hidl_offset + 40);
        usage = _hidl_blob.getInt32(_hidl_offset + 44);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AudioOffloadInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, sampleRateHz);
        _hidl_blob.putInt32(_hidl_offset + 4, channelMask);
        _hidl_blob.putInt32(_hidl_offset + 8, format);
        _hidl_blob.putInt32(_hidl_offset + 12, streamType);
        _hidl_blob.putInt32(_hidl_offset + 16, bitRatePerSecond);
        _hidl_blob.putInt64(_hidl_offset + 24, durationMicroseconds);
        _hidl_blob.putBool(_hidl_offset + 32, hasVideo);
        _hidl_blob.putBool(_hidl_offset + 33, isStreaming);
        _hidl_blob.putInt32(_hidl_offset + 36, bitWidth);
        _hidl_blob.putInt32(_hidl_offset + 40, bufferSize);
        _hidl_blob.putInt32(_hidl_offset + 44, usage);
    }
};

