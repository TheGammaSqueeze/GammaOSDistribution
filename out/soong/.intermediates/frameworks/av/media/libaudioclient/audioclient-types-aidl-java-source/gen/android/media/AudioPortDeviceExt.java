/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioPortDeviceExt implements android.os.Parcelable
{
  /** Module the device is attached to. Interpreted as audio_module_handle_t. */
  public int hwModule = 0;
  public android.media.AudioDevice device;
  /** Bitmask, indexed by AudioEncapsulationMode. */
  public int encapsulationModes = 0;
  /** Bitmask, indexed by AudioEncapsulationMetadataType. */
  public int encapsulationMetadataTypes = 0;
  public static final android.os.Parcelable.Creator<AudioPortDeviceExt> CREATOR = new android.os.Parcelable.Creator<AudioPortDeviceExt>() {
    @Override
    public AudioPortDeviceExt createFromParcel(android.os.Parcel _aidl_source) {
      AudioPortDeviceExt _aidl_out = new AudioPortDeviceExt();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPortDeviceExt[] newArray(int _aidl_size) {
      return new AudioPortDeviceExt[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(hwModule);
    if ((device!=null)) {
      _aidl_parcel.writeInt(1);
      device.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(encapsulationModes);
    _aidl_parcel.writeInt(encapsulationMetadataTypes);
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
      if ((0!=_aidl_parcel.readInt())) {
        device = android.media.AudioDevice.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        device = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      encapsulationModes = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      encapsulationMetadataTypes = _aidl_parcel.readInt();
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
    _mask |= describeContents(device);
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
