/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * A status for indicating the type of a recognition event.
 * {@hide}
 */
public @interface RecognitionStatus {
  /** Recognition success. */
  public static final int SUCCESS = 0;
  /** Recognition aborted (e.g. capture preempted by another use-case. */
  public static final int ABORTED = 1;
  /** Recognition failure. */
  public static final int FAILURE = 2;
  /**
      * Recognition event was triggered by a forceRecognitionEvent request, not by the DSP.
      * Note that forced detections *do not* stop the active recognition, unlike the other types.
      */
  public static final int FORCED = 3;
}
