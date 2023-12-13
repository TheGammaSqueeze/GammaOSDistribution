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
 * A LiveData which tracks the number of custom permission groups that are used by at least one
 * package
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0003J\b\u0010\u0006\u001a\u00020\u0007H\u0014R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/NumCustomPermGroupsWithPackagesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "()V", "customPermGroupPackages", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData;", "onUpdate", ""})
public final class NumCustomPermGroupsWithPackagesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.lang.Integer> {
    private final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData customPermGroupPackages = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public NumCustomPermGroupsWithPackagesLiveData() {
        super(false);
    }
}