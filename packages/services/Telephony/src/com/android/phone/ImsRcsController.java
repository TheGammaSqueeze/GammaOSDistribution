/*
 * Copyright (C) 2019 The Android Open Source Project
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

import android.Manifest;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Binder;
import android.os.RemoteException;
import android.os.ServiceSpecificException;
import android.os.UserHandle;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyFrameworkInitializer;
import android.telephony.ims.DelegateRequest;
import android.telephony.ims.ImsException;
import android.telephony.ims.RcsContactUceCapability;
import android.telephony.ims.RcsUceAdapter.PublishState;
import android.telephony.ims.RegistrationManager;
import android.telephony.ims.aidl.IImsCapabilityCallback;
import android.telephony.ims.aidl.IImsRcsController;
import android.telephony.ims.aidl.IImsRegistrationCallback;
import android.telephony.ims.aidl.IRcsUceControllerCallback;
import android.telephony.ims.aidl.IRcsUcePublishStateCallback;
import android.telephony.ims.aidl.ISipDelegate;
import android.telephony.ims.aidl.ISipDelegateConnectionStateCallback;
import android.telephony.ims.aidl.ISipDelegateMessageCallback;
import android.telephony.ims.feature.ImsFeature;
import android.telephony.ims.feature.RcsFeature;
import android.telephony.ims.stub.ImsRegistrationImplBase;
import android.util.Log;

import com.android.ims.ImsManager;
import com.android.ims.internal.IImsServiceFeatureCallback;
import com.android.internal.telephony.IIntegerConsumer;
import com.android.internal.telephony.Phone;
import com.android.internal.telephony.TelephonyPermissions;
import com.android.internal.telephony.ims.ImsResolver;
import com.android.services.telephony.rcs.RcsFeatureController;
import com.android.services.telephony.rcs.SipTransportController;
import com.android.services.telephony.rcs.TelephonyRcsService;
import com.android.services.telephony.rcs.UceControllerManager;

import java.util.List;
import java.util.Set;

/**
 * Implementation of the IImsRcsController interface.
 */
public class ImsRcsController extends IImsRcsController.Stub {
    private static final String TAG = "ImsRcsController";

    /** The singleton instance. */
    private static ImsRcsController sInstance;

    private PhoneGlobals mApp;
    private TelephonyRcsService mRcsService;
    private ImsResolver mImsResolver;
    // set by shell cmd phone src set-device-enabled true/false
    private Boolean mSingleRegistrationOverride;

    /**
     * Initialize the singleton ImsRcsController instance.
     * This is only done once, at startup, from PhoneApp.onCreate().
     */
    static ImsRcsController init(PhoneGlobals app) {
        synchronized (ImsRcsController.class) {
            if (sInstance == null) {
                sInstance = new ImsRcsController(app);
            } else {
                Log.wtf(TAG, "init() called multiple times!  sInstance = " + sInstance);
            }
            return sInstance;
        }
    }

    /** Private constructor; @see init() */
    private ImsRcsController(PhoneGlobals app) {
        Log.i(TAG, "ImsRcsController");
        mApp = app;
        TelephonyFrameworkInitializer
                .getTelephonyServiceManager().getTelephonyImsServiceRegisterer().register(this);
        mImsResolver = ImsResolver.getInstance();
    }

