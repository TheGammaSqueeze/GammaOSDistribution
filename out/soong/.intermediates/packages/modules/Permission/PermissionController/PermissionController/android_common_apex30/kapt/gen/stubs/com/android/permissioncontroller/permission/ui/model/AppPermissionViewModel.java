package com.android.permissioncontroller.permission.ui.model;

import android.Manifest;
import android.app.AppOpsManager;
import android.app.Application;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.UserHandle;
import android.util.Log;
import androidx.annotation.StringRes;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.PermissionControllerStatsLog;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData;
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState;
import com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermission;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.LocationUtils;
import com.android.permissioncontroller.permission.utils.SafetyNetLogger;
import com.android.permissioncontroller.permission.utils.Utils;
import com.android.settingslib.RestrictedLockUtils;
import java.util.Random;

/**
 * ViewModel for the AppPermissionFragment. Determines button state and detail text strings, logs
 * permission change information, and makes permission changes.
 *
 * @param app The current application
 * @param packageName The name of the package this ViewModel represents
 * @param permGroupName The name of the permission group this ViewModel represents
 * @param user The user of the package
 * @param sessionId A session ID used in logs to identify this particular session
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009c\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0011\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0007\u0018\u0000 U2\u00020\u0001:\u0005RSTUVB-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJH\u0010\'\u001a\u00020\u001e2\u0006\u0010(\u001a\u00020!2\u0006\u0010)\u001a\u00020\u001e2\u0006\u0010*\u001a\u00020\u001e2\u0006\u0010+\u001a\u00020\u00102\u0006\u0010,\u001a\u00020\u00102\u0006\u0010-\u001a\u00020\u00102\u0006\u0010.\u001a\u00020\u00102\u0006\u0010/\u001a\u00020\u0010H\u0002J\u0018\u00100\u001a\u00020\u00172\u0006\u0010(\u001a\u00020!2\u0006\u00101\u001a\u00020\u001eH\u0002J\u001c\u00102\u001a\u000e\u0012\u0004\u0012\u00020\u0017\u0012\u0004\u0012\u00020\u00170\u00162\u0006\u0010(\u001a\u00020!H\u0002J\u0010\u00103\u001a\u00020\u001e2\u0006\u0010(\u001a\u00020!H\u0002J\u0010\u00104\u001a\u00020\u001e2\u0006\u00105\u001a\u00020\u0005H\u0002J \u00106\u001a\u0002072\u0006\u00108\u001a\u00020\n2\u0006\u00109\u001a\u00020:2\u0006\u0010;\u001a\u00020\u0017H\u0002J\u0006\u0010<\u001a\u000207J \u0010=\u001a\u0002072\u0006\u0010>\u001a\u00020!2\u0006\u0010?\u001a\u00020!2\u0006\u0010;\u001a\u00020\u0017H\u0002J\u001e\u0010@\u001a\u0002072\u0006\u0010A\u001a\u00020B2\u0006\u0010;\u001a\u00020\u00172\u0006\u0010C\u001a\u00020\u001eJ.\u0010D\u001a\u0002072\u0006\u0010E\u001a\u00020\u001e2\u0006\u0010F\u001a\u00020G2\u0006\u0010H\u001a\u00020I2\u0006\u0010A\u001a\u00020B2\u0006\u0010J\u001a\u00020\u0017J\u000e\u0010K\u001a\u0002072\u0006\u0010L\u001a\u00020\u001eJ\u0016\u0010M\u001a\u0002072\u0006\u0010F\u001a\u00020G2\u0006\u0010N\u001a\u00020OJ\u001e\u0010P\u001a\u0002072\u0006\u0010F\u001a\u00020G2\u0006\u0010Q\u001a\u00020\u00052\u0006\u0010N\u001a\u00020OR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R(\u0010\f\u001a\u0019\u0012\u0015\u0012\u0013\u0012\u0004\u0012\u00020\u000f\u0012\u0004\u0012\u00020\u00100\u000e\u00a2\u0006\u0002\b\u00110\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R%\u0010\u0014\u001a\u0016\u0012\u0012\u0012\u0010\u0012\u0004\u0012\u00020\u0017\u0012\u0006\u0012\u0004\u0018\u00010\u00170\u00160\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u0017\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u001b0\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u0013R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010 \u001a\u0004\u0018\u00010!X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\"\u001a\u0004\u0018\u00010\u001eX\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010#R\u0017\u0010$\u001a\b\u0012\u0004\u0012\u00020%0\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u0019R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel;", "Landroidx/lifecycle/ViewModel;", "app", "Landroid/app/Application;", "packageName", "", "permGroupName", "user", "Landroid/os/UserHandle;", "sessionId", "", "(Landroid/app/Application;Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;J)V", "buttonStateLiveData", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ButtonType;", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ButtonState;", "Lkotlin/jvm/JvmSuppressWildcards;", "getButtonStateLiveData", "()Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "detailResIdLiveData", "Landroidx/lifecycle/MutableLiveData;", "Lkotlin/Pair;", "", "getDetailResIdLiveData", "()Landroidx/lifecycle/MutableLiveData;", "fullStorageStateLiveData", "Lcom/android/permissioncontroller/permission/data/FullStoragePermissionAppsLiveData$FullStoragePackageState;", "getFullStorageStateLiveData", "hasConfirmedRevoke", "", "isStorage", "lightAppPermGroup", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "shouldShowLocationAccuracy", "Ljava/lang/Boolean;", "showAdminSupportLiveData", "Lcom/android/settingslib/RestrictedLockUtils$EnforcedAdmin;", "getShowAdminSupportLiveData", "applyFixToForegroundBackground", "group", "isForegroundFixed", "isBackgroundFixed", "allowedAlwaysState", "allowedForegroundState", "askState", "deniedState", "deniedForegroundState", "getDetailResIdForFixedByPolicyPermissionGroup", "hasAdmin", "getIndividualPermissionDetailResId", "isFineLocationChecked", "isForegroundGroupSpecialCase", "permissionGroupName", "logAppPermissionFragmentActionReported", "", "changeId", "permission", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "buttonPressed", "logAppPermissionFragmentViewed", "logPermissionChanges", "oldGroup", "newGroup", "onDenyAnyWay", "changeRequest", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;", "oneTime", "requestChange", "setOneTime", "fragment", "Landroidx/fragment/app/Fragment;", "defaultDeny", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ConfirmDialogShowingFragment;", "buttonClicked", "setAllFilesAccess", "granted", "showAllPermissions", "args", "Landroid/os/Bundle;", "showBottomLinkPage", "action", "ButtonState", "ButtonType", "ChangeRequest", "Companion", "ConfirmDialogShowingFragment"})
public final class AppPermissionViewModel extends androidx.lifecycle.ViewModel {
    private final boolean isStorage = false;
    private boolean hasConfirmedRevoke = false;
    private com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup lightAppPermGroup;
    private java.lang.Boolean shouldShowLocationAccuracy;
    
    /**
     * A livedata which determines which detail string, if any, should be shown
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.MutableLiveData<kotlin.Pair<java.lang.Integer, java.lang.Integer>> detailResIdLiveData = null;
    
    /**
     * A livedata which stores the device admin, if there is one
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.MutableLiveData<com.android.settingslib.RestrictedLockUtils.EnforcedAdmin> showAdminSupportLiveData = null;
    
    /**
     * A livedata which determines which detail string, if any, should be shown
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState> fullStorageStateLiveData = null;
    
    /**
     * A livedata which computes the state of the radio buttons
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState>> buttonStateLiveData = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final java.lang.String permGroupName = null;
    private final android.os.UserHandle user = null;
    private final long sessionId = 0L;
    private static final java.lang.String LOG_TAG = null;
    private static final java.lang.String DEVICE_PROFILE_ROLE_PREFIX = "android.app.role";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<kotlin.Pair<java.lang.Integer, java.lang.Integer>> getDetailResIdLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<com.android.settingslib.RestrictedLockUtils.EnforcedAdmin> getShowAdminSupportLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState> getFullStorageStateLiveData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState>> getButtonStateLiveData() {
        return null;
    }
    
    private final boolean isFineLocationChecked(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return false;
    }
    
    private final boolean isForegroundGroupSpecialCase(java.lang.String permissionGroupName) {
        return false;
    }
    
    /**
     * Modifies the radio buttons to reflect the current policy fixing state
     *
     * @return if anything was changed
     */
    private final boolean applyFixToForegroundBackground(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean isForegroundFixed, boolean isBackgroundFixed, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState allowedAlwaysState, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState allowedForegroundState, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState askState, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState deniedState, com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState deniedForegroundState) {
        return false;
    }
    
    /**
     * Navigate to either the App Permission Groups screen, or the Permission Apps Screen.
     * @param fragment The current fragment
     * @param action The action to be taken
     * @param args The arguments to pass to the fragment
     */
    public final void showBottomLinkPage(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    java.lang.String action, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    /**
     * Request to grant/revoke permissions group.
     *
     * Does <u>not</u> handle:
     *
     * * Individually granted permissions
     * * Permission groups with background permissions
     *
     * <u>Does</u> handle:
     *
     * * Default grant permissions
     *
     * @param setOneTime Whether or not to set this permission as one time
     * @param fragment The fragment calling this method
     * @param defaultDeny The system which will show the default deny dialog. Usually the same as
     * the fragment.
     * @param changeRequest Which permission group (foreground/background/both) should be changed
     * @param buttonClicked button which was pressed to initiate the change, one of
     *                     AppPermissionFragmentActionReported.button_pressed constants
     *
     * @return The dialogue to show, if applicable, or if the request was processed.
     */
    public final void requestChange(boolean setOneTime, @org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ConfirmDialogShowingFragment defaultDeny, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest changeRequest, int buttonClicked) {
    }
    
    /**
     * Once the user has confirmed that he/she wants to revoke a permission that was granted by
     * default, actually revoke the permissions.
     *
     * @param changeRequest whether to change foreground, background, or both.
     * @param buttonPressed button pressed to initiate the change, one of
     *                     AppPermissionFragmentActionReported.button_pressed constants
     * @param oneTime whether the change should show that the permission was selected as one-time
     */
    public final void onDenyAnyWay(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest changeRequest, int buttonPressed, boolean oneTime) {
    }
    
    /**
     * Set the All Files access for this app
     *
     * @param granted Whether to grant or revoke access
     */
    public final void setAllFilesAccess(boolean granted) {
    }
    
    /**
     * Show the All App Permissions screen with the proper filter group, package name, and user.
     *
     * @param fragment The current fragment we wish to transition from
     */
    public final void showAllPermissions(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    private final kotlin.Pair<java.lang.Integer, java.lang.Integer> getIndividualPermissionDetailResId(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    /**
     * Get the detail string id of a permission group if it is at least partially fixed by policy.
     */
    private final int getDetailResIdForFixedByPolicyPermissionGroup(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean hasAdmin) {
        return 0;
    }
    
    private final void logPermissionChanges(com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup oldGroup, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup newGroup, int buttonPressed) {
    }
    
    private final void logAppPermissionFragmentActionReported(long changeId, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission permission, int buttonPressed) {
    }
    
    /**
     * Logs information about this AppPermissionGroup and view session
     */
    public final void logAppPermissionFragmentViewed() {
    }
    
    public AppPermissionViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    java.lang.String permGroupName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long sessionId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J*\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\b\u0001\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u00072\u0006\u0010\t\u001a\u00020\nH&"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ConfirmDialogShowingFragment;", "", "showConfirmDialog", "", "changeRequest", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;", "messageId", "", "buttonPressed", "oneTime", ""})
    public static abstract interface ConfirmDialogShowingFragment {
        
        public abstract void showConfirmDialog(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest changeRequest, @androidx.annotation.StringRes()
        int messageId, int buttonPressed, boolean oneTime);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\u000f\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0011\u0010\u0007\u001a\u00020\u00032\u0006\u0010\b\u001a\u00020\u0000H\u0086\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006j\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000ej\u0002\b\u000fj\u0002\b\u0010j\u0002\b\u0011j\u0002\b\u0012"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;", "", "value", "", "(Ljava/lang/String;II)V", "getValue", "()I", "andValue", "other", "GRANT_FOREGROUND", "REVOKE_FOREGROUND", "GRANT_BACKGROUND", "REVOKE_BACKGROUND", "GRANT_BOTH", "REVOKE_BOTH", "GRANT_FOREGROUND_ONLY", "GRANT_All_FILE_ACCESS", "GRANT_FINE_LOCATION", "REVOKE_FINE_LOCATION"})
    public static enum ChangeRequest {
        /*public static final*/ GRANT_FOREGROUND /* = new GRANT_FOREGROUND(0) */,
        /*public static final*/ REVOKE_FOREGROUND /* = new REVOKE_FOREGROUND(0) */,
        /*public static final*/ GRANT_BACKGROUND /* = new GRANT_BACKGROUND(0) */,
        /*public static final*/ REVOKE_BACKGROUND /* = new REVOKE_BACKGROUND(0) */,
        /*public static final*/ GRANT_BOTH /* = new GRANT_BOTH(0) */,
        /*public static final*/ REVOKE_BOTH /* = new REVOKE_BOTH(0) */,
        /*public static final*/ GRANT_FOREGROUND_ONLY /* = new GRANT_FOREGROUND_ONLY(0) */,
        /*public static final*/ GRANT_All_FILE_ACCESS /* = new GRANT_All_FILE_ACCESS(0) */,
        /*public static final*/ GRANT_FINE_LOCATION /* = new GRANT_FINE_LOCATION(0) */,
        /*public static final*/ REVOKE_FINE_LOCATION /* = new REVOKE_FINE_LOCATION(0) */;
        private final int value = 0;
        
        public final int andValue(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest other) {
            return 0;
        }
        
        public final int getValue() {
            return 0;
        }
        
        ChangeRequest(int value) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\u000b\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000e"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ButtonType;", "", "type", "", "(Ljava/lang/String;II)V", "getType", "()I", "ALLOW", "ALLOW_ALWAYS", "ALLOW_FOREGROUND", "ASK_ONCE", "ASK", "DENY", "DENY_FOREGROUND", "LOCATION_ACCURACY"})
    public static enum ButtonType {
        /*public static final*/ ALLOW /* = new ALLOW(0) */,
        /*public static final*/ ALLOW_ALWAYS /* = new ALLOW_ALWAYS(0) */,
        /*public static final*/ ALLOW_FOREGROUND /* = new ALLOW_FOREGROUND(0) */,
        /*public static final*/ ASK_ONCE /* = new ASK_ONCE(0) */,
        /*public static final*/ ASK /* = new ASK(0) */,
        /*public static final*/ DENY /* = new DENY(0) */,
        /*public static final*/ DENY_FOREGROUND /* = new DENY_FOREGROUND(0) */,
        /*public static final*/ LOCATION_ACCURACY /* = new LOCATION_ACCURACY(0) */;
        private final int type = 0;
        
        public final int getType() {
            return 0;
        }
        
        ButtonType(int type) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0012\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0007\b\u0016\u00a2\u0006\u0002\u0010\u0002B\'\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0004\u0012\b\u0010\u0007\u001a\u0004\u0018\u00010\b\u00a2\u0006\u0002\u0010\tJ\t\u0010\u0013\u001a\u00020\u0004H\u00c6\u0003J\t\u0010\u0014\u001a\u00020\u0004H\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0004H\u00c6\u0003J\u000b\u0010\u0016\u001a\u0004\u0018\u00010\bH\u00c6\u0003J3\u0010\u0017\u001a\u00020\u00002\b\b\u0002\u0010\u0003\u001a\u00020\u00042\b\b\u0002\u0010\u0005\u001a\u00020\u00042\b\b\u0002\u0010\u0006\u001a\u00020\u00042\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\bH\u00c6\u0001J\u0013\u0010\u0018\u001a\u00020\u00042\b\u0010\u0019\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001a\u001a\u00020\u001bH\u00d6\u0001J\t\u0010\u001c\u001a\u00020\u001dH\u00d6\u0001R\u001c\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0003\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001a\u0010\u0005\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u000e\"\u0004\b\u0011\u0010\u0010R\u001a\u0010\u0006\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0006\u0010\u000e\"\u0004\b\u0012\u0010\u0010"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ButtonState;", "", "()V", "isChecked", "", "isEnabled", "isShown", "customRequest", "Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;", "(ZZZLcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;)V", "getCustomRequest", "()Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;", "setCustomRequest", "(Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$ChangeRequest;)V", "()Z", "setChecked", "(Z)V", "setEnabled", "setShown", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString", ""})
    public static final class ButtonState {
        private boolean isChecked;
        private boolean isEnabled;
        private boolean isShown;
        @org.jetbrains.annotations.Nullable()
        private com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest customRequest;
        
        public final boolean isChecked() {
            return false;
        }
        
        public final void setChecked(boolean p0) {
        }
        
        public final boolean isEnabled() {
            return false;
        }
        
        public final void setEnabled(boolean p0) {
        }
        
        public final boolean isShown() {
            return false;
        }
        
        public final void setShown(boolean p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest getCustomRequest() {
            return null;
        }
        
        public final void setCustomRequest(@org.jetbrains.annotations.Nullable()
        com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest p0) {
        }
        
        public ButtonState(boolean isChecked, boolean isEnabled, boolean isShown, @org.jetbrains.annotations.Nullable()
        com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest customRequest) {
            super();
        }
        
        public ButtonState() {
            super();
        }
        
        public final boolean component1() {
            return false;
        }
        
        public final boolean component2() {
            return false;
        }
        
        public final boolean component3() {
            return false;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest component4() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonState copy(boolean isChecked, boolean isEnabled, boolean isShown, @org.jetbrains.annotations.Nullable()
        com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ChangeRequest customRequest) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0005\u001a\n \u0006*\u0004\u0018\u00010\u00040\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AppPermissionViewModel$Companion;", "", "()V", "DEVICE_PROFILE_ROLE_PREFIX", "", "LOG_TAG", "kotlin.jvm.PlatformType"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}