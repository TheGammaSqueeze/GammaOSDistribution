/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class ScanResultInfoParcelable implements android.os.Parcelable
{
  public java.lang.String ssid;
  public java.lang.String bssid;
  public android.net.InformationElementParcelable[] informationElements;
  public static final android.os.Parcelable.Creator<ScanResultInfoParcelable> CREATOR = new android.os.Parcelable.Creator<ScanResultInfoParcelable>() {
    @Override
    public ScanResultInfoParcelable createFromParcel(android.os.Parcel _aidl_source) {
      ScanResultInfoParcelable _aidl_out = new ScanResultInfoParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ScanResultInfoParcelable[] newArray(int _aidl_size) {
      return new ScanResultInfoParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(ssid);
    _aidl_parcel.writeString(bssid);
    _aidl_parcel.writeTypedArray(informationElements, 0);
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
      ssid = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bssid = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      informationElements = _aidl_parcel.createTypedArray(android.net.InformationElementParcelable.CREATOR);
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public String toString() {
    java.util.StringJoiner _aidl_sj = new java.util.StringJoiner(", ", "{", "}");
    _aidl_sj.add("ssid: " + (java.util.Objects.toString(ssid)));
    _aidl_sj.add("bssid: " + (java.util.Objects.toString(bssid)));
    _aidl_sj.add("informationElements: " + (java.util.Arrays.toString(informationElements)));
    return "android.net.ScanResultInfoParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(informationElements);
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
