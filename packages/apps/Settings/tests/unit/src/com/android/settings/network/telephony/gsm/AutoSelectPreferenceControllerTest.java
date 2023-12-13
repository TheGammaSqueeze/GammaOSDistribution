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

package com.android.settings.network.telephony.gsm;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.fail;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.PersistableBundle;
import android.telephony.CarrierConfigManager;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;

import androidx.lifecycle.Lifecycle;
import androidx.preference.SwitchPreference;
import androidx.test.core.app.ApplicationProvider;
import androidx.test.ext.junit.runners.AndroidJUnit4;

import com.android.settings.testutils.ResourcesUtils;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Answers;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

@RunWith(AndroidJUnit4.class)
public class AutoSelectPreferenceControllerTest {
    private static final int SUB_ID = 2;
    private static final String OPERATOR_NAME = "T-mobile";

    @Mock(answer = Answers.RETURNS_DEEP_STUBS)
    private TelephonyManager mTelephonyManager;
    @Mock
    private SubscriptionManager mSubscriptionManager;
    @Mock
    private CarrierConfigManager mCarrierConfigManager;
    @Mock
    private ProgressDialog mProgressDialog;
    @Mock
    private Lifecycle mLifecycle;

    private PersistableBundle mCarrierConfig;
    private AutoSelectPreferenceController mController;
    private SwitchPreference mSwitchPreference;
    private Context mContext;


    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);

        mContext = spy(ApplicationProvider.getApplicationContext());

        when(mContext.getSystemService(TelephonyManager.class)).thenReturn(mTelephonyManager);
        when(mContext.getSystemService(SubscriptionManager.class)).thenReturn(mSubscriptionManager);
        when(mContext.getSystemService(CarrierConfigManager.class)).thenReturn(
            mCarrierConfigManager);
        when(mTelephonyManager.createForSubscriptionId(SUB_ID)).thenReturn(mTelephonyManager);

        mCarrierConfig = new PersistableBundle();
        mCarrierConfig.putBoolean(CarrierConfigManager.KEY_ONLY_AUTO_SELECT_IN_HOME_NETWORK_BOOL,
            true);
        when(mCarrierConfigManager.getConfigForSubId(SUB_ID)).thenReturn(mCarrierConfig);

        mSwitchPreference = new SwitchPreference(mContext);
        mController = new AutoSelectPreferenceController(mContext, "auto_select");
        mController.mProgressDialog = mProgressDialog;
        mController.mSwitchPreference = mSwitchPreference;
        mController.init(mLifecycle, SUB_ID);
    }

    @Test
    public void setChecked_isChecked_showProgressDialog() {
        when(mTelephonyManager.getNetworkSelectionMode()).thenReturn(
            TelephonyManager.NETWORK_SELECTION_MODE_AUTO);

        // Wait for asynchronous thread to finish, otherwise test will flake.
        Future thread = mController.setAutomaticSelectionMode();
        try {
            thread.get();
        } catch (ExecutionException | InterruptedException e) {
            e.printStackTrace();
            fail("Exception during automatic selection");
        }

        verify(mProgressDialog).show();
        verify(mTelephonyManager).setNetworkSelectionModeAutomatic();
    }

    @Test
    public void updateState_isRoaming_enabled() {
        when(mTelephonyManager.getServiceState().getRoaming()).thenReturn(true);

        mController.updateState(mSwitchPreference);

        assertThat(mSwitchPreference.isEnabled()).isTrue();
    }

    @Test
    public void updateState_notRoamingWithAutoSelectOn_disabled() {
        when(mTelephonyManager.getServiceState().getRoaming()).thenReturn(false);
        doReturn(OPERATOR_NAME).when(mTelephonyManager).getSimOperatorName();

        mController.updateState(mSwitchPreference);

        assertThat(mSwitchPreference.isEnabled()).isFalse();
        assertThat(mSwitchPreference.getSummary()).isEqualTo(
                ResourcesUtils.getResourcesString(mContext, "manual_mode_disallowed_summary",
                mTelephonyManager.getSimOperatorName()));
    }

    @Test
    public void init_carrierConfigNull_shouldNotCrash() {
        when(mCarrierConfigManager.getConfigForSubId(SUB_ID)).thenReturn(null);

        // Should not crash
        mController.init(mLifecycle, SUB_ID);
    }
}
