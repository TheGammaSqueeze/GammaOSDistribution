package com.android.permissioncontroller.permission.utils;

import android.app.Activity;
import android.app.Application;
import android.app.Service;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.pm.ComponentInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.Looper;
import android.os.UserHandle;
import java.util.concurrent.Executors;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000R\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\u001a\u0006\u0010\u0010\u001a\u00020\u0011\u001a\u0012\u0010\u0012\u001a\u00020\u0005*\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0005\u001aS\u0010\u0015\u001a\u00020\u0011*\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u001a\u001a\u00020\u00132*\u0010\u001b\u001a\u0016\u0012\u0012\b\u0001\u0012\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u001e0\u001d0\u001c\"\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u001e0\u001d\u00a2\u0006\u0002\u0010\u001f\"\u0011\u0010\u0000\u001a\u00020\u0001\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0002\u0010\u0003\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\"\u0015\u0010\u0006\u001a\u00020\u0007*\u00020\b8F\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\n\"\u0015\u0010\u000b\u001a\u00020\f*\u00020\r8F\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"IPC", "Lkotlinx/coroutines/ExecutorCoroutineDispatcher;", "getIPC", "()Lkotlinx/coroutines/ExecutorCoroutineDispatcher;", "IPC_THREAD_POOL_COUNT", "", "application", "Landroid/app/Application;", "Landroid/content/Context;", "getApplication", "(Landroid/content/Context;)Landroid/app/Application;", "componentInfo", "Landroid/content/pm/ComponentInfo;", "Landroid/content/pm/ResolveInfo;", "getComponentInfo", "(Landroid/content/pm/ResolveInfo;)Landroid/content/pm/ComponentInfo;", "ensureMainThread", "", "getUid", "Landroid/os/UserHandle;", "appId", "updatePermissionFlags", "Landroid/content/pm/PackageManager;", "permissionName", "", "packageName", "user", "flags", "", "Lkotlin/Pair;", "", "(Landroid/content/pm/PackageManager;Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;[Lkotlin/Pair;)V"})
public final class AndroidUtilsKt {
    
    /**
     * The number of threads in the IPC thread pool. Set to the maximum number of binder threads allowed
     * to an app by the Android System.
     */
    public static final int IPC_THREAD_POOL_COUNT = 8;
    
    /**
     * A coroutine dispatcher with a fixed thread pool size, to be used for background tasks
     */
    @org.jetbrains.annotations.NotNull()
    private static final kotlinx.coroutines.ExecutorCoroutineDispatcher IPC = null;
    
    @org.jetbrains.annotations.NotNull()
    public static final android.app.Application getApplication(@org.jetbrains.annotations.NotNull()
    android.content.Context $this$application) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final kotlinx.coroutines.ExecutorCoroutineDispatcher getIPC() {
        return null;
    }
    
    /**
     * Assert that an operation is running on main thread
     */
    public static final void ensureMainThread() {
    }
    
    /**
     * A more readable version of [PackageManager.updatePermissionFlags]
     */
    public static final void updatePermissionFlags(@org.jetbrains.annotations.NotNull()
    android.content.pm.PackageManager $this$updatePermissionFlags, @org.jetbrains.annotations.NotNull()
    java.lang.String permissionName, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    kotlin.Pair<java.lang.Integer, java.lang.Boolean>... flags) {
    }
    
    /**
     * @see UserHandle.getUid
     */
    public static final int getUid(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle $this$getUid, int appId) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final android.content.pm.ComponentInfo getComponentInfo(@org.jetbrains.annotations.NotNull()
    android.content.pm.ResolveInfo $this$componentInfo) {
        return null;
    }
}