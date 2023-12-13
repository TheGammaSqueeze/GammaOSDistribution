/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class TetherStatsParcel implements android.os.Parcelable
{
  public java.lang.String iface;
  public long rxBytes = 0L;
  public long rxPackets = 0L;
  public long txBytes = 0L;
  public long txPackets = 0L;
  public int ifIndex = 0;
  public static final android.os.Parcelable.Creator<TetherStatsParcel> CREATOR = new android.os.Parcelable.Creator<TetherStatsParcel>() {
    @Override
    public TetherStatsParcel createFromParcel(android.os.Parcel _aidl_source) {
      TetherStatsParcel _aidl_out = new TetherStatsParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TetherStatsParcel[] newArray(int _aidl_size) {
      return new TetherStatsParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(iface);
    _aidl_parcel.writeLong(rxBytes);
    _aidl_parcel.writeLong(rxPackets);
    _aidl_parcel.writeLong(txBytes);
    _aidl_parcel.writeLong(txPackets);
    _aidl_parcel.writeInt(ifIndex);
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
      iface = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      rxBytes = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      rxPackets = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      txBytes = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      txPackets = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ifIndex = _aidl_parcel.readInt();
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
