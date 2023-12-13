package com.android.permissioncontroller.permission.model.livedatatypes;

import java.lang.System;

/**
 * Tracks the setting state of hibernation and auto revoke for a package
 *
 * @param isEnabledGlobal Whether or not the hibernation/auto-revoke job runs
 * @param isEnabledForApp Whether or not the OPSTR_AUTO_REVOKE_PERMISSIONS_IF_UNUSED is set to
 * MODE_ALLOWED for this package
 * @param revocableGroupNames A list of which permission groups of this package are eligible for
 * auto-revoke. A permission group is auto-revocable if it does not contain a default granted
 * permission.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u000b\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B#\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\u0002\u0010\bJ\t\u0010\f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\u000f\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006H\u00c6\u0003J-\u0010\u000f\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\u000e\b\u0002\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006H\u00c6\u0001J\u0013\u0010\u0010\u001a\u00020\u00032\b\u0010\u0011\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0012\u001a\u00020\u0013H\u00d6\u0001J\t\u0010\u0014\u001a\u00020\u0007H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0004\u0010\tR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0002\u0010\tR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/HibernationSettingState;", "", "isEnabledGlobal", "", "isEnabledForApp", "revocableGroupNames", "", "", "(ZZLjava/util/List;)V", "()Z", "getRevocableGroupNames", "()Ljava/util/List;", "component1", "component2", "component3", "copy", "equals", "other", "hashCode", "", "toString"})
public final class HibernationSettingState {
    private final boolean isEnabledGlobal = false;
    private final boolean isEnabledForApp = false;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.String> revocableGroupNames = null;
    
    public final boolean isEnabledGlobal() {
        return false;
    }
    
    public final boolean isEnabledForApp() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getRevocableGroupNames() {
        return null;
    }
    
    public HibernationSettingState(boolean isEnabledGlobal, boolean isEnabledForApp, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> revocableGroupNames) {
        super();
    }
    
    public final boolean component1() {
        return false;
    }
    
    public final boolean component2() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> component3() {
        return null;
    }
    
    /**
     * Tracks the setting state of hibernation and auto revoke for a package
     *
     * @param isEnabledGlobal Whether or not the hibernation/auto-revoke job runs
     * @param isEnabledForApp Whether or not the OPSTR_AUTO_REVOKE_PERMISSIONS_IF_UNUSED is set to
     * MODE_ALLOWED for this package
     * @param revocableGroupNames A list of which permission groups of this package are eligible for
     * auto-revoke. A permission group is auto-revocable if it does not contain a default granted
     * permission.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.HibernationSettingState copy(boolean isEnabledGlobal, boolean isEnabledForApp, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> revocableGroupNames) {
        return null;
    }
    
    /**
     * Tracks the setting state of hibernation and auto revoke for a package
     *
     * @param isEnabledGlobal Whether or not the hibernation/auto-revoke job runs
     * @param isEnabledForApp Whether or not the OPSTR_AUTO_REVOKE_PERMISSIONS_IF_UNUSED is set to
     * MODE_ALLOWED for this package
     * @param revocableGroupNames A list of which permission groups of this package are eligible for
     * auto-revoke. A permission group is auto-revocable if it does not contain a default granted
     * permission.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Tracks the setting state of hibernation and auto revoke for a package
     *
     * @param isEnabledGlobal Whether or not the hibernation/auto-revoke job runs
     * @param isEnabledForApp Whether or not the OPSTR_AUTO_REVOKE_PERMISSIONS_IF_UNUSED is set to
     * MODE_ALLOWED for this package
     * @param revocableGroupNames A list of which permission groups of this package are eligible for
     * auto-revoke. A permission group is auto-revocable if it does not contain a default granted
     * permission.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Tracks the setting state of hibernation and auto revoke for a package
     *
     * @param isEnabledGlobal Whether or not the hibernation/auto-revoke job runs
     * @param isEnabledForApp Whether or not the OPSTR_AUTO_REVOKE_PERMISSIONS_IF_UNUSED is set to
     * MODE_ALLOWED for this package
     * @param revocableGroupNames A list of which permission groups of this package are eligible for
     * auto-revoke. A permission group is auto-revocable if it does not contain a default granted
     * permission.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}