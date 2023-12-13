package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager;
import android.content.pm.PermissionInfo;
import android.os.Build;
import android.os.UserHandle;
import android.permission.PermissionManager;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermission;
import com.android.permissioncontroller.permission.utils.LocationUtils;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A LiveData which represents the permissions for one package and permission group.
 *
 * @param app The current application
 * @param packageName The name of the package
 * @param permGroupName The name of the permission group
 * @param user The user of the package
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000`\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\u0018\u0000 &2\n\u0012\u0006\u0012\u0004\u0018\u00010\u00020\u00012\u00020\u0003:\u0001&B\'\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ$\u0010\u001a\u001a\u00020\u00132\u0006\u0010\u001b\u001a\u00020\u001c2\u0012\u0010\u001d\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001f0\u001eH\u0002J\b\u0010 \u001a\u00020!H\u0014J\b\u0010\"\u001a\u00020!H\u0014J\u0010\u0010#\u001a\u00020!2\u0006\u0010$\u001a\u00020\u0013H\u0016J\b\u0010%\u001a\u00020!H\u0014R\u0019\u0010\f\u001a\n \r*\u0004\u0018\u00010\u00070\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightAppPermGroupLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "Lcom/android/permissioncontroller/permission/utils/LocationUtils$LocationListener;", "app", "Landroid/app/Application;", "packageName", "", "permGroupName", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "getLOG_TAG", "()Ljava/lang/String;", "fgPermNamesLiveData", "Lcom/android/permissioncontroller/permission/data/ForegroundPermNamesLiveData;", "isSpecialLocation", "", "packageInfoLiveData", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "permGroupLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "permStateLiveData", "Lcom/android/permissioncontroller/permission/data/PermStateLiveData;", "hasInstallToRuntimeSplit", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "permissionMap", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "onActive", "", "onInactive", "onLocationStateChange", "enabled", "onUpdate", "Companion"})
public final class LightAppPermGroupLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> implements com.android.permissioncontroller.permission.utils.LocationUtils.LocationListener {
    private final java.lang.String LOG_TAG = null;
    private boolean isSpecialLocation = false;
    private final com.android.permissioncontroller.permission.data.PermStateLiveData permStateLiveData = null;
    private final com.android.permissioncontroller.permission.data.PermGroupLiveData permGroupLiveData = null;
    private final com.android.permissioncontroller.permission.data.LightPackageInfoLiveData packageInfoLiveData = null;
    private final com.android.permissioncontroller.permission.data.ForegroundPermNamesLiveData fgPermNamesLiveData = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final java.lang.String permGroupName = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData.Companion Companion = null;
    
    public final java.lang.String getLOG_TAG() {
        return null;
    }
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    /**
     * Check if permission group contains a runtime permission that split from an installed
     * permission and the split happened in an Android version higher than app's targetSdk.
     *
     * @return `true` if there is such permission, `false` otherwise
     */
    private final boolean hasInstallToRuntimeSplit(com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission> permissionMap) {
        return false;
    }
    
    @java.lang.Override()
    public void onLocationStateChange(boolean enabled) {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private LightAppPermGroupLiveData(android.app.Application app, java.lang.String packageName, java.lang.String permGroupName, android.os.UserHandle user) {
        super(false);
    }
    
    /**
     * Repository for AppPermGroupLiveDatas.
     * <p> Key value is a triple of string package name, string permission group name, and
     * UserHandle, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002 \u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\"\u0010\u0007\u001a\u00020\u00052\u0018\u0010\b\u001a\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LightAppPermGroupLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "Lkotlin/Triple;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/LightAppPermGroupLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<kotlin.Triple<? extends java.lang.String, ? extends java.lang.String, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Triple<java.lang.String, java.lang.String, android.os.UserHandle> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}