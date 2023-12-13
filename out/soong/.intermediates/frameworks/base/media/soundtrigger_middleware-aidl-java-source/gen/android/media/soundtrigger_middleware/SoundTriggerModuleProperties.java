/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Capabilities of a sound trigger module.
 * {@hide}
 */
public class SoundTriggerModuleProperties implements android.os.Parcelable
{
  /** Implementor name */
  public java.lang.String implementor;
  /** Implementation description */
  public java.lang.String description;
  /** Implementation version */
  public int version = 0;
  /**
       * Unique implementation ID. The UUID must change with each version of
         the engine implementation */
  public java.lang.String uuid;
  /**
       * String naming the architecture used for running the supported models.
       * (eg. a platform running models on a DSP could implement this string to convey the DSP
       * architecture used)
       * This property is supported for soundtrigger HAL v2.3 and above.
       * If running a previous version, the string will be empty.
       */
  public java.lang.String supportedModelArch;
  /** Maximum number of concurrent sound models loaded */
  public int maxSoundModels = 0;
  /** Maximum number of key phrases */
  public int maxKeyPhrases = 0;
  /** Maximum number of concurrent users detected */
  public int maxUsers = 0;
  /** All supported modes. e.g RecognitionMode.VOICE_TRIGGER */
  public int recognitionModes = 0;
  /** Supports seamless transition from detection to capture */
  public boolean captureTransition = false;
  /** Maximum buffering capacity in ms if captureTransition is true */
  public int maxBufferMs = 0;
  /** Supports capture by other use cases while detection is active */
  public boolean concurrentCapture = false;
  /** Returns the trigger capture in event */
  public boolean triggerInEvent = false;
  /**
       * Rated power consumption when detection is active with TDB
       * silence/sound/speech ratio */
  public int powerConsumptionMw = 0;
  /**
       * Bit field encoding of the AudioCapabilities
       * supported by the firmware.
       * This property is supported for soundtrigger HAL v2.3 and above.
       * If running a previous version, this value will be 0.
       */
  public int audioCapabilities = 0;
  public static final android.os.Parcelable.Creator<SoundTriggerModuleProperties> CREATOR = new android.os.Parcelable.Creator<SoundTriggerModuleProperties>() {
    @Override
    public SoundTriggerModuleProperties createFromParcel(android.os.Parcel _aidl_source) {
      SoundTriggerModuleProperties _aidl_out = new SoundTriggerModuleProperties();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SoundTriggerModuleProperties[] newArray(int _aidl_size) {
      return new SoundTriggerModuleProperties[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(implementor);
    _aidl_parcel.writeString(description);
    _aidl_parcel.writeInt(version);
    _aidl_parcel.writeString(uuid);
    _aidl_parcel.writeString(supportedModelArch);
    _aidl_parcel.writeInt(maxSoundModels);
    _aidl_parcel.writeInt(maxKeyPhrases);
    _aidl_parcel.writeInt(maxUsers);
    _aidl_parcel.writeInt(recognitionModes);
    _aidl_parcel.writeInt(((captureTransition)?(1):(0)));
    _aidl_parcel.writeInt(maxBufferMs);
    _aidl_parcel.writeInt(((concurrentCapture)?(1):(0)));
    _aidl_parcel.writeInt(((triggerInEvent)?(1):(0)));
    _aidl_parcel.writeInt(powerConsumptionMw);
    _aidl_parcel.writeInt(audioCapabilities);
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
      implementor = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      description = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      version = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      uuid = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      supportedModelArch = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxSoundModels = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxKeyPhrases = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxUsers = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      recognitionModes = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      captureTransition = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxBufferMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      concurrentCapture = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      triggerInEvent = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      powerConsumptionMw = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      audioCapabilities = _aidl_parcel.readInt();
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