    /**
     * Register a {@link RegistrationManager.RegistrationCallback} to receive IMS network
     * registration state.
     */
    @Override
    public void registerImsRegistrationCallback(int subId, IImsRegistrationCallback callback) {
        TelephonyPermissions.enforceCallingOrSelfReadPrecisePhoneStatePermissionOrCarrierPrivilege(
                mApp, subId, "registerImsRegistrationCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).registerImsRegistrationCallback(subId, callback);
        } catch (ImsException e) {
            Log.e(TAG, "registerImsRegistrationCallback: sudId=" + subId + ", " + e.getMessage());
            throw new ServiceSpecificException(e.getCode());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Removes an existing {@link RegistrationManager.RegistrationCallback}.
     */
    @Override
    public void unregisterImsRegistrationCallback(int subId, IImsRegistrationCallback callback) {
        TelephonyPermissions.enforceCallingOrSelfReadPrecisePhoneStatePermissionOrCarrierPrivilege(
                mApp, subId, "unregisterImsRegistrationCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).unregisterImsRegistrationCallback(subId, callback);
        } catch (ServiceSpecificException e) {
            Log.e(TAG, "unregisterImsRegistrationCallback: error=" + e.errorCode);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Get the IMS service registration state for the RcsFeature associated with this sub id.
     */
    @Override
    public void getImsRcsRegistrationState(int subId, IIntegerConsumer consumer) {
        TelephonyPermissions.enforceCallingOrSelfReadPrecisePhoneStatePermissionOrCarrierPrivilege(
                mApp, subId, "getImsRcsRegistrationState");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).getRegistrationState(regState -> {
                try {
                    consumer.accept((regState == null)
                            ? RegistrationManager.REGISTRATION_STATE_NOT_REGISTERED : regState);
                } catch (RemoteException e) {
                    Log.w(TAG, "getImsRcsRegistrationState: callback is not available.");
                }
            });
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Gets the Transport Type associated with the current IMS RCS registration.
     */
    @Override
    public void getImsRcsRegistrationTransportType(int subId, IIntegerConsumer consumer) {
        TelephonyPermissions.enforceCallingOrSelfReadPrecisePhoneStatePermissionOrCarrierPrivilege(
                mApp, subId, "getImsRcsRegistrationTransportType");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).getRegistrationTech(regTech -> {
                // Convert registration tech from ImsRegistrationImplBase -> RegistrationManager
                int regTechConverted = (regTech == null)
                        ? ImsRegistrationImplBase.REGISTRATION_TECH_NONE : regTech;
                regTechConverted = RegistrationManager.IMS_REG_TO_ACCESS_TYPE_MAP.get(
                        regTechConverted);
                try {
                    consumer.accept(regTechConverted);
                } catch (RemoteException e) {
                    Log.w(TAG, "getImsRcsRegistrationTransportType: callback is not available.");
                }
            });
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Register a capability callback which will provide RCS availability updates for the
     * subscription specified.
     *
     * @param subId the subscription ID
     * @param callback The ImsCapabilityCallback to be registered.
     */
    @Override
    public void registerRcsAvailabilityCallback(int subId, IImsCapabilityCallback callback) {
        enforceReadPrivilegedPermission("registerRcsAvailabilityCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).registerRcsAvailabilityCallback(subId, callback);
        } catch (ImsException e) {
            Log.e(TAG, "registerRcsAvailabilityCallback: sudId=" + subId + ", " + e.getMessage());
            throw new ServiceSpecificException(e.getCode());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Remove the registered capability callback.
     *
     * @param subId the subscription ID
     * @param callback The ImsCapabilityCallback to be removed.
     */
    @Override
    public void unregisterRcsAvailabilityCallback(int subId, IImsCapabilityCallback callback) {
        enforceReadPrivilegedPermission("unregisterRcsAvailabilityCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            getRcsFeatureController(subId).unregisterRcsAvailabilityCallback(subId, callback);
        } catch (ServiceSpecificException e) {
            Log.e(TAG, "unregisterRcsAvailabilityCallback: error=" + e.errorCode);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Query for the capability of an IMS RCS service
     *
     * @param subId the subscription ID
     * @param capability the RCS capability to query.
     * @param radioTech the radio technology type that we are querying.
     * @return true if the RCS capability is capable for this subscription, false otherwise.
     */
    @Override
    public boolean isCapable(int subId,
            @RcsFeature.RcsImsCapabilities.RcsImsCapabilityFlag int capability,
            @ImsRegistrationImplBase.ImsRegistrationTech int radioTech) {
        enforceReadPrivilegedPermission("isCapable");
        final long token = Binder.clearCallingIdentity();
        try {
            return getRcsFeatureController(subId).isCapable(capability, radioTech);
        } catch (ImsException e) {
            Log.e(TAG, "isCapable: sudId=" + subId
                    + ", capability=" + capability + ", " + e.getMessage());
            return false;
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Query the availability of an IMS RCS capability.
     *
     * @param subId the subscription ID
     * @param capability the RCS capability to query.
     * @return true if the RCS capability is currently available for the associated subscription,
     * @param radioTech the radio technology type that we are querying.
     * false otherwise.
     */
    @Override
    public boolean isAvailable(int subId,
            @RcsFeature.RcsImsCapabilities.RcsImsCapabilityFlag int capability,
            @ImsRegistrationImplBase.ImsRegistrationTech int radioTech) {
        enforceReadPrivilegedPermission("isAvailable");
        final long token = Binder.clearCallingIdentity();
        try {
            return getRcsFeatureController(subId).isAvailable(capability, radioTech);
        } catch (ImsException e) {
            Log.e(TAG, "isAvailable: sudId=" + subId
                    + ", capability=" + capability + ", " + e.getMessage());
            return false;
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public void requestCapabilities(int subId, String callingPackage, String callingFeatureId,
            List<Uri> contactNumbers, IRcsUceControllerCallback c) {
        enforceAccessUserCapabilityExchangePermission("requestCapabilities");
        enforceReadContactsPermission("requestCapabilities");
        final long token = Binder.clearCallingIdentity();
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "This subscription does not support UCE.");
            }
            uceCtrlManager.requestCapabilities(contactNumbers, c);
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public void requestAvailability(int subId, String callingPackage,
            String callingFeatureId, Uri contactNumber, IRcsUceControllerCallback c) {
        enforceAccessUserCapabilityExchangePermission("requestAvailability");
        enforceReadContactsPermission("requestAvailability");
        final long token = Binder.clearCallingIdentity();
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "This subscription does not support UCE.");
            }
            uceCtrlManager.requestNetworkAvailability(contactNumber, c);
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public @PublishState int getUcePublishState(int subId) {
        enforceReadPrivilegedPermission("getUcePublishState");
        final long token = Binder.clearCallingIdentity();
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "This subscription does not support UCE.");
            }
            return uceCtrlManager.getUcePublishState();
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    /**
     * Add new feature tags to the Set used to calculate the capabilities in PUBLISH.
     */
    // Used for SHELL command only right now.
    public RcsContactUceCapability addUceRegistrationOverrideShell(int subId,
            Set<String> featureTags) throws ImsException {
        // Permission check happening in PhoneInterfaceManager.
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return null;
            }
            return uceCtrlManager.addUceRegistrationOverride(featureTags);
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * Remove existing feature tags to the Set used to calculate the capabilities in PUBLISH.
     */
    // Used for SHELL command only right now.
    public RcsContactUceCapability removeUceRegistrationOverrideShell(int subId,
            Set<String> featureTags) throws ImsException {
        // Permission check happening in PhoneInterfaceManager.
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return null;
            }
            return uceCtrlManager.removeUceRegistrationOverride(featureTags);
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * Clear all overrides in the Set used to calculate the capabilities in PUBLISH.
     */
    // Used for SHELL command only right now.
    public RcsContactUceCapability clearUceRegistrationOverrideShell(int subId)
            throws ImsException {
        try {
            // Permission check happening in PhoneInterfaceManager.
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return null;
            }
            return uceCtrlManager.clearUceRegistrationOverride();
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * @return current RcsContactUceCapability instance that will be used for PUBLISH.
     */
    // Used for SHELL command only right now.
    public RcsContactUceCapability getLatestRcsContactUceCapabilityShell(int subId)
            throws ImsException {
        try {
            // Permission check happening in PhoneInterfaceManager.
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return null;
            }
            return uceCtrlManager.getLatestRcsContactUceCapability();
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * @return the PIDf XML used in the last PUBLISH procedure or "none" if the device is not
     * published. Returns {@code null} if the operation failed due to an error.
     */
    // Used for SHELL command only right now.
    public String getLastUcePidfXmlShell(int subId) throws ImsException {
        try {
            // Permission check happening in PhoneInterfaceManager.
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return null;
            }
            String pidfXml = uceCtrlManager.getLastPidfXml();
            return pidfXml == null ? "none" : pidfXml;
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * Remove UCE requests cannot be sent to the network status.
     * @return true if this command is successful.
     */
    // Used for SHELL command only right now.
    public boolean removeUceRequestDisallowedStatus(int subId) throws ImsException {
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId, true).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return false;
            }
            return uceCtrlManager.removeUceRequestDisallowedStatus();
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    /**
     * Set the timeout for contact capabilities request.
     */
    // Used for SHELL command only right now.
    public boolean setCapabilitiesRequestTimeout(int subId, long timeoutAfter) throws ImsException {
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId, true).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                return false;
            }
            return uceCtrlManager.setCapabilitiesRequestTimeout(timeoutAfter);
        } catch (ServiceSpecificException e) {
            throw new ImsException(e.getMessage(), e.errorCode);
        }
    }

    @Override
    public void registerUcePublishStateCallback(int subId, IRcsUcePublishStateCallback c) {
        enforceReadPrivilegedPermission("registerUcePublishStateCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "This subscription does not support UCE.");
            }
            uceCtrlManager.registerPublishStateCallback(c);
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public void unregisterUcePublishStateCallback(int subId, IRcsUcePublishStateCallback c) {
        enforceReadPrivilegedPermission("unregisterUcePublishStateCallback");
        final long token = Binder.clearCallingIdentity();
        try {
            UceControllerManager uceCtrlManager = getRcsFeatureController(subId).getFeature(
                    UceControllerManager.class);
            if (uceCtrlManager == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "This subscription does not support UCE.");
            }
            uceCtrlManager.unregisterPublishStateCallback(c);
        } catch (ServiceSpecificException e) {
            Log.e(TAG, "unregisterUcePublishStateCallback: error=" + e.errorCode);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public boolean isUceSettingEnabled(int subId, String callingPackage, String callingFeatureId) {
        if (!TelephonyPermissions.checkCallingOrSelfReadPhoneState(
                mApp, subId, callingPackage, callingFeatureId, "isUceSettingEnabled")) {
            Log.w(TAG, "isUceSettingEnabled: READ_PHONE_STATE app op disabled when accessing "
                    + "isUceSettingEnabled");
            return false;
        }
        final long token = Binder.clearCallingIdentity();
        try {
            return SubscriptionManager.getBooleanSubscriptionProperty(subId,
                    SubscriptionManager.IMS_RCS_UCE_ENABLED, false /*defaultValue*/, mApp);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public void setUceSettingEnabled(int subId, boolean isEnabled) {
        enforceModifyPermission();
        final long token = Binder.clearCallingIdentity();
        try {
            SubscriptionManager.setSubscriptionProperty(subId,
                    SubscriptionManager.IMS_RCS_UCE_ENABLED, (isEnabled ? "1" : "0"));
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public boolean isSipDelegateSupported(int subId) {
        TelephonyPermissions.enforceAnyPermissionGranted(mApp, Binder.getCallingUid(),
                "isSipDelegateSupported",
                Manifest.permission.PERFORM_IMS_SINGLE_REGISTRATION,
                Manifest.permission.READ_PRIVILEGED_PHONE_STATE);
        if (!isImsSingleRegistrationSupportedOnDevice()) {
            return false;
        }
        final long token = Binder.clearCallingIdentity();
        try {
            SipTransportController transport = getRcsFeatureController(subId).getFeature(
                    SipTransportController.class);
            if (transport == null) {
                return false;
            }
            return transport.isSupported(subId);
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } catch (ServiceSpecificException e) {
            if (e.errorCode == ImsException.CODE_ERROR_UNSUPPORTED_OPERATION) {
                return false;
            }
            throw e;
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    @Override
    public void createSipDelegate(int subId, DelegateRequest request, String packageName,
            ISipDelegateConnectionStateCallback delegateState,
            ISipDelegateMessageCallback delegateMessage) {
        enforceImsSingleRegistrationPermission("createSipDelegate");
        if (!isImsSingleRegistrationSupportedOnDevice()) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "SipDelegate creation is only supported for devices supporting IMS single "
                            + "registration");
        }
        if (!UserHandle.getUserHandleForUid(Binder.getCallingUid()).isSystem()) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "SipDelegate creation is only available to primary user.");
        }
        try {
            int remoteUid = mApp.getPackageManager().getPackageUid(packageName, 0 /*flags*/);
            if (Binder.getCallingUid() != remoteUid) {
                throw new SecurityException("passed in packageName does not match the caller");
            }
        } catch (PackageManager.NameNotFoundException e) {
            throw new SecurityException("Passed in PackageName can not be found on device");
        }

        final long identity = Binder.clearCallingIdentity();
        SipTransportController transport = getRcsFeatureController(subId).getFeature(
                SipTransportController.class);
        if (transport == null) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "This subscription does not support the creation of SIP delegates");
        }
        try {
            transport.createSipDelegate(subId, request, packageName, delegateState,
                    delegateMessage);
        } catch (ImsException e) {
            throw new ServiceSpecificException(e.getCode(), e.getMessage());
        } finally {
            Binder.restoreCallingIdentity(identity);
        }
    }

    @Override
    public void destroySipDelegate(int subId, ISipDelegate connection, int reason) {
        // Do not check permissions here - the caller needs to have a connection already from the
        // create method to call this method.
        if (connection == null) {
            return;
        }
        final long identity = Binder.clearCallingIdentity();
        try {
            SipTransportController transport = getRcsFeatureController(subId).getFeature(
                    SipTransportController.class);
            if (transport == null) {
                return;
            }
            transport.destroySipDelegate(subId, connection, reason);
        } catch (ServiceSpecificException e) {
            Log.e(TAG, "destroySipDelegate: error=" + e.errorCode);
        } finally {
            Binder.restoreCallingIdentity(identity);
        }
    }

    @Override
    public void triggerNetworkRegistration(int subId, ISipDelegate connection, int sipCode,
            String sipReason) {
        enforceImsSingleRegistrationPermission("triggerNetworkRegistration");

        final long identity = Binder.clearCallingIdentity();
        try {
            SipTransportController transport = getRcsFeatureController(subId).getFeature(
                    SipTransportController.class);
            if (transport == null) {
                return;
            }
            transport.triggerFullNetworkRegistration(subId, connection, sipCode, sipReason);
        } catch (ServiceSpecificException e) {
            Log.e(TAG, "triggerNetworkRegistration: error=" + e.errorCode);
        } finally {
            Binder.restoreCallingIdentity(identity);
        }
    }

    /**
     * Registers for updates to the RcsFeature connection through the IImsServiceFeatureCallback
     * callback.
     */
    @Override
    public void registerRcsFeatureCallback(int slotId, IImsServiceFeatureCallback callback) {
        enforceModifyPermission();

        final long identity = Binder.clearCallingIdentity();
        try {
            if (mImsResolver == null) {
                throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                        "Device does not support IMS");
            }
            mImsResolver.listenForFeature(slotId, ImsFeature.FEATURE_RCS, callback);
        } finally {
            Binder.restoreCallingIdentity(identity);
        }
    }

    /**
     * Unregister a previously registered IImsServiceFeatureCallback associated with an ImsFeature.
     */
    @Override
    public void unregisterImsFeatureCallback(IImsServiceFeatureCallback callback) {
        enforceModifyPermission();

        final long identity = Binder.clearCallingIdentity();
        try {
            if (mImsResolver == null) return;
            mImsResolver.unregisterImsFeatureCallback(callback);
        } finally {
            Binder.restoreCallingIdentity(identity);
        }
    }

    /**
     * Make sure either called from same process as self (phone) or IPC caller has read privilege.
     *
     * @throws SecurityException if the caller does not have the required permission
     */
    private void enforceReadPrivilegedPermission(String message) {
        mApp.enforceCallingOrSelfPermission(
                android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE, message);
    }

    /**
     * @throws SecurityException if the caller does not have the required
     *     PERFORM_IMS_SINGLE_REGISTRATION permission.
     */
    private void enforceImsSingleRegistrationPermission(String message) {
        mApp.enforceCallingOrSelfPermission(
                Manifest.permission.PERFORM_IMS_SINGLE_REGISTRATION, message);
    }

    /**
     * Make sure the caller has the MODIFY_PHONE_STATE permission.
     *
     * @throws SecurityException if the caller does not have the required permission
     */
    private void enforceModifyPermission() {
        mApp.enforceCallingOrSelfPermission(android.Manifest.permission.MODIFY_PHONE_STATE, null);
    }

    /**
     * Make sure the caller has the ACCESS_RCS_USER_CAPABILITY_EXCHANGE permission.
     *
     * @throws SecurityException if the caller does not have the required permission.
     */
    private void enforceAccessUserCapabilityExchangePermission(String message) {
        mApp.enforceCallingOrSelfPermission(
                android.Manifest.permission.ACCESS_RCS_USER_CAPABILITY_EXCHANGE, message);
    }

    /**
     * Make sure the caller has the READ_CONTACTS permission.
     *
     * @throws SecurityException if the caller does not have the required permission.
     */
    private void enforceReadContactsPermission(String message) {
        mApp.enforceCallingOrSelfPermission(
                android.Manifest.permission.READ_CONTACTS, message);
    }

    /**
     * Retrieve RcsFeatureManager instance.
     *
     * @param subId the subscription ID
     * @return The RcsFeatureManager instance
     * @throws ServiceSpecificException if getting RcsFeatureManager instance failed.
     */
    private RcsFeatureController getRcsFeatureController(int subId) {
        return getRcsFeatureController(subId, false /* skipVerifyingConfig */);
    }

    /**
     * Retrieve RcsFeatureManager instance.
     *
     * @param subId the subscription ID
     * @param skipVerifyingConfig If the RCS configuration can be skip.
     * @return The RcsFeatureManager instance
     * @throws ServiceSpecificException if getting RcsFeatureManager instance failed.
     */
    private RcsFeatureController getRcsFeatureController(int subId, boolean skipVerifyingConfig) {
        if (!ImsManager.isImsSupportedOnDevice(mApp)) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "IMS is not available on device.");
        }
        if (mRcsService == null) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "IMS is not available on device.");
        }
        Phone phone = PhoneGlobals.getPhone(subId);
        if (phone == null) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_INVALID_SUBSCRIPTION,
                    "Invalid subscription Id: " + subId);
        }
        int slotId = phone.getPhoneId();
        if (!skipVerifyingConfig) {
            verifyImsRcsConfiguredOrThrow(slotId);
        }
        RcsFeatureController c = mRcsService.getFeatureController(slotId);
        if (c == null) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "The requested operation is not supported for subId " + subId);
        }
        return c;
    }

    /**
     * Throw an ImsException if the IMS resolver does not have an ImsService configured for RCS
     * for the given slot ID or no ImsResolver instance has been created.
     * @param slotId The slot ID that the IMS service is created for.
     * @throws ServiceSpecificException If there is no ImsService configured for this slot.
     */
    private void verifyImsRcsConfiguredOrThrow(int slotId) {
        if (mImsResolver == null
                || !mImsResolver.isImsServiceConfiguredForFeature(slotId, ImsFeature.FEATURE_RCS)) {
            throw new ServiceSpecificException(ImsException.CODE_ERROR_UNSUPPORTED_OPERATION,
                    "This subscription does not support RCS");
        }
    }

    private boolean isImsSingleRegistrationSupportedOnDevice() {
        return mSingleRegistrationOverride != null ? mSingleRegistrationOverride
                : mApp.getPackageManager().hasSystemFeature(
                        PackageManager.FEATURE_TELEPHONY_IMS_SINGLE_REGISTRATION);
    }

    void setRcsService(TelephonyRcsService rcsService) {
        mRcsService = rcsService;
    }

    /**
     * Override device RCS single registration support check for CTS testing or remove override
     * if the Boolean is set to null.
     */
    void setDeviceSingleRegistrationSupportOverride(Boolean deviceOverrideValue) {
        mSingleRegistrationOverride = deviceOverrideValue;
    }
}
