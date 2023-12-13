package com.android.permissioncontroller.permission.model.livedatatypes;

import java.lang.System;

/**
 * A triple of booleans that correspond to an App Permission Group, and give information about how
 * the UI should treat the App Permission Group
 *
 * @param shouldShow Whether or not this app perm group should be shown in the UI
 * @param permGrantState Whether this app perm group has granted permissions
 * @param isSystem Whether or not this app is a system app, which should be hidden by default
 * @param isUserSet Whether or not the user has set or fixed this app perm group
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000f\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001:\u0001\u0018B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\bJ\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000e\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0010\u001a\u00020\u0003H\u00c6\u0003J1\u0010\u0011\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00032\b\b\u0002\u0010\u0007\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0012\u001a\u00020\u00032\b\u0010\u0013\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0014\u001a\u00020\u0015H\u00d6\u0001J\t\u0010\u0016\u001a\u00020\u0017H\u00d6\u0001R\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\tR\u0011\u0010\u0007\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\t"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo;", "", "shouldShow", "", "permGrantState", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;", "isSystem", "isUserSet", "(ZLcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;ZZ)V", "()Z", "getPermGrantState", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;", "getShouldShow", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString", "", "PermGrantState"})
public final class AppPermGroupUiInfo {
    private final boolean shouldShow = false;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState permGrantState = null;
    private final boolean isSystem = false;
    private final boolean isUserSet = false;
    
    public final boolean getShouldShow() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState getPermGrantState() {
        return null;
    }
    
    public final boolean isSystem() {
        return false;
    }
    
    public final boolean isUserSet() {
        return false;
    }
    
    public AppPermGroupUiInfo(boolean shouldShow, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState permGrantState, boolean isSystem, boolean isUserSet) {
        super();
    }
    
    public final boolean component1() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState component2() {
        return null;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final boolean component4() {
        return false;
    }
    
    /**
     * A triple of booleans that correspond to an App Permission Group, and give information about how
     * the UI should treat the App Permission Group
     *
     * @param shouldShow Whether or not this app perm group should be shown in the UI
     * @param permGrantState Whether this app perm group has granted permissions
     * @param isSystem Whether or not this app is a system app, which should be hidden by default
     * @param isUserSet Whether or not the user has set or fixed this app perm group
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo copy(boolean shouldShow, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState permGrantState, boolean isSystem, boolean isUserSet) {
        return null;
    }
    
    /**
     * A triple of booleans that correspond to an App Permission Group, and give information about how
     * the UI should treat the App Permission Group
     *
     * @param shouldShow Whether or not this app perm group should be shown in the UI
     * @param permGrantState Whether this app perm group has granted permissions
     * @param isSystem Whether or not this app is a system app, which should be hidden by default
     * @param isUserSet Whether or not the user has set or fixed this app perm group
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A triple of booleans that correspond to an App Permission Group, and give information about how
     * the UI should treat the App Permission Group
     *
     * @param shouldShow Whether or not this app perm group should be shown in the UI
     * @param permGrantState Whether this app perm group has granted permissions
     * @param isSystem Whether or not this app is a system app, which should be hidden by default
     * @param isUserSet Whether or not the user has set or fixed this app perm group
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A triple of booleans that correspond to an App Permission Group, and give information about how
     * the UI should treat the App Permission Group
     *
     * @param shouldShow Whether or not this app perm group should be shown in the UI
     * @param permGrantState Whether this app perm group has granted permissions
     * @param isSystem Whether or not this app is a system app, which should be hidden by default
     * @param isUserSet Whether or not the user has set or fixed this app perm group
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0005j\u0002\b\u0006j\u0002\b\u0007j\u0002\b\bj\u0002\b\t"}, d2 = {"Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;", "", "grantState", "", "(Ljava/lang/String;II)V", "PERMS_DENIED", "PERMS_ALLOWED", "PERMS_ALLOWED_FOREGROUND_ONLY", "PERMS_ALLOWED_ALWAYS", "PERMS_ASK"})
    public static enum PermGrantState {
        /*public static final*/ PERMS_DENIED /* = new PERMS_DENIED(0) */,
        /*public static final*/ PERMS_ALLOWED /* = new PERMS_ALLOWED(0) */,
        /*public static final*/ PERMS_ALLOWED_FOREGROUND_ONLY /* = new PERMS_ALLOWED_FOREGROUND_ONLY(0) */,
        /*public static final*/ PERMS_ALLOWED_ALWAYS /* = new PERMS_ALLOWED_ALWAYS(0) */,
        /*public static final*/ PERMS_ASK /* = new PERMS_ASK(0) */;
        private final int grantState = 0;
        
        PermGrantState(int grantState) {
        }
    }
}