/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.keymaster;
public class HardwareAuthToken implements android.os.Parcelable
{
  public long challenge = 0L;
  public long userId = 0L;
  public long authenticatorId = 0L;
  public int authenticatorType = android.hardware.keymaster.HardwareAuthenticatorType.NONE;
  public android.hardware.keymaster.Timestamp timestamp;
  public byte[] mac;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<HardwareAuthToken> CREATOR = new android.os.Parcelable.Creator<HardwareAuthToken>() {
    @Override
    public HardwareAuthToken createFromParcel(android.os.Parcel _aidl_source) {
      HardwareAuthToken _aidl_out = new HardwareAuthToken();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public HardwareAuthToken[] newArray(int _aidl_size) {
      return new HardwareAuthToken[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeLong(challenge);
    _aidl_parcel.writeLong(userId);
    _aidl_parcel.writeLong(authenticatorId);
    _aidl_parcel.writeInt(authenticatorType);
    if ((timestamp!=null)) {
      _aidl_parcel.writeInt(1);
      timestamp.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeByteArray(mac);
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
      challenge = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      userId = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      authenticatorId = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      authenticatorType = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        timestamp = android.hardware.keymaster.Timestamp.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        timestamp = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      mac = _aidl_parcel.createByteArray();
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
    _mask |= describeContents(timestamp);
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
