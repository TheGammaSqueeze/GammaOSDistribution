/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.audio.common;
/**
 * Additional information about the stream passed to hardware decoders.
 *
 * {@hide}
 */
public class AudioOffloadInfo implements android.os.Parcelable
{
  public int sampleRateHz = 0;
  public int channelMask = 0;
  public int format;
  public int streamType;
  public int bitRatePerSecond = 0;
  public long durationMicroseconds = 0L;
  public boolean hasVideo = false;
  public boolean isStreaming = false;
  public int bitWidth = 0;
  public int bufferSize = 0;
  public int usage;
  public static final android.os.Parcelable.Creator<AudioOffloadInfo> CREATOR = new android.os.Parcelable.Creator<AudioOffloadInfo>() {
    @Override
    public AudioOffloadInfo createFromParcel(android.os.Parcel _aidl_source) {
      AudioOffloadInfo _aidl_out = new AudioOffloadInfo();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioOffloadInfo[] newArray(int _aidl_size) {
      return new AudioOffloadInfo[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(sampleRateHz);
    _aidl_parcel.writeInt(channelMask);
    _aidl_parcel.writeInt(format);
    _aidl_parcel.writeInt(streamType);
    _aidl_parcel.writeInt(bitRatePerSecond);
    _aidl_parcel.writeLong(durationMicroseconds);
    _aidl_parcel.writeInt(((hasVideo)?(1):(0)));
    _aidl_parcel.writeInt(((isStreaming)?(1):(0)));
    _aidl_parcel.writeInt(bitWidth);
    _aidl_parcel.writeInt(bufferSize);
    _aidl_parcel.writeInt(usage);
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public final void readFromParcel(android.os.Parcel _aidl_parcel)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return;
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sampleRateHz = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      channelMask = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      format = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      streamType = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bitRatePerSecond = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      durationMicroseconds = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hasVideo = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isStreaming = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bitWidth = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bufferSize = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      usage = _aidl_parcel.readInt();
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
