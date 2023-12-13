/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * An event that gets sent to indicate a phrase recognition (or aborting of the recognition
   process).
 * {@hide}
 */
public class PhraseRecognitionEvent implements android.os.Parcelable
{
  /** Common recognition event. */
  public android.media.soundtrigger_middleware.RecognitionEvent common;
  /** List of descriptors for each recognized key phrase */
  public android.media.soundtrigger_middleware.PhraseRecognitionExtra[] phraseExtras;
  public static final android.os.Parcelable.Creator<PhraseRecognitionEvent> CREATOR = new android.os.Parcelable.Creator<PhraseRecognitionEvent>() {
    @Override
    public PhraseRecognitionEvent createFromParcel(android.os.Parcel _aidl_source) {
      PhraseRecognitionEvent _aidl_out = new PhraseRecognitionEvent();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public PhraseRecognitionEvent[] newArray(int _aidl_size) {
      return new PhraseRecognitionEvent[_aidl_size];
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
    _aidl_parcel.writeTypedArray(phraseExtras, 0);
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
        common = android.media.soundtrigger_middleware.RecognitionEvent.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        common = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      phraseExtras = _aidl_parcel.createTypedArray(android.media.soundtrigger_middleware.PhraseRecognitionExtra.CREATOR);
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
    _mask |= describeContents(phraseExtras);
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
