/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tunerresourcemanager;
/**
 * Information required to request a Tuner Lnb.
 *
 * @hide
 */
public class TunerLnbRequest implements android.os.Parcelable
{
  public int clientId = 0;
  public static final android.os.Parcelable.Creator<TunerLnbRequest> CREATOR = new android.os.Parcelable.Creator<TunerLnbRequest>() {
    @Override
    public TunerLnbRequest createFromParcel(android.os.Parcel _aidl_source) {
      TunerLnbRequest _aidl_out = new TunerLnbRequest();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TunerLnbRequest[] newArray(int _aidl_size) {
      return new TunerLnbRequest[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(clientId);
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
      clientId = _aidl_parcel.readInt();
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
