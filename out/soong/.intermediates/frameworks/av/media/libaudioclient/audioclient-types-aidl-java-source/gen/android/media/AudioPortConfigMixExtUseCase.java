/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;

/**
 * {@hide}
 */
public final class AudioPortConfigMixExtUseCase implements android.os.Parcelable {
  // tags for union fields
  public final static int unspecified = 0;  // boolean unspecified;
  public final static int stream = 1;  // android.media.AudioStreamType stream;
  public final static int source = 2;  // android.media.AudioSourceType source;

  private int _tag;
  private Object _value;

  public AudioPortConfigMixExtUseCase() {
    boolean _value = false;
    this._tag = unspecified;
    this._value = _value;
  }

  private AudioPortConfigMixExtUseCase(android.os.Parcel _aidl_parcel) {
    readFromParcel(_aidl_parcel);
  }

  private AudioPortConfigMixExtUseCase(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }

  public int getTag() {
    return _tag;
  }

  // boolean unspecified;

  /**
       * This to be set if the containing config has the AudioPortRole::NONE role.
       * This represents an empty value (value is ignored).
       * TODO(ytai): replace with the canonical representation for an empty union, as soon as it is
       *             established.
       */
  public static AudioPortConfigMixExtUseCase unspecified(boolean _value) {
    return new AudioPortConfigMixExtUseCase(unspecified, _value);
  }

  public boolean getUnspecified() {
    _assertTag(unspecified);
    return (boolean) _value;
  }

  public void setUnspecified(boolean _value) {
    _set(unspecified, _value);
  }

  // android.media.AudioStreamType stream;

  /** This to be set if the containing config has the AudioPortRole::SOURCE role. */
  public static AudioPortConfigMixExtUseCase stream(int _value) {
    return new AudioPortConfigMixExtUseCase(stream, _value);
  }

  public int getStream() {
    _assertTag(stream);
    return (int) _value;
  }

  public void setStream(int _value) {
    _set(stream, _value);
  }

  // android.media.AudioSourceType source;

  /** This to be set if the containing config has the AudioPortRole::SINK role. */
  public static AudioPortConfigMixExtUseCase source(int _value) {
    return new AudioPortConfigMixExtUseCase(source, _value);
  }

  public int getSource() {
    _assertTag(source);
    return (int) _value;
  }

  public void setSource(int _value) {
    _set(source, _value);
  }

  public static final android.os.Parcelable.Creator<AudioPortConfigMixExtUseCase> CREATOR = new android.os.Parcelable.Creator<AudioPortConfigMixExtUseCase>() {
    @Override
    public AudioPortConfigMixExtUseCase createFromParcel(android.os.Parcel _aidl_source) {
      return new AudioPortConfigMixExtUseCase(_aidl_source);
    }
    @Override
    public AudioPortConfigMixExtUseCase[] newArray(int _aidl_size) {
      return new AudioPortConfigMixExtUseCase[_aidl_size];
    }
  };

  @Override
  public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag) {
    _aidl_parcel.writeInt(_tag);
    switch (_tag) {
    case unspecified:
      _aidl_parcel.writeInt(((getUnspecified())?(1):(0)));
      break;
    case stream:
      _aidl_parcel.writeInt(getStream());
      break;
    case source:
      _aidl_parcel.writeInt(getSource());
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
    case stream: {
      int _aidl_value;
      _aidl_value = _aidl_parcel.readInt();
      _set(_aidl_tag, _aidl_value);
      return; }
    case source: {
      int _aidl_value;
      _aidl_value = _aidl_parcel.readInt();
      _set(_aidl_tag, _aidl_value);
      return; }
    }
    throw new IllegalArgumentException("union: unknown tag: " + _aidl_tag);
  }

  @Override
  public int describeContents() {
    int _mask = 0;
    switch (getTag()) {
    }
    return _mask;
  }

  private void _assertTag(int tag) {
    if (getTag() != tag) {
      throw new IllegalStateException("bad access: " + _tagString(tag) + ", " + _tagString(getTag()) + " is available.");
    }
  }

  private String _tagString(int _tag) {
    switch (_tag) {
    case unspecified: return "unspecified";
    case stream: return "stream";
    case source: return "source";
    }
    throw new IllegalStateException("unknown field: " + _tag);
  }

  private void _set(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }
}
