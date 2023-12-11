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

package com.android.bedstead.harrier;

import static android.Manifest.permission.INTERACT_ACROSS_USERS_FULL;
import static android.app.ActivityManager.STOP_USER_ON_SWITCH_DEFAULT;
import static android.app.ActivityManager.STOP_USER_ON_SWITCH_FALSE;

import static com.android.bedstead.nene.permissions.Permissions.NOTIFY_PENDING_SYSTEM_UPDATE;
import static com.android.bedstead.nene.users.UserType.MANAGED_PROFILE_TYPE_NAME;
import static com.android.bedstead.nene.users.UserType.SECONDARY_USER_TYPE_NAME;
import static com.android.bedstead.nene.utils.Versions.meetsSdkVersionRequirements;

import static com.google.common.truth.Truth.assertWithMessage;

import static org.junit.Assert.assertFalse;
import static org.junit.Assume.assumeFalse;
import static org.junit.Assume.assumeTrue;

import android.app.ActivityManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;

import androidx.test.core.app.ApplicationProvider;
import androidx.test.platform.app.InstrumentationRegistry;

import com.android.bedstead.harrier.annotations.AfterClass;
import com.android.bedstead.harrier.annotations.BeforeClass;
import com.android.bedstead.harrier.annotations.EnsureDoesNotHavePermission;
import com.android.bedstead.harrier.annotations.EnsureHasPermission;
import com.android.bedstead.harrier.annotations.EnsurePackageNotInstalled;
import com.android.bedstead.harrier.annotations.FailureMode;
import com.android.bedstead.harrier.annotations.RequireDoesNotHaveFeature;
import com.android.bedstead.harrier.annotations.RequireFeature;
import com.android.bedstead.harrier.annotations.RequireGmsInstrumentation;
import com.android.bedstead.harrier.annotations.RequireHeadlessSystemUserMode;
import com.android.bedstead.harrier.annotations.RequireLowRamDevice;
import com.android.bedstead.harrier.annotations.RequireNotHeadlessSystemUserMode;
import com.android.bedstead.harrier.annotations.RequireNotLowRamDevice;
import com.android.bedstead.harrier.annotations.RequirePackageInstalled;
import com.android.bedstead.harrier.annotations.RequirePackageNotInstalled;
import com.android.bedstead.harrier.annotations.RequireSdkVersion;
import com.android.bedstead.harrier.annotations.RequireUserSupported;
import com.android.bedstead.harrier.annotations.TestTag;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasDelegate;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasDeviceOwner;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasNoDelegate;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasNoDeviceOwner;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasNoProfileOwner;
import com.android.bedstead.harrier.annotations.enterprise.EnsureHasProfileOwner;
import com.android.bedstead.harrier.annotations.meta.EnsureHasNoProfileAnnotation;
import com.android.bedstead.harrier.annotations.meta.EnsureHasNoUserAnnotation;
import com.android.bedstead.harrier.annotations.meta.EnsureHasProfileAnnotation;
import com.android.bedstead.harrier.annotations.meta.EnsureHasUserAnnotation;
import com.android.bedstead.harrier.annotations.meta.ParameterizedAnnotation;
import com.android.bedstead.harrier.annotations.meta.RequireRunOnProfileAnnotation;
import com.android.bedstead.harrier.annotations.meta.RequireRunOnUserAnnotation;
import com.android.bedstead.harrier.annotations.meta.RequiresBedsteadJUnit4;
import com.android.bedstead.nene.TestApis;
import com.android.bedstead.nene.devicepolicy.DeviceOwner;
import com.android.bedstead.nene.devicepolicy.DevicePolicyController;
import com.android.bedstead.nene.devicepolicy.ProfileOwner;
import com.android.bedstead.nene.exceptions.AdbException;
import com.android.bedstead.nene.exceptions.NeneException;
import com.android.bedstead.nene.packages.Package;
import com.android.bedstead.nene.permissions.PermissionContextImpl;
import com.android.bedstead.nene.users.UserBuilder;
import com.android.bedstead.nene.users.UserReference;
import com.android.bedstead.nene.utils.ShellCommand;
import com.android.bedstead.nene.utils.Tags;
import com.android.bedstead.nene.utils.Versions;
import com.android.bedstead.remotedpc.RemoteDelegate;
import com.android.bedstead.remotedpc.RemoteDpc;
import com.android.bedstead.remotedpc.RemotePolicyManager;
import com.android.bedstead.testapp.TestApp;
import com.android.bedstead.testapp.TestAppInstance;
import com.android.compatibility.common.util.BlockingBroadcastReceiver;
import com.android.eventlib.EventLogs;

import com.google.common.base.Objects;

import junit.framework.AssertionFailedError;

import org.junit.AssumptionViolatedException;
import org.junit.rules.TestRule;
import org.junit.runner.Description;
import org.junit.runners.model.FrameworkMethod;
import org.junit.runners.model.Statement;
import org.junit.runners.model.TestClass;

import java.lang.annotation.Annotation;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Function;


/**
 * A Junit rule which exposes methods for efficiently changing and querying device state.
 *
 * <p>States set by the methods on this class will by default be cleaned up after the test.
 *
 *
 * <p>Using this rule also enforces preconditions in annotations from the
 * {@code com.android.comaptibility.common.util.enterprise.annotations} package.
 *
 * {@code assumeTrue} will be used, so tests which do not meet preconditions will be skipped.
 */
public final class DeviceState implements TestRule {

    private static final String GMS_PKG = "com.google.android.gms";
    private static final ComponentName REMOTE_DPC_COMPONENT_NAME = RemoteDpc.DPC_COMPONENT_NAME;

    private static final String SWITCHED_TO_USER = "switchedToUser";
    private static final String SWITCHED_TO_PARENT_USER = "switchedToParentUser";
    public static final String INSTALL_INSTRUMENTED_APP = "installInstrumentedApp";
    public static final String FOR_USER = "forUser";
    public static final String DPC_IS_PRIMARY = "dpcIsPrimary";
    public static final String AFFILIATION_IDS = "affiliationIds";

    private final Context mContext = ApplicationProvider.getApplicationContext();
    private static final String SKIP_TEST_TEARDOWN_KEY = "skip-test-teardown";
    private static final String SKIP_CLASS_TEARDOWN_KEY = "skip-class-teardown";
    private static final String SKIP_TESTS_REASON_KEY = "skip-tests-reason";
    private static final String MIN_SDK_VERSION_KEY = "min-sdk-version";
    private boolean mSkipTestTeardown;
    private boolean mSkipClassTeardown;
    private boolean mSkipTests;
    private boolean mFailTests;
    private boolean mUsingBedsteadJUnit4 = false;
    private String mSkipTestsReason;
    private String mFailTestsReason;
    // The minimum version supported by tests, defaults to current version
    private final int mMinSdkVersion;
    private int mMinSdkVersionCurrentTest;

    // Marks if the conditions for requiring running under GMS instrumentation have been set
    // if not - we assume the test should never run under GMS instrumentation
    private boolean mHasRequireGmsInstrumentation = false;

    private static final String TV_PROFILE_TYPE_NAME = "com.android.tv.profile";

    public DeviceState() {
        Bundle arguments = InstrumentationRegistry.getArguments();
        mSkipTestTeardown = Boolean.parseBoolean(
                arguments.getString(SKIP_TEST_TEARDOWN_KEY, "false"));
        mSkipClassTeardown = Boolean.parseBoolean(
                arguments.getString(SKIP_CLASS_TEARDOWN_KEY, "false"));
        mSkipTestsReason = arguments.getString(SKIP_TESTS_REASON_KEY, "");
        mSkipTests = !mSkipTestsReason.isEmpty();
        mMinSdkVersion = arguments.getInt(MIN_SDK_VERSION_KEY, Build.VERSION.SDK_INT);
    }

    void setSkipTestTeardown(boolean skipTestTeardown) {
        mSkipTestTeardown = skipTestTeardown;
    }

    void setUsingBedsteadJUnit4(boolean usingBedsteadJUnit4) {
        mUsingBedsteadJUnit4 = usingBedsteadJUnit4;
    }

    @Override public Statement apply(final Statement base,
            final Description description) {

        if (description.isTest()) {
            return applyTest(base, description);
        } else if (description.isSuite()) {
            return applySuite(base, description);
        }
        throw new IllegalStateException("Unknown description type: " + description);
    }

