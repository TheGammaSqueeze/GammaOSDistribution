package com.android.permissioncontroller.permission.model.livedatatypes;

import android.app.Application;
import android.content.pm.PackageItemInfo;
import android.content.pm.PermissionGroupInfo;
import android.content.pm.PermissionInfo;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A light version of a PackageItemInfo, representing information about a permission group.
 *
 * @param name The name of this group
 * @param packageName The name of the package which defines this group
 * @param labelRes The resource ID of this group's label
 * @param icon The resource ID of this group's icon
 * @param descriptionRes The resource ID of this group's desctiption
 * @param isSinglePermGroup Whether or not this is a group with a single permission in it
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0015\n\u0002\u0018\u0002\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u000f\b\u0016\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007B5\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\t\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\f\u0012\u0006\u0010\u000e\u001a\u00020\f\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\u0002\u0010\u0011J\t\u0010\u001a\u001a\u00020\tH\u00c6\u0003J\t\u0010\u001b\u001a\u00020\tH\u00c6\u0003J\t\u0010\u001c\u001a\u00020\fH\u00c6\u0003J\t\u0010\u001d\u001a\u00020\fH\u00c6\u0003J\t\u0010\u001e\u001a\u00020\fH\u00c6\u0003J\t\u0010\u001f\u001a\u00020\u0010H\u00c6\u0003JE\u0010 \u001a\u00020\u00002\b\b\u0002\u0010\b\u001a\u00020\t2\b\b\u0002\u0010\n\u001a\u00020\t2\b\b\u0002\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\f2\b\b\u0002\u0010\u000e\u001a\u00020\f2\b\b\u0002\u0010\u000f\u001a\u00020\u0010H\u00c6\u0001J\u0013\u0010!\u001a\u00020\u00102\b\u0010\"\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010#\u001a\u00020\fH\u00d6\u0001J\u0010\u0010$\u001a\u0004\u0018\u00010\u00032\u0006\u0010%\u001a\u00020&J\t\u0010\'\u001a\u00020\tH\u00d6\u0001R\u0011\u0010\u000e\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\r\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0013R\u0011\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0015R\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0013R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u0011\u0010\n\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u0018"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "", "pII", "Landroid/content/pm/PackageItemInfo;", "(Landroid/content/pm/PackageItemInfo;)V", "pGI", "Landroid/content/pm/PermissionGroupInfo;", "(Landroid/content/pm/PermissionGroupInfo;)V", "name", "", "packageName", "labelRes", "", "icon", "descriptionRes", "isSinglePermGroup", "", "(Ljava/lang/String;Ljava/lang/String;IIIZ)V", "getDescriptionRes", "()I", "getIcon", "()Z", "getLabelRes", "getName", "()Ljava/lang/String;", "getPackageName", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "equals", "other", "hashCode", "toPackageItemInfo", "app", "Landroid/app/Application;", "toString"})
public final class LightPermGroupInfo {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String name = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    private final int labelRes = 0;
    private final int icon = 0;
    private final int descriptionRes = 0;
    private final boolean isSinglePermGroup = false;
    
    /**
     * Gets the PackageItemInfo for this permission group from the system.
     *
     * @param app The current application, which will be used to get the PackageItemInfo
     *
     * @return The PackageItemInfo corresponding to this permission group, or null, if no
     * such group exists
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.pm.PackageItemInfo toPackageItemInfo(@org.jetbrains.annotations.NotNull()
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
    
    public final int getLabelRes() {
        return 0;
    }
    
    public final int getIcon() {
        return 0;
    }
    
    public final int getDescriptionRes() {
        return 0;
    }
    
    public final boolean isSinglePermGroup() {
        return false;
    }
    
    public LightPermGroupInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, int labelRes, int icon, int descriptionRes, boolean isSinglePermGroup) {
        super();
    }
    
    public LightPermGroupInfo(@org.jetbrains.annotations.NotNull()
    android.content.pm.PackageItemInfo pII) {
        super();
    }
    
    public LightPermGroupInfo(@org.jetbrains.annotations.NotNull()
    android.content.pm.PermissionGroupInfo pGI) {
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
    
    public final int component3() {
        return 0;
    }
    
    public final int component4() {
        return 0;
    }
    
    public final int component5() {
        return 0;
    }
    
    public final boolean component6() {
        return false;
    }
    
    /**
     * A light version of a PackageItemInfo, representing information about a permission group.
     *
     * @param name The name of this group
     * @param packageName The name of the package which defines this group
     * @param labelRes The resource ID of this group's label
     * @param icon The resource ID of this group's icon
     * @param descriptionRes The resource ID of this group's desctiption
     * @param isSinglePermGroup Whether or not this is a group with a single permission in it
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo copy(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, int labelRes, int icon, int descriptionRes, boolean isSinglePermGroup) {
        return null;
    }
    
    /**
     * A light version of a PackageItemInfo, representing information about a permission group.
     *
     * @param name The name of this group
     * @param packageName The name of the package which defines this group
     * @param labelRes The resource ID of this group's label
     * @param icon The resource ID of this group's icon
     * @param descriptionRes The resource ID of this group's desctiption
     * @param isSinglePermGroup Whether or not this is a group with a single permission in it
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A light version of a PackageItemInfo, representing information about a permission group.
     *
     * @param name The name of this group
     * @param packageName The name of the package which defines this group
     * @param labelRes The resource ID of this group's label
     * @param icon The resource ID of this group's icon
     * @param descriptionRes The resource ID of this group's desctiption
     * @param isSinglePermGroup Whether or not this is a group with a single permission in it
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A light version of a PackageItemInfo, representing information about a permission group.
     *
     * @param name The name of this group
     * @param packageName The name of the package which defines this group
     * @param labelRes The resource ID of this group's label
     * @param icon The resource ID of this group's icon
     * @param descriptionRes The resource ID of this group's desctiption
     * @param isSinglePermGroup Whether or not this is a group with a single permission in it
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}