package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;

/**
 * A LiveData which returns all of the preinstalled packageinfos. For packages that are preinstalled
 * and then updated, the preinstalled (i.e. old) version is returned.
 *
 * @param app The current application
 * @param user The user whose packages are desired
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 \u00102\u0013\u0012\u000f\u0012\r\u0012\u0004\u0012\u00020\u00030\u0002\u00a2\u0006\u0002\b\u00040\u0001:\u0001\u0010B\u0017\b\u0002\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u0019\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u000eJ\b\u0010\u000f\u001a\u00020\u000bH\u0014R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PreinstalledUserPackageInfosLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "Lkotlin/jvm/JvmSuppressWildcards;", "app", "Landroid/app/Application;", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Landroid/os/UserHandle;)V", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "Companion"})
public final class PreinstalledUserPackageInfosLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> {
    private final android.app.Application app = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PreinstalledUserPackageInfosLiveData.Companion Companion = null;
    
    /**
     * Get all of the preinstalled packages in the system for this user
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
    
    private PreinstalledUserPackageInfosLiveData(android.app.Application app, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for PreinstalledUserPackageInfosLiveData.
     *
     * <p>Key value is a UserHandle, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PreinstalledUserPackageInfosLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/PreinstalledUserPackageInfosLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<android.os.UserHandle, com.android.permissioncontroller.permission.data.PreinstalledUserPackageInfosLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.PreinstalledUserPackageInfosLiveData newValue(@org.jetbrains.annotations.NotNull()
        android.os.UserHandle key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}