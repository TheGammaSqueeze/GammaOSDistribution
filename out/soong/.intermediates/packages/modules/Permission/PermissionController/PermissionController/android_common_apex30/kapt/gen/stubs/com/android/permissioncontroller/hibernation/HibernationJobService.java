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
 * A job to check for apps unused in the last [getUnusedThresholdMs]ms every
 * [getCheckFrequencyMs]ms and hibernate the app / revoke their runtime permissions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0012H\u0016J\u0012\u0010\u0013\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0012H\u0016J!\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\nH\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019R\u001c\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000e\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/hibernation/HibernationJobService;", "Landroid/app/job/JobService;", "()V", "job", "Lkotlinx/coroutines/Job;", "getJob", "()Lkotlinx/coroutines/Job;", "setJob", "(Lkotlinx/coroutines/Job;)V", "jobStartTime", "", "getJobStartTime", "()J", "setJobStartTime", "(J)V", "onStartJob", "", "params", "Landroid/app/job/JobParameters;", "onStopJob", "showUnusedAppsNotification", "", "numUnused", "", "sessionId", "(IJLkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class HibernationJobService extends android.app.job.JobService {
    @org.jetbrains.annotations.Nullable()
    private kotlinx.coroutines.Job job;
    private long jobStartTime = -1L;
    
    @org.jetbrains.annotations.Nullable()
    public final kotlinx.coroutines.Job getJob() {
        return null;
    }
    
    public final void setJob(@org.jetbrains.annotations.Nullable()
    kotlinx.coroutines.Job p0) {
    }
    
    public final long getJobStartTime() {
        return 0L;
    }
    
    public final void setJobStartTime(long p0) {
    }
    
    @java.lang.Override()
    public boolean onStartJob(@org.jetbrains.annotations.Nullable()
    android.app.job.JobParameters params) {
        return false;
    }
    
    @java.lang.Override()
    public boolean onStopJob(@org.jetbrains.annotations.Nullable()
    android.app.job.JobParameters params) {
        return false;
    }
    
    public HibernationJobService() {
        super();
    }
}