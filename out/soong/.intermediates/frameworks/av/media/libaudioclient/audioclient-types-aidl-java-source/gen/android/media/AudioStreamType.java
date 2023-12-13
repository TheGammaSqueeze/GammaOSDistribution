/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public @interface AudioStreamType {
  public static final int DEFAULT = -1;
  public static final int VOICE_CALL = 0;
  public static final int SYSTEM = 1;
  public static final int RING = 2;
  public static final int MUSIC = 3;
  public static final int ALARM = 4;
  public static final int NOTIFICATION = 5;
  public static final int BLUETOOTH_SCO = 6;
  public static final int ENFORCED_AUDIBLE = 7;
  public static final int DTMF = 8;
  public static final int TTS = 9;
  public static final int ACCESSIBILITY = 10;
  public static final int ASSISTANT = 11;
  /** For dynamic policy output mixes. Only used by the audio policy */
  public static final int REROUTING = 12;
  /** For audio flinger tracks volume. Only used by the audioflinger */
  public static final int PATCH = 13;
  /** stream for corresponding to AUDIO_USAGE_CALL_ASSISTANT */
  public static final int CALL_ASSISTANT = 14;
}
