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

package com.android.libraries.entitlement.eapaka;

import static com.android.libraries.entitlement.eapaka.EapAkaChallengeTest.EAP_AKA_CHALLENGE_REQUEST;
import static com.android.libraries.entitlement.eapaka.EapAkaChallengeTest.EAP_AKA_SECURITY_CONTEXT_REQUEST_EXPECTED;
import static com.android.libraries.entitlement.eapaka.EapAkaResponseTest.EAP_AKA_SECURITY_CONTEXT_RESPONSE_SUCCESS;
import static com.android.libraries.entitlement.eapaka.EapAkaResponseTest.EAP_AKA_SECURITY_CONTEXT_RESPONSE_SYNC_FAILURE;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.Mockito.any;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;
import static org.testng.Assert.expectThrows;

import android.content.Context;
import android.net.Network;
import android.telephony.TelephonyManager;

import androidx.test.core.app.ApplicationProvider;
import androidx.test.runner.AndroidJUnit4;

import com.android.libraries.entitlement.CarrierConfig;
import com.android.libraries.entitlement.EsimOdsaOperation;
import com.android.libraries.entitlement.ServiceEntitlement;
import com.android.libraries.entitlement.ServiceEntitlementException;
import com.android.libraries.entitlement.ServiceEntitlementRequest;
import com.android.libraries.entitlement.http.HttpClient;
import com.android.libraries.entitlement.http.HttpConstants.ContentType;
import com.android.libraries.entitlement.http.HttpRequest;
import com.android.libraries.entitlement.http.HttpResponse;

import com.google.common.collect.ImmutableList;
import com.google.common.net.HttpHeaders;

import org.json.JSONException;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Captor;
import org.mockito.Mock;
import org.mockito.junit.MockitoJUnit;
import org.mockito.junit.MockitoRule;

@RunWith(AndroidJUnit4.class)
public class EapAkaApiTest {
    private static final String TEST_URL = "https://test.url/test-path";
    private static final String EAP_AKA_CHALLENGE =
            "{\"eap-relay-packet\":\"" + EAP_AKA_CHALLENGE_REQUEST + "\"}";
    // com.google.common.net.HttpHeaders.COOKIE
    private static final String HTTP_HEADER_COOKIE = "Cookie";
    private static final String COOKIE_VALUE = "COOKIE=abcdefg";
    private static final String COOKIE_VALUE_1 = "COOKIE=hijklmn";
    private static final String RESPONSE_XML =
            "<wap-provisioningdoc version=\"1.1\">\n"
                    + "    <characteristic type=\"TOKEN\">\n"
                    + "        <parm name=\"token\" value=\"kZYfCEpSsMr88KZVmab5UsZVzl+nWSsX\"/>\n"
                    + "        <parm name=\"validity\" value=\"3600\"/>\n"
                    + "    </characteristic>\n"
                    + "    <characteristic type=\"APPLICATION\">\n"
                    + "        <parm name=\"EntitlementStatus\" value=\"0\"/>\n"
                    + "        <parm name=\"AddrStatus\" value=\"0\"/>\n"
                    + "        <parm name=\"TC_Status\" value=\"2\"/>\n"
                    + "        <parm name=\"ProvStatus\" value=\"2\"/>\n"
                    + "        <parm name=\"ServiceFlow_URL\""
                    + " value=\"http://vm-host:8180/self-prov-websheet/rcs\"/>\n"
                    + "        <parm name=\"ServiceFlow_UserData\""
                    + " value=\"token=test_token\"/>\n"
                    + "    </characteristic>\n"
                    + "</wap-provisioningdoc>\n";
    private static final String TOKEN = "kZYfCEpSsMr88KZVmab5UsZVzl+nWSsX";
    private static final String IMSI = "234107813240779";
    private static final String MCCMNC = "23410";
    private static final String IMEI = "355494343566743";
    private static final int SUB_ID = 1;
    private static final String ACCEPT_CONTENT_TYPE_JSON_AND_XML =
            "application/vnd.gsma.eap-relay.v1.0+json, text/vnd.wap.connectivity-xml";

    @Rule public final MockitoRule rule = MockitoJUnit.rule();

    @Mock private HttpClient mMockHttpClient;
    @Mock private Network mMockNetwork;
    @Mock private TelephonyManager mMockTelephonyManager;
    @Mock private TelephonyManager mMockTelephonyManagerForSubId;
    @Captor private ArgumentCaptor<HttpRequest> mHttpRequestCaptor;

