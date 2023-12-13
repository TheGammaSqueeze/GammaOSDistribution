package com.android.permissioncontroller.permission.service;

import android.content.pm.PackageManager;
import android.os.Process;
import androidx.core.util.Consumer;
import androidx.lifecycle.Lifecycle;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.Observer;
import com.android.permissioncontroller.DumpableLog;
import com.android.permissioncontroller.PermissionControllerProto.PermissionControllerDumpProto;
import com.android.permissioncontroller.permission.data.AppPermGroupUiInfoLiveData;
import com.android.permissioncontroller.permission.data.PackagePermissionsLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.data.UserPackageInfosLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;
import java.util.function.IntConsumer;

/**
 * A model for the PermissionControllerServiceImpl. Handles the data gathering for some methods of
 * ServiceImpl, and supports retrieving data from LiveDatas.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000j\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004JI\u0010\b\u001a\u00020\t\"\u0004\b\u0000\u0010\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u0002H\n0\u00072\b\b\u0002\u0010\f\u001a\u00020\r2#\u0010\u000e\u001a\u001f\u0012\u0015\u0012\u0013\u0018\u0001H\n\u00a2\u0006\f\b\u0010\u0012\b\b\u0011\u0012\u0004\b\b(\u0012\u0012\u0004\u0012\u00020\t0\u000fJ$\u0010\u0013\u001a\u00020\t2\f\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u00152\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aJ\u0011\u0010\u001b\u001a\u00020\u001cH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001dJ.\u0010\u001e\u001a\u00020\t2\u0006\u0010\u001f\u001a\u00020\u00162\u001e\u0010\u0019\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0016\u0012\u0004\u0012\u00020\"0!0\u00150 J6\u0010#\u001a\u00020\t2\f\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u00152\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u000e\u0010$\u001a\n\u0012\u0004\u0012\u00020%\u0018\u00010\u0015H\u0002J\u0006\u0010&\u001a\u00020\tR\u0018\u0010\u0005\u001a\f\u0012\b\u0012\u0006\u0012\u0002\b\u00030\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/service/PermissionControllerServiceModel;", "", "service", "Lcom/android/permissioncontroller/permission/service/PermissionControllerServiceImpl;", "(Lcom/android/permissioncontroller/permission/service/PermissionControllerServiceImpl;)V", "observedLiveDatas", "", "Landroidx/lifecycle/LiveData;", "observeAndCheckForLifecycleState", "", "T", "liveData", "forceUpdate", "", "onChangedFun", "Lkotlin/Function1;", "Lkotlin/ParameterName;", "name", "t", "onCountPermissionAppsLiveData", "permissionNames", "", "", "flags", "", "callback", "Ljava/util/function/IntConsumer;", "onDump", "Lcom/android/permissioncontroller/PermissionControllerProto$PermissionControllerDumpProto;", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onGetAppPermissions", "packageName", "Landroidx/core/util/Consumer;", "Lkotlin/Pair;", "Lcom/android/permissioncontroller/permission/model/livedatatypes/AppPermGroupUiInfo;", "onPackagesLoadedForCountPermissionApps", "packageInfos", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "removeObservers"})
public final class PermissionControllerServiceModel {
    private final java.util.List<androidx.lifecycle.LiveData<?>> observedLiveDatas = null;
    private final com.android.permissioncontroller.permission.service.PermissionControllerServiceImpl service = null;
    
    /**
     * *Must* be used instead of LiveData.observe, in order to allow the lifecycle state to
     * be set to "started" correctly. If the liveData was inactive, create a no op observer, which
     * will survive until the service goes inactive. Will remove the provided observer after one
     * update (one non-stale update, in the case of a SmartUpdateMediatorLiveData).
     *
     * @param liveData The livedata we wish to observe
     * @param onChangedFun The function we wish to be called upon livedata updates
     * @param <T> The type of the livedata and observer
     */
    public final <T extends java.lang.Object>void observeAndCheckForLifecycleState(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LiveData<T> liveData, boolean forceUpdate, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super T, kotlin.Unit> onChangedFun) {
    }
    
    /**
     * Stop observing all currently observed liveDatas
     */
    public final void removeObservers() {
    }
    
    /**
     * Counts the number of apps that have at least one of a provided list of permissions, subject
     * to the options specified in flags. This data is gathered from a series of LiveData objects.
     *
     * @param permissionNames The list of permission names whose apps we want to count
     * @param flags Flags specifying if we want to count system apps, and count only granted apps
     * @param callback The callback our result will be returned to
     */
    public final void onCountPermissionAppsLiveData(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> permissionNames, int flags, @org.jetbrains.annotations.NotNull()
    java.util.function.IntConsumer callback) {
    }
    
    /**
     * Called upon receiving a list of packages which we want to filter by a list of permissions
     * and flags. Observes the AppPermGroupUiInfoLiveData for every app, and, upon receiving a
     * non-stale update, adds it to the count if it matches the permission list and flags. Will
     * only use the first non-stale update, so if an app is updated after this update, but before
     * execution is complete, the changes will not be reflected until the method is called again.
     *
     * @param permissionNames The list of permission names whose apps we want to count
     * @param flags Flags specifying if we want to count system apps, and count only granted apps
     * @param callback The callback our result will be returned to
     * @param packageInfos The list of LightPackageInfos we want to filter and count
     */
    private final void onPackagesLoadedForCountPermissionApps(java.util.List<java.lang.String> permissionNames, int flags, java.util.function.IntConsumer callback, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> packageInfos) {
    }
    
    /**
     * Gets a list of the runtime permission groups which a package requests, and the UI information
     * about those groups. Will only use the first non-stale data for each group, so if an app is
     * updated after this update, but before execution is complete, the changes will not be
     * reflected until the method is called again.
     *
     * @param packageName The package whose permission information we want
     * @param callback The callback which will accept the list of <group name, group UI info> pairs
     */
    public final void onGetAppPermissions(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    androidx.core.util.Consumer<java.util.List<kotlin.Pair<java.lang.String, com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo>>> callback) {
    }
    
    /**
     * Dump state of the permission controller service
     *
     * @return the dump state as a proto
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object onDump(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super com.android.permissioncontroller.PermissionControllerProto.PermissionControllerDumpProto> p0) {
        return null;
    }
    
    public PermissionControllerServiceModel(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.service.PermissionControllerServiceImpl service) {
        super();
    }
}