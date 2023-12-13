/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class Layer2PacketParcelable implements android.os.Parcelable
{
  public android.net.MacAddress dstMacAddress;
  public byte[] payload;
  public static final android.os.Parcelable.Creator<Layer2PacketParcelable> CREATOR = new android.os.Parcelable.Creator<Layer2PacketParcelable>() {
    @Override
    public Layer2PacketParcelable createFromParcel(android.os.Parcel _aidl_source) {
      Layer2PacketParcelable _aidl_out = new Layer2PacketParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public Layer2PacketParcelable[] newArray(int _aidl_size) {
      return new Layer2PacketParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((dstMacAddress!=null)) {
      _aidl_parcel.writeInt(1);
      dstMacAddress.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeByteArray(payload);
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
        dstMacAddress = android.net.MacAddress.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        dstMacAddress = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      payload = _aidl_parcel.createByteArray();
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
    _aidl_sj.add("dstMacAddress: " + (java.util.Objects.toString(dstMacAddress)));
    _aidl_sj.add("payload: " + (java.util.Arrays.toString(payload)));
    return "android.net.Layer2PacketParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(dstMacAddress);
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
