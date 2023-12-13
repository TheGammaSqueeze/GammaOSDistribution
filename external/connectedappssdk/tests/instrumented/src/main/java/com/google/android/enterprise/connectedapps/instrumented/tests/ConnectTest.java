/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.android.enterprise.connectedapps.instrumented.tests;

import static com.google.common.truth.Truth.assertThat;
import static org.junit.Assert.assertThrows;

import android.app.Application;
import androidx.test.core.app.ApplicationProvider;
import com.google.android.enterprise.connectedapps.exceptions.UnavailableProfileException;
import com.google.android.enterprise.connectedapps.instrumented.utils.InstrumentedTestUtilities;
import com.google.android.enterprise.connectedapps.testapp.connector.TestProfileConnector;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

/**
 * Tests regarding manual connections.
 *
 * <p>These must be instrumented tests as they require multiple threads.
 *
 * <p>Tests for manual connections when not installed in the other profile are in {@link
 * NotInstalledInOtherUserTest}.
 */
@RunWith(JUnit4.class)
public class ConnectTest {
  private static final Application context = ApplicationProvider.getApplicationContext();

  private static final TestProfileConnector connector = TestProfileConnector.create(context);
  private static final InstrumentedTestUtilities utilities =
      new InstrumentedTestUtilities(context, connector);

  @Before
  public void setup() {
    utilities.ensureReadyForCrossProfileCalls();
  }

  @After
  public void teardown() {
    connector.stopManualConnectionManagement();
    utilities.waitForDisconnected();
  }

  @AfterClass
  public static void teardownClass() {
    utilities.ensureNoWorkProfile();
  }

  @Test
  public void connect_connects() throws Exception {
    utilities.ensureReadyForCrossProfileCalls();

    connector.connect();

    assertThat(connector.isConnected()).isTrue();
  }

  @Test
  public void connect_startsManuallyManagingConnection() throws Exception {
    utilities.ensureReadyForCrossProfileCalls();

    connector.connect();

    assertThat(connector.isManuallyManagingConnection()).isTrue();
  }

  @Test
  public void connect_otherProfileNotAvailable_throwsUnavailableProfileException() {
    utilities.ensureNoWorkProfile();

    assertThrows(UnavailableProfileException.class, connector::connect);
  }

  @Test
  public void connect_otherProfileNotAvailable_doesNotConnect() {
    utilities.ensureNoWorkProfile();

    connectIgnoreExceptions();

    assertThat(connector.isConnected()).isFalse();
  }

  @Test
  public void connect_otherProfileNotAvailable_doesNotStartManuallyManagingConnection() {
    utilities.ensureNoWorkProfile();

    connectIgnoreExceptions();

    assertThat(connector.isManuallyManagingConnection()).isFalse();
  }

  @Test
  public void connect_alreadyConnected_returns() throws UnavailableProfileException {
    utilities.ensureReadyForCrossProfileCalls();
    connector.connect();

    connector.connect();

    assertThat(connector.isConnected()).isTrue();
  }

  private void connectIgnoreExceptions() {
    try {
      connector.connect();
    } catch (UnavailableProfileException ignored) {
      // Ignore
    }
  }
}
