package com.android.permissioncontroller.permission.data;

import android.Manifest;
import android.app.AppOpsManager;
import android.app.Application;
import android.content.pm.PackageManager;
import android.content.pm.PermissionInfo;
import android.os.Build;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.PermState;
import com.android.permissioncontroller.permission.utils.LocationUtils;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A LiveData representing UI properties of an App Permission Group:
 * <ul>
 *    <li>shouldShow</li>
 *    <li>isSystem</li>
 *    <li>isGranted</li>
 * </ul>
 *
 * @param app The current application
 * @param packageName The name of the package
 * @param permGroupName The name of the permission group whose permissions are observed
 * @param user The user of the package
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000~\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u001e\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\u0018\u0000 42\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u00014B\'\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ@\u0010\u0015\u001a\u00020\u00022\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0012\u0010\u001a\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001c0\u001b2\u0012\u0010\u001d\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001e0\u001bH\u0002J8\u0010\u001f\u001a\u00020 2\u0012\u0010\u001d\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001e0\u001b2\u0012\u0010\u001a\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001c0\u001b2\u0006\u0010!\u001a\u00020\u0017H\u0002J\u000f\u0010\"\u001a\u0004\u0018\u00010\rH\u0002\u00a2\u0006\u0002\u0010#J\u0010\u0010$\u001a\u00020\r2\u0006\u0010!\u001a\u00020\u0017H\u0002J&\u0010%\u001a\u00020\r2\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\f\u0010&\u001a\b\u0012\u0004\u0012\u00020\u001c0\'H\u0002J\u001c\u0010(\u001a\u00020\r2\u0012\u0010\u001d\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001e0\u001bH\u0002J\u001c\u0010)\u001a\u00020\r2\u0012\u0010\u001d\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u001e0\u001bH\u0002J\u0019\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010.J\b\u0010/\u001a\u00020+H\u0014J\b\u00100\u001a\u00020+H\u0014J\u0010\u00101\u001a\u00020+2\u0006\u00102\u001a\u00020\rH\u0016J\b\u00103\u001a\u00020\rH\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AppPermGroupUiInfoLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo;", "Lcom/android/permissioncontroller/permission/utils/LocationUtils$LocationListener;", "app", "Landroid/app/Application;", "packageName", "", "permGroupName", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;)V", "isSpecialLocation", "", "isStorage", "packageInfoLiveData", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "permGroupLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "permissionStateLiveData", "Lcom/android/permissioncontroller/permission/data/PermStateLiveData;", "getAppPermGroupUiInfo", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "groupInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "allPermInfos", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermInfo;", "permissionState", "Lcom/android/permissioncontroller/permission/model/livedatatypes/PermState;", "getGrantedIncludingBackground", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;", "pkg", "getIsSpecialLocationState", "()Ljava/lang/Boolean;", "isFullFilesAccessGranted", "isGrantableAndNotLegacyPlatform", "permissionInfos", "", "isUserSensitive", "isUserSet", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onLocationStateChange", "enabled", "shouldShowAsForegroundGroup", "Companion"})
public final class AppPermGroupUiInfoLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo> implements com.android.permissioncontroller.permission.utils.LocationUtils.LocationListener {
    private boolean isSpecialLocation = false;
    private final com.android.permissioncontroller.permission.data.LightPackageInfoLiveData packageInfoLiveData = null;
    private final com.android.permissioncontroller.permission.data.PermGroupLiveData permGroupLiveData = null;
    private final com.android.permissioncontroller.permission.data.PermStateLiveData permissionStateLiveData = null;
    private final boolean isStorage = false;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final java.lang.String permGroupName = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    /**
     * Determines if the UI should show a given package, if that package is a system app, and
     * if it has granted permissions in this LiveData's permission group.
     *
     * @param packageInfo The PackageInfo of the package we wish to examine
     * @param groupInfo The groupInfo of the permission group we wish to examine
     * @param allPermInfos All of the PermissionInfos in the permission group
     * @param permissionState The flags and grant state for all permissions in the permission
     * group that this package requests
     */
    private final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo getAppPermGroupUiInfo(com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> allPermInfos, java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermState> permissionState) {
        return null;
    }
    
    /**
     * Determines if a package permission group is able to be granted, and whether or not it is a
     * legacy system permission group.
     *
     * @param packageInfo The PackageInfo of the package we are examining
     * @param groupInfo The Permission Group Info of the permission group we are examining
     * @param permissionInfos The LightPermInfos corresponding to the permissions in the
     * permission group that this package requests
     *
     * @return True if the app permission group is grantable, and is not a legacy system permission,
     * false otherwise.
     */
    private final boolean isGrantableAndNotLegacyPlatform(com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, java.util.Collection<com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> permissionInfos) {
        return false;
    }
    
    /**
     * Determines if an app's permission group is user-sensitive. If an app is not user sensitive,
     * then it is considered a system app, and hidden in the UI by default.
     *
     * @param permissionState The permission flags and grant state corresponding to the permissions
     * in this group requested by a given app
     *
     * @return Whether or not this package requests a user sensitive permission in the given
     * permission group
     */
    private final boolean isUserSensitive(java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermState> permissionState) {
        return false;
    }
    
    /**
     * Determines if the app permission group is user set
     *
     * @param permissionState The permission flags and grant state corresponding to the permissions
     * in this group requested by a given app
     *
     * @return Whether or not any of the permissions in this group have been set or fixed by the
     * user
     */
    private final boolean isUserSet(java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermState> permissionState) {
        return false;
    }
    
    /**
     * Determines if this app permission group is granted, granted in foreground only, or denied.
     * It is granted if it either requests no background permissions, and has at least one requested
     * permission that is granted, or has granted at least one requested background permission.
     * It is granted in foreground only if it has at least one non-background permission granted,
     * and has denied all requested background permissions. It is denied if all requested
     * permissions are denied.
     *
     * @param permissionState The permission flags and grant state corresponding to the permissions
     * in this group requested by a given app
     * @param allPermInfos All of the permissionInfos in the permission group of this app
     * permission group
     *
     * @return The int code corresponding to the app permission group state, either allowed, allowed
     * in foreground only, or denied.
     */
    private final com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState getGrantedIncludingBackground(java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermState> permissionState, java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.LightPermInfo> allPermInfos, com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkg) {
        return null;
    }
    
    private final java.lang.Boolean getIsSpecialLocationState() {
        return null;
    }
    
    private final boolean isFullFilesAccessGranted(com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo pkg) {
        return false;
    }
    
    private final boolean shouldShowAsForegroundGroup() {
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
    
    private AppPermGroupUiInfoLiveData(android.app.Application app, java.lang.String packageName, java.lang.String permGroupName, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for AppPermGroupUiInfoLiveDatas.
     * <p> Key value is a triple of string package name, string permission group name, and UserHandle,
     * value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002 \u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\"\u0010\u0007\u001a\u00020\u00052\u0018\u0010\b\u001a\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AppPermGroupUiInfoLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "Lkotlin/Triple;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/AppPermGroupUiInfoLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepositoryForPackage<kotlin.Triple<? extends java.lang.String, ? extends java.lang.String, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Triple<java.lang.String, java.lang.String, android.os.UserHandle> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}