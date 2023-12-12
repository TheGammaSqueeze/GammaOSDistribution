package com.android.permissioncontroller.permission.model.livedatatypes;

import android.content.pm.PackageManager;
import android.content.pm.PermissionInfo;
import com.android.permissioncontroller.permission.utils.SoftRestrictedPermissionPolicy;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * Represents a single permission, and its state
 *
 * @param pkgInfo The package requesting the permission
 * @param permInfo The permissionInfo this represents
 * @param isGrantedIncludingAppOp Whether or not this permission is functionally granted.
 * A non-granted app op but granted permission is counted as not granted
 * @param flags The PermissionController flags for this permission
 * @param foregroundPerms The foreground permission names corresponding to this permission, if this
 * permission is a background permission
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b*\b\u0086\b\u0018\u00002\u00020\u0001B/\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u000e\u0010\b\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010\t\u00a2\u0006\u0002\u0010\u000bB5\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u000e\u0010\b\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010\t\u00a2\u0006\u0002\u0010\u0010J\t\u00100\u001a\u00020\u0003H\u00c6\u0003J\t\u00101\u001a\u00020\u0005H\u00c6\u0003J\t\u00102\u001a\u00020\rH\u00c6\u0003J\t\u00103\u001a\u00020\u000fH\u00c6\u0003J\u0011\u00104\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010\tH\u00c6\u0003JC\u00105\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\f\u001a\u00020\r2\b\b\u0002\u0010\u000e\u001a\u00020\u000f2\u0010\b\u0002\u0010\b\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010\tH\u00c6\u0001J\u0013\u00106\u001a\u00020\r2\b\u00107\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u00108\u001a\u00020\u000fH\u00d6\u0001J\b\u00109\u001a\u00020\nH\u0016R\u0013\u0010\u0011\u001a\u0004\u0018\u00010\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0019\u0010\b\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0018\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u0011\u0010\u001a\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u0019R\u0011\u0010\u001b\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u0019R\u0011\u0010\u001c\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u0019R\u0011\u0010\u001d\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u0019R\u0011\u0010\f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\u0019R\u0011\u0010\u001e\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u0019R\u0011\u0010\u001f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u0019R\u0011\u0010 \u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u0019R\u0011\u0010!\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u0019R\u0011\u0010\"\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u0019R\u0011\u0010#\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\u0019R\u0011\u0010$\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u0019R\u0011\u0010%\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010\u0019R\u0011\u0010&\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u0019R\u0011\u0010\'\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u0019R\u0011\u0010(\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\u0019R\u0011\u0010)\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b)\u0010\u0019R\u0011\u0010*\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b+\u0010\u0013R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010-R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010/"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "", "pkgInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "permInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "permState", "Lcom/android/permissioncontroller/permission/model/livedatatypes/PermState;", "foregroundPerms", "", "", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/PermState;Ljava/util/List;)V", "isGrantedIncludingAppOp", "", "flags", "", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;ZILjava/util/List;)V", "backgroundPermission", "getBackgroundPermission", "()Ljava/lang/String;", "getFlags", "()I", "getForegroundPerms", "()Ljava/util/List;", "isAutoRevoked", "()Z", "isBackgroundPermission", "isCompatRevoked", "isGrantedByDefault", "isGrantedByRole", "isInstantPerm", "isOneTime", "isPolicyFixed", "isRestricted", "isReviewRequired", "isRevokeWhenRequested", "isRuntimeOnly", "isSelectedLocationAccuracy", "isSystemFixed", "isUserFixed", "isUserSensitive", "isUserSet", "name", "getName", "getPermInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "getPkgInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "component1", "component2", "component3", "component4", "component5", "copy", "equals", "other", "hashCode", "toString"})
public final class LightPermission {
    
    /**
     * The name of this permission
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String name = null;
    
    /**
     * The background permission name of this permission, if it exists
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String backgroundPermission = null;
    
    /**
     * If this is a background permission
     */
    private final boolean isBackgroundPermission = false;
    
    /**
     * Whether this permission is fixed by policy
     */
    private final boolean isPolicyFixed = false;
    
    /**
     * Whether this permission is fixed by the system
     */
    private final boolean isSystemFixed = false;
    
    /**
     * Whether this permission is fixed by the system
     */
    private final boolean isUserFixed = false;
    
    /**
     * Whether this permission is user set
     */
    private final boolean isUserSet = false;
    
    /**
     * Whether this permission is granted, but its app op is revoked
     */
    private final boolean isCompatRevoked = false;
    
    /**
     * Whether this permission requires review (only relevant for pre-M apps)
     */
    private final boolean isReviewRequired = false;
    
