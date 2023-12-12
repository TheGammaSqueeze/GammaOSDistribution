/*
 * Copyright 2016 The gRPC Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package io.grpc.auth;

import static com.google.common.base.Charsets.US_ASCII;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import static org.mockito.Matchers.any;
import static org.mockito.Matchers.eq;
import static org.mockito.Mockito.doAnswer;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import com.google.auth.Credentials;
import com.google.auth.RequestMetadataCallback;
import com.google.auth.oauth2.AccessToken;
import com.google.auth.oauth2.GoogleCredentials;
import com.google.auth.oauth2.OAuth2Credentials;
import com.google.auth.oauth2.ServiceAccountCredentials;
import com.google.common.collect.Iterables;
import com.google.common.collect.LinkedListMultimap;
import com.google.common.collect.ListMultimap;
import com.google.common.collect.Multimaps;
import io.grpc.Attributes;
import io.grpc.CallCredentials2;
import io.grpc.CallCredentials2.MetadataApplier;
import io.grpc.Metadata;
import io.grpc.MethodDescriptor;
import io.grpc.SecurityLevel;
import io.grpc.Status;
import io.grpc.testing.TestMethodDescriptors;
import java.io.IOException;
import java.net.URI;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Executor;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.mockito.ArgumentCaptor;
import org.mockito.Captor;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.invocation.InvocationOnMock;
import org.mockito.stubbing.Answer;

/**
 * Tests for {@link GoogleAuthLibraryCallCredentials}.
 */
@RunWith(JUnit4.class)
public class GoogleAuthLibraryCallCredentialsTest {

  private static final Metadata.Key<String> AUTHORIZATION = Metadata.Key.of("Authorization",
      Metadata.ASCII_STRING_MARSHALLER);
  private static final Metadata.Key<byte[]> EXTRA_AUTHORIZATION = Metadata.Key.of(
      "Extra-Authorization-bin", Metadata.BINARY_BYTE_MARSHALLER);

  @Mock
  private Credentials credentials;

  @Mock
  private MetadataApplier applier;

  private Executor executor = new Executor() {
    @Override public void execute(Runnable r) {
      pendingRunnables.add(r);
    }
  };

  @Captor
  private ArgumentCaptor<Metadata> headersCaptor;

  @Captor
  private ArgumentCaptor<Status> statusCaptor;

  private MethodDescriptor<Void, Void> method = MethodDescriptor.<Void, Void>newBuilder()
      .setType(MethodDescriptor.MethodType.UNKNOWN)
      .setFullMethodName("a.service/method")
      .setRequestMarshaller(TestMethodDescriptors.voidMarshaller())
      .setResponseMarshaller(TestMethodDescriptors.voidMarshaller())
      .build();
  private URI expectedUri = URI.create("https://testauthority/a.service");

  private static final String AUTHORITY = "testauthority";
  private static final SecurityLevel SECURITY_LEVEL = SecurityLevel.PRIVACY_AND_INTEGRITY;

  private ArrayList<Runnable> pendingRunnables = new ArrayList<>();

  @Before
  public void setUp() throws Exception {
    MockitoAnnotations.initMocks(this);
    doAnswer(new Answer<Void>() {
      @Override
      public Void answer(InvocationOnMock invocation) {
        Credentials mock = (Credentials) invocation.getMock();
        URI uri = (URI) invocation.getArguments()[0];
        RequestMetadataCallback callback = (RequestMetadataCallback) invocation.getArguments()[2];
        Map<String, List<String>> metadata;
        try {
          // Default to calling the blocking method, since it is easier to mock
          metadata = mock.getRequestMetadata(uri);
        } catch (Exception ex) {
          callback.onFailure(ex);
          return null;
        }
        callback.onSuccess(metadata);
        return null;
      }
    }).when(credentials).getRequestMetadata(
        any(URI.class),
        any(Executor.class),
        any(RequestMetadataCallback.class));
  }

  @After
  public void tearDown() {
    assertEquals(0, pendingRunnables.size());
  }

  @Test
  public void copyCredentialsToHeaders() throws Exception {
    ListMultimap<String, String> values = LinkedListMultimap.create();
    values.put("Authorization", "token1");
    values.put("Authorization", "token2");
    values.put("Extra-Authorization-bin", "dG9rZW4z");  // bytes "token3" in base64
    values.put("Extra-Authorization-bin", "dG9rZW40");  // bytes "token4" in base64
    when(credentials.getRequestMetadata(eq(expectedUri))).thenReturn(Multimaps.asMap(values));

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);

