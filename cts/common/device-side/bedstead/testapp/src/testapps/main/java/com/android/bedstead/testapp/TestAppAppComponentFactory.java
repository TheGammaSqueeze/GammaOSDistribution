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

package com.android.bedstead.testapp;

import android.accounts.AccountManager;
import android.app.Activity;
import android.app.AppComponentFactory;
import android.app.Service;
import android.app.admin.DevicePolicyManager;
import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.CrossProfileApps;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.net.wifi.WifiManager;
import android.os.HardwarePropertiesManager;
import android.os.UserManager;
import android.security.KeyChain;
import android.util.Log;

import com.android.bedstead.testapp.processor.annotations.FrameworkClass;
import com.android.bedstead.testapp.processor.annotations.TestAppReceiver;

/**
 * An {@link AppComponentFactory} which redirects invalid class names to premade TestApp classes.
 */
@TestAppReceiver(
        frameworkClasses = {
                @FrameworkClass(frameworkClass = DevicePolicyManager.class, constructor = "context.getSystemService(android.app.admin.DevicePolicyManager.class)"),
                @FrameworkClass(frameworkClass = HardwarePropertiesManager.class, constructor = "context.getSystemService(android.os.HardwarePropertiesManager.class)"),
                @FrameworkClass(frameworkClass = UserManager.class, constructor = "context.getSystemService(android.os.UserManager.class)"),
                @FrameworkClass(frameworkClass = WifiManager.class, constructor = "context.getSystemService(android.net.wifi.WifiManager.class)"),
                @FrameworkClass(frameworkClass = PackageManager.class, constructor = "context.getPackageManager()"),
                @FrameworkClass(frameworkClass = CrossProfileApps.class, constructor = "context.getSystemService(android.content.pm.CrossProfileApps.class)"),
                @FrameworkClass(frameworkClass = LauncherApps.class, constructor = "context.getSystemService(android.content.pm.LauncherApps.class)"),
                @FrameworkClass(frameworkClass = AccountManager.class, constructor = "context.getSystemService(android.accounts.AccountManager.class)"),
                @FrameworkClass(frameworkClass = Context.class, constructor = "context"),
                @FrameworkClass(frameworkClass = ContentResolver.class, constructor = "context.getContentResolver()"),
                @FrameworkClass(frameworkClass = KeyChain.class, constructor = "null") // KeyChain can not be instantiated - all calls are static
        }
)
public final class TestAppAppComponentFactory extends AppComponentFactory {

    private static final String LOG_TAG = "TestAppACF";

    @Override
    public Activity instantiateActivity(ClassLoader classLoader, String className, Intent intent)
            throws InstantiationException, IllegalAccessException, ClassNotFoundException {

        try {
            return super.instantiateActivity(classLoader, className, intent);
        } catch (ClassNotFoundException e) {
            Log.d(LOG_TAG,
                    "Activity class (" + className + ") not found, routing to TestAppActivity");
            BaseTestAppActivity activity =
                    (BaseTestAppActivity) super.instantiateActivity(
                            classLoader, BaseTestAppActivity.class.getName(), intent);
            activity.setOverrideActivityClassName(className);
            return activity;
        }
    }

    @Override
    public BroadcastReceiver instantiateReceiver(ClassLoader classLoader, String className,
            Intent intent)
            throws InstantiationException, IllegalAccessException, ClassNotFoundException {
        try {
            return super.instantiateReceiver(classLoader, className, intent);
        } catch (ClassNotFoundException e) {

            if (className.endsWith("DeviceAdminReceiver")) {
                Log.d(LOG_TAG, "Broadcast Receiver class (" + className
                        + ") not found, routing to TestAppDeviceAdminReceiver");
                BaseTestAppDeviceAdminReceiver receiver = (BaseTestAppDeviceAdminReceiver)
                        super.instantiateReceiver(
                                classLoader, BaseTestAppDeviceAdminReceiver.class.getName(),
                                intent);
                receiver.setOverrideDeviceAdminReceiverClassName(className);
                return receiver;
            }

            Log.d(LOG_TAG, "Broadcast Receiver class (" + className
                    + ") not found, routing to TestAppBroadcastReceiver");
            BaseTestAppBroadcastReceiver receiver = (BaseTestAppBroadcastReceiver)
                    super.instantiateReceiver(
                            classLoader, BaseTestAppBroadcastReceiver.class.getName(), intent);
            receiver.setOverrideBroadcastReceiverClassName(className);
            return receiver;
        }
    }

    @Override
    public Service instantiateService(ClassLoader classLoader, String className, Intent intent)
            throws InstantiationException, IllegalAccessException, ClassNotFoundException {
        try {
            return super.instantiateService(classLoader, className, intent);
        } catch (ClassNotFoundException e) {
            if (className.endsWith("AccountAuthenticatorService")) {
                Log.d(LOG_TAG, "Service class (" + className
                        + ") not found, routing to TestAppAccountAuthenticatorService");
                return super.instantiateService(
                        classLoader,
                        TestAppAccountAuthenticatorService.class.getName(),
                        intent);
            } else {
                throw e;
            }
        }
    }
}
