/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.permissioncontroller.permission.ui.model

import android.Manifest
import android.Manifest.permission.ACCESS_COARSE_LOCATION
import android.app.AppOpsManager
import android.app.AppOpsManager.MODE_ALLOWED
import android.app.AppOpsManager.MODE_ERRORED
import android.app.AppOpsManager.OPSTR_MANAGE_EXTERNAL_STORAGE
import android.app.Application
import android.content.Intent
import android.Manifest.permission_group.LOCATION
import android.Manifest.permission.ACCESS_FINE_LOCATION
import android.os.Build
import android.os.Bundle
import android.os.UserHandle
import android.util.Log
import androidx.annotation.StringRes
import androidx.fragment.app.Fragment
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.fragment.findNavController
import com.android.permissioncontroller.PermissionControllerStatsLog
import com.android.permissioncontroller.PermissionControllerStatsLog.APP_PERMISSION_FRAGMENT_ACTION_REPORTED
import com.android.permissioncontroller.PermissionControllerStatsLog.APP_PERMISSION_FRAGMENT_VIEWED
import com.android.permissioncontroller.R
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData
import com.android.permissioncontroller.permission.data.FullStoragePermissionAppsLiveData.FullStoragePackageState
import com.android.permissioncontroller.permission.data.LightAppPermGroupLiveData
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData
import com.android.permissioncontroller.permission.data.get

