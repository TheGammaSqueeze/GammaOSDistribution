package com.android.permissioncontroller.permission.model.livedatatypes;

import android.app.Application;
import android.content.pm.PackageManager;
import android.content.pm.PermissionInfo;

/**
 * A light version of the system PermissionInfo
 *
 * @param name The name of this permission
 * @param packageName The name of the package which defines this permission
 * @param group The optional name of the group this permission is in
 * @param backgroundPermission The background permission associated with this permission
 * @param protection The protection level of this permission
 * @param protection Extra information about the protection of this permission
 * @param flags The system flags of this permission
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\u0015\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004BA\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u0012\b\u0010\b\u001a\u0004\u0018\u00010\u0006\u0012\b\u0010\t\u001a\u0004\u0018\u00010\u0006\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\u000b\u0012\u0006\u0010\r\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\u000eJ\t\u0010\u0018\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0006H\u00c6\u0003J\u000b\u0010\u001a\u001a\u0004\u0018\u00010\u0006H\u00c6\u0003J\u000b\u0010\u001b\u001a\u0004\u0018\u00010\u0006H\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u000bH\u00c6\u0003J\t\u0010\u001d\u001a\u00020\u000bH\u00c6\u0003J\t\u0010\u001e\u001a\u00020\u000bH\u00c6\u0003JS\u0010\u001f\u001a\u00020\u00002\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\u00062\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\u00062\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\u00062\b\b\u0002\u0010\n\u001a\u00020\u000b2\b\b\u0002\u0010\f\u001a\u00020\u000b2\b\b\u0002\u0010\r\u001a\u00020\u000bH\u00c6\u0001J\u0013\u0010 \u001a\u00020!2\b\u0010\"\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010#\u001a\u00020\u000bH\u00d6\u0001J\u0010\u0010$\u001a\u0004\u0018\u00010\u00032\u0006\u0010%\u001a\u00020&J\t\u0010\'\u001a\u00020\u0006H\u00d6\u0001R\u0013\u0010\t\u001a\u0004\u0018\u00010\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\r\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u0013\u0010\b\u001a\u0004\u0018\u00010\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0010R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0010R\u0011\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0010R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0012R\u0011\u0010\f\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0012"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "", "permInfo", "Landroid/content/pm/PermissionInfo;", "(Landroid/content/pm/PermissionInfo;)V", "name", "", "packageName", "group", "backgroundPermission", "protection", "", "protectionFlags", "flags", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;III)V", "getBackgroundPermission", "()Ljava/lang/String;", "getFlags", "()I", "getGroup", "getName", "getPackageName", "getProtection", "getProtectionFlags", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "copy", "equals", "", "other", "hashCode", "toPermissionInfo", "app", "Landroid/app/Application;", "toString"})
public final class LightPermInfo {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String name = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String group = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String backgroundPermission = null;
    private final int protection = 0;
    private final int protectionFlags = 0;
    private final int flags = 0;
    
    /**
     * Gets the PermissionInfo for this permission from the system.
     *
     * @param app The current application, which will be used to get the PermissionInfo
     *
     * @return The PermissionInfo corresponding to this permission, or null, if no
     * such permission exists
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.pm.PermissionInfo toPermissionInfo(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getGroup() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getBackgroundPermission() {
        return null;
    }
    
    public final int getProtection() {
        return 0;
    }
    
    public final int getProtectionFlags() {
        return 0;
    }
    
    public final int getFlags() {
        return 0;
    }
    
    public LightPermInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    java.lang.String group, @org.jetbrains.annotations.Nullable()
    java.lang.String backgroundPermission, int protection, int protectionFlags, int flags) {
        super();
    }
    
    public LightPermInfo(@org.jetbrains.annotations.NotNull()
    android.content.pm.PermissionInfo permInfo) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component2() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component3() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component4() {
        return null;
    }
    
    public final int component5() {
        return 0;
    }
    
    public final int component6() {
        return 0;
    }
    
    public final int component7() {
        return 0;
    }
    
    /**
     * A light version of the system PermissionInfo
     *
     * @param name The name of this permission
     * @param packageName The name of the package which defines this permission
     * @param group The optional name of the group this permission is in
     * @param backgroundPermission The background permission associated with this permission
     * @param protection The protection level of this permission
     * @param protection Extra information about the protection of this permission
     * @param flags The system flags of this permission
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo copy(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    java.lang.String group, @org.jetbrains.annotations.Nullable()
    java.lang.String backgroundPermission, int protection, int protectionFlags, int flags) {
        return null;
    }
    
    /**
     * A light version of the system PermissionInfo
     *
     * @param name The name of this permission
     * @param packageName The name of the package which defines this permission
     * @param group The optional name of the group this permission is in
     * @param backgroundPermission The background permission associated with this permission
     * @param protection The protection level of this permission
     * @param protection Extra information about the protection of this permission
     * @param flags The system flags of this permission
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A light version of the system PermissionInfo
     *
     * @param name The name of this permission
     * @param packageName The name of the package which defines this permission
     * @param group The optional name of the group this permission is in
     * @param backgroundPermission The background permission associated with this permission
     * @param protection The protection level of this permission
     * @param protection Extra information about the protection of this permission
     * @param flags The system flags of this permission
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A light version of the system PermissionInfo
     *
     * @param name The name of this permission
     * @param packageName The name of the package which defines this permission
     * @param group The optional name of the group this permission is in
     * @param backgroundPermission The background permission associated with this permission
     * @param protection The protection level of this permission
     * @param protection Extra information about the protection of this permission
     * @param flags The system flags of this permission
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}