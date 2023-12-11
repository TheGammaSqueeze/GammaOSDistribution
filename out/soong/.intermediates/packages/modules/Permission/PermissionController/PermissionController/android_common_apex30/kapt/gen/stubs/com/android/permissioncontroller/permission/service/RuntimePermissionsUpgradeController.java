package com.android.permissioncontroller.permission.service;

import android.Manifest.permission;
import android.Manifest.permission_group;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PermissionInfo;
import android.permission.PermissionManager;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData;
import com.android.permissioncontroller.permission.data.LightPermInfoLiveData;
import com.android.permissioncontroller.permission.data.PreinstalledUserPackageInfosLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.data.UserPackageInfosLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermission;
import kotlinx.coroutines.GlobalScope;

/**
 * This class handles upgrading the runtime permissions database
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u00c0\u0002\u0018\u00002\u00020\u0001:\u0003\"#$B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J4\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\u00060\f2\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000e0\t2\b\b\u0002\u0010\u000f\u001a\u00020\u0004H\u0002J!\u0010\u0010\u001a\u00020\u00042\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0004H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0014Jt\u0010\u0015\u001a \u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\n0\t\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00170\t0\u00162\u0006\u0010\u0018\u001a\u00020\u00042\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000e0\t2\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00060\f2\f\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u001b0\t2\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001b0\t2\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u001b0\tH\u0002J\u0016\u0010\u001e\u001a\u00020\u001f2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010 \u001a\u00020!R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController;", "", "()V", "LATEST_VERSION", "", "LOG_TAG", "", "kotlin.jvm.PlatformType", "getExemptions", "", "Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController$RestrictionExemption;", "permissions", "", "pkgs", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "flags", "onUpgradeLocked", "context", "Landroid/content/Context;", "currentVersion", "(Landroid/content/Context;ILkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onUpgradeLockedDataLoaded", "Lkotlin/Triple;", "Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController$Grant;", "currVersion", "restrictedPermissions", "bgApps", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "accessMediaApps", "bgMicApps", "upgradeIfNeeded", "", "onComplete", "Ljava/lang/Runnable;", "Grant", "RestrictionExemption", "UpgradeData"})
public final class RuntimePermissionsUpgradeController {
    private static final java.lang.String LOG_TAG = null;
    private static final int LATEST_VERSION = 9;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController INSTANCE = null;
    
    public final void upgradeIfNeeded(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable onComplete) {
    }
    
    /**
     * Create exemptions for select restricted permissions of select apps.
     *
     * @param permissionInfos permissions to exempt
     * @param pkgs packages to exempt
     *
     * @return the exemptions to apply
     */
    private final java.util.List<com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.RestrictionExemption> getExemptions(java.util.Set<java.lang.String> permissions, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> pkgs, int flags) {
        return null;
    }
    
    private final kotlin.Triple<java.lang.Integer, java.util.List<com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.RestrictionExemption>, java.util.List<com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.Grant>> onUpgradeLockedDataLoaded(int currVersion, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> pkgs, java.util.Set<java.lang.String> restrictedPermissions, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgApps, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> accessMediaApps, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgMicApps) {
        return null;
    }
    
    private RuntimePermissionsUpgradeController() {
        super();
    }
    
    /**
     * All data needed by {@link #onUpgradeLocked}
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0082\b\u0018\u00002\u00020\u0001BY\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u0012\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u0012\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\u0002\u0010\rJ\u000f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u000f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006H\u00c6\u0003J\u000f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u000f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0003J\u000f\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0003J\u000f\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0003Ji\u0010\u001c\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u000e\b\u0002\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u00062\u000e\b\u0002\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u000e\b\u0002\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u00032\u000e\b\u0002\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\u00032\u000e\b\u0002\u0010\f\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0001J\u0013\u0010\u001d\u001a\u00020\u001e2\b\u0010\u001f\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010 \u001a\u00020!H\u00d6\u0001J\t\u0010\"\u001a\u00020\u0007H\u00d6\u0001R\u0017\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0017\u0010\f\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000fR\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u000fR\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u000fR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0017\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u000f"}, d2 = {"Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController$UpgradeData;", "", "preinstalledPkgs", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "restrictedPermissions", "", "", "pkgs", "bgGroups", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "storageGroups", "bgMicGroups", "(Ljava/util/List;Ljava/util/Set;Ljava/util/List;Ljava/util/List;Ljava/util/List;Ljava/util/List;)V", "getBgGroups", "()Ljava/util/List;", "getBgMicGroups", "getPkgs", "getPreinstalledPkgs", "getRestrictedPermissions", "()Ljava/util/Set;", "getStorageGroups", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "equals", "", "other", "hashCode", "", "toString"})
    static final class UpgradeData {
        
        /**
         * Preinstalled packages
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> preinstalledPkgs = null;
        
        /**
         * Restricted permissions
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.Set<java.lang.String> restrictedPermissions = null;
        
        /**
         * Currently installed packages
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> pkgs = null;
        
        /**
         * Background Location groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgGroups = null;
        
        /**
         * Storage groups that need to be inspected by {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> storageGroups = null;
        
        /**
         * Background Microphone groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgMicGroups = null;
        
        /**
         * Preinstalled packages
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> getPreinstalledPkgs() {
            return null;
        }
        
        /**
         * Restricted permissions
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.String> getRestrictedPermissions() {
            return null;
        }
        
        /**
         * Currently installed packages
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> getPkgs() {
            return null;
        }
        
        /**
         * Background Location groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> getBgGroups() {
            return null;
        }
        
        /**
         * Storage groups that need to be inspected by {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> getStorageGroups() {
            return null;
        }
        
        /**
         * Background Microphone groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> getBgMicGroups() {
            return null;
        }
        
        public UpgradeData(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> preinstalledPkgs, @org.jetbrains.annotations.NotNull()
        java.util.Set<java.lang.String> restrictedPermissions, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> pkgs, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgGroups, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> storageGroups, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgMicGroups) {
            super();
        }
        
        /**
         * Preinstalled packages
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> component1() {
            return null;
        }
        
        /**
         * Restricted permissions
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.String> component2() {
            return null;
        }
        
        /**
         * Currently installed packages
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> component3() {
            return null;
        }
        
        /**
         * Background Location groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> component4() {
            return null;
        }
        
        /**
         * Storage groups that need to be inspected by {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> component5() {
            return null;
        }
        
        /**
         * Background Microphone groups that need to be inspected by
         * {@link #onUpgradeLockedDataLoaded}
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> component6() {
            return null;
        }
        
        /**
         * All data needed by {@link #onUpgradeLocked}
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.UpgradeData copy(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> preinstalledPkgs, @org.jetbrains.annotations.NotNull()
        java.util.Set<java.lang.String> restrictedPermissions, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> pkgs, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgGroups, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> storageGroups, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> bgMicGroups) {
            return null;
        }
        
        /**
         * All data needed by {@link #onUpgradeLocked}
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * All data needed by {@link #onUpgradeLocked}
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * All data needed by {@link #onUpgradeLocked}
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * A restricted permission of an app that should be exempted
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0082\b\u0018\u00002\u00020\u0001B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010J\t\u0010\u0011\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0013\u001a\u00020\u0006H\u00c6\u0003J\'\u0010\u0014\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u0015\u001a\u00020\u00162\b\u0010\u0017\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0018\u001a\u00020\u0006H\u00d6\u0001J\t\u0010\u0019\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\u000b"}, d2 = {"Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController$RestrictionExemption;", "", "pkgName", "", "permission", "flags", "", "(Ljava/lang/String;Ljava/lang/String;I)V", "getFlags", "()I", "getPermission", "()Ljava/lang/String;", "getPkgName", "applyToPlatform", "", "context", "Landroid/content/Context;", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "toString"})
    static final class RestrictionExemption {
        
        /**
         * Name of package to exempt
         */
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String pkgName = null;
        
        /**
         * Name of permissions to exempt
         */
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String permission = null;
        
        /**
         * Name of permissions to exempt
         */
        private final int flags = 0;
        
        /**
         * Exempt the permission by updating the platform state.
         *
         * @param context context to use when calling the platform
         */
        public final void applyToPlatform(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
        }
        
        /**
         * Name of package to exempt
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPkgName() {
            return null;
        }
        
        /**
         * Name of permissions to exempt
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPermission() {
            return null;
        }
        
        /**
         * Name of permissions to exempt
         */
        public final int getFlags() {
            return 0;
        }
        
        public RestrictionExemption(@org.jetbrains.annotations.NotNull()
        java.lang.String pkgName, @org.jetbrains.annotations.NotNull()
        java.lang.String permission, int flags) {
            super();
        }
        
        /**
         * Name of package to exempt
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        /**
         * Name of permissions to exempt
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component2() {
            return null;
        }
        
        /**
         * Name of permissions to exempt
         */
        public final int component3() {
            return 0;
        }
        
        /**
         * A restricted permission of an app that should be exempted
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.RestrictionExemption copy(@org.jetbrains.annotations.NotNull()
        java.lang.String pkgName, @org.jetbrains.annotations.NotNull()
        java.lang.String permission, int flags) {
            return null;
        }
        
        /**
         * A restricted permission of an app that should be exempted
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * A restricted permission of an app that should be exempted
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * A restricted permission of an app that should be exempted
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * A permission group of an app that should get granted
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u001c\n\u0000\b\u0082\b\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u000e\b\u0002\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u00a2\u0006\u0002\u0010\tJ\u000e\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rJ\t\u0010\u000e\u001a\u00020\u0003H\u00c2\u0003J\t\u0010\u000f\u001a\u00020\u0005H\u00c2\u0003J\u000f\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u00c2\u0003J-\u0010\u0011\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\u000e\b\u0002\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u00c6\u0001J\u0013\u0010\u0012\u001a\u00020\u00032\b\u0010\u0013\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0014\u001a\u00020\u0015H\u00d6\u0001J\u001e\u0010\u0016\u001a\u00020\u000b2\u0006\u0010\u0017\u001a\u00020\u00052\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\b0\u0019H\u0002J\t\u0010\u001a\u001a\u00020\bH\u00d6\u0001R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/service/RuntimePermissionsUpgradeController$Grant;", "", "isBackground", "", "group", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "permissions", "", "", "(ZLcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;Ljava/util/List;)V", "applyToPlatform", "", "context", "Landroid/content/Context;", "component1", "component2", "component3", "copy", "equals", "other", "hashCode", "", "logRuntimePermissionUpgradeResult", "permissionGroup", "filterPermissions", "", "toString"})
    static final class Grant {
        
        /**
         * Should the grant be for the foreground or background permissions
         */
        private final boolean isBackground = false;
        
        /**
         * Group to be granted
         */
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group = null;
        
        /**
         * Which of th permissions in the group should be granted
         */
        private final java.util.List<java.lang.String> permissions = null;
        
        /**
         * Grant the permission by updating the platform state.
         *
         * @param context context to use when calling the platform
         */
        public final void applyToPlatform(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
        }
        
        /**
         * Log to the platform that permissions were granted due to an update
         *
         * @param permissionGroup The group that was granted
         * @param filterPermissions Out of the group which permissions were granted
         */
        private final void logRuntimePermissionUpgradeResult(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup permissionGroup, java.lang.Iterable<java.lang.String> filterPermissions) {
        }
        
        public Grant(boolean isBackground, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> permissions) {
            super();
        }
        
        /**
         * Should the grant be for the foreground or background permissions
         */
        private final boolean component1() {
            return false;
        }
        
        /**
         * Group to be granted
         */
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup component2() {
            return null;
        }
        
        /**
         * Which of th permissions in the group should be granted
         */
        private final java.util.List<java.lang.String> component3() {
            return null;
        }
        
        /**
         * A permission group of an app that should get granted
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.service.RuntimePermissionsUpgradeController.Grant copy(boolean isBackground, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> permissions) {
            return null;
        }
        
        /**
         * A permission group of an app that should get granted
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * A permission group of an app that should get granted
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * A permission group of an app that should get granted
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}