/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class Layer2InformationParcelable implements android.os.Parcelable
{
  public java.lang.String l2Key;
  public java.lang.String cluster;
  public android.net.MacAddress bssid;
  public static final android.os.Parcelable.Creator<Layer2InformationParcelable> CREATOR = new android.os.Parcelable.Creator<Layer2InformationParcelable>() {
    @Override
    public Layer2InformationParcelable createFromParcel(android.os.Parcel _aidl_source) {
      Layer2InformationParcelable _aidl_out = new Layer2InformationParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public Layer2InformationParcelable[] newArray(int _aidl_size) {
      return new Layer2InformationParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(l2Key);
    _aidl_parcel.writeString(cluster);
    if ((bssid!=null)) {
      _aidl_parcel.writeInt(1);
      bssid.writeToParcel(_aidl_parcel, 0);
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
      l2Key = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      cluster = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        bssid = android.net.MacAddress.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        bssid = null;
      }
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
    _aidl_sj.add("l2Key: " + (java.util.Objects.toString(l2Key)));
    _aidl_sj.add("cluster: " + (java.util.Objects.toString(cluster)));
    _aidl_sj.add("bssid: " + (java.util.Objects.toString(bssid)));
    return "android.net.Layer2InformationParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(bssid);
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
