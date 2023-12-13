package com.android.permissioncontroller.hibernation;

import android.app.usage.UsageStatsManager;
import android.apphibernation.AppHibernationManager;
import android.content.Context;
import android.os.Build;
import android.os.UserHandle;
import com.android.permissioncontroller.DumpableLog;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;

/**
 * Hibernation controller that handles modifying hibernation state.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\u0018\u0000 \u00182\u00020\u0001:\u0001\u0018B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ2\u0010\u000f\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0012\u0012\u0004\u0012\u00020\u00130\u00110\u00102\u0018\u0010\u0014\u001a\u0014\u0012\u0004\u0012\u00020\u0013\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00170\u00160\u0015R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/permissioncontroller/hibernation/HibernationController;", "", "context", "Landroid/content/Context;", "unusedThreshold", "", "targetsPreS", "", "(Landroid/content/Context;JZ)V", "getContext", "()Landroid/content/Context;", "getTargetsPreS", "()Z", "getUnusedThreshold", "()J", "hibernateApps", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "apps", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "Companion"})
public final class HibernationController {
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    private final long unusedThreshold = 0L;
    private final boolean targetsPreS = false;
    private static final java.lang.String LOG_TAG = "HibernationController";
    private static final boolean DEBUG_HIBERNATION = true;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.hibernation.HibernationController.Companion Companion = null;
    
    /**
     * Hibernates the apps provided for each user.
     *
     * @param apps map of each user to a list of packages that should be hibernated for the user
     * @return list of apps that were successfully hibernated
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<kotlin.Pair<java.lang.String, android.os.UserHandle>> hibernateApps(@org.jetbrains.annotations.NotNull()
    java.util.Map<android.os.UserHandle, ? extends java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> apps) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    public final long getUnusedThreshold() {
        return 0L;
    }
    
    public final boolean getTargetsPreS() {
        return false;
    }
    
    public HibernationController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, long unusedThreshold, boolean targetsPreS) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/hibernation/HibernationController$Companion;", "", "()V", "DEBUG_HIBERNATION", "", "LOG_TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}