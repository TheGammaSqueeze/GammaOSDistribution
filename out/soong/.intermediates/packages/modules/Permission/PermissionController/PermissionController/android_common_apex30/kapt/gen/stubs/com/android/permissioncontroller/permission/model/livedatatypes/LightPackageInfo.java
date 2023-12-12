package com.android.permissioncontroller.permission.model.livedatatypes;

import android.app.Application;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.UserHandle;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A lighter version of the system's PackageInfo class, containing select information about the
 * package.
 *
 * @param packageName The name of the packages
 * @param permissions The list of LightPermInfos representing the permissions this package defines
 * @param requestedPermissions The names of the permissions this package requests
 * @param requestedPermissionsFlags The grant state of the permissions this package requests
 * @param uid The UID of this package
 * @param targetSdkVersion The target SDK of this package
 * @param isInstantApp Whether or not this package is an instant app
 * @param enabled Whether or not this package is enabled.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\u001f\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\b\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004Bg\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\b\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00060\b\u0012\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\b\u0012\u0006\u0010\r\u001a\u00020\f\u0012\u0006\u0010\u000e\u001a\u00020\f\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0010\u0012\u0006\u0010\u0012\u001a\u00020\f\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010\u0015J\t\u0010&\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\'\u001a\u00020\u0014H\u00c6\u0003J\u000f\u0010(\u001a\b\u0012\u0004\u0012\u00020\t0\bH\u00c6\u0003J\u000f\u0010)\u001a\b\u0012\u0004\u0012\u00020\u00060\bH\u00c6\u0003J\u000f\u0010*\u001a\b\u0012\u0004\u0012\u00020\f0\bH\u00c6\u0003J\t\u0010+\u001a\u00020\fH\u00c6\u0003J\t\u0010,\u001a\u00020\fH\u00c6\u0003J\t\u0010-\u001a\u00020\u0010H\u00c6\u0003J\t\u0010.\u001a\u00020\u0010H\u00c6\u0003J\t\u0010/\u001a\u00020\fH\u00c6\u0003J\u007f\u00100\u001a\u00020\u00002\b\b\u0002\u0010\u0005\u001a\u00020\u00062\u000e\b\u0002\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\b2\u000e\b\u0002\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00060\b2\u000e\b\u0002\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\b2\b\b\u0002\u0010\r\u001a\u00020\f2\b\b\u0002\u0010\u000e\u001a\u00020\f2\b\b\u0002\u0010\u000f\u001a\u00020\u00102\b\b\u0002\u0010\u0011\u001a\u00020\u00102\b\b\u0002\u0010\u0012\u001a\u00020\f2\b\b\u0002\u0010\u0013\u001a\u00020\u0014H\u00c6\u0001J\u0013\u00101\u001a\u00020\u00102\b\u00102\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\u0010\u00103\u001a\u0004\u0018\u0001042\u0006\u00105\u001a\u000206J\t\u00107\u001a\u00020\fH\u00d6\u0001J\u0010\u00108\u001a\u0004\u0018\u00010\u00032\u0006\u00105\u001a\u000206J\t\u00109\u001a\u00020\u0006H\u00d6\u0001R\u0011\u0010\u0012\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0011\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u0011\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u0017\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u00060\b8F\u00a2\u0006\u0006\u001a\u0004\b\u001d\u0010\u001eR\u0011\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0019R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010 R\u0017\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\b\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u001eR\u0017\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00060\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u001eR\u0017\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\b\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\u001eR\u0011\u0010\u000e\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u0017R\u0011\u0010\r\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010\u0017"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "", "pI", "Landroid/content/pm/PackageInfo;", "(Landroid/content/pm/PackageInfo;)V", "packageName", "", "permissions", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "requestedPermissions", "requestedPermissionsFlags", "", "uid", "targetSdkVersion", "isInstantApp", "", "enabled", "appFlags", "firstInstallTime", "", "(Ljava/lang/String;Ljava/util/List;Ljava/util/List;Ljava/util/List;IIZZIJ)V", "getAppFlags", "()I", "getEnabled", "()Z", "getFirstInstallTime", "()J", "grantedPermissions", "getGrantedPermissions", "()Ljava/util/List;", "getPackageName", "()Ljava/lang/String;", "getPermissions", "getRequestedPermissions", "getRequestedPermissionsFlags", "getTargetSdkVersion", "getUid", "component1", "component10", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "getApplicationInfo", "Landroid/content/pm/ApplicationInfo;", "app", "Landroid/app/Application;", "hashCode", "toPackageInfo", "toString"})
