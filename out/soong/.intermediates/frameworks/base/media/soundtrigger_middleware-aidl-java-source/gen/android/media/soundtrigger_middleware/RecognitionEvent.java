/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * An event that gets sent to indicate a recognition (or aborting of the recognition process).
 * {@hide}
 */
public class RecognitionEvent implements android.os.Parcelable
{
  /** Recognition status. */
  public int status;
  /** Event type, same as sound model type. */
  public int type;
  /** Is it possible to capture audio from this utterance buffered by the implementation. */
  public boolean captureAvailable = false;
  /** Audio session ID. framework use. */
  public int captureSession = 0;
  /**
       * Delay in ms between end of model detection and start of audio available for capture.
       * A negative value is possible (e.g. if key phrase is also available for Capture.
       */
  public int captureDelayMs = 0;
  /** Duration in ms of audio captured before the start of the trigger. 0 if none. */
  public int capturePreambleMs = 0;
  /** If true, the 'data' field below contains the capture of the trigger sound. */
  public boolean triggerInData = false;
  /**
       * Audio format of either the trigger in event data or to use for capture of the rest of the
       * utterance. May be null when no audio is available for this event type.
       */
  public android.media.audio.common.AudioConfig audioConfig;
  /** Additional data. */
  public byte[] data;
  public static final android.os.Parcelable.Creator<RecognitionEvent> CREATOR = new android.os.Parcelable.Creator<RecognitionEvent>() {
    @Override
    public RecognitionEvent createFromParcel(android.os.Parcel _aidl_source) {
      RecognitionEvent _aidl_out = new RecognitionEvent();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public RecognitionEvent[] newArray(int _aidl_size) {
      return new RecognitionEvent[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(status);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeInt(((captureAvailable)?(1):(0)));
    _aidl_parcel.writeInt(captureSession);
    _aidl_parcel.writeInt(captureDelayMs);
    _aidl_parcel.writeInt(capturePreambleMs);
    _aidl_parcel.writeInt(((triggerInData)?(1):(0)));
    if ((audioConfig!=null)) {
      _aidl_parcel.writeInt(1);
      audioConfig.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
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
      status = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      captureAvailable = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      captureSession = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      captureDelayMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      capturePreambleMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      triggerInData = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        audioConfig = android.media.audio.common.AudioConfig.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        audioConfig = null;
      }
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
    _mask |= describeContents(audioConfig);
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
