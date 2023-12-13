/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class TcpKeepalivePacketDataParcelable implements android.os.Parcelable
{
  public byte[] srcAddress;
  public int srcPort = 0;
  public byte[] dstAddress;
  public int dstPort = 0;
  public int seq = 0;
  public int ack = 0;
  public int rcvWnd = 0;
  public int rcvWndScale = 0;
  public int tos = 0;
  public int ttl = 0;
  public static final android.os.Parcelable.Creator<TcpKeepalivePacketDataParcelable> CREATOR = new android.os.Parcelable.Creator<TcpKeepalivePacketDataParcelable>() {
    @Override
    public TcpKeepalivePacketDataParcelable createFromParcel(android.os.Parcel _aidl_source) {
      TcpKeepalivePacketDataParcelable _aidl_out = new TcpKeepalivePacketDataParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TcpKeepalivePacketDataParcelable[] newArray(int _aidl_size) {
      return new TcpKeepalivePacketDataParcelable[_aidl_size];
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
    _aidl_parcel.writeInt(seq);
    _aidl_parcel.writeInt(ack);
    _aidl_parcel.writeInt(rcvWnd);
    _aidl_parcel.writeInt(rcvWndScale);
    _aidl_parcel.writeInt(tos);
    _aidl_parcel.writeInt(ttl);
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
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      seq = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ack = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      rcvWnd = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      rcvWndScale = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tos = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      ttl = _aidl_parcel.readInt();
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
    _aidl_sj.add("seq: " + (seq));
    _aidl_sj.add("ack: " + (ack));
    _aidl_sj.add("rcvWnd: " + (rcvWnd));
    _aidl_sj.add("rcvWndScale: " + (rcvWndScale));
    _aidl_sj.add("tos: " + (tos));
    _aidl_sj.add("ttl: " + (ttl));
    return "android.net.TcpKeepalivePacketDataParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
