package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager;
import android.os.UserHandle;
import android.util.Log;
import androidx.annotation.MainThread;
import androidx.lifecycle.Observer;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * LiveData for a LightPackageInfo.
 *
 * @param app The current Application
 * @param packageName The name of the package this LiveData will watch for mode changes for
 * @param user The user for whom the packageInfo will be defined
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\u0018\u0000 *2\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u00032\u00020\u0004:\u0001*B\u001f\b\u0002\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0019\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!J\b\u0010\"\u001a\u00020\u001eH\u0014J\b\u0010#\u001a\u00020\u001eH\u0014J\u0010\u0010$\u001a\u00020\u001e2\u0006\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010%\u001a\u00020\u001eH\u0016J\u0012\u0010&\u001a\u00020\u001e2\b\u0010\'\u001a\u0004\u0018\u00010\u0002H\u0016J\b\u0010(\u001a\u00020\u001eH\u0016J\b\u0010)\u001a\u00020\u001eH\u0003R\u0016\u0010\f\u001a\n \r*\u0004\u0018\u00010\b0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0012R\u0012\u0010\u0013\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0012R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010\u0014\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00020\u00160\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "Lcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer$PermissionChangeCallback;", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "context", "Landroid/content/Context;", "registeredUid", "", "Ljava/lang/Integer;", "uid", "userPackageInfosObserver", "Landroidx/lifecycle/Observer;", "", "getUserPackageInfosObserver", "()Landroidx/lifecycle/Observer;", "userPackagesLiveData", "Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData;", "watchingUserPackagesLiveData", "", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onPackageUpdate", "onPermissionChange", "setValue", "newValue", "updateAsync", "updateFromUserPackageInfosLiveData", "Companion"})
public final class LightPackageInfoLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> implements com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener, com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback {
    private final java.lang.String LOG_TAG = null;
    private final com.android.permissioncontroller.permission.data.UserPackageInfosLiveData userPackagesLiveData = null;
    private android.content.Context context;
    private java.lang.Integer uid;
    
    /**
     * The currently registered UID on which this LiveData is listening for permission changes.
     */
    private java.lang.Integer registeredUid;
    
    /**
     * Whether or not this package livedata is watching the UserPackageInfosLiveData
     */
    private boolean watchingUserPackagesLiveData = false;
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.Observer<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> userPackageInfosObserver = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.LightPackageInfoLiveData.Companion Companion = null;
    
    /**
     * Callback from the PackageBroadcastReceiver. Either deletes or generates package data.
     *
     * @param packageName the name of the package which was updated. Ignored in this method
     */
    @java.lang.Override()
    public void onPackageUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    @java.lang.Override()
    public void setValue(@org.jetbrains.annotations.Nullable()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo newValue) {
    }
    
    @java.lang.Override()
    public void updateAsync() {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    /**
     * Callback from the PermissionListener. Either deletes or generates package data.
     */
    @java.lang.Override()
    public void onPermissionChange() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.Observer<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> getUserPackageInfosObserver() {
        return null;
    }
    
    @androidx.annotation.MainThread()
    private final void updateFromUserPackageInfosLiveData() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private LightPackageInfoLiveData(android.app.Application app, java.lang.String packageName, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for LightPackageInfoLiveDatas
     * <p> Key value is a string package name and UserHandle pair, value is its corresponding
     * LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\u001c\u0010\u0007\u001a\u00020\u00052\u0012\u0010\b\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.LightPackageInfoLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.LightPackageInfoLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<java.lang.String, android.os.UserHandle> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}