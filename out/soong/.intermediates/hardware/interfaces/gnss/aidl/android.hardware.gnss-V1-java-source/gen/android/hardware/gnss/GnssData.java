/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.gnss;
public class GnssData implements android.os.Parcelable
{
  public android.hardware.gnss.GnssMeasurement[] measurements;
  public android.hardware.gnss.GnssClock clock;
  public android.hardware.gnss.ElapsedRealtime elapsedRealtime;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<GnssData> CREATOR = new android.os.Parcelable.Creator<GnssData>() {
    @Override
    public GnssData createFromParcel(android.os.Parcel _aidl_source) {
      GnssData _aidl_out = new GnssData();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public GnssData[] newArray(int _aidl_size) {
      return new GnssData[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeTypedArray(measurements, 0);
    if ((clock!=null)) {
      _aidl_parcel.writeInt(1);
      clock.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((elapsedRealtime!=null)) {
      _aidl_parcel.writeInt(1);
      elapsedRealtime.writeToParcel(_aidl_parcel, 0);
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
      measurements = _aidl_parcel.createTypedArray(android.hardware.gnss.GnssMeasurement.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        clock = android.hardware.gnss.GnssClock.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        clock = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        elapsedRealtime = android.hardware.gnss.ElapsedRealtime.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        elapsedRealtime = null;
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
    _mask |= describeContents(measurements);
    _mask |= describeContents(clock);
    _mask |= describeContents(elapsedRealtime);
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
