package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageItemInfo;
import android.content.pm.PackageManager;
import android.content.pm.PermissionGroupInfo;
import android.content.pm.PermissionInfo;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.PermGroup;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * LiveData for a Permission Group. Contains GroupInfo and a list of PermissionInfos. Loads
 * synchronously.
 *
 * @param app The current application
 * @param groupName The name of the permission group this LiveData represents
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\u0018\u0000 \u00182\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001\u0018B\u0017\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010\u0012\u001a\u00020\u0013H\u0014J\b\u0010\u0014\u001a\u00020\u0013H\u0014J\u0010\u0010\u0015\u001a\u00020\u00132\u0006\u0010\u0016\u001a\u00020\u0007H\u0016J\b\u0010\u0017\u001a\u00020\u0013H\u0014R\u0016\u0010\t\u001a\n \n*\u0004\u0018\u00010\u00070\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u00110\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/PermGroup;", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "app", "Landroid/app/Application;", "groupName", "", "(Landroid/app/Application;Ljava/lang/String;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "context", "Landroid/content/Context;", "groupInfo", "Landroid/content/pm/PackageItemInfo;", "packageLiveDatas", "", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "onActive", "", "onInactive", "onPackageUpdate", "packageName", "onUpdate", "Companion"})
public final class PermGroupLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.PermGroup> implements com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener {
    private final java.lang.String LOG_TAG = null;
    private final android.content.Context context = null;
    
    /**
     * Map<packageName, LiveData<PackageInfo>>
     */
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.LightPackageInfoLiveData> packageLiveDatas = null;
    private android.content.pm.PackageItemInfo groupInfo;
    private final android.app.Application app = null;
    private final java.lang.String groupName = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PermGroupLiveData.Companion Companion = null;
    
    /**
     * Called when a package is installed, changed, or removed.
     *
     * @param packageName the package which was added or changed
     */
    @java.lang.Override()
    public void onPackageUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    /**
     * Initializes this permission group from scratch. Resets the groupInfo, PermissionInfos, and
     * PackageInfoLiveDatas, then re-adds them.
     */
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    /**
     * Load data, and register a package change listener. We must watch for package changes,
     * because there is currently no listener for permission changes.
     */
    @java.lang.Override()
    protected void onActive() {
    }
    
    private PermGroupLiveData(android.app.Application app, java.lang.String groupName) {
        super(false);
    }
    
    /**
     * Repository for PermGroupLiveDatas.
     * <p> Key value is a string permission group name, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "", "Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<java.lang.String, com.android.permissioncontroller.permission.data.PermGroupLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.PermGroupLiveData newValue(@org.jetbrains.annotations.NotNull()
        java.lang.String key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}