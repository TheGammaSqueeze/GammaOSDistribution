/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioPortConfig implements android.os.Parcelable
{
  /**
       * Port unique ID.
       * Interpreted as audio_port_handle_t.
       */
  public int id = 0;
  /** Sink or source. */
  public int role;
  /** Device, mix ... */
  public int type;
  /** Bitmask, indexed by AudioPortConfigType. */
  public int configMask = 0;
  /** Sampling rate in Hz. */
  public int sampleRate = 0;
  /**
       * Channel mask, if applicable.
       * Interpreted as audio_channel_mask_t.
       * TODO: bitmask?
       */
  public int channelMask = 0;
  /**
       * Format, if applicable.
       */
  public int format;
  /** Gain to apply, if applicable. */
  public android.media.AudioGainConfig gain;
  /** Framework only: HW_AV_SYNC, DIRECT, ... */
  public android.media.AudioIoFlags flags;
  public android.media.AudioPortConfigExt ext;
  public static final android.os.Parcelable.Creator<AudioPortConfig> CREATOR = new android.os.Parcelable.Creator<AudioPortConfig>() {
    @Override
    public AudioPortConfig createFromParcel(android.os.Parcel _aidl_source) {
      AudioPortConfig _aidl_out = new AudioPortConfig();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPortConfig[] newArray(int _aidl_size) {
      return new AudioPortConfig[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(id);
    _aidl_parcel.writeInt(role);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeInt(configMask);
    _aidl_parcel.writeInt(sampleRate);
    _aidl_parcel.writeInt(channelMask);
    _aidl_parcel.writeInt(format);
    if ((gain!=null)) {
      _aidl_parcel.writeInt(1);
      gain.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((flags!=null)) {
      _aidl_parcel.writeInt(1);
      flags.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((ext!=null)) {
      _aidl_parcel.writeInt(1);
      ext.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
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
      id = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      role = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      configMask = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sampleRate = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      channelMask = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      format = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        gain = android.media.AudioGainConfig.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        gain = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        flags = android.media.AudioIoFlags.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        flags = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        ext = android.media.AudioPortConfigExt.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        ext = null;
      }
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
    _mask |= describeContents(gain);
    _mask |= describeContents(flags);
    _mask |= describeContents(ext);
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