    private Statement applyTest(Statement base, Description description) {
        return new Statement() {
            @Override public void evaluate() throws Throwable {
                PermissionContextImpl permissionContext = null;

                try {
                    Log.d(LOG_TAG, "Preparing state for test " + description.getMethodName());

                    Tags.clearTags();
                    Tags.addTag(Tags.USES_DEVICESTATE);
                    assumeFalse(mSkipTestsReason, mSkipTests);
                    assertFalse(mFailTestsReason, mFailTests);

                    // Ensure that tests only see events from the current test
                    EventLogs.resetLogs();

                    mMinSdkVersionCurrentTest = mMinSdkVersion;
                    List<Annotation> annotations = getAnnotations(description);
                    permissionContext = applyAnnotations(annotations);

                    Log.d(LOG_TAG,
                            "Finished preparing state for test " + description.getMethodName());

                    base.evaluate();
                } finally {
                    Log.d(LOG_TAG,
                            "Tearing down state for test " + description.getMethodName());

                    if (permissionContext != null) {
                        permissionContext.close();
                    }

                    teardownNonShareableState();
                    if (!mSkipTestTeardown) {
                        teardownShareableState();
                    }
                    Log.d(LOG_TAG,
                            "Finished tearing down state for test "
                                    + description.getMethodName());
                }
            }};
    }

