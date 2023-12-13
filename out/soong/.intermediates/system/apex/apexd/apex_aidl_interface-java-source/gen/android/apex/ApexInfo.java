/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.apex;
public class ApexInfo implements android.os.Parcelable
{
  public java.lang.String moduleName;
  public java.lang.String modulePath;
  public java.lang.String preinstalledModulePath;
  public long versionCode = 0L;
  public java.lang.String versionName;
  public boolean isFactory = false;
  public boolean isActive = false;
  public static final android.os.Parcelable.Creator<ApexInfo> CREATOR = new android.os.Parcelable.Creator<ApexInfo>() {
    @Override
    public ApexInfo createFromParcel(android.os.Parcel _aidl_source) {
      ApexInfo _aidl_out = new ApexInfo();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ApexInfo[] newArray(int _aidl_size) {
      return new ApexInfo[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(moduleName);
    _aidl_parcel.writeString(modulePath);
    _aidl_parcel.writeString(preinstalledModulePath);
    _aidl_parcel.writeLong(versionCode);
    _aidl_parcel.writeString(versionName);
    _aidl_parcel.writeInt(((isFactory)?(1):(0)));
    _aidl_parcel.writeInt(((isActive)?(1):(0)));
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
      moduleName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      modulePath = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      preinstalledModulePath = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      versionCode = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      versionName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isFactory = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isActive = (0!=_aidl_parcel.readInt());
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
