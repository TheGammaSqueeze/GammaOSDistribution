package com.android.permissioncontroller.permission.data;

import android.Manifest;
import android.app.Application;
import android.os.Build;
import android.os.UserHandle;
import androidx.lifecycle.LiveData;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.PermGroup;

/**
 * A LiveData which tracks either all platform permission groups, or all custom permission groups,
 * and the packages which contain runtime permissions in one of those group.
 *
 * @param app The current application
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\u0018\u0000 \u00152&\u0012\"\u0012 \u0012\u0004\u0012\u00020\u0003\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00060\u00050\u00040\u00020\u0001:\u0001\u0015B#\b\u0002\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0012\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u000b0\n\u00a2\u0006\u0002\u0010\fJ\b\u0010\u0013\u001a\u00020\u0014H\u0014R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u00030\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0010\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00120\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "", "Lkotlin/Pair;", "Landroid/os/UserHandle;", "app", "Landroid/app/Application;", "groupNamesLiveData", "Landroidx/lifecycle/LiveData;", "", "(Landroid/app/Application;Landroidx/lifecycle/LiveData;)V", "groupNames", "packagesLiveData", "Lcom/android/permissioncontroller/permission/data/AllPackageInfosLiveData;", "permGroupLiveDatas", "", "Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "onUpdate", "", "Companion"})
public final class PermGroupsPackagesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<java.lang.String, ? extends java.util.Set<? extends kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>>>> {
    private final com.android.permissioncontroller.permission.data.AllPackageInfosLiveData packagesLiveData = null;
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.PermGroupLiveData> permGroupLiveDatas = null;
    private java.util.List<java.lang.String> groupNames;
    private final android.app.Application app = null;
    private static final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData customInstance = null;
    private static final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData standardInstance = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData.Companion Companion = null;
    
    /**
     * Using the current list of permission groups, go through all packages in the system,
     * and figure out which permission groups they have permissions for. If applicable, remove
     * any lone-permission permission that are not requested by any packages.
     */
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    private PermGroupsPackagesLiveData(android.app.Application app, androidx.lifecycle.LiveData<java.util.List<java.lang.String>> groupNamesLiveData) {
        super(false);
    }
    
    /**
     * Get either the PermGroupsPackageLiveData instance corresponding either to the custom
     * permission groups, or the standard permission group.
     *
     * @param customGroups Whether to get the custom groups instance, or the standard
     *
     * @return The specified PermGroupsPackageLiveData
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData get(boolean customGroups) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0006\u001a\u00020\u00042\b\b\u0002\u0010\u0007\u001a\u00020\bH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData$Companion;", "", "()V", "customInstance", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData;", "standardInstance", "get", "customGroups", ""})
    public static final class Companion {
        
        /**
         * Get either the PermGroupsPackageLiveData instance corresponding either to the custom
         * permission groups, or the standard permission group.
         *
         * @param customGroups Whether to get the custom groups instance, or the standard
         *
         * @return The specified PermGroupsPackageLiveData
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData get(boolean customGroups) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}