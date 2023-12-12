package com.android.permissioncontroller.permission.ui.model;

import android.app.Application;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.UserHandle;
import android.provider.Settings;
import android.util.Log;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.permission.data.AllPackageInfosLiveData;
import com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData;
import com.android.permissioncontroller.permission.data.UsageStatsLiveData;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;

/**
 * UnusedAppsViewModel for the AutoRevokeFragment. Has a livedata which provides all unused apps,
 * organized by how long they have been unused.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 !2\u00020\u0001:\u0003!\"#B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u000f\u001a\u00020\u0010J\u0016\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J \u0010\u0017\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0018\u001a\u00020\u0019H\u0002J&\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u001b\u001a\u00020\u00142\u0006\u0010\u001c\u001a\u00020\u0010J\u001e\u0010\u001d\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0004\u001a\u00020\u0005J\u001e\u0010\u001e\u001a\u00020\u00122\u0006\u0010\u001f\u001a\u00020 2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R)\u0010\u0007\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\n\u0012\n\u0012\b\u0012\u0004\u0012\u00020\f0\u000b0\t0\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel;", "Landroidx/lifecycle/ViewModel;", "app", "Landroid/app/Application;", "sessionId", "", "(Landroid/app/Application;J)V", "unusedPackageCategoriesLiveData", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Months;", "", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$UnusedPackageInfo;", "getUnusedPackageCategoriesLiveData", "()Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "areUnusedPackagesLoaded", "", "disableApp", "", "packageName", "", "user", "Landroid/os/UserHandle;", "logAppInteraction", "action", "", "logAppView", "groupName", "isNew", "navigateToAppInfo", "requestUninstallApp", "fragment", "Landroidx/fragment/app/Fragment;", "Companion", "Months", "UnusedPackageInfo"})
public final class UnusedAppsViewModel extends androidx.lifecycle.ViewModel {
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months, java.util.List<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.UnusedPackageInfo>>> unusedPackageCategoriesLiveData = null;
    private final android.app.Application app = null;
    private final long sessionId = 0L;
    private static final long SIX_MONTHS_MILLIS = 0L;
    private static final java.lang.String LOG_TAG = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months, java.util.List<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.UnusedPackageInfo>>> getUnusedPackageCategoriesLiveData() {
        return null;
    }
    
    public final boolean areUnusedPackagesLoaded() {
        return false;
    }
    
    public final void navigateToAppInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long sessionId) {
    }
    
    public final void requestUninstallApp(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
    }
    
    public final void disableApp(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
    }
    
    private final void logAppInteraction(java.lang.String packageName, android.os.UserHandle user, int action) {
    }
    
    public final void logAppView(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName, boolean isNew) {
    }
    
    public UnusedAppsViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app, long sessionId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0006\b\u0086\u0001\u0018\u0000 \t2\b\u0012\u0004\u0012\u00020\u00000\u0001:\u0001\tB\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006j\u0002\b\u0007j\u0002\b\b"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Months;", "", "value", "", "(Ljava/lang/String;ILjava/lang/String;)V", "getValue", "()Ljava/lang/String;", "THREE", "SIX", "Companion"})
    public static enum Months {
        /*public static final*/ THREE /* = new THREE(null) */,
        /*public static final*/ SIX /* = new SIX(null) */;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String value = null;
        @org.jetbrains.annotations.NotNull()
        public static final com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months.Companion Companion = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getValue() {
            return null;
        }
        
        Months(java.lang.String value) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public static final java.util.List<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months> allMonths() {
            return null;
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004H\u0007"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Months$Companion;", "", "()V", "allMonths", "", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Months;"})
        public static final class Companion {
            
            @org.jetbrains.annotations.NotNull()
            public final java.util.List<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months> allMonths() {
                return null;
            }
            
            private Companion() {
                super();
            }
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\"\n\u0002\b\u0011\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B+\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00030\t\u00a2\u0006\u0002\u0010\nJ\t\u0010\u0013\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0014\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0007H\u00c6\u0003J\u000f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00030\tH\u00c6\u0003J7\u0010\u0017\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\u000e\b\u0002\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00030\tH\u00c6\u0001J\u0013\u0010\u0018\u001a\u00020\u00072\b\u0010\u0019\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001a\u001a\u00020\u001bH\u00d6\u0001J\t\u0010\u001c\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00030\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$UnusedPackageInfo;", "", "packageName", "", "user", "Landroid/os/UserHandle;", "shouldDisable", "", "revokedGroups", "", "(Ljava/lang/String;Landroid/os/UserHandle;ZLjava/util/Set;)V", "getPackageName", "()Ljava/lang/String;", "getRevokedGroups", "()Ljava/util/Set;", "getShouldDisable", "()Z", "getUser", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString"})
    public static final class UnusedPackageInfo {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String packageName = null;
        @org.jetbrains.annotations.NotNull()
        private final android.os.UserHandle user = null;
        private final boolean shouldDisable = false;
        @org.jetbrains.annotations.NotNull()
        private final java.util.Set<java.lang.String> revokedGroups = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPackageName() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.UserHandle getUser() {
            return null;
        }
        
        public final boolean getShouldDisable() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.String> getRevokedGroups() {
            return null;
        }
        
        public UnusedPackageInfo(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, boolean shouldDisable, @org.jetbrains.annotations.NotNull()
        java.util.Set<java.lang.String> revokedGroups) {
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
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.String> component4() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.UnusedPackageInfo copy(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, boolean shouldDisable, @org.jetbrains.annotations.NotNull()
        java.util.Set<java.lang.String> revokedGroups) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0016\u0010\u0003\u001a\n \u0005*\u0004\u0018\u00010\u00040\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Companion;", "", "()V", "LOG_TAG", "", "kotlin.jvm.PlatformType", "SIX_MONTHS_MILLIS", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}