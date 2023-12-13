/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Configuration for tuning behavior of an active recognition process.
 * {@hide}
 */
public class RecognitionConfig implements android.os.Parcelable
{
  /** Capture and buffer audio for this recognition instance. */
  public boolean captureRequested = false;
  /** Configuration for each key phrase. */
  public android.media.soundtrigger_middleware.PhraseRecognitionExtra[] phraseRecognitionExtras;
  /**
       * Bit field encoding of the AudioCapabilities
       * supported by the firmware.
       */
  public int audioCapabilities = 0;
  /** Opaque capture configuration data. */
  public byte[] data;
  public static final android.os.Parcelable.Creator<RecognitionConfig> CREATOR = new android.os.Parcelable.Creator<RecognitionConfig>() {
    @Override
    public RecognitionConfig createFromParcel(android.os.Parcel _aidl_source) {
      RecognitionConfig _aidl_out = new RecognitionConfig();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public RecognitionConfig[] newArray(int _aidl_size) {
      return new RecognitionConfig[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(((captureRequested)?(1):(0)));
    _aidl_parcel.writeTypedArray(phraseRecognitionExtras, 0);
    _aidl_parcel.writeInt(audioCapabilities);
    _aidl_parcel.writeByteArray(data);
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
      captureRequested = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      phraseRecognitionExtras = _aidl_parcel.createTypedArray(android.media.soundtrigger_middleware.PhraseRecognitionExtra.CREATOR);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      audioCapabilities = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      data = _aidl_parcel.createByteArray();
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
    _mask |= describeContents(phraseRecognitionExtras);
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
