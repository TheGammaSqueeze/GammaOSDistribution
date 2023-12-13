/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioPort implements android.os.Parcelable
{
  /** Port unique ID. Interpreted as audio_port_handle_t. */
  public int id = 0;
  /** Sink or source. */
  public int role;
  /** Device, mix ... */
  public int type;
  public java.lang.String name;
  /** AudioProfiles supported by this port (format, Rates, Channels). */
  public android.media.AudioProfile[] profiles;
  /**
       * ExtraAudioDescriptors supported by this port. The format is not unrecognized to the
       * platform. The audio capability is described by a hardware descriptor.
       */
  public android.media.ExtraAudioDescriptor[] extraAudioDescriptors;
  /** Gain controllers. */
  public android.media.AudioGain[] gains;
  /** Current audio port configuration. */
  public android.media.AudioPortConfig activeConfig;
  public android.media.AudioPortExt ext;
  public static final android.os.Parcelable.Creator<AudioPort> CREATOR = new android.os.Parcelable.Creator<AudioPort>() {
    @Override
    public AudioPort createFromParcel(android.os.Parcel _aidl_source) {
      AudioPort _aidl_out = new AudioPort();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPort[] newArray(int _aidl_size) {
      return new AudioPort[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(id);
    _aidl_parcel.writeInt(role);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeString(name);
    _aidl_parcel.writeTypedArray(profiles, 0);
    _aidl_parcel.writeTypedArray(extraAudioDescriptors, 0);
    _aidl_parcel.writeTypedArray(gains, 0);
    if ((activeConfig!=null)) {
      _aidl_parcel.writeInt(1);
      activeConfig.writeToParcel(_aidl_parcel, 0);
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
      name = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      profiles = _aidl_parcel.createTypedArray(android.media.AudioProfile.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      extraAudioDescriptors = _aidl_parcel.createTypedArray(android.media.ExtraAudioDescriptor.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      gains = _aidl_parcel.createTypedArray(android.media.AudioGain.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        activeConfig = android.media.AudioPortConfig.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        activeConfig = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        ext = android.media.AudioPortExt.CREATOR.createFromParcel(_aidl_parcel);
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
    _mask |= describeContents(profiles);
    _mask |= describeContents(extraAudioDescriptors);
    _mask |= describeContents(gains);
    _mask |= describeContents(activeConfig);
    _mask |= describeContents(ext);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    Class<?> _clazz = _v.getClass();
    if (_clazz.isArray() && _clazz.getComponentType() == Object.class) {
      int _mask = 0;
      for (Object o : (Object[]) _v) {
        _mask |= describeContents(o);
      }
      return _mask;
    }
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
