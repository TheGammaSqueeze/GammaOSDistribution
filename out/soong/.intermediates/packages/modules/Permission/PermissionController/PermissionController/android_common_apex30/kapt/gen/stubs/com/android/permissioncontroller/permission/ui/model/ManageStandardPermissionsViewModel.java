package com.android.permissioncontroller.permission.ui.model;

import android.app.Application;
import android.os.Bundle;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.Transformations;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData;
import com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.data.StandardPermGroupNamesLiveData;

/**
 * A ViewModel for the ManageStandardPermissionsFragment. Provides a LiveData which watches over all
 * platform permission groups, and sends async updates when these groups have changes. It also
 * provides a liveData which watches the custom permission groups of the system, and provides
 * a list of group names.
 * @param app The current application of the fragment
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0018J\u0016\u0010\u0019\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0018J\u0016\u0010\u001a\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0018R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001f\u0010\u0005\u001a\u0010\u0012\f\u0012\n \b*\u0004\u0018\u00010\u00070\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ManageStandardPermissionsViewModel;", "Landroidx/lifecycle/AndroidViewModel;", "app", "Landroid/app/Application;", "(Landroid/app/Application;)V", "numAutoRevoked", "Landroidx/lifecycle/LiveData;", "", "kotlin.jvm.PlatformType", "getNumAutoRevoked", "()Landroidx/lifecycle/LiveData;", "numCustomPermGroups", "Lcom/android/permissioncontroller/permission/ui/model/NumCustomPermGroupsWithPackagesLiveData;", "getNumCustomPermGroups", "()Lcom/android/permissioncontroller/permission/ui/model/NumCustomPermGroupsWithPackagesLiveData;", "uiDataLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesUiInfoLiveData;", "getUiDataLiveData", "()Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesUiInfoLiveData;", "showAutoRevoke", "", "fragment", "Landroidx/fragment/app/Fragment;", "args", "Landroid/os/Bundle;", "showCustomPermissions", "showPermissionApps"})
public final class ManageStandardPermissionsViewModel extends androidx.lifecycle.AndroidViewModel {
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData uiDataLiveData = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.ui.model.NumCustomPermGroupsWithPackagesLiveData numCustomPermGroups = null;
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.lang.Integer> numAutoRevoked = null;
    private final android.app.Application app = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData getUiDataLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.ui.model.NumCustomPermGroupsWithPackagesLiveData getNumCustomPermGroups() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.lang.Integer> getNumAutoRevoked() {
        return null;
    }
    
    /**
     * Navigate to the Custom Permissions screen
     *
     * @param fragment The fragment we are navigating from
     * @param args The args to pass to the new fragment
     */
    public final void showCustomPermissions(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    /**
     * Navigate to a Permission Apps fragment
     *
     * @param fragment The fragment we are navigating from
     * @param args The args to pass to the new fragment
     */
    public final void showPermissionApps(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    public final void showAutoRevoke(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    public ManageStandardPermissionsViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        super(null);
    }
}