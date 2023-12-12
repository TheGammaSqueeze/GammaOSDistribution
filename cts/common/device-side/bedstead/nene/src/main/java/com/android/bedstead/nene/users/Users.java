/*
 * Copyright (C) 2021 The Android Open Source Project
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

package com.android.bedstead.nene.users;

import static android.Manifest.permission.CREATE_USERS;
import static android.Manifest.permission.INTERACT_ACROSS_USERS;
import static android.Manifest.permission.INTERACT_ACROSS_USERS_FULL;
import static android.os.Build.VERSION.SDK_INT;
import static android.os.Build.VERSION_CODES.S;
import static android.os.Build.VERSION_CODES.S_V2;
import static android.os.Process.myUserHandle;

import static com.android.bedstead.nene.users.UserType.MANAGED_PROFILE_TYPE_NAME;
import static com.android.bedstead.nene.users.UserType.SECONDARY_USER_TYPE_NAME;
import static com.android.bedstead.nene.users.UserType.SYSTEM_USER_TYPE_NAME;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.UserInfo;
import android.os.Build;
import android.os.UserHandle;
import android.os.UserManager;

import androidx.annotation.CheckResult;
import androidx.annotation.Nullable;

import com.android.bedstead.nene.TestApis;
import com.android.bedstead.nene.exceptions.AdbException;
import com.android.bedstead.nene.exceptions.AdbParseException;
import com.android.bedstead.nene.exceptions.NeneException;
import com.android.bedstead.nene.permissions.PermissionContext;
import com.android.bedstead.nene.permissions.Permissions;
import com.android.bedstead.nene.utils.Poll;
import com.android.bedstead.nene.utils.ShellCommand;
import com.android.bedstead.nene.utils.Versions;

import java.time.Duration;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class Users {

    static final int SYSTEM_USER_ID = 0;
    private static final Duration WAIT_FOR_USER_TIMEOUT = Duration.ofMinutes(4);

    private Map<Integer, AdbUser> mCachedUsers = null;
    private Map<String, UserType> mCachedUserTypes = null;
    private Set<UserType> mCachedUserTypeValues = null;
    private final AdbUserParser mParser;
    private static final UserManager sUserManager =
            TestApis.context().instrumentedContext().getSystemService(UserManager.class);

    public static final Users sInstance = new Users();

    private Users() {
        mParser = AdbUserParser.get(SDK_INT);
    }

    /** Get all {@link UserReference}s on the device. */
    public Collection<UserReference> all() {
        if (!Versions.meetsMinimumSdkVersionRequirement(S)) {
            fillCache();
            return mCachedUsers.keySet().stream().map(UserReference::new)
                    .collect(Collectors.toSet());
        }

        return users().map(
                ui -> new UserReference(ui.id)
        ).collect(Collectors.toSet());
    }

    /**
     * Gets a {@link UserReference} for the initial user for the device.
     *
     * <p>This will be the {@link #system()} user on most systems.</p>
     */
    public UserReference initial() {
        if (!isHeadlessSystemUserMode()) {
            return system();
        }
        if (TestApis.packages().features().contains("android.hardware.type.automotive")) {
            try {
                return ShellCommand.builder("cmd car_service get-initial-user")
                        .executeAndParseOutput(i -> find(Integer.parseInt(i.trim())));
            } catch (AdbException e) {
                throw new NeneException("Error finding initial user on Auto", e);
            }
        }

        List<UserReference> users = new ArrayList<>(all());
        users.sort(Comparator.comparingInt(UserReference::id));

        for (UserReference user : users) {
            if (user.parent() == null) {
                return user;
            }
        }

        throw new NeneException("No initial user available");
    }

    /** Get a {@link UserReference} for the user currently switched to. */
    public UserReference current() {
        if (Versions.meetsMinimumSdkVersionRequirement(S)) {
            try (PermissionContext p =
                         TestApis.permissions().withPermission(INTERACT_ACROSS_USERS_FULL)) {
                return find(ActivityManager.getCurrentUser());
            }
        }

        try {
            return find((int) ShellCommand.builder("am get-current-user")
                    .executeAndParseOutput(i -> Integer.parseInt(i.trim())));
        } catch (AdbException e) {
            throw new NeneException("Error getting current user", e);
        }
    }

    /** Get a {@link UserReference} for the user running the current test process. */
    public UserReference instrumented() {
        return find(myUserHandle());
    }

    /** Get a {@link UserReference} for the system user. */
    public UserReference system() {
        return find(0);
    }

    /** Get a {@link UserReference} by {@code id}. */
    public UserReference find(int id) {
        return new UserReference(id);
    }

    /** Get a {@link UserReference} by {@code userHandle}. */
    public UserReference find(UserHandle userHandle) {
        return new UserReference(userHandle.getIdentifier());
    }

    /** Get all supported {@link UserType}s. */
    public Set<UserType> supportedTypes() {
        // TODO(b/203557600): Stop using adb
        ensureSupportedTypesCacheFilled();
        return mCachedUserTypeValues;
    }

    /** Get a {@link UserType} with the given {@code typeName}, or {@code null} */
    @Nullable
    public UserType supportedType(String typeName) {
        ensureSupportedTypesCacheFilled();
        return mCachedUserTypes.get(typeName);
    }

    /**
     * Find all users which have the given {@link UserType}.
     */
    public Set<UserReference> findUsersOfType(UserType userType) {
        if (userType == null) {
            throw new NullPointerException();
        }

        if (userType.baseType().contains(UserType.BaseType.PROFILE)) {
            throw new NeneException("Cannot use findUsersOfType with profile type " + userType);
        }

        return all().stream()
                .filter(u -> u.type().equals(userType))
                .collect(Collectors.toSet());
    }

    /**
     * Find a single user which has the given {@link UserType}.
     *
     * <p>If there are no users of the given type, {@code Null} will be returned.
     *
     * <p>If there is more than one user of the given type, {@link NeneException} will be thrown.
     */
    @Nullable
    public UserReference findUserOfType(UserType userType) {
        Set<UserReference> users = findUsersOfType(userType);

        if (users.isEmpty()) {
            return null;
        } else if (users.size() > 1) {
            throw new NeneException("findUserOfType called but there is more than 1 user of type "
                    + userType + ". Found: " + users);
        }

        return users.iterator().next();
    }

    /**
     * Find all users which have the given {@link UserType} and the given parent.
     */
    public Set<UserReference> findProfilesOfType(UserType userType, UserReference parent) {
        if (userType == null || parent == null) {
            throw new NullPointerException();
        }

        if (!userType.baseType().contains(UserType.BaseType.PROFILE)) {
            throw new NeneException("Cannot use findProfilesOfType with non-profile type "
                    + userType);
        }

        return all().stream()
                .filter(u -> parent.equals(u.parent())
                        && u.type().equals(userType))
                .collect(Collectors.toSet());
    }

    /**
     * Find all users which have the given {@link UserType} and the given parent.
     *
     * <p>If there are no users of the given type and parent, {@code Null} will be returned.
     *
     * <p>If there is more than one user of the given type and parent, {@link NeneException} will
     * be thrown.
     */
    @Nullable
    public UserReference findProfileOfType(UserType userType, UserReference parent) {
        Set<UserReference> profiles = findProfilesOfType(userType, parent);

        if (profiles.isEmpty()) {
            return null;
        } else if (profiles.size() > 1) {
            throw new NeneException("findProfileOfType called but there is more than 1 user of "
                    + "type " + userType + " with parent " + parent + ". Found: " + profiles);
        }

        return profiles.iterator().next();
    }

    private void ensureSupportedTypesCacheFilled() {
        if (mCachedUserTypes != null) {
            // SupportedTypes don't change so don't need to be refreshed
            return;
        }
        if (SDK_INT < Build.VERSION_CODES.R) {
            mCachedUserTypes = new HashMap<>();
            mCachedUserTypes.put(MANAGED_PROFILE_TYPE_NAME, managedProfileUserType());
            mCachedUserTypes.put(SYSTEM_USER_TYPE_NAME, systemUserType());
            mCachedUserTypes.put(SECONDARY_USER_TYPE_NAME, secondaryUserType());
            mCachedUserTypeValues = new HashSet<>();
            mCachedUserTypeValues.addAll(mCachedUserTypes.values());
            return;
        }

        fillCache();
    }

    private UserType managedProfileUserType() {
        UserType.MutableUserType managedProfileMutableUserType = new UserType.MutableUserType();
        managedProfileMutableUserType.mName = MANAGED_PROFILE_TYPE_NAME;
        managedProfileMutableUserType.mBaseType = Set.of(UserType.BaseType.PROFILE);
        managedProfileMutableUserType.mEnabled = true;
        managedProfileMutableUserType.mMaxAllowed = -1;
        managedProfileMutableUserType.mMaxAllowedPerParent = 1;
        return new UserType(managedProfileMutableUserType);
    }

    private UserType systemUserType() {
        UserType.MutableUserType managedProfileMutableUserType = new UserType.MutableUserType();
        managedProfileMutableUserType.mName = SYSTEM_USER_TYPE_NAME;
        managedProfileMutableUserType.mBaseType =
                Set.of(UserType.BaseType.FULL, UserType.BaseType.SYSTEM);
        managedProfileMutableUserType.mEnabled = true;
        managedProfileMutableUserType.mMaxAllowed = -1;
        managedProfileMutableUserType.mMaxAllowedPerParent = -1;
        return new UserType(managedProfileMutableUserType);
    }

    private UserType secondaryUserType() {
        UserType.MutableUserType managedProfileMutableUserType = new UserType.MutableUserType();
        managedProfileMutableUserType.mName = SECONDARY_USER_TYPE_NAME;
        managedProfileMutableUserType.mBaseType = Set.of(UserType.BaseType.FULL);
        managedProfileMutableUserType.mEnabled = true;
        managedProfileMutableUserType.mMaxAllowed = -1;
        managedProfileMutableUserType.mMaxAllowedPerParent = -1;
        return new UserType(managedProfileMutableUserType);
    }

    /**
     * Create a new user.
     */
    @CheckResult
    public UserBuilder createUser() {
        return new UserBuilder();
    }

    /**
     * Get a {@link UserReference} to a user who does not exist.
     */
    public UserReference nonExisting() {
        Set<Integer> userIds;
        if (Versions.meetsMinimumSdkVersionRequirement(S)) {
            userIds = users().map(ui -> ui.id).collect(Collectors.toSet());
        } else {
            fillCache();
            userIds = mCachedUsers.keySet();
        }

        int id = 0;

        while (userIds.contains(id)) {
            id++;
        }

        return new UserReference(id);
    }

    private void fillCache() {
        try {
            // TODO: Replace use of adb on supported versions of Android
            String userDumpsysOutput = ShellCommand.builder("dumpsys user").execute();
            AdbUserParser.ParseResult result = mParser.parse(userDumpsysOutput);

            mCachedUsers = result.mUsers;
            if (result.mUserTypes != null) {
                mCachedUserTypes = result.mUserTypes;
            } else {
                ensureSupportedTypesCacheFilled();
            }

            Iterator<Map.Entry<Integer, AdbUser>> iterator = mCachedUsers.entrySet().iterator();

            while (iterator.hasNext()) {
                Map.Entry<Integer, AdbUser> entry = iterator.next();

                if (entry.getValue().isRemoving()) {
                    // We don't expose users who are currently being removed
                    iterator.remove();
                    continue;
                }

                AdbUser.MutableUser mutableUser = entry.getValue().mMutableUser;

                if (SDK_INT < Build.VERSION_CODES.R) {
                    if (entry.getValue().id() == SYSTEM_USER_ID) {
                        mutableUser.mType = supportedType(SYSTEM_USER_TYPE_NAME);
                        mutableUser.mIsPrimary = true;
                    } else if (entry.getValue().hasFlag(AdbUser.FLAG_MANAGED_PROFILE)) {
                        mutableUser.mType =
                                supportedType(MANAGED_PROFILE_TYPE_NAME);
                        mutableUser.mIsPrimary = false;
                    } else {
                        mutableUser.mType =
                                supportedType(SECONDARY_USER_TYPE_NAME);
                        mutableUser.mIsPrimary = false;
                    }
                }

                if (SDK_INT < S) {
                    if (mutableUser.mType.baseType()
                            .contains(UserType.BaseType.PROFILE)) {
                        // We assume that all profiles before S were on the System User
                        mutableUser.mParent = find(SYSTEM_USER_ID);
                    }
                }
            }

            mCachedUserTypeValues = new HashSet<>();
            mCachedUserTypeValues.addAll(mCachedUserTypes.values());

        } catch (AdbException | AdbParseException e) {
            throw new RuntimeException("Error filling cache", e);
        }
    }

    /**
     * Block until the user with the given {@code userReference} to not exist or to be in the
     * correct state.
     *
     * <p>If this cannot be met before a timeout, a {@link NeneException} will be thrown.
     */
    @Nullable
    UserReference waitForUserToNotExistOrMatch(
            UserReference userReference, Function<UserReference, Boolean> userChecker) {
        return waitForUserToMatch(userReference, userChecker, /* waitForExist= */ false);
    }

    @Nullable
    private UserReference waitForUserToMatch(
            UserReference userReference, Function<UserReference, Boolean> userChecker,
            boolean waitForExist) {
        // TODO(scottjonathan): This is pretty heavy because we resolve everything when we know we
        //  are throwing away everything except one user. Optimise
        try {
            return Poll.forValue("user", () -> userReference)
                    .toMeet((user) -> {
                        if (user == null) {
                            return !waitForExist;
                        }
                        return userChecker.apply(user);
                    }).timeout(WAIT_FOR_USER_TIMEOUT)
                    .errorOnFail("Expected user to meet requirement")
                    .await();
        } catch (AssertionError e) {
            if (!userReference.exists()) {
                throw new NeneException(
                        "Timed out waiting for user state for user "
                                + userReference + ". User does not exist.", e);
            }
            throw new NeneException(
                    "Timed out waiting for user state, current state " + userReference, e
            );
        }
    }

    /** See {@link UserManager#isHeadlessSystemUserMode()}. */
    @SuppressWarnings("NewApi")
    public boolean isHeadlessSystemUserMode() {
        if (Versions.meetsMinimumSdkVersionRequirement(S)) {
            return UserManager.isHeadlessSystemUserMode();
        }

        return false;
    }

    /**
     * Set the stopBgUsersOnSwitch property.
     *
     * <p>This affects if background users will be swapped when switched away from on some devices.
     */
    public void setStopBgUsersOnSwitch(int value) {
        if (!Versions.meetsMinimumSdkVersionRequirement(S_V2)) {
            return;
        }
        Context context = TestApis.context().instrumentedContext();
        try (PermissionContext p = TestApis.permissions()
                .withPermission(INTERACT_ACROSS_USERS)) {
            context.getSystemService(ActivityManager.class).setStopUserOnSwitch(value);
        }
    }

    @Nullable
    AdbUser fetchUser(int id) {
        fillCache();
        return mCachedUsers.get(id);
    }

    static Stream<UserInfo> users() {
        if (Permissions.sIgnorePermissions.get()) {
            return sUserManager.getUsers(
                    /* excludePartial= */ false,
                    /* excludeDying= */ true,
                    /* excludePreCreated= */ false).stream();
        }

        try (PermissionContext p = TestApis.permissions().withPermission(CREATE_USERS)) {
            return sUserManager.getUsers(
                    /* excludePartial= */ false,
                    /* excludeDying= */ true,
                    /* excludePreCreated= */ false).stream();
        }
    }
}
