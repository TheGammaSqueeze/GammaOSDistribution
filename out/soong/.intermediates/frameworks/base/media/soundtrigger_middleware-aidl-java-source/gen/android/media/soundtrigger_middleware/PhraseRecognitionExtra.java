/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Specialized recognition event for key phrase detection.
 * {@hide}
 */
public class PhraseRecognitionExtra implements android.os.Parcelable
{
  // TODO(ytai): Constants / enums.
  /** keyphrase ID */
  public int id = 0;
  /** recognition modes used for this keyphrase */
  public int recognitionModes = 0;
  /** confidence level for mode RECOGNITION_MODE_VOICE_TRIGGER */
  public int confidenceLevel = 0;
  /** number of user confidence levels */
  public android.media.soundtrigger_middleware.ConfidenceLevel[] levels;
  public static final android.os.Parcelable.Creator<PhraseRecognitionExtra> CREATOR = new android.os.Parcelable.Creator<PhraseRecognitionExtra>() {
    @Override
    public PhraseRecognitionExtra createFromParcel(android.os.Parcel _aidl_source) {
      PhraseRecognitionExtra _aidl_out = new PhraseRecognitionExtra();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public PhraseRecognitionExtra[] newArray(int _aidl_size) {
      return new PhraseRecognitionExtra[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(id);
    _aidl_parcel.writeInt(recognitionModes);
    _aidl_parcel.writeInt(confidenceLevel);
    _aidl_parcel.writeTypedArray(levels, 0);
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
      id = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      recognitionModes = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      confidenceLevel = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      levels = _aidl_parcel.createTypedArray(android.media.soundtrigger_middleware.ConfidenceLevel.CREATOR);
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
    _mask |= describeContents(levels);
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
