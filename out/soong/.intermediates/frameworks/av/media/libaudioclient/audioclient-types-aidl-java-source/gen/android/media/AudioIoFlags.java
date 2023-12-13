/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;

/**
 * {@hide}
 */
public final class AudioIoFlags implements android.os.Parcelable {
  // tags for union fields
  public final static int input = 0;  // int input;
  public final static int output = 1;  // int output;

  private int _tag;
  private Object _value;

  public AudioIoFlags() {
    int _value = 0;
    this._tag = input;
    this._value = _value;
  }

  private AudioIoFlags(android.os.Parcel _aidl_parcel) {
    readFromParcel(_aidl_parcel);
  }

  private AudioIoFlags(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }

  public int getTag() {
    return _tag;
  }

  // int input;

  /** Bitmask indexed by AudioInputFlags. */
  public static AudioIoFlags input(int _value) {
    return new AudioIoFlags(input, _value);
  }

  public int getInput() {
    _assertTag(input);
    return (int) _value;
  }

  public void setInput(int _value) {
    _set(input, _value);
  }

  // int output;

  /** Bitmask indexed by AudioOutputFlags. */
  public static AudioIoFlags output(int _value) {
    return new AudioIoFlags(output, _value);
  }

  public int getOutput() {
    _assertTag(output);
    return (int) _value;
  }

  public void setOutput(int _value) {
    _set(output, _value);
  }

  public static final android.os.Parcelable.Creator<AudioIoFlags> CREATOR = new android.os.Parcelable.Creator<AudioIoFlags>() {
    @Override
    public AudioIoFlags createFromParcel(android.os.Parcel _aidl_source) {
      return new AudioIoFlags(_aidl_source);
    }
    @Override
    public AudioIoFlags[] newArray(int _aidl_size) {
      return new AudioIoFlags[_aidl_size];
    }
  };

  @Override
  public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag) {
    _aidl_parcel.writeInt(_tag);
    switch (_tag) {
    case input:
      _aidl_parcel.writeInt(getInput());
      break;
    case output:
      _aidl_parcel.writeInt(getOutput());
      break;
    }
  }

  public void readFromParcel(android.os.Parcel _aidl_parcel) {
    int _aidl_tag;
    _aidl_tag = _aidl_parcel.readInt();
    switch (_aidl_tag) {
    case input: {
      int _aidl_value;
      _aidl_value = _aidl_parcel.readInt();
      _set(_aidl_tag, _aidl_value);
      return; }
    case output: {
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
    case input: return "input";
    case output: return "output";
    }
    throw new IllegalStateException("unknown field: " + _tag);
  }

  private void _set(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }
}
