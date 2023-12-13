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

package com.android.car.pm;


import static org.mockito.Mockito.verify;

import android.car.AbstractExtendedMockitoCarServiceTestCase;
import android.view.accessibility.AccessibilityEvent;

import com.android.car.CarLocalServices;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.mockito.Mock;

@RunWith(JUnit4.class)
public class CarSafetyAccessibilityServiceTest extends AbstractExtendedMockitoCarServiceTestCase {
    @Mock
    private CarPackageManagerService mMockCarPackageManagerService;

    private CarSafetyAccessibilityService mCarSafetyAccessibilityService;

    @Before
    public void setup() {
        mockGetCarLocalService(CarPackageManagerService.class, mMockCarPackageManagerService);
        mCarSafetyAccessibilityService = new CarSafetyAccessibilityService();
    }

    @Test
    public void onAccessibilityEvent_carPackageManagerServiceNotified() {
        mCarSafetyAccessibilityService.onAccessibilityEvent(new AccessibilityEvent());

        verify(mMockCarPackageManagerService).onWindowChangeEvent();
    }

    @Override
    protected void onSessionBuilder(CustomMockitoSessionBuilder session) {
        session.spyStatic(CarLocalServices.class);
    }
}
