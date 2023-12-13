package com.android.permissioncontroller.permission.service;

import android.content.Context;
import android.os.UserHandle;
import android.os.UserManager;
import androidx.annotation.MainThread;
import com.android.permissioncontroller.DumpableLog;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData;
import com.android.permissioncontroller.permission.data.PackagePermissionsLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import java.util.concurrent.atomic.AtomicBoolean;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000>\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\u001aO\u0010\b\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u000b0\n0\t2\u0018\u0010\f\u001a\u0014\u0012\u0004\u0012\u00020\u000b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000e0\u00030\r2\u0006\u0010\u000f\u001a\u00020\u00102\b\b\u0002\u0010\u0011\u001a\u00020\u0012H\u0087@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0013\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0007X\u0082D\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"DEBUG_AUTO_REVOKE", "", "EXEMPT_PERMISSIONS", "", "", "LOG_TAG", "SERVER_LOG_ID", "", "revokeAppPermissions", "", "Lkotlin/Pair;", "Landroid/os/UserHandle;", "apps", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "context", "Landroid/content/Context;", "sessionId", "", "(Ljava/util/Map;Landroid/content/Context;JLkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class AutoRevokePermissions {
    private static final java.lang.String LOG_TAG = "AutoRevokePermissions";
    public static final boolean DEBUG_AUTO_REVOKE = true;
    private static final java.util.List<java.lang.String> EXEMPT_PERMISSIONS = null;
    private static final int SERVER_LOG_ID = com.android.permissioncontroller.PermissionControllerStatsLog.PERMISSION_GRANT_REQUEST_RESULT_REPORTED__RESULT__AUTO_UNUSED_APP_PERMISSION_REVOKED;
    
    /**
     * Revoke granted app permissions for apps that should be auto-revoked
     *
     * @return list of packages that successfully had their permissions revoked
     */
    @org.jetbrains.annotations.Nullable()
    @androidx.annotation.MainThread()
    public static final java.lang.Object revokeAppPermissions(@org.jetbrains.annotations.NotNull()
    java.util.Map<android.os.UserHandle, ? extends java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> apps, @org.jetbrains.annotations.NotNull()
    android.content.Context context, long sessionId, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.Set<kotlin.Pair<java.lang.String, android.os.UserHandle>>> p3) {
        return null;
    }
}