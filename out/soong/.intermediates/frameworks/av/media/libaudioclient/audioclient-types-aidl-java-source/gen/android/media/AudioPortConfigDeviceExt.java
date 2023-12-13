/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioPortConfigDeviceExt implements android.os.Parcelable
{
  /**
       * Module the device is attached to.
       * Interpreted as audio_module_handle_t.
       */
  public int hwModule = 0;
  /**
       * Device type (e.g AUDIO_DEVICE_OUT_SPEAKER).
       * Interpreted as audio_devices_t.
       * TODO: Convert to a standalone AIDL representation.
       */
  public int type = 0;
  /** Device address. "" if N/A. */
  public java.lang.String address;
  public static final android.os.Parcelable.Creator<AudioPortConfigDeviceExt> CREATOR = new android.os.Parcelable.Creator<AudioPortConfigDeviceExt>() {
    @Override
    public AudioPortConfigDeviceExt createFromParcel(android.os.Parcel _aidl_source) {
      AudioPortConfigDeviceExt _aidl_out = new AudioPortConfigDeviceExt();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPortConfigDeviceExt[] newArray(int _aidl_size) {
      return new AudioPortConfigDeviceExt[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(hwModule);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeString(address);
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
      hwModule = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      address = _aidl_parcel.readString();
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
