/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;

/**
 * {@hide}
 */
public final class AudioPortExt implements android.os.Parcelable {
  // tags for union fields
  public final static int unspecified = 0;  // boolean unspecified;
  public final static int device = 1;  // android.media.AudioPortDeviceExt device;
  public final static int mix = 2;  // android.media.AudioPortMixExt mix;
  public final static int session = 3;  // android.media.AudioPortSessionExt session;

  private int _tag;
  private Object _value;

  public AudioPortExt() {
    boolean _value = false;
    this._tag = unspecified;
    this._value = _value;
  }

  private AudioPortExt(android.os.Parcel _aidl_parcel) {
    readFromParcel(_aidl_parcel);
  }

  private AudioPortExt(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }

  public int getTag() {
    return _tag;
  }

  // boolean unspecified;

  /**
       * This represents an empty union. Value is ignored.
       * TODO(ytai): replace with the canonical representation for an empty union, as soon as it is
       *             established.
       */
  public static AudioPortExt unspecified(boolean _value) {
    return new AudioPortExt(unspecified, _value);
  }

  public boolean getUnspecified() {
    _assertTag(unspecified);
    return (boolean) _value;
  }

  public void setUnspecified(boolean _value) {
    _set(unspecified, _value);
  }

  // android.media.AudioPortDeviceExt device;

  /** Device specific info. */
  public static AudioPortExt device(android.media.AudioPortDeviceExt _value) {
    return new AudioPortExt(device, _value);
  }

  public android.media.AudioPortDeviceExt getDevice() {
    _assertTag(device);
    return (android.media.AudioPortDeviceExt) _value;
  }

  public void setDevice(android.media.AudioPortDeviceExt _value) {
    _set(device, _value);
  }

  // android.media.AudioPortMixExt mix;

  /** Mix specific info. */
  public static AudioPortExt mix(android.media.AudioPortMixExt _value) {
    return new AudioPortExt(mix, _value);
  }

  public android.media.AudioPortMixExt getMix() {
    _assertTag(mix);
    return (android.media.AudioPortMixExt) _value;
  }

  public void setMix(android.media.AudioPortMixExt _value) {
    _set(mix, _value);
  }

  // android.media.AudioPortSessionExt session;

  /** Session specific info. */
  public static AudioPortExt session(android.media.AudioPortSessionExt _value) {
    return new AudioPortExt(session, _value);
  }

  public android.media.AudioPortSessionExt getSession() {
    _assertTag(session);
    return (android.media.AudioPortSessionExt) _value;
  }

  public void setSession(android.media.AudioPortSessionExt _value) {
    _set(session, _value);
  }

  public static final android.os.Parcelable.Creator<AudioPortExt> CREATOR = new android.os.Parcelable.Creator<AudioPortExt>() {
    @Override
    public AudioPortExt createFromParcel(android.os.Parcel _aidl_source) {
      return new AudioPortExt(_aidl_source);
    }
    @Override
    public AudioPortExt[] newArray(int _aidl_size) {
      return new AudioPortExt[_aidl_size];
    }
  };

  @Override
  public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag) {
    _aidl_parcel.writeInt(_tag);
    switch (_tag) {
    case unspecified:
      _aidl_parcel.writeInt(((getUnspecified())?(1):(0)));
      break;
    case device:
      if ((getDevice()!=null)) {
        _aidl_parcel.writeInt(1);
        getDevice().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case mix:
      if ((getMix()!=null)) {
        _aidl_parcel.writeInt(1);
        getMix().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case session:
      if ((getSession()!=null)) {
        _aidl_parcel.writeInt(1);
        getSession().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    }
  }

  public void readFromParcel(android.os.Parcel _aidl_parcel) {
    int _aidl_tag;
    _aidl_tag = _aidl_parcel.readInt();
    switch (_aidl_tag) {
    case unspecified: {
      boolean _aidl_value;
      _aidl_value = (0!=_aidl_parcel.readInt());
      _set(_aidl_tag, _aidl_value);
      return; }
    case device: {
      android.media.AudioPortDeviceExt _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.AudioPortDeviceExt.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case mix: {
      android.media.AudioPortMixExt _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.AudioPortMixExt.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case session: {
      android.media.AudioPortSessionExt _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.AudioPortSessionExt.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    }
    throw new IllegalArgumentException("union: unknown tag: " + _aidl_tag);
  }

  @Override
  public int describeContents() {
    int _mask = 0;
    switch (getTag()) {
    case device:
      _mask |= describeContents(getDevice());
      break;
    case mix:
      _mask |= describeContents(getMix());
      break;
    case session:
      _mask |= describeContents(getSession());
      break;
    }
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }

  private void _assertTag(int tag) {
    if (getTag() != tag) {
      throw new IllegalStateException("bad access: " + _tagString(tag) + ", " + _tagString(getTag()) + " is available.");
    }
  }

  private String _tagString(int _tag) {
    switch (_tag) {
    case unspecified: return "unspecified";
    case device: return "device";
    case mix: return "mix";
    case session: return "session";
    }
    throw new IllegalStateException("unknown field: " + _tag);
  }

  private void _set(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }
}
