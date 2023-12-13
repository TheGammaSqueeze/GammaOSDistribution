package com.android.permissioncontroller.permission.model.livedatatypes;

import java.lang.System;

/**
 * A permission Group, represented as a PackageItemInfo groupInfo, and a map of permission name
 * to PermissionInfo objects.
 *
 * @param groupInfo information about the permission group
 * @param permissionInfos the Permissions in this group
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\r\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B!\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0012\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005\u00a2\u0006\u0002\u0010\bJ\t\u0010\u0016\u001a\u00020\u0003H\u00c6\u0003J\u0015\u0010\u0017\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005H\u00c6\u0003J)\u0010\u0018\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\u0014\b\u0002\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005H\u00c6\u0001J\u0013\u0010\u0019\u001a\u00020\u000e2\b\u0010\u001a\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001b\u001a\u00020\u001cH\u00d6\u0001J\t\u0010\u001d\u001a\u00020\u0006H\u00d6\u0001R\u001a\u0010\u0002\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0011\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u001d\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/PermGroup;", "", "groupInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "permissionInfos", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;Ljava/util/Map;)V", "getGroupInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "setGroupInfo", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;)V", "hasRuntimePermissions", "", "getHasRuntimePermissions", "()Z", "name", "getName", "()Ljava/lang/String;", "getPermissionInfos", "()Ljava/util/Map;", "component1", "component2", "copy", "equals", "other", "hashCode", "", "toString"})
public final class PermGroup {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String name = null;
    private final boolean hasRuntimePermissions = false;
    @org.jetbrains.annotations.NotNull()
    private com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo;
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissionInfos = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getName() {
        return null;
    }
    
    public final boolean getHasRuntimePermissions() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo getGroupInfo() {
        return null;
    }
    
    public final void setGroupInfo(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> getPermissionInfos() {
        return null;
    }
    
    public PermGroup(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissionInfos) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> component2() {
        return null;
    }
    
    /**
     * A permission Group, represented as a PackageItemInfo groupInfo, and a map of permission name
     * to PermissionInfo objects.
     *
     * @param groupInfo information about the permission group
     * @param permissionInfos the Permissions in this group
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.PermGroup copy(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissionInfos) {
        return null;
    }
    
    /**
     * A permission Group, represented as a PackageItemInfo groupInfo, and a map of permission name
     * to PermissionInfo objects.
     *
     * @param groupInfo information about the permission group
     * @param permissionInfos the Permissions in this group
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A permission Group, represented as a PackageItemInfo groupInfo, and a map of permission name
     * to PermissionInfo objects.
     *
     * @param groupInfo information about the permission group
     * @param permissionInfos the Permissions in this group
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A permission Group, represented as a PackageItemInfo groupInfo, and a map of permission name
     * to PermissionInfo objects.
     *
     * @param groupInfo information about the permission group
     * @param permissionInfos the Permissions in this group
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}