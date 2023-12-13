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
package com.google.android.enterprise.connectedapps.robotests;

import static com.google.android.enterprise.connectedapps.SharedTestUtilities.INTERACT_ACROSS_USERS;
import static com.google.common.truth.Truth.assertThat;
import static org.junit.Assert.assertThrows;
import static org.robolectric.annotation.LooperMode.Mode.LEGACY;

import android.app.Application;
import android.app.Service;
import android.os.Build.VERSION_CODES;
import android.os.IBinder;
import androidx.test.core.app.ApplicationProvider;
import com.google.android.enterprise.connectedapps.RobolectricTestUtilities;
import com.google.android.enterprise.connectedapps.TestScheduledExecutorService;
import com.google.android.enterprise.connectedapps.exceptions.UnavailableProfileException;
import com.google.android.enterprise.connectedapps.testapp.NotReallySerializableObject;
import com.google.android.enterprise.connectedapps.testapp.ParcelableObject;
import com.google.android.enterprise.connectedapps.testapp.configuration.TestApplication;
import com.google.android.enterprise.connectedapps.testapp.connector.TestProfileConnector;
import com.google.android.enterprise.connectedapps.testapp.types.ProfileTestCrossProfileType;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.IOException;
import java.sql.SQLException;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.robolectric.Robolectric;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.annotation.Config;
import org.robolectric.annotation.LooperMode;

@LooperMode(LEGACY)
@RunWith(RobolectricTestRunner.class)
@Config(minSdk = VERSION_CODES.O)
public class OtherProfileSynchronousTest {

  private static final String STRING = "String";
  private static final ParcelableObject PARCELABLE_OBJECT = new ParcelableObject("");
  private static final NotReallySerializableObject NOT_REALLY_SERIALIZABLE_OBJECT =
      new NotReallySerializableObject(PARCELABLE_OBJECT);

  private final Application context = ApplicationProvider.getApplicationContext();
  private final TestScheduledExecutorService scheduledExecutorService =
      new TestScheduledExecutorService();
  private final TestProfileConnector testProfileConnector =
      TestProfileConnector.create(context, scheduledExecutorService);
  private final RobolectricTestUtilities testUtilities =
      new RobolectricTestUtilities(testProfileConnector, scheduledExecutorService);
  private final ProfileTestCrossProfileType profileTestCrossProfileType =
      ProfileTestCrossProfileType.create(testProfileConnector);

  @Before
  public void setUp() {
    Service profileAwareService = Robolectric.setupService(TestApplication.getService());
    testUtilities.initTests();
    IBinder binder = profileAwareService.onBind(/* intent= */ null);
    testUtilities.setBinding(binder, RobolectricTestUtilities.TEST_CONNECTOR_CLASS_NAME);
    testUtilities.createWorkUser();
    testUtilities.turnOnWorkProfile();
    testUtilities.setRunningOnPersonalProfile();
    testUtilities.setRequestsPermissions(INTERACT_ACROSS_USERS);
    testUtilities.grantPermissions(INTERACT_ACROSS_USERS);
    testUtilities.startConnectingAndWait();
  }

  @Test
  public void other_synchronous_isBound_callsMethod() throws UnavailableProfileException {
    testUtilities.turnOnWorkProfile();
    testUtilities.startConnectingAndWait();

    assertThat(profileTestCrossProfileType.other().identityStringMethod(STRING)).isEqualTo(STRING);
  }

  @Test
  public void other_synchronous_isNotBound_throwsUnavailableProfileException() {
    testUtilities.turnOffWorkProfile();

    assertThrows(
        UnavailableProfileException.class,
        () -> profileTestCrossProfileType.other().identityStringMethod(STRING));
  }

  @Test
  public void other_synchronous_isNotInitialised_throwsUnavailableProfileException() {
    ProfileTestCrossProfileType profileTestCrossProfileType =
        ProfileTestCrossProfileType.create(TestProfileConnector.create(context));

    assertThrows(
        UnavailableProfileException.class,
        () -> profileTestCrossProfileType.other().identityStringMethod(STRING));
  }

  @Test
  public void
      other_synchronous_isBound_automaticConnectionManagement_throwsUnavailableProfileException() {
    testUtilities.turnOnWorkProfile();
    testProfileConnector.stopManualConnectionManagement();
    ListenableFuture<Void> ignored =
        profileTestCrossProfileType.other().listenableFutureVoidMethod(); // Causes it to bind

    assertThrows(
        UnavailableProfileException.class,
        () -> profileTestCrossProfileType.other().voidMethod());
  }

  @Test
  public void other_serializableObjectParameterIsNotReallySerializable_throwsException() {
    assertThrows(
        RuntimeException.class,
        () ->
            profileTestCrossProfileType
                .other()
                .identityNotReallySerializableObjectMethod(NOT_REALLY_SERIALIZABLE_OBJECT));
  }

  @Test
  public void other_synchronous_contextArgument_works() throws Exception {
    assertThat(profileTestCrossProfileType.other().isContextArgumentPassed()).isTrue();
  }

  @Test
  public void other_synchronous_declaresButDoesNotThrowException_works() throws Exception {
    assertThat(
            profileTestCrossProfileType
                .other()
                .identityStringMethodDeclaresButDoesNotThrowIOException(STRING))
        .isEqualTo(STRING);
  }

  @Test
  public void other_synchronous_throwsException_works() {
    assertThrows(
        IOException.class,
        () ->
            profileTestCrossProfileType
                .other()
                .identityStringMethodThrowsIOException(STRING));
  }

  @Test
  public void other_synchronous_declaresMultipleExceptions_throwsException_works() {
    assertThrows(
        SQLException.class,
        () ->
            profileTestCrossProfileType
                .other()
                .identityStringMethodDeclaresIOExceptionThrowsSQLException(STRING));
  }
}
