package com.android.permissioncontroller.permission.data;

import android.app.AppOpsManager;
import android.app.Application;
import android.os.Build;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;

/**
 * A liveData which tracks all packages in the system which have full file permissions, as
 * represented by the OPSTR_LEGACY_STORAGE app op, not just media-only storage permissions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00020\u0001:\u0001\u0016B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J$\u0010\t\u001a\u0004\u0018\u00010\u00032\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\n\b\u0002\u0010\u000e\u001a\u0004\u0018\u00010\u000fJ\u0019\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0014J\u0006\u0010\u0015\u001a\u00020\u0011R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/FullStoragePermissionAppsLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/data/FullStoragePermissionAppsLiveData$FullStoragePackageState;", "()V", "app", "Landroid/app/Application;", "standardPermGroupsPackagesLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData;", "getFullStorageStateForPackage", "appOpsManager", "Landroid/app/AppOpsManager;", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "userHandle", "Landroid/os/UserHandle;", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "recalculate", "FullStoragePackageState"})
public final class FullStoragePermissionAppsLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.List<? extends com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState>> {
    private static final android.app.Application app = null;
    private static final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData standardPermGroupsPackagesLiveData = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData INSTANCE = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    /**
     * Gets the full storage package information for a given package
     *
     * @param appOpsManager The App Ops manager to use, if applicable
     * @param packageInfo The package whose state is to be determined
     * @param userHandle A preexisting UserHandle object to use. Otherwise, one will be created
     *
     * @return the FullStoragePackageState for the package, or null if the package does not request
     * full storage permissions
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState getFullStorageStateForPackage(@org.jetbrains.annotations.NotNull()
    android.app.AppOpsManager appOpsManager, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, @org.jetbrains.annotations.Nullable()
    android.os.UserHandle userHandle) {
        return null;
    }
    
    /**
     * Recalculate the LiveData
     * TODO ntmyren: Make livedata properly observe app ops
     */
    public final void recalculate() {
    }
    
    private FullStoragePermissionAppsLiveData() {
        super(false, false);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u000f\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0010\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0011\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0007H\u00c6\u0003J1\u0010\u0013\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\u0007H\u00c6\u0001J\u0013\u0010\u0014\u001a\u00020\u00072\b\u0010\u0015\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0016\u001a\u00020\u0017H\u00d6\u0001J\t\u0010\u0018\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\nR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\nR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/permissioncontroller/permission/data/FullStoragePermissionAppsLiveData$FullStoragePackageState;", "", "packageName", "", "user", "Landroid/os/UserHandle;", "isLegacy", "", "isGranted", "(Ljava/lang/String;Landroid/os/UserHandle;ZZ)V", "()Z", "getPackageName", "()Ljava/lang/String;", "getUser", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString"})
    public static final class FullStoragePackageState {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String packageName = null;
        @org.jetbrains.annotations.NotNull()
        private final android.os.UserHandle user = null;
        private final boolean isLegacy = false;
        private final boolean isGranted = false;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPackageName() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.UserHandle getUser() {
            return null;
        }
        
        public final boolean isLegacy() {
            return false;
        }
        
        public final boolean isGranted() {
            return false;
        }
        
        public FullStoragePackageState(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, boolean isLegacy, boolean isGranted) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.UserHandle component2() {
            return null;
        }
        
        public final boolean component3() {
            return false;
        }
        
        public final boolean component4() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState copy(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, boolean isLegacy, boolean isGranted) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}