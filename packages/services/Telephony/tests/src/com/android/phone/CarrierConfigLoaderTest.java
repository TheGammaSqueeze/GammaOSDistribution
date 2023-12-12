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

package com.android.phone;

import static com.android.TestContext.STUB_PERMISSION_ENABLE_ALL;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertThrows;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.ArgumentMatchers.nullable;
import static org.mockito.Mockito.doNothing;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.verify;

import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.os.Build;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.os.PersistableBundle;
import android.os.UserHandle;
import android.service.carrier.CarrierIdentifier;
import android.telephony.CarrierConfigManager;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.testing.TestableLooper;

import androidx.test.InstrumentationRegistry;
import androidx.test.ext.junit.runners.AndroidJUnit4;

import com.android.TelephonyTestBase;
import com.android.internal.telephony.IccCardConstants;
import com.android.internal.telephony.SubscriptionInfoUpdater;

import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.Mockito;

import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.List;

/**
 * Unit Test for CarrierConfigLoader.
 */
@RunWith(AndroidJUnit4.class)
public class CarrierConfigLoaderTest extends TelephonyTestBase {

    private static final int DEFAULT_PHONE_ID = 0;
    private static final int DEFAULT_SUB_ID = SubscriptionManager.getDefaultSubscriptionId();
    private static final String PLATFORM_CARRIER_CONFIG_PACKAGE = "com.android.carrierconfig";
    private static final long PLATFORM_CARRIER_CONFIG_PACKAGE_VERSION_CODE = 1;
    private static final String CARRIER_CONFIG_EXAMPLE_KEY =
            CarrierConfigManager.KEY_CARRIER_USSD_METHOD_INT;
    private static final int CARRIER_CONFIG_EXAMPLE_VALUE =
            CarrierConfigManager.USSD_OVER_CS_PREFERRED;

    @Mock Resources mResources;
    @Mock PackageManager mPackageManager;
    @Mock PackageInfo mPackageInfo;
    @Mock SubscriptionInfoUpdater mSubscriptionInfoUpdater;
    @Mock SharedPreferences mSharedPreferences;

    private TelephonyManager mTelephonyManager;
    private CarrierConfigLoader mCarrierConfigLoader;
    private Handler mHandler;
    private HandlerThread mHandlerThread;
    private TestableLooper mTestableLooper;

    @Before
    public void setUp() throws Exception {
        super.setUp();

        doReturn(mSharedPreferences).when(mContext).getSharedPreferences(anyString(), anyInt());
        doReturn(Build.FINGERPRINT).when(mSharedPreferences).getString(eq("build_fingerprint"),
                any());
        doReturn(mPackageManager).when(mContext).getPackageManager();
        doReturn(mResources).when(mContext).getResources();
        doReturn(InstrumentationRegistry.getTargetContext().getFilesDir()).when(
                mContext).getFilesDir();
        doReturn(PLATFORM_CARRIER_CONFIG_PACKAGE).when(mResources).getString(
                eq(R.string.platform_carrier_config_package));
        mTelephonyManager = mContext.getSystemService(TelephonyManager.class);
        doReturn(1).when(mTelephonyManager).getSupportedModemCount();
        doReturn(1).when(mTelephonyManager).getActiveModemCount();
        doReturn("spn").when(mTelephonyManager).getSimOperatorNameForPhone(anyInt());
        doReturn("310260").when(mTelephonyManager).getSimOperatorNumericForPhone(anyInt());
        doReturn(mPackageInfo).when(mPackageManager).getPackageInfo(
                eq(PLATFORM_CARRIER_CONFIG_PACKAGE), eq(0) /*flags*/);
        doReturn(PLATFORM_CARRIER_CONFIG_PACKAGE_VERSION_CODE).when(
                mPackageInfo).getLongVersionCode();

        mHandlerThread = new HandlerThread("CarrierConfigLoaderTest");
        mHandlerThread.start();

        mTestableLooper = new TestableLooper(mHandlerThread.getLooper());
        mCarrierConfigLoader = new CarrierConfigLoader(mContext, mSubscriptionInfoUpdater,
                mTestableLooper.getLooper());
        mHandler = mCarrierConfigLoader.getHandler();

        // Clear all configs to have the same starting point.
        mCarrierConfigLoader.clearConfigForPhone(DEFAULT_PHONE_ID, false);
    }

    @After
    public void tearDown() throws Exception {
        mContext.revokeAllPermissions();
        mTestableLooper.destroy();
        mHandlerThread.quit();
        super.tearDown();
    }

    /**
     * Verifies that SecurityException should throw when call #updateConfigForPhoneId() without
     * MODIFY_PHONE_STATE permission.
     */
    @Test
    public void testUpdateConfigForPhoneId_noPermission() throws Exception {
        assertThrows(SecurityException.class,
                () -> mCarrierConfigLoader.updateConfigForPhoneId(DEFAULT_PHONE_ID,
                        IccCardConstants.INTENT_VALUE_ICC_ABSENT));
    }

    /**
     * Verifies that IllegalArgumentException should throw when call #updateConfigForPhoneId() with
     * invalid phoneId.
     */
    @Test
    public void testUpdateConfigForPhoneId_invalidPhoneId() throws Exception {
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        assertThrows(IllegalArgumentException.class,
                () -> mCarrierConfigLoader.updateConfigForPhoneId(
                        SubscriptionManager.INVALID_PHONE_INDEX,
                        IccCardConstants.INTENT_VALUE_ICC_ABSENT));
    }

    /**
     * Verifies that when call #updateConfigForPhoneId() with SIM absence, both carrier config from
     * default app and carrier should be cleared but no-sim config should be loaded.
     */
    @Test
    public void testUpdateConfigForPhoneId_simAbsent() throws Exception {
        // Bypass case if default subId is not supported by device to reduce flakiness
        if (!SubscriptionManager.isValidPhoneId(SubscriptionManager.getPhoneId(DEFAULT_SUB_ID))) {
            return;
        }
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);
        doNothing().when(mContext).sendBroadcastAsUser(any(Intent.class), any(UserHandle.class));

        // Prepare a cached config to fetch from xml
        PersistableBundle config = getTestConfig();
        mCarrierConfigLoader.saveNoSimConfigToXml(PLATFORM_CARRIER_CONFIG_PACKAGE, config);
        mCarrierConfigLoader.updateConfigForPhoneId(DEFAULT_PHONE_ID,
                IccCardConstants.INTENT_VALUE_ICC_ABSENT);
        mTestableLooper.processAllMessages();

        assertThat(mCarrierConfigLoader.getConfigFromDefaultApp(DEFAULT_PHONE_ID)).isNull();
        assertThat(mCarrierConfigLoader.getConfigFromCarrierApp(DEFAULT_PHONE_ID)).isNull();
        assertThat(mCarrierConfigLoader.getNoSimConfig().getInt(CARRIER_CONFIG_EXAMPLE_KEY))
                .isEqualTo(CARRIER_CONFIG_EXAMPLE_VALUE);
        verify(mContext).sendBroadcastAsUser(any(Intent.class), any(UserHandle.class));
    }

    /**
     * Verifies that with cached config in XML, calling #updateConfigForPhoneId() with SIM loaded
     * will return the right config in the XML.
     */
    @Test
    public void testUpdateConfigForPhoneId_simLoaded_withCachedConfigInXml() throws Exception {
        // Bypass case if default subId is not supported by device to reduce flakiness
        if (!SubscriptionManager.isValidPhoneId(SubscriptionManager.getPhoneId(DEFAULT_SUB_ID))) {
            return;
        }
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        // Prepare to make sure we can save the config into the XML file which used as cache
        List<String> carrierPackages = List.of(PLATFORM_CARRIER_CONFIG_PACKAGE);
        doReturn(carrierPackages).when(mTelephonyManager).getCarrierPackageNamesForIntentAndPhone(
                nullable(Intent.class), anyInt());

        // Save the sample config into the XML file
        PersistableBundle config = getTestConfig();
        CarrierIdentifier carrierId = mCarrierConfigLoader.getCarrierIdentifierForPhoneId(
                DEFAULT_PHONE_ID);
        mCarrierConfigLoader.saveConfigToXml(PLATFORM_CARRIER_CONFIG_PACKAGE, "",
                DEFAULT_PHONE_ID, carrierId, config);
        mCarrierConfigLoader.updateConfigForPhoneId(DEFAULT_PHONE_ID,
                IccCardConstants.INTENT_VALUE_ICC_LOADED);
        mTestableLooper.processAllMessages();

        assertThat(mCarrierConfigLoader.getConfigFromDefaultApp(DEFAULT_PHONE_ID).getInt(
                CARRIER_CONFIG_EXAMPLE_KEY)).isEqualTo(CARRIER_CONFIG_EXAMPLE_VALUE);

    }

    /**
     * Verifies that SecurityException should throw if call #overrideConfig() without
     * MODIFY_PHONE_STATE permission.
     */
    @Test
    public void testOverrideConfig_noPermission() throws Exception {
        assertThrows(SecurityException.class,
                () -> mCarrierConfigLoader.overrideConfig(DEFAULT_SUB_ID, PersistableBundle.EMPTY,
                        false));
    }

    /**
     * Verifies IllegalArgumentException should throw if call #overrideConfig() with invalid subId.
     */
    @Test
    public void testOverrideConfig_invalidSubId() throws Exception {
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        assertThrows(IllegalArgumentException.class, () -> mCarrierConfigLoader.overrideConfig(
                SubscriptionManager.INVALID_SUBSCRIPTION_ID, new PersistableBundle(), false));
    }

    /**
     * Verifies that override config is not null when calling #overrideConfig with null bundle.
     */
    @Test
    public void testOverrideConfig_withNullBundle() throws Exception {
        // Bypass case if default subId is not supported by device to reduce flakiness
        if (!SubscriptionManager.isValidPhoneId(SubscriptionManager.getPhoneId(DEFAULT_SUB_ID))) {
            return;
        }
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        mCarrierConfigLoader.overrideConfig(DEFAULT_SUB_ID, null /*overrides*/,
                false/*persistent*/);
        mTestableLooper.processAllMessages();

        assertThat(mCarrierConfigLoader.getOverrideConfig(DEFAULT_PHONE_ID).isEmpty()).isTrue();
        verify(mSubscriptionInfoUpdater).updateSubscriptionByCarrierConfigAndNotifyComplete(
                eq(DEFAULT_PHONE_ID), eq(PLATFORM_CARRIER_CONFIG_PACKAGE),
                any(PersistableBundle.class), any(Message.class));
    }

    /**
     * Verifies that override config is not null when calling #overrideConfig with non-null bundle.
     */
    @Test
    public void testOverrideConfig_withNonNullBundle() throws Exception {
        // Bypass case if default subId is not supported by device to reduce flakiness
        if (!SubscriptionManager.isValidPhoneId(SubscriptionManager.getPhoneId(DEFAULT_SUB_ID))) {
            return;
        }
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        PersistableBundle config = getTestConfig();
        mCarrierConfigLoader.overrideConfig(DEFAULT_SUB_ID, config /*overrides*/,
                false/*persistent*/);
        mTestableLooper.processAllMessages();

        assertThat(mCarrierConfigLoader.getOverrideConfig(DEFAULT_PHONE_ID).getInt(
                CARRIER_CONFIG_EXAMPLE_KEY)).isEqualTo(CARRIER_CONFIG_EXAMPLE_VALUE);
        verify(mSubscriptionInfoUpdater).updateSubscriptionByCarrierConfigAndNotifyComplete(
                eq(DEFAULT_PHONE_ID), eq(PLATFORM_CARRIER_CONFIG_PACKAGE),
                any(PersistableBundle.class), any(Message.class));
    }

    /**
     * Verifies that IllegalArgumentException should throw when calling
     * #notifyConfigChangedForSubId() with invalid subId.
     */
    @Test
    public void testNotifyConfigChangedForSubId_invalidSubId() throws Exception {
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        assertThrows(IllegalArgumentException.class,
                () -> mCarrierConfigLoader.notifyConfigChangedForSubId(
                        SubscriptionManager.INVALID_SUBSCRIPTION_ID));
    }

    // TODO(b/184040111): Enable test case when support disabling carrier privilege
    // Phone/System UID always has carrier privilege (TelephonyPermission#getCarrierPrivilegeStatus)
    // when running the test here.
    /**
     * Verifies that SecurityException should throw when calling notifyConfigChangedForSubId without
     * MODIFY_PHONE_STATE permission.
     */
    @Ignore
    public void testNotifyConfigChangedForSubId_noPermission() throws Exception {
        setCarrierPrivilegesForSubId(false, DEFAULT_SUB_ID);

        assertThrows(SecurityException.class,
                () -> mCarrierConfigLoader.notifyConfigChangedForSubId(DEFAULT_SUB_ID));
    }

    /**
     * Verifies that SecurityException should throw when calling getDefaultCarrierServicePackageName
     * without READ_PRIVILEGED_PHONE_STATE permission.
     */
    @Test
    public void testGetDefaultCarrierServicePackageName_noPermission() {
        assertThrows(SecurityException.class,
                () -> mCarrierConfigLoader.getDefaultCarrierServicePackageName());
    }

    /**
     * Verifies that the right default carrier service package name is return when calling
     * getDefaultCarrierServicePackageName with permission.
     */
    @Test
    public void testGetDefaultCarrierServicePackageName_withPermission() {
        mContext.grantPermission(STUB_PERMISSION_ENABLE_ALL);

        assertThat(mCarrierConfigLoader.getDefaultCarrierServicePackageName())
                .isEqualTo(PLATFORM_CARRIER_CONFIG_PACKAGE);
    }

    // TODO(b/184040111): Enable test case when support disabling carrier privilege
    // Phone/System UID always has carrier privilege (TelephonyPermission#getCarrierPrivilegeStatus)
    // when running the test here.
    /**
     * Verifies that without permission, #getConfigForSubId will return an empty PersistableBundle.
     */
    @Ignore
    public void testGetConfigForSubId_noPermission() {
        // Bypass case if default subId is not supported by device to reduce flakiness
        if (!SubscriptionManager.isValidPhoneId(SubscriptionManager.getPhoneId(DEFAULT_SUB_ID))) {
            return;
        }
        setCarrierPrivilegesForSubId(false, DEFAULT_SUB_ID);

        assertThat(mCarrierConfigLoader.getConfigForSubId(DEFAULT_SUB_ID,
                PLATFORM_CARRIER_CONFIG_PACKAGE)).isEqualTo(PersistableBundle.EMPTY);
    }

    /**
     * Verifies that when have no DUMP permission, the #dump() method shows permission denial.
     */
    @Test
    public void testDump_noPermission() {
        StringWriter stringWriter = new StringWriter();
        mCarrierConfigLoader.dump(new FileDescriptor(), new PrintWriter(stringWriter),
                new String[0]);
        stringWriter.flush();

        assertThat(stringWriter.toString()).contains("Permission Denial:");
    }

    /**
     * Verifies that when have DUMP permission, the #dump() method can dump the CarrierConfigLoader.
     */
    @Test
    public void testDump_withPermission() {
        mContext.grantPermission(android.Manifest.permission.DUMP);

        StringWriter stringWriter = new StringWriter();
        mCarrierConfigLoader.dump(new FileDescriptor(), new PrintWriter(stringWriter),
                new String[0]);
        stringWriter.flush();

        String dumpContent = stringWriter.toString();
        assertThat(dumpContent).contains("CarrierConfigLoader:");
        assertThat(dumpContent).doesNotContain("Permission Denial:");
    }

    private static PersistableBundle getTestConfig() {
        PersistableBundle config = new PersistableBundle();
        config.putInt(CARRIER_CONFIG_EXAMPLE_KEY, CARRIER_CONFIG_EXAMPLE_VALUE);
        return config;
    }

    private void setCarrierPrivilegesForSubId(boolean hasCarrierPrivileges, int subId) {
        TelephonyManager mockTelephonyManager = Mockito.mock(TelephonyManager.class);
        doReturn(mockTelephonyManager).when(mTelephonyManager).createForSubscriptionId(subId);
        doReturn(hasCarrierPrivileges ? TelephonyManager.CARRIER_PRIVILEGE_STATUS_HAS_ACCESS
                : TelephonyManager.CARRIER_PRIVILEGE_STATUS_NO_ACCESS).when(
                mockTelephonyManager).getCarrierPrivilegeStatus(anyInt());
    }
}
