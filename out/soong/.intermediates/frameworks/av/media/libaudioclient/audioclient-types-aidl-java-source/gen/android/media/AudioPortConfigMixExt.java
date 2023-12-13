/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class AudioPortConfigMixExt implements android.os.Parcelable
{
  /**
       * Module the stream is attached to.
       * Interpreted as audio_module_handle_t.
       */
  public int hwModule = 0;
  /**
       * I/O handle of the input/output stream.
       * Interpreted as audio_io_handle_t.
       */
  public int handle = 0;
  public android.media.AudioPortConfigMixExtUseCase usecase;
  public static final android.os.Parcelable.Creator<AudioPortConfigMixExt> CREATOR = new android.os.Parcelable.Creator<AudioPortConfigMixExt>() {
    @Override
    public AudioPortConfigMixExt createFromParcel(android.os.Parcel _aidl_source) {
      AudioPortConfigMixExt _aidl_out = new AudioPortConfigMixExt();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPortConfigMixExt[] newArray(int _aidl_size) {
      return new AudioPortConfigMixExt[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(hwModule);
    _aidl_parcel.writeInt(handle);
    if ((usecase!=null)) {
      _aidl_parcel.writeInt(1);
      usecase.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
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
      hwModule = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      handle = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        usecase = android.media.AudioPortConfigMixExtUseCase.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        usecase = null;
      }
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
    _mask |= describeContents(usecase);
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