import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermission
import com.android.permissioncontroller.permission.utils.KotlinUtils
import com.android.permissioncontroller.permission.utils.LocationUtils
import com.android.permissioncontroller.permission.utils.SafetyNetLogger
import com.android.permissioncontroller.permission.ui.handheld.dashboard.getDefaultPrecision
import com.android.permissioncontroller.permission.ui.handheld.dashboard.isLocationAccuracyEnabled
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.ALLOW
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.ALLOW_ALWAYS
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.ALLOW_FOREGROUND
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.ASK_ONCE
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.ASK
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.DENY
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.DENY_FOREGROUND
import com.android.permissioncontroller.permission.ui.model.AppPermissionViewModel.ButtonType.LOCATION_ACCURACY
import com.android.permissioncontroller.permission.utils.Utils
import com.android.permissioncontroller.permission.utils.navigateSafe
import com.android.settingslib.RestrictedLockUtils
import java.util.Random
import kotlin.collections.component1
import kotlin.collections.component2
import kotlin.collections.filter
import kotlin.collections.iterator

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
class AppPermissionViewModel(
    private val app: Application,
    private val packageName: String,
    private val permGroupName: String,
    private val user: UserHandle,
    private val sessionId: Long
) : ViewModel() {

    companion object {
        private val LOG_TAG = AppPermissionViewModel::class.java.simpleName

        private const val DEVICE_PROFILE_ROLE_PREFIX = "android.app.role"
    }

    interface ConfirmDialogShowingFragment {
        fun showConfirmDialog(
            changeRequest: ChangeRequest,
            @StringRes messageId: Int,
            buttonPressed: Int,
            oneTime: Boolean
        )
    }

    enum class ChangeRequest(val value: Int) {
        GRANT_FOREGROUND(1),
        REVOKE_FOREGROUND(2),
        GRANT_BACKGROUND(4),
        REVOKE_BACKGROUND(8),
        GRANT_BOTH(GRANT_FOREGROUND.value or GRANT_BACKGROUND.value),
        REVOKE_BOTH(REVOKE_FOREGROUND.value or REVOKE_BACKGROUND.value),
        GRANT_FOREGROUND_ONLY(GRANT_FOREGROUND.value or REVOKE_BACKGROUND.value),
        GRANT_All_FILE_ACCESS(16),
        GRANT_FINE_LOCATION(32),
        REVOKE_FINE_LOCATION(64);

        infix fun andValue(other: ChangeRequest): Int {
            return value and other.value
        }
    }

    enum class ButtonType(val type: Int) {
        ALLOW(0),
        ALLOW_ALWAYS(1),
        ALLOW_FOREGROUND(2),
        ASK_ONCE(3),
        ASK(4),
        DENY(5),
        DENY_FOREGROUND(6),
        LOCATION_ACCURACY(7);
    }

    private val isStorage = permGroupName == Manifest.permission_group.STORAGE
    private var hasConfirmedRevoke = false
    private var lightAppPermGroup: LightAppPermGroup? = null

    /* Whether the current ViewModel is Location permission with both Coarse and Fine */
    private var shouldShowLocationAccuracy: Boolean? = null

    /**
     * A livedata which determines which detail string, if any, should be shown
     */
    val detailResIdLiveData = MutableLiveData<Pair<Int, Int?>>()
    /**
     * A livedata which stores the device admin, if there is one
     */
    val showAdminSupportLiveData = MutableLiveData<RestrictedLockUtils.EnforcedAdmin>()

    /**
     * A livedata which determines which detail string, if any, should be shown
     */
    val fullStorageStateLiveData = object : SmartUpdateMediatorLiveData<FullStoragePackageState>() {
        init {
            if (isStorage) {
                addSource(FullStoragePermissionAppsLiveData) {
                    update()
                }
            } else {
                value = null
            }
        }
        override fun onUpdate() {
            for (state in FullStoragePermissionAppsLiveData.value ?: return) {
                if (state.packageName == packageName && state.user == user) {
                    value = state
                    return
                }
            }
            value = null
            return
        }
    }

    data class ButtonState(
        var isChecked: Boolean,
        var isEnabled: Boolean,
        var isShown: Boolean,
        var customRequest: ChangeRequest?
    ) {
        constructor() : this(false, true, false, null)
    }

    /**
     * A livedata which computes the state of the radio buttons
     */
    val buttonStateLiveData = object
        : SmartUpdateMediatorLiveData<@JvmSuppressWildcards Map<ButtonType, ButtonState>>() {

        private val appPermGroupLiveData = LightAppPermGroupLiveData[packageName, permGroupName,
            user]

        init {
            addSource(appPermGroupLiveData) { appPermGroup ->
                lightAppPermGroup = appPermGroup
                if (appPermGroupLiveData.isInitialized && appPermGroup == null) {
                    value = null
                } else if (appPermGroup != null) {
                    if (isStorage && !fullStorageStateLiveData.isInitialized) {
                        return@addSource
                    }
                    if (value == null) {
                        logAppPermissionFragmentViewed()
                    }
                    update()
                }
            }

            if (isStorage) {
                addSource(fullStorageStateLiveData) {
                    update()
                }
            }
        }

        override fun onUpdate() {
            val group = appPermGroupLiveData.value ?: return

            val admin = RestrictedLockUtils.getProfileOrDeviceOwner(app, user)

            val allowedState = ButtonState()
            val allowedAlwaysState = ButtonState()
            val allowedForegroundState = ButtonState()
            val askOneTimeState = ButtonState()
            val askState = ButtonState()
            val deniedState = ButtonState()
            val deniedForegroundState = ButtonState()

            askOneTimeState.isShown = group.foreground.isGranted && group.isOneTime
            askState.isShown = Utils.supportsOneTimeGrant(permGroupName) &&
                    !(group.foreground.isGranted && group.isOneTime)
            deniedState.isShown = true

            if (group.hasPermWithBackgroundMode) {
                // Background / Foreground / Deny case
                allowedForegroundState.isShown = true
                if (group.hasBackgroundGroup) {
                    allowedAlwaysState.isShown = true
                }

                allowedAlwaysState.isChecked = group.background.isGranted &&
                    group.foreground.isGranted
                allowedForegroundState.isChecked = group.foreground.isGranted &&
                    !group.background.isGranted && !group.isOneTime
                askState.isChecked = !group.foreground.isGranted && group.isOneTime
                askOneTimeState.isChecked = group.foreground.isGranted && group.isOneTime
                askOneTimeState.isShown = askOneTimeState.isChecked
                deniedState.isChecked = !group.foreground.isGranted && !group.isOneTime
                if (applyFixToForegroundBackground(group, group.foreground.isSystemFixed,
                        group.background.isSystemFixed, allowedAlwaysState,
                        allowedForegroundState, askState, deniedState,
                        deniedForegroundState) ||
                    applyFixToForegroundBackground(group, group.foreground.isPolicyFixed,
                        group.background.isPolicyFixed, allowedAlwaysState,
                        allowedForegroundState, askState, deniedState,
                        deniedForegroundState)) {
                    showAdminSupportLiveData.value = admin
                    val detailId = getDetailResIdForFixedByPolicyPermissionGroup(group,
                        admin != null)
                    if (detailId != 0) {
                        detailResIdLiveData.value = detailId to null
                    }
                } else if (Utils.areGroupPermissionsIndividuallyControlled(app, permGroupName)) {
                    val detailId = getIndividualPermissionDetailResId(group)
                    detailResIdLiveData.value = detailId.first to detailId.second
                }
            } else {
                // Allow / Deny case
                allowedState.isShown = true

                allowedState.isChecked = group.foreground.isGranted
                askState.isChecked = !group.foreground.isGranted && group.isOneTime
                askOneTimeState.isChecked = group.foreground.isGranted && group.isOneTime
                askOneTimeState.isShown = askOneTimeState.isChecked
                deniedState.isChecked = !group.foreground.isGranted && !group.isOneTime

                if (group.foreground.isPolicyFixed || group.foreground.isSystemFixed) {
                    allowedState.isEnabled = false
                    askState.isEnabled = false
                    deniedState.isEnabled = false
                    showAdminSupportLiveData.value = admin
                    val detailId = getDetailResIdForFixedByPolicyPermissionGroup(group,
                        admin != null)
                    if (detailId != 0) {
                        detailResIdLiveData.value = detailId to null
                    }
                }
                if (isForegroundGroupSpecialCase(permGroupName)) {
                    allowedForegroundState.isShown = true
                    allowedState.isShown = false
                    allowedForegroundState.isChecked = allowedState.isChecked
                    allowedForegroundState.isEnabled = allowedState.isEnabled
                }
            }
            if (group.packageInfo.targetSdkVersion < Build.VERSION_CODES.M) {
                // Pre-M app's can't ask for runtime permissions
                askState.isShown = false
                deniedState.isChecked = askState.isChecked || deniedState.isChecked
                deniedForegroundState.isChecked = askState.isChecked ||
                    deniedForegroundState.isChecked
            }

            val storageState = fullStorageStateLiveData.value
            if (isStorage && storageState?.isLegacy != true) {
                val allowedAllFilesState = allowedAlwaysState
                val allowedMediaOnlyState = allowedForegroundState
                if (storageState != null) {
                        // Set up the tri state permission for storage
                        allowedAllFilesState.isEnabled = allowedState.isEnabled
                        allowedAllFilesState.isShown = true
                        if (storageState.isGranted) {
                            allowedAllFilesState.isChecked = true
                            deniedState.isChecked = false
                        }
                } else {
                    allowedAllFilesState.isEnabled = false
                    allowedAllFilesState.isShown = false
                }
                allowedMediaOnlyState.isShown = true
                allowedMediaOnlyState.isEnabled = allowedState.isEnabled
                allowedMediaOnlyState.isChecked = allowedState.isChecked &&
                    storageState?.isGranted != true
                allowedState.isChecked = false
                allowedState.isShown = false
            }

            if (shouldShowLocationAccuracy == null) {
                shouldShowLocationAccuracy = group.permGroupName == LOCATION &&
                        group.permissions.containsKey(ACCESS_FINE_LOCATION) &&
                        isLocationAccuracyEnabled()
            }
            val locationAccuracyState = ButtonState(isFineLocationChecked(group),
                    true, false, null)
            if (shouldShowLocationAccuracy == true && !deniedState.isChecked) {
                locationAccuracyState.isShown = true
            }
            if (group.foreground.isSystemFixed || group.foreground.isPolicyFixed) {
                locationAccuracyState.isEnabled = false
            }

            value = mapOf(
                ALLOW to allowedState, ALLOW_ALWAYS to allowedAlwaysState,
                ALLOW_FOREGROUND to allowedForegroundState, ASK_ONCE to askOneTimeState,
                ASK to askState, DENY to deniedState, DENY_FOREGROUND to deniedForegroundState,
                LOCATION_ACCURACY to locationAccuracyState)
        }
    }

    private fun isFineLocationChecked(group: LightAppPermGroup): Boolean {
        if (shouldShowLocationAccuracy == true) {
            val coarseLocation = group.permissions[ACCESS_COARSE_LOCATION]!!
            val fineLocation = group.permissions[ACCESS_FINE_LOCATION]!!
            // Steps to decide location accuracy toggle state
            // 1. If none of the FINE and COARSE isSelectedLocationAccuracy flags is set,
            //    then use default precision from device config.
            // 2. Otherwise return if FINE isSelectedLocationAccuracy is set to true.
            return if ((!fineLocation.isSelectedLocationAccuracy &&
                            !coarseLocation.isSelectedLocationAccuracy)) {
                getDefaultPrecision()
            } else {
                fineLocation.isSelectedLocationAccuracy
            }
        }
        return false
    }

    // TODO evanseverson: Actually change mic/camera to be a foreground only permission
    private fun isForegroundGroupSpecialCase(permissionGroupName: String): Boolean {
        return permissionGroupName.equals(Manifest.permission_group.CAMERA) ||
                permissionGroupName.equals(Manifest.permission_group.MICROPHONE)
    }

    /**
     * Modifies the radio buttons to reflect the current policy fixing state
     *
     * @return if anything was changed
     */
    private fun applyFixToForegroundBackground(
        group: LightAppPermGroup,
        isForegroundFixed: Boolean,
        isBackgroundFixed: Boolean,
        allowedAlwaysState: ButtonState,
        allowedForegroundState: ButtonState,
        askState: ButtonState,
        deniedState: ButtonState,
        deniedForegroundState: ButtonState
    ): Boolean {
        if (isBackgroundFixed && isForegroundFixed) {
            // Background and foreground are both policy fixed. Disable everything
            allowedAlwaysState.isEnabled = false
            allowedForegroundState.isEnabled = false
            askState.isEnabled = false
            deniedState.isEnabled = false

            if (askState.isChecked) {
                askState.isChecked = false
                deniedState.isChecked = true
            }
        } else if (isBackgroundFixed && !isForegroundFixed) {
            if (group.background.isGranted) {
                // Background policy fixed as granted, foreground flexible. Granting
                // foreground implies background comes with it in this case.
                // Only allow user to grant background or deny (which only toggles fg)
                allowedForegroundState.isEnabled = false
                askState.isEnabled = false
                deniedState.isShown = false
                deniedForegroundState.isShown = true
                deniedForegroundState.isChecked = deniedState.isChecked

                if (askState.isChecked) {
                    askState.isChecked = false
                    deniedState.isChecked = true
                }
            } else {
                // Background policy fixed as not granted, foreground flexible
                allowedAlwaysState.isEnabled = false
            }
        } else if (!isBackgroundFixed && isForegroundFixed) {
            if (group.foreground.isGranted) {
                // Foreground is fixed as granted, background flexible.
                // Allow switching between foreground and background. No denying
                allowedForegroundState.isEnabled = allowedAlwaysState.isShown
                askState.isEnabled = false
                deniedState.isEnabled = false
            } else {
                // Foreground is fixed denied. Background irrelevant
                allowedAlwaysState.isEnabled = false
                allowedForegroundState.isEnabled = false
                askState.isEnabled = false
                deniedState.isEnabled = false

                if (askState.isChecked) {
                    askState.isChecked = false
                    deniedState.isChecked = true
                }
            }
        } else {
            return false
        }
        return true
    }

    /**
     * Navigate to either the App Permission Groups screen, or the Permission Apps Screen.
     * @param fragment The current fragment
     * @param action The action to be taken
     * @param args The arguments to pass to the fragment
     */
    fun showBottomLinkPage(fragment: Fragment, action: String, args: Bundle) {
        var actionId = R.id.app_to_perm_groups
        if (action == Intent.ACTION_MANAGE_PERMISSION_APPS) {
            actionId = R.id.app_to_perm_apps
        }

        fragment.findNavController().navigateSafe(actionId, args)
    }

    /**
     * Request to grant/revoke permissions group.
     *
     * Does <u>not</u> handle:
     *
     *  * Individually granted permissions
     *  * Permission groups with background permissions
     *
     * <u>Does</u> handle:
     *
     *  * Default grant permissions
     *
     * @param setOneTime Whether or not to set this permission as one time
     * @param fragment The fragment calling this method
     * @param defaultDeny The system which will show the default deny dialog. Usually the same as
     * the fragment.
     * @param changeRequest Which permission group (foreground/background/both) should be changed
     * @param buttonClicked button which was pressed to initiate the change, one of
     *                      AppPermissionFragmentActionReported.button_pressed constants
     *
     * @return The dialogue to show, if applicable, or if the request was processed.
     */
    fun requestChange(
        setOneTime: Boolean,
        fragment: Fragment,
        defaultDeny: ConfirmDialogShowingFragment,
        changeRequest: ChangeRequest,
        buttonClicked: Int
    ) {
        val context = fragment.context ?: return
        val group = lightAppPermGroup ?: return
        val wasForegroundGranted = group.foreground.isGranted
        val wasBackgroundGranted = group.background.isGranted

        if (LocationUtils.isLocationGroupAndProvider(context, permGroupName, packageName)) {
            val packageLabel = KotlinUtils.getPackageLabel(app, packageName, user)
            LocationUtils.showLocationDialog(context, packageLabel)
        }

        if (changeRequest == ChangeRequest.GRANT_FINE_LOCATION) {
            if (!group.isOneTime) {
                KotlinUtils.grantForegroundRuntimePermissions(app, group)
            }
            KotlinUtils.setFlagsWhenLocationAccuracyChanged(app, group, true)
            return
        }

        if (changeRequest == ChangeRequest.REVOKE_FINE_LOCATION) {
            if (!group.isOneTime) {
                KotlinUtils.revokeForegroundRuntimePermissions(app, group,
                    filterPermissions = listOf(ACCESS_FINE_LOCATION))
            }
            KotlinUtils.setFlagsWhenLocationAccuracyChanged(app, group, false)
            return
        }

        val shouldGrantForeground = changeRequest andValue ChangeRequest.GRANT_FOREGROUND != 0
        val shouldGrantBackground = changeRequest andValue ChangeRequest.GRANT_BACKGROUND != 0
        val shouldRevokeForeground = changeRequest andValue ChangeRequest.REVOKE_FOREGROUND != 0
        val shouldRevokeBackground = changeRequest andValue ChangeRequest.REVOKE_BACKGROUND != 0
        var showDefaultDenyDialog = false
        var showGrantedByDefaultWarning = false
        var showCDMWarning = false

        if (shouldRevokeForeground && wasForegroundGranted) {
            showDefaultDenyDialog = (group.foreground.isGrantedByDefault ||
                    !group.supportsRuntimePerms ||
                    group.hasInstallToRuntimeSplit)
            showGrantedByDefaultWarning = showGrantedByDefaultWarning ||
                    group.foreground.isGrantedByDefault
            showCDMWarning = showCDMWarning || group.foreground.isGrantedByRole
        }

        if (shouldRevokeBackground && wasBackgroundGranted) {
            showDefaultDenyDialog = showDefaultDenyDialog ||
                    group.background.isGrantedByDefault ||
                    !group.supportsRuntimePerms ||
                    group.hasInstallToRuntimeSplit
            showGrantedByDefaultWarning = showGrantedByDefaultWarning ||
                    group.background.isGrantedByDefault
            showCDMWarning = showCDMWarning || group.background.isGrantedByRole
        }

        if (showCDMWarning) {
            // Refine showCDMWarning to only trigger for apps holding a device profile role
            val heldRoles = context.getSystemService(android.app.role.RoleManager::class.java)
                    .getHeldRolesFromController(packageName)
            val heldProfiles = heldRoles.filter { it.startsWith(DEVICE_PROFILE_ROLE_PREFIX) }
            showCDMWarning = showCDMWarning && heldProfiles.isNotEmpty()
        }

        if (showDefaultDenyDialog && !hasConfirmedRevoke && showGrantedByDefaultWarning) {
            defaultDeny.showConfirmDialog(changeRequest, R.string.system_warning, buttonClicked,
                setOneTime)
            return
        }

        if (showDefaultDenyDialog && !hasConfirmedRevoke) {
            defaultDeny.showConfirmDialog(changeRequest, R.string.old_sdk_deny_warning,
                    buttonClicked, setOneTime)
            return
        }

        if (showCDMWarning) {
            defaultDeny.showConfirmDialog(changeRequest,
                    R.string.cdm_profile_revoke_warning, buttonClicked, setOneTime)
            return
        }

        var newGroup = group
        val oldGroup = group

        if (shouldRevokeBackground && group.hasBackgroundGroup &&
                (wasBackgroundGranted || group.background.isUserFixed ||
                        group.isOneTime != setOneTime)) {
            newGroup = KotlinUtils
                    .revokeBackgroundRuntimePermissions(app, newGroup)

            // only log if we have actually denied permissions, not if we switch from
            // "ask every time" to denied
            if (wasBackgroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup, true)
            }
        }

        if (shouldRevokeForeground && (wasForegroundGranted || group.isOneTime != setOneTime)) {
            newGroup = KotlinUtils
                    .revokeForegroundRuntimePermissions(app, newGroup, false, setOneTime)

            // only log if we have actually denied permissions, not if we switch from
            // "ask every time" to denied
            if (wasForegroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup)
            }
        }

        if (shouldGrantForeground) {
            if (shouldShowLocationAccuracy == true && !isFineLocationChecked(newGroup)) {
                newGroup = KotlinUtils.grantForegroundRuntimePermissions(app, newGroup,
                    filterPermissions = listOf(ACCESS_COARSE_LOCATION))
            } else {
                newGroup = KotlinUtils.grantForegroundRuntimePermissions(app, newGroup)
            }

            if (!wasForegroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup)
            }
        }

        if (shouldGrantBackground && group.hasBackgroundGroup) {
            newGroup = KotlinUtils.grantBackgroundRuntimePermissions(app, newGroup)

            if (!wasBackgroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup, true)
            }
        }

        logPermissionChanges(oldGroup, newGroup, buttonClicked)

        fullStorageStateLiveData.value?.let {
            FullStoragePermissionAppsLiveData.recalculate()
        }
    }

    /**
     * Once the user has confirmed that he/she wants to revoke a permission that was granted by
     * default, actually revoke the permissions.
     *
     * @param changeRequest whether to change foreground, background, or both.
     * @param buttonPressed button pressed to initiate the change, one of
     *                      AppPermissionFragmentActionReported.button_pressed constants
     * @param oneTime whether the change should show that the permission was selected as one-time
     *
     */
    fun onDenyAnyWay(changeRequest: ChangeRequest, buttonPressed: Int, oneTime: Boolean) {
        val group = lightAppPermGroup ?: return
        val wasForegroundGranted = group.foreground.isGranted
        val wasBackgroundGranted = group.background.isGranted
        var hasDefaultPermissions = false

        var newGroup = group
        val oldGroup = group

        if (changeRequest andValue ChangeRequest.REVOKE_BACKGROUND != 0 &&
            group.hasBackgroundGroup) {
            newGroup = KotlinUtils.revokeBackgroundRuntimePermissions(app, newGroup, false, oneTime)

            if (wasBackgroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup)
            }
            hasDefaultPermissions = hasDefaultPermissions ||
                group.background.isGrantedByDefault
        }

        if (changeRequest andValue ChangeRequest.REVOKE_FOREGROUND != 0) {
            newGroup = KotlinUtils.revokeForegroundRuntimePermissions(app, newGroup, false, oneTime)
            if (wasForegroundGranted) {
                SafetyNetLogger.logPermissionToggled(newGroup)
            }
            hasDefaultPermissions = group.foreground.isGrantedByDefault
        }
        logPermissionChanges(oldGroup, newGroup, buttonPressed)

        if (hasDefaultPermissions || !group.supportsRuntimePerms) {
            hasConfirmedRevoke = true
        }

        fullStorageStateLiveData.value?.let {
            FullStoragePermissionAppsLiveData.recalculate()
        }
    }

    /**
     * Set the All Files access for this app
     *
     * @param granted Whether to grant or revoke access
     */
    fun setAllFilesAccess(granted: Boolean) {
        val aom = app.getSystemService(AppOpsManager::class.java)!!
        val uid = lightAppPermGroup?.packageInfo?.uid ?: return
        val mode = if (granted) {
            MODE_ALLOWED
        } else {
            MODE_ERRORED
        }
        val fullStorageGrant = fullStorageStateLiveData.value?.isGranted
        if (fullStorageGrant != null && fullStorageGrant != granted) {
            aom.setUidMode(OPSTR_MANAGE_EXTERNAL_STORAGE, uid, mode)
            FullStoragePermissionAppsLiveData.recalculate()
        }
    }

    /**
     * Show the All App Permissions screen with the proper filter group, package name, and user.
     *
     * @param fragment The current fragment we wish to transition from
     */
    fun showAllPermissions(fragment: Fragment, args: Bundle) {
        fragment.findNavController().navigateSafe(R.id.app_to_all_perms, args)
    }

    private fun getIndividualPermissionDetailResId(group: LightAppPermGroup): Pair<Int, Int> {
        return when (val numRevoked =
            group.permissions.filter { !it.value.isGrantedIncludingAppOp }.size) {
            0 -> R.string.permission_revoked_none to numRevoked
            group.permissions.size -> R.string.permission_revoked_all to numRevoked
            else -> R.string.permission_revoked_count to numRevoked
        }
    }

    /**
     * Get the detail string id of a permission group if it is at least partially fixed by policy.
     */
    private fun getDetailResIdForFixedByPolicyPermissionGroup(
        group: LightAppPermGroup,
        hasAdmin: Boolean
    ): Int {
        val isForegroundPolicyDenied = group.foreground.isPolicyFixed && !group.foreground.isGranted
        val isPolicyFullyFixedWithGrantedOrNoBkg = group.isPolicyFullyFixed &&
            (group.background.isGranted || !group.hasBackgroundGroup)
        if (group.foreground.isSystemFixed || group.background.isSystemFixed) {
            return R.string.permission_summary_enabled_system_fixed
        } else if (hasAdmin) {
            // Permission is fully controlled by policy and cannot be switched
            if (isForegroundPolicyDenied) {
                return R.string.disabled_by_admin
            } else if (isPolicyFullyFixedWithGrantedOrNoBkg) {
                return R.string.enabled_by_admin
            } else if (group.isPolicyFullyFixed) {
                return R.string.permission_summary_enabled_by_admin_foreground_only
            }

            // Part of the permission group can still be switched
            if (group.background.isPolicyFixed && group.background.isGranted) {
                return R.string.permission_summary_enabled_by_admin_background_only
            } else if (group.background.isPolicyFixed) {
                return R.string.permission_summary_disabled_by_admin_background_only
            } else if (group.foreground.isPolicyFixed) {
                return R.string.permission_summary_enabled_by_admin_foreground_only
            }
        } else {
            // Permission is fully controlled by policy and cannot be switched
            if ((isForegroundPolicyDenied) || isPolicyFullyFixedWithGrantedOrNoBkg) {
                // Permission is fully controlled by policy and cannot be switched
                // State will be displayed by switch, so no need to add text for that
                return R.string.permission_summary_enforced_by_policy
            } else if (group.isPolicyFullyFixed) {
                return R.string.permission_summary_enabled_by_policy_foreground_only
            }

            // Part of the permission group can still be switched
            if (group.background.isPolicyFixed && group.background.isGranted) {
                return R.string.permission_summary_enabled_by_policy_background_only
            } else if (group.background.isPolicyFixed) {
                return R.string.permission_summary_disabled_by_policy_background_only
            } else if (group.foreground.isPolicyFixed) {
                return R.string.permission_summary_enabled_by_policy_foreground_only
            }
        }
        return 0
    }

    private fun logPermissionChanges(
        oldGroup: LightAppPermGroup,
        newGroup: LightAppPermGroup,
        buttonPressed: Int
    ) {
        val changeId = Random().nextLong()

        for ((permName, permission) in oldGroup.permissions) {
            val newPermission = newGroup.permissions[permName] ?: continue

            if (permission.isGrantedIncludingAppOp != newPermission.isGrantedIncludingAppOp ||
                permission.flags != newPermission.flags) {
                logAppPermissionFragmentActionReported(changeId, newPermission, buttonPressed)
            }
        }
    }

    private fun logAppPermissionFragmentActionReported(
        changeId: Long,
        permission: LightPermission,
        buttonPressed: Int
    ) {
        val uid = KotlinUtils.getPackageUid(app, packageName, user) ?: return
        PermissionControllerStatsLog.write(APP_PERMISSION_FRAGMENT_ACTION_REPORTED, sessionId,
            changeId, uid, packageName, permission.permInfo.name,
            permission.isGrantedIncludingAppOp, permission.flags, buttonPressed)
        Log.v(LOG_TAG, "Permission changed via UI with sessionId=$sessionId changeId=" +
            "$changeId uid=$uid packageName=$packageName permission=" + permission.permInfo.name +
            " isGranted=" + permission.isGrantedIncludingAppOp + " permissionFlags=" +
            permission.flags + " buttonPressed=$buttonPressed")
    }

    /**
     * Logs information about this AppPermissionGroup and view session
     */
    fun logAppPermissionFragmentViewed() {
        val uid = KotlinUtils.getPackageUid(app, packageName, user) ?: return
        PermissionControllerStatsLog.write(APP_PERMISSION_FRAGMENT_VIEWED, sessionId,
            uid, packageName, permGroupName)
        Log.v(LOG_TAG, "AppPermission fragment viewed with sessionId=$sessionId uid=" +
            "$uid packageName=$packageName" +
            "permGroupName=$permGroupName")
    }
}

/**
 * Factory for an AppPermissionViewModel
 *
 * @param app The current application
 * @param packageName The name of the package this ViewModel represents
 * @param permGroupName The name of the permission group this ViewModel represents
 * @param user The user of the package
 * @param sessionId A session ID used in logs to identify this particular session
 */
class AppPermissionViewModelFactory(
    private val app: Application,
    private val packageName: String,
    private val permGroupName: String,
    private val user: UserHandle,
    private val sessionId: Long
) : ViewModelProvider.Factory {
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        @Suppress("UNCHECKED_CAST")
        return AppPermissionViewModel(app, packageName, permGroupName, user, sessionId) as T
    }
}