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

package com.android.ims.rcs.uce.request;

import static android.telephony.ims.RcsContactUceCapability.CAPABILITY_MECHANISM_PRESENCE;

import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_CACHED_CAPABILITY_UPDATE;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_CAPABILITY_UPDATE;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_COMMAND_ERROR;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_ERROR;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_NETWORK_RESPONSE;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_NO_NEED_REQUEST_FROM_NETWORK;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_REMOTE_REQUEST_DONE;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_RESOURCE_TERMINATED;
import static com.android.ims.rcs.uce.request.UceRequestCoordinator.REQUEST_UPDATE_TERMINATED;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyLong;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;

import android.content.Context;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.telephony.ims.RcsContactUceCapability;
import android.telephony.ims.RcsUceAdapter;
import android.telephony.ims.aidl.IOptionsRequestCallback;
import android.telephony.ims.aidl.IRcsUceControllerCallback;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.filters.SmallTest;

import com.android.ims.ImsTestBase;
import com.android.ims.rcs.uce.UceController;
import com.android.ims.rcs.uce.UceController.UceControllerCallback;
import com.android.ims.rcs.uce.request.UceRequestManager.RequestManagerCallback;
import com.android.ims.rcs.uce.request.UceRequestManager.UceUtilsProxy;
import com.android.ims.rcs.uce.util.FeatureTags;

import java.util.ArrayList;
import java.util.List;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;

@RunWith(AndroidJUnit4.class)
public class UceRequestManagerTest extends ImsTestBase {

    @Mock UceRequest mUceRequest;
    @Mock UceRequestCoordinator mCoordinator;
    @Mock UceControllerCallback mCallback;
    @Mock UceRequestRepository mRequestRepository;
    @Mock IRcsUceControllerCallback mCapabilitiesCallback;
    @Mock IOptionsRequestCallback mOptionsReqCallback;

    private int mSubId = 1;
    private long mTaskId = 1L;
    private long mCoordId = 1L;

    @Before
    public void setUp() throws Exception {
        super.setUp();
        doReturn(mUceRequest).when(mRequestRepository).getUceRequest(anyLong());
        doReturn(mCoordinator).when(mRequestRepository).getRequestCoordinator(anyLong());
        doReturn(mCoordinator).when(mRequestRepository).removeRequestCoordinator(anyLong());
    }

    @After
    public void tearDown() throws Exception {
        super.tearDown();
    }

    @Test
    @SmallTest
    public void testSendCapabilityRequest() throws Exception {
        UceRequestManager requestManager = getUceRequestManager();
        requestManager.setsUceUtilsProxy(getUceUtilsProxy(true, true, false, false, true, 10));

        List<Uri> uriList = new ArrayList<>();
        uriList.add(Uri.fromParts("sip", "test", null));
        requestManager.sendCapabilityRequest(uriList, false, mCapabilitiesCallback);

        verify(mRequestRepository).addRequestCoordinator(any());
    }

    @Test
    @SmallTest
    public void testSendAvailabilityRequest() throws Exception {
        UceRequestManager requestManager = getUceRequestManager();
        requestManager.setsUceUtilsProxy(getUceUtilsProxy(true, true, false, false, true, 10));

        Uri uri = Uri.fromParts("sip", "test", null);
        requestManager.sendAvailabilityRequest(uri, mCapabilitiesCallback);

        verify(mRequestRepository).addRequestCoordinator(any());
    }

    @Test
    @SmallTest
    public void testRequestDestroyed() throws Exception {
        UceRequestManager requestManager = getUceRequestManager();
        requestManager.setsUceUtilsProxy(getUceUtilsProxy(true, true, true, false, true, 10));

        requestManager.onDestroy();

        List<Uri> uriList = new ArrayList<>();
        requestManager.sendCapabilityRequest(uriList, false, mCapabilitiesCallback);

        Handler handler = requestManager.getUceRequestHandler();
        waitForHandlerAction(handler, 500L);

        verify(mUceRequest, never()).executeRequest();
        verify(mCapabilitiesCallback).onError(RcsUceAdapter.ERROR_GENERIC_FAILURE, 0L);
    }

