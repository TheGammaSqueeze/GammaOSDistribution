package com.android.permissioncontroller.permission.ui.model;

import android.app.Application;
import android.os.Bundle;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData;
import com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;

/**
 * A ViewModel for the ManageCustomPermissionsFragment. Provides a LiveData which watches over all
 * custom permission groups, and sends async updates when these groups have changes.
 *
 * @param app The current application of the fragment
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ManageCustomPermissionsViewModel;", "Landroidx/lifecycle/AndroidViewModel;", "app", "Landroid/app/Application;", "(Landroid/app/Application;)V", "uiDataLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesUiInfoLiveData;", "getUiDataLiveData", "()Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesUiInfoLiveData;", "showPermissionApps", "", "fragment", "Landroidx/fragment/app/Fragment;", "args", "Landroid/os/Bundle;"})
public final class ManageCustomPermissionsViewModel extends androidx.lifecycle.AndroidViewModel {
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData uiDataLiveData = null;
    private final android.app.Application app = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.PermGroupsPackagesUiInfoLiveData getUiDataLiveData() {
        return null;
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
    
    public ManageCustomPermissionsViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        super(null);
    }
}