    private Context mContext;
    private EapAkaApi mEapAkaApi;

    @Before
    public void setUp() {
        mContext = spy(ApplicationProvider.getApplicationContext());
        mEapAkaApi = new EapAkaApi(mContext, SUB_ID, mMockHttpClient);
        when(mContext.getSystemService(TelephonyManager.class))
                .thenReturn(mMockTelephonyManager);
        when(mMockTelephonyManager.createForSubscriptionId(SUB_ID))
                .thenReturn(mMockTelephonyManagerForSubId);
        when(mMockTelephonyManagerForSubId.getSubscriberId()).thenReturn(IMSI);
        when(mMockTelephonyManagerForSubId.getSimOperator()).thenReturn(MCCMNC);
    }

    @Test
    public void queryEntitlementStatus_hasAuthenticationToken() throws Exception {
        HttpResponse httpResponse =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any())).thenReturn(httpResponse);
        CarrierConfig carrierConfig =
                CarrierConfig.builder().setServerUrl(TEST_URL).setNetwork(mMockNetwork).build();
        ServiceEntitlementRequest request =
                ServiceEntitlementRequest.builder().setAuthenticationToken(TOKEN).build();

        String response =
                mEapAkaApi.queryEntitlementStatus(
                        ImmutableList.of(ServiceEntitlement.APP_VOWIFI), carrierConfig, request);

        assertThat(response).isEqualTo(RESPONSE_XML);
        verify(mMockHttpClient).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getValue().timeoutInSec())
                .isEqualTo(CarrierConfig.DEFAULT_TIMEOUT_IN_SEC);
        assertThat(mHttpRequestCaptor.getValue().network()).isEqualTo(mMockNetwork);
    }

    @Test
    public void queryEntitlementStatus_noAuthenticationToken() throws Exception {
        when(mMockTelephonyManagerForSubId.getIccAuthentication(
                TelephonyManager.APPTYPE_USIM,
                TelephonyManager.AUTHTYPE_EAP_AKA,
                EAP_AKA_SECURITY_CONTEXT_REQUEST_EXPECTED))
                .thenReturn(EAP_AKA_SECURITY_CONTEXT_RESPONSE_SUCCESS);
        HttpResponse eapChallengeResponse =
                HttpResponse
                        .builder().setContentType(ContentType.JSON).setBody(EAP_AKA_CHALLENGE)
                        .setCookies(ImmutableList.of(COOKIE_VALUE, COOKIE_VALUE_1)).build();
        HttpResponse xmlResponse =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any()))
                .thenReturn(eapChallengeResponse).thenReturn(xmlResponse);
        CarrierConfig carrierConfig = CarrierConfig.builder().setServerUrl(TEST_URL).build();
        ServiceEntitlementRequest request = ServiceEntitlementRequest.builder().build();

        String respopnse =
                mEapAkaApi.queryEntitlementStatus(
                        ImmutableList.of(ServiceEntitlement.APP_VOWIFI), carrierConfig, request);

        assertThat(respopnse).isEqualTo(RESPONSE_XML);
        // Verify that the 2nd request has cookies set by the 1st response
        verify(mMockHttpClient, times(2)).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getAllValues().get(1).requestProperties())
                .containsAtLeast(HTTP_HEADER_COOKIE, COOKIE_VALUE,
                                 HTTP_HEADER_COOKIE, COOKIE_VALUE_1);
        assertThat(mHttpRequestCaptor.getAllValues().get(0).timeoutInSec())
                .isEqualTo(CarrierConfig.DEFAULT_TIMEOUT_IN_SEC);
        assertThat(mHttpRequestCaptor.getAllValues().get(0).network()).isNull();
        assertThat(mHttpRequestCaptor.getAllValues().get(1).timeoutInSec())
                .isEqualTo(CarrierConfig.DEFAULT_TIMEOUT_IN_SEC);
        assertThat(mHttpRequestCaptor.getAllValues().get(1).network()).isNull();
    }

    @Test
    public void queryEntitlementStatus_hasAuthenticationToken_multipleAppIds() throws Exception {
        HttpResponse response =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any())).thenReturn(response);
        ImmutableList<String> appIds = ImmutableList.of(ServiceEntitlement.APP_VOWIFI,
                ServiceEntitlement.APP_VOLTE);
        CarrierConfig carrierConfig =
                CarrierConfig.builder().setServerUrl(TEST_URL).setTimeoutInSec(70).build();
        ServiceEntitlementRequest request =
                ServiceEntitlementRequest.builder().setAuthenticationToken(TOKEN).build();

        mEapAkaApi.queryEntitlementStatus(appIds, carrierConfig, request);

        verify(mMockHttpClient).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getValue().url()).contains(ServiceEntitlement.APP_VOWIFI);
        assertThat(mHttpRequestCaptor.getValue().url()).contains(ServiceEntitlement.APP_VOLTE);
        assertThat(mHttpRequestCaptor.getValue().timeoutInSec()).isEqualTo(70);
        assertThat(mHttpRequestCaptor.getValue().network()).isNull();
    }

    @Test
    public void queryEntitlementStatus_noAuthenticationToken_emptyResponseBody_throwException()
            throws Exception {
        HttpResponse eapChallengeResponse =
                HttpResponse.builder().setContentType(ContentType.JSON).build();
        when(mMockHttpClient.request(any())).thenReturn(eapChallengeResponse);
        CarrierConfig carrierConfig =
                CarrierConfig.builder().setServerUrl(TEST_URL).build();
        ServiceEntitlementRequest request = ServiceEntitlementRequest.builder().build();

        ServiceEntitlementException exception = expectThrows(
                ServiceEntitlementException.class,
                () -> mEapAkaApi.queryEntitlementStatus(
                        ImmutableList.of(ServiceEntitlement.APP_VOWIFI),
                        carrierConfig,
                        request));

        assertThat(exception.getErrorCode()).isEqualTo(
                ServiceEntitlementException.ERROR_MALFORMED_HTTP_RESPONSE);
        assertThat(exception.getMessage()).isEqualTo("Failed to parse json object");
        assertThat(exception.getCause()).isInstanceOf(JSONException.class);
    }

    @Test
    public void queryEntitlementStatus_noAuthenticationToken_handleEapAkaSyncFailure()
            throws Exception {
        when(mMockTelephonyManagerForSubId.getIccAuthentication(
                TelephonyManager.APPTYPE_USIM,
                TelephonyManager.AUTHTYPE_EAP_AKA,
                EAP_AKA_SECURITY_CONTEXT_REQUEST_EXPECTED))
                .thenReturn(EAP_AKA_SECURITY_CONTEXT_RESPONSE_SYNC_FAILURE)
                .thenReturn(EAP_AKA_SECURITY_CONTEXT_RESPONSE_SUCCESS);
        HttpResponse eapChallengeResponse =
                HttpResponse
                        .builder().setContentType(ContentType.JSON).setBody(EAP_AKA_CHALLENGE)
                        .setCookies(ImmutableList.of(COOKIE_VALUE)).build();
        HttpResponse xmlResponse =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any()))
                .thenReturn(eapChallengeResponse)
                .thenReturn(eapChallengeResponse)
                .thenReturn(xmlResponse);
        CarrierConfig carrierConfig = CarrierConfig.builder().setServerUrl(TEST_URL).build();
        ServiceEntitlementRequest request = ServiceEntitlementRequest.builder().build();

        String response =
                mEapAkaApi.queryEntitlementStatus(
                        ImmutableList.of(ServiceEntitlement.APP_VOWIFI), carrierConfig, request);

        assertThat(response).isEqualTo(RESPONSE_XML);
        // Verify that the 2nd/3rd request has cookie set by the 1st/2nd response
        verify(mMockHttpClient, times(3)).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getAllValues().get(1).requestProperties())
                .containsEntry(HTTP_HEADER_COOKIE, COOKIE_VALUE);
        assertThat(mHttpRequestCaptor.getAllValues().get(2).requestProperties())
                .containsEntry(HTTP_HEADER_COOKIE, COOKIE_VALUE);
    }

    @Test
    public void queryEntitlementStatus_acceptContentTypeSpecified_verfityAcceptContentType()
            throws Exception {
        HttpResponse response = HttpResponse.builder().setBody(RESPONSE_XML).build();
        when(mMockHttpClient.request(any())).thenReturn(response);
        CarrierConfig carrierConfig = CarrierConfig.builder().build();
        ServiceEntitlementRequest request =
                ServiceEntitlementRequest
                        .builder()
                        .setAuthenticationToken(TOKEN)
                        .setAcceptContentType(ServiceEntitlementRequest.ACCEPT_CONTENT_TYPE_XML)
                        .build();

        mEapAkaApi.queryEntitlementStatus(
                ImmutableList.of(ServiceEntitlement.APP_VOWIFI), carrierConfig, request);

        verify(mMockHttpClient).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getValue().requestProperties().get(HttpHeaders.ACCEPT))
                .containsExactly(ServiceEntitlementRequest.ACCEPT_CONTENT_TYPE_XML);
    }

    @Test
    public void queryEntitlementStatus_acceptContentTypeNotSpecified_defaultAcceptContentType()
            throws Exception {
        HttpResponse response = HttpResponse.builder().setBody(RESPONSE_XML).build();
        when(mMockHttpClient.request(any())).thenReturn(response);
        CarrierConfig carrierConfig = CarrierConfig.builder().build();
        ServiceEntitlementRequest request =
                ServiceEntitlementRequest
                        .builder()
                        .setAuthenticationToken(TOKEN)
                        .build();

        mEapAkaApi.queryEntitlementStatus(
                ImmutableList.of(ServiceEntitlement.APP_VOWIFI), carrierConfig, request);

        verify(mMockHttpClient).request(mHttpRequestCaptor.capture());
        assertThat(mHttpRequestCaptor.getValue().requestProperties().get(HttpHeaders.ACCEPT))
                .containsExactly(ServiceEntitlementRequest.ACCEPT_CONTENT_TYPE_JSON_AND_XML);
    }

    @Test
    public void performEsimOdsaOperation_noAuthenticationToken_returnsResult() throws Exception {
        when(mMockTelephonyManagerForSubId.getIccAuthentication(
                TelephonyManager.APPTYPE_USIM,
                TelephonyManager.AUTHTYPE_EAP_AKA,
                EAP_AKA_SECURITY_CONTEXT_REQUEST_EXPECTED))
                .thenReturn(EAP_AKA_SECURITY_CONTEXT_RESPONSE_SUCCESS);
        HttpResponse eapChallengeResponse =
                HttpResponse
                        .builder().setContentType(ContentType.JSON).setBody(EAP_AKA_CHALLENGE)
                        .setCookies(ImmutableList.of(COOKIE_VALUE)).build();
        HttpResponse xmlResponse =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any()))
                .thenReturn(eapChallengeResponse).thenReturn(xmlResponse);
        CarrierConfig carrierConfig = CarrierConfig.builder().setServerUrl(TEST_URL).build();
        ServiceEntitlementRequest request = ServiceEntitlementRequest.builder().build();
        EsimOdsaOperation operation = EsimOdsaOperation.builder().build();

        String response =
                mEapAkaApi.performEsimOdsaOperation(ServiceEntitlement.APP_ODSA_COMPANION,
                        carrierConfig, request, operation);

        assertThat(response).isEqualTo(RESPONSE_XML);
        verify(mMockHttpClient, times(2)).request(any());
    }

    @Test
    public void performEsimOdsaOperation_manageSubscription_returnsResult() throws Exception {
        HttpResponse httpResponse =
                HttpResponse.builder().setContentType(ContentType.XML).setBody(RESPONSE_XML)
                        .build();
        when(mMockHttpClient.request(any())).thenReturn(httpResponse);
        CarrierConfig carrierConfig =
                CarrierConfig.builder().setServerUrl(TEST_URL).build();
        ServiceEntitlementRequest request =
                ServiceEntitlementRequest.builder().setAuthenticationToken(TOKEN).build();
        EsimOdsaOperation operation = EsimOdsaOperation.builder()
                .setOperation(EsimOdsaOperation.OPERATION_MANAGE_SUBSCRIPTION)
                .setOperationType(EsimOdsaOperation.OPERATION_TYPE_SUBSCRIBE)
                .build();

        String response =
                mEapAkaApi.performEsimOdsaOperation(ServiceEntitlement.APP_ODSA_COMPANION,
                        carrierConfig, request, operation);

        assertThat(response).isEqualTo(RESPONSE_XML);
        verify(mMockHttpClient, times(1)).request(any());
    }
}
