package com.android.permissioncontroller.permission.ui.model;

import android.Manifest;
import android.app.Application;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.UserHandle;
import android.util.Log;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.AbstractSavedStateViewModelFactory;
import androidx.lifecycle.MediatorLiveData;
import androidx.lifecycle.SavedStateHandle;
import androidx.lifecycle.ViewModel;
import androidx.preference.Preference;
import androidx.savedstate.SavedStateRegistryOwner;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.AllPackageInfosLiveData;
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData;
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState;
import com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData;
import com.android.permissioncontroller.permission.model.AppPermissionUsage;
import com.android.permissioncontroller.permission.model.livedatatypes.AppPermGroupUiInfo.PermGrantState;
import com.android.permissioncontroller.permission.ui.Category;
import com.android.permissioncontroller.permission.ui.LocationProviderInterceptDialog;
import com.android.permissioncontroller.permission.utils.LocationUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import java.text.Collator;
import java.time.Instant;
import java.util.concurrent.TimeUnit;

/**
 * ViewModel for the PermissionAppsFragment. Has a liveData with all of the UI info for each
 * package which requests permissions in this permission group, a liveData which tracks whether or
 * not to show system apps, and a liveData tracking whether there are any system apps which request
 * permissions in this group.
 *
 * @param app The current application
 * @param groupName The name of the permission group this viewModel is representing
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0092\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\u0018\u0000 I2\u00020\u0001:\u0002HIB\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0006\u0010 \u001a\u00020\u000eJ\u001e\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020$2\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020&J \u0010(\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020*0)2\f\u0010+\u001a\b\u0012\u0004\u0012\u00020,0\u001aJ\u0006\u0010-\u001a\u00020*J\"\u0010.\u001a\u00020\u00072\u0006\u0010/\u001a\u0002002\u0012\u00101\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\"02JV\u00103\u001a\u0002042\u0006\u00105\u001a\u00020\u00072\u0006\u00106\u001a\u0002072\u0006\u00108\u001a\u00020*2\u0006\u00109\u001a\u00020\u000e2\u0006\u0010:\u001a\u00020\u000e2\u0006\u0010;\u001a\u00020\u000e2\u0006\u0010<\u001a\u00020*2\u0006\u0010=\u001a\u00020\u00052\u0006\u0010>\u001a\u00020\u00072\u0006\u0010?\u001a\u00020\u0007J&\u0010@\u001a\u0002042\u0006\u0010A\u001a\u00020B2\u0006\u00105\u001a\u00020\u00072\u0006\u00106\u001a\u0002072\u0006\u0010C\u001a\u00020DJ\u0016\u0010E\u001a\u00020\u000e2\u0006\u00105\u001a\u00020\u00072\u0006\u00106\u001a\u000207J\u000e\u0010F\u001a\u0002042\u0006\u0010G\u001a\u00020\u000eR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0015\u0010\t\u001a\u00060\nR\u00020\u0000\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR$\u0010\u000f\u001a\u00020\u000e2\u0006\u0010\r\u001a\u00020\u000e8F@FX\u0086\u000e\u00a2\u0006\f\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001f\u0010\u0014\u001a\u0010\u0012\f\u0012\n \u0016*\u0004\u0018\u00010\u000e0\u000e0\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u0014\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001b0\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001f\u0010\u001c\u001a\u0010\u0012\f\u0012\n \u0016*\u0004\u0018\u00010\u000e0\u000e0\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u0018R\u001f\u0010\u001e\u001a\u0010\u0012\f\u0012\n \u0016*\u0004\u0018\u00010\u000e0\u000e0\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u0018R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel;", "Landroidx/lifecycle/ViewModel;", "state", "Landroidx/lifecycle/SavedStateHandle;", "app", "Landroid/app/Application;", "groupName", "", "(Landroidx/lifecycle/SavedStateHandle;Landroid/app/Application;Ljava/lang/String;)V", "categorizedAppsLiveData", "Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel$CategorizedAppsLiveData;", "getCategorizedAppsLiveData", "()Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel$CategorizedAppsLiveData;", "value", "", "creationLogged", "getCreationLogged", "()Z", "setCreationLogged", "(Z)V", "hasSystemAppsLiveData", "Landroidx/lifecycle/MutableLiveData;", "kotlin.jvm.PlatformType", "getHasSystemAppsLiveData", "()Landroidx/lifecycle/MutableLiveData;", "packagesWithFullFileAccess", "", "Lcom/android/permissioncontroller/permission/data/FullStoragePermissionAppsLiveData$FullStoragePackageState;", "shouldShowSystemLiveData", "getShouldShowSystemLiveData", "showAllowAlwaysStringLiveData", "getShowAllowAlwaysStringLiveData", "arePackagesLoaded", "comparePreference", "", "collator", "Ljava/text/Collator;", "lhs", "Landroidx/preference/Preference;", "rhs", "extractGroupUsageLastAccessTime", "", "", "appPermissionUsages", "Lcom/android/permissioncontroller/permission/model/AppPermissionUsage;", "getFilterTimeBeginMillis", "getPreferenceSummary", "res", "Landroid/content/res/Resources;", "summaryTimestamp", "Lkotlin/Pair;", "logPermissionAppsFragmentCreated", "", "packageName", "user", "Landroid/os/UserHandle;", "viewId", "isAllowed", "isAllowedForeground", "isDenied", "sessionId", "application", "permGroupName", "tag", "navigateToAppPermission", "fragment", "Landroidx/fragment/app/Fragment;", "args", "Landroid/os/Bundle;", "packageHasFullStorage", "updateShowSystem", "showSystem", "CategorizedAppsLiveData", "Companion"})
public final class PermissionAppsViewModel extends androidx.lifecycle.ViewModel {
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.MutableLiveData<java.lang.Boolean> shouldShowSystemLiveData = null;
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.MutableLiveData<java.lang.Boolean> hasSystemAppsLiveData = null;
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.MutableLiveData<java.lang.Boolean> showAllowAlwaysStringLiveData = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.ui.model.PermissionAppsViewModel.CategorizedAppsLiveData categorizedAppsLiveData = null;
    
    /**
     * If this is the storage permission group, some apps have full access to storage, while
     * others just have access to media files. This list contains the packages with full access.
     * To listen for changes, create and observe a FullStoragePermissionAppsLiveData
     */
    private java.util.List<com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState> packagesWithFullFileAccess;
    private final androidx.lifecycle.SavedStateHandle state = null;
    private final android.app.Application app = null;
    private final java.lang.String groupName = null;
    public static final int AGGREGATE_DATA_FILTER_BEGIN_DAYS = 1;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String SHOULD_SHOW_SYSTEM_KEY = "showSystem";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String HAS_SYSTEM_APPS_KEY = "hasSystem";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String SHOW_ALWAYS_ALLOWED = "showAlways";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String CREATION_LOGGED_KEY = "creationLogged";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.model.PermissionAppsViewModel.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<java.lang.Boolean> getShouldShowSystemLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<java.lang.Boolean> getHasSystemAppsLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<java.lang.Boolean> getShowAllowAlwaysStringLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.ui.model.PermissionAppsViewModel.CategorizedAppsLiveData getCategorizedAppsLiveData() {
        return null;
    }
    
    public final void updateShowSystem(boolean showSystem) {
    }
    
    public final boolean getCreationLogged() {
        return false;
    }
    
    public final void setCreationLogged(boolean value) {
    }
    
    /**
     * Whether or not to show the "Files and Media" subtitle label for a package, vs. the normal
     * "Media". Requires packagesWithFullFileAccess to be updated in order to work. To do this,
     * create and observe a FullStoragePermissionAppsLiveData.
     *
     * @param packageName The name of the package we want to check
     * @param user The name of the user whose package we want to check
     *
     * @return true if the package and user has full file access
     */
    public final boolean packageHasFullStorage(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return false;
    }
    
    /**
     * Whether or not packages have been loaded from the system.
     * To update, need to observe the allPackageInfosLiveData.
     *
     * @return Whether or not all packages have been loaded
     */
    public final boolean arePackagesLoaded() {
        return false;
    }
    
    /**
     * Navigate to an AppPermissionFragment, unless this is a special location package
     *
     * @param fragment The fragment attached to this ViewModel
     * @param packageName The package name we want to navigate to
     * @param user The user we want to navigate to the package of
     * @param args The arguments to pass onto the fragment
     */
    public final void navigateToAppPermission(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    public final long getFilterTimeBeginMillis() {
        return 0L;
    }
    
    /**
     * Return a mapping of user + packageName to their last access timestamps for the permission
     * group.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, java.lang.Long> extractGroupUsageLastAccessTime(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.permissioncontroller.permission.model.AppPermissionUsage> appPermissionUsages) {
        return null;
    }
    
    /**
     * Return the String preference summary based on the last access time.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPreferenceSummary(@org.jetbrains.annotations.NotNull()
    android.content.res.Resources res, @org.jetbrains.annotations.NotNull()
    kotlin.Pair<java.lang.String, java.lang.Integer> summaryTimestamp) {
        return null;
    }
    
    /**
     * Return two preferences to determine their ordering.
     */
    public final int comparePreference(@org.jetbrains.annotations.NotNull()
    java.text.Collator collator, @org.jetbrains.annotations.NotNull()
    androidx.preference.Preference lhs, @org.jetbrains.annotations.NotNull()
    androidx.preference.Preference rhs) {
        return 0;
    }
    
    /**
     * Log that the fragment was created.
     */
    public final void logPermissionAppsFragmentCreated(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long viewId, boolean isAllowed, boolean isAllowedForeground, boolean isDenied, long sessionId, @org.jetbrains.annotations.NotNull()
    android.app.Application application, @org.jetbrains.annotations.NotNull()
    java.lang.String permGroupName, @org.jetbrains.annotations.NotNull()
    java.lang.String tag) {
    }
    
    public PermissionAppsViewModel(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.SavedStateHandle state, @org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\b\u0086\u0004\u0018\u00002+\u0012\'\u0012%\u0012\u0004\u0012\u00020\u0003\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u00050\u00040\u0002\u00a2\u0006\u0002\b\b0\u0001B\r\u0012\u0006\u0010\t\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\nJ\u0006\u0010\r\u001a\u00020\u000eR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel$CategorizedAppsLiveData;", "Landroidx/lifecycle/MediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/ui/Category;", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "Lkotlin/jvm/JvmSuppressWildcards;", "groupName", "(Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel;Ljava/lang/String;)V", "packagesUiInfoLiveData", "Lcom/android/permissioncontroller/permission/data/SinglePermGroupPackagesUiInfoLiveData;", "update", ""})
    public final class CategorizedAppsLiveData extends androidx.lifecycle.MediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.Category, java.util.List<kotlin.Pair<java.lang.String, android.os.UserHandle>>>> {
        private final com.android.permissioncontroller.permission.data.SinglePermGroupPackagesUiInfoLiveData packagesUiInfoLiveData = null;
        
        public final void update() {
        }
        
        public CategorizedAppsLiveData(@org.jetbrains.annotations.NotNull()
        java.lang.String groupName) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0006X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0006X\u0080T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/PermissionAppsViewModel$Companion;", "", "()V", "AGGREGATE_DATA_FILTER_BEGIN_DAYS", "", "CREATION_LOGGED_KEY", "", "HAS_SYSTEM_APPS_KEY", "SHOULD_SHOW_SYSTEM_KEY", "SHOW_ALWAYS_ALLOWED"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}