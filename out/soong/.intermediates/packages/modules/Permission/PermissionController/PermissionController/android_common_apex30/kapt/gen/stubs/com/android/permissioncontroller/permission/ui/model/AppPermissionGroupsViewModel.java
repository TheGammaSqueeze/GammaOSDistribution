package com.android.permissioncontroller.permission.ui.model;

import android.Manifest;
import android.app.AppOpsManager;
import android.apphibernation.AppHibernationManager;
import android.content.Context;
import android.os.Bundle;
import android.os.UserHandle;
import android.util.Log;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData;
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData;
import com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData;
import com.android.permissioncontroller.permission.data.LightPackageInfoLiveData;
import com.android.permissioncontroller.permission.data.PackagePermissionsLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.model.AppPermissionUsage;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState;
import com.android.permissioncontroller.permission.ui.Category;
import com.android.permissioncontroller.permission.utils.Utils;
import com.android.permissioncontroller.permission.utils.Utils.AppPermsLastAccessType;
import kotlinx.coroutines.GlobalScope;
import java.time.Instant;
import java.util.concurrent.TimeUnit;

/**
 * ViewModel for the AppPermissionGroupsFragment. Has a liveData with the UI information for all
 * permission groups that this package requests runtime permissions from
 *
 * @param packageName The name of the package this viewModel is representing
 * @param user The user of the package this viewModel is representing
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000|\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010%\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 /2\u00020\u0001:\u0003/01B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ0\u0010\u001a\u001a\u00020\u001b2\u0012\u0010\u001c\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00070\u001d2\f\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020\u001f0\u00152\u0006\u0010\u0002\u001a\u00020\u0003J%\u0010 \u001a\u00020\u00032\u0006\u0010!\u001a\u00020\u00162\u0006\u0010\"\u001a\u00020#2\b\u0010$\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\u0002\u0010%J\u000e\u0010&\u001a\u00020\u001b2\u0006\u0010\'\u001a\u00020(J\u0016\u0010)\u001a\u00020\u001b2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-J\u0016\u0010.\u001a\u00020\u001b2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-R\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R.\u0010\u0011\u001a\u001f\u0012\u001b\u0012\u0019\u0012\u0004\u0012\u00020\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00160\u00150\u0013\u00a2\u0006\u0002\b\u00170\u0012\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel;", "Landroidx/lifecycle/ViewModel;", "packageName", "", "user", "Landroid/os/UserHandle;", "sessionId", "", "(Ljava/lang/String;Landroid/os/UserHandle;J)V", "app", "Lcom/android/permissioncontroller/PermissionControllerApplication;", "getApp", "()Lcom/android/permissioncontroller/PermissionControllerApplication;", "autoRevokeLiveData", "Lcom/android/permissioncontroller/permission/data/HibernationSettingStateLiveData;", "getAutoRevokeLiveData", "()Lcom/android/permissioncontroller/permission/data/HibernationSettingStateLiveData;", "packagePermGroupsLiveData", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/ui/Category;", "", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$GroupUiInfo;", "Lkotlin/jvm/JvmSuppressWildcards;", "getPackagePermGroupsLiveData", "()Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "extractGroupUsageLastAccessTime", "", "accessTime", "", "appPermissionUsages", "Lcom/android/permissioncontroller/permission/model/AppPermissionUsage;", "getPreferenceSummary", "groupInfo", "context", "Landroid/content/Context;", "lastAccessTime", "(Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$GroupUiInfo;Landroid/content/Context;Ljava/lang/Long;)Ljava/lang/String;", "setAutoRevoke", "enabled", "", "showAllPermissions", "fragment", "Landroidx/fragment/app/Fragment;", "args", "Landroid/os/Bundle;", "showExtraPerms", "Companion", "GroupUiInfo", "PermSubtitle"})
public final class AppPermissionGroupsViewModel extends androidx.lifecycle.ViewModel {
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.PermissionControllerApplication app = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData autoRevokeLiveData = null;
    
    /**
     * LiveData whose data is a map of grant category (either allowed or denied) to a list
     * of permission group names that match the key, and two booleans representing if this is a
     * system group, and a subtitle resource ID, if applicable.
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.Category, java.util.List<com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.GroupUiInfo>>> packagePermGroupsLiveData = null;
    private final java.lang.String packageName = null;
    private final android.os.UserHandle user = null;
    private final long sessionId = 0L;
    public static final int AGGREGATE_DATA_FILTER_BEGIN_DAYS = 1;
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String LOG_TAG = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.PermissionControllerApplication getApp() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.HibernationSettingStateLiveData getAutoRevokeLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.Category, java.util.List<com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.GroupUiInfo>>> getPackagePermGroupsLiveData() {
        return null;
    }
    
    public final void setAutoRevoke(boolean enabled) {
    }
    
    public final void showExtraPerms(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    public final void showAllPermissions(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    public final void extractGroupUsageLastAccessTime(@org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, java.lang.Long> accessTime, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.permissioncontroller.permission.model.AppPermissionUsage> appPermissionUsages, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPreferenceSummary(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.GroupUiInfo groupInfo, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    java.lang.Long lastAccessTime) {
        return null;
    }
    
    public AppPermissionGroupsViewModel(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long sessionId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\b\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000b"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$PermSubtitle;", "", "value", "", "(Ljava/lang/String;II)V", "getValue", "()I", "NONE", "MEDIA_ONLY", "ALL_FILES", "FOREGROUND_ONLY", "BACKGROUND"})
    public static enum PermSubtitle {
        /*public static final*/ NONE /* = new NONE(0) */,
        /*public static final*/ MEDIA_ONLY /* = new MEDIA_ONLY(0) */,
        /*public static final*/ ALL_FILES /* = new ALL_FILES(0) */,
        /*public static final*/ FOREGROUND_ONLY /* = new FOREGROUND_ONLY(0) */,
        /*public static final*/ BACKGROUND /* = new BACKGROUND(0) */;
        private final int value = 0;
        
        public final int getValue() {
            return 0;
        }
        
        PermSubtitle(int value) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B\u0017\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0010\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0011\u001a\u00020\bH\u00c6\u0003J\'\u0010\u0012\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\bH\u00c6\u0001J\u0013\u0010\u0013\u001a\u00020\u00052\b\u0010\u0014\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0015\u001a\u00020\u0016H\u00d6\u0001J\t\u0010\u0017\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0004\u0010\fR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$GroupUiInfo;", "", "groupName", "", "isSystem", "", "(Ljava/lang/String;Z)V", "subtitle", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$PermSubtitle;", "(Ljava/lang/String;ZLcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$PermSubtitle;)V", "getGroupName", "()Ljava/lang/String;", "()Z", "getSubtitle", "()Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$PermSubtitle;", "component1", "component2", "component3", "copy", "equals", "other", "hashCode", "", "toString"})
    public static final class GroupUiInfo {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String groupName = null;
        private final boolean isSystem = false;
        @org.jetbrains.annotations.NotNull()
        private final com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.PermSubtitle subtitle = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getGroupName() {
            return null;
        }
        
        public final boolean isSystem() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.PermSubtitle getSubtitle() {
            return null;
        }
        
        public GroupUiInfo(@org.jetbrains.annotations.NotNull()
        java.lang.String groupName, boolean isSystem, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.PermSubtitle subtitle) {
            super();
        }
        
        public GroupUiInfo(@org.jetbrains.annotations.NotNull()
        java.lang.String groupName, boolean isSystem) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        public final boolean component2() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.PermSubtitle component3() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.GroupUiInfo copy(@org.jetbrains.annotations.NotNull()
        java.lang.String groupName, boolean isSystem, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.AppPermissionGroupsViewModel.PermSubtitle subtitle) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionGroupsViewModel$Companion;", "", "()V", "AGGREGATE_DATA_FILTER_BEGIN_DAYS", "", "LOG_TAG", "", "getLOG_TAG", "()Ljava/lang/String;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getLOG_TAG() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}