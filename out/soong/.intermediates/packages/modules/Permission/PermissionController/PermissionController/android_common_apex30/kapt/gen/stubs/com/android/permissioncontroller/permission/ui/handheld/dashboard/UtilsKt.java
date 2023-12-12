package com.android.permissioncontroller.permission.ui.handheld.dashboard;

import android.content.Context;
import android.icu.util.Calendar;
import android.provider.DeviceConfig;
import android.util.Pair;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.model.AppPermissionUsage.GroupUsage;
import java.util.Locale;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u00004\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\f\u001a\u001a\u0010\u000b\u001a\u000e\u0012\u0004\u0012\u00020\r\u0012\u0004\u0012\u00020\u00010\f2\u0006\u0010\u000e\u001a\u00020\r\u001a\u001a\u0010\u000f\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013\u001a\u0018\u0010\u0014\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\r\u001a\u0006\u0010\u0016\u001a\u00020\u0017\u001a\u0016\u0010\u0018\u001a\u00020\u00052\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u000e\u001a\u00020\r\u001a\u0016\u0010\u0019\u001a\u00020\u00052\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u000e\u001a\u00020\r\u001a\u001a\u0010\u001a\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013\u001a\u0006\u0010\u001b\u001a\u00020\u0017\u001a\u0006\u0010\u001c\u001a\u00020\u0017\u001a\u0006\u0010\u001d\u001a\u00020\u0017\u001a\u0006\u0010\u001e\u001a\u00020\u0017\u001a\u0010\u0010\u001f\u001a\u00020\u00172\u0006\u0010 \u001a\u00020\rH\u0002\u001a\u0006\u0010!\u001a\u00020\u0017\u001a\u0006\u0010\"\u001a\u00020\u0017\u001a\u0006\u0010#\u001a\u00020\u0017\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\n\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DAYS", "", "HOURS", "MINUTES", "PROPERTY_CAMERA_MIC_ICONS_ENABLED", "", "PROPERTY_LOCATION_ACCURACY_ENABLED", "PROPERTY_LOCATION_INDICATORS_ENABLED", "PROPERTY_LOCATION_PRECISION", "PROPERTY_PERMISSIONS_HUB_2_ENABLED", "SECONDS", "calculateTimeDiffAndUnit", "Landroid/util/Pair;", "", "duration", "getAbsoluteLastUsageString", "context", "Landroid/content/Context;", "groupUsage", "Lcom/android/permissioncontroller/permission/model/AppPermissionUsage$GroupUsage;", "getAbsoluteTimeString", "lastAccessTime", "getDefaultPrecision", "", "getDurationUsedStr", "getTimeDiffStr", "getUsageDurationString", "isCameraMicIconsFlagEnabled", "isLocationAccuracyEnabled", "isLocationIndicatorsFlagEnabled", "isPermissionsHub2FlagEnabled", "isToday", "time", "shouldShowCameraMicIndicators", "shouldShowLocationIndicators", "shouldShowPermissionsDashboard"})
public final class UtilsKt {
    
    /**
     * Whether to show the Permissions Hub.
     */
    private static final java.lang.String PROPERTY_PERMISSIONS_HUB_2_ENABLED = "permissions_hub_2_enabled";
    
    /**
     * Whether to show the mic and camera icons.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PROPERTY_CAMERA_MIC_ICONS_ENABLED = "camera_mic_icons_enabled";
    
    /**
     * Whether to show the location indicators.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PROPERTY_LOCATION_INDICATORS_ENABLED = "location_indicators_enabled";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PROPERTY_LOCATION_ACCURACY_ENABLED = "location_accuracy_enabled";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PROPERTY_LOCATION_PRECISION = "location_precision";
    public static final int SECONDS = 1;
    public static final int MINUTES = 2;
    public static final int HOURS = 3;
    public static final int DAYS = 4;
    
    /**
     * Whether the Permissions Hub 2 flag is enabled
     *
     * @return whether the flag is enabled
     */
    public static final boolean isPermissionsHub2FlagEnabled() {
        return false;
    }
    