    /**
     * Whether this permission is one-time
     */
    private final boolean isOneTime = false;
    
    /**
     * Whether this permission is an instant app permission
     */
    private final boolean isInstantPerm = false;
    
    /**
     * Whether this permission is a runtime only permission
     */
    private final boolean isRuntimeOnly = false;
    
    /**
     * Whether this permission is granted by default
     */
    private final boolean isGrantedByDefault = false;
    
    /**
     * Whether this permission is granted by role
     */
    private final boolean isGrantedByRole = false;
    
    /**
     * Whether this permission is set to be revoked upon being requested
     */
    private final boolean isRevokeWhenRequested = false;
    
    /**
     * Whether this permission is user sensitive in its current grant state
     */
    private final boolean isUserSensitive = false;
    
    /**
     * Whether the permission is restricted
     */
    private final boolean isRestricted = false;
    
    /**
     * Whether the permission is auto revoked
     */
    private final boolean isAutoRevoked = false;
    
    /**
     * Whether the location permission is selected as the level of granularity of location accuracy
     */
    private final boolean isSelectedLocationAccuracy = false;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkgInfo = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo permInfo = null;
    private final boolean isGrantedIncludingAppOp = false;
    private final int flags = 0;
    @org.jetbrains.annotations.Nullable()
    private final java.util.List<java.lang.String> foregroundPerms = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getName() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getBackgroundPermission() {
        return null;
    }
    
    public final boolean isBackgroundPermission() {
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
    
    public final boolean isCompatRevoked() {
        return false;
    }
    
    public final boolean isReviewRequired() {
        return false;
    }
    
    public final boolean isOneTime() {
        return false;
    }
    
    public final boolean isInstantPerm() {
        return false;
    }
    
    public final boolean isRuntimeOnly() {
        return false;
    }
    
    public final boolean isGrantedByDefault() {
        return false;
    }
    
    public final boolean isGrantedByRole() {
        return false;
    }
    
    public final boolean isRevokeWhenRequested() {
        return false;
    }
    
    public final boolean isUserSensitive() {
        return false;
    }
    
    public final boolean isRestricted() {
        return false;
    }
    
    public final boolean isAutoRevoked() {
        return false;
    }
    
    public final boolean isSelectedLocationAccuracy() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo getPkgInfo() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo getPermInfo() {
        return null;
    }
    
    public final boolean isGrantedIncludingAppOp() {
        return false;
    }
    
    public final int getFlags() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.util.List<java.lang.String> getForegroundPerms() {
        return null;
    }
    
    public LightPermission(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkgInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo permInfo, boolean isGrantedIncludingAppOp, int flags, @org.jetbrains.annotations.Nullable()
    java.util.List<java.lang.String> foregroundPerms) {
        super();
    }
    
    public LightPermission(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkgInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo permInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.PermState permState, @org.jetbrains.annotations.Nullable()
    java.util.List<java.lang.String> foregroundPerms) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo component2() {
        return null;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final int component4() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.util.List<java.lang.String> component5() {
        return null;
    }
    
    /**
     * Represents a single permission, and its state
     *
     * @param pkgInfo The package requesting the permission
     * @param permInfo The permissionInfo this represents
     * @param isGrantedIncludingAppOp Whether or not this permission is functionally granted.
     * A non-granted app op but granted permission is counted as not granted
     * @param flags The PermissionController flags for this permission
     * @param foregroundPerms The foreground permission names corresponding to this permission, if this
     * permission is a background permission
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermission copy(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkgInfo, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo permInfo, boolean isGrantedIncludingAppOp, int flags, @org.jetbrains.annotations.Nullable()
    java.util.List<java.lang.String> foregroundPerms) {
        return null;
    }
    
    /**
     * Represents a single permission, and its state
     *
     * @param pkgInfo The package requesting the permission
     * @param permInfo The permissionInfo this represents
     * @param isGrantedIncludingAppOp Whether or not this permission is functionally granted.
     * A non-granted app op but granted permission is counted as not granted
     * @param flags The PermissionController flags for this permission
     * @param foregroundPerms The foreground permission names corresponding to this permission, if this
     * permission is a background permission
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Represents a single permission, and its state
     *
     * @param pkgInfo The package requesting the permission
     * @param permInfo The permissionInfo this represents
     * @param isGrantedIncludingAppOp Whether or not this permission is functionally granted.
     * A non-granted app op but granted permission is counted as not granted
     * @param flags The PermissionController flags for this permission
     * @param foregroundPerms The foreground permission names corresponding to this permission, if this
     * permission is a background permission
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}