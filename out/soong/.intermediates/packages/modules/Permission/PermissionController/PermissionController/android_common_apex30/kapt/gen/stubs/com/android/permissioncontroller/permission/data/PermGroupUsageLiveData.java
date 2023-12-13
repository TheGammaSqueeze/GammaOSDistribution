package com.android.permissioncontroller.permission.data;

import android.app.Application;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * LiveData that loads the last usage of permission group for every package/attributionTag-pair.
 *
 * <p>This relies on app-ops data, hence this only works for platform defined permission groups.
 *
 * <p>For app-ops with duration the end of the access is considered.
 *
 * <p>Returns map perm-group-name -> {@link OpUsageLiveData.OpAccess}
 *
 * @param app The current application
 * @param permGroupsNames The names of the permission groups we wish to search for
 * @param usageDurationMs how much ago can an access have happened to be considered
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\u0018\u0000 \u00102\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\u00020\u0001:\u0001\u0010B#\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00030\u0004\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\b\u0010\u000e\u001a\u00020\u000fH\u0014R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\f\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\r0\u0002X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00030\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupUsageLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "", "Lcom/android/permissioncontroller/permission/data/OpAccess;", "app", "Landroid/app/Application;", "permGroupsNames", "usageDurationMs", "", "(Landroid/app/Application;Ljava/util/List;J)V", "permGroupUsages", "Lcom/android/permissioncontroller/permission/data/OpUsageLiveData;", "onUpdate", "", "Companion"})
public final class PermGroupUsageLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<java.lang.String, ? extends java.util.List<? extends com.android.permissioncontroller.permission.data.OpAccess>>> {
    
    /**
     * Perm group name -> OpUsageLiveData
     */
    private final java.util.Map<java.lang.String, com.android.permissioncontroller.permission.data.OpUsageLiveData> permGroupUsages = null;
    private final android.app.Application app = null;
    private final java.util.List<java.lang.String> permGroupsNames = null;
    private final long usageDurationMs = 0L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.PermGroupUsageLiveData.Companion Companion = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public PermGroupUsageLiveData(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> permGroupsNames, long usageDurationMs) {
        super(false);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\u0010\t\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002 \u0012\u0016\u0012\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0004\u0012\u00020\u00050\u0002\u0012\u0004\u0012\u00020\u00060\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0007J\"\u0010\b\u001a\u00020\u00062\u0018\u0010\t\u001a\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0004\u0012\u00020\u00050\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/PermGroupUsageLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Pair;", "", "", "", "Lcom/android/permissioncontroller/permission/data/PermGroupUsageLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Pair<? extends java.util.List<? extends java.lang.String>, ? extends java.lang.Long>, com.android.permissioncontroller.permission.data.PermGroupUsageLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.PermGroupUsageLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<? extends java.util.List<java.lang.String>, java.lang.Long> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}