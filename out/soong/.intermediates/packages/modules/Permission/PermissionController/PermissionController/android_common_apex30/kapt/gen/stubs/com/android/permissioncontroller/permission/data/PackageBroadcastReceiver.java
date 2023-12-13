package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import com.android.permissioncontroller.PermissionControllerApplication;
import kotlinx.coroutines.GlobalScope;

/**
 * Listens for package additions, replacements, and removals, and notifies listeners.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u00020\u0001:\u0001\u001dB\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0005J\u0016\u0010\u0010\u001a\u00020\u000e2\u0006\u0010\u0011\u001a\u00020\n2\u0006\u0010\u000f\u001a\u00020\u0005J\b\u0010\u0012\u001a\u00020\u0013H\u0002J\b\u0010\u0014\u001a\u00020\u0015H\u0002J\u0018\u0010\u0016\u001a\u00020\u000e2\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0016J\u000e\u0010\u001b\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0005J\u0018\u0010\u001c\u001a\u00020\u000e2\b\u0010\u0011\u001a\u0004\u0018\u00010\n2\u0006\u0010\u000f\u001a\u00020\u0005R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\b\u001a\u0014\u0012\u0004\u0012\u00020\n\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver;", "Landroid/content/BroadcastReceiver;", "()V", "allCallbacks", "", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "app", "Landroid/app/Application;", "changeCallbacks", "", "", "intentFilter", "Landroid/content/IntentFilter;", "addAllCallback", "", "listener", "addChangeCallback", "packageName", "getNumListeners", "", "hasNoListeners", "", "onReceive", "context", "Landroid/content/Context;", "intent", "Landroid/content/Intent;", "removeAllCallback", "removeChangeCallback", "PackageBroadcastListener"})
public final class PackageBroadcastReceiver extends android.content.BroadcastReceiver {
    private static final android.app.Application app = null;
    private static final android.content.IntentFilter intentFilter = null;
    
    /**
     * Map<packageName, callbacks listenening to package>
     */
    private static final java.util.Map<java.lang.String, java.util.Set<com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener>> changeCallbacks = null;
    
    /**
     * A list of listener IDs, which listen to all package additions, changes, and removals.
     */
    private static final java.util.Set<com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener> allCallbacks = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PackageBroadcastReceiver INSTANCE = null;
    
    /**
     * Add a callback which will be notified when the specified packaged is changed or removed.
     */
    public final void addChangeCallback(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener listener) {
    }
    
    /**
     * Add a callback which will be notified any time a package is added, removed, or changed.
     *
     * @param listener the listener to be added
     * @return returns the integer ID assigned to the
     */
    public final void addAllCallback(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener listener) {
    }
    
    /**
     * Removes a package add/remove/change callback.
     *
     * @param listener the listener we wish to remove
     */
    public final void removeAllCallback(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener listener) {
    }
    
    /**
     * Removes a change callback.
     *
     * @param packageName the package the listener is listening for
     * @param listener the listener we wish to remove
     */
    public final void removeChangeCallback(@org.jetbrains.annotations.Nullable()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener listener) {
    }
    
    private final int getNumListeners() {
        return 0;
    }
    
    private final boolean hasNoListeners() {
        return false;
    }
    
    /**
     * Upon receiving a broadcast, rout it to the proper callbacks.
     *
     * @param context the context of the broadcast
     * @param intent data about the broadcast which was sent
     */
    @java.lang.Override()
    public void onReceive(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
    }
    
    private PackageBroadcastReceiver() {
        super();
    }
    
    /**
     * A listener interface for objects desiring to be notified of package broadcasts.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "", "onPackageUpdate", "", "packageName", ""})
    public static abstract interface PackageBroadcastListener {
        
        /**
         * To be called when a specific package has been changed, or when any package has been
         * installed.
         *
         * @param packageName the name of the package which was updated
         */
        public abstract void onPackageUpdate(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName);
    }
}