    verify(credentials).getRequestMetadata(eq(expectedUri));
    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    Iterable<String> authorization = headers.getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"token1", "token2"},
        Iterables.toArray(authorization, String.class));
    Iterable<byte[]> extraAuthorization = headers.getAll(EXTRA_AUTHORIZATION);
    assertEquals(2, Iterables.size(extraAuthorization));
    assertArrayEquals("token3".getBytes(US_ASCII), Iterables.get(extraAuthorization, 0));
    assertArrayEquals("token4".getBytes(US_ASCII), Iterables.get(extraAuthorization, 1));
  }

  @Test
  public void invalidBase64() throws Exception {
    ListMultimap<String, String> values = LinkedListMultimap.create();
    values.put("Extra-Authorization-bin", "dG9rZW4z1");  // invalid base64
    when(credentials.getRequestMetadata(eq(expectedUri))).thenReturn(Multimaps.asMap(values));

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);

    verify(credentials).getRequestMetadata(eq(expectedUri));
    verify(applier).fail(statusCaptor.capture());
    Status status = statusCaptor.getValue();
    assertEquals(Status.Code.UNAUTHENTICATED, status.getCode());
    assertEquals(IllegalArgumentException.class, status.getCause().getClass());
  }

  @Test
  public void credentialsFailsWithIoException() throws Exception {
    Exception exception = new IOException("Broken");
    when(credentials.getRequestMetadata(eq(expectedUri))).thenThrow(exception);

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);

    verify(credentials).getRequestMetadata(eq(expectedUri));
    verify(applier).fail(statusCaptor.capture());
    Status status = statusCaptor.getValue();
    assertEquals(Status.Code.UNAVAILABLE, status.getCode());
    assertEquals(exception, status.getCause());
  }

  @Test
  public void credentialsFailsWithRuntimeException() throws Exception {
    Exception exception = new RuntimeException("Broken");
    when(credentials.getRequestMetadata(eq(expectedUri))).thenThrow(exception);

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);

    verify(credentials).getRequestMetadata(eq(expectedUri));
    verify(applier).fail(statusCaptor.capture());
    Status status = statusCaptor.getValue();
    assertEquals(Status.Code.UNAUTHENTICATED, status.getCode());
    assertEquals(exception, status.getCause());
  }

  @Test
  @SuppressWarnings("unchecked")
  public void credentialsReturnNullMetadata() throws Exception {
    ListMultimap<String, String> values = LinkedListMultimap.create();
    values.put("Authorization", "token1");
    when(credentials.getRequestMetadata(eq(expectedUri)))
        .thenReturn(null, Multimaps.<String, String>asMap(values), null);

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    for (int i = 0; i < 3; i++) {
      callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);
    }

    verify(credentials, times(3)).getRequestMetadata(eq(expectedUri));

    verify(applier, times(3)).apply(headersCaptor.capture());
    List<Metadata> headerList = headersCaptor.getAllValues();
    assertEquals(3, headerList.size());

    assertEquals(0, headerList.get(0).keys().size());

    Iterable<String> authorization = headerList.get(1).getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"token1"}, Iterables.toArray(authorization, String.class));

    assertEquals(0, headerList.get(2).keys().size());
  }

  @Test
  public void oauth2Credential() {
    final AccessToken token = new AccessToken("allyourbase", new Date(Long.MAX_VALUE));
    final OAuth2Credentials credentials = new OAuth2Credentials() {
      @Override
      public AccessToken refreshAccessToken() throws IOException {
        return token;
      }
    };

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(
        new RequestInfoImpl(SecurityLevel.NONE), executor, applier);
    assertEquals(1, runPendingRunnables());

    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    Iterable<String> authorization = headers.getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"Bearer allyourbase"},
        Iterables.toArray(authorization, String.class));
  }

  @Test
  public void googleCredential_privacyAndIntegrityAllowed() {
    final AccessToken token = new AccessToken("allyourbase", new Date(Long.MAX_VALUE));
    final Credentials credentials = GoogleCredentials.create(token);

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(
        new RequestInfoImpl(SecurityLevel.PRIVACY_AND_INTEGRITY), executor, applier);
    runPendingRunnables();

    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    Iterable<String> authorization = headers.getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"Bearer allyourbase"},
        Iterables.toArray(authorization, String.class));
  }

  @Test
  public void googleCredential_integrityDenied() {
    final AccessToken token = new AccessToken("allyourbase", new Date(Long.MAX_VALUE));
    final Credentials credentials = GoogleCredentials.create(token);
    // Anything less than PRIVACY_AND_INTEGRITY should fail

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(
        new RequestInfoImpl(SecurityLevel.INTEGRITY), executor, applier);
    runPendingRunnables();

    verify(applier).fail(statusCaptor.capture());
    Status status = statusCaptor.getValue();
    assertEquals(Status.Code.UNAUTHENTICATED, status.getCode());
  }

  @Test
  public void serviceUri() throws Exception {
    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(
        new RequestInfoImpl("example.com:443"), executor, applier);
    verify(credentials).getRequestMetadata(eq(new URI("https://example.com/a.service")));

    callCredentials.applyRequestMetadata(
        new RequestInfoImpl("example.com:123"), executor, applier);
    verify(credentials).getRequestMetadata(eq(new URI("https://example.com:123/a.service")));
  }

  @Test
  public void serviceAccountToJwt() throws Exception {
    KeyPair pair = KeyPairGenerator.getInstance("RSA").generateKeyPair();
    @SuppressWarnings("deprecation")
    ServiceAccountCredentials credentials = new ServiceAccountCredentials(
        null, "email@example.com", pair.getPrivate(), null, null) {
      @Override
      public AccessToken refreshAccessToken() {
        throw new AssertionError();
      }
    };

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);
    assertEquals(0, runPendingRunnables());

    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    String[] authorization = Iterables.toArray(headers.getAll(AUTHORIZATION), String.class);
    assertEquals(1, authorization.length);
    assertTrue(authorization[0], authorization[0].startsWith("Bearer "));
    // JWT is reasonably long. Normal tokens aren't.
    assertTrue(authorization[0], authorization[0].length() > 300);
  }

  @Test
  public void serviceAccountWithScopeNotToJwt() throws Exception {
    final AccessToken token = new AccessToken("allyourbase", new Date(Long.MAX_VALUE));
    KeyPair pair = KeyPairGenerator.getInstance("RSA").generateKeyPair();
    @SuppressWarnings("deprecation")
    ServiceAccountCredentials credentials = new ServiceAccountCredentials(
        null, "email@example.com", pair.getPrivate(), null, Arrays.asList("somescope")) {
      @Override
      public AccessToken refreshAccessToken() {
        return token;
      }
    };

    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);
    assertEquals(1, runPendingRunnables());

    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    Iterable<String> authorization = headers.getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"Bearer allyourbase"},
        Iterables.toArray(authorization, String.class));
  }

  @Test
  public void oauthClassesNotInClassPath() throws Exception {
    ListMultimap<String, String> values = LinkedListMultimap.create();
    values.put("Authorization", "token1");
    when(credentials.getRequestMetadata(eq(expectedUri))).thenReturn(Multimaps.asMap(values));

    assertNull(GoogleAuthLibraryCallCredentials.createJwtHelperOrNull(null));
    GoogleAuthLibraryCallCredentials callCredentials =
        new GoogleAuthLibraryCallCredentials(credentials, null);
    callCredentials.applyRequestMetadata(new RequestInfoImpl(), executor, applier);

    verify(credentials).getRequestMetadata(eq(expectedUri));
    verify(applier).apply(headersCaptor.capture());
    Metadata headers = headersCaptor.getValue();
    Iterable<String> authorization = headers.getAll(AUTHORIZATION);
    assertArrayEquals(new String[]{"token1"},
        Iterables.toArray(authorization, String.class));
  }

  private int runPendingRunnables() {
    ArrayList<Runnable> savedPendingRunnables = pendingRunnables;
    pendingRunnables = new ArrayList<>();
    for (Runnable r : savedPendingRunnables) {
      r.run();
    }
    return savedPendingRunnables.size();
  }

  private final class RequestInfoImpl extends CallCredentials2.RequestInfo {
    final String authority;
    final SecurityLevel securityLevel;

    RequestInfoImpl() {
      this(AUTHORITY, SECURITY_LEVEL);
    }

    RequestInfoImpl(SecurityLevel securityLevel) {
      this(AUTHORITY, securityLevel);
    }

    RequestInfoImpl(String authority) {
      this(authority, SECURITY_LEVEL);
    }

    RequestInfoImpl(String authority, SecurityLevel securityLevel) {
      this.authority = authority;
      this.securityLevel = securityLevel;
    }

    @Override
    public MethodDescriptor<?, ?> getMethodDescriptor() {
      return method;
    }

    @Override
    public SecurityLevel getSecurityLevel() {
      return securityLevel;
    }

    @Override
    public String getAuthority() {
      return authority;
    }

    @Override
    public Attributes getTransportAttrs() {
      return Attributes.EMPTY;
    }
  }
}
