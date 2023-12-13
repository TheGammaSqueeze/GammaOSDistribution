/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.permission;
/**
 * A collection of identity-related information, required for permission enforcement.
 *
 * {@hide}
 */
public class Identity implements android.os.Parcelable
{
  /** Linux user ID. */
  public int uid = -1;
  /** Linux process ID. */
  public int pid = -1;
  /** Package name. If null, the first package owned by the given uid will be assumed. */
  public java.lang.String packageName;
  /** Attribution tag. Mostly used for diagnostic purposes. */
  public java.lang.String attributionTag;
  public static final android.os.Parcelable.Creator<Identity> CREATOR = new android.os.Parcelable.Creator<Identity>() {
    @Override
    public Identity createFromParcel(android.os.Parcel _aidl_source) {
      Identity _aidl_out = new Identity();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public Identity[] newArray(int _aidl_size) {
      return new Identity[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(uid);
    _aidl_parcel.writeInt(pid);
    _aidl_parcel.writeString(packageName);
    _aidl_parcel.writeString(attributionTag);
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
      uid = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      pid = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      packageName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      attributionTag = _aidl_parcel.readString();
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
