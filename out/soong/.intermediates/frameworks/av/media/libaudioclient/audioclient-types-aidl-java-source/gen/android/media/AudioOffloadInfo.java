/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioOffloadInfo implements android.os.Parcelable
{
  /** Version of the info structure. Interpreted as a uint16_t version constant. */
  public int version = 0;
  /** Audio configuration. */
  public android.media.AudioConfigBase config;
  /** Stream type. */
  public int streamType;
  /** Bit rate in bits per second. */
  public int bitRate = 0;
  /** Duration in microseconds, -1 if unknown. */
  public long durationUs = 0L;
  /** true if stream is tied to a video stream. */
  public boolean hasVideo = false;
  /** true if streaming, false if local playback. */
  public boolean isStreaming = false;
  public int bitWidth = 0;
  /** Offload fragment size. */
  public int offloadBufferSize = 0;
  public int usage;
  public int encapsulationMode;
  /** Content id from tuner HAL (0 if none). */
  public int contentId = 0;
  /** Sync id from tuner HAL (0 if none). */
  public int syncId = 0;
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
    _aidl_parcel.writeInt(version);
    if ((config!=null)) {
      _aidl_parcel.writeInt(1);
      config.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(streamType);
    _aidl_parcel.writeInt(bitRate);
    _aidl_parcel.writeLong(durationUs);
    _aidl_parcel.writeInt(((hasVideo)?(1):(0)));
    _aidl_parcel.writeInt(((isStreaming)?(1):(0)));
    _aidl_parcel.writeInt(bitWidth);
    _aidl_parcel.writeInt(offloadBufferSize);
    _aidl_parcel.writeInt(usage);
    _aidl_parcel.writeInt(encapsulationMode);
    _aidl_parcel.writeInt(contentId);
    _aidl_parcel.writeInt(syncId);
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
      version = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        config = android.media.AudioConfigBase.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        config = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      streamType = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bitRate = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      durationUs = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hasVideo = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isStreaming = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bitWidth = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      offloadBufferSize = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      usage = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      encapsulationMode = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      contentId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      syncId = _aidl_parcel.readInt();
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
    _mask |= describeContents(config);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
