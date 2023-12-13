/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Specialized sound model for key phrase detection.
 * Proprietary representation of key phrases in binary data must match
 * information indicated by phrases field.
 * {@hide}
 */
public class PhraseSoundModel implements android.os.Parcelable
{
  /** Common part of sound model descriptor */
  public android.media.soundtrigger_middleware.SoundModel common;
  /** List of descriptors for key phrases supported by this sound model */
  public android.media.soundtrigger_middleware.Phrase[] phrases;
  public static final android.os.Parcelable.Creator<PhraseSoundModel> CREATOR = new android.os.Parcelable.Creator<PhraseSoundModel>() {
    @Override
    public PhraseSoundModel createFromParcel(android.os.Parcel _aidl_source) {
      PhraseSoundModel _aidl_out = new PhraseSoundModel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public PhraseSoundModel[] newArray(int _aidl_size) {
      return new PhraseSoundModel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((common!=null)) {
      _aidl_parcel.writeInt(1);
      common.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeTypedArray(phrases, 0);
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
        common = android.media.soundtrigger_middleware.SoundModel.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        common = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      phrases = _aidl_parcel.createTypedArray(android.media.soundtrigger_middleware.Phrase.CREATOR);
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
    _mask |= describeContents(common);
    _mask |= describeContents(phrases);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    Class<?> _clazz = _v.getClass();
    if (_clazz.isArray() && _clazz.getComponentType() == Object.class) {
      int _mask = 0;
      for (Object o : (Object[]) _v) {
        _mask |= describeContents(o);
      }
      return _mask;
    }
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
