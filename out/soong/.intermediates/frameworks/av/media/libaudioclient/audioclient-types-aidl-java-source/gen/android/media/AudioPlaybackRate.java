/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * The AudioPlaybackRate.
 *
 * See https://developer.android.com/reference/android/media/PlaybackParams.
 * TODO(b/175166815): Reconcile with framework-media-sources PlaybackParams.aidl.
 *       As this is used for native wire serialization, no need to define
 *       audio_timestretch_stretch_mode_t and audio_timestretch_fallback_mode_t enums
 *       until we attempt to unify with PlaybackParams.
 *
 * {@hide}
 */
public class AudioPlaybackRate implements android.os.Parcelable
{
  /** Speed of audio playback, >= 0.f, 1.f nominal (system limits are further restrictive) */
  public float speed = 0.000000f;
  /** Pitch of audio, >= 0.f, 1.f nominal (system limits are further restrictive) */
  public float pitch = 0.000000f;
  /** Interpreted as audio_timestretch_stretch_mode_t */
  public int stretchMode = 0;
  /** Interpreted as audio_timestretch_fallback_mode_t */
  public int fallbackMode = 0;
  public static final android.os.Parcelable.Creator<AudioPlaybackRate> CREATOR = new android.os.Parcelable.Creator<AudioPlaybackRate>() {
    @Override
    public AudioPlaybackRate createFromParcel(android.os.Parcel _aidl_source) {
      AudioPlaybackRate _aidl_out = new AudioPlaybackRate();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AudioPlaybackRate[] newArray(int _aidl_size) {
      return new AudioPlaybackRate[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeFloat(speed);
    _aidl_parcel.writeFloat(pitch);
    _aidl_parcel.writeInt(stretchMode);
    _aidl_parcel.writeInt(fallbackMode);
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
      speed = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      pitch = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      stretchMode = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      fallbackMode = _aidl_parcel.readInt();
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