public final class LightPackageInfo {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissions = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.String> requestedPermissions = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.Integer> requestedPermissionsFlags = null;
    private final int uid = 0;
    private final int targetSdkVersion = 0;
    private final boolean isInstantApp = false;
    private final boolean enabled = false;
    private final int appFlags = 0;
    private final long firstInstallTime = 0L;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getGrantedPermissions() {
        return null;
    }
    
    /**
     * Gets the ApplicationInfo for this package from the system. Can be expensive if called too
     * often.
     *
     * @param app The current application, which will be used to get the ApplicationInfo
     *
     * @return The ApplicationInfo corresponding to this package, with this UID, or null, if no
     * such package exists
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.pm.ApplicationInfo getApplicationInfo(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        return null;
    }
    
    /**
     * Gets the PackageInfo for this package from the system. Can be expensive if called too
     * often.
     *
     * @param app The current application, which will be used to get the PackageInfo
     *
     * @return The PackageInfo corresponding to this package, with this UID, or null, if no
     * such package exists
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.pm.PackageInfo toPackageInfo(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> getPermissions() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getRequestedPermissions() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> getRequestedPermissionsFlags() {
        return null;
    }
    
    public final int getUid() {
        return 0;
    }
    
    public final int getTargetSdkVersion() {
        return 0;
    }
    
    public final boolean isInstantApp() {
        return false;
    }
    
    public final boolean getEnabled() {
        return false;
    }
    
    public final int getAppFlags() {
        return 0;
    }
    
    public final long getFirstInstallTime() {
        return 0L;
    }
    
    public LightPackageInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> requestedPermissions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Integer> requestedPermissionsFlags, int uid, int targetSdkVersion, boolean isInstantApp, boolean enabled, int appFlags, long firstInstallTime) {
        super();
    }
    
    public LightPackageInfo(@org.jetbrains.annotations.NotNull()
    android.content.pm.PackageInfo pI) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> component3() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> component4() {
        return null;
    }
    
    public final int component5() {
        return 0;
    }
    
    public final int component6() {
        return 0;
    }
    
    public final boolean component7() {
        return false;
    }
    
    public final boolean component8() {
        return false;
    }
    
    public final int component9() {
        return 0;
    }
    
    public final long component10() {
        return 0L;
    }
    
    /**
     * A lighter version of the system's PackageInfo class, containing select information about the
     * package.
     *
     * @param packageName The name of the packages
     * @param permissions The list of LightPermInfos representing the permissions this package defines
     * @param requestedPermissions The names of the permissions this package requests
     * @param requestedPermissionsFlags The grant state of the permissions this package requests
     * @param uid The UID of this package
     * @param targetSdkVersion The target SDK of this package
     * @param isInstantApp Whether or not this package is an instant app
     * @param enabled Whether or not this package is enabled.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo copy(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> requestedPermissions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Integer> requestedPermissionsFlags, int uid, int targetSdkVersion, boolean isInstantApp, boolean enabled, int appFlags, long firstInstallTime) {
        return null;
    }
    
    /**
     * A lighter version of the system's PackageInfo class, containing select information about the
     * package.
     *
     * @param packageName The name of the packages
     * @param permissions The list of LightPermInfos representing the permissions this package defines
     * @param requestedPermissions The names of the permissions this package requests
     * @param requestedPermissionsFlags The grant state of the permissions this package requests
     * @param uid The UID of this package
     * @param targetSdkVersion The target SDK of this package
     * @param isInstantApp Whether or not this package is an instant app
     * @param enabled Whether or not this package is enabled.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A lighter version of the system's PackageInfo class, containing select information about the
     * package.
     *
     * @param packageName The name of the packages
     * @param permissions The list of LightPermInfos representing the permissions this package defines
     * @param requestedPermissions The names of the permissions this package requests
     * @param requestedPermissionsFlags The grant state of the permissions this package requests
     * @param uid The UID of this package
     * @param targetSdkVersion The target SDK of this package
     * @param isInstantApp Whether or not this package is an instant app
     * @param enabled Whether or not this package is enabled.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A lighter version of the system's PackageInfo class, containing select information about the
     * package.
     *
     * @param packageName The name of the packages
     * @param permissions The list of LightPermInfos representing the permissions this package defines
     * @param requestedPermissions The names of the permissions this package requests
     * @param requestedPermissionsFlags The grant state of the permissions this package requests
     * @param uid The UID of this package
     * @param targetSdkVersion The target SDK of this package
     * @param isInstantApp Whether or not this package is an instant app
     * @param enabled Whether or not this package is enabled.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}