    @Test
    @SmallTest
    public void testRequestManagerCallback() throws Exception {
        UceRequestManager requestManager = getUceRequestManager();
        requestManager.setsUceUtilsProxy(getUceUtilsProxy(true, true, true, false, true, 10));
        RequestManagerCallback requestMgrCallback = requestManager.getRequestManagerCallback();
        Handler handler = requestManager.getUceRequestHandler();

        Uri contact = Uri.fromParts("sip", "test", null);
        List<Uri> uriList = new ArrayList<>();
        uriList.add(contact);

        requestMgrCallback.notifySendingRequest(mCoordId, mTaskId, 0L);
        waitForHandlerAction(handler, 400L);
        verify(mUceRequest).executeRequest();

        requestMgrCallback.getCapabilitiesFromCache(uriList);
        verify(mCallback).getCapabilitiesFromCache(uriList);

        requestMgrCallback.getAvailabilityFromCache(contact);
        verify(mCallback).getAvailabilityFromCache(contact);

        List<RcsContactUceCapability> capabilityList = new ArrayList<>();
        requestMgrCallback.saveCapabilities(capabilityList);
        verify(mCallback).saveCapabilities(capabilityList);

        requestMgrCallback.getDeviceCapabilities(CAPABILITY_MECHANISM_PRESENCE);
        verify(mCallback).getDeviceCapabilities(CAPABILITY_MECHANISM_PRESENCE);

        requestMgrCallback.getDeviceState();
        verify(mCallback).getDeviceState();

        requestMgrCallback.refreshDeviceState(200, "OK");
        verify(mCallback).refreshDeviceState(200, "OK", UceController.REQUEST_TYPE_CAPABILITY);

        requestMgrCallback.notifyRequestError(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_ERROR);

        requestMgrCallback.notifyCommandError(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_COMMAND_ERROR);

        requestMgrCallback.notifyNetworkResponse(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_NETWORK_RESPONSE);

        requestMgrCallback.notifyTerminated(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_TERMINATED);

        requestMgrCallback.notifyResourceTerminated(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_RESOURCE_TERMINATED);

        requestMgrCallback.notifyCapabilitiesUpdated(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_CAPABILITY_UPDATE);

        requestMgrCallback.notifyCachedCapabilitiesUpdated(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_CACHED_CAPABILITY_UPDATE);

        requestMgrCallback.notifyNoNeedRequestFromNetwork(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_NO_NEED_REQUEST_FROM_NETWORK);

        requestMgrCallback.notifyRemoteRequestDone(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onRequestUpdated(mTaskId, REQUEST_UPDATE_REMOTE_REQUEST_DONE);

        requestMgrCallback.notifyUceRequestFinished(mCoordId, mTaskId);
        waitForHandlerAction(handler, 400L);
        verify(mRequestRepository).notifyRequestFinished(mTaskId);

        requestMgrCallback.notifyRequestCoordinatorFinished(mCoordId);
        waitForHandlerAction(handler, 400L);
        verify(mCoordinator).onFinish();
    }

    @Test
    @SmallTest
    public void testRetrieveCapForRemote() throws Exception {
        UceRequestManager requestManager = getUceRequestManager();
        requestManager.setsUceUtilsProxy(getUceUtilsProxy(true, true, true, false, true, 10));

        Uri contact = Uri.fromParts("sip", "test", null);
        List<String> remoteCapList = new ArrayList<>();
        remoteCapList.add(FeatureTags.FEATURE_TAG_CHAT_IM);
        remoteCapList.add(FeatureTags.FEATURE_TAG_FILE_TRANSFER);
        requestManager.retrieveCapabilitiesForRemote(contact, remoteCapList, mOptionsReqCallback);

        verify(mRequestRepository).addRequestCoordinator(any());
    }

    private UceRequestManager getUceRequestManager() {
        UceRequestManager manager = new UceRequestManager(mContext, mSubId, Looper.getMainLooper(),
                mCallback, mRequestRepository);
        return manager;
    }

    private UceUtilsProxy getUceUtilsProxy(boolean presenceCapEnabled, boolean supportPresence,
            boolean supportOptions, boolean isBlocked, boolean groupSubscribe, int rclMaximum) {
        return new UceUtilsProxy() {
            @Override
            public boolean isPresenceCapExchangeEnabled(Context context, int subId) {
                return presenceCapEnabled;
            }

            @Override
            public boolean isPresenceSupported(Context context, int subId) {
                return supportPresence;
            }

            @Override
            public boolean isSipOptionsSupported(Context context, int subId) {
                return supportOptions;
            }

            @Override
            public boolean isPresenceGroupSubscribeEnabled(Context context, int subId) {
                return groupSubscribe;
            }

            @Override
            public int getRclMaxNumberEntries(int subId) {
                return rclMaximum;
            }

            @Override
            public boolean isNumberBlocked(Context context, String phoneNumber) {
                return isBlocked;
            }
        };
    }
}