    /**
     * Whether to show the Permissions Dashboard
     *
     * @return whether to show the Permissions Dashboard.
     */
    public static final boolean shouldShowPermissionsDashboard() {
        return false;
    }
    
    /**
     * Whether the Camera and Mic Icons are enabled by flag.
     *
     * @return whether the Camera and Mic Icons are enabled.
     */
    public static final boolean isCameraMicIconsFlagEnabled() {
        return false;
    }
    
    /**
     * Whether to show Camera and Mic Icons. They should be shown if the permission hub, or the icons
     * specifically, are enabled.
     *
     * @return whether to show the icons.
     */
    public static final boolean shouldShowCameraMicIndicators() {
        return false;
    }
    
    /**
     * Whether the location indicators are enabled by flag.
     *
     * @return whether the location indicators are enabled by flag.
     */
    public static final boolean isLocationIndicatorsFlagEnabled() {
        return false;
    }
    
    /**
     * Whether to show the location indicators. The location indicators are enable if the
     * permission hub, or location indicator specifically are enabled.
     */
    public static final boolean shouldShowLocationIndicators() {
        return false;
    }
    
    /**
     * Whether the location accuracy feature is enabled
     */
    public static final boolean isLocationAccuracyEnabled() {
        return false;
    }
    
    /**
     * Default state of location precision
     * true: default is FINE.
     * false: default is COARSE.
     */
    public static final boolean getDefaultPrecision() {
        return false;
    }
    
    /**
     * Build a string representing the given time if it happened on the current day and the date
     * otherwise.
     *
     * @param context the context.
     * @param lastAccessTime the time in milliseconds.
     *
     * @return a string representing the time or date of the given time or null if the time is 0.
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getAbsoluteTimeString(@org.jetbrains.annotations.NotNull()
    android.content.Context context, long lastAccessTime) {
        return null;
    }
    
    /**
     * Build a string representing the time of the most recent permission usage if it happened on
     * the current day and the date otherwise.
     *
     * @param context the context.
     * @param groupUsage the permission usage.
     *
     * @return a string representing the time or date of the most recent usage or null if there are
     * no usages.
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getAbsoluteLastUsageString(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    com.android.permissioncontroller.permission.model.AppPermissionUsage.GroupUsage groupUsage) {
        return null;
    }
    
    /**
     * Build a string representing the duration of a permission usage.
     *
     * @return a string representing the duration of this app's usage or null if there are no
     * usages.
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getUsageDurationString(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    com.android.permissioncontroller.permission.model.AppPermissionUsage.GroupUsage groupUsage) {
        return null;
    }
    
    /**
     * Build a string representing the number of milliseconds passed in.  It rounds to the nearest
     * unit.  For example, given a duration of 3500 and an English locale, this can return
     * "3 seconds".
     * @param context The context.
     * @param duration The number of milliseconds.
     * @return a string representing the given number of milliseconds.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String getTimeDiffStr(@org.jetbrains.annotations.NotNull()
    android.content.Context context, long duration) {
        return null;
    }
    
    /**
     * Build a string representing the duration used of milliseconds passed in.
     * @return a string representing the duration used in the nearest unit. ex: Used for 3 mins
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String getDurationUsedStr(@org.jetbrains.annotations.NotNull()
    android.content.Context context, long duration) {
        return null;
    }
    
    /**
     * Given the duration in milliseconds, calculate the time of that duration in the nearest unit.
     * @return a Pair of the <duration in the nearest unit, the nearest unit>
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.util.Pair<java.lang.Long, java.lang.Integer> calculateTimeDiffAndUnit(long duration) {
        return null;
    }
    
    /**
     * Check whether the given time (in milliseconds) is in the current day.
     *
     * @param time the time in milliseconds
     *
     * @return whether the given time is in the current day.
     */
    private static final boolean isToday(long time) {
        return false;
    }
}