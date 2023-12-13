/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.gnss;
public class SatellitePvt implements android.os.Parcelable
{
  public int flags = 0;
  public android.hardware.gnss.SatellitePositionEcef satPosEcef;
  public android.hardware.gnss.SatelliteVelocityEcef satVelEcef;
  public android.hardware.gnss.SatelliteClockInfo satClockInfo;
  public double ionoDelayMeters = 0.000000;
  public double tropoDelayMeters = 0.000000;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<SatellitePvt> CREATOR = new android.os.Parcelable.Creator<SatellitePvt>() {
    @Override
    public SatellitePvt createFromParcel(android.os.Parcel _aidl_source) {
      SatellitePvt _aidl_out = new SatellitePvt();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SatellitePvt[] newArray(int _aidl_size) {
      return new SatellitePvt[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(flags);
    if ((satPosEcef!=null)) {
      _aidl_parcel.writeInt(1);
      satPosEcef.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((satVelEcef!=null)) {
      _aidl_parcel.writeInt(1);
      satVelEcef.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((satClockInfo!=null)) {
      _aidl_parcel.writeInt(1);
      satClockInfo.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeDouble(ionoDelayMeters);
    _aidl_parcel.writeDouble(tropoDelayMeters);
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
      flags = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        satPosEcef = android.hardware.gnss.SatellitePositionEcef.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        satPosEcef = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        satVelEcef = android.hardware.gnss.SatelliteVelocityEcef.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        satVelEcef = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        satClockInfo = android.hardware.gnss.SatelliteClockInfo.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        satClockInfo = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ionoDelayMeters = _aidl_parcel.readDouble();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tropoDelayMeters = _aidl_parcel.readDouble();
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  public static final int HAS_POSITION_VELOCITY_CLOCK_INFO = 1;
  public static final int HAS_IONO = 2;
  public static final int HAS_TROPO = 4;
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(satPosEcef);
    _mask |= describeContents(satVelEcef);
    _mask |= describeContents(satClockInfo);
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
