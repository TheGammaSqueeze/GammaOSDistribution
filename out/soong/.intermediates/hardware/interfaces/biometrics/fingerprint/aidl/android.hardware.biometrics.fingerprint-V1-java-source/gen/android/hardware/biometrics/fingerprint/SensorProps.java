/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.biometrics.fingerprint;
public class SensorProps implements android.os.Parcelable
{
  public android.hardware.biometrics.common.CommonProps commonProps;
  public byte sensorType = android.hardware.biometrics.fingerprint.FingerprintSensorType.UNKNOWN;
  public android.hardware.biometrics.fingerprint.SensorLocation[] sensorLocations;
  public boolean supportsNavigationGestures = false;
  public boolean supportsDetectInteraction = false;
  public boolean halHandlesDisplayTouches = false;
  public boolean halControlsIllumination = false;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<SensorProps> CREATOR = new android.os.Parcelable.Creator<SensorProps>() {
    @Override
    public SensorProps createFromParcel(android.os.Parcel _aidl_source) {
      SensorProps _aidl_out = new SensorProps();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SensorProps[] newArray(int _aidl_size) {
      return new SensorProps[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((commonProps!=null)) {
      _aidl_parcel.writeInt(1);
      commonProps.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeByte(sensorType);
    _aidl_parcel.writeTypedArray(sensorLocations, 0);
    _aidl_parcel.writeInt(((supportsNavigationGestures)?(1):(0)));
    _aidl_parcel.writeInt(((supportsDetectInteraction)?(1):(0)));
    _aidl_parcel.writeInt(((halHandlesDisplayTouches)?(1):(0)));
    _aidl_parcel.writeInt(((halControlsIllumination)?(1):(0)));
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
      if ((0!=_aidl_parcel.readInt())) {
        commonProps = android.hardware.biometrics.common.CommonProps.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        commonProps = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sensorType = _aidl_parcel.readByte();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sensorLocations = _aidl_parcel.createTypedArray(android.hardware.biometrics.fingerprint.SensorLocation.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      supportsNavigationGestures = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      supportsDetectInteraction = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      halHandlesDisplayTouches = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      halControlsIllumination = (0!=_aidl_parcel.readInt());
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
    _mask |= describeContents(commonProps);
    _mask |= describeContents(sensorLocations);
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
