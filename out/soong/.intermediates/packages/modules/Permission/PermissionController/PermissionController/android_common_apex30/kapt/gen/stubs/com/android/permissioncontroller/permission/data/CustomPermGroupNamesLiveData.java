package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PermissionInfo;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A class which tracks the names of all custom permission groups in the system, including
 * non-grouped runtime permissions, the UNDEFINED group, and any group not defined by the system.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\b\u00c6\u0002\u0018\u00002\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\b\u0010\t\u001a\u00020\nH\u0014R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/CustomPermGroupNamesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "()V", "app", "Landroid/app/Application;", "packagesLiveData", "Lcom/android/permissioncontroller/permission/data/AllPackageInfosLiveData;", "onUpdate", ""})
public final class CustomPermGroupNamesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.List<? extends java.lang.String>> {
    private static final android.app.Application app = null;
    private static final com.android.permissioncontroller.permission.data.AllPackageInfosLiveData packagesLiveData = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.CustomPermGroupNamesLiveData INSTANCE = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    private CustomPermGroupNamesLiveData() {
        super(false);
    }
}