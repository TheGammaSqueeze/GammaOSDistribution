package com.android.permissioncontroller.permission.model.livedatatypes;

import android.Manifest;
import android.os.Build;
import android.os.UserHandle;

/**
 * A lightweight version of the AppPermissionGroup data structure. Represents information about a
 * package, and all permissions in a particular permission group this package requests.
 *
 * @param packageInfo Information about the package
 * @param permGroupInfo Information about the permission group
 * @param allPermissions The permissions in the permission group that the package requests
 * (including restricted ones).
 * @param hasInstallToRuntimeSplit If this group contains a permission that was previously an
 * install permission, but is currently a runtime permission
 * @param specialLocationGrant If this package is the location provider, or the extra location
 * package, then the grant state of the group is not determined by the grant state of individual
 * permissions, but by other system properties
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\b%\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\b\u0018\u00002\u00020\u0001:\u0001NB+\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0012\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007\u00a2\u0006\u0002\u0010\nB;\u0012\u0006\u0010\u000b\u001a\u00020\u0003\u0012\u0006\u0010\f\u001a\u00020\u0005\u0012\u0012\u0010\r\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\b\u0010\u0010\u001a\u0004\u0018\u00010\u000f\u00a2\u0006\u0002\u0010\u0011J\t\u0010B\u001a\u00020\u0003H\u00c6\u0003J\t\u0010C\u001a\u00020\u0005H\u00c6\u0003J\u0015\u0010D\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007H\u00c6\u0003J\t\u0010E\u001a\u00020\u000fH\u00c6\u0003J\u0010\u0010F\u001a\u0004\u0018\u00010\u000fH\u00c6\u0003\u00a2\u0006\u0002\u0010:JN\u0010G\u001a\u00020\u00002\b\b\u0002\u0010\u000b\u001a\u00020\u00032\b\b\u0002\u0010\f\u001a\u00020\u00052\u0014\b\u0002\u0010\r\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u00072\b\b\u0002\u0010\u000e\u001a\u00020\u000f2\n\b\u0002\u0010\u0010\u001a\u0004\u0018\u00010\u000fH\u00c6\u0001\u00a2\u0006\u0002\u0010HJ\u0013\u0010I\u001a\u00020\u000f2\b\u0010J\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010K\u001a\u00020LH\u00d6\u0001J\t\u0010M\u001a\u00020\bH\u00d6\u0001R\u001d\u0010\r\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\u0014\u001a\u00020\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0017\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\b0\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u0011\u0010\u001c\u001a\u00020\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u0017R\u0017\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020\b0\u00198F\u00a2\u0006\u0006\u001a\u0004\b\u001f\u0010\u001bR\u0011\u0010 \u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\"R\u0011\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\"R\u0011\u0010$\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010\"R\u0011\u0010&\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\"R\u0011\u0010\'\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\"R\u0011\u0010(\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\"R\u0011\u0010)\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b)\u0010\"R\u0011\u0010*\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b*\u0010\"R\u0011\u0010+\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b+\u0010\"R\u0011\u0010,\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010\"R\u0011\u0010-\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b-\u0010\"R\u0011\u0010\u000b\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010/R\u0011\u00100\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b1\u00102R\u0011\u0010\f\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b3\u00104R\u0011\u00105\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b6\u00102R\u001d\u00107\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b8\u0010\u0013R\u0015\u0010\u0010\u001a\u0004\u0018\u00010\u000f\u00a2\u0006\n\n\u0002\u0010;\u001a\u0004\b9\u0010:R\u0011\u0010<\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b=\u0010\"R\u0011\u0010>\u001a\u00020?\u00a2\u0006\b\n\u0000\u001a\u0004\b@\u0010A"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "", "pI", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "pGI", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "perms", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;Ljava/util/Map;)V", "packageInfo", "permGroupInfo", "allPermissions", "hasInstallToRuntimeSplit", "", "specialLocationGrant", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;Ljava/util/Map;ZLjava/lang/Boolean;)V", "getAllPermissions", "()Ljava/util/Map;", "background", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup$AppPermSubGroup;", "getBackground", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup$AppPermSubGroup;", "backgroundPermNames", "", "getBackgroundPermNames", "()Ljava/util/List;", "foreground", "getForeground", "foregroundPermNames", "getForegroundPermNames", "hasBackgroundGroup", "getHasBackgroundGroup", "()Z", "getHasInstallToRuntimeSplit", "hasPermWithBackgroundMode", "getHasPermWithBackgroundMode", "isBackgroundFixed", "isForegroundFixed", "isGrantedByDefault", "isGrantedByRole", "isOneTime", "isPolicyFullyFixed", "isRevokeWhenRequested", "isUserSensitive", "getPackageInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "packageName", "getPackageName", "()Ljava/lang/String;", "getPermGroupInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "permGroupName", "getPermGroupName", "permissions", "getPermissions", "getSpecialLocationGrant", "()Ljava/lang/Boolean;", "Ljava/lang/Boolean;", "supportsRuntimePerms", "getSupportsRuntimePerms", "userHandle", "Landroid/os/UserHandle;", "getUserHandle", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "component4", "component5", "copy", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;Ljava/util/Map;ZLjava/lang/Boolean;)Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "equals", "other", "hashCode", "", "toString", "AppPermSubGroup"})
public final class LightAppPermGroup {
    
    /**
     * All unrestricted permissions. Usually restricted permissions are ignored
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> permissions = null;
    
    /**
     * The package name of this group
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    
    /**
     * The permission group name of this group
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String permGroupName = null;
    
    /**
     * The current userHandle of this AppPermGroup.
     */
    @org.jetbrains.annotations.NotNull()
    private final android.os.UserHandle userHandle = null;
    
    /**
     * The names of all background permissions in the permission group which are requested by the
     * package.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.String> backgroundPermNames = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup.AppPermSubGroup foreground = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup.AppPermSubGroup background = null;
    
    /**
     * Whether or not this App Permission Group has a permission which has a background mode
     */
    private final boolean hasPermWithBackgroundMode = false;
    
    /**
     * Whether or not this App Permission Group requests a background permission
     */
    private final boolean hasBackgroundGroup = false;
    
    /**
     * Whether this App Permission Group's background and foreground permissions are fixed by policy
     */
    private final boolean isPolicyFullyFixed = false;
    
    /**
     * Whether this App Permission Group's background permissions are fixed by the system or policy
     */
    private final boolean isBackgroundFixed = false;
    
    /**
     * Whether this App Permission Group's foreground permissions are fixed by the system or policy
     */
    private final boolean isForegroundFixed = false;
    
    /**
     * Whether or not this group supports runtime permissions
     */
    private final boolean supportsRuntimePerms = false;
    
    /**
     * Whether this App Permission Group is one-time. 2 cases:
     * 1. If the perm group is not LOCATION, check if any of the permissions is one-time.
     * 2. If the perm group is LOCATION, check if ACCESS_COARSE_LOCATION is one-time.
     */
    private final boolean isOneTime = false;
    
    /**
     * Whether any permissions in this group are granted by default (pregrant)
     */
    private final boolean isGrantedByDefault = false;
    
    /**
     * Whether any permissions in this group are granted by being a role holder
     */
    private final boolean isGrantedByRole = false;
    
    /**
     * Whether any permissions in this group are user sensitive
     */
    private final boolean isUserSensitive = false;
    
    /**
     * Whether any permissions in this group are revoke-when-requested
     */
    private final boolean isRevokeWhenRequested = false;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo permGroupInfo = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> allPermissions = null;
    private final boolean hasInstallToRuntimeSplit = false;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Boolean specialLocationGrant = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> getPermissions() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPermGroupName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle getUserHandle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getBackgroundPermNames() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getForegroundPermNames() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup.AppPermSubGroup getForeground() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup.AppPermSubGroup getBackground() {
        return null;
    }
    
    public final boolean getHasPermWithBackgroundMode() {
        return false;
    }
    
    public final boolean getHasBackgroundGroup() {
        return false;
    }
    
    public final boolean isPolicyFullyFixed() {
        return false;
    }
    
    public final boolean isBackgroundFixed() {
        return false;
    }
    
    public final boolean isForegroundFixed() {
        return false;
    }
    
    public final boolean getSupportsRuntimePerms() {
        return false;
    }
    
    public final boolean isOneTime() {
        return false;
    }
    
    public final boolean isGrantedByDefault() {
        return false;
    }
    
    public final boolean isGrantedByRole() {
        return false;
    }
    
    public final boolean isUserSensitive() {
        return false;
    }
    
    public final boolean isRevokeWhenRequested() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo getPackageInfo() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo getPermGroupInfo() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> getAllPermissions() {
        return null;
    }
    
    public final boolean getHasInstallToRuntimeSplit() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Boolean getSpecialLocationGrant() {
        return null;
    }
    
    public LightAppPermGroup(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo permGroupInfo, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> allPermissions, boolean hasInstallToRuntimeSplit, @org.jetbrains.annotations.Nullable()
    java.lang.Boolean specialLocationGrant) {
        super();
    }
    
    public LightAppPermGroup(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pI, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo pGI, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> perms) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> component3() {
        return null;
    }
    
    public final boolean component4() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Boolean component5() {
        return null;
    }
    
    /**
     * A lightweight version of the AppPermissionGroup data structure. Represents information about a
     * package, and all permissions in a particular permission group this package requests.
     *
     * @param packageInfo Information about the package
     * @param permGroupInfo Information about the permission group
     * @param allPermissions The permissions in the permission group that the package requests
     * (including restricted ones).
     * @param hasInstallToRuntimeSplit If this group contains a permission that was previously an
     * install permission, but is currently a runtime permission
     * @param specialLocationGrant If this package is the location provider, or the extra location
     * package, then the grant state of the group is not determined by the grant state of individual
     * permissions, but by other system properties
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup copy(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo permGroupInfo, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> allPermissions, boolean hasInstallToRuntimeSplit, @org.jetbrains.annotations.Nullable()
    java.lang.Boolean specialLocationGrant) {
        return null;
    }
    
    /**
     * A lightweight version of the AppPermissionGroup data structure. Represents information about a
     * package, and all permissions in a particular permission group this package requests.
     *
     * @param packageInfo Information about the package
     * @param permGroupInfo Information about the permission group
     * @param allPermissions The permissions in the permission group that the package requests
     * (including restricted ones).
     * @param hasInstallToRuntimeSplit If this group contains a permission that was previously an
     * install permission, but is currently a runtime permission
     * @param specialLocationGrant If this package is the location provider, or the extra location
     * package, then the grant state of the group is not determined by the grant state of individual
     * permissions, but by other system properties
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A lightweight version of the AppPermissionGroup data structure. Represents information about a
     * package, and all permissions in a particular permission group this package requests.
     *
     * @param packageInfo Information about the package
     * @param permGroupInfo Information about the permission group
     * @param allPermissions The permissions in the permission group that the package requests
     * (including restricted ones).
     * @param hasInstallToRuntimeSplit If this group contains a permission that was previously an
     * install permission, but is currently a runtime permission
     * @param specialLocationGrant If this package is the location provider, or the extra location
     * package, then the grant state of the group is not determined by the grant state of individual
     * permissions, but by other system properties
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A lightweight version of the AppPermissionGroup data structure. Represents information about a
     * package, and all permissions in a particular permission group this package requests.
     *
     * @param packageInfo Information about the package
     * @param permGroupInfo Information about the permission group
     * @param allPermissions The permissions in the permission group that the package requests
     * (including restricted ones).
     * @param hasInstallToRuntimeSplit If this group contains a permission that was previously an
     * install permission, but is currently a runtime permission
     * @param specialLocationGrant If this package is the location provider, or the extra location
     * package, then the grant state of the group is not determined by the grant state of individual
     * permissions, but by other system properties
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    /**
     * A subset of the AppPermssionGroup, representing either the background or foreground permissions
     * of the full group.
     *
     * @param permissions The permissions contained within this subgroup, a subset of those contained
     * in the full group
     * @param specialLocationGrant Whether this is a special location package
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0017\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B-\b\u0000\u0012\u0012\u0010\u0002\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\u0010\b\u001a\u0004\u0018\u00010\t\u00a2\u0006\u0002\u0010\nJ\u0015\u0010\u0018\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003H\u00c2\u0003J\t\u0010\u0019\u001a\u00020\u0007H\u00c2\u0003J\u0010\u0010\u001a\u001a\u0004\u0018\u00010\tH\u00c2\u0003\u00a2\u0006\u0002\u0010\u001bJ:\u0010\u001c\u001a\u00020\u00002\u0014\b\u0002\u0010\u0002\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u00032\b\b\u0002\u0010\u0006\u001a\u00020\u00072\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\tH\u00c6\u0001\u00a2\u0006\u0002\u0010\u001dJ\u0013\u0010\u001e\u001a\u00020\t2\b\u0010\u001f\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010 \u001a\u00020!H\u00d6\u0001J\t\u0010\"\u001a\u00020\u0004H\u00d6\u0001R\u000e\u0010\u000b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\r\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u000f\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u000eR\u0011\u0010\u0010\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000eR\u0011\u0010\u0011\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u000eR\u0011\u0010\u0012\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u000eR\u0011\u0010\u0013\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u000eR\u0011\u0010\u0014\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u000eR\u0011\u0010\u0015\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u000eR\u0011\u0010\u0016\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u000eR\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0002\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u0004\u0018\u00010\tX\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0017"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup$AppPermSubGroup;", "", "permissions", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "specialLocationGrant", "", "(Ljava/util/Map;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Ljava/lang/Boolean;)V", "hasInstantPerm", "hasPreRuntimePerm", "isGrantable", "()Z", "isGranted", "isGrantedByDefault", "isGrantedByRole", "isGrantedExcludeRevokeWhenRequestedPermissions", "isPolicyFixed", "isSystemFixed", "isUserFixed", "isUserSet", "Ljava/lang/Boolean;", "component1", "component2", "component3", "()Ljava/lang/Boolean;", "copy", "(Ljava/util/Map;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Ljava/lang/Boolean;)Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup$AppPermSubGroup;", "equals", "other", "hashCode", "", "toString"})
    public static final class AppPermSubGroup {
        
        /**
         * Whether any of this App Permission SubGroup's permissions are granted
         */
        private final boolean isGranted = false;
        
        /**
         * Whether any of this App Permission SubGroup's permissions are granted excluding
         * auto granted permissions during install time with flag RevokeWhenRequested
         */
        private final boolean isGrantedExcludeRevokeWhenRequestedPermissions = false;
        
        /**
         * Whether any of this App Permission SubGroup's permissions are granted by default
         */
        private final boolean isGrantedByDefault = false;
        
        /**
         * Whether any of this App Permission Subgroup's foreground permissions are fixed by policy
         */
        private final boolean isPolicyFixed = false;
        
        /**
         * Whether any of this App Permission Subgroup's permissions are fixed by the system
         */
        private final boolean isSystemFixed = false;
        
        /**
         * Whether any of this App Permission Subgroup's permissions are fixed by the user
         */
        private final boolean isUserFixed = false;
        
        /**
         * Whether any of this App Permission Subgroup's permissions are set by the user
         */
        private final boolean isUserSet = false;
        
        /**
         * Whether any of this App Permission Subgroup's permissions are set by the role of this app
         */
        private final boolean isGrantedByRole = false;
        private final boolean hasPreRuntimePerm = false;
        private final boolean hasInstantPerm = false;
        
        /**
         * Whether or not any permissions in this App Permission Subgroup can be granted
         */
        private final boolean isGrantable = false;
        private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> permissions = null;
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo = null;
        private final java.lang.Boolean specialLocationGrant = null;
        
        public final boolean isGranted() {
            return false;
        }
        
        public final boolean isGrantedExcludeRevokeWhenRequestedPermissions() {
            return false;
        }
        
        public final boolean isGrantedByDefault() {
            return false;
        }
        
        public final boolean isPolicyFixed() {
            return false;
        }
        
        public final boolean isSystemFixed() {
            return false;
        }
        
        public final boolean isUserFixed() {
            return false;
        }
        
        public final boolean isUserSet() {
            return false;
        }
        
        public final boolean isGrantedByRole() {
            return false;
        }
        
        public final boolean isGrantable() {
            return false;
        }
        
        public AppPermSubGroup(@org.jetbrains.annotations.NotNull()
        java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> permissions, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, @org.jetbrains.annotations.Nullable()
        java.lang.Boolean specialLocationGrant) {
            super();
        }
        
        private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> component1() {
            return null;
        }
        
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo component2() {
            return null;
        }
        
        private final java.lang.Boolean component3() {
            return null;
        }
        
        /**
         * A subset of the AppPermssionGroup, representing either the background or foreground permissions
         * of the full group.
         *
         * @param permissions The permissions contained within this subgroup, a subset of those contained
         * in the full group
         * @param specialLocationGrant Whether this is a special location package
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup.AppPermSubGroup copy(@org.jetbrains.annotations.NotNull()
        java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> permissions, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, @org.jetbrains.annotations.Nullable()
        java.lang.Boolean specialLocationGrant) {
            return null;
        }
        
        /**
         * A subset of the AppPermssionGroup, representing either the background or foreground permissions
         * of the full group.
         *
         * @param permissions The permissions contained within this subgroup, a subset of those contained
         * in the full group
         * @param specialLocationGrant Whether this is a special location package
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * A subset of the AppPermssionGroup, representing either the background or foreground permissions
         * of the full group.
         *
         * @param permissions The permissions contained within this subgroup, a subset of those contained
         * in the full group
         * @param specialLocationGrant Whether this is a special location package
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * A subset of the AppPermssionGroup, representing either the background or foreground permissions
         * of the full group.
         *
         * @param permissions The permissions contained within this subgroup, a subset of those contained
         * in the full group
         * @param specialLocationGrant Whether this is a special location package
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}