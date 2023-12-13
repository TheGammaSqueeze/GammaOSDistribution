package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;

/**
 * A LiveData which tracks all of the packageinfos installed for a given user.
 *
 * @param app The current application
 * @param user The user whose packages are desired
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0004\u0018\u0000 \u001f2\u0013\u0012\u000f\u0012\r\u0012\u0004\u0012\u00020\u00030\u0002\u00a2\u0006\u0002\b\u00040\u00012\u00020\u00052\u00020\u0006:\u0001\u001fB\u0017\b\u0002\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0019\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0015H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0016J\b\u0010\u0017\u001a\u00020\u0013H\u0014J\b\u0010\u0018\u001a\u00020\u0013H\u0014J\u0010\u0010\u0019\u001a\u00020\u00132\u0006\u0010\u001a\u001a\u00020\u001bH\u0016J\b\u0010\u001c\u001a\u00020\u0013H\u0016J\u0018\u0010\u001d\u001a\u00020\u00132\u000e\u0010\u001e\u001a\n\u0012\u0004\u0012\u00020\u0003\u0018\u00010\u0002H\u0016R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\f\u001a\u00020\rX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000f\"\u0004\b\u0010\u0010\u0011R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "Lkotlin/jvm/JvmSuppressWildcards;", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "Lcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer$PermissionChangeCallback;", "app", "Landroid/app/Application;", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Landroid/os/UserHandle;)V", "permChangeStale", "", "getPermChangeStale", "()Z", "setPermChangeStale", "(Z)V", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onPackageUpdate", "packageName", "", "onPermissionChange", "setValue", "newValue", "Companion"})
public final class UserPackageInfosLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> implements com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener, com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback {
    
    /**
     * Whether or not the permissions in this liveData are out of date
     */
    private boolean permChangeStale = false;
    private final android.app.Application app = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.UserPackageInfosLiveData.Companion Companion = null;
    
    public final boolean getPermChangeStale() {
        return false;
    }
    
    public final void setPermChangeStale(boolean p0) {
    }
    
    @java.lang.Override()
    public void onPackageUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    @java.lang.Override()
    public void onPermissionChange() {
    }
    
    @java.lang.Override()
    public void setValue(@org.jetbrains.annotations.Nullable()
    java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> newValue) {
    }
    
    /**
     * Get all of the packages in the system, organized by user.
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private UserPackageInfosLiveData(android.app.Application app, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for UserPackageInfosLiveDatas.
     * <p> Key value is a UserHandle, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<android.os.UserHandle, com.android.permissioncontroller.permission.data.UserPackageInfosLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.UserPackageInfosLiveData newValue(@org.jetbrains.annotations.NotNull()
        android.os.UserHandle key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}