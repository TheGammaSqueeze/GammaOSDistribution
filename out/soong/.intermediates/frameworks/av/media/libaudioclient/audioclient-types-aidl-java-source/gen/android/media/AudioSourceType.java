/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public @interface AudioSourceType {
  public static final int INVALID = -1;
  public static final int DEFAULT = 0;
  public static final int MIC = 1;
  public static final int VOICE_UPLINK = 2;
  public static final int VOICE_DOWNLINK = 3;
  public static final int VOICE_CALL = 4;
  public static final int CAMCORDER = 5;
  public static final int VOICE_RECOGNITION = 6;
  public static final int VOICE_COMMUNICATION = 7;
  public static final int REMOTE_SUBMIX = 8;
  public static final int UNPROCESSED = 9;
  public static final int VOICE_PERFORMANCE = 10;
  public static final int ECHO_REFERENCE = 1997;
  public static final int FM_TUNER = 1998;
  /**
       * A low-priority, preemptible audio source for for background software
       * hotword detection. Same tuning as VOICE_RECOGNITION.
       * Used only internally by the framework.
       */
  public static final int HOTWORD = 1999;
}
