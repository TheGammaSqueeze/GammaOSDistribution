package com.android.permissioncontroller.permission.utils;

import android.content.pm.PackageManager;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.data.UserSensitivityLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.UidSensitivityState;
import kotlinx.coroutines.GlobalScope;
import java.lang.IllegalStateException;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000,\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u001a\u001c\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0007\u001a.\u0010\b\u001a\u00020\u00032\u0012\u0010\t\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u000b0\n2\u0006\u0010\f\u001a\u00020\r2\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0002\u001a\u0016\u0010\u000e\u001a\u00020\u00032\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u0006\u001a\u00020\u0007\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"LOG_TAG", "", "updateUserSensitiveForUid", "", "uid", "", "callback", "Ljava/lang/Runnable;", "updateUserSensitiveForUidsInternal", "uidsUserSensitivity", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/UidSensitivityState;", "user", "Landroid/os/UserHandle;", "updateUserSensitiveForUser"})
public final class UserSensitiveFlagsUtils {
    private static final java.lang.String LOG_TAG = "UserSensitiveFlagsUtils";
    
    /**
     * Update the [PackageManager.FLAG_PERMISSION_USER_SENSITIVE_WHEN_GRANTED] and
     * [PackageManager.FLAG_PERMISSION_USER_SENSITIVE_WHEN_DENIED] for all apps of this user.
     *
     * @see UserSensitivityLiveData.loadDataAndPostValue
     *
     * @param user The user for whom packages will be updated
     * @param callback A callback which will be executed when finished
     */
    public static final void updateUserSensitiveForUser(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback) {
    }
    
    private static final void updateUserSensitiveForUidsInternal(java.util.Map<java.lang.Integer, com.android.permissioncontroller.permission.model.livedatatypes.UidSensitivityState> uidsUserSensitivity, android.os.UserHandle user, java.lang.Runnable callback) {
    }
    
    /**
     * [updateUserSensitiveForUser] for a single [uid]
     *
     * @param uid The uid to be updated
     * @param callback A callback which will be executed when finished
     */
    public static final void updateUserSensitiveForUid(int uid, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable callback) {
    }
    
    /**
     * [updateUserSensitiveForUser] for a single [uid]
     *
     * @param uid The uid to be updated
     * @param callback A callback which will be executed when finished
     */
    public static final void updateUserSensitiveForUid(int uid) {
    }
}