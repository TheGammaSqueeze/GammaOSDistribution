/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class NattKeepalivePacketDataParcelable implements android.os.Parcelable
{
  public byte[] srcAddress;
  public int srcPort = 0;
  public byte[] dstAddress;
  public int dstPort = 0;
  public static final android.os.Parcelable.Creator<NattKeepalivePacketDataParcelable> CREATOR = new android.os.Parcelable.Creator<NattKeepalivePacketDataParcelable>() {
    @Override
    public NattKeepalivePacketDataParcelable createFromParcel(android.os.Parcel _aidl_source) {
      NattKeepalivePacketDataParcelable _aidl_out = new NattKeepalivePacketDataParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public NattKeepalivePacketDataParcelable[] newArray(int _aidl_size) {
      return new NattKeepalivePacketDataParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeByteArray(srcAddress);
    _aidl_parcel.writeInt(srcPort);
    _aidl_parcel.writeByteArray(dstAddress);
    _aidl_parcel.writeInt(dstPort);
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
      srcAddress = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      srcPort = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dstAddress = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dstPort = _aidl_parcel.readInt();
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
    _aidl_sj.add("srcAddress: " + (java.util.Arrays.toString(srcAddress)));
    _aidl_sj.add("srcPort: " + (srcPort));
    _aidl_sj.add("dstAddress: " + (java.util.Arrays.toString(dstAddress)));
    _aidl_sj.add("dstPort: " + (dstPort));
    return "android.net.NattKeepalivePacketDataParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
