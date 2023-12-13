/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * {@hide}
 */
public @interface Status {
  /** Success. */
  public static final int SUCCESS = 0;
  /** Failure due to resource contention. This is typically a temporary condition. */
  public static final int RESOURCE_CONTENTION = 1;
  /** Operation is not supported in this implementation. This is a permanent condition. */
  public static final int OPERATION_NOT_SUPPORTED = 2;
  /** Temporary lack of permission. */
  public static final int TEMPORARY_PERMISSION_DENIED = 3;
  /** The object on which this method is called is dead and all of its state is lost. */
  public static final int DEAD_OBJECT = 4;
  /**
       * Unexpected internal error has occurred. Usually this will result in the service rebooting
       * shortly after. The client should treat the state of the server as undefined.
       */
  public static final int INTERNAL_ERROR = 5;
}
