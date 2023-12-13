package com.android.permissioncontroller.permission.model.livedatatypes;

import java.lang.System;

/**
 * Tracks the packages associated with a uid, and the user sensitivity state of the permissions for
 * those packages.
 *
 * @param packages A LightPackageInfo for every package with this uid
 * @param permStates A map <requested permission name, use sensitive state>, with the state being a
 * combination of FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED and
 * FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0010\b\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0086\b\u0018\u00002\u00020\u0001B\'\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0012\u0010\u0005\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006\u00a2\u0006\u0002\u0010\tJ\u000f\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u0015\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006H\u00c6\u0003J/\u0010\u0010\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u0014\b\u0002\u0010\u0005\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006H\u00c6\u0001J\u0013\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0014\u001a\u00020\bH\u00d6\u0001J\t\u0010\u0015\u001a\u00020\u0007H\u00d6\u0001R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u001d\u0010\u0005\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/UidSensitivityState;", "", "packages", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "permStates", "", "", "", "(Ljava/util/Set;Ljava/util/Map;)V", "getPackages", "()Ljava/util/Set;", "getPermStates", "()Ljava/util/Map;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString"})
public final class UidSensitivityState {
    @org.jetbrains.annotations.NotNull()
    private final java.util.Set<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> packages = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.String, java.lang.Integer> permStates = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> getPackages() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, java.lang.Integer> getPermStates() {
        return null;
    }
    
    public UidSensitivityState(@org.jetbrains.annotations.NotNull()
    java.util.Set<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> packages, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, java.lang.Integer> permStates) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, java.lang.Integer> component2() {
        return null;
    }
    
    /**
     * Tracks the packages associated with a uid, and the user sensitivity state of the permissions for
     * those packages.
     *
     * @param packages A LightPackageInfo for every package with this uid
     * @param permStates A map <requested permission name, use sensitive state>, with the state being a
     * combination of FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED and
     * FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.UidSensitivityState copy(@org.jetbrains.annotations.NotNull()
    java.util.Set<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> packages, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, java.lang.Integer> permStates) {
        return null;
    }
    
    /**
     * Tracks the packages associated with a uid, and the user sensitivity state of the permissions for
     * those packages.
     *
     * @param packages A LightPackageInfo for every package with this uid
     * @param permStates A map <requested permission name, use sensitive state>, with the state being a
     * combination of FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED and
     * FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Tracks the packages associated with a uid, and the user sensitivity state of the permissions for
     * those packages.
     *
     * @param packages A LightPackageInfo for every package with this uid
     * @param permStates A map <requested permission name, use sensitive state>, with the state being a
     * combination of FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED and
     * FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Tracks the packages associated with a uid, and the user sensitivity state of the permissions for
     * those packages.
     *
     * @param packages A LightPackageInfo for every package with this uid
     * @param permStates A map <requested permission name, use sensitive state>, with the state being a
     * combination of FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED and
     * FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}