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

/**
 * Live data for whether the hibernation feature is enabled or not.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\b\u00c6\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0003"}, d2 = {"Lcom/android/permissioncontroller/hibernation/HibernationEnabledLiveData;", "Landroidx/lifecycle/MutableLiveData;", "", "()V"})
public final class HibernationEnabledLiveData extends androidx.lifecycle.MutableLiveData<java.lang.Boolean> {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.hibernation.HibernationEnabledLiveData INSTANCE = null;
    
    private HibernationEnabledLiveData() {
        super(null);
    }
}