package com.android.permissioncontroller.permission.data;

import android.annotation.SuppressLint;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.UserHandle;
import android.os.UserManager;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * Live data of the users of the current profile group.
 *
 *
 * Data source: system server
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\b\u00c6\u0002\u0018\u00002\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\b\u0010\n\u001a\u00020\u000bH\u0014J\b\u0010\f\u001a\u00020\u000bH\u0014J\b\u0010\r\u001a\u00020\u000bH\u0014R\u0018\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u00068\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UsersLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Landroid/os/UserHandle;", "()V", "app", "Lcom/android/permissioncontroller/PermissionControllerApplication;", "kotlin.jvm.PlatformType", "mUserMonitor", "Landroid/content/BroadcastReceiver;", "onActive", "", "onInactive", "onUpdate"})
public final class UsersLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.List<? extends android.os.UserHandle>> {
    @android.annotation.SuppressLint(value = {"StaticFieldLeak"})
    private static final com.android.permissioncontroller.PermissionControllerApplication app = null;
    
    /**
     * Monitors changes to the users on this device
     */
    private static final android.content.BroadcastReceiver mUserMonitor = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.UsersLiveData INSTANCE = null;
    
    /**
     * Update the encapsulated data with the current list of users.
     */
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private UsersLiveData() {
        super(false);
    }
}