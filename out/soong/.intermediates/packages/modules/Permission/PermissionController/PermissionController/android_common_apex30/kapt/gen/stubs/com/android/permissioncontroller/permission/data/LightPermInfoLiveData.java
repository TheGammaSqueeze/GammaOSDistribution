package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo;

/**
 * LiveData for a LightPermInfo.
 *
 * @param app current Application
 * @param permissionName name of the permission this LiveData will watch for mode changes for
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\u0018\u0000 \u001a2\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001\u001aB\u0017\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010\r\u001a\u00020\fH\u0002J\u0019\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0012J\b\u0010\u0013\u001a\u00020\u000fH\u0014J\b\u0010\u0014\u001a\u00020\u000fH\u0014J\u0010\u0010\u0015\u001a\u00020\u000f2\u0006\u0010\u0016\u001a\u00020\u0007H\u0016J\b\u0010\u0017\u001a\u00020\u000fH\u0002J\b\u0010\u0018\u001a\u00020\u000fH\u0002J\b\u0010\u0019\u001a\u00020\u000fH\u0016R\u0016\u0010\t\u001a\n \n*\u0004\u0018\u00010\u00070\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightPermInfoLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "app", "Landroid/app/Application;", "permissionName", "", "(Landroid/app/Application;Ljava/lang/String;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "isListeningForChanges", "", "isImmutable", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onPackageUpdate", "ignored", "startListeningForChanges", "stopListeningForChanges", "updateAsync", "Companion"})
public final class LightPermInfoLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> implements com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener {
    private final java.lang.String LOG_TAG = null;
    
    /**
     * Is this liveData currently listing for changes
     */
    private boolean isListeningForChanges = false;
    private final android.app.Application app = null;
    private final java.lang.String permissionName = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.LightPermInfoLiveData.Companion Companion = null;
    
    /**
     * Callback from the PackageBroadcastReceiver.
     *
     * <p>Package updates might change permission properties
     */
    @java.lang.Override()
    public void onPackageUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String ignored) {
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
     * @return if the permission state can never change
     */
    private final boolean isImmutable() {
        return false;
    }
    
    /**
     * Start listing for changes to this permission if needed
     */
    private final void startListeningForChanges() {
    }
    
    /**
     * Stop listing for changes to this permission
     */
    private final void stopListeningForChanges() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private LightPermInfoLiveData(android.app.Application app, java.lang.String permissionName) {
        super(false, false);
    }
    
    /**
     * Repository for LightPermInfoLiveData
     *
     * <p>Key value is a string permission name, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightPermInfoLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "", "Lcom/android/permissioncontroller/permission/data/LightPermInfoLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<java.lang.String, com.android.permissioncontroller.permission.data.LightPermInfoLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.LightPermInfoLiveData newValue(@org.jetbrains.annotations.NotNull()
        java.lang.String key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}