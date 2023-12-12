package com.android.permissioncontroller.permission.model.livedatatypes;

import java.lang.System;

/**
 * Represents the UI information of a permission group as a whole- the number of granted non-system
 * apps, and the total number of non-system apps.
 *
 * @param name The name of the permission group whose UI data this represents
 * @param nonSystemTotal The total number of non-system applications that request permissions in
 * this group
 * @param nonSystemGranted The total number of non-system applications that request permissions in
 * this group, and have at least one permission in this group granted.
 * @param nonSystemUserSetOrPreGranted The total number of non-system applications that request
 * permissions in this group, and have at least one permission in this group granted, or one
 * permission denied by the user
 * @param systemGranted The total number of system applications that request permissions in
 * this group, and have at least one permission in this group granted.
 * @param systemUserSetOrPreGranted The total number of system applications that request
 * permissions in this group, and have at least one permission in this group granted, or one
 * permission denied by the user
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0017\b\u0086\b\u0018\u00002\u00020\u0001B=\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0005\u0012\u0006\u0010\b\u001a\u00020\u0005\u0012\u0006\u0010\t\u001a\u00020\u0005\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0018\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001b\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001d\u001a\u00020\u000bH\u00c6\u0003JO\u0010\u001e\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\u00052\b\b\u0002\u0010\b\u001a\u00020\u00052\b\b\u0002\u0010\t\u001a\u00020\u00052\b\b\u0002\u0010\n\u001a\u00020\u000bH\u00c6\u0001J\u0013\u0010\u001f\u001a\u00020\u000b2\b\u0010 \u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010!\u001a\u00020\u0005H\u00d6\u0001J\t\u0010\"\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0010R\u0011\u0010\u0007\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0010R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\b\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0010R\u0011\u0010\t\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0010"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/PermGroupPackagesUiInfo;", "", "name", "", "nonSystemTotal", "", "nonSystemGranted", "nonSystemUserSetOrPreGranted", "systemGranted", "systemUserSetOrPreGranted", "onlyShellPackageGranted", "", "(Ljava/lang/String;IIIIIZ)V", "getName", "()Ljava/lang/String;", "getNonSystemGranted", "()I", "getNonSystemTotal", "getNonSystemUserSetOrPreGranted", "getOnlyShellPackageGranted", "()Z", "getSystemGranted", "getSystemUserSetOrPreGranted", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "copy", "equals", "other", "hashCode", "toString"})
public final class PermGroupPackagesUiInfo {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String name = null;
    private final int nonSystemTotal = 0;
    private final int nonSystemGranted = 0;
    private final int nonSystemUserSetOrPreGranted = 0;
    private final int systemGranted = 0;
    private final int systemUserSetOrPreGranted = 0;
    private final boolean onlyShellPackageGranted = false;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getName() {
        return null;
    }
    
    public final int getNonSystemTotal() {
        return 0;
    }
    
    public final int getNonSystemGranted() {
        return 0;
    }
    
    public final int getNonSystemUserSetOrPreGranted() {
        return 0;
    }
    
    public final int getSystemGranted() {
        return 0;
    }
    
    public final int getSystemUserSetOrPreGranted() {
        return 0;
    }
    
    public final boolean getOnlyShellPackageGranted() {
        return false;
    }
    
    public PermGroupPackagesUiInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int nonSystemTotal, int nonSystemGranted, int nonSystemUserSetOrPreGranted, int systemGranted, int systemUserSetOrPreGranted, boolean onlyShellPackageGranted) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    public final int component2() {
        return 0;
    }
    
    public final int component3() {
        return 0;
    }
    
    public final int component4() {
        return 0;
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
    
    /**
     * Represents the UI information of a permission group as a whole- the number of granted non-system
     * apps, and the total number of non-system apps.
     *
     * @param name The name of the permission group whose UI data this represents
     * @param nonSystemTotal The total number of non-system applications that request permissions in
     * this group
     * @param nonSystemGranted The total number of non-system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param nonSystemUserSetOrPreGranted The total number of non-system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     * @param systemGranted The total number of system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param systemUserSetOrPreGranted The total number of system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo copy(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int nonSystemTotal, int nonSystemGranted, int nonSystemUserSetOrPreGranted, int systemGranted, int systemUserSetOrPreGranted, boolean onlyShellPackageGranted) {
        return null;
    }
    
    /**
     * Represents the UI information of a permission group as a whole- the number of granted non-system
     * apps, and the total number of non-system apps.
     *
     * @param name The name of the permission group whose UI data this represents
     * @param nonSystemTotal The total number of non-system applications that request permissions in
     * this group
     * @param nonSystemGranted The total number of non-system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param nonSystemUserSetOrPreGranted The total number of non-system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     * @param systemGranted The total number of system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param systemUserSetOrPreGranted The total number of system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Represents the UI information of a permission group as a whole- the number of granted non-system
     * apps, and the total number of non-system apps.
     *
     * @param name The name of the permission group whose UI data this represents
     * @param nonSystemTotal The total number of non-system applications that request permissions in
     * this group
     * @param nonSystemGranted The total number of non-system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param nonSystemUserSetOrPreGranted The total number of non-system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     * @param systemGranted The total number of system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param systemUserSetOrPreGranted The total number of system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Represents the UI information of a permission group as a whole- the number of granted non-system
     * apps, and the total number of non-system apps.
     *
     * @param name The name of the permission group whose UI data this represents
     * @param nonSystemTotal The total number of non-system applications that request permissions in
     * this group
     * @param nonSystemGranted The total number of non-system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param nonSystemUserSetOrPreGranted The total number of non-system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     * @param systemGranted The total number of system applications that request permissions in
     * this group, and have at least one permission in this group granted.
     * @param systemUserSetOrPreGranted The total number of system applications that request
     * permissions in this group, and have at least one permission in this group granted, or one
     * permission denied by the user
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}