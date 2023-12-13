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

package com.android.settings.biometrics.combination;

import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.any;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.reset;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.content.Context;
import android.content.pm.PackageManager;
import android.hardware.face.FaceManager;
import android.hardware.fingerprint.FingerprintManager;
import android.os.UserManager;

import androidx.lifecycle.LifecycleOwner;
import androidx.preference.Preference;

import com.android.internal.widget.LockPatternUtils;
import com.android.settings.testutils.FakeFeatureFactory;
import com.android.settingslib.RestrictedLockUtils;
import com.android.settingslib.RestrictedPreference;
import com.android.settingslib.core.lifecycle.Lifecycle;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.RuntimeEnvironment;
import org.robolectric.shadows.ShadowApplication;

@RunWith(RobolectricTestRunner.class)
public class CombinedBiometricStatusPreferenceControllerTest {

    private static final String TEST_PREF_KEY = "foo";

    @Mock
    private LockPatternUtils mLockPatternUtils;
    @Mock
    private FingerprintManager mFingerprintManager;
    @Mock
    private FaceManager mFaceManager;
    @Mock
    private UserManager mUm;
    @Mock
    private PackageManager mPackageManager;

    private FakeFeatureFactory mFeatureFactory;
    private Context mContext;
    private CombinedBiometricStatusPreferenceController mController;
    private Preference mPreference;
    private Lifecycle mLifecycle;
    private LifecycleOwner mLifecycleOwner;

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);
        mContext = spy(RuntimeEnvironment.application);
        mLifecycleOwner = () -> mLifecycle;
        mLifecycle = new Lifecycle(mLifecycleOwner);
        when(mContext.getPackageManager()).thenReturn(mPackageManager);
        when(mPackageManager.hasSystemFeature(PackageManager.FEATURE_FINGERPRINT)).thenReturn(true);
        when(mPackageManager.hasSystemFeature(PackageManager.FEATURE_FACE)).thenReturn(true);
        ShadowApplication.getInstance().setSystemService(Context.FINGERPRINT_SERVICE,
                mFingerprintManager);
        ShadowApplication.getInstance().setSystemService(Context.FACE_SERVICE, mFaceManager);
        ShadowApplication.getInstance().setSystemService(Context.USER_SERVICE, mUm);
        mPreference = new Preference(mContext);
        mFeatureFactory = FakeFeatureFactory.setupForTest();
        when(mFeatureFactory.securityFeatureProvider.getLockPatternUtils(mContext))
                .thenReturn(mLockPatternUtils);
        when(mUm.getProfileIdsWithDisabled(anyInt())).thenReturn(new int[] {1234});
        mController = new CombinedBiometricStatusPreferenceController(
                mContext, TEST_PREF_KEY, mLifecycle);
    }

    @Test
    public void updateState_parentalConsentRequired_preferenceDisabled() {
        when(mFaceManager.isHardwareDetected()).thenReturn(true);
        when(mFingerprintManager.isHardwareDetected()).thenReturn(true);

        RestrictedPreference restrictedPreference = mock(RestrictedPreference.class);
        RestrictedLockUtils.EnforcedAdmin admin = mock(RestrictedLockUtils.EnforcedAdmin.class);

        mController.mPreference = restrictedPreference;
        mController.updateStateInternal(admin, true, true);
        verify(restrictedPreference).setDisabledByAdmin(eq(admin));

        mController.updateStateInternal(admin, true, false);
        verify(restrictedPreference).setDisabledByAdmin(eq(null));

        mController.updateStateInternal(admin, false, true);
        verify(restrictedPreference).setDisabledByAdmin(eq(null));

        mController.updateStateInternal(admin, false, false);
        verify(restrictedPreference).setDisabledByAdmin(eq(null));
    }
}
