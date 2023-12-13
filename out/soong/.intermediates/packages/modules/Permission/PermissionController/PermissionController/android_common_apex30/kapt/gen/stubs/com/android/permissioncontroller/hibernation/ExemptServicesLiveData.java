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
 * Packages using exempt services for the current user (package-name -> list<service-interfaces>
 * implemented by the package)
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\u0018\u0000 \u000e2\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00040\u00020\u0001:\u0001\u000eB\r\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\b\u0010\f\u001a\u00020\rH\u0014R \u0010\b\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\t0\u00010\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/permissioncontroller/hibernation/ExemptServicesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "", "user", "Landroid/os/UserHandle;", "(Landroid/os/UserHandle;)V", "serviceLiveDatas", "", "getUser", "()Landroid/os/UserHandle;", "onUpdate", "", "Companion"})
public final class ExemptServicesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<java.lang.String, ? extends java.util.List<? extends java.lang.String>>> {
    private final java.util.List<com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Set<java.lang.String>>> serviceLiveDatas = null;
    @org.jetbrains.annotations.NotNull()
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.hibernation.ExemptServicesLiveData.Companion Companion = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle getUser() {
        return null;
    }
    
    public ExemptServicesLiveData(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        super(false);
    }
    
    /**
     * Repository for ExemptServiceLiveData
     *
     * <p> Key value is user
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/hibernation/ExemptServicesLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/hibernation/ExemptServicesLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<android.os.UserHandle, com.android.permissioncontroller.hibernation.ExemptServicesLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.hibernation.ExemptServicesLiveData newValue(@org.jetbrains.annotations.NotNull()
        android.os.UserHandle key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}