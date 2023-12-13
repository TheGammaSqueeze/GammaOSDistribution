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
 * A LiveData which tracks the names of Custom Permission Groups which are used by at least one
 * package. This includes single-permission permission groups, as well as the Undefined permission
 * group, and any other permission groups not defined by the system.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u0002\u0018\u00002\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0004J\b\u0010\u0005\u001a\u00020\u0006H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/UsedCustomPermGroupNamesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "()V", "onUpdate", ""})
public final class UsedCustomPermGroupNamesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.List<? extends java.lang.String>> {
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public UsedCustomPermGroupNamesLiveData() {
        super(false);
    }
}