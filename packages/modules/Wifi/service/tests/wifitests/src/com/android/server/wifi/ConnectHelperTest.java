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

package com.android.server.wifi;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiManager;

import androidx.test.filters.SmallTest;

import com.android.server.wifi.util.ActionListenerWrapper;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

/** Unit tests for {@link ConnectHelper} */
@SmallTest
public class ConnectHelperTest extends WifiBaseTest {

    private static final int TEST_CALLING_UID = 1000;
    private static final int TEST_NETWORK_ID = 42;
    private static final String TEST_SSID = "TestSSID";

    private ConnectHelper mConnectHelper;

    @Mock
    private WifiConfigManager mWifiConfigManager;
    @Mock
    private ClientModeManager mClientModeManager;
    @Mock
    private ActionListenerWrapper mActionListener;

    private WifiConfiguration mWifiConfig;

    @Before
    public void setUp() throws Exception {
        MockitoAnnotations.initMocks(this);
        ActiveModeWarden activeModeWarden = mock(ActiveModeWarden.class);
        when(activeModeWarden.getPrimaryClientModeManager()).thenReturn(mClientModeManager);

        mConnectHelper = new ConnectHelper(activeModeWarden, mWifiConfigManager);
        mWifiConfig = new WifiConfiguration();
        mWifiConfig.SSID = TEST_SSID;
        mWifiConfig.networkId = TEST_NETWORK_ID;
    }

    @Test
    public void connectToNetwork_success() throws Exception {
        when(mWifiConfigManager.getConfiguredNetwork(TEST_NETWORK_ID)).thenReturn(mWifiConfig);

        NetworkUpdateResult result = new NetworkUpdateResult(TEST_NETWORK_ID);
        mConnectHelper.connectToNetwork(result, mActionListener, TEST_CALLING_UID);

        verify(mWifiConfigManager).updateBeforeConnect(TEST_NETWORK_ID, TEST_CALLING_UID);
        verify(mClientModeManager).connectNetwork(eq(result), any(), eq(TEST_CALLING_UID));
        // success is sent by ClientModeManager, not sent by ConnectHelper
        verify(mActionListener, never()).sendSuccess();
        verify(mActionListener, never()).sendFailure(anyInt());
    }

    @Test
    public void connectToNetwork_invalidNetId_failure() throws Exception {
        when(mWifiConfigManager.getConfiguredNetwork(TEST_NETWORK_ID)).thenReturn(null);

        mConnectHelper.connectToNetwork(new NetworkUpdateResult(TEST_NETWORK_ID), mActionListener,
                TEST_CALLING_UID);

        verify(mWifiConfigManager, never()).updateBeforeConnect(TEST_NETWORK_ID, TEST_CALLING_UID);
        verify(mClientModeManager, never()).connectNetwork(any(), any(), anyInt());
        verify(mActionListener).sendFailure(WifiManager.ERROR);
        verify(mActionListener, never()).sendSuccess();
    }
}
