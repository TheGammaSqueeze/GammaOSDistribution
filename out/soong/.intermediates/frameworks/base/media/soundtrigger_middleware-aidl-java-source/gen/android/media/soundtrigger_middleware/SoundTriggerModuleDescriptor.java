/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * A descriptor of an available sound trigger module, containing the handle used to reference the
 * module, as well its capabilities.
 * {@hide}
 */
public class SoundTriggerModuleDescriptor implements android.os.Parcelable
{
  /** Module handle to be used for attaching to it. */
  public int handle = 0;
  /** Module capabilities. */
  public android.media.soundtrigger_middleware.SoundTriggerModuleProperties properties;
  public static final android.os.Parcelable.Creator<SoundTriggerModuleDescriptor> CREATOR = new android.os.Parcelable.Creator<SoundTriggerModuleDescriptor>() {
    @Override
    public SoundTriggerModuleDescriptor createFromParcel(android.os.Parcel _aidl_source) {
      SoundTriggerModuleDescriptor _aidl_out = new SoundTriggerModuleDescriptor();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SoundTriggerModuleDescriptor[] newArray(int _aidl_size) {
      return new SoundTriggerModuleDescriptor[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(handle);
    if ((properties!=null)) {
      _aidl_parcel.writeInt(1);
      properties.writeToParcel(_aidl_parcel, 0);
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
      handle = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        properties = android.media.soundtrigger_middleware.SoundTriggerModuleProperties.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        properties = null;
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
    _mask |= describeContents(properties);
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
