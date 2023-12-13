package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * LiveData for the UI info for all packages in a single permission group. Tracks which packages
 * have permissions in the given group, which should be shown on the UI, and which are granted or
 * not.
 *
 * @param app The current application
 * @param permGroupName The name of the permission group this LiveData represents
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\b\u0002\u0018\u0000 \u001a2 \u0012\u001c\u0012\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\u0004\u0012\u00020\u00060\u00020\u0001:\u0001\u001aB\u0017\b\u0002\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\nJ\"\u0010\u0015\u001a\u00020\u00162\u0018\u0010\u0017\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u00030\u0018H\u0002J\b\u0010\u0019\u001a\u00020\u0016H\u0014R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u000b\u001a\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\u0004\u0012\u00020\r0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u0014\u001a\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\u0004\u0012\u00020\u00060\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/SinglePermGroupPackagesUiInfoLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo;", "app", "Landroid/app/Application;", "permGroupName", "(Landroid/app/Application;Ljava/lang/String;)V", "appPermGroupLiveDatas", "", "Lcom/android/permissioncontroller/permission/data/AppPermGroupUiInfoLiveData;", "isCustomGroup", "", "permGroupLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupLiveData;", "permGroupPackagesLiveData", "Lcom/android/permissioncontroller/permission/data/PermGroupsPackagesLiveData;", "shownPackages", "addAndRemoveAppPermGroupLiveDatas", "", "pkgs", "", "onUpdate", "Companion"})
public final class SinglePermGroupPackagesUiInfoLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>, ? extends com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo>> {
    private final com.android.permissioncontroller.permission.data.PermGroupLiveData permGroupLiveData = null;
    private final boolean isCustomGroup = false;
    private final com.android.permissioncontroller.permission.data.PermGroupsPackagesLiveData permGroupPackagesLiveData = null;
    
    /**
     * Map<Pair<package name, UserHandle>, UI data LiveData>
     */
    private final java.util.Map<kotlin.Pair<java.lang.String, android.os.UserHandle>, com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData> appPermGroupLiveDatas = null;
    
    /**
     * Map<Pair<packageName, userHandle>, UI data>.
     */
    private final java.util.Map<kotlin.Pair<java.lang.String, android.os.UserHandle>, com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo> shownPackages = null;
    private final android.app.Application app = null;
    private final java.lang.String permGroupName = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData.Companion Companion = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    private final void addAndRemoveAppPermGroupLiveDatas(java.util.List<kotlin.Pair<java.lang.String, android.os.UserHandle>> pkgs) {
    }
    
    private SinglePermGroupPackagesUiInfoLiveData(android.app.Application app, java.lang.String permGroupName) {
        super(false);
    }
    
    /**
     * Repository for SinglePermGroupPackagesUiInfoLiveData objects.
     * <p> Key value is a string permission group name, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/SinglePermGroupPackagesUiInfoLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "", "Lcom/android/permissioncontroller/permission/data/SinglePermGroupPackagesUiInfoLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<java.lang.String, com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData newValue(@org.jetbrains.annotations.NotNull()
        java.lang.String key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}