package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.app.role.OnRoleHoldersChangedListener;
import android.app.role.RoleManager;
import android.os.UserHandle;
import androidx.annotation.GuardedBy;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * Serves as a single shared Role Change Listener.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0006\b\u00c6\u0002\u0018\u00002\u00020\u0001:\u0001\u0016B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u001e\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\b2\u0006\u0010\u0012\u001a\u00020\u00072\u0006\u0010\u0013\u001a\u00020\nJ\u0018\u0010\u0014\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\b2\u0006\u0010\u0012\u001a\u00020\u0007H\u0016J\u001e\u0010\u0015\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\b2\u0006\u0010\u0012\u001a\u00020\u00072\u0006\u0010\u0013\u001a\u00020\nR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R.\u0010\u0005\u001a \u0012\u0004\u0012\u00020\u0007\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\n0\t0\u00060\u00068\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/RoleListenerMultiplexer;", "Landroid/app/role/OnRoleHoldersChangedListener;", "()V", "app", "Landroid/app/Application;", "callbacks", "", "Landroid/os/UserHandle;", "", "", "Lcom/android/permissioncontroller/permission/data/RoleListenerMultiplexer$RoleHoldersChangeCallback;", "lock", "Ljava/lang/Object;", "roleManager", "Landroid/app/role/RoleManager;", "addCallback", "", "roleName", "user", "callback", "onRoleHoldersChanged", "removeCallback", "RoleHoldersChangeCallback"})
public final class RoleListenerMultiplexer implements android.app.role.OnRoleHoldersChangedListener {
    private static final android.app.Application app = null;
    @androidx.annotation.GuardedBy(value = "lock")
    private static final java.util.Map<android.os.UserHandle, java.util.Map<java.lang.String, java.util.List<com.android.permissioncontroller.permission.data.RoleListenerMultiplexer.RoleHoldersChangeCallback>>> callbacks = null;
    private static final android.app.role.RoleManager roleManager = null;
    private static final java.lang.Object lock = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.RoleListenerMultiplexer INSTANCE = null;
    
    @java.lang.Override()
    public void onRoleHoldersChanged(@org.jetbrains.annotations.NotNull()
    java.lang.String roleName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
    }
    
    public final void addCallback(@org.jetbrains.annotations.NotNull()
    java.lang.String roleName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.RoleListenerMultiplexer.RoleHoldersChangeCallback callback) {
    }
    
    public final void removeCallback(@org.jetbrains.annotations.NotNull()
    java.lang.String roleName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.RoleListenerMultiplexer.RoleHoldersChangeCallback callback) {
    }
    
    private RoleListenerMultiplexer() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/permissioncontroller/permission/data/RoleListenerMultiplexer$RoleHoldersChangeCallback;", "", "onRoleHoldersChanged", ""})
    public static abstract interface RoleHoldersChangeCallback {
        
        public abstract void onRoleHoldersChanged();
    }
}