    private PermissionContextImpl applyAnnotations(List<Annotation> annotations)
            throws Throwable {
        PermissionContextImpl permissionContext = null;
        for (Annotation annotation : annotations) {
            Log.i(LOG_TAG, "Applying annotation " + annotation);

            Class<? extends Annotation> annotationType = annotation.annotationType();

            EnsureHasNoProfileAnnotation ensureHasNoProfileAnnotation =
                    annotationType.getAnnotation(EnsureHasNoProfileAnnotation.class);
            if (ensureHasNoProfileAnnotation != null) {
                UserType userType = (UserType) annotation.annotationType()
                        .getMethod(FOR_USER).invoke(annotation);
                ensureHasNoProfile(ensureHasNoProfileAnnotation.value(), userType);
                continue;
            }

            EnsureHasProfileAnnotation ensureHasProfileAnnotation =
                    annotationType.getAnnotation(EnsureHasProfileAnnotation.class);
            if (ensureHasProfileAnnotation != null) {
                UserType forUser = (UserType) annotation.annotationType()
                        .getMethod(FOR_USER).invoke(annotation);
                OptionalBoolean installInstrumentedApp = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(INSTALL_INSTRUMENTED_APP).invoke(annotation);

                boolean dpcIsPrimary = false;
                if (ensureHasProfileAnnotation.hasProfileOwner()) {
                    dpcIsPrimary = (boolean)
                            annotation.annotationType()
                                    .getMethod(DPC_IS_PRIMARY).invoke(annotation);
                }

                OptionalBoolean switchedToParentUser = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(SWITCHED_TO_PARENT_USER).invoke(annotation);

                ensureHasProfile(
                        ensureHasProfileAnnotation.value(), installInstrumentedApp,
                        forUser, ensureHasProfileAnnotation.hasProfileOwner(),
                        dpcIsPrimary, switchedToParentUser);
                continue;
            }

            EnsureHasNoUserAnnotation ensureHasNoUserAnnotation =
                    annotationType.getAnnotation(EnsureHasNoUserAnnotation.class);
            if (ensureHasNoUserAnnotation != null) {
                ensureHasNoUser(ensureHasNoUserAnnotation.value());
                continue;
            }

            EnsureHasUserAnnotation ensureHasUserAnnotation =
                    annotationType.getAnnotation(EnsureHasUserAnnotation.class);
            if (ensureHasUserAnnotation != null) {
                OptionalBoolean installInstrumentedApp = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(INSTALL_INSTRUMENTED_APP).invoke(annotation);
                OptionalBoolean switchedToUser = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(SWITCHED_TO_USER).invoke(annotation);
                ensureHasUser(
                        ensureHasUserAnnotation.value(), installInstrumentedApp, switchedToUser);
                continue;
            }

            RequireRunOnUserAnnotation requireRunOnUserAnnotation =
                    annotationType.getAnnotation(RequireRunOnUserAnnotation.class);
            if (requireRunOnUserAnnotation != null) {
                OptionalBoolean switchedToUser = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(SWITCHED_TO_USER).invoke(annotation);
                requireRunOnUser(requireRunOnUserAnnotation.value(), switchedToUser);
                continue;
            }

            if (annotation instanceof TestTag) {
                TestTag testTagAnnotation = (TestTag) annotation;
                Tags.addTag(testTagAnnotation.value());
            }

            RequireRunOnProfileAnnotation requireRunOnProfileAnnotation =
                    annotationType.getAnnotation(RequireRunOnProfileAnnotation.class);
            if (requireRunOnProfileAnnotation != null) {
                OptionalBoolean installInstrumentedAppInParent = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod("installInstrumentedAppInParent")
                                .invoke(annotation);

                OptionalBoolean switchedToParentUser = (OptionalBoolean)
                        annotation.annotationType()
                                .getMethod(SWITCHED_TO_PARENT_USER).invoke(annotation);


                boolean dpcIsPrimary = false;
                Set<String> affiliationIds = null;
                if (requireRunOnProfileAnnotation.hasProfileOwner()) {
                    dpcIsPrimary = (boolean)
                            annotation.annotationType()
                                    .getMethod(DPC_IS_PRIMARY).invoke(annotation);
                    affiliationIds = new HashSet<>(Arrays.asList((String[])
                            annotation.annotationType()
                                    .getMethod(AFFILIATION_IDS).invoke(annotation)));
                }

                requireRunOnProfile(requireRunOnProfileAnnotation.value(),
                        installInstrumentedAppInParent,
                        requireRunOnProfileAnnotation.hasProfileOwner(),
                        dpcIsPrimary, switchedToParentUser, affiliationIds);
                continue;
            }

            if (annotation instanceof EnsureHasDelegate) {
                EnsureHasDelegate ensureHasDelegateAnnotation =
                        (EnsureHasDelegate) annotation;
                ensureHasDelegate(
                        ensureHasDelegateAnnotation.admin(),
                        Arrays.asList(ensureHasDelegateAnnotation.scopes()),
                        ensureHasDelegateAnnotation.isPrimary());
                continue;
            }


            if (annotation instanceof EnsureHasDeviceOwner) {
                EnsureHasDeviceOwner ensureHasDeviceOwnerAnnotation =
                        (EnsureHasDeviceOwner) annotation;
                ensureHasDeviceOwner(ensureHasDeviceOwnerAnnotation.failureMode(),
                        ensureHasDeviceOwnerAnnotation.isPrimary(),
                        new HashSet<>(
                                Arrays.asList(ensureHasDeviceOwnerAnnotation.affiliationIds())));
                continue;
            }

            if (annotation instanceof EnsureHasNoDelegate) {
                EnsureHasNoDelegate ensureHasNoDelegateAnnotation =
                        (EnsureHasNoDelegate) annotation;
                ensureHasNoDelegate(ensureHasNoDelegateAnnotation.admin());
                continue;
            }

            if (annotation instanceof EnsureHasNoDeviceOwner) {
                ensureHasNoDeviceOwner();
                continue;
            }

            if (annotation instanceof RequireFeature) {
                RequireFeature requireFeatureAnnotation = (RequireFeature) annotation;
                requireFeature(
                        requireFeatureAnnotation.value(),
                        requireFeatureAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof RequireDoesNotHaveFeature) {
                RequireDoesNotHaveFeature requireDoesNotHaveFeatureAnnotation =
                        (RequireDoesNotHaveFeature) annotation;
                requireDoesNotHaveFeature(
                        requireDoesNotHaveFeatureAnnotation.value(),
                        requireDoesNotHaveFeatureAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof EnsureHasProfileOwner) {
                EnsureHasProfileOwner ensureHasProfileOwnerAnnotation =
                        (EnsureHasProfileOwner) annotation;
                ensureHasProfileOwner(ensureHasProfileOwnerAnnotation.onUser(),
                        ensureHasProfileOwnerAnnotation.isPrimary(),
                        new HashSet<>(Arrays.asList(ensureHasProfileOwnerAnnotation.affiliationIds())));
                continue;
            }

            if (annotationType.equals(EnsureHasNoProfileOwner.class)) {
                EnsureHasNoProfileOwner ensureHasNoProfileOwnerAnnotation =
                        (EnsureHasNoProfileOwner) annotation;
                ensureHasNoProfileOwner(ensureHasNoProfileOwnerAnnotation.onUser());
                continue;
            }

            if (annotation instanceof RequireUserSupported) {
                RequireUserSupported requireUserSupportedAnnotation =
                        (RequireUserSupported) annotation;
                requireUserSupported(
                        requireUserSupportedAnnotation.value(),
                        requireUserSupportedAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof RequireGmsInstrumentation) {
                RequireGmsInstrumentation requireGmsInstrumentationAnnotation =
                        (RequireGmsInstrumentation) annotation;
                requireGmsInstrumentation(requireGmsInstrumentationAnnotation.min(),
                        requireGmsInstrumentationAnnotation.max());
                continue;
            }

            if (annotation instanceof RequireLowRamDevice) {
                RequireLowRamDevice requireLowRamDeviceAnnotation =
                        (RequireLowRamDevice) annotation;
                requireLowRamDevice(requireLowRamDeviceAnnotation.reason(),
                        requireLowRamDeviceAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof RequireNotLowRamDevice) {
                RequireNotLowRamDevice requireNotLowRamDeviceAnnotation =
                        (RequireNotLowRamDevice) annotation;
                requireNotLowRamDevice(requireNotLowRamDeviceAnnotation.reason(),
                        requireNotLowRamDeviceAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof RequireSdkVersion) {
                RequireSdkVersion requireSdkVersionAnnotation =
                        (RequireSdkVersion) annotation;

                if (requireSdkVersionAnnotation.reason().isEmpty()) {
                    requireSdkVersion(
                            requireSdkVersionAnnotation.min(),
                            requireSdkVersionAnnotation.max(),
                            requireSdkVersionAnnotation.failureMode());
                } else {
                    requireSdkVersion(
                            requireSdkVersionAnnotation.min(),
                            requireSdkVersionAnnotation.max(),
                            requireSdkVersionAnnotation.failureMode(),
                            requireSdkVersionAnnotation.reason());
                }

                continue;
            }

            if (annotation instanceof RequirePackageInstalled) {
                RequirePackageInstalled requirePackageInstalledAnnotation =
                        (RequirePackageInstalled) annotation;
                requirePackageInstalled(
                        requirePackageInstalledAnnotation.value(),
                        requirePackageInstalledAnnotation.onUser(),
                        requirePackageInstalledAnnotation.failureMode());
                continue;
            }

            if (annotation instanceof RequirePackageNotInstalled) {
                RequirePackageNotInstalled requirePackageNotInstalledAnnotation =
                        (RequirePackageNotInstalled) annotation;
                requirePackageNotInstalled(
                        requirePackageNotInstalledAnnotation.value(),
                        requirePackageNotInstalledAnnotation.onUser(),
                        requirePackageNotInstalledAnnotation.failureMode()
                );
                continue;
            }

            if (annotation instanceof EnsurePackageNotInstalled) {
                EnsurePackageNotInstalled ensurePackageNotInstalledAnnotation =
                        (EnsurePackageNotInstalled) annotation;
                ensurePackageNotInstalled(
                        ensurePackageNotInstalledAnnotation.value(),
                        ensurePackageNotInstalledAnnotation.onUser()
                );
                continue;
            }

            if (annotation instanceof RequireNotHeadlessSystemUserMode) {
                requireNotHeadlessSystemUserMode();
                continue;
            }

            if (annotation instanceof RequireHeadlessSystemUserMode) {
                requireHeadlessSystemUserMode();
                continue;
            }

            if (annotation instanceof EnsureHasPermission) {
                EnsureHasPermission ensureHasPermissionAnnotation =
                        (EnsureHasPermission) annotation;

                for (String permission : ensureHasPermissionAnnotation.value()) {
                    ensureCanGetPermission(permission);
                }

                try {
                    if (permissionContext == null) {
                        permissionContext = TestApis.permissions().withPermission(
                                ensureHasPermissionAnnotation.value());
                    } else {
                        permissionContext = permissionContext.withPermission(
                                ensureHasPermissionAnnotation.value());
                    }
                } catch (NeneException e) {
                    failOrSkip("Error getting permission: " + e,
                            ensureHasPermissionAnnotation.failureMode());
                }
                continue;
            }

            if (annotation instanceof EnsureDoesNotHavePermission) {
                EnsureDoesNotHavePermission ensureDoesNotHavePermission =
                        (EnsureDoesNotHavePermission) annotation;

                try {
                    if (permissionContext == null) {
                        permissionContext = TestApis.permissions().withoutPermission(
                                ensureDoesNotHavePermission.value());
                    } else {
                        permissionContext = permissionContext.withoutPermission(
                                ensureDoesNotHavePermission.value());
                    }
                } catch (NeneException e) {
                    failOrSkip("Error denying permission: " + e,
                            ensureDoesNotHavePermission.failureMode());
                }
                continue;
            }
        }

        requireSdkVersion(/* min= */ mMinSdkVersionCurrentTest,
                /* max= */ Integer.MAX_VALUE, FailureMode.SKIP);

        if (!mHasRequireGmsInstrumentation) {
            // TODO(scottjonathan): Only enforce if we've configured GMS Instrumentation
            requireNoGmsInstrumentation();
        }

        return permissionContext;
    }

    private List<Annotation> getAnnotations(Description description) {
        if (mUsingBedsteadJUnit4 && description.isTest()) {
            // The annotations are already exploded for tests
            return new ArrayList<>(description.getAnnotations());
        }

        // Otherwise we should build a new collection by recursively gathering annotations
        // if we find any which don't work without the runner we should error and fail the test
        List<Annotation> annotations = new ArrayList<>();

        if (description.isTest()) {
            annotations =
                    new ArrayList<>(Arrays.asList(description.getTestClass().getAnnotations()));
        }

        annotations.addAll(description.getAnnotations());

        checkAnnotations(annotations);

        BedsteadJUnit4.resolveRecursiveAnnotations(annotations,
                /* parameterizedAnnotation= */ null);

        checkAnnotations(annotations);

        return annotations;
    }

    private void checkAnnotations(Collection<Annotation> annotations) {
        for (Annotation annotation : annotations) {
            if (annotation.annotationType().getAnnotation(RequiresBedsteadJUnit4.class) != null
                    || annotation.annotationType().getAnnotation(
                            ParameterizedAnnotation.class) != null) {
                throw new AssertionFailedError("Test is annotated "
                        + annotation.annotationType().getSimpleName()
                        + " which requires using the BedsteadJUnit4 test runner");
            }
        }
    }

    private Statement applySuite(Statement base, Description description) {
        return new Statement() {
            @Override
            public void evaluate() throws Throwable {
                checkValidAnnotations(description);

                TestClass testClass = new TestClass(description.getTestClass());

                PermissionContextImpl permissionContext = null;

                if (mSkipTests || mFailTests) {
                    Log.d(LOG_TAG, "Skipping suite setup and teardown due to skipTests: "
                            + mSkipTests + ", failTests: " + mFailTests);
                    base.evaluate();
                    return;
                }

                Log.d(LOG_TAG, "Preparing state for suite " + description.getClassName());

                Tags.clearTags();
                Tags.addTag(Tags.USES_DEVICESTATE);
                if (TestApis.packages().instrumented().isInstantApp()) {
                    Tags.addTag(Tags.INSTANT_APP);
                }

                try {
                    TestApis.users().setStopBgUsersOnSwitch(STOP_USER_ON_SWITCH_FALSE);

                    try {
                        List<Annotation> annotations =
                                new ArrayList<>(getAnnotations(description));
                        permissionContext = applyAnnotations(annotations);
                    } catch (AssumptionViolatedException e) {
                        Log.i(LOG_TAG, "Assumption failed during class setup", e);
                        mSkipTests = true;
                        mSkipTestsReason = e.getMessage();
                    } catch (AssertionError e) {
                        Log.i(LOG_TAG, "Assertion failed during class setup", e);
                        mFailTests = true;
                        mFailTestsReason = e.getMessage();
                    }

                    Log.d(LOG_TAG,
                            "Finished preparing state for suite "
                                    + description.getClassName());

                    if (!mSkipTests && !mFailTests) {
                        // Tests may be skipped during the class setup
                        runAnnotatedMethods(testClass, BeforeClass.class);
                    }

                    base.evaluate();
                } finally {
                    runAnnotatedMethods(testClass, AfterClass.class);

                    if (permissionContext != null) {
                        permissionContext.close();
                    }

                    if (!mSkipClassTeardown) {
                        teardownShareableState();
                    }

                    TestApis.users().setStopBgUsersOnSwitch(STOP_USER_ON_SWITCH_DEFAULT);
                }
            }
        };
    }

    private static final Map<Class<? extends Annotation>, Class<? extends Annotation>>
            BANNED_ANNOTATIONS_TO_REPLACEMENTS = getBannedAnnotationsToReplacements();
    private static Map<
            Class<? extends Annotation>,
            Class<? extends Annotation>> getBannedAnnotationsToReplacements() {
        Map<
                Class<? extends Annotation>,
                Class<? extends Annotation>> bannedAnnotationsToReplacements = new HashMap<>();
        bannedAnnotationsToReplacements.put(org.junit.BeforeClass.class, BeforeClass.class);
        bannedAnnotationsToReplacements.put(org.junit.AfterClass.class, AfterClass.class);
        return bannedAnnotationsToReplacements;
    }

    private void checkValidAnnotations(Description classDescription) {
        for (Method method : classDescription.getTestClass().getMethods()) {
            for (Map.Entry<
                    Class<? extends Annotation>,
                    Class<? extends Annotation>> bannedAnnotation
                    : BANNED_ANNOTATIONS_TO_REPLACEMENTS.entrySet()) {
                if (method.isAnnotationPresent(bannedAnnotation.getKey())) {
                    throw new IllegalStateException("Do not use "
                            + bannedAnnotation.getKey().getCanonicalName()
                            + " when using DeviceState, replace with "
                            + bannedAnnotation.getValue().getCanonicalName());
                }
            }

            if (method.getAnnotation(BeforeClass.class) != null
                    || method.getAnnotation(AfterClass.class) != null) {
                checkPublicStaticVoidNoArgs(method);
            }
        }
    }

    private void checkPublicStaticVoidNoArgs(Method method) {
        if (method.getParameterTypes().length > 0) {
            throw new IllegalStateException(
                    "Method " + method.getName() + " should have no parameters");
        }
        if (method.getReturnType() != Void.TYPE) {
            throw new IllegalStateException("Method " + method.getName() + "() should be void");
        }
        if (!Modifier.isStatic(method.getModifiers())) {
            throw new IllegalStateException("Method " + method.getName() + "() should be static");
        }
        if (!Modifier.isPublic(method.getModifiers())) {
            throw new IllegalStateException("Method " + method.getName() + "() should be public");
        }
    }

    private void runAnnotatedMethods(
            TestClass testClass, Class<? extends Annotation> annotation) throws Throwable {

        List<FrameworkMethod> methods = new ArrayList<>(testClass.getAnnotatedMethods(annotation));
        Collections.reverse(methods);
        for (FrameworkMethod method : methods) {
            try {
                method.invokeExplosively(testClass.getJavaClass());
            } catch (InvocationTargetException e) {
                throw e.getCause();
            }
        }
    }

    private void requireRunOnUser(String[] userTypes, OptionalBoolean switchedToUser) {
        UserReference instrumentedUser = TestApis.users().instrumented();

        assumeTrue("This test only runs on users of type " + Arrays.toString(userTypes),
                Arrays.stream(userTypes).anyMatch(i -> i.equals(instrumentedUser.type().name())));

        mUsers.put(instrumentedUser.type(), instrumentedUser);

        ensureSwitchedToUser(switchedToUser, instrumentedUser);
    }

    private void requireRunOnProfile(String userType,
            OptionalBoolean installInstrumentedAppInParent,
            boolean hasProfileOwner, boolean dpcIsPrimary,
            OptionalBoolean switchedToParentUser, Set<String> affiliationIds) {
        UserReference instrumentedUser = TestApis.users().instrumented();

        assumeTrue("This test only runs on users of type " + userType,
                instrumentedUser.type().name().equals(userType));

        if (!mProfiles.containsKey(instrumentedUser.type())) {
            mProfiles.put(instrumentedUser.type(), new HashMap<>());
        }

        mProfiles.get(instrumentedUser.type()).put(instrumentedUser.parent(), instrumentedUser);

        if (installInstrumentedAppInParent.equals(OptionalBoolean.TRUE)) {
            TestApis.packages().find(sContext.getPackageName()).installExisting(
                    instrumentedUser.parent());
        } else if (installInstrumentedAppInParent.equals(OptionalBoolean.FALSE)) {
            TestApis.packages().find(sContext.getPackageName()).uninstall(
                    instrumentedUser.parent());
        }

        if (hasProfileOwner) {
            ensureHasProfileOwner(instrumentedUser, dpcIsPrimary, affiliationIds);
        } else {
            ensureHasNoProfileOwner(instrumentedUser);
        }

        ensureSwitchedToUser(switchedToParentUser, instrumentedUser.parent());
    }

    private void ensureSwitchedToUser(OptionalBoolean switchedtoUser, UserReference user) {
        if (switchedtoUser.equals(OptionalBoolean.TRUE)) {
            switchToUser(user);
        } else if (switchedtoUser.equals(OptionalBoolean.FALSE)) {
            switchFromUser(user);
        }
    }

    private void requireFeature(String feature, FailureMode failureMode) {
        checkFailOrSkip("Device must have feature " + feature,
                TestApis.packages().features().contains(feature), failureMode);
    }

    private void requireDoesNotHaveFeature(String feature, FailureMode failureMode) {
        checkFailOrSkip("Device must not have feature " + feature,
                !TestApis.packages().features().contains(feature), failureMode);
    }

    private void requireNoGmsInstrumentation() {
        boolean instrumentingGms =
                TestApis.context().instrumentedContext().getPackageName().equals(GMS_PKG);

        checkFailOrSkip(
                "This test never runs using gms instrumentation",
                !instrumentingGms,
                FailureMode.SKIP
        );
    }

    private void requireGmsInstrumentation(int min, int max) {
        mHasRequireGmsInstrumentation = true;
        boolean instrumentingGms =
                TestApis.context().instrumentedContext().getPackageName().equals(GMS_PKG);

        if (meetsSdkVersionRequirements(min, max)) {
            checkFailOrSkip(
                    "For SDK versions between " + min +  " and " + max
                            + " (inclusive), this test only runs when using gms instrumentation",
                    instrumentingGms,
                    FailureMode.SKIP
            );
        } else {
            checkFailOrSkip(
                    "For SDK versions between " + min +  " and " + max
                            + " (inclusive), this test only runs when not using gms "
                            + "instrumentation",
                    !instrumentingGms,
                    FailureMode.SKIP
            );
        }
    }

    private void requireSdkVersion(int min, int max, FailureMode failureMode) {
        requireSdkVersion(min, max, failureMode,
                "Sdk version must be between " + min +  " and " + max + " (inclusive)");
    }

    private void requireSdkVersion(
            int min, int max, FailureMode failureMode, String failureMessage) {
        mMinSdkVersionCurrentTest = min;
        checkFailOrSkip(
                failureMessage + " (version is " + Build.VERSION.SDK_INT + ")",
                meetsSdkVersionRequirements(min, max),
                failureMode
        );
    }

    private com.android.bedstead.nene.users.UserType requireUserSupported(
            String userType, FailureMode failureMode) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                TestApis.users().supportedType(userType);

        checkFailOrSkip(
                "Device must support user type " + userType
                + " only supports: " + TestApis.users().supportedTypes(),
                resolvedUserType != null, failureMode);

        return resolvedUserType;
    }

    private void checkFailOrSkip(String message, boolean value, FailureMode failureMode) {
        if (failureMode.equals(FailureMode.FAIL)) {
            assertWithMessage(message).that(value).isTrue();
        } else if (failureMode.equals(FailureMode.SKIP)) {
            assumeTrue(message, value);
        } else {
            throw new IllegalStateException("Unknown failure mode: " + failureMode);
        }
    }

    private void failOrSkip(String message, FailureMode failureMode) {
        if (failureMode.equals(FailureMode.FAIL)) {
            throw new AssertionError(message);
        } else if (failureMode.equals(FailureMode.SKIP)) {
            throw new AssumptionViolatedException(message);
        } else {
            throw new IllegalStateException("Unknown failure mode: " + failureMode);
        }
    }

    public enum UserType {
        /** Only to be used with annotations. */
        ANY,
        SYSTEM_USER,
        CURRENT_USER,
        PRIMARY_USER,
        SECONDARY_USER,
        WORK_PROFILE,
        TV_PROFILE,
    }

    private static final String LOG_TAG = "DeviceState";

    private static final Context sContext = TestApis.context().instrumentedContext();

    private final Map<com.android.bedstead.nene.users.UserType, UserReference> mUsers =
            new HashMap<>();
    private final Map<com.android.bedstead.nene.users.UserType, Map<UserReference, UserReference>>
            mProfiles = new HashMap<>();
    private DevicePolicyController mDeviceOwner;
    private Map<UserReference, DevicePolicyController> mProfileOwners = new HashMap<>();
    private RemotePolicyManager mPrimaryPolicyManager;

    private final List<UserReference> mCreatedUsers = new ArrayList<>();
    private final List<UserBuilder> mRemovedUsers = new ArrayList<>();
    private final List<BlockingBroadcastReceiver> mRegisteredBroadcastReceivers = new ArrayList<>();
    private boolean mHasChangedDeviceOwner = false;
    private DevicePolicyController mOriginalDeviceOwner;
    private Map<UserReference, DevicePolicyController> mChangedProfileOwners = new HashMap<>();
    private UserReference mOriginalSwitchedUser;

    /**
     * Get the {@link UserReference} of the work profile for the current user.
     *
     * <p>If the current user is a work profile, then the current user will be returned.
     *
     * <p>This should only be used to get work profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed work profile
     */
    public UserReference workProfile() {
        return workProfile(/* forUser= */ UserType.CURRENT_USER);
    }

    /**
     * Get the {@link UserReference} of the work profile.
     *
     * <p>This should only be used to get work profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed work profile for the given user
     */
    public UserReference workProfile(UserType forUser) {
        return workProfile(resolveUserTypeToUser(forUser));
    }

    /**
     * Get the {@link UserReference} of the work profile.
     *
     * <p>This should only be used to get work profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed work profile for the given user
     */
    public UserReference workProfile(UserReference forUser) {
        return profile(MANAGED_PROFILE_TYPE_NAME, forUser);
    }

    /**
     * Get the {@link UserReference} of the profile of the given type for the given user.
     *
     * <p>This should only be used to get profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed profile for the given user
     */
    public UserReference profile(String profileType, UserType forUser) {
        return profile(profileType, resolveUserTypeToUser(forUser));
    }

    /**
     * Get the {@link UserReference} of the profile for the current user.
     *
     * <p>If the current user is a profile of the correct type, then the current user will be
     * returned.
     *
     * <p>This should only be used to get profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed profile
     */
    public UserReference profile(String profileType) {
        return profile(profileType, /* forUser= */ UserType.CURRENT_USER);
    }

    /**
     * Get the {@link UserReference} of the profile of the given type for the given user.
     *
     * <p>This should only be used to get profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed profile for the given user
     */
    public UserReference profile(String profileType, UserReference forUser) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                TestApis.users().supportedType(profileType);

        if (resolvedUserType == null) {
            throw new IllegalStateException("Can not have a profile of type " + profileType
                    + " as they are not supported on this device");
        }

        return profile(resolvedUserType, forUser);
    }

    /**
     * Get the {@link UserReference} of the profile of the given type for the given user.
     *
     * <p>This should only be used to get profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed profile for the given user
     */
    public UserReference profile(
            com.android.bedstead.nene.users.UserType userType, UserReference forUser) {
        if (userType == null || forUser == null) {
            throw new NullPointerException();
        }

        if (!mProfiles.containsKey(userType) || !mProfiles.get(userType).containsKey(forUser)) {
            UserReference parentUser = TestApis.users().instrumented().parent();

            if (parentUser != null) {
                if (mProfiles.containsKey(userType)
                        && mProfiles.get(userType).containsKey(parentUser)) {
                    return mProfiles.get(userType).get(parentUser);
                }
            }

            throw new IllegalStateException(
                    "No harrier-managed profile of type " + userType + ". This method should only"
                            + " be used when Harrier has been used to create the profile.");
        }

        return mProfiles.get(userType).get(forUser);
    }

    /**
     * Get the {@link UserReference} of the tv profile for the current user
     *
     * <p>This should only be used to get tv profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed tv profile
     */
    public UserReference tvProfile() {
        return tvProfile(/* forUser= */ UserType.CURRENT_USER);
    }

    /**
     * Get the {@link UserReference} of the tv profile.
     *
     * <p>This should only be used to get tv profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed tv profile
     */
    public UserReference tvProfile(UserType forUser) {
        return tvProfile(resolveUserTypeToUser(forUser));
    }

    /**
     * Get the {@link UserReference} of the tv profile.
     *
     * <p>This should only be used to get tv profiles managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed tv profile
     */
    public UserReference tvProfile(UserReference forUser) {
        return profile(TV_PROFILE_TYPE_NAME, forUser);
    }

    /**
     * Get the user ID of the first human user on the device.
     */
    public UserReference primaryUser() {
        return TestApis.users().all()
                .stream().filter(UserReference::isPrimary).findFirst()
                .orElseThrow(IllegalStateException::new);
    }

    /**
     * Get a secondary user.
     *
     * <p>This should only be used to get secondary users managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed secondary user
     */
    public UserReference secondaryUser() {
        return user(SECONDARY_USER_TYPE_NAME);
    }

    /**
     * Get a user of the given type.
     *
     * <p>This should only be used to get users managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed user of the correct type
     */
    public UserReference user(String userType) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                TestApis.users().supportedType(userType);

        if (resolvedUserType == null) {
            throw new IllegalStateException("Can not have a user of type " + userType
                    + " as they are not supported on this device");
        }

        return user(resolvedUserType);
    }

    /**
     * Get a user of the given type.
     *
     * <p>This should only be used to get users managed by Harrier (using either the
     * annotations or calls to the {@link DeviceState} class.
     *
     * @throws IllegalStateException if there is no harrier-managed user of the correct type
     */
    public UserReference user(com.android.bedstead.nene.users.UserType userType) {
        if (userType == null) {
            throw new NullPointerException();
        }

        if (!mUsers.containsKey(userType)) {
            throw new IllegalStateException(
                    "No harrier-managed user of type " + userType + ". This method should only be"
                            + "used when Harrier has been used to create the user.");
        }

        return mUsers.get(userType);
    }

    private UserReference ensureHasProfile(
            String profileType,
            OptionalBoolean installInstrumentedApp,
            UserType forUser,
            boolean hasProfileOwner,
            boolean profileOwnerIsPrimary,
            OptionalBoolean switchedToParentUser) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                requireUserSupported(profileType, FailureMode.SKIP);

        UserReference forUserReference = resolveUserTypeToUser(forUser);

        UserReference profile =
                TestApis.users().findProfileOfType(resolvedUserType, forUserReference);
        if (profile == null) {
            if (profileType.equals(MANAGED_PROFILE_TYPE_NAME)) {
                // DO + work profile isn't a valid state
                ensureHasNoDeviceOwner();
            }

            profile = createProfile(resolvedUserType, forUserReference);
        }

        profile.start();

        if (installInstrumentedApp.equals(OptionalBoolean.TRUE)) {
            TestApis.packages().find(sContext.getPackageName()).installExisting(profile);
        } else if (installInstrumentedApp.equals(OptionalBoolean.FALSE)) {
            TestApis.packages().find(sContext.getPackageName()).uninstall(profile);
        }

        if (!mProfiles.containsKey(resolvedUserType)) {
            mProfiles.put(resolvedUserType, new HashMap<>());
        }

        mProfiles.get(resolvedUserType).put(forUserReference, profile);

        if (hasProfileOwner) {
            ensureHasProfileOwner(profile, profileOwnerIsPrimary, /* affiliationIds= */ null);
        }

        ensureSwitchedToUser(switchedToParentUser, forUserReference);

        return profile;
    }

    private void ensureHasNoProfile(String profileType, UserType forUser) {
        UserReference forUserReference = resolveUserTypeToUser(forUser);
        com.android.bedstead.nene.users.UserType resolvedProfileType =
                TestApis.users().supportedType(profileType);

        if (resolvedProfileType == null) {
            // These profile types don't exist so there can't be any
            return;
        }

        UserReference profile =
                TestApis.users().findProfileOfType(
                        resolvedProfileType,
                        forUserReference);
        if (profile != null) {
            removeAndRecordUser(profile);
        }
    }

    private void ensureHasUser(
            String userType, OptionalBoolean installInstrumentedApp,
            OptionalBoolean switchedToUser) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                requireUserSupported(userType, FailureMode.SKIP);

        Collection<UserReference> users = TestApis.users().findUsersOfType(resolvedUserType);

        UserReference user = users.isEmpty() ? createUser(resolvedUserType)
                : users.iterator().next();

        user.start();

        if (installInstrumentedApp.equals(OptionalBoolean.TRUE)) {
            TestApis.packages().find(sContext.getPackageName()).installExisting(user);
        } else if (installInstrumentedApp.equals(OptionalBoolean.FALSE)) {
            TestApis.packages().find(sContext.getPackageName()).uninstall(user);
        }

        ensureSwitchedToUser(switchedToUser, user);

        mUsers.put(resolvedUserType, user);
    }

    /**
     * Ensure that there is no user of the given type.
     */
    private void ensureHasNoUser(String userType) {
        com.android.bedstead.nene.users.UserType resolvedUserType =
                TestApis.users().supportedType(userType);

        if (resolvedUserType == null) {
            // These user types don't exist so there can't be any
            return;
        }

        for (UserReference secondaryUser : TestApis.users().findUsersOfType(resolvedUserType)) {
            if (secondaryUser.equals(TestApis.users().instrumented())) {
                throw new AssumptionViolatedException(
                        "This test only runs on devices without a "
                                + userType + " user. But the instrumented user is " + userType);
            }
            removeAndRecordUser(secondaryUser);
        }
    }

    private void removeAndRecordUser(UserReference userReference) {
        if (userReference == null) {
            return; // Nothing to remove
        }

        switchFromUser(userReference);

        if (!mCreatedUsers.remove(userReference)) {
            mRemovedUsers.add(TestApis.users().createUser()
                    .name(userReference.name())
                    .type(userReference.type())
                    .parent(userReference.parent()));
        }

        userReference.remove();
    }

    public void requireCanSupportAdditionalUser() {
        int maxUsers = getMaxNumberOfUsersSupported();
        int currentUsers = TestApis.users().all().size();

        assumeTrue("The device does not have space for an additional user (" + currentUsers +
                " current users, " + maxUsers + " max users)", currentUsers + 1 <= maxUsers);
    }

    /**
     * Create and register a {@link BlockingBroadcastReceiver} which will be unregistered after the
     * test has run.
     */
    public BlockingBroadcastReceiver registerBroadcastReceiver(String action) {
        return registerBroadcastReceiver(action, /* checker= */ null);
    }

    /**
     * Create and register a {@link BlockingBroadcastReceiver} which will be unregistered after the
     * test has run.
     */
    public BlockingBroadcastReceiver registerBroadcastReceiver(
            String action, Function<Intent, Boolean> checker) {
        BlockingBroadcastReceiver broadcastReceiver =
                new BlockingBroadcastReceiver(mContext, action, checker);
        broadcastReceiver.register();
        mRegisteredBroadcastReceivers.add(broadcastReceiver);

        return broadcastReceiver;
    }

    private UserReference resolveUserTypeToUser(UserType userType) {
        switch (userType) {
            case SYSTEM_USER:
                return TestApis.users().system();
            case CURRENT_USER:
                return TestApis.users().instrumented();
            case PRIMARY_USER:
                return primaryUser();
            case SECONDARY_USER:
                return secondaryUser();
            case WORK_PROFILE:
                return workProfile();
            case TV_PROFILE:
                return tvProfile();
            case ANY:
                throw new IllegalStateException("ANY UserType can not be used here");
            default:
                throw new IllegalArgumentException("Unknown user type " + userType);
        }
    }

    private void teardownNonShareableState() {
        mProfiles.clear();
        mUsers.clear();

        for (BlockingBroadcastReceiver broadcastReceiver : mRegisteredBroadcastReceivers) {
            broadcastReceiver.unregisterQuietly();
        }
        mRegisteredBroadcastReceivers.clear();
        mPrimaryPolicyManager = null;
    }

    private Set<TestAppInstance> mInstalledTestApps = new HashSet<>();
    private Set<TestAppInstance> mUninstalledTestApps = new HashSet<>();

    private void teardownShareableState() {
        if (mOriginalSwitchedUser != null) {
            if (!mOriginalSwitchedUser.exists()) {
                Log.d(LOG_TAG, "Could not switch back to original user "
                        + mOriginalSwitchedUser
                        + " as it does not exist. Switching to initial instead.");
                TestApis.users().initial().switchTo();
            } else {
                mOriginalSwitchedUser.switchTo();
            }
            mOriginalSwitchedUser = null;
        }

        if (mHasChangedDeviceOwner) {
            if (mOriginalDeviceOwner == null) {
                if (mDeviceOwner != null) {
                    mDeviceOwner.remove();
                }
            } else if (!mOriginalDeviceOwner.equals(mDeviceOwner)) {
                mDeviceOwner.remove();
                TestApis.devicePolicy().setDeviceOwner(
                        mOriginalDeviceOwner.componentName());
            }
            mHasChangedDeviceOwner = false;
            mOriginalDeviceOwner = null;
        }

        for (Map.Entry<UserReference, DevicePolicyController> originalProfileOwner :
                mChangedProfileOwners.entrySet()) {

            ProfileOwner currentProfileOwner =
                    TestApis.devicePolicy().getProfileOwner(originalProfileOwner.getKey());

            if (Objects.equal(currentProfileOwner, originalProfileOwner.getValue())) {
                continue; // No need to restore
            }

            if (currentProfileOwner != null) {
                currentProfileOwner.remove();
            }

            if (originalProfileOwner.getValue() != null) {
                TestApis.devicePolicy().setProfileOwner(originalProfileOwner.getKey(),
                        originalProfileOwner.getValue().componentName());
            }
        }
        mChangedProfileOwners.clear();

        for (UserReference user : mCreatedUsers) {
            user.remove();
        }

        mCreatedUsers.clear();

        for (UserBuilder userBuilder : mRemovedUsers) {
            userBuilder.create();
        }

        mRemovedUsers.clear();

        for (TestAppInstance installedTestApp : mInstalledTestApps) {
            installedTestApp.uninstall();
        }
        mInstalledTestApps.clear();

        for (TestAppInstance uninstalledTestApp : mUninstalledTestApps) {
            uninstalledTestApp.testApp().install(uninstalledTestApp.user());
        }
        mUninstalledTestApps.clear();
    }

    private UserReference createProfile(
            com.android.bedstead.nene.users.UserType profileType, UserReference parent) {
        requireCanSupportAdditionalUser();
        try {
            UserReference user = TestApis.users().createUser()
                    .parent(parent)
                    .type(profileType)
                    .createAndStart();
            mCreatedUsers.add(user);
            return user;
        } catch (NeneException e) {
            throw new IllegalStateException("Error creating profile of type " + profileType, e);
        }
    }

    private UserReference createUser(com.android.bedstead.nene.users.UserType userType) {
        requireCanSupportAdditionalUser();
        try {
            UserReference user = TestApis.users().createUser()
                    .type(userType)
                    .createAndStart();
            mCreatedUsers.add(user);
            return user;
        } catch (NeneException e) {
            throw new IllegalStateException("Error creating user of type " + userType, e);
        }
    }

    private int getMaxNumberOfUsersSupported() {
        try {
            return ShellCommand.builder("pm get-max-users")
                    .validate((output) -> output.startsWith("Maximum supported users:"))
                    .executeAndParseOutput(
                            (output) -> Integer.parseInt(output.split(": ", 2)[1].trim()));
        } catch (AdbException e) {
            throw new IllegalStateException("Invalid command output", e);
        }
    }

    private void ensureHasDelegate(
            EnsureHasDelegate.AdminType adminType, List<String> scopes, boolean isPrimary) {
        RemotePolicyManager dpc = getDeviceAdmin(adminType);


        boolean specifiesAdminType = adminType != EnsureHasDelegate.AdminType.PRIMARY;
        boolean currentPrimaryPolicyManagerIsNotDelegator = mPrimaryPolicyManager != dpc;

        if (isPrimary && mPrimaryPolicyManager != null
                && (specifiesAdminType || currentPrimaryPolicyManagerIsNotDelegator)) {
            throw new IllegalStateException(
                    "Only one DPC can be marked as primary per test (current primary is "
                            + mPrimaryPolicyManager + ")");
        }

        if (!dpc.user().equals(TestApis.users().instrumented())) {
            // INTERACT_ACROSS_USERS_FULL is required for RemoteDPC
            ensureCanGetPermission(INTERACT_ACROSS_USERS_FULL);
        }

        ensureTestAppInstalled(RemoteDelegate.sTestApp, dpc.user());
        RemoteDelegate delegate = new RemoteDelegate(RemoteDelegate.sTestApp, dpc().user());
        dpc.devicePolicyManager().setDelegatedScopes(
                dpc.componentName(), delegate.packageName(), scopes);

        if (isPrimary) {
            mPrimaryPolicyManager = delegate;
        }
    }

    private void ensureHasNoDelegate(EnsureHasNoDelegate.AdminType adminType) {
        if (adminType == EnsureHasNoDelegate.AdminType.ANY) {
            for (UserReference user : TestApis.users().all()) {
                ensureTestAppNotInstalled(RemoteDelegate.sTestApp, user);
            }
            return;
        }
        RemotePolicyManager dpc =
                adminType == EnsureHasNoDelegate.AdminType.PRIMARY ? mPrimaryPolicyManager
                : adminType == EnsureHasNoDelegate.AdminType.DEVICE_OWNER ? deviceOwner()
                : adminType == EnsureHasNoDelegate.AdminType.PROFILE_OWNER ? profileOwner() : null;
        if (dpc == null) {
            throw new IllegalStateException("Unknown Admin Type " + adminType);
        }

        ensureTestAppNotInstalled(RemoteDelegate.sTestApp, dpc.user());
    }

    private RemotePolicyManager getDeviceAdmin(EnsureHasDelegate.AdminType adminType) {
        switch (adminType) {
            case DEVICE_OWNER:
                return deviceOwner();
            case PROFILE_OWNER:
                return profileOwner();
            case PRIMARY:
                return dpc();
            default:
                throw new IllegalStateException("Unknown device admin type " + adminType);
        }
    }

    private void ensureTestAppInstalled(TestApp testApp, UserReference user) {
        if (TestApis.packages().find(testApp.packageName()).installedOnUser(user)) {
            return;
        }

        mInstalledTestApps.add(testApp.install(user));
    }

    private void ensureTestAppNotInstalled(TestApp testApp, UserReference user) {
        if (!TestApis.packages().find(testApp.packageName()).installedOnUser(user)) {
            return;
        }

        TestAppInstance instance = testApp.instance(user);

        if (mInstalledTestApps.contains(instance)) {
            mInstalledTestApps.remove(instance);
        } else {
            mUninstalledTestApps.add(instance);
        }

        testApp.uninstall(user);
    }

    private void ensureHasDeviceOwner(FailureMode failureMode, boolean isPrimary,
            Set<String> affiliationIds) {
        // TODO(scottjonathan): Should support non-remotedpc device owner (default to remotedpc)

        UserReference userReference = TestApis.users().system();

        if (isPrimary && mPrimaryPolicyManager != null && !userReference.equals(
                mPrimaryPolicyManager.user())) {
            throw new IllegalStateException(
                    "Only one DPC can be marked as primary per test (current primary is "
                            + mPrimaryPolicyManager + ")");
        }
        if (!userReference.equals(TestApis.users().instrumented())) {
            // INTERACT_ACROSS_USERS_FULL is required for RemoteDPC
            ensureCanGetPermission(INTERACT_ACROSS_USERS_FULL);
        }

        DeviceOwner currentDeviceOwner = TestApis.devicePolicy().getDeviceOwner();

        if (currentDeviceOwner != null
                && currentDeviceOwner.componentName().equals(RemoteDpc.DPC_COMPONENT_NAME)) {
            mDeviceOwner = currentDeviceOwner;
        } else {
            UserReference instrumentedUser = TestApis.users().instrumented();

            if (!Versions.meetsMinimumSdkVersionRequirement(Build.VERSION_CODES.S)) {
                // Prior to S we can't set device owner if there are other users on the device

                if (instrumentedUser.id() != 0) {
                    // If we're not on the system user we can't reach the required state
                    throw new AssumptionViolatedException(
                            "Can't set Device Owner when running on non-system-user"
                                    + " on this version of Android");
                }

                for (UserReference u : TestApis.users().all()) {
                    if (u.equals(instrumentedUser)) {
                        // Can't remove the user we're running on
                        continue;
                    }
                    try {
                        removeAndRecordUser(u);
                    } catch (NeneException e) {
                        failOrSkip(
                                "Error removing user to prepare for DeviceOwner: " + e.toString(),
                                failureMode);
                    }
                }
            }

            // TODO(scottjonathan): Remove accounts
            ensureHasNoProfileOwner(userReference);

            if (!mHasChangedDeviceOwner) {
                mOriginalDeviceOwner = currentDeviceOwner;
                mHasChangedDeviceOwner = true;
            }

            mDeviceOwner = RemoteDpc.setAsDeviceOwner().devicePolicyController();
        }

        if (isPrimary) {
            mPrimaryPolicyManager = RemoteDpc.forDevicePolicyController(mDeviceOwner);
        }
        
        RemoteDpc.forDevicePolicyController(mDeviceOwner)
                .devicePolicyManager()
                .setAffiliationIds(REMOTE_DPC_COMPONENT_NAME, affiliationIds);
    }

    private void ensureHasProfileOwner(UserType onUser, boolean isPrimary, Set<String> affiliationIds) {
        // TODO(scottjonathan): Should support non-remotedpc profile owner (default to remotedpc)
        UserReference user = resolveUserTypeToUser(onUser);
        ensureHasProfileOwner(user, isPrimary, affiliationIds);
    }

    private void ensureHasProfileOwner(
            UserReference user, boolean isPrimary, Set<String> affiliationIds) {
        if (isPrimary && mPrimaryPolicyManager != null
                && !user.equals(mPrimaryPolicyManager.user())) {
            throw new IllegalStateException("Only one DPC can be marked as primary per test");
        }

        if (!user.equals(TestApis.users().instrumented())) {
            // INTERACT_ACROSS_USERS_FULL is required for RemoteDPC
            ensureCanGetPermission(INTERACT_ACROSS_USERS_FULL);
        }

        ProfileOwner currentProfileOwner = TestApis.devicePolicy().getProfileOwner(user);
        DeviceOwner currentDeviceOwner = TestApis.devicePolicy().getDeviceOwner();

        if (currentDeviceOwner != null && currentDeviceOwner.user().equals(user)) {
            // Can't have DO and PO on the same user
            ensureHasNoDeviceOwner();
        }

        if (currentProfileOwner != null
                && currentProfileOwner.componentName().equals(
                RemoteDpc.DPC_COMPONENT_NAME)) {
            mProfileOwners.put(user, currentProfileOwner);
        } else {
            if (!mChangedProfileOwners.containsKey(user)) {
                mChangedProfileOwners.put(user, currentProfileOwner);
            }

            mProfileOwners.put(user, RemoteDpc.setAsProfileOwner(user).devicePolicyController());
        }

        if (isPrimary) {
            mPrimaryPolicyManager = RemoteDpc.forDevicePolicyController(mProfileOwners.get(user));
        }

        if (affiliationIds != null) {
            RemoteDpc profileOwner = profileOwner(user);
            profileOwner.devicePolicyManager()
                    .setAffiliationIds(REMOTE_DPC_COMPONENT_NAME, affiliationIds);
        }
    }

    private void ensureHasNoDeviceOwner() {
        DeviceOwner deviceOwner = TestApis.devicePolicy().getDeviceOwner();

        if (deviceOwner == null) {
            return;
        }

        if (!mHasChangedDeviceOwner) {
            mOriginalDeviceOwner = deviceOwner;
            mHasChangedDeviceOwner = true;
        }

        mDeviceOwner = null;
        deviceOwner.remove();
    }

    private void ensureHasNoProfileOwner(UserType onUser) {
        UserReference user = resolveUserTypeToUser(onUser);

        ensureHasNoProfileOwner(user);
    }

    private void ensureHasNoProfileOwner(UserReference user) {

        ProfileOwner currentProfileOwner = TestApis.devicePolicy().getProfileOwner(user);

        if (currentProfileOwner == null) {
            return;
        }

        if (!mChangedProfileOwners.containsKey(user)) {
            mChangedProfileOwners.put(user, currentProfileOwner);
        }

        TestApis.devicePolicy().getProfileOwner(user).remove();
        mProfileOwners.remove(user);
    }

