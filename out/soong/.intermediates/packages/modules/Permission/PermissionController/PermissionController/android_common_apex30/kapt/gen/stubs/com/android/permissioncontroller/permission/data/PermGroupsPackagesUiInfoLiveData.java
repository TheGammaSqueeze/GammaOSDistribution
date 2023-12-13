package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.app.role.RoleManager;
import android.os.UserHandle;
import androidx.lifecycle.LiveData;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A LiveData which tracks all app permission groups for a set of permission groups, either platform
 * or custom, as well as the UI information related to each app permission group, and the permission
 * group as a whole.
 *
 * @param app The current application
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010%\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u001b\u0012\u0017\u0012\u0015\u0012\u0004\u0012\u00020\u0003\u0012\u0006\u0012\u0004\u0018\u00010\u00040\u0002\u00a2\u0006\u0002\b\u00050\u0001B!\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0012\u0010\b\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\n0\t\u00a2\u0006\u0002\u0010\u000bJ0\u0010\u0012\u001a\u00020\u00042\u0006\u0010\u0013\u001a\u00020\u00032\u001e\u0010\u0014\u001a\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00160\u0015\u0012\u0004\u0012\u00020\u00170\u0002H\u0002J\b\u0010\u0018\u001a\u00020\u0019H\u0002J\u0010\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001dH\u0002J\u0012\u0010\u001e\u001a\u00020\u001b2\b\u0010\u001f\u001a\u0004\u0018\u00010\u0003H\u0002J\b\u0010 \u001a\u00020\u0019H\u0014R\u000e\u0010\f\u001a\u00020\u0003X\u0082D\u00a2\u0006\u0002\n\u0000R\u001c\u0010\r\u001a\u0010\u0012\u0004\u0012\u00020\u0003\u0012\u0006\u0012\u0004\u0018\u00010\u00040\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00030\nX\u0082.\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0010\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00110\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesUiInfoLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/PermGroupPackagesUiInfo;", "Lkotlin/jvm/JvmSuppressWildcards;", "app", "Landroid/app/Application;", "groupNamesLiveData", "Landroidx/lifecycle/LiveData;", "", "(Landroid/app/Application;Landroidx/lifecycle/LiveData;)V", "SYSTEM_SHELL", "allPackageData", "", "groupNames", "permGroupPackagesLiveDatas", "Lcom/android/permissioncontroller/permission/data/SinglePermGroupPackagesUiInfoLiveData;", "createPermGroupPackageUiInfo", "groupName", "appPermGroups", "Lkotlin/Pair;", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo;", "getPermGroupPackageLiveDatas", "", "isGranted", "", "grantState", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo$PermGrantState;", "isPackageShell", "packageName", "onUpdate"})
public final class PermGroupsPackagesUiInfoLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> {
    private final java.lang.String SYSTEM_SHELL = "android.app.role.SYSTEM_SHELL";
    
    /**
     * Map<permission group name, PermGroupUiLiveDatas>
     */
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData> permGroupPackagesLiveDatas = null;
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo> allPackageData = null;
    private java.util.List<java.lang.String> groupNames;
    private final android.app.Application app = null;
    
    private final void getPermGroupPackageLiveDatas() {
    }
    
    private final boolean isGranted(com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState grantState) {
        return false;
    }
    
    private final com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo createPermGroupPackageUiInfo(java.lang.String groupName, java.util.Map<kotlin.Pair<java.lang.String, android.os.UserHandle>, com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo> appPermGroups) {
        return null;
    }
    
    private final boolean isPackageShell(java.lang.String packageName) {
        return false;
    }
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public PermGroupsPackagesUiInfoLiveData(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LiveData<java.util.List<java.lang.String>> groupNamesLiveData) {
        super(false);
    }
}