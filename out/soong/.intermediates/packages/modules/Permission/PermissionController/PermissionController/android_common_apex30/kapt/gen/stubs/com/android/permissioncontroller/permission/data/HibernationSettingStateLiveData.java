package com.android.permissioncontroller.permission.data;

import android.app.AppOpsManager;
import android.app.Application;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.HibernationSettingState;
import com.android.permissioncontroller.hibernation.ExemptServicesLiveData;
import com.android.permissioncontroller.hibernation.HibernationEnabledLiveData;

/**
 * A LiveData which tracks the hibernation/auto-revoke state for one user package.
 *
 * @param app The current application
 * @param packageName The package name whose state we want
 * @param user The user for whom we want the package
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u0000 \u001f2\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001\u001fB\u001f\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0019\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0019H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001aJ\b\u0010\u001b\u001a\u00020\u0017H\u0014J\b\u0010\u001c\u001a\u00020\u0017H\u0014J\u001c\u0010\u001d\u001a\u00020\u00172\b\u0010\u001e\u001a\u0004\u0018\u00010\u00072\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0013\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u00150\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/HibernationSettingStateLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/HibernationSettingState;", "Landroid/app/AppOpsManager$OnOpChangedListener;", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;)V", "appOpsManager", "Landroid/app/AppOpsManager;", "exemptServicesLiveData", "Lcom/android/permissioncontroller/hibernation/ExemptServicesLiveData;", "packageLiveData", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "packagePermsLiveData", "Lcom/android/permissioncontroller/permission/data/PackagePermissionsLiveData;", "permStateLiveDatas", "", "Lcom/android/permissioncontroller/permission/data/PermStateLiveData;", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onOpChanged", "op", "Companion"})
public final class HibernationSettingStateLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.HibernationSettingState> implements android.app.AppOpsManager.OnOpChangedListener {
    private final com.android.permissioncontroller.permission.data.PackagePermissionsLiveData packagePermsLiveData = null;
    private final com.android.permissioncontroller.permission.data.LightPackageInfoLiveData packageLiveData = null;
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.PermStateLiveData> permStateLiveDatas = null;
    private final com.android.permissioncontroller.hibernation.ExemptServicesLiveData exemptServicesLiveData = null;
    private final android.app.AppOpsManager appOpsManager = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @java.lang.Override()
    public void onOpChanged(@org.jetbrains.annotations.Nullable()
    java.lang.String op, @org.jetbrains.annotations.Nullable()
    java.lang.String packageName) {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private HibernationSettingStateLiveData(android.app.Application app, java.lang.String packageName, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for HibernationSettingStateLiveDatas.
     * <p> Key value is a pair of string package name and UserHandle, value is its corresponding
     * LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\u001c\u0010\u0007\u001a\u00020\u00052\u0012\u0010\b\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/HibernationSettingStateLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/HibernationSettingStateLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<java.lang.String, android.os.UserHandle> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}