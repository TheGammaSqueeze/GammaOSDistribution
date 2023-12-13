/*
 * Copyright (C) 2022 The Android Open Source Project
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

package com.android.car.telemetry.sessioncontroller;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertThrows;

import android.os.PersistableBundle;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.junit.MockitoJUnitRunner;

@RunWith(MockitoJUnitRunner.class)
public class SessionAnnotationUnitTest {
    private static final int SESSION_ID = 1;
    private static final int SESSION_STATE = SessionController.STATE_ENTER_DRIVING_SESSION;
    private static final long CREATED_AT_SINCE_BOOT_MILLIS = 123;
    private static final long CREATED_AT_MILLIS = 123123;
    private static final String BOOT_REASON = "reboot";

    private static final SessionAnnotation sAnnotation = new SessionAnnotation(SESSION_ID,
            SESSION_STATE,
            CREATED_AT_SINCE_BOOT_MILLIS, CREATED_AT_MILLIS, BOOT_REASON);

    @Test
    public void testToPersistableBundle_populatesBundle() {
        PersistableBundle result = sAnnotation.toPersistableBundle();

        assertThat(result.getInt(SessionAnnotation.ANNOTATION_BUNDLE_KEY_SESSION_ID)).isEqualTo(
                SESSION_ID);
        assertThat(result.getInt(SessionAnnotation.ANNOTATION_BUNDLE_KEY_SESSION_STATE)).isEqualTo(
                SESSION_STATE);
        assertThat(result.getLong(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_CREATED_AT_SINCE_BOOT_MILLIS)).isEqualTo(
                CREATED_AT_SINCE_BOOT_MILLIS);
        assertThat(result.getLong(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_CREATED_AT_MILLIS)).isEqualTo(
                CREATED_AT_MILLIS);
        assertThat(result.getString(SessionAnnotation.ANNOTATION_BUNDLE_KEY_BOOT_REASON)).isEqualTo(
                BOOT_REASON);
    }

    @Test
    public void testAddAnnotationsToBundle_addsPopulatedBundle() {
        PersistableBundle data = new PersistableBundle();

        sAnnotation.addAnnotationsToBundle(data);

        assertThat(data.containsKey(SessionAnnotation.ANNOTATION_BUNDLE_KEY_ROOT)).isTrue();
        PersistableBundle conversionResult = data.getPersistableBundle(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_ROOT);
        assertThat(conversionResult.getInt(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_SESSION_ID)).isEqualTo(
                SESSION_ID);
        assertThat(conversionResult.getInt(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_SESSION_STATE)).isEqualTo(
                SESSION_STATE);
        assertThat(conversionResult.getLong(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_CREATED_AT_SINCE_BOOT_MILLIS)).isEqualTo(
                CREATED_AT_SINCE_BOOT_MILLIS);
        assertThat(
                conversionResult.getLong(
                        SessionAnnotation.ANNOTATION_BUNDLE_KEY_CREATED_AT_MILLIS)).isEqualTo(
                CREATED_AT_MILLIS);
        assertThat(conversionResult.getString(
                SessionAnnotation.ANNOTATION_BUNDLE_KEY_BOOT_REASON)).isEqualTo(
                BOOT_REASON);
    }

    @Test
    public void testAddAnnotationsToBundle_throwsExceptionIfKeyExists() {
        PersistableBundle data = new PersistableBundle();
        data.putInt(SessionAnnotation.ANNOTATION_BUNDLE_KEY_ROOT, 100);

        assertThrows(IllegalArgumentException.class,
                () -> sAnnotation.addAnnotationsToBundle(data));
    }
}
