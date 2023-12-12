package com.android.permissioncontroller.hibernation;

import android.Manifest;
import android.accessibilityservice.AccessibilityService;
import android.app.ActivityManager;
import android.app.AppOpsManager;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.admin.DeviceAdminReceiver;
import android.app.admin.DevicePolicyManager;
import android.app.job.JobInfo;
import android.app.job.JobParameters;
import android.app.job.JobScheduler;
import android.app.job.JobService;
import android.app.usage.UsageStats;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Process;
import android.os.UserHandle;
import android.os.UserManager;
import android.printservice.PrintService;
import android.provider.DeviceConfig;
import android.service.autofill.AutofillService;
import android.service.dreams.DreamService;
import android.service.notification.NotificationListenerService;
import android.service.voice.VoiceInteractionService;
import android.service.wallpaper.WallpaperService;
import android.util.Log;
import android.view.inputmethod.InputMethod;
import androidx.annotation.MainThread;
import androidx.lifecycle.MutableLiveData;
import androidx.preference.PreferenceManager;
import com.android.modules.utils.build.SdkLevel;
import com.android.permissioncontroller.Constants;
import com.android.permissioncontroller.DumpableLog;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.AllPackageInfosLiveData;
import com.android.permissioncontroller.permission.data.AppOpLiveData;
import com.android.permissioncontroller.permission.data.BroadcastReceiverLiveData;
import com.android.permissioncontroller.permission.data.CarrierPrivilegedStatusLiveData;
import com.android.permissioncontroller.permission.data.DataRepositoryForPackage;
import com.android.permissioncontroller.permission.data.HasIntentAction;
import com.android.permissioncontroller.permission.data.LauncherPackagesLiveData;
import com.android.permissioncontroller.permission.data.ServiceLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.data.UsageStatsLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;
import java.util.Date;
import java.util.Random;
import java.util.concurrent.TimeUnit;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000F\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u000f\n\u0002\u0018\u0002\n\u0002\b\u0002\u001a+\u0010\u0013\u001a\u0014\u0012\u0004\u0012\u00020\u0015\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00170\u00160\u00142\u0006\u0010\u0018\u001a\u00020\fH\u0083@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019\u001a\b\u0010\u001a\u001a\u00020\u0005H\u0002\u001a\u0006\u0010\u001b\u001a\u00020\u0005\u001a\u0006\u0010\u001c\u001a\u00020\u0001\u001a\u0006\u0010\u001d\u001a\u00020\u0001\u001a\u0006\u0010\u001e\u001a\u00020\u0001\u001a!\u0010\u001f\u001a\u00020\u00012\u0006\u0010 \u001a\u00020\u00172\u0006\u0010!\u001a\u00020\u0015H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\"\u001a!\u0010#\u001a\u00020\u00012\u0006\u0010\u0018\u001a\u00020\f2\u0006\u0010 \u001a\u00020\u0017H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010$\u001a\u0014\u0010%\u001a\u00020\u0001*\u00020\f2\u0006\u0010 \u001a\u00020\bH\u0002\u001a\n\u0010&\u001a\u00020\u0005*\u00020\'\u001a\u001a\u0010&\u001a\u00020\u0005*\b\u0012\u0004\u0012\u00020\'0\u00162\u0006\u0010(\u001a\u00020\bH\u0002\u001a \u0010&\u001a\u00020\u0005*\b\u0012\u0004\u0012\u00020\'0\u00162\f\u0010)\u001a\b\u0012\u0004\u0012\u00020\b0\u0016H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\n\u001a\u00020\u0001X\u0082\u000e\u00a2\u0006\u0002\n\u0000\"\u0018\u0010\u000b\u001a\u00020\u0005*\u00020\f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000e\"\u0015\u0010\u000f\u001a\u00020\u0010*\u00020\f8F\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\u0012\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"AUTO_REVOKE_ENABLED", "", "DEBUG_HIBERNATION_POLICY", "DEBUG_OVERRIDE_THRESHOLDS", "DEFAULT_CHECK_FREQUENCY_MS", "", "DEFAULT_UNUSED_THRESHOLD_MS", "LOG_TAG", "", "PREF_KEY_FIRST_BOOT_TIME", "SKIP_NEXT_RUN", "firstBootTime", "Landroid/content/Context;", "getFirstBootTime", "(Landroid/content/Context;)J", "sharedPreferences", "Landroid/content/SharedPreferences;", "getSharedPreferences", "(Landroid/content/Context;)Landroid/content/SharedPreferences;", "getAppsToHibernate", "", "Landroid/os/UserHandle;", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "context", "(Landroid/content/Context;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getCheckFrequencyMs", "getUnusedThresholdMs", "hibernationTargetsPreSApps", "isHibernationEnabled", "isHibernationJobEnabled", "isPackageHibernationExemptBySystem", "pkg", "user", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Landroid/os/UserHandle;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "isPackageHibernationExemptByUser", "(Landroid/content/Context;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "isPackageCrossProfile", "lastTimePackageUsed", "Landroid/app/usage/UsageStats;", "pkgName", "pkgNames"})
public final class HibernationPolicyKt {
    private static final java.lang.String LOG_TAG = "HibernationPolicy";
    public static final boolean DEBUG_OVERRIDE_THRESHOLDS = false;
    public static final boolean DEBUG_HIBERNATION_POLICY = true;
    private static final boolean AUTO_REVOKE_ENABLED = true;
    private static boolean SKIP_NEXT_RUN = false;
    private static final long DEFAULT_UNUSED_THRESHOLD_MS = 0L;
    private static final long DEFAULT_CHECK_FREQUENCY_MS = 0L;
    private static final java.lang.String PREF_KEY_FIRST_BOOT_TIME = "first_boot_time";
    
    public static final long getUnusedThresholdMs() {
        return 0L;
    }
    
    private static final long getCheckFrequencyMs() {
        return 0L;
    }
    
    public static final boolean isHibernationEnabled() {
        return false;
    }
    
    /**
     * Whether hibernation defaults on and affects apps that target pre-S. Has no effect if
     * [isHibernationEnabled] is false.
     */
    public static final boolean hibernationTargetsPreSApps() {
        return false;
    }
    
    public static final boolean isHibernationJobEnabled() {
        return false;
    }
    
    /**
     * Gets the last time we consider the package used based off its usage stats. On pre-S devices
     * this looks at last time visible which tracks explicit usage. In S, we add component usage
     * which tracks various forms of implicit usage (e.g. service bindings).
     */
    public static final long lastTimePackageUsed(@org.jetbrains.annotations.NotNull()
    android.app.usage.UsageStats $this$lastTimePackageUsed) {
        return 0L;
    }
    
    private static final long lastTimePackageUsed(java.util.List<android.app.usage.UsageStats> $this$lastTimePackageUsed, java.util.List<java.lang.String> pkgNames) {
        return 0L;
    }
    
    private static final long lastTimePackageUsed(java.util.List<android.app.usage.UsageStats> $this$lastTimePackageUsed, java.lang.String pkgName) {
        return 0L;
    }
    
    /**
     * Checks if the given package is exempt from hibernation in a way that's not user-overridable
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.Object isPackageHibernationExemptBySystem(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkg, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Boolean> p2) {
        return null;
    }
    
    /**
     * Checks if the given package is exempt from hibernation/auto revoke in a way that's
     * user-overridable
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.Object isPackageHibernationExemptByUser(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkg, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Boolean> p2) {
        return null;
    }
    
    private static final boolean isPackageCrossProfile(android.content.Context $this$isPackageCrossProfile, java.lang.String pkg) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final android.content.SharedPreferences getSharedPreferences(@org.jetbrains.annotations.NotNull()
    android.content.Context $this$sharedPreferences) {
        return null;
    }
    
    private static final long getFirstBootTime(android.content.Context $this$firstBootTime) {
        return 0L;
    }
}