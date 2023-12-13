/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioProfile implements android.os.Parcelable
{
  public java.lang.String name;
  /** The format for an audio profile should only be set when initialized. */
  public int format;
  /** Interpreted as audio_channel_mask_t. */
  public int[] channelMasks;
  public int[] samplingRates;
  public boolean isDynamicFormat = false;
  public boolean isDynamicChannels = false;
  public boolean isDynamicRate = false;
  public int encapsulationType;
  public static final android.os.Parcelable.Creator<AudioProfile> CREATOR = new android.os.Parcelable.Creator<AudioProfile>() {
    @Override
    public AudioProfile createFromParcel(android.os.Parcel _aidl_source) {
      AudioProfile _aidl_out = new AudioProfile();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioProfile[] newArray(int _aidl_size) {
      return new AudioProfile[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(name);
    _aidl_parcel.writeInt(format);
    _aidl_parcel.writeIntArray(channelMasks);
    _aidl_parcel.writeIntArray(samplingRates);
    _aidl_parcel.writeInt(((isDynamicFormat)?(1):(0)));
    _aidl_parcel.writeInt(((isDynamicChannels)?(1):(0)));
    _aidl_parcel.writeInt(((isDynamicRate)?(1):(0)));
    _aidl_parcel.writeInt(encapsulationType);
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
      name = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      format = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      channelMasks = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      samplingRates = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isDynamicFormat = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isDynamicChannels = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isDynamicRate = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      encapsulationType = _aidl_parcel.readInt();
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
