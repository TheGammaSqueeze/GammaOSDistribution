/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class DhcpResultsParcelable implements android.os.Parcelable
{
  public android.net.StaticIpConfiguration baseConfiguration;
  public int leaseDuration = 0;
  public int mtu = 0;
  public java.lang.String serverAddress;
  public java.lang.String vendorInfo;
  public java.lang.String serverHostName;
  public java.lang.String captivePortalApiUrl;
  public static final android.os.Parcelable.Creator<DhcpResultsParcelable> CREATOR = new android.os.Parcelable.Creator<DhcpResultsParcelable>() {
    @Override
    public DhcpResultsParcelable createFromParcel(android.os.Parcel _aidl_source) {
      DhcpResultsParcelable _aidl_out = new DhcpResultsParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public DhcpResultsParcelable[] newArray(int _aidl_size) {
      return new DhcpResultsParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((baseConfiguration!=null)) {
      _aidl_parcel.writeInt(1);
      baseConfiguration.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(leaseDuration);
    _aidl_parcel.writeInt(mtu);
    _aidl_parcel.writeString(serverAddress);
    _aidl_parcel.writeString(vendorInfo);
    _aidl_parcel.writeString(serverHostName);
    _aidl_parcel.writeString(captivePortalApiUrl);
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
        baseConfiguration = android.net.StaticIpConfiguration.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        baseConfiguration = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      leaseDuration = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      mtu = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      serverAddress = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      vendorInfo = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      serverHostName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      captivePortalApiUrl = _aidl_parcel.readString();
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
    _aidl_sj.add("baseConfiguration: " + (java.util.Objects.toString(baseConfiguration)));
    _aidl_sj.add("leaseDuration: " + (leaseDuration));
    _aidl_sj.add("mtu: " + (mtu));
    _aidl_sj.add("serverAddress: " + (java.util.Objects.toString(serverAddress)));
    _aidl_sj.add("vendorInfo: " + (java.util.Objects.toString(vendorInfo)));
    _aidl_sj.add("serverHostName: " + (java.util.Objects.toString(serverHostName)));
    _aidl_sj.add("captivePortalApiUrl: " + (java.util.Objects.toString(captivePortalApiUrl)));
    return "android.net.DhcpResultsParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(baseConfiguration);
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
