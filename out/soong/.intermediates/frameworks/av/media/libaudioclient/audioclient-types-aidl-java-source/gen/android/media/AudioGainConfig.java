/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioGainConfig implements android.os.Parcelable
{
  /** Index of the corresponding audio_gain in the audio_port gains[] table. */
  public int index = 0;
  /** Mode requested for this command. Bitfield indexed by AudioGainMode. */
  public int mode = 0;
  /**
       * Channels which gain value follows. N/A in joint mode.
       * Interpreted as audio_channel_mask_t.
       */
  public int channelMask = 0;
  /**
       * Gain values in millibels.
       * For each channel ordered from LSb to MSb in channel mask. The number of values is 1 in joint
       * mode, otherwise equals the number of bits implied by channelMask.
       */
  public int[] values;
  /** Ramp duration in ms. */
  public int rampDurationMs = 0;
  public static final android.os.Parcelable.Creator<AudioGainConfig> CREATOR = new android.os.Parcelable.Creator<AudioGainConfig>() {
    @Override
    public AudioGainConfig createFromParcel(android.os.Parcel _aidl_source) {
      AudioGainConfig _aidl_out = new AudioGainConfig();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioGainConfig[] newArray(int _aidl_size) {
      return new AudioGainConfig[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(index);
    _aidl_parcel.writeInt(mode);
    _aidl_parcel.writeInt(channelMask);
    _aidl_parcel.writeIntArray(values);
    _aidl_parcel.writeInt(rampDurationMs);
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
      index = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      mode = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      channelMask = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      values = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      rampDurationMs = _aidl_parcel.readInt();
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
