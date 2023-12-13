/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.audio.common;
/**
 * A channel mask per se only defines the presence or absence of a channel, not
 * the order.
 *
 * The channel order convention is that channels are interleaved in order from
 * least significant channel mask bit to most significant channel mask bit,
 * with unused bits skipped. For example for stereo, LEFT would be first,
 * followed by RIGHT.
 * Any exceptions to this convention are noted at the appropriate API.
 *
 * AudioChannelMask is an opaque type and its internal layout should not be
 * assumed as it may change in the future.  Instead, always use functions
 * to examine it.
 *
 * These are the current representations:
 *
 *   REPRESENTATION_POSITION
 *     is a channel mask representation for position assignment.  Each low-order
 *     bit corresponds to the spatial position of a transducer (output), or
 *     interpretation of channel (input).  The user of a channel mask needs to
 *     know the context of whether it is for output or input.  The constants
 *     OUT_* or IN_* apply to the bits portion.  It is not permitted for no bits
 *     to be set.
 *
 *   REPRESENTATION_INDEX
 *     is a channel mask representation for index assignment.  Each low-order
 *     bit corresponds to a selected channel.  There is no platform
 *     interpretation of the various bits.  There is no concept of output or
 *     input.  It is not permitted for no bits to be set.
 *
 * All other representations are reserved for future use.
 *
 * Warning: current representation distinguishes between input and output, but
 * this will not the be case in future revisions of the platform. Wherever there
 * is an ambiguity between input and output that is currently resolved by
 * checking the channel mask, the implementer should look for ways to fix it
 * with additional information outside of the mask.
 *
 * {@hide}
 */
public @interface AudioChannelMask {
  /**
       * must be 0 for compatibility
       */
  public static final int REPRESENTATION_POSITION = 0;
  /**
       * 1 is reserved for future use
       */
  public static final int REPRESENTATION_INDEX = 2;
  /**
       * 3 is reserved for future use
       *
       *
       * These can be a complete value of AudioChannelMask
       */
  public static final int NONE = 0;
  public static final int INVALID = -1073741824;
  /**
       * These can be the bits portion of an AudioChannelMask
       * with representation REPRESENTATION_POSITION.
       *
       *
       * output channels
       */
  public static final int OUT_FRONT_LEFT = 1;
  public static final int OUT_FRONT_RIGHT = 2;
  public static final int OUT_FRONT_CENTER = 4;
  public static final int OUT_LOW_FREQUENCY = 8;
  public static final int OUT_BACK_LEFT = 16;
  public static final int OUT_BACK_RIGHT = 32;
  public static final int OUT_FRONT_LEFT_OF_CENTER = 64;
  public static final int OUT_FRONT_RIGHT_OF_CENTER = 128;
  public static final int OUT_BACK_CENTER = 256;
  public static final int OUT_SIDE_LEFT = 512;
  public static final int OUT_SIDE_RIGHT = 1024;
  public static final int OUT_TOP_CENTER = 2048;
  public static final int OUT_TOP_FRONT_LEFT = 4096;
  public static final int OUT_TOP_FRONT_CENTER = 8192;
  public static final int OUT_TOP_FRONT_RIGHT = 16384;
  public static final int OUT_TOP_BACK_LEFT = 32768;
  public static final int OUT_TOP_BACK_CENTER = 65536;
  public static final int OUT_TOP_BACK_RIGHT = 131072;
  public static final int OUT_TOP_SIDE_LEFT = 262144;
  public static final int OUT_TOP_SIDE_RIGHT = 524288;
  /**
       * Haptic channel characteristics are specific to a device and
       * only used to play device specific resources (eg: ringtones).
       * The HAL can freely map A and B to haptic controllers, the
       * framework shall not interpret those values and forward them
       * from the device audio assets.
       */
  public static final int OUT_HAPTIC_A = 536870912;
  public static final int OUT_HAPTIC_B = 268435456;
  // TODO(ytai): Aliases not currently supported in AIDL - can inline the values.
  //    OUT_MONO = OUT_FRONT_LEFT,
  //    OUT_STEREO = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT),
  //    OUT_2POINT1 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_LOW_FREQUENCY),
  //    OUT_2POINT0POINT2 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT),
  //    OUT_2POINT1POINT2 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT | OUT_LOW_FREQUENCY),
  //    OUT_3POINT0POINT2 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT),
  //    OUT_3POINT1POINT2 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT | OUT_LOW_FREQUENCY),
  //    OUT_QUAD = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_BACK_LEFT | OUT_BACK_RIGHT),
  //    OUT_QUAD_BACK = OUT_QUAD,
  //    /**
  //     * like OUT_QUAD_BACK with *_SIDE_* instead of *_BACK_*
  //     */
  //    OUT_QUAD_SIDE = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_SIDE_LEFT | OUT_SIDE_RIGHT),
  //    OUT_SURROUND = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_BACK_CENTER),
  //    OUT_PENTA = (OUT_QUAD | OUT_FRONT_CENTER),
  //    OUT_5POINT1 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT),
  //    OUT_5POINT1_BACK = OUT_5POINT1,
  //    /**
  //     * like OUT_5POINT1_BACK with *_SIDE_* instead of *_BACK_*
  //     */
  //    OUT_5POINT1_SIDE = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_SIDE_LEFT | OUT_SIDE_RIGHT),
  //    OUT_5POINT1POINT2 = (OUT_5POINT1 | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT),
  //    OUT_5POINT1POINT4 = (OUT_5POINT1 | OUT_TOP_FRONT_LEFT | OUT_TOP_FRONT_RIGHT | OUT_TOP_BACK_LEFT | OUT_TOP_BACK_RIGHT),
  //    OUT_6POINT1 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT | OUT_BACK_CENTER),
  //    /**
  //     * matches the correct AudioFormat.CHANNEL_OUT_7POINT1_SURROUND
  //     */
  //    OUT_7POINT1 = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT | OUT_SIDE_LEFT | OUT_SIDE_RIGHT),
  //    OUT_7POINT1POINT2 = (OUT_7POINT1 | OUT_TOP_SIDE_LEFT | OUT_TOP_SIDE_RIGHT),
  //    OUT_7POINT1POINT4 = (OUT_7POINT1 | OUT_TOP_FRONT_LEFT | OUT_TOP_FRONT_RIGHT | OUT_TOP_BACK_LEFT | OUT_TOP_BACK_RIGHT),
  //    OUT_MONO_HAPTIC_A = (OUT_FRONT_LEFT | OUT_HAPTIC_A),
  //    OUT_STEREO_HAPTIC_A = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_HAPTIC_A),
  //    OUT_HAPTIC_AB = (OUT_HAPTIC_A | OUT_HAPTIC_B),
  //    OUT_MONO_HAPTIC_AB = (OUT_FRONT_LEFT | OUT_HAPTIC_A | OUT_HAPTIC_B),
  //    OUT_STEREO_HAPTIC_AB = (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_HAPTIC_A | OUT_HAPTIC_B),
  /**
       * These are bits only, not complete values
       *
       *
       * input channels
       */
  public static final int IN_LEFT = 4;
  public static final int IN_RIGHT = 8;
  public static final int IN_FRONT = 16;
  public static final int IN_BACK = 32;
  public static final int IN_LEFT_PROCESSED = 64;
  public static final int IN_RIGHT_PROCESSED = 128;
  public static final int IN_FRONT_PROCESSED = 256;
  public static final int IN_BACK_PROCESSED = 512;
  public static final int IN_PRESSURE = 1024;
  public static final int IN_X_AXIS = 2048;
  public static final int IN_Y_AXIS = 4096;
  public static final int IN_Z_AXIS = 8192;
  public static final int IN_BACK_LEFT = 65536;
  public static final int IN_BACK_RIGHT = 131072;
  public static final int IN_CENTER = 262144;
  public static final int IN_LOW_FREQUENCY = 1048576;
  public static final int IN_TOP_LEFT = 2097152;
  public static final int IN_TOP_RIGHT = 4194304;
  public static final int IN_VOICE_UPLINK = 16384;
  public static final int IN_VOICE_DNLINK = 32768;
}
