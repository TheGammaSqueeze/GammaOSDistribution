/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class TetherOffloadRuleParcel implements android.os.Parcelable
{
  public int inputInterfaceIndex = 0;
  public int outputInterfaceIndex = 0;
  public byte[] destination;
  public int prefixLength = 0;
  public byte[] srcL2Address;
  public byte[] dstL2Address;
  public static final android.os.Parcelable.Creator<TetherOffloadRuleParcel> CREATOR = new android.os.Parcelable.Creator<TetherOffloadRuleParcel>() {
    @Override
    public TetherOffloadRuleParcel createFromParcel(android.os.Parcel _aidl_source) {
      TetherOffloadRuleParcel _aidl_out = new TetherOffloadRuleParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TetherOffloadRuleParcel[] newArray(int _aidl_size) {
      return new TetherOffloadRuleParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(inputInterfaceIndex);
    _aidl_parcel.writeInt(outputInterfaceIndex);
    _aidl_parcel.writeByteArray(destination);
    _aidl_parcel.writeInt(prefixLength);
    _aidl_parcel.writeByteArray(srcL2Address);
    _aidl_parcel.writeByteArray(dstL2Address);
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
      inputInterfaceIndex = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      outputInterfaceIndex = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      destination = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixLength = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      srcL2Address = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dstL2Address = _aidl_parcel.createByteArray();
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
