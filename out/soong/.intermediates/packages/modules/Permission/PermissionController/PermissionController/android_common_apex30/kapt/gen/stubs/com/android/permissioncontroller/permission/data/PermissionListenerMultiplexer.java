package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * Serves as a single shared Permission Change Listener for all AppPermissionGroupLiveDatas.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\b\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\t\b\u00c6\u0002\u0018\u00002\u00020\u0001:\u0001\u0017B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00072\u0006\u0010\u0010\u001a\u00020\tJ%\u0010\u0011\u001a\u00020\u000e2\b\u0010\u0012\u001a\u0004\u0018\u00010\u00072\u0006\u0010\u0013\u001a\u00020\u00072\u0006\u0010\u0010\u001a\u00020\t\u00a2\u0006\u0002\u0010\u0014J\u0010\u0010\u0015\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0007H\u0016J\u0016\u0010\u0016\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00072\u0006\u0010\u0010\u001a\u00020\tR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0005\u001a\u0014\u0012\u0004\u0012\u00020\u0007\u0012\n\u0012\b\u0012\u0004\u0012\u00020\t0\b0\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\n\u001a\n \f*\u0004\u0018\u00010\u000b0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer;", "Landroid/content/pm/PackageManager$OnPermissionsChangedListener;", "()V", "app", "Landroid/app/Application;", "callbacks", "", "", "", "Lcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer$PermissionChangeCallback;", "pm", "Landroid/content/pm/PackageManager;", "kotlin.jvm.PlatformType", "addCallback", "", "uid", "callback", "addOrReplaceCallback", "oldUid", "newUid", "(Ljava/lang/Integer;ILcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer$PermissionChangeCallback;)V", "onPermissionsChanged", "removeCallback", "PermissionChangeCallback"})
public final class PermissionListenerMultiplexer implements android.content.pm.PackageManager.OnPermissionsChangedListener {
    private static final android.app.Application app = null;
    
    /**
     * Map<UID, list of PermissionChangeCallbacks that wish to be informed when
     * permissions are updated for that UID>
     */
    private static final java.util.Map<java.lang.Integer, java.util.List<com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback>> callbacks = null;
    private static final android.content.pm.PackageManager pm = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer INSTANCE = null;
    
    @java.lang.Override()
    public void onPermissionsChanged(int uid) {
    }
    
    public final void addOrReplaceCallback(@org.jetbrains.annotations.Nullable()
    java.lang.Integer oldUid, int newUid, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback callback) {
    }
    
    public final void addCallback(int uid, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback callback) {
    }
    
    public final void removeCallback(int uid, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PermissionListenerMultiplexer.PermissionChangeCallback callback) {
    }
    
    private PermissionListenerMultiplexer() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermissionListenerMultiplexer$PermissionChangeCallback;", "", "onPermissionChange", ""})
    public static abstract interface PermissionChangeCallback {
        
        public abstract void onPermissionChange();
    }
}