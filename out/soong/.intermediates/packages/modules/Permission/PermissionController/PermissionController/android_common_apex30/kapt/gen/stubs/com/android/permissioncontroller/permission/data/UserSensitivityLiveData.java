package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Process;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.UidSensitivityState;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import java.lang.IllegalArgumentException;

/**
 * Live data of the user sensitivity of either one uid, or all uids that belong to a user.
 * Maps <uid, user sensitive state>
 *
 * @param app The current application
 * @param uid The uid whose user sensitivity we would like to observer, or INVALID_UID if we want
 * all uids for a user
 * @param user The user for whom we want the uid/s
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u001b2\u0016\u0012\u0012\u0012\u0010\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0004\u0018\u00010\u00020\u0001:\u0001\u001bB\u001f\b\u0002\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010\u0015\u001a\u00020\u000eH\u0002J\u0019\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0019H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001aR\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00120\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UserSensitivityLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/UidSensitivityState;", "app", "Landroid/app/Application;", "uid", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;ILandroid/os/UserHandle;)V", "context", "Landroid/content/Context;", "getAllUids", "", "packageLiveDatas", "", "", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "userPackageInfosLiveData", "Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData;", "getAndObservePackageLiveDatas", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "Companion"})
public final class UserSensitivityLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<java.lang.Integer, ? extends com.android.permissioncontroller.permission.model.livedatatypes.UidSensitivityState>> {
    private final android.content.Context context = null;
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.LightPackageInfoLiveData> packageLiveDatas = null;
    private final com.android.permissioncontroller.permission.data.UserPackageInfosLiveData userPackageInfosLiveData = null;
    private final boolean getAllUids = false;
    private final android.app.Application app = null;
    private final int uid = 0;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.UserSensitivityLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    private final boolean getAndObservePackageLiveDatas() {
        return false;
    }
    
    private UserSensitivityLiveData(android.app.Application app, int uid, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for a UserSensitivityLiveData
     * <p> Key value is a pair of int uid (INVALID_UID for all uids), and UserHandle,
     * value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\u0011\u0010\u0007\u001a\u00020\u00052\u0006\u0010\b\u001a\u00020\u0004H\u0086\u0002J\u0011\u0010\u0007\u001a\u00020\u00052\u0006\u0010\t\u001a\u00020\u0003H\u0086\u0002J\u001c\u0010\n\u001a\u00020\u00052\u0012\u0010\u000b\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UserSensitivityLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/UserSensitivityLiveData;", "()V", "get", "user", "uid", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Pair<? extends java.lang.Integer, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.UserSensitivityLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.UserSensitivityLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<java.lang.Integer, android.os.UserHandle> key) {
            return null;
        }
        
        /**
         * Gets a liveData for a uid, automatically generating the UserHandle from the uid. Will
         * throw an exception if the uid is INVALID_UID.
         *
         * @param uid The uid for which we want the liveData
         *
         * @return The liveData associated with the given UID
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.UserSensitivityLiveData get(int uid) {
            return null;
        }
        
        /**
         * Gets a liveData for a user, which will track all uids under
         *
         * @param user The user for whom we want the liveData
         *
         * @return The liveData associated with that user, for all uids
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.UserSensitivityLiveData get(@org.jetbrains.annotations.NotNull()
        android.os.UserHandle user) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}