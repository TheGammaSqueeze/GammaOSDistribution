package com.android.permissioncontroller.permission.ui.model;

import android.Manifest;
import android.app.Activity;
import android.app.Application;
import android.app.admin.DevicePolicyManager;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Process;
import android.permission.PermissionManager;
import android.util.Log;
import androidx.core.util.Consumer;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.Constants;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData;
import com.android.permissioncontroller.permission.data.LightPackageInfoLiveData;
import com.android.permissioncontroller.permission.data.PackagePermissionsLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo;
import com.android.permissioncontroller.permission.ui.AutoGrantPermissionsNotifier;
import com.android.permissioncontroller.permission.ui.GrantPermissionsActivity;
import com.android.permissioncontroller.permission.ui.GrantPermissionsViewHandler;
import com.android.permissioncontroller.permission.ui.ManagePermissionsActivity;
import com.android.permissioncontroller.permission.utils.AdminRestrictedPermissionsUtils;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.SafetyNetLogger;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;

/**
 * ViewModel for the GrantPermissionsActivity. Tracks all permission groups that are affected by
 * the permissions requested by the user, and generates a RequestInfo object for each group, if
 * action is needed. It will not return any data if one of the requests is malformed.
 *
 * @param app: The current application
 * @param packageName: The packageName permissions are being requested for
 * @param requestedPermissions: The list of permissions requested
 * @param sessionId: A long to identify this session
 * @param storedState: Previous state, if this activity was stopped and is being recreated
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a0\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010!\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010$\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u001e\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u0000 \\2\u00020\u0001:\u0003\\]^B5\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\u0010\n\u001a\u0004\u0018\u00010\u000b\u00a2\u0006\u0002\u0010\fJ\u0006\u00100\u001a\u000201J0\u00102\u001a\b\u0012\u0004\u0012\u00020\u00050\u00072\u0006\u00103\u001a\u00020\u00052\u0018\u00104\u001a\u0014\u0012\u0004\u0012\u00020\u0005\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u000705H\u0002J\b\u00106\u001a\u00020\u0017H\u0002J&\u00107\u001a\u00020\'2\u0006\u00103\u001a\u00020\u00052\u0006\u00108\u001a\u0002092\f\u0010:\u001a\b\u0012\u0004\u0012\u00020\u00050\u0007H\u0002J \u0010;\u001a\u0004\u0018\u0001092\u0006\u00103\u001a\u00020\u00052\f\u0010<\u001a\b\u0012\u0004\u0012\u0002090\u0007H\u0002J\u0018\u0010=\u001a\u00020\u00052\u0006\u0010>\u001a\u00020\u00052\u0006\u0010?\u001a\u00020\u001dH\u0002J.\u0010@\u001a\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u001d0\u001c\u0012\u0004\u0012\u00020\u001e0\u001b2\f\u0010<\u001a\b\u0012\u0004\u0012\u0002090\u0007H\u0002J\u0018\u0010A\u001a\u00020\'2\u0006\u00103\u001a\u00020\u00052\u0006\u00108\u001a\u000209H\u0002J\u0018\u0010B\u001a\u00020\u001d2\u0006\u00103\u001a\u00020\u00052\u0006\u00108\u001a\u000209H\u0002J(\u0010C\u001a\u0002012\b\u0010>\u001a\u0004\u0018\u00010\u00052\u0006\u0010D\u001a\u00020\'2\u0006\u0010E\u001a\u00020\'2\u0006\u0010F\u001a\u00020\'J\u0006\u0010G\u001a\u000201J\u0018\u0010H\u001a\u0002012\u0006\u0010>\u001a\u00020\u00052\u0006\u0010I\u001a\u00020\'H\u0002J(\u0010J\u001a\u0002012\b\u0010>\u001a\u0004\u0018\u00010\u00052\u000e\u0010K\u001a\n\u0012\u0004\u0012\u00020\u0005\u0018\u00010\u00072\u0006\u0010I\u001a\u00020\'J8\u0010L\u001a\u0002012\u0006\u0010M\u001a\u00020\u001e2\u000e\u0010K\u001a\n\u0012\u0004\u0012\u00020\u0005\u0018\u00010\u00072\u0006\u0010N\u001a\u00020\u001d2\u0006\u0010O\u001a\u00020\u001d2\u0006\u0010P\u001a\u00020\u001dH\u0002J\u0018\u0010Q\u001a\u0002012\u0006\u0010R\u001a\u00020\u00052\u0006\u0010I\u001a\u00020\'H\u0002J\u001e\u0010Q\u001a\u0002012\f\u0010S\u001a\b\u0012\u0004\u0012\u00020\u00050\u00072\u0006\u0010I\u001a\u00020\'H\u0002J\u000e\u0010T\u001a\u0002012\u0006\u0010U\u001a\u00020\u000bJ\u0016\u0010V\u001a\u0002012\u0006\u0010W\u001a\u00020X2\u0006\u0010>\u001a\u00020\u0005J\u0016\u0010Y\u001a\u0002012\u0006\u0010W\u001a\u00020X2\u0006\u0010>\u001a\u00020\u0005J\u0006\u0010Z\u001a\u00020\u001dJ\u0018\u0010[\u001a\u0002012\u0006\u0010W\u001a\u00020X2\u0006\u0010>\u001a\u00020\u0005H\u0002R\u0016\u0010\r\u001a\n \u000e*\u0004\u0018\u00010\u00050\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\u000f\u001a\n\u0012\u0004\u0012\u00020\u0011\u0018\u00010\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0016\u001a\u0004\u0018\u00010\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u001a\u001a\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u001d0\u001c\u0012\u0004\u0012\u00020\u001e0\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020!X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010$\u001a\b\u0012\u0004\u0012\u00020\u00050%X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\'X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010(\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020*0\u00070)\u00a2\u0006\b\n\u0000\u001a\u0004\b+\u0010,R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\n\u001a\u0004\u0018\u00010\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010-\u001a\b\u0012\u0004\u0012\u00020\u00050\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010.\u001a\n \u000e*\u0004\u0018\u00010/0/X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel;", "Landroidx/lifecycle/ViewModel;", "app", "Landroid/app/Application;", "packageName", "", "requestedPermissions", "", "sessionId", "", "storedState", "Landroid/os/Bundle;", "(Landroid/app/Application;Ljava/lang/String;Ljava/util/List;JLandroid/os/Bundle;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "activityResultCallback", "Landroidx/core/util/Consumer;", "Landroid/content/Intent;", "getActivityResultCallback", "()Landroidx/core/util/Consumer;", "setActivityResultCallback", "(Landroidx/core/util/Consumer;)V", "autoGrantNotifier", "Lcom/android/permissioncontroller/permission/ui/AutoGrantPermissionsNotifier;", "dpm", "Landroid/app/admin/DevicePolicyManager;", "groupStates", "", "Lkotlin/Pair;", "", "Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$GroupState;", "isFirstTimeRequestingFineAndCoarse", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "packageInfoLiveData", "Lcom/android/permissioncontroller/permission/data/LightPackageInfoLiveData;", "permGroupsToSkip", "", "permissionPolicy", "", "requestInfosLiveData", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$RequestInfo;", "getRequestInfosLiveData", "()Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "unfilteredAffectedPermissions", "user", "Landroid/os/UserHandle;", "autoGrantNotify", "", "computeAffectedPermissions", "perm", "appPermissions", "", "getAutoGrantNotifier", "getGroupState", "group", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "groupRequestedPermissions", "getGroupWithPerm", "groups", "getInstanceStateKey", "groupName", "isBackground", "getRequiredGroupStates", "getStateFromPolicy", "isPermissionGrantableAndNotFixed", "logClickedButtons", "selectedPrecision", "clickedButton", "presentedButtons", "logRequestedPermissionGroups", "logSettingsInteraction", "result", "onPermissionGrantResult", "affectedForegroundPermissions", "onPermissionGrantResultSingleState", "groupState", "granted", "isOneTime", "doNotAskAgain", "reportRequestResult", "permission", "permissions", "saveInstanceState", "outState", "sendDirectlyToSettings", "activity", "Landroid/app/Activity;", "sendToSettingsFromLink", "shouldReturnPermissionState", "startAppPermissionFragment", "Companion", "GroupState", "RequestInfo"})
public final class GrantPermissionsViewModel extends androidx.lifecycle.ViewModel {
    private final java.lang.String LOG_TAG = null;
    private final android.os.UserHandle user = null;
    private final com.android.permissioncontroller.permission.data.LightPackageInfoLiveData packageInfoLiveData = null;
    private final android.app.admin.DevicePolicyManager dpm = null;
    private final int permissionPolicy = 0;
    private final java.util.List<java.lang.String> permGroupsToSkip = null;
    private java.util.Map<kotlin.Pair<java.lang.String, java.lang.Boolean>, com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.GroupState> groupStates;
    private boolean isFirstTimeRequestingFineAndCoarse = false;
    private com.android.permissioncontroller.permission.ui.AutoGrantPermissionsNotifier autoGrantNotifier;
    private com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo;
    private java.util.List<java.lang.String> unfilteredAffectedPermissions;
    @org.jetbrains.annotations.Nullable()
    private androidx.core.util.Consumer<android.content.Intent> activityResultCallback;
    
    /**
     * A LiveData which holds a list of the currently pending RequestInfos
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.List<com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.RequestInfo>> requestInfosLiveData = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final java.util.List<java.lang.String> requestedPermissions = null;
    private final long sessionId = 0L;
    private final android.os.Bundle storedState = null;
    private static final int APP_PERMISSION_REQUEST_CODE = 1;
    private static final int STATE_UNKNOWN = 0;
    private static final int STATE_ALLOWED = 1;
    private static final int STATE_DENIED = 2;
    private static final int STATE_SKIPPED = 3;
    private static final int STATE_ALREADY_ALLOWED = 4;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion Companion = null;
    
    private final com.android.permissioncontroller.permission.ui.AutoGrantPermissionsNotifier getAutoGrantNotifier() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final androidx.core.util.Consumer<android.content.Intent> getActivityResultCallback() {
        return null;
    }
    
    public final void setActivityResultCallback(@org.jetbrains.annotations.Nullable()
    androidx.core.util.Consumer<android.content.Intent> p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.List<com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.RequestInfo>> getRequestInfosLiveData() {
        return null;
    }
    
    /**
     * Converts a list of LightAppPermGroups into a list of GroupStates
     */
    private final java.util.Map<kotlin.Pair<java.lang.String, java.lang.Boolean>, com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.GroupState> getRequiredGroupStates(java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> groups) {
        return null;
    }
    
    /**
     * Get the actually requested permissions when a permission is requested.
     *
     * >In some cases requesting to grant a single permission requires the system to grant
     * additional permissions. E.g. before N-MR1 a single permission of a group caused the whole
     * group to be granted. Another case are permissions that are split into two. For apps that
     * target an SDK before the split, this method automatically adds the split off permission.
     *
     * @param perm The requested permission
     *
     * @return The actually requested permissions
     */
    private final java.util.List<java.lang.String> computeAffectedPermissions(java.lang.String perm, java.util.Map<java.lang.String, ? extends java.util.List<java.lang.String>> appPermissions) {
        return null;
    }
    
    private final boolean isPermissionGrantableAndNotFixed(java.lang.String perm, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return false;
    }
    
    private final int getGroupState(java.lang.String perm, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, java.util.List<java.lang.String> groupRequestedPermissions) {
        return 0;
    }
    
    private final int getStateFromPolicy(java.lang.String perm, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return 0;
    }
    
    /**
     * Upon the user clicking a button, grant permissions, if applicable.
     *
     * @param groupName The name of the permission group which was changed
     * @param affectedForegroundPermissions The name of the foreground permission which was changed
     * @param result The choice the user made regarding the group.
     */
    public final void onPermissionGrantResult(@org.jetbrains.annotations.Nullable()
    java.lang.String groupName, @org.jetbrains.annotations.Nullable()
    java.util.List<java.lang.String> affectedForegroundPermissions, int result) {
    }
    
    private final void onPermissionGrantResultSingleState(com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.GroupState groupState, java.util.List<java.lang.String> affectedForegroundPermissions, boolean granted, boolean isOneTime, boolean doNotAskAgain) {
    }
    
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup getGroupWithPerm(java.lang.String perm, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup> groups) {
        return null;
    }
    
    private final void reportRequestResult(java.util.List<java.lang.String> permissions, int result) {
    }
    
    /**
     * Report the result of a grant of a permission.
     *
     * @param permission The permission that was granted or denied
     * @param result The permission grant result
     */
    private final void reportRequestResult(java.lang.String permission, int result) {
    }
    
    /**
     * Save the group states of the view model, to allow for state restoration after lifecycle
     * events
     *
     * @param outState The bundle in which to store state
     */
    public final void saveInstanceState(@org.jetbrains.annotations.NotNull()
    android.os.Bundle outState) {
    }
    
    /**
     * Determine if the activity should return permission state to the caller
     *
     * @return Whether or not state should be returned. False only if the package is pre-M, true
     * otherwise.
     */
    public final boolean shouldReturnPermissionState() {
        return false;
    }
    
    /**
     * Send the user directly to the AppPermissionFragment. Used for R+ apps.
     *
     * @param activity The current activity
     * @param groupName The name of the permission group whose fragment should be opened
     */
    public final void sendDirectlyToSettings(@org.jetbrains.annotations.NotNull()
    android.app.Activity activity, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
    }
    
    /**
     * Send the user to the AppPermissionFragment from a link. Used for Q- apps
     *
     * @param activity The current activity
     * @param groupName The name of the permission group whose fragment should be opened
     */
    public final void sendToSettingsFromLink(@org.jetbrains.annotations.NotNull()
    android.app.Activity activity, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
    }
    
    private final void startAppPermissionFragment(android.app.Activity activity, java.lang.String groupName) {
    }
    
    private final java.lang.String getInstanceStateKey(java.lang.String groupName, boolean isBackground) {
        return null;
    }
    
    private final void logSettingsInteraction(java.lang.String groupName, int result) {
    }
    
    /**
     * Log all permission groups which were requested
     */
    public final void logRequestedPermissionGroups() {
    }
    
    /**
     * Log information about the buttons which were shown and clicked by the user.
     *
     * @param groupName The name of the permission group which was interacted with
     * @param selectedPrecision Selected precision of the location permission - bit flags indicate
     *                         which locations were chosen
     * @param clickedButton The button that was clicked by the user
     * @param presentedButtons All buttons which were shown to the user
     */
    public final void logClickedButtons(@org.jetbrains.annotations.Nullable()
    java.lang.String groupName, int selectedPrecision, int clickedButton, int presentedButtons) {
    }
    
    /**
     * Use the autoGrantNotifier to notify of auto-granted permissions.
     */
    public final void autoGrantNotify() {
    }
    
    public GrantPermissionsViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> requestedPermissions, long sessionId, @org.jetbrains.annotations.Nullable()
    android.os.Bundle storedState) {
        super();
    }
    
    /**
     * A class which represents a correctly requested permission group, and the buttons and messages
     * which should be shown with it.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u000e\n\u0002\b\u0010\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001BK\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u000e\b\u0002\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\u000e\b\u0002\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\t\u0012\b\b\u0002\u0010\u000b\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\fJ\t\u0010\u001b\u001a\u00020\u0003H\u00c6\u0003J\u000f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005H\u00c6\u0003J\u000f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005H\u00c6\u0003J\t\u0010\u001e\u001a\u00020\tH\u00c6\u0003J\t\u0010\u001f\u001a\u00020\tH\u00c6\u0003J\t\u0010 \u001a\u00020\u0006H\u00c6\u0003JQ\u0010!\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\u000e\b\u0002\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u00052\u000e\b\u0002\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\u00052\b\b\u0002\u0010\b\u001a\u00020\t2\b\b\u0002\u0010\n\u001a\u00020\t2\b\b\u0002\u0010\u000b\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\"\u001a\u00020\u00062\b\u0010#\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010$\u001a\u00020%H\u00d6\u0001J\t\u0010&\u001a\u00020\u0014H\u00d6\u0001R\u0017\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\n\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u0011\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u0017\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u000eR\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0010R\u0011\u0010\u000b\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001a"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$RequestInfo;", "", "groupInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "buttonVisibilities", "", "", "locationVisibilities", "message", "Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion$RequestMessage;", "detailMessage", "sendToSettingsImmediately", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;Ljava/util/List;Ljava/util/List;Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion$RequestMessage;Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion$RequestMessage;Z)V", "getButtonVisibilities", "()Ljava/util/List;", "getDetailMessage", "()Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion$RequestMessage;", "getGroupInfo", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermGroupInfo;", "groupName", "", "getGroupName", "()Ljava/lang/String;", "getLocationVisibilities", "getMessage", "getSendToSettingsImmediately", "()Z", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "equals", "other", "hashCode", "", "toString"})
    public static final class RequestInfo {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String groupName = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.Boolean> buttonVisibilities = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.Boolean> locationVisibilities = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage message;
        @org.jetbrains.annotations.NotNull()
        private final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage detailMessage;
        private final boolean sendToSettingsImmediately = false;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getGroupName() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo getGroupInfo() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.Boolean> getButtonVisibilities() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.Boolean> getLocationVisibilities() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage getMessage() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage getDetailMessage() {
            return null;
        }
        
        public final boolean getSendToSettingsImmediately() {
            return false;
        }
        
        public RequestInfo(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.Boolean> buttonVisibilities, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.Boolean> locationVisibilities, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage message, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage detailMessage, boolean sendToSettingsImmediately) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.Boolean> component2() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.Boolean> component3() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage component4() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage component5() {
            return null;
        }
        
        public final boolean component6() {
            return false;
        }
        
        /**
         * A class which represents a correctly requested permission group, and the buttons and messages
         * which should be shown with it.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.RequestInfo copy(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightPermGroupInfo groupInfo, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.Boolean> buttonVisibilities, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.Boolean> locationVisibilities, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage message, @org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.GrantPermissionsViewModel.Companion.RequestMessage detailMessage, boolean sendToSettingsImmediately) {
            return null;
        }
        
        /**
         * A class which represents a correctly requested permission group, and the buttons and messages
         * which should be shown with it.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * A class which represents a correctly requested permission group, and the buttons and messages
         * which should be shown with it.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * A class which represents a correctly requested permission group, and the buttons and messages
         * which should be shown with it.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * An internal class which represents the state of a current AppPermissionGroup grant request.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010!\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\f\b\u0000\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u000e\b\u0002\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\b\b\u0002\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\b\u0010\u0016\u001a\u00020\bH\u0016R\u001a\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0080\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0014\u0010\u0002\u001a\u00020\u0003X\u0080\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0014\u0010\u0004\u001a\u00020\u0005X\u0080\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u001a\u0010\t\u001a\u00020\nX\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$GroupState;", "", "group", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "isBackground", "", "affectedPermissions", "", "", "state", "", "(Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;ZLjava/util/List;I)V", "getAffectedPermissions$main", "()Ljava/util/List;", "getGroup$main", "()Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "isBackground$main", "()Z", "getState$main", "()I", "setState$main", "(I)V", "toString"})
    public static final class GroupState {
        @org.jetbrains.annotations.NotNull()
        private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group = null;
        private final boolean isBackground = false;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.String> affectedPermissions = null;
        private int state;
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup getGroup$main() {
            return null;
        }
        
        public final boolean isBackground$main() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.String> getAffectedPermissions$main() {
            return null;
        }
        
        public final int getState$main() {
            return 0;
        }
        
        public final void setState$main(int p0) {
        }
        
        public GroupState(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean isBackground, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> affectedPermissions, int state) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002\u00020\u0001:\u0001\nB\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion;", "", "()V", "APP_PERMISSION_REQUEST_CODE", "", "STATE_ALLOWED", "STATE_ALREADY_ALLOWED", "STATE_DENIED", "STATE_SKIPPED", "STATE_UNKNOWN", "RequestMessage"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * An enum that represents the type of message which should be shown- foreground,
         * background, upgrade, or no message.
         */
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\u0007\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004j\u0002\b\u0005j\u0002\b\u0006j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\n"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/GrantPermissionsViewModel$Companion$RequestMessage;", "", "request", "", "(Ljava/lang/String;II)V", "FG_MESSAGE", "BG_MESSAGE", "UPGRADE_MESSAGE", "NO_MESSAGE", "FG_FINE_LOCATION_MESSAGE", "FG_COARSE_LOCATION_MESSAGE"})
        public static enum RequestMessage {
            /*public static final*/ FG_MESSAGE /* = new FG_MESSAGE(0) */,
            /*public static final*/ BG_MESSAGE /* = new BG_MESSAGE(0) */,
            /*public static final*/ UPGRADE_MESSAGE /* = new UPGRADE_MESSAGE(0) */,
            /*public static final*/ NO_MESSAGE /* = new NO_MESSAGE(0) */,
            /*public static final*/ FG_FINE_LOCATION_MESSAGE /* = new FG_FINE_LOCATION_MESSAGE(0) */,
            /*public static final*/ FG_COARSE_LOCATION_MESSAGE /* = new FG_COARSE_LOCATION_MESSAGE(0) */;
            
            RequestMessage(int request) {
            }
        }
    }
}