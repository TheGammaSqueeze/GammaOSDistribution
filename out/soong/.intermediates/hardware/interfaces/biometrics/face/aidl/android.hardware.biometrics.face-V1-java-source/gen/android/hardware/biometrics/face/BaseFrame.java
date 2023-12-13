/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.biometrics.face;
public class BaseFrame implements android.os.Parcelable
{
  public byte acquiredInfo = android.hardware.biometrics.face.AcquiredInfo.UNKNOWN;
  public int vendorCode = 0;
  public float pan = 0.000000f;
  public float tilt = 0.000000f;
  public float distance = 0.000000f;
  public boolean isCancellable = false;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<BaseFrame> CREATOR = new android.os.Parcelable.Creator<BaseFrame>() {
    @Override
    public BaseFrame createFromParcel(android.os.Parcel _aidl_source) {
      BaseFrame _aidl_out = new BaseFrame();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public BaseFrame[] newArray(int _aidl_size) {
      return new BaseFrame[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeByte(acquiredInfo);
    _aidl_parcel.writeInt(vendorCode);
    _aidl_parcel.writeFloat(pan);
    _aidl_parcel.writeFloat(tilt);
    _aidl_parcel.writeFloat(distance);
    _aidl_parcel.writeInt(((isCancellable)?(1):(0)));
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
      acquiredInfo = _aidl_parcel.readByte();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      vendorCode = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      pan = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tilt = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      distance = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isCancellable = (0!=_aidl_parcel.readInt());
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
