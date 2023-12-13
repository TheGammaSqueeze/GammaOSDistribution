/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class InterfaceConfigurationParcel implements android.os.Parcelable
{
  public java.lang.String ifName;
  public java.lang.String hwAddr;
  public java.lang.String ipv4Addr;
  public int prefixLength = 0;
  public java.lang.String[] flags;
  public static final android.os.Parcelable.Creator<InterfaceConfigurationParcel> CREATOR = new android.os.Parcelable.Creator<InterfaceConfigurationParcel>() {
    @Override
    public InterfaceConfigurationParcel createFromParcel(android.os.Parcel _aidl_source) {
      InterfaceConfigurationParcel _aidl_out = new InterfaceConfigurationParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public InterfaceConfigurationParcel[] newArray(int _aidl_size) {
      return new InterfaceConfigurationParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(ifName);
    _aidl_parcel.writeString(hwAddr);
    _aidl_parcel.writeString(ipv4Addr);
    _aidl_parcel.writeInt(prefixLength);
    _aidl_parcel.writeStringArray(flags);
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
      ifName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hwAddr = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ipv4Addr = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixLength = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      flags = _aidl_parcel.createStringArray();
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