    /**
     * Get the {@link RemoteDpc} for the device owner controlled by Harrier.
     *
     * <p>If no Harrier-managed device owner exists, an exception will be thrown.
     *
     * <p>If the device owner is not a RemoteDPC then an exception will be thrown
     */
    public RemoteDpc deviceOwner() {
        if (mDeviceOwner == null) {
            throw new IllegalStateException("No Harrier-managed device owner. This method should "
                    + "only be used when Harrier was used to set the Device Owner.");
        }
        if (!mDeviceOwner.componentName().equals(REMOTE_DPC_COMPONENT_NAME)) {
            throw new IllegalStateException("The device owner is not a RemoteDPC."
                    + " You must use Nene to query for this device owner.");
        }

        return RemoteDpc.forDevicePolicyController(mDeviceOwner);
    }

    /**
     * Get the {@link RemoteDpc} for the profile owner on the current user controlled by Harrier.
     *
     * <p>If no Harrier-managed profile owner exists, an exception will be thrown.
     *
     * <p>If the profile owner is not a RemoteDPC then an exception will be thrown.
     */
    public RemoteDpc profileOwner() {
        return profileOwner(UserType.CURRENT_USER);
    }

    /**
     * Get the {@link RemoteDpc} for the profile owner on the given user controlled by Harrier.
     *
     * <p>If no Harrier-managed profile owner exists, an exception will be thrown.
     *
     * <p>If the profile owner is not a RemoteDPC then an exception will be thrown.
     */
    public RemoteDpc profileOwner(UserType onUser) {
        if (onUser == null) {
            throw new NullPointerException();
        }

        return profileOwner(resolveUserTypeToUser(onUser));
    }

    /**
     * Get the {@link RemoteDpc} for the profile owner on the given user controlled by Harrier.
     *
     * <p>If no Harrier-managed profile owner exists, an exception will be thrown.
     *
     * <p>If the profile owner is not a RemoteDPC then an exception will be thrown.
     */
    public RemoteDpc profileOwner(UserReference onUser) {
        if (onUser == null) {
            throw new NullPointerException();
        }

        if (!mProfileOwners.containsKey(onUser)) {
            throw new IllegalStateException("No Harrier-managed profile owner. This method should "
                    + "only be used when Harrier was used to set the Profile Owner.");
        }

        DevicePolicyController profileOwner = mProfileOwners.get(onUser);

        if (!profileOwner.componentName().equals(REMOTE_DPC_COMPONENT_NAME)) {
            throw new IllegalStateException("The profile owner is not a RemoteDPC."
                    + " You must use Nene to query for this profile owner.");
        }

        return RemoteDpc.forDevicePolicyController(profileOwner);
    }

    private void requirePackageInstalled(
            String packageName, UserType forUser, FailureMode failureMode) {

        Package pkg = TestApis.packages().find(packageName);

        if (forUser.equals(UserType.ANY)) {
            checkFailOrSkip(
                    packageName + " is required to be installed",
                    !pkg.installedOnUsers().isEmpty(),
                    failureMode);
        } else {
            checkFailOrSkip(
                    packageName + " is required to be installed for " + forUser,
                    pkg.installedOnUser(resolveUserTypeToUser(forUser)),
                    failureMode);
        }
    }

    private void requirePackageNotInstalled(
            String packageName, UserType forUser, FailureMode failureMode) {
        Package pkg = TestApis.packages().find(packageName);

        if (forUser.equals(UserType.ANY)) {
            checkFailOrSkip(
                    packageName + " is required to be not installed",
                    pkg.installedOnUsers().isEmpty(),
                    failureMode);
        } else {
            checkFailOrSkip(
                    packageName + " is required to be not installed for " + forUser,
                    !pkg.installedOnUser(resolveUserTypeToUser(forUser)),
                    failureMode);
        }
    }

    private void ensurePackageNotInstalled(
            String packageName, UserType forUser) {
        Package pkg = TestApis.packages().find(packageName);

        if (forUser.equals(UserType.ANY)) {
            pkg.uninstallFromAllUsers();
        } else {
            UserReference user = resolveUserTypeToUser(forUser);
            pkg.uninstall(user);
        }
    }

    /**
     * Get the most appropriate {@link RemotePolicyManager} instance for the device state.
     *
     * <p>This method should only be used by tests which are annotated with {@link PolicyTest}.
     *
     * <p>This may be a DPC, a delegate, or a normal app with or without given permissions.
     *
     * <p>If no policy manager is set as "primary" for the device state, then this method will first
     * check for a profile owner in the current user, or else check for a device owner.
     *
     * <p>If no Harrier-managed profile owner or device owner exists, an exception will be thrown.
     *
     * <p>If the profile owner or device owner is not a RemoteDPC then an exception will be thrown.
     */
    public RemotePolicyManager dpc() {
        if (mPrimaryPolicyManager != null) {
            return mPrimaryPolicyManager;
        }

        if (mProfileOwners.containsKey(TestApis.users().instrumented())) {
            DevicePolicyController profileOwner =
                    mProfileOwners.get(TestApis.users().instrumented());


            if (profileOwner.componentName().equals(REMOTE_DPC_COMPONENT_NAME)) {
                return RemoteDpc.forDevicePolicyController(profileOwner);
            }
        }

        if (mDeviceOwner != null) {
            if (mDeviceOwner.componentName().equals(REMOTE_DPC_COMPONENT_NAME)) {
                return RemoteDpc.forDevicePolicyController(mDeviceOwner);
            }

        }

        throw new IllegalStateException("No Harrier-managed profile owner or device owner.");
    }

    private void ensureCanGetPermission(String permission) {
        // TODO(scottjonathan): Apply gms permission switches automatically rather than hard-coding
        // TODO(scottjonathan): Add a config to only enforce gms permission when needed
        if (permission.equals(NOTIFY_PENDING_SYSTEM_UPDATE)) {
            requireGmsInstrumentation(1, Build.VERSION_CODES.R);
        }
        // TODO(scottjonathan): Apply version-specific constraints automatically
        if (permission.equals(INTERACT_ACROSS_USERS_FULL)) {
            requireSdkVersion(
                    Build.VERSION_CODES.Q, Integer.MAX_VALUE, FailureMode.SKIP,
                    "This test requires INTERACT_ACROSS_USERS_FULL which can only be used on Q+");
        }
    }

    private void switchToUser(UserReference user) {
        UserReference currentUser = TestApis.users().current();
        if (!currentUser.equals(user)) {
            if (mOriginalSwitchedUser == null) {
                mOriginalSwitchedUser = currentUser;
            }
            user.switchTo();
        }
    }

    private void switchFromUser(UserReference user) {
        UserReference currentUser = TestApis.users().current();
        if (!currentUser.equals(user)) {
            return;
        }

        // We need to find a different user to switch to
        // full users only, starting with lowest ID
        List<UserReference> users = new ArrayList<>(TestApis.users().all());
        users.sort(Comparator.comparingInt(UserReference::id));

        for (UserReference otherUser : users) {
            if (otherUser.equals(user)) {
                continue;
            }

            if (otherUser.parent() != null) {
                continue;
            }

            switchToUser(otherUser);
            return;
        }

        // There are no users to switch to so we'll create one
        ensureHasUser(SECONDARY_USER_TYPE_NAME,
                /* installInstrumentedApp= */ OptionalBoolean.ANY,
                /* switchedToUser= */ OptionalBoolean.TRUE);
    }

    private void requireNotHeadlessSystemUserMode() {
        assumeFalse("This test is not supported on headless system user devices",
                TestApis.users().isHeadlessSystemUserMode());
    }

    private void requireHeadlessSystemUserMode() {
        assumeTrue("This test is only supported on headless system user devices",
                TestApis.users().isHeadlessSystemUserMode());
    }

    private void requireLowRamDevice(String reason, FailureMode failureMode) {
        checkFailOrSkip(reason,
                TestApis.context().instrumentedContext()
                        .getSystemService(ActivityManager.class)
                        .isLowRamDevice(),
                failureMode);
    }

    private void requireNotLowRamDevice(String reason, FailureMode failureMode) {
        checkFailOrSkip(reason,
                !TestApis.context().instrumentedContext()
                        .getSystemService(ActivityManager.class)
                        .isLowRamDevice(),
                failureMode);
    }
}
