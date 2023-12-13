/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.resolv.aidl;
/** @hide */
public class Nat64PrefixEventParcel implements android.os.Parcelable
{
  public int netId = 0;
  public int prefixOperation = 0;
  public java.lang.String prefixAddress;
  public int prefixLength = 0;
  public static final android.os.Parcelable.Creator<Nat64PrefixEventParcel> CREATOR = new android.os.Parcelable.Creator<Nat64PrefixEventParcel>() {
    @Override
    public Nat64PrefixEventParcel createFromParcel(android.os.Parcel _aidl_source) {
      Nat64PrefixEventParcel _aidl_out = new Nat64PrefixEventParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public Nat64PrefixEventParcel[] newArray(int _aidl_size) {
      return new Nat64PrefixEventParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeInt(prefixOperation);
    _aidl_parcel.writeString(prefixAddress);
    _aidl_parcel.writeInt(prefixLength);
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
      netId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixOperation = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixAddress = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      prefixLength = _aidl_parcel.readInt();
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
    _aidl_sj.add("netId: " + (netId));
    _aidl_sj.add("prefixOperation: " + (prefixOperation));
    _aidl_sj.add("prefixAddress: " + (java.util.Objects.toString(prefixAddress)));
    _aidl_sj.add("prefixLength: " + (prefixLength));
    return "android.net.resolv.aidl.Nat64PrefixEventParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
