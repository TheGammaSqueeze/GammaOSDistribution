/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Base sound model descriptor. This struct can be extended for various specific types by way of
 * aggregation.
 * {@hide}
 */
public class SoundModel implements android.os.Parcelable
{
  /** Model type. */
  public int type;
  /** Unique sound model ID. */
  public java.lang.String uuid;
  /**
       * Unique vendor ID. Identifies the engine the sound model
       * was build for */
  public java.lang.String vendorUuid;
  /** Opaque data transparent to Android framework. May be null if dataSize is 0. */
  public android.os.ParcelFileDescriptor data;
  /** Size of the above data, in bytes. */
  public int dataSize = 0;
  public static final android.os.Parcelable.Creator<SoundModel> CREATOR = new android.os.Parcelable.Creator<SoundModel>() {
    @Override
    public SoundModel createFromParcel(android.os.Parcel _aidl_source) {
      SoundModel _aidl_out = new SoundModel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SoundModel[] newArray(int _aidl_size) {
      return new SoundModel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeString(uuid);
    _aidl_parcel.writeString(vendorUuid);
    if ((data!=null)) {
      _aidl_parcel.writeInt(1);
      data.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(dataSize);
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
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      uuid = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      vendorUuid = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        data = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        data = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dataSize = _aidl_parcel.readInt();
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
    _mask |= describeContents(data);
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
