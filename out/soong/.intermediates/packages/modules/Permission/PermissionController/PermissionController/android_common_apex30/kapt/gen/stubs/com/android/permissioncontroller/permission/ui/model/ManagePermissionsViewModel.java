package com.android.permissioncontroller.permission.ui.model;

import android.app.Application;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MediatorLiveData;
import com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData;
import com.android.permissioncontroller.permission.data.StandardPermGroupNamesLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo;

/**
 * A [androidx.lifecycle.ViewModel] for [ManagePermissionsFragment] and
 * [ManagePermissionsOtherFragment].
 * However, [ManagePermissionsViewModel] is designed in a way so that its owner should be an
 * [Activity][androidx.fragment.app.FragmentActivity] rather than individual
 * [Fragments][androidx.fragment.app.Fragment], and the aforementioned Fragments that manage
 * different sets of the permission groups should to share a single instance of
 * [ManagePermissionsViewModel].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0005\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u001d\u0010\u0005\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0019\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u00068G\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\nR\u001a\u0010\r\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010\u000e\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\nR\u001d\u0010\u0010\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\n"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ManagePermissionsViewModel;", "Landroidx/lifecycle/AndroidViewModel;", "app", "Landroid/app/Application;", "(Landroid/app/Application;)V", "additionalPermissionGroups", "Landroidx/lifecycle/LiveData;", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/PermGroupPackagesUiInfo;", "getAdditionalPermissionGroups", "()Landroidx/lifecycle/LiveData;", "hasUnusedOrAdditionalPermissionGroups", "", "standardPermGroupsLiveData", "unusedPermissionGroups", "getUnusedPermissionGroups", "usedPermissionGroups", "getUsedPermissionGroups"})
public final class ManagePermissionsViewModel extends androidx.lifecycle.AndroidViewModel {
    private final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> standardPermGroupsLiveData = null;
    
    /**
     * [LiveData] that contains a list of platform-defined permission groups, such
     * that at least one the permissions in the group has been requested at runtime by at least one
     * non-system application or has been pregranted to a non-system application.
     * @see com.android.permissioncontroller.permission.ui.television.ManagePermissionsFragment
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> usedPermissionGroups = null;
    
    /**
     * [LiveData] that contains a list of platform-defined permission groups, such that all
     * of the permissions in the group neither has been requested at runtime by any of the
     * non-system applications nor has been pregranted to any such application. But at least one of
     * the permissions in the group is requested by or pregranted to at least one system
     * application, other than the Shell (we do not show permission groups that are granted only to
     * the Shell, because it has all the permissions granted).
     * @see com.android.permissioncontroller.permission.ui.television.ManagePermissionsOtherFragment
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> unusedPermissionGroups = null;
    
    /**
     * [LiveData] that contains a list of the application-defined permission groups
     * (a.k.a. "custom" permissions), such that at least one of the permissions in the group has
     * been requested at runtime by or has been pregranted to at least one application (system or
     * non-system).
     * @see com.android.permissioncontroller.permission.ui.television.ManagePermissionsOtherFragment
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> additionalPermissionGroups = null;
    
    /**
     * [LiveData] that indicates whether there any unused or additional permission groups.
     * @see com.android.permissioncontroller.permission.ui.television.ManagePermissionsFragment
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.lang.Boolean> hasUnusedOrAdditionalPermissionGroups = null;
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> getUsedPermissionGroups() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> getUnusedPermissionGroups() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.PermGroupPackagesUiInfo>> getAdditionalPermissionGroups() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.lang.Boolean> hasUnusedOrAdditionalPermissionGroups() {
        return null;
    }
    
    public ManagePermissionsViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        super(null);
    }
}