/* AUTO-GENERATED FILE. DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * aapt tool from the resource data it found. It
 * should not be modified by hand.
 */

package me.phh.treble.overlay.xiaomi.redmi6a;

public final class R {
  public static final class array {
    /**
     * Array of output values for LCD backlight corresponding to the LUX values
     * in the config_autoBrightnessLevels array.  This array should have size one greater
     * than the size of the config_autoBrightnessLevels array.
     * The brightness values must be between 0 and 255 and be non-decreasing.
     * This must be overridden in platform specific overlays
     */
    public static final int config_autoBrightnessLcdBacklightValues=0x7f010000;
    /**
     * Array of light sensor LUX values to define our levels for auto backlight brightness support.
     * The N entries of this array define N + 1 control points as follows:
     * (1-based arrays)
     * Point 1:            (0, value[1]):             lux <= 0
     * Point 2:     (level[1], value[2]):  0        < lux <= level[1]
     * Point 3:     (level[2], value[3]):  level[2] < lux <= level[3]
     * ...
     * Point N+1: (level[N], value[N+1]):  level[N] < lux
     * The control points must be strictly increasing.  Each control point
     * corresponds to an entry in the brightness backlight values arrays.
     * For example, if LUX == level[1] (first element of the levels array)
     * then the brightness will be determined by value[2] (second element
     * of the brightness values array).
     * Spline interpolation is used to determine the auto-brightness
     * backlight values for LUX levels between these control points.
     * Must be overridden in platform specific overlays
     */
    public static final int config_autoBrightnessLevels=0x7f010001;
    /**
     * Default list of files pinned by the Pinner Service
     */
    public static final int config_defaultPinnerServiceFiles=0x7f010002;
    /**
     * Vibrator pattern for a very short but reliable vibration for soft keyboard tap
     */
    public static final int config_keyboardTapVibePattern=0x7f010003;
    /**
     * Vibrator pattern for feedback about a long screen/key press
     */
    public static final int config_longPressVibePattern=0x7f010004;
    public static final int config_mobile_tcp_buffers=0x7f010005;
    /**
     * List of regexpressions describing the interface (if any) that represent tetherable
     * bluetooth interfaces.  If the device doesn't want to support tethering over bluetooth this
     * should be empty.
     */
    public static final int config_tether_bluetooth_regexs=0x7f010006;
    /**
     * Common options are [1, 4] for TYPE_WIFI and TYPE_MOBILE_DUN or
     * [0,1,5,7] for TYPE_MOBILE, TYPE_WIFI, TYPE_MOBILE_HIPRI and TYPE_BLUETOOTH
     */
    public static final int config_tether_upstream_types=0x7f010007;
    /**
     * List of regexpressions describing the interface (if any) that represent tetherable
     * USB interfaces.  If the device doesn't want to support tething over USB this should
     * be empty.  An example would be "usb.*"
     */
    public static final int config_tether_usb_regexs=0x7f010008;
    /**
     * List of regexpressions describing the interface (if any) that represent tetherable
     * Wifi interfaces.  If the device doesn't want to support tethering over Wifi this
     * should be empty.  An example would be "softap.*"
     */
    public static final int config_tether_wifi_regexs=0x7f010009;
    /**
     * Vibrator pattern for feedback about touching a virtual key
     */
    public static final int config_virtualKeyVibePattern=0x7f01000a;
    /**
     * the 6th element indicates boot-time dependency-met value.
     */
    public static final int networkAttributes=0x7f01000b;
    /**
     * An Array of "[ConnectivityManager connectionType],
     * [# simultaneous connection types]"
     */
    public static final int radioAttributes=0x7f01000c;
  }
  public static final class bool {
    /**
     * Flag indicating whether the we should enable the automatic brightness in Settings.
     * Software implementation will be used if config_hardware_auto_brightness_available is not set
     */
    public static final int config_automatic_brightness_available=0x7f020000;
    /**
     * If true, the doze component is not started until after the screen has been
     * turned off and the screen off animation has been performed.
     */
    public static final int config_dozeAfterScreenOffByDefault=0x7f020001;
    /**
     * Is the device capable of hot swapping an ICC Card
     */
    public static final int config_hotswapCapable=0x7f020002;
    /**
     * Indicate whether closing the lid causes the device to go to sleep and opening
     * it causes the device to wake up.
     * The default is false.
     */
    public static final int config_lidControlsSleep=0x7f020003;
    /**
     * Should the pinner service pin the Camera application?
     */
    public static final int config_pinnerCameraApp=0x7f020004;
    /**
     * Should the pinner service pin the Home application?
     */
    public static final int config_pinnerHomeApp=0x7f020005;
    /**
     * Power Management: Specifies whether to decouple the auto-suspend state of the
     * device from the display on/off state.
     * When false, autosuspend_disable() will be called before the display is turned on
     * and autosuspend_enable() will be called after the display is turned off.
     * This mode provides best compatibility for devices using legacy power management
     * features such as early suspend / late resume.
     * When true, autosuspend_display() and autosuspend_enable() will be called
     * independently of whether the display is being turned on or off.  This mode
     * enables the power manager to suspend the application processor while the
     * display is on.
     * This resource should be set to "true" when a doze component has been specified
     * to maximize power savings but not all devices support it.
     * Refer to autosuspend.h for details.
     */
    public static final int config_powerDecoupleAutoSuspendModeFromDisplay=0x7f020006;
    /**
     * Boolean indicating whether the HWC setColorTransform function can be performed efficiently in hardware.
     */
    public static final int config_setColorTransformAccelerated=0x7f020007;
    /**
     * Whether a software navigation bar should be shown. NOTE: in the future this may be
     * autodetected from the Configuration.
     */
    public static final int config_showNavigationBar=0x7f020008;
    /**
     * Whether device supports double tap to wake
     */
    public static final int config_supportDoubleTapWake=0x7f020009;
    /**
     * When true use the linux /dev/input/event subsystem to detect the switch changes
     * on the headphone/microphone jack. When false use the older uevent framework.
     */
    public static final int config_useDevInputEventForAudioJack=0x7f02000a;
    /**
     * The restoring is handled by modem if it is true
     */
    public static final int skip_restoring_network_selection=0x7f02000b;
  }
  public static final class dimen {
    public static final int rounded_corner_radius=0x7f030000;
  }
  public static final class integer {
    /**
     * Stability requirements in milliseconds for accepting a new brightness level.  This is used
     * for debouncing the light sensor.  Different constants are used to debounce the light sensor
     * when adapting to brighter or darker environments.  This parameter controls how quickly
     * brightness changes occur in response to an observed change in light level that exceeds the
     * hysteresis threshold.
     */
    public static final int config_autoBrightnessBrighteningLightDebounce=0x7f040000;
    public static final int config_autoBrightnessDarkeningLightDebounce=0x7f040001;
    /**
     * Fast brightness animation ramp rate in brightness units per second
     */
    public static final int config_brightness_ramp_rate_fast=0x7f040002;
    /**
     * Slow brightness animation ramp rate in brightness units per second
     */
    public static final int config_brightness_ramp_rate_slow=0x7f040003;
    /**
     * Screen brightness used to dim the screen while dozing in a very low power state.
     * May be less than the minimum allowed brightness setting
     * that can be set by the user.
     */
    public static final int config_screenBrightnessDoze=0x7f040004;
    /**
     * Minimum screen brightness setting allowed by the power manager.
     * The user is forbidden from setting the brightness below this level.
     */
    public static final int config_screenBrightnessSettingMinimum=0x7f040005;
  }
  public static final class xml {
    public static final int power_profile=0x7f050000;
  }
}