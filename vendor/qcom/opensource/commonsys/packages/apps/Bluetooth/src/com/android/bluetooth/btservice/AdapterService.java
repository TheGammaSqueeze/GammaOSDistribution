/*
 * Copyright (C) 2017, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the
 * disclaimer below) provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 * * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 * GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright (C) 2012 The Android Open Source Project
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

package com.android.bluetooth.btservice;

import static android.text.format.DateUtils.MINUTE_IN_MILLIS;
import static android.text.format.DateUtils.SECOND_IN_MILLIS;

import static com.android.bluetooth.Utils.addressToBytes;
import static com.android.bluetooth.Utils.callerIsSystemOrActiveOrManagedUser;
import static com.android.bluetooth.Utils.callerIsSystemOrActiveUser;
import static com.android.bluetooth.Utils.enforceBluetoothPrivilegedPermission;
import static com.android.bluetooth.Utils.enforceCdmAssociation;
import static com.android.bluetooth.Utils.hasBluetoothPrivilegedPermission;
import static com.android.bluetooth.Utils.enforceDumpPermission;
import static com.android.bluetooth.Utils.enforceLocalMacAddressPermission;
import static com.android.bluetooth.Utils.hasBluetoothPrivilegedPermission;
import static com.android.bluetooth.Utils.isPackageNameAccurate;

import android.annotation.NonNull;
import android.annotation.RequiresPermission;
import android.annotation.SuppressLint;
import android.app.ActivityManager;
import android.app.AlarmManager;
import android.app.AppOpsManager;
import android.app.PendingIntent;
import android.app.PropertyInvalidatedCache;
import android.app.Service;
import android.bluetooth.BluetoothA2dp;
import android.app.admin.DevicePolicyManager;
import android.bluetooth.BluetoothActivityEnergyInfo;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothAdapter.ActiveDeviceUse;
import android.bluetooth.BluetoothClass;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothProfile;
import android.bluetooth.BluetoothProtoEnums;
import android.bluetooth.BluetoothStatusCodes;
import android.bluetooth.BluetoothUuid;
import android.bluetooth.BufferConstraints;
import android.bluetooth.IBluetooth;
import android.bluetooth.IBluetoothCallback;
import android.bluetooth.IBluetoothConnectionCallback;
import android.bluetooth.IBluetoothMetadataListener;
import android.bluetooth.IBluetoothOobDataCallback;
import android.bluetooth.IBluetoothSocketManager;
import android.bluetooth.OobData;
import android.bluetooth.UidTraffic;
import android.companion.CompanionDeviceManager;
import android.content.AttributionSource;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.os.AsyncTask;
import android.os.BatteryStats;
import android.os.Binder;
import android.os.Bundle;
import android.os.BytesMatcher;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.ParcelUuid;
import android.os.PowerManager;
import android.os.Process;
import android.os.RemoteCallbackList;
import android.os.RemoteException;
import android.os.ResultReceiver;
import android.os.ServiceManager;
import android.os.SystemClock;
import android.os.SystemProperties;
import android.os.UserHandle;
import android.os.UserManager;
import android.provider.DeviceConfig;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Base64;
import android.util.Log;
import android.util.SparseArray;

import com.android.bluetooth.BluetoothMetricsProto;
import com.android.bluetooth.BluetoothStatsLog;
import com.android.bluetooth.Utils;
import com.android.bluetooth.a2dp.A2dpService;
import com.android.bluetooth.a2dpsink.A2dpSinkService;
import com.android.bluetooth.apm.ApmConstIntf;
import com.android.bluetooth.apm.ActiveDeviceManagerServiceIntf;
import com.android.bluetooth.apm.MediaAudioIntf;
import com.android.bluetooth.apm.CallAudioIntf;
import com.android.bluetooth.btservice.RemoteDevices.DeviceProperties;
import com.android.bluetooth.btservice.bluetoothkeystore.BluetoothKeystoreService;
import com.android.bluetooth.btservice.storage.DatabaseManager;
import com.android.bluetooth.btservice.storage.MetadataDatabase;
import com.android.bluetooth.btservice.AdapterState;
import com.android.bluetooth.gatt.GattService;
import com.android.bluetooth.hearingaid.HearingAidService;
import com.android.bluetooth.hfp.HeadsetService;
import com.android.bluetooth.hfpclient.HeadsetClientService;
import com.android.bluetooth.hid.HidDeviceService;
import com.android.bluetooth.hid.HidHostService;
import com.android.bluetooth.map.BluetoothMapService;
import com.android.bluetooth.mapclient.MapClientService;
import com.android.bluetooth.pan.PanService;
import com.android.bluetooth.pbap.BluetoothPbapService;
import com.android.bluetooth.pbapclient.PbapClientService;
import com.android.bluetooth.ReflectionUtils;
import com.android.bluetooth.sap.SapService;
import com.android.bluetooth.sdp.SdpManager;
import com.android.bluetooth.ba.BATService;
import com.android.internal.R;
import com.android.internal.annotations.GuardedBy;
import com.android.internal.annotations.VisibleForTesting;
import com.android.internal.app.IBatteryStats;
import com.android.internal.os.BackgroundThread;
import com.android.internal.os.BinderCallsStats;
import com.android.internal.util.ArrayUtils;
import android.media.MediaMetadata;

import java.lang.reflect.*;

import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.net.NetworkInfo;
import android.os.ParcelUuid;
import android.net.wifi.SoftApConfiguration;

import com.google.protobuf.InvalidProtocolBufferException;

import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.function.Predicate;
import java.util.UUID;
import java.util.regex.Pattern;

public class AdapterService extends Service {
    private static final String TAG = "BluetoothAdapterService";
    private static final boolean DBG = true;
    private static final boolean VERBOSE = false;
    private static final int MIN_ADVT_INSTANCES_FOR_MA = 5;
    private static final int MIN_OFFLOADED_FILTERS = 10;
    private static final int MIN_OFFLOADED_SCAN_STORAGE_BYTES = 1024;

    private final Object mEnergyInfoLock = new Object();
    private int mStackReportedState;
    private long mTxTimeTotalMs;
    private long mRxTimeTotalMs;
    private long mIdleTimeTotalMs;
    private long mEnergyUsedTotalVoltAmpSecMicro;
    private WifiManager mWifiManager;
    private final SparseArray<UidTraffic> mUidTraffic = new SparseArray<>();

    private final ArrayList<ProfileService> mRegisteredProfiles = new ArrayList<>();
    private final ArrayList<ProfileService> mRunningProfiles = new ArrayList<>();

    public static final String ACTION_LOAD_ADAPTER_PROPERTIES =
            "com.android.bluetooth.btservice.action.LOAD_ADAPTER_PROPERTIES";
    public static final String ACTION_SERVICE_STATE_CHANGED =
            "com.android.bluetooth.btservice.action.STATE_CHANGED";
    public static final String EXTRA_ACTION = "action";
    public static final int PROFILE_CONN_REJECTED = 2;
    public static final int  SOFT_AP_BAND_DUAL = 1 << 3;

    private static final String ACTION_ALARM_WAKEUP =
            "com.android.bluetooth.btservice.action.ALARM_WAKEUP";

    static final String BLUETOOTH_BTSNOOP_LOG_MODE_PROPERTY = "persist.bluetooth.btsnooplogmode";
    static final String BLUETOOTH_BTSNOOP_DEFAULT_MODE_PROPERTY =
            "persist.bluetooth.btsnoopdefaultmode";
    private String mSnoopLogSettingAtEnable = "empty";
    private String mDefaultSnoopLogSettingAtEnable = "empty";

    public static final String BLUETOOTH_PRIVILEGED =
            android.Manifest.permission.BLUETOOTH_PRIVILEGED;
    static final String LOCAL_MAC_ADDRESS_PERM = android.Manifest.permission.LOCAL_MAC_ADDRESS;
    static final String RECEIVE_MAP_PERM = android.Manifest.permission.RECEIVE_BLUETOOTH_MAP;

    private static final String PHONEBOOK_ACCESS_PERMISSION_PREFERENCE_FILE =
            "phonebook_access_permission";
    private static final String MESSAGE_ACCESS_PERMISSION_PREFERENCE_FILE =
            "message_access_permission";
    private static final String SIM_ACCESS_PERMISSION_PREFERENCE_FILE = "sim_access_permission";

    private static final int CONTROLLER_ENERGY_UPDATE_TIMEOUT_MILLIS = 30;
    private static final int DELAY_A2DP_SLEEP_MILLIS = 100;
    private static final int GROUP_ID_START = 1;
    private static final int GROUP_ID_END = 15;
    private static final int TYPE_BREDR = 100;
    private static final int TYPE_PRIVATE_ADDRESS = 101;
    private static final int INVALID_GROUP_ID = 16;


    private static final UUID EMPTY_UUID = UUID.fromString("00000000-0000-0000-0000-000000000000");

    private final ArrayList<DiscoveringPackage> mDiscoveringPackages = new ArrayList<>();
    static {
        System.loadLibrary("bluetooth_qti_jni");
        classInitNative();
    }

    private static AdapterService sAdapterService;

    public static synchronized AdapterService getAdapterService() {
        if (VERBOSE) {
            Log.v(TAG, "getAdapterService " + sAdapterService);
        }
        return sAdapterService;
    }

    private static synchronized void setAdapterService(AdapterService instance) {
        if (DBG) {
            Log.d(TAG, "setAdapterService " + instance);
        }
        if (instance == null) {
            return;
        }
        sAdapterService = instance;
    }

    private static synchronized void clearAdapterService(AdapterService current) {
        if (sAdapterService == current) {
            sAdapterService = null;
        }
    }

    private AdapterProperties mAdapterProperties;
    private AdapterState mAdapterStateMachine;
    private Vendor mVendor;
    private boolean mVendorAvailble;
    private BondStateMachine mBondStateMachine;
    private JniCallbacks mJniCallbacks;
    private RemoteDevices mRemoteDevices;

    /* TODO: Consider to remove the search API from this class, if changed to use call-back*/
    private SdpManager mSdpManager = null;

    private boolean mNativeAvailable;
    private boolean mCleaningUp;
    private final HashMap<BluetoothDevice, ArrayList<IBluetoothMetadataListener>>
            mMetadataListeners = new HashMap<>();
    private final HashMap<String, Integer> mProfileServicesState = new HashMap<String, Integer>();
    private Set<IBluetoothConnectionCallback> mBluetoothConnectionCallbacks = new HashSet<>();
    //Only BluetoothManagerService should be registered
    private RemoteCallbackList<IBluetoothCallback> mCallbacks;
    private int mCurrentRequestId;
    private boolean mQuietmode = false;

    private AlarmManager mAlarmManager;
    private PendingIntent mPendingAlarm;
    private IBatteryStats mBatteryStats;
    private PowerManager mPowerManager;
    private PowerManager.WakeLock mWakeLock;
    private String mWakeLockName;
    private UserManager mUserManager;
    private static BluetoothAdapter mAdapter;
    private CompanionDeviceManager mCompanionDeviceManager;
    private ProfileObserver mProfileObserver;
    private PhonePolicy mPhonePolicy;
    private ActiveDeviceManager mActiveDeviceManager;
    private DatabaseManager mDatabaseManager;
    private SilenceDeviceManager mSilenceDeviceManager;
    private AppOpsManager mAppOps;
    private VendorSocket mVendorSocket;

    private BluetoothKeystoreService mBluetoothKeystoreService;
    private A2dpService mA2dpService;
    private A2dpSinkService mA2dpSinkService;
    private HeadsetService mHeadsetService;
    private HeadsetClientService mHeadsetClientService;
    private BluetoothMapService mMapService;
    private MapClientService mMapClientService;
    private HidDeviceService mHidDeviceService;
    private HidHostService mHidHostService;
    private PanService mPanService;
    private BluetoothPbapService mPbapService;
    private PbapClientService mPbapClientService;
    private HearingAidService mHearingAidService;
    private Object mGroupService;
    private SapService mSapService;
    private GattService mGattService;

    ///*_REF
    Object mBCService = null;
    Method mBCGetService = null;
    Method mBCGetConnPolicy = null;
    Method mBCSetConnPolicy = null;
    Method mBCConnect = null;
    Method mBCDisconnect = null;
    Method mBCGetConnState = null;
    String mBCId = null;
    String mBSId = null;
    Object mBroadcastService = null;
    Method mBroadcastGetService = null;
    Method mBroadcastIsActive = null;
    Method mBroadcastIsStreaming = null;
    Method mBroadcastNotifyState = null;
    Method mBroadcastGetAddr = null;
    Method mBroadcastDevice = null;
    Method mBroadcastMeta = null;

    private volatile boolean mTestModeEnabled = false;

    //_REF*/
    /**
     * Register a {@link ProfileService} with AdapterService.
     *
     * @param profile the service being added.
     */
    public void addProfile(ProfileService profile) {
        mHandler.obtainMessage(MESSAGE_PROFILE_SERVICE_REGISTERED, profile).sendToTarget();
    }

    /**
     * Unregister a ProfileService with AdapterService.
     *
     * @param profile the service being removed.
     */
    public void removeProfile(ProfileService profile) {
        mHandler.obtainMessage(MESSAGE_PROFILE_SERVICE_UNREGISTERED, profile).sendToTarget();
    }

    /**
     * Notify AdapterService that a ProfileService has started or stopped.
     *
     * @param profile the service being removed.
     * @param state {@link BluetoothAdapter#STATE_ON} or {@link BluetoothAdapter#STATE_OFF}
     */
    public void onProfileServiceStateChanged(ProfileService profile, int state) {
        if (state != BluetoothAdapter.STATE_ON && state != BluetoothAdapter.STATE_OFF) {
            throw new IllegalArgumentException(BluetoothAdapter.nameForState(state));
        }
        Message m = mHandler.obtainMessage(MESSAGE_PROFILE_SERVICE_STATE_CHANGED);
        m.obj = profile;
        m.arg1 = state;
        mHandler.sendMessage(m);
    }

    public boolean getProfileInfo(int profile_id , int profile_info) {
        if (isVendorIntfEnabled()) {
            return mVendor.getProfileInfo(profile_id, profile_info);
        } else {
            return false;
        }
    }

    private void fetchWifiState() {
        if (!isVendorIntfEnabled()) {
            return;
        }
        boolean isWifiConnected = false;
        WifiManager wifiMgr = (WifiManager) getSystemService(Context.WIFI_SERVICE);
        if ((wifiMgr != null) && (wifiMgr.isWifiEnabled())) {
            WifiInfo wifiInfo = wifiMgr.getConnectionInfo();
            if((wifiInfo != null) && (wifiInfo.getNetworkId() != -1)) {
                isWifiConnected = true;
            }
        }
        mVendor.setWifiState(isWifiConnected);
    }

    public void StartHCIClose() {
        if (isVendorIntfEnabled()) {
            mVendor.HCIClose();
        }
    }

     public void voipNetworkWifiInfo(boolean isVoipStarted, boolean isNetworkWifi) {
        debugLog("In voipNetworkWifiInfo, isVoipStarted: " + isVoipStarted +
                    ", isNetworkWifi: " + isNetworkWifi);
        mVendor.voipNetworkWifiInformation(isVoipStarted, isNetworkWifi);
    }

    public String getSocName() {
        return mVendor.getSocName();
    }

    public String getA2apOffloadCapability() {
        return mVendor.getA2apOffloadCapability();
    }

    public boolean isSplitA2dpEnabled() {
        return mVendor.isSplitA2dpEnabled();
    }

    public boolean isSwbEnabled() {
        return mVendor.isSwbEnabled();
    }
    public boolean isSwbPmEnabled() {
        return mVendor.isSwbPmEnabled();
    }

    private static final int MESSAGE_PROFILE_SERVICE_STATE_CHANGED = 1;
    private static final int MESSAGE_PROFILE_SERVICE_REGISTERED = 2;
    private static final int MESSAGE_PROFILE_SERVICE_UNREGISTERED = 3;

    class AdapterServiceHandler extends Handler {
        @Override
        public void handleMessage(Message msg) {
            verboseLog("handleMessage() - Message: " + msg.what);

            switch (msg.what) {
                case MESSAGE_PROFILE_SERVICE_STATE_CHANGED:
                    verboseLog("handleMessage() - MESSAGE_PROFILE_SERVICE_STATE_CHANGED");
                    processProfileServiceStateChanged((ProfileService) msg.obj, msg.arg1);
                    break;
                case MESSAGE_PROFILE_SERVICE_REGISTERED:
                    verboseLog("handleMessage() - MESSAGE_PROFILE_SERVICE_REGISTERED");
                    registerProfileService((ProfileService) msg.obj);
                    break;
                case MESSAGE_PROFILE_SERVICE_UNREGISTERED:
                    verboseLog("handleMessage() - MESSAGE_PROFILE_SERVICE_UNREGISTERED");
                    unregisterProfileService((ProfileService) msg.obj);
                    break;
            }
        }

        private void registerProfileService(ProfileService profile) {
            if (mRegisteredProfiles.contains(profile)) {
                errorLog(profile.getName() + " already registered.");
                return;
            }
            mRegisteredProfiles.add(profile);
        }

        private void unregisterProfileService(ProfileService profile) {
            if (!mRegisteredProfiles.contains(profile)) {
                errorLog( profile.getName() + " not registered (UNREGISTER).");
                return;
            }
            mRegisteredProfiles.remove(profile);
        }

        private void processProfileServiceStateChanged(ProfileService profile, int state) {
            switch (state) {
                case BluetoothAdapter.STATE_ON:
                    if (!mRegisteredProfiles.contains(profile)) {
                        Log.e(TAG, profile.getName() + " not registered (STATE_ON).");
                        return;
                    }
                    if (mRunningProfiles.contains(profile)) {
                        Log.e(TAG, profile.getName() + " already running.");
                        return;
                    }
                    mRunningProfiles.add(profile);
                    if (GattService.class.getSimpleName().equals(profile.getName())) {
                        Log.w(TAG,"onProfileServiceStateChange() - Gatt profile service started..");
                        enableNative();
                    } else if (mRegisteredProfiles.size() == Config.getSupportedProfiles().length
                            && mRegisteredProfiles.size() == mRunningProfiles.size()) {
                        Log.w(TAG,"onProfileServiceStateChange() - All profile services started..");
                        mAdapterProperties.onBluetoothReady();
                        updateUuids();
                        setBluetoothClassFromConfig();
                        initProfileServices();
                        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_LOCAL_IO_CAPS);
                        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_LOCAL_IO_CAPS_BLE);
                        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_DYNAMIC_AUDIO_BUFFER);
                        mAdapterStateMachine.sendMessage(AdapterState.BREDR_STARTED);
                        //update wifi state to lower layers
                        fetchWifiState();
                        if (isVendorIntfEnabled()) {
                            if (isPowerbackRequired()) {
                                mVendor.setPowerBackoff(true);
                            } else {
                                mVendor.setPowerBackoff(false);
                            }
                        }
                    }
                    break;
                case BluetoothAdapter.STATE_OFF:
                    if (!mRegisteredProfiles.contains(profile)) {
                        Log.e(TAG, profile.getName() + " not registered (STATE_OFF).");
                        return;
                    }
                    if (!mRunningProfiles.contains(profile)) {
                        Log.e(TAG, profile.getName() + " not running.");
                        return;
                    }
                    mRunningProfiles.remove(profile);
                    // If only GATT is left, send BREDR_STOPPED.
                    if ((mRunningProfiles.size() == 1 && (GattService.class.getSimpleName()
                            .equals(mRunningProfiles.get(0).getName())))) {
                        Log.w(TAG,"onProfileServiceStateChange() - All profile services except gatt stopped..");
                        mAdapterStateMachine.sendMessage(AdapterState.BREDR_STOPPED);
                    } else if (mRunningProfiles.size() == 0) {
                        Log.w(TAG,"onProfileServiceStateChange() - All profile services stopped..");
                        mAdapterStateMachine.sendMessage(AdapterState.BLE_STOPPED);
                        disableNative();
                    }
                    break;
                default:
                    Log.e(TAG, "Unhandled profile state: " + state);
            }
        }
    }

    private final AdapterServiceHandler mHandler = new AdapterServiceHandler();

    private void updateInteropDatabase() {
        interopDatabaseClearNative();

        String interopString = Settings.Global.getString(getContentResolver(),
                Settings.Global.BLUETOOTH_INTEROPERABILITY_LIST);
        if (interopString == null) {
            return;
        }
        Log.d(TAG, "updateInteropDatabase: [" + interopString + "]");

        String[] entries = interopString.split(";");
        for (String entry : entries) {
            String[] tokens = entry.split(",");
            if (tokens.length != 2) {
                continue;
            }

            // Get feature
            int feature = 0;
            try {
                feature = Integer.parseInt(tokens[1]);
            } catch (NumberFormatException e) {
                Log.e(TAG, "updateInteropDatabase: Invalid feature '" + tokens[1] + "'");
                continue;
            }

            // Get address bytes and length
            int length = (tokens[0].length() + 1) / 3;
            if (length < 1 || length > 6) {
                Log.e(TAG, "updateInteropDatabase: Malformed address string '" + tokens[0] + "'");
                continue;
            }

            byte[] addr = new byte[6];
            int offset = 0;
            for (int i = 0; i < tokens[0].length(); ) {
                if (tokens[0].charAt(i) == ':') {
                    i += 1;
                } else {
                    try {
                        addr[offset++] = (byte) Integer.parseInt(tokens[0].substring(i, i + 2), 16);
                    } catch (NumberFormatException e) {
                        offset = 0;
                        break;
                    }
                    i += 2;
                }
            }

            // Check if address was parsed ok, otherwise, move on...
            if (offset == 0) {
                continue;
            }

            // Add entry
            interopDatabaseAddNative(feature, addr, length);
        }
    }

    @Override
    public void onCreate() {
        super.onCreate();
        debugLog("onCreate()");
        mAdapter = BluetoothAdapter.getDefaultAdapter();
        mDeviceConfigListener.start();
        mRemoteDevices = new RemoteDevices(this, Looper.getMainLooper());
        mRemoteDevices.init();
        clearDiscoveringPackages();
        mBinder = new AdapterServiceBinder(this);
        mAdapterProperties = new AdapterProperties(this);
        mVendor = new Vendor(this);
        mAdapterStateMachine =  AdapterState.make(this);
        mJniCallbacks = new JniCallbacks(this, mAdapterProperties);
        mVendorSocket = new VendorSocket(this);
        mBluetoothKeystoreService = new BluetoothKeystoreService(isCommonCriteriaMode());
        mBluetoothKeystoreService.start();
        int configCompareResult = mBluetoothKeystoreService.getCompareResult();

        // Android TV doesn't show consent dialogs for just works and encryption only le pairing
        boolean isAtvDevice = getApplicationContext().getPackageManager().hasSystemFeature(
                PackageManager.FEATURE_LEANBACK_ONLY);
        initNative(isGuest(), isCommonCriteriaMode(), configCompareResult, isAtvDevice, getInitFlags());
        mNativeAvailable = true;
        mCallbacks = new RemoteCallbackList<IBluetoothCallback>();
        mAppOps = getSystemService(AppOpsManager.class);
        //Load the name and address
        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_BDADDR);
        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_BDNAME);
        getAdapterPropertyNative(AbstractionLayer.BT_PROPERTY_CLASS_OF_DEVICE);
        mAlarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
        mPowerManager = (PowerManager) getSystemService(Context.POWER_SERVICE);
        mUserManager = (UserManager) getSystemService(Context.USER_SERVICE);
        mBatteryStats = IBatteryStats.Stub.asInterface(
                ServiceManager.getService(BatteryStats.SERVICE_NAME));
        mCompanionDeviceManager = getSystemService(CompanionDeviceManager.class);
        mBluetoothKeystoreService.initJni();

        mSdpManager = SdpManager.init(this);
        registerReceiver(mAlarmBroadcastReceiver, new IntentFilter(ACTION_ALARM_WAKEUP));
        IntentFilter wifiFilter = new IntentFilter();
        wifiFilter.addAction(WifiManager.NETWORK_STATE_CHANGED_ACTION);
        wifiFilter.addAction(WifiManager.WIFI_AP_STATE_CHANGED_ACTION);
        wifiFilter.addAction(WifiManager.WIFI_STATE_CHANGED_ACTION);
        registerReceiver(mWifiStateBroadcastReceiver, wifiFilter);
        mProfileObserver = new ProfileObserver(getApplicationContext(), this, new Handler());
        mProfileObserver.start();

        mDatabaseManager = new DatabaseManager(this);
        mDatabaseManager.start(MetadataDatabase.createDatabase(this));

        // Phone policy is specific to phone implementations and hence if a device wants to exclude
        // it out then it can be disabled by using the flag below.
        if (getResources().getBoolean(com.android.bluetooth.R.bool.enable_phone_policy)) {
            debugLog("Phone policy enabled");
            mPhonePolicy = new PhonePolicy(this, new ServiceFactory());
            mPhonePolicy.start();
        } else {
            debugLog ("Phone policy disabled");
        }
        mBondStateMachine = BondStateMachine.make(mPowerManager, this, mAdapterProperties, mRemoteDevices);

        mActiveDeviceManager = new ActiveDeviceManager(this, new ServiceFactory());
        mActiveDeviceManager.start();

        mSilenceDeviceManager = new SilenceDeviceManager(this, new ServiceFactory(),
                Looper.getMainLooper());
        mSilenceDeviceManager.start();

        setAdapterService(this);

        invalidateBluetoothCaches();

        // First call to getSharedPreferences will result in a file read into
        // memory cache. Call it here asynchronously to avoid potential ANR
        // in the future
        new AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... params) {
                getSharedPreferences(PHONEBOOK_ACCESS_PERMISSION_PREFERENCE_FILE,
                        Context.MODE_PRIVATE);
                getSharedPreferences(MESSAGE_ACCESS_PERMISSION_PREFERENCE_FILE,
                        Context.MODE_PRIVATE);
                getSharedPreferences(SIM_ACCESS_PERMISSION_PREFERENCE_FILE, Context.MODE_PRIVATE);
                return null;
            }
        }.execute();
        mVendor.init();
        mVendorAvailble = mVendor.getQtiStackStatus();
        mVendorSocket.init();

        try {
            int systemUiUid = getApplicationContext().getPackageManager().getPackageUid(
                    "com.android.systemui", PackageManager.MATCH_SYSTEM_ONLY);

            Utils.setSystemUiUid(systemUiUid);
            setSystemUiUidNative(systemUiUid);
        } catch (PackageManager.NameNotFoundException e) {
            // Some platforms, such as wearables do not have a system ui.
            Log.w(TAG, "Unable to resolve SystemUI's UID.", e);
        }

        IntentFilter filter = new IntentFilter(Intent.ACTION_USER_SWITCHED);
        getApplicationContext().registerReceiverForAllUsers(sUserSwitchedReceiver, filter, null, null);
        int fuid = ActivityManager.getCurrentUser();
        Utils.setForegroundUserId(fuid);
        setForegroundUserIdNative(fuid);

        // Reset |mRemoteDevices| whenever BLE is turned off then on
        // This is to replace the fact that |mRemoteDevices| was
        // reinitialized in previous code.
        //
        // TODO(apanicke): The reason is unclear but
        // I believe it is to clear the variable every time BLE was
        // turned off then on. The same effect can be achieved by
        // calling cleanup but this may not be necessary at all
        // We should figure out why this is needed later
        mRemoteDevices.reset();
        mAdapterProperties.init(mRemoteDevices);
    }

    @Override
    public IBinder onBind(Intent intent) {
        debugLog("onBind()");
        return mBinder;
    }

    @Override
    public boolean onUnbind(Intent intent) {
        debugLog("onUnbind() - calling cleanup");
        cleanup();
        return super.onUnbind(intent);
    }

    @Override
    public void onDestroy() {
        debugLog("onDestroy()");
        mProfileObserver.stop();
        if (!isMock()) {
            // TODO(b/27859763)
            Log.i(TAG, "Force exit to cleanup internal state in Bluetooth stack");
            System.exit(0);
        }
    }

    public static final BroadcastReceiver sUserSwitchedReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (Intent.ACTION_USER_SWITCHED.equals(intent.getAction())) {
                int fuid = intent.getIntExtra(Intent.EXTRA_USER_HANDLE, 0);
                Utils.setForegroundUserId(fuid);
                setForegroundUserIdNative(fuid);
            }
        }
    };

    void bringUpBle() {
        debugLog("bleOnProcessStart()");
        /* To reload profile support in BLE turning ON state. So even if profile support
         *  is disabled in Bluetooth Adapter turned off state(10), this flag will ensure
         *  rechecking profile support after BT is turned ON
         */
        if (getResources().getBoolean(
                com.android.bluetooth.R.bool.reload_supported_profiles_when_enabled)) {
            Config.init(getApplicationContext());
        }

        debugLog("BleOnProcessStart() - Make Bond State Machine");

        mJniCallbacks.init(mBondStateMachine, mRemoteDevices);

        try {
            mBatteryStats.noteResetBleScan();
        } catch (RemoteException e) {
            Log.w(TAG, "RemoteException trying to send a reset to BatteryStats");
        }
        BluetoothStatsLog.write_non_chained(BluetoothStatsLog.BLE_SCAN_STATE_CHANGED, -1, null,
                BluetoothStatsLog.BLE_SCAN_STATE_CHANGED__STATE__RESET, false, false, false);

        //Start Gatt service
        setProfileServiceState(GattService.class, BluetoothAdapter.STATE_ON);
    }

    void bringDownBle() {
        stopGattProfileService();
    }

    void stateChangeCallback(int status) {
        if (status == AbstractionLayer.BT_STATE_OFF) {
            debugLog("stateChangeCallback: disableNative() completed");
            mAdapterStateMachine.sendMessage(AdapterState.STACK_DISABLED);
        } else if (status == AbstractionLayer.BT_STATE_ON) {
            String BT_SOC = getSocName();

            if (BT_SOC.equals("pronto")) {
                debugLog( "setting max audio connection to 2");
                mAdapterProperties.setMaxConnectedAudioDevices(2);
            }
            mAdapterStateMachine.sendMessage(AdapterState.BLE_STARTED);
        } else {
            Log.e(TAG, "Incorrect status " + status + " in stateChangeCallback");
        }
    }

    void ssrCleanupCallback() {
        disableProfileServices(false);
        Log.e(TAG, "Disabling the BluetoothInCallService component"+
                " and kill the process to recover");
        getApplicationContext().getPackageManager().setComponentEnabledSetting(
            AdapterState.BLUETOOTH_INCALLSERVICE_COMPONENT,
            PackageManager.COMPONENT_ENABLED_STATE_DISABLED,
            PackageManager.DONT_KILL_APP);
        android.os.Process.killProcess(android.os.Process.myPid());
    }

    /**
     * Sets the Bluetooth CoD value of the local adapter if there exists a config value for it.
     */
    void setBluetoothClassFromConfig() {
        int bluetoothClassConfig = retrieveBluetoothClassConfig();
        if (bluetoothClassConfig != 0) {
            mAdapterProperties.setBluetoothClass(new BluetoothClass(bluetoothClassConfig));
        }
    }

    private int retrieveBluetoothClassConfig() {
        return Settings.Global.getInt(
                getContentResolver(), Settings.Global.BLUETOOTH_CLASS_OF_DEVICE, 0);
    }

    private boolean storeBluetoothClassConfig(int bluetoothClass) {
        boolean result = Settings.Global.putInt(
                getContentResolver(), Settings.Global.BLUETOOTH_CLASS_OF_DEVICE, bluetoothClass);

        if (!result) {
            Log.e(TAG, "Error storing BluetoothClass config - " + bluetoothClass);
        }

        return result;
    }

    void startBluetoothDisable() {
        mAdapterStateMachine.sendMessage(AdapterState.BEGIN_BREDR_STOP);
    }

    void startProfileServices() {
        debugLog("startCoreServices()");
        Config.initAdvAudioSupport(getApplicationContext());
        Class[] supportedProfileServices = Config.getSupportedProfiles();
        if (supportedProfileServices.length == 1 && GattService.class.getSimpleName()
                .equals(supportedProfileServices[0].getSimpleName())) {
            mAdapterProperties.onBluetoothReady();
            updateUuids();
            setBluetoothClassFromConfig();
            mAdapterStateMachine.sendMessage(AdapterState.BREDR_STARTED);
        } else {
            setAllProfileServiceStates(supportedProfileServices, BluetoothAdapter.STATE_ON);
        }
    }

    void startBrEdrStartup(){
        if (isVendorIntfEnabled()) {
            mVendor.bredrStartup();
        }
    }

    void informTimeoutToHidl() {
        if (isVendorIntfEnabled()) {
            mVendor.informTimeoutToHidl();
        }
    }

    void startBrEdrCleanup(){
        mAdapterProperties.onBluetoothDisable();
        if (isVendorIntfEnabled()) {
            mVendor.bredrCleanup();
        } else {
            mAdapterStateMachine.sendMessage(
            mAdapterStateMachine.obtainMessage(AdapterState.BEGIN_BREDR_STOP));
        }
    }

    void stopProfileServices() {
        Class[] supportedProfileServices = Config.getSupportedProfiles();
        if (supportedProfileServices.length == 1 && (mRunningProfiles.size() == 1
                && GattService.class.getSimpleName().equals(mRunningProfiles.get(0).getName()))) {
            debugLog("stopProfileServices() - No profiles services to stop or already stopped.");
            mAdapterStateMachine.sendMessage(AdapterState.BREDR_STOPPED);
        } else {
            setAllProfileServiceStates(supportedProfileServices, BluetoothAdapter.STATE_OFF);
        }
    }

    void disableProfileServices(boolean onlyGatt) {
        Class[] services = Config.getSupportedProfiles();
        for (int i = 0; i < services.length; i++) {
            if (onlyGatt && !(GattService.class.getSimpleName().equals(services[i].getSimpleName())))
                continue;
            boolean res = false;
            String serviceName = services[i].getName();
            mProfileServicesState.put(serviceName,BluetoothAdapter.STATE_OFF);
            Intent intent = new Intent(this,services[i]);
            intent.putExtra(EXTRA_ACTION,ACTION_SERVICE_STATE_CHANGED);
            intent.putExtra(BluetoothAdapter.EXTRA_STATE, BluetoothAdapter.STATE_OFF);
            intent.addFlags(Intent.FLAG_RECEIVER_FOREGROUND);
            res = stopService(intent);
            debugLog( "disableProfileServices() - Stopping service "
                + serviceName + " with result: " + res);
            if(onlyGatt)
                break;
        }
        return;
    }

    private void stopGattProfileService() {
        mAdapterProperties.onBleDisable();
        if (mRunningProfiles.size() == 0) {
            debugLog("stopGattProfileService() - No profiles services to stop.");
            mAdapterStateMachine.sendMessage(AdapterState.BLE_STOPPED);
        }
        setProfileServiceState(GattService.class, BluetoothAdapter.STATE_OFF);
    }

    void unregGattIds() {
      if (mGattService != null) {
          mGattService.clearPendingOperations();
      } else {
          debugLog("FAILED to clear All registered Gatt Ids");
      }
    }

    private void invalidateBluetoothGetStateCache() {
        BluetoothAdapter.invalidateBluetoothGetStateCache();
    }

    void updateAdapterState(int prevState, int newState) {
        mAdapterProperties.setState(newState);
        invalidateBluetoothGetStateCache();
        if (mCallbacks != null) {
            int n = mCallbacks.beginBroadcast();
            debugLog("updateAdapterState() - Broadcasting state " + BluetoothAdapter.nameForState(
                    newState) + " to " + n + " receivers.");
            for (int i = 0; i < n; i++) {
                try {
                    mCallbacks.getBroadcastItem(i).onBluetoothStateChange(prevState, newState);
                } catch (RemoteException e) {
                    debugLog("updateAdapterState() - Callback #" + i + " failed (" + e + ")");
                }
            }
            mCallbacks.finishBroadcast();
        }

        // Turn the Adapter all the way off if we are disabling and the snoop log setting changed.
        if (newState == BluetoothAdapter.STATE_BLE_TURNING_ON) {
            mSnoopLogSettingAtEnable =
                    SystemProperties.get(BLUETOOTH_BTSNOOP_LOG_MODE_PROPERTY, "empty");
            mDefaultSnoopLogSettingAtEnable =
                    Settings.Global.getString(getContentResolver(),
                            Settings.Global.BLUETOOTH_BTSNOOP_DEFAULT_MODE);
            SystemProperties.set(BLUETOOTH_BTSNOOP_DEFAULT_MODE_PROPERTY,
                    mDefaultSnoopLogSettingAtEnable);
        } else if (newState == BluetoothAdapter.STATE_BLE_ON
                   && prevState != BluetoothAdapter.STATE_OFF) {
            String snoopLogSetting =
                    SystemProperties.get(BLUETOOTH_BTSNOOP_LOG_MODE_PROPERTY, "empty");
            String snoopDefaultModeSetting =
                    Settings.Global.getString(getContentResolver(),
                            Settings.Global.BLUETOOTH_BTSNOOP_DEFAULT_MODE);

            if (!TextUtils.equals(mSnoopLogSettingAtEnable, snoopLogSetting)
                    || !TextUtils.equals(mDefaultSnoopLogSettingAtEnable,
                            snoopDefaultModeSetting)) {
                mAdapterStateMachine.sendMessage(AdapterState.BLE_TURN_OFF);
            }
        }
    }

    void cleanup() {
        debugLog("cleanup()");
        if (mCleaningUp) {
            errorLog("cleanup() - Service already starting to cleanup, ignoring request...");
            return;
        }

        // Unregistering Bluetooth Adapter
        if ( mAdapter!= null ){
            mAdapter.unregisterAdapter();
            mAdapter = null;
        }

        BluetoothAdapter.invalidateGetProfileConnectionStateCache();
        BluetoothAdapter.invalidateIsOffloadedFilteringSupportedCache();

        clearAdapterService(this);

        mCleaningUp = true;
        invalidateBluetoothCaches();

        unregisterReceiver(mAlarmBroadcastReceiver);
        unregisterReceiver(mWifiStateBroadcastReceiver);

        if (mPendingAlarm != null) {
            mAlarmManager.cancel(mPendingAlarm);
            mPendingAlarm = null;
        }

        // This wake lock release may also be called concurrently by
        // {@link #releaseWakeLock(String lockName)}, so a synchronization is needed here.
        synchronized (this) {
            if (mWakeLock != null) {
                if (mWakeLock.isHeld()) {
                    mWakeLock.release();
                }
                mWakeLock = null;
            }
        }

        if (mDatabaseManager != null) {
            mDatabaseManager.cleanup();
        }

        if (mAdapterStateMachine != null) {
            mAdapterStateMachine.doQuit();
        }

        if (mBondStateMachine != null) {
            mBondStateMachine.doQuit();
        }

        if (mRemoteDevices != null) {
            mRemoteDevices.cleanup();
        }

        if (mSdpManager != null) {
            mSdpManager.cleanup();
            mSdpManager = null;
        }

        if (mBluetoothKeystoreService != null) {
            mBluetoothKeystoreService.cleanup();
        }

        if (mNativeAvailable) {
            debugLog("cleanup() - Cleaning up adapter native");
            cleanupNative();
            mNativeAvailable = false;
        }

        if (mAdapterProperties != null) {
            mAdapterProperties.cleanup();
        }

        if (mVendor != null) {
            mVendor.cleanup();
        }

        if (mVendorSocket!= null) {
            mVendorSocket.cleanup();
        }

        if (mJniCallbacks != null) {
            mJniCallbacks.cleanup();
        }

        if (mPhonePolicy != null) {
            mPhonePolicy.cleanup();
        }

        if (mSilenceDeviceManager != null) {
            mSilenceDeviceManager.cleanup();
        }

        if (mActiveDeviceManager != null) {
            mActiveDeviceManager.cleanup();
        }

        if (mProfileServicesState != null) {
            mProfileServicesState.clear();
        }

        if (mBinder != null) {
            mBinder.cleanup();
            mBinder = null;  //Do not remove. Otherwise Binder leak!
        }

        if (mCallbacks != null) {
            mCallbacks.kill();
        }
    }

    private void invalidateBluetoothCaches() {
        BluetoothAdapter.invalidateGetProfileConnectionStateCache();
        BluetoothAdapter.invalidateIsOffloadedFilteringSupportedCache();
        BluetoothDevice.invalidateBluetoothGetBondStateCache();
        BluetoothAdapter.invalidateBluetoothGetStateCache();
    }

    private void setProfileServiceState(Class service, int state) {
        Intent intent = new Intent(this, service);
        intent.putExtra(EXTRA_ACTION, ACTION_SERVICE_STATE_CHANGED);
        intent.putExtra(BluetoothAdapter.EXTRA_STATE, state);
        intent.addFlags(Intent.FLAG_RECEIVER_FOREGROUND);
        startService(intent);
    }

    private void setAllProfileServiceStates(Class[] services, int state) {
        for (Class service : services) {
            if (GattService.class.getSimpleName().equals(service.getSimpleName())) {
                continue;
            }
            Log.d(TAG, "Calling setProfileServiceState for: " + service.getSimpleName());
            setProfileServiceState(service, state);
        }
    }

    /**
     * Verifies whether the profile is supported by the local bluetooth adapter by checking a
     * bitmask of its supported profiles
     *
     * @param remoteDeviceUuids is an array of all supported profiles by the remote device
     * @param localDeviceUuids  is an array of all supported profiles by the local device
     * @param profile           is the profile we are checking for support
     * @param device            is the remote device we wish to connect to
     * @return true if the profile is supported by both the local and remote device, false otherwise
     */
    private boolean isSupported(ParcelUuid[] localDeviceUuids, ParcelUuid[] remoteDeviceUuids,
            int profile, BluetoothDevice device) {
        ParcelUuid ADV_AUDIO_T_MEDIA =
            ParcelUuid.fromString("00006AD0-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_HEARINGAID =
            ParcelUuid.fromString("00006AD2-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_P_MEDIA =
            ParcelUuid.fromString("00006AD1-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_P_VOICE =
            ParcelUuid.fromString("00006AD4-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_T_VOICE =
            ParcelUuid.fromString("00006AD5-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_G_MEDIA =
            ParcelUuid.fromString("00006AD3-0000-1000-8000-00805F9B34FB");

        ParcelUuid ADV_AUDIO_W_MEDIA =
            ParcelUuid.fromString("2587db3c-ce70-4fc9-935f-777ab4188fd7");

        ParcelUuid ADV_AUDIO_G_VBC =
            ParcelUuid.fromString("00006AD6-0000-1000-8000-00805F9B34FB");

        if (remoteDeviceUuids == null || remoteDeviceUuids.length == 0) {
            Log.e(TAG, "isSupported: Remote Device Uuids Empty");
        }

        if (profile == BluetoothProfile.HEADSET) {
            return ((ArrayUtils.contains(localDeviceUuids, BluetoothUuid.HSP_AG)
                    && ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HSP))
                    || (ArrayUtils.contains(localDeviceUuids, BluetoothUuid.HFP_AG)
                    && ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HFP))
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_HEARINGAID)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_T_VOICE)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_P_VOICE));
        }
        if (profile == BluetoothProfile.HEADSET_CLIENT) {
          return (ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HFP_AG)
                && ArrayUtils.contains(localDeviceUuids, BluetoothUuid.HFP));
        }
        if (profile == BluetoothProfile.A2DP) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.ADV_AUDIO_DIST)
                    || ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.A2DP_SINK)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_T_MEDIA)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_HEARINGAID)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_G_MEDIA)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_W_MEDIA)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_P_MEDIA)
                    || ArrayUtils.contains(remoteDeviceUuids, ADV_AUDIO_G_VBC);
        }
        if (profile == BluetoothProfile.A2DP_SINK) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.ADV_AUDIO_DIST)
                    || ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.A2DP_SOURCE);
        }
        if (profile == BluetoothProfile.OPP) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.OBEX_OBJECT_PUSH);
        }
        if (profile == BluetoothProfile.HID_HOST) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HID)
                    || ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HOGP);
        }
        if (profile == BluetoothProfile.HID_DEVICE) {
            return mHidDeviceService.getConnectionState(device)
                    == BluetoothProfile.STATE_DISCONNECTED;
        }
        if (profile == BluetoothProfile.PAN) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.NAP);
        }
        if (profile == BluetoothProfile.MAP) {
            return mMapService.getConnectionState(device) == BluetoothProfile.STATE_CONNECTED;
        }
        if (profile == BluetoothProfile.PBAP) {
            return mPbapService.getConnectionState(device) == BluetoothProfile.STATE_CONNECTED;
        }
        if (profile == BluetoothProfile.MAP_CLIENT) {
            return true;
        }
        if (profile == BluetoothProfile.PBAP_CLIENT) {
            return ArrayUtils.contains(localDeviceUuids, BluetoothUuid.PBAP_PCE)
                    && ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.PBAP_PSE);
        }
        if (profile == BluetoothProfile.HEARING_AID) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.HEARING_AID);
        }
        if (profile == BluetoothProfile.SAP) {
            return ArrayUtils.contains(remoteDeviceUuids, BluetoothUuid.SAP);
        }
        if (profile == BluetoothProfile.BC_PROFILE) {
            return mBCId != null && ArrayUtils.contains(remoteDeviceUuids, ParcelUuid.fromString (mBCId));
        }

        Log.e(TAG, "isSupported: Unexpected profile passed in to function: " + profile);
        return false;
    }

    /**
     * Checks if any profile is enabled for the given device
     *
     * @param device is the device for which we are checking if any profiles are enabled
     * @return true if any profile is enabled, false otherwise
     */
    private boolean isAnyProfileEnabled(BluetoothDevice device) {
        boolean isLeAudioEnabled = ApmConstIntf.getLeAudioEnabled();
        if(isLeAudioEnabled) {
            MediaAudioIntf mMediaAudio = MediaAudioIntf.get();
            if(mMediaAudio != null && mMediaAudio.getConnectionPolicy(device)
                        > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                return true;
            }
        } else if (mA2dpService != null && mA2dpService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mA2dpSinkService != null && mA2dpSinkService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if(isLeAudioEnabled) {
            CallAudioIntf mCallAudio = CallAudioIntf.get();
            if(mCallAudio != null && mCallAudio.getConnectionPolicy(device)
                        > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                return true;
            }
        } else if (mHeadsetService != null && mHeadsetService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mHeadsetClientService != null && mHeadsetClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mMapClientService != null && mMapClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mHidHostService != null && mHidHostService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mPanService != null && mPanService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mPbapClientService != null && mPbapClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        if (mHearingAidService != null && mHearingAidService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            return true;
        }
        ///*_REF
        if (mBCService != null && mBCGetConnPolicy != null) {
            int connPolicy = 0;
            try {
                connPolicy = (int) mBCGetConnPolicy.invoke(mBCService, device);
            } catch (IllegalAccessException ex) {
                Log.e(TAG, "mBCGetConnPolicy >> IllegalAccessException");
            } catch (InvocationTargetException e) {
                   Log.e(TAG, "BC:Connect InvocationTargetException");
            }
            if (connPolicy > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN)
                return true;
        }
        //_REF*/

        return false;
    }

    /**
     * Connects only available profiles
     * (those with {@link BluetoothProfile.CONNECTION_POLICY_ALLOWED})
     *
     * @param device is the device with which we are connecting the profiles
     * @return true
     */
    private boolean connectEnabledProfiles(BluetoothDevice device) {
        ParcelUuid[] remoteDeviceUuids = getRemoteUuids(device);
        ParcelUuid[] localDeviceUuids = mAdapterProperties.getUuids();
        CallAudioIntf mCallAudio = CallAudioIntf.get();
        MediaAudioIntf mMediaAudio = MediaAudioIntf.get();
        boolean mediaConnect = false;
        boolean voiceConnect = false;

        boolean isLeAudioEnabled = ApmConstIntf.getLeAudioEnabled();
        if(isLeAudioEnabled) {
            if(mMediaAudio != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP, device) && mMediaAudio.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                    mediaConnect = true;
            }

            if(mCallAudio != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEADSET, device) && mCallAudio.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                Log.e(TAG, "isLeAudioEnabled  call audio connect " + isLeAudioEnabled);
                voiceConnect = true;
                mCallAudio.connect(device, mediaConnect);
            }
        } else if (mHeadsetService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEADSET, device) && mHeadsetService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting Headset Profile");
            mHeadsetService.connect(device);
        }
        /*delaying the A2DP connection so that HFP connection can be established first*/
        Log.d(TAG, "delaying the A2dp Connection by " + DELAY_A2DP_SLEEP_MILLIS + "msec");
        try {
            Thread.sleep(DELAY_A2DP_SLEEP_MILLIS);
        } catch(InterruptedException ex) {
            Log.e(TAG, "connectEnabledProfiles thread was interrupted");
            Thread.currentThread().interrupt();
        }

        if(isLeAudioEnabled) {
            if(mMediaAudio != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP, device) && mMediaAudio.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                mMediaAudio.connect(device, voiceConnect);
            }
        } else if (mA2dpService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP, device) && mA2dpService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting A2dp");
            mA2dpService.connect(device);
        }
        if (mA2dpSinkService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP_SINK, device) && mA2dpSinkService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting A2dp Sink");
            mA2dpSinkService.connect(device);
        }
        if (mHeadsetClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEADSET_CLIENT, device)
                && mHeadsetClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting HFP");
            mHeadsetClientService.connect(device);
        }
        if (mMapClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.MAP_CLIENT, device)
                && mMapClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting MAP");
            mMapClientService.connect(device);
        }
        if (mHidHostService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HID_HOST, device) && mHidHostService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting Hid Host Profile");
            mHidHostService.connect(device);
        }
        if (mPanService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.PAN, device) && mPanService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting Pan Profile");
            mPanService.connect(device);
        }
        if (mPbapClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.PBAP_CLIENT, device)
                && mPbapClientService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting Pbap");
            mPbapClientService.connect(device);
        }
        if (mHearingAidService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEARING_AID, device)
                && mHearingAidService.getConnectionPolicy(device)
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
            Log.i(TAG, "connectEnabledProfiles: Connecting Hearing Aid Profile");
            mHearingAidService.connect(device);
        }
        ///*_REF
        if (mBCService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.BC_PROFILE, device) && mBCGetConnPolicy != null) {
                int connPolicy = BluetoothProfile.CONNECTION_POLICY_FORBIDDEN;
                try {
                   connPolicy = (int) mBCGetConnPolicy.invoke(mBCService, device);
                } catch(IllegalAccessException e) {
                   Log.e(TAG, "BC:connPolicy IllegalAccessException");
                } catch (InvocationTargetException e) {
                   Log.e(TAG, "BC:connPolicy InvocationTargetException");
                }
                if (connPolicy
                > BluetoothProfile.CONNECTION_POLICY_FORBIDDEN) {
                    Log.i(TAG, "connectEnabledProfiles: Connecting BC Profile");
                    if (mBCConnect != null) {
                        try {
                          mBCConnect.invoke(mBCService, device);
                        } catch(IllegalAccessException e) {
                          Log.e(TAG, "BC:Connect IllegalAccessException");
                        } catch (InvocationTargetException e) {
                          Log.e(TAG, "BC:Connect InvocationTargetException");
                        }
                    } else {
                       Log.e(TAG, "no bc connect handle");
                    }
                 }
        }
        //_REF*/
        return true;
    }

    /**
     * Verifies that all bluetooth profile services are running
     *
     * @return true if all bluetooth profile services running, false otherwise
     */
    private boolean profileServicesRunning() {
        if (mRegisteredProfiles.size() == Config.getSupportedProfiles().length
                && mRegisteredProfiles.size() == mRunningProfiles.size()) {
            return true;
        }

        Log.e(TAG, "profileServicesRunning: One or more supported services not running");
        return false;
    }

    /**
     * Initializes all the profile services fields
     */
    private void initProfileServices() {
        Log.i(TAG, "initProfileServices: Initializing all bluetooth profile services");
        mA2dpService = A2dpService.getA2dpService();
        mA2dpSinkService = A2dpSinkService.getA2dpSinkService();
        mHeadsetService = HeadsetService.getHeadsetService();
        mHeadsetClientService = HeadsetClientService.getHeadsetClientService();
        mMapService = BluetoothMapService.getBluetoothMapService();
        mMapClientService = MapClientService.getMapClientService();
        mHidDeviceService = HidDeviceService.getHidDeviceService();
        mHidHostService = HidHostService.getHidHostService();
        mPanService = PanService.getPanService();
        mPbapService = BluetoothPbapService.getBluetoothPbapService();
        mPbapClientService = PbapClientService.getPbapClientService();
        mHearingAidService = HearingAidService.getHearingAidService();
        mGroupService = new ServiceFactory().getGroupService();
        mSapService = SapService.getSapService();
        mGattService = GattService.getGattService();
        if (isAdvBCAAudioFeatEnabled()) {
        ///*_REF
            Class<?> bcClass = null;
            try {
                bcClass = Class.forName("com.android.bluetooth.bc.BCService");
            } catch (ClassNotFoundException ex) {
                Log.e(TAG, "no BC: exists");
                bcClass = null;
            }
            if (bcClass != null) {
                Log.d(TAG, "Able to get BC class handle");
                try {
                    mBCGetService =  bcClass.getMethod("getBCService", (Class<?>)null);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:getBCService method exists");
                    return;
                }
                if (mBCGetService != null) {
                    try {
                       mBCService = mBCGetService.invoke(null, (Object[])null);
                    } catch(IllegalAccessException e) {
                       Log.e(TAG, "BC:Connect IllegalAccessException");
                    } catch (InvocationTargetException e) {
                       Log.e(TAG, "BC:Connect InvocationTargetException");
                    }
                }

                try {
                    mBCGetConnPolicy =  bcClass.getMethod("getConnectionPolicy", BluetoothDevice.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:getConnectionPolicy method exists");
                }

                try {
                    mBCGetConnState =    bcClass.getMethod("getConnectionState", BluetoothDevice.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:getConnectionState method exists");
                    //break;
                }

                try {
                    mBCSetConnPolicy =  bcClass.getMethod("setConnectionPolicy", new Class[] {BluetoothDevice.class, int.class});
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:setConnectionPolicy method exists");
                    //break;
                }

                try {
                    mBCConnect =    bcClass.getMethod("connect", BluetoothDevice.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:connect method exists");
                    //break;
                }
                try {
                    mBCDisconnect =  bcClass.getMethod("disconnect", BluetoothDevice.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BC:disconnect method exists");
                    //break;
                }
                try {
                    mBCId = (String)bcClass.getDeclaredField("BC_ID").get(null);
                } catch (NoSuchFieldException ex) {
                    Log.w(TAG, ex);
                } catch (IllegalAccessException ex) {
                    Log.w(TAG, ex);
                }
                try {
                    mBSId = (String)bcClass.getDeclaredField("BS_ID").get(null);
                } catch (NoSuchFieldException ex) {
                    Log.w(TAG, ex);
                } catch (IllegalAccessException ex) {
                    Log.w(TAG, ex);
                }
            }
            //_REF*/
        }
        if (isAdvBCSAudioFeatEnabled()) {
        //_REF*/
            Class<?> broadcastClass = null;
            try {
                broadcastClass = Class.forName("com.android.bluetooth.broadcast.BroadcastService");
            } catch (ClassNotFoundException ex) {
                Log.e(TAG, "no Broadcast: exists");
                broadcastClass = null;
            }
            if (broadcastClass != null) {
                try {
                    mBroadcastGetService = broadcastClass.getMethod("getBroadcastService", (Class<?>)null);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no BroadcastService method exists");
                    return;
                }
                if (mBroadcastGetService != null) {
                    try {
                        mBroadcastService = mBroadcastGetService.invoke(null, (Object[])null);
                    } catch(IllegalAccessException e) {
                        Log.e(TAG, "BroadcastService IllegalAccessException");
                    } catch (InvocationTargetException e) {
                        Log.e(TAG, "BroadcastService InvocationTargetException");
                    }
                }
                try {
                    mBroadcastIsActive = broadcastClass.getMethod("isBroadcastActive");
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:IsActive method exists");
                }
                try {
                    mBroadcastIsStreaming = broadcastClass.getMethod("isBroadcastStreaming");
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:IsActive method exists");
                }
                try {
                    mBroadcastNotifyState = broadcastClass.getMethod("notifyBroadcastEnabled", boolean.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:NotifyState method exists");
                }
                try {
                    mBroadcastGetAddr = broadcastClass.getMethod("getBroadcastAddress");
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:GetAddr method exists");
                }
                try {
                    mBroadcastDevice = broadcastClass.getMethod("getBroadcastDevice");
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:GetDevice method exists");
                }
                try {
                    mBroadcastMeta = broadcastClass.getMethod("updateMetadataFromAvrcp", MediaMetadata.class);
                } catch (NoSuchMethodException e) {
                    Log.e(TAG, "no Broadcast:UpdateMetadata method exists");
                }
                mActiveDeviceManager.init_broadcast_ref();
            }
        }
    }

    ///*_REF
    public Object getBCService() {
        return mBCService;
    }
    public Method getBCGetConnPolicy() {
        return mBCGetConnPolicy;
    }
    public Method getBCSetConnPolicy() {
        return mBCSetConnPolicy;
    }
    public Method getBCConnect() {
        return mBCConnect;
    }
    public String getBCId() {
        return mBCId;
    }

    public String getBSId() {
        return mBSId;
    }
    //_REF*/

    private boolean isAvailable() {
        return !mCleaningUp;
    }

    public Object getBroadcastService() {
        return mBroadcastService;
    }

    public Method getBroadcastActive() {
        return mBroadcastIsActive;
    }

    public Method getBroadcastStreaming() {
        return mBroadcastIsStreaming;
    }

    public Method getBroadcastNotifyState() {
        return mBroadcastNotifyState;
    }

    public Method getBroadcastAddress() {
        return mBroadcastGetAddr;
    }

    public Method getBroadcastDevice() {
        return mBroadcastDevice;
    }

    public Method getBroadcastMeta() {
        return mBroadcastMeta;
    }
    /**
     * Handlers for incoming service calls
     */
    private AdapterServiceBinder mBinder;

    /**
     * The Binder implementation must be declared to be a static class, with
     * the AdapterService instance passed in the constructor. Furthermore,
     * when the AdapterService shuts down, the reference to the AdapterService
     * must be explicitly removed.
     *
     * Otherwise, a memory leak can occur from repeated starting/stopping the
     * service...Please refer to android.os.Binder for further details on
     * why an inner instance class should be avoided.
     *
     */
    private static class AdapterServiceBinder extends IBluetooth.Stub {
        private AdapterService mService;

        AdapterServiceBinder(AdapterService svc) {
            mService = svc;
            mService.invalidateBluetoothGetStateCache();
            BluetoothAdapter.getDefaultAdapter().disableBluetoothGetStateCache();
        }

        public void cleanup() {
            mService = null;
        }

        public AdapterService getService() {
            if (mService != null && mService.isAvailable()) {
                return mService;
            }
            return null;
        }

        @Override
        public int getState() {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null) {
                return BluetoothAdapter.STATE_OFF;
            }
            return service.getState();
        }

        @Override
        public boolean enable(boolean quietMode, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "enable")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService enable")) {
                return false;
            }
            return service.enable();
        }

        @Override
        public boolean disable(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "disable")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService disable")) {
                return false;
            }
            return service.disable();
        }

        @Override
        public String getAddress() {
            return getAddressWithAttribution(Utils.getCallingAttributionSource());
        }

        @Override
        public String getAddressWithAttribution(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getAddress")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getAddress")) {
                return null;
            }

            enforceLocalMacAddressPermission(service);

            return Utils.getAddressStringFromByte(service.mAdapterProperties.getAddress());
        }

        @Override
        public ParcelUuid[] getUuids(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getUuids")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getUuids")) {
                return new ParcelUuid[0];
            }

            return service.mAdapterProperties.getUuids();
        }

        @Override
        public String getName(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getName")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getName")) {
                return null;
            }

            return service.getName();
        }

        @Override
        public int getNameLengthForAdvertise(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getNameLengthForAdvertise")
                    || !Utils.checkAdvertisePermissionForDataDelivery(
                            service, attributionSource, TAG)) {
                return -1;
            }

            return service.getNameLengthForAdvertise();
        }

        @Override
        public boolean setName(String name, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "setName")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService setName")) {
                return false;
            }

            return service.mAdapterProperties.setName(name);
        }

        @Override
        public BluetoothClass getBluetoothClass(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getBluetoothClass")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterSource getBluetoothClass")) {
                return null;
            }

            return service.mAdapterProperties.getBluetoothClass();
        }

        @Override
        public boolean setBluetoothClass(BluetoothClass bluetoothClass, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            if (!service.mAdapterProperties.setBluetoothClass(bluetoothClass)) {
              return false;
            }

            return Settings.Global.putInt(
                    service.getContentResolver(),
                    Settings.Global.BLUETOOTH_CLASS_OF_DEVICE,
                    bluetoothClass.getClassOfDevice());
        }

        @Override
        public int getIoCapability(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getIoCapability")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getIoCapability")) {
                return BluetoothAdapter.IO_CAPABILITY_UNKNOWN;
            }

            return service.mAdapterProperties.getIoCapability();
        }

        @Override
        public boolean setIoCapability(int capability, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            if (!isValidIoCapability(capability)) {
              return false;
            }

            return service.mAdapterProperties.setIoCapability(capability);
        }

        @Override
        public int getLeIoCapability(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getLeIoCapability")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getLeIoCapability")) {
                return BluetoothAdapter.IO_CAPABILITY_UNKNOWN;
            }

            return service.mAdapterProperties.getLeIoCapability();
        }

        @Override
        public boolean setLeIoCapability(int capability, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            if (!isValidIoCapability(capability)) {
              return false;
            }

            return service.mAdapterProperties.setLeIoCapability(capability);
        }

        @Override
        public int getScanMode(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getScanMode")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getScanMode")) {
                return BluetoothAdapter.SCAN_MODE_NONE;
            }

            return service.mAdapterProperties.getScanMode();
        }

        @Override
        public boolean setScanMode(int mode, int duration, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "setScanMode")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService setScanMode")) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            service.mAdapterProperties.setDiscoverableTimeout(duration);
            return service.mAdapterProperties.setScanMode(convertScanModeToHal(mode));
        }

        @Override
        public int getDiscoverableTimeout(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getDiscoverableTimeout")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getDiscoverableTimeout")) {
                return 0;
            }
            return service.mAdapterProperties.getDiscoverableTimeout();
        }

        @Override
        public boolean setDiscoverableTimeout(int timeout, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "setDiscoverableTimeout")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService setDiscoverableTimeout")) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            return service.mAdapterProperties.setDiscoverableTimeout(timeout);
        }

        @Override
        public boolean startDiscovery(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "startDiscovery")) {
                return false;
            }

            if (!Utils.checkScanPermissionForDataDelivery(
                    service, attributionSource, "Starting discovery.")) {
                return false;
            }

            return service.startDiscovery(attributionSource);
        }

        @Override
        public boolean cancelDiscovery(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "cancelDiscovery")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService cancelDiscovery")) {
                return false;
            }
            service.debugLog("cancelDiscovery");
            return service.cancelDiscovery();
        }

        @Override
        public boolean isDiscovering(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "isDiscovering")
                    || !Utils.checkScanPermissionForDataDelivery(
                            service, attributionSource, "AdapterService isDiscovering")) {
                return false;
            }

            return service.mAdapterProperties.isDiscovering();
        }

        @Override
        public long getDiscoveryEndMillis(AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return -1;
            }
            enforceBluetoothPrivilegedPermission(service);
            return service.mAdapterProperties.discoveryEndMillis();
        }

        @Override
        public List<BluetoothDevice> getMostRecentlyConnectedDevices(
                AttributionSource attributionSource) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getMostRecentlyConnectedDevices")) {
                return new ArrayList<>();
            }

            return service.mDatabaseManager.getMostRecentlyConnectedDevices();
        }

        @Override
        public BluetoothDevice[] getBondedDevices(AttributionSource attributionSource) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getBondedDevices")) {
                return new BluetoothDevice[0];
            }
            return service.getBondedDevices();
        }

        @Override
        public int getAdapterConnectionState() {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null) {
                return BluetoothAdapter.STATE_DISCONNECTED;
            }
            return service.mAdapterProperties.getConnectionState();
        }

        /**
         * This method has an associated binder cache.  The invalidation
         * methods must be changed if the logic behind this method changes.
         */
        @Override
        public int getProfileConnectionState(int profile) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(
                            service, TAG, "getProfileConnectionState")) {
                return BluetoothProfile.STATE_DISCONNECTED;
            }
            return service.mAdapterProperties.getProfileConnectionState(profile);
        }

        @Override
        public boolean createBond(BluetoothDevice device, int transport, OobData remoteP192Data,
                OobData remoteP256Data, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveOrManagedUser(service, TAG, "createBond")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService createBond")) {
                return false;
            }
            // This conditional is required to satisfy permission dependencies
            // since createBond calls createBondOutOfBand with null value passed as data.
            // BluetoothDevice#createBond requires BLUETOOTH_ADMIN only.
            service.enforceBluetoothPrivilegedPermissionIfNeeded(remoteP192Data, remoteP256Data);

            return service.createBond(device, transport, remoteP192Data, remoteP256Data,
                    attributionSource.getPackageName());
        }

        @Override
        public boolean cancelBondProcess(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "cancelBondProcess")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService cancelBondProcess")) {
                return false;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            if (deviceProp != null) {
                deviceProp.setBondingInitiatedLocally(false);
            }

            return service.cancelBondNative(addressToBytes(device.getAddress()));
        }

        @Override
        public boolean removeBond(BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "removeBond")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService removeBond")) {
                return false;
            }
            return service.removeBond(device);
        }

        @Override
        public int getBondState(BluetoothDevice device, AttributionSource attributionSource) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getBondState")) {
                return BluetoothDevice.BOND_NONE;
            }
            return service.getBondState(device);
        }

        @Override
        public boolean isBondingInitiatedLocally(
            BluetoothDevice device, AttributionSource attributionSource) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService isBondingInitiatedLocally")) {
                return false;
            }
            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            return deviceProp != null && deviceProp.isBondingInitiatedLocally();
        }

        @Override
        public void setBondingInitiatedLocally(BluetoothDevice device, boolean localInitiated,
                    AttributionSource source) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, source, "setBondingInitiatedLocally")) {
                return;
            }
            service.setBondingInitiatedLocally(device,localInitiated);
            return;
        }

        @Override
        public void generateLocalOobData(int transport, IBluetoothOobDataCallback callback,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveOrManagedUser(service, TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.generateLocalOobData(transport, callback);
        }

        @Override
        public long getSupportedProfiles() {
            AdapterService service = getService();
            if (service == null) {
                return 0;
            }
            return service.getSupportedProfiles();
        }

        @Override
        public int getConnectionState(BluetoothDevice device) {
            return getConnectionStateWithAttribution(device, Utils.getCallingAttributionSource());
        }

        @Override
        public int getConnectionStateWithAttribution(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getConnectionState")) {
                return 0;
            }
          return service.getConnectionState(device);
        }

      @Override
        public boolean canBondWithoutDialog(BluetoothDevice device, AttributionSource source) {
            return false;
        }

        @Override
        public boolean removeActiveDevice(@ActiveDeviceUse int profiles, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            return service.setActiveDevice(null, profiles);
        }

        @Override
        public boolean setActiveDevice(BluetoothDevice device, @ActiveDeviceUse int profiles, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            return service.setActiveDevice(device, profiles);
        }

        @Override
        public boolean connectAllEnabledProfiles(BluetoothDevice device, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);
            return service.connectAllEnabledProfiles(device);
        }

        @Override
        public boolean disconnectAllEnabledProfiles(BluetoothDevice device,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            return service.disconnectAllEnabledProfiles(device);
        }

        @Override
        public String getRemoteName(BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getRemoteName")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getRemoteName")) {
                return null;
            }
            return service.getRemoteName(device);
        }

        @Override
        public int getRemoteType(BluetoothDevice device,AttributionSource attributionSource) {

            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getRemoteType")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getRemoteType")) {
                return BluetoothDevice.DEVICE_TYPE_UNKNOWN;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            return deviceProp != null ?
                    deviceProp.getDeviceType() : BluetoothDevice.DEVICE_TYPE_UNKNOWN;
        }

        @Override
        public String getRemoteAlias(BluetoothDevice device) {
            return getRemoteAliasWithAttribution(device, Utils.getCallingAttributionSource());
        }

        @Override
        public String getRemoteAliasWithAttribution(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getRemoteAlias")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getRemoteAlias")) {
                return null;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            return deviceProp != null ? deviceProp.getAlias() : null;
        }

        @Override
        public int setRemoteAlias(BluetoothDevice device, String name,
            AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null) {
                return BluetoothStatusCodes.ERROR_BLUETOOTH_NOT_ENABLED;
            }
            if (!callerIsSystemOrActiveUser(TAG, "setRemoteAlias")) {
                return BluetoothStatusCodes.ERROR_BLUETOOTH_NOT_ALLOWED;
            }
            if (name != null && name.isEmpty()) {
                throw new IllegalArgumentException("alias cannot be the empty string");
            }

            if (!hasBluetoothPrivilegedPermission(service)) {
                if (!Utils.checkConnectPermissionForDataDelivery(
                        service, attributionSource, "AdapterService setRemoteAlias")) {
                    return BluetoothStatusCodes.ERROR_MISSING_BLUETOOTH_CONNECT_PERMISSION;
                }
                enforceCdmAssociation(service.mCompanionDeviceManager, service,
                        attributionSource.getPackageName(), Binder.getCallingUid(), device);
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            if (deviceProp == null) {
                return BluetoothStatusCodes.ERROR_DEVICE_NOT_BONDED;
            }
            deviceProp.setAlias(device, name);
            return BluetoothStatusCodes.SUCCESS;
        }

        @Override
        public int getRemoteClass(BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getRemoteClass")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getRemoteClass")) {
                return 0;
            }
            return service.getRemoteClass(device);
        }

        @Override
        public ParcelUuid[] getRemoteUuids(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "getRemoteUuids")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getRemoteUuids")) {
                return new ParcelUuid[0];
            }
            return service.getRemoteUuids(device);
        }

        @Override
        public boolean fetchRemoteUuids(BluetoothDevice device) {
            return fetchRemoteUuidsWithAttribution(device, Utils.getCallingAttributionSource());
        }

        @Override
        public boolean fetchRemoteUuidsWithAttribution(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null
                    || !callerIsSystemOrActiveOrManagedUser(service, TAG, "fetchRemoteUuids")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService fetchRemoteUuids")) {
                return false;
            }

            service.fetchRemoteUuids(device);
            return true;
        }

        @Override
        public boolean setPin(BluetoothDevice device, boolean accept, int len, byte[] pinCode,
                AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "setPin")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService setPin")) {
                return false;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            // Only allow setting a pin in bonding state, or bonded state in case of security
            // upgrade.
            if (deviceProp == null || !deviceProp.isBondingOrBonded()) {
                return false;
            }
            if (pinCode.length != len) {
                android.util.EventLog.writeEvent(0x534e4554, "139287605", -1,
                        "PIN code length mismatch");
                return false;
            }
            service.logUserBondResponse(device, accept,
                    BluetoothProtoEnums.BOND_SUB_STATE_LOCAL_PIN_REPLIED);
            return service.pinReplyNative(addressToBytes(device.getAddress()),
                    accept, len, pinCode);
        }

        @Override
        public boolean setPasskey(BluetoothDevice device, boolean accept, int len, byte[] passkey,
                AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "setPasskey")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService setPasskey")) {
                return false;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            if (deviceProp == null || !deviceProp.isBonding()) {
                return false;
            }
            if (passkey.length != len) {
                android.util.EventLog.writeEvent(0x534e4554, "139287605", -1,
                        "Passkey length mismatch");
                return false;
            }
            service.logUserBondResponse(device, accept,
                    BluetoothProtoEnums.BOND_SUB_STATE_LOCAL_SSP_REPLIED);
            return service.sspReplyNative(
                    addressToBytes(device.getAddress()),
                    AbstractionLayer.BT_SSP_VARIANT_PASSKEY_ENTRY,
                    accept,
                    Utils.byteArrayToInt(passkey));
        }

        @Override
        public boolean setPairingConfirmation(BluetoothDevice device, boolean accept,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            if (deviceProp == null || !deviceProp.isBonding()) {
                return false;
            }
            service.logUserBondResponse(device, accept,
                    BluetoothProtoEnums.BOND_SUB_STATE_LOCAL_SSP_REPLIED);
            return service.sspReplyNative(
                    addressToBytes(device.getAddress()),
                    AbstractionLayer.BT_SSP_VARIANT_PASSKEY_CONFIRMATION,
                    accept,
                    0);
        }

        @Override
        public boolean getSilenceMode(BluetoothDevice device, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);

            return service.mSilenceDeviceManager.getSilenceMode(device);
        }

        @Override
        public boolean setSilenceMode(BluetoothDevice device, boolean silence,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);

            service.mSilenceDeviceManager.setSilenceMode(device, silence);
            return true;
        }

        @Override
        public int getPhonebookAccessPermission(
            BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getPhonebookAccessPermission")
                    || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getPhonebookAccessPermission")) {
                return BluetoothDevice.ACCESS_UNKNOWN;
            }
            return service.getPhonebookAccessPermission(device);
        }


        @Override
        public boolean setPhonebookAccessPermission(BluetoothDevice device, int value,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.setPhonebookAccessPermission(device, value);
            return true;
        }

        @Override
        public int getMessageAccessPermission(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getMessageAccessPermission")
                    || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getMessageAccessPermission")) {
                return BluetoothDevice.ACCESS_UNKNOWN;
            }
            return service.getMessageAccessPermission(device);
        }

        @Override
        public boolean setMessageAccessPermission(BluetoothDevice device, int value,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            service.setMessageAccessPermission(device, value);
            return true;
        }

        @Override
        public int getSimAccessPermission(
                BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getSimAccessPermission")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getSimAccessPermission")) {
                return BluetoothDevice.ACCESS_UNKNOWN;
            }
            return service.getSimAccessPermission(device);
        }

        @Override
        public boolean setSimAccessPermission(BluetoothDevice device, int value,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }

            enforceBluetoothPrivilegedPermission(service);

            service.setSimAccessPermission(device, value);
            return true;
        }

        @Override
        public IBluetoothSocketManager getSocketManager() {
            AdapterService service = getService();
            if (service == null) {
                return null;
            }
            return service.getSocketManager();
        }

        @Override
        public boolean sdpSearch(
                BluetoothDevice device, ParcelUuid uuid, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "sdpSearch")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService sdpSearch")) {
                return false;
            }
            if (service.mSdpManager == null) {
                return false;
            }
            service.mSdpManager.sdpSearch(device, uuid);
            return true;
        }

        @Override
        public boolean isTwsPlusDevice(BluetoothDevice device,
                AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "isTwsPlusDevice")) {
                return false;
            }
            return service.isTwsPlusDevice(device);
        }

        @Override
        public String getTwsPlusPeerAddress(BluetoothDevice device,
                AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "getTwsPlusPeerAddress")) {
                return null;
            }
            return service.getTwsPlusPeerAddress(device);
        }

        @Override
        public int getBatteryLevel(BluetoothDevice device, AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !callerIsSystemOrActiveUser(TAG, "getBatteryLevel")
                    || !Utils.checkConnectPermissionForDataDelivery(
                            service, attributionSource, "AdapterService getBatteryLevel")) {
                return BluetoothDevice.BATTERY_LEVEL_UNKNOWN;
            }

            DeviceProperties deviceProp = service.mRemoteDevices.getDeviceProperties(device);
            if (deviceProp == null) {
                return BluetoothDevice.BATTERY_LEVEL_UNKNOWN;
            }
            return deviceProp.getBatteryLevel();
        }

        @Override
        public int getMaxConnectedAudioDevices(AttributionSource attributionSource) {
            // don't check caller, may be called from system UI
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                    service, attributionSource, "AdapterService getMaxConnectedAudioDevices")) {
                return AdapterProperties.MAX_CONNECTED_AUDIO_DEVICES_LOWER_BOND;
            }
            return service.getMaxConnectedAudioDevices();
        }

        @Override
        public boolean isBroadcastActive(AttributionSource attributionSource) {
            AdapterService service = getService();
            if (service == null || !Utils.checkConnectPermissionForDataDelivery(
                         service, attributionSource, "AdapterService isBroadcastActive")) {
                return false;
            }
            return service.isBroadcastActive();
        }
        @Override
        public boolean factoryReset(AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);
            if ((getState() == BluetoothAdapter.STATE_BLE_ON) ||
                (getState() == BluetoothAdapter.STATE_BLE_TURNING_ON)) {
                service.onBrEdrDown();
            } else {
                service.disable();
            }
            if (service.mDatabaseManager != null) {
                service.mDatabaseManager.factoryReset();
            }
            if (service.mBluetoothKeystoreService != null) {
                service.mBluetoothKeystoreService.factoryReset();
            }
            return service.factoryResetNative();
        }

        @Override
        public boolean registerBluetoothConnectionCallback(IBluetoothConnectionCallback callback,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.mBluetoothConnectionCallbacks.add(callback);
            return true;
        }

        @Override
        public boolean unregisterBluetoothConnectionCallback(
                IBluetoothConnectionCallback callback, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);
            return service.mBluetoothConnectionCallbacks.remove(callback);
        }

        @Override
        public void registerCallback(IBluetoothCallback callback, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.mCallbacks.register(callback);
        }

        @Override
        public void unregisterCallback(IBluetoothCallback callback, AttributionSource source) {
            AdapterService service = getService();
            if (service == null || service.mCallbacks == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.mCallbacks.unregister(callback);
        }

        @Override
        public boolean isMultiAdvertisementSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }

            int val = service.mAdapterProperties.getNumOfAdvertisementInstancesSupported();
            return val >= MIN_ADVT_INSTANCES_FOR_MA;
        }

        /**
         * This method has an associated binder cache.  The invalidation
         * methods must be changed if the logic behind this method changes.
         */
        @Override
        public boolean isOffloadedFilteringSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            int val = service.getNumOfOffloadedScanFilterSupported();
            return val >= MIN_OFFLOADED_FILTERS;
        }

        @Override
        public boolean isOffloadedScanBatchingSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            int val = service.getOffloadedScanResultStorage();
            return val >= MIN_OFFLOADED_SCAN_STORAGE_BYTES;
        }

        @Override
        public boolean isLe2MPhySupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            return service.isLe2MPhySupported();
        }

        @Override
        public boolean isLeCodedPhySupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            return service.isLeCodedPhySupported();
        }

        @Override
        public boolean isLeExtendedAdvertisingSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            return service.isLeExtendedAdvertisingSupported();
        }

        @Override
        public boolean isLePeriodicAdvertisingSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            return service.isLePeriodicAdvertisingSupported();
        }

        @Override
        public int getLeMaximumAdvertisingDataLength() {
            AdapterService service = getService();
            if (service == null) {
                return 0;
            }
            return service.getLeMaximumAdvertisingDataLength();
        }

        @Override
        public boolean isActivityAndEnergyReportingSupported() {
            AdapterService service = getService();
            if (service == null) {
                return false;
            }
            return service.mAdapterProperties.isActivityAndEnergyReportingSupported();
        }

        @Override
        public BluetoothActivityEnergyInfo reportActivityInfo(AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return null;
            }

            enforceBluetoothPrivilegedPermission(service);

            return service.reportActivityInfo();
        }

        @Override
        public boolean registerMetadataListener(IBluetoothMetadataListener listener,
                BluetoothDevice device, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);

            if (service.mMetadataListeners == null) {
                return false;
            }
            ArrayList<IBluetoothMetadataListener> list = service.mMetadataListeners.get(device);
            if (list == null) {
                list = new ArrayList<>();
            } else if (list.contains(listener)) {
                // The device is already registered with this listener
                return true;
            }
            list.add(listener);
            service.mMetadataListeners.put(device, list);
            return true;
        }

        @Override
        public boolean unregisterMetadataListener(BluetoothDevice device,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);

            if (service.mMetadataListeners == null) {
                return false;
            }
            if (service.mMetadataListeners.containsKey(device)) {
                service.mMetadataListeners.remove(device);
            }
            return true;
        }

        @Override
        public boolean setMetadata(BluetoothDevice device, int key, byte[] value,
                AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return false;
            }
            enforceBluetoothPrivilegedPermission(service);

            if (value.length > BluetoothDevice.METADATA_MAX_LENGTH) {
                return false;
            }
            return service.mDatabaseManager.setCustomMeta(device, key, value);
        }

        @Override
        public byte[] getMetadata(BluetoothDevice device, int key, AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return null;
            }
            enforceBluetoothPrivilegedPermission(service);
            return service.mDatabaseManager.getCustomMeta(device, key);
        }

        @Override
        public void requestActivityInfo(ResultReceiver result, AttributionSource source) {
            Bundle bundle = new Bundle();
            bundle.putParcelable(BatteryStats.RESULT_RECEIVER_CONTROLLER_KEY, reportActivityInfo(source));
            result.send(0, bundle);
        }

        @Override
        public void onLeServiceUp(AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.mAdapterStateMachine.sendMessage(AdapterState.USER_TURN_ON);
        }

        @Override
        public void updateQuietModeStatus(boolean quietMode, AttributionSource source) {
            AdapterService service = getService();
            if (service == null  || !Utils.checkConnectPermissionForDataDelivery(
                    service, source, "updateQuietModeStatus")) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.updateQuietModeStatus(quietMode);
        }


        @Override
        public void onBrEdrDown(AttributionSource source) {
            AdapterService service = getService();
            if (service == null
                    || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    || !Utils.checkConnectPermissionForDataDelivery(service, source, TAG)) {
                return;
            }
            enforceBluetoothPrivilegedPermission(service);
            service.mAdapterStateMachine.sendMessage(AdapterState.BLE_TURN_OFF);
        }

        @Override
        public int setSocketOpt(int type, int channel, int optionName, byte [] optionVal,
                int optionLen) {
            AdapterService service = getService();
            if (service == null || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    ||  !Utils.checkConnectPermissionForDataDelivery(
                    service,  Utils.getCallingAttributionSource(), "setSocketOpt")) {
                Log.w(TAG,"setSocketOpt not allowed for non-active user");
                return -1;
            }
            return service.setSocketOpt(type, channel, optionName, optionVal, optionLen);
        }

        @Override
        public int getSocketOpt(int type, int channel, int optionName, byte [] optionVal) {
            AdapterService service = getService();
            if (service == null || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    ||  !Utils.checkConnectPermissionForDataDelivery(
                            service,  Utils.getCallingAttributionSource(), "getSocketOpt")) {
                Log.w(TAG,"getSocketOpt not allowed for non-active user");
                return -1;
            }
            return service.getSocketOpt(type, channel, optionName, optionVal);
        }

        @Override
        public void dump(FileDescriptor fd, String[] args) {
            PrintWriter writer = new PrintWriter(new FileOutputStream(fd));
            AdapterService service = getService();
            if (service == null) {
                return;
            }
            enforceDumpPermission(service);
            service.dump(fd, writer, args);
            writer.close();
        }

        @Override
        public int getDeviceType(BluetoothDevice device, AttributionSource source) {
            AdapterService service = getService();
            if (service == null || !Utils.checkCallerIsSystemOrActiveUser(TAG)
                    ||  !Utils.checkConnectPermissionForDataDelivery(
                            service, source, "getDeviceType")) {
                Log.w(TAG,"getDeviceType not allowed for non-active user");
                return -1;
            }
            enforceBluetoothPrivilegedPermission(service);
            return service.getDeviceType(device);
        }

    }

    ;

    public boolean isEnabled() {
        return mAdapterProperties.getState() == BluetoothAdapter.STATE_ON;
    }

     // ----API Methods--------

    public boolean isVendorIntfEnabled() {
        return mVendorAvailble;
    }

    public int getState() {
        if (mAdapterProperties != null) {
            return mAdapterProperties.getState();
        }
        return BluetoothAdapter.STATE_OFF;
    }

    public boolean enable() {
        return enable(false);
    }

    public synchronized boolean enable(boolean quietMode) {
        // Enforce the user restriction for disallowing Bluetooth if it was set.
        if (mUserManager.hasUserRestriction(UserManager.DISALLOW_BLUETOOTH, UserHandle.SYSTEM)) {
            debugLog("enable() called when Bluetooth was disallowed");
            return false;
        }

        debugLog("enable() - Enable called with quiet mode status =  " + quietMode);
        mQuietmode = quietMode;
        mAdapterStateMachine.sendMessage(AdapterState.BLE_TURN_ON);
        return true;
    }

    boolean disable() {
        debugLog("disable() called with mRunningProfiles.size() = " + mRunningProfiles.size());
        mAdapterStateMachine.sendMessage(AdapterState.USER_TURN_OFF);
        return true;
    }

    public String getName() {

        try {
            return mAdapterProperties.getName();
        } catch (Throwable t) {
            debugLog("getName() - Unexpected exception (" + t + ")");
        }
        return null;
    }

    public int getNameLengthForAdvertise() {
        return mAdapterProperties.getName().length();
    }

    private static boolean isValidIoCapability(int capability) {
        if (capability < 0 || capability >= BluetoothAdapter.IO_CAPABILITY_MAX) {
            Log.e(TAG, "Invalid IO capability value - " + capability);
            return false;
        }

        return true;
    }

    private boolean validateInputOutputCapability(int capability) {
        if (capability < 0 || capability >= BluetoothAdapter.IO_CAPABILITY_MAX) {
            Log.e(TAG, "Invalid IO capability value - " + capability);
            return false;
        }

        return true;
    }

    boolean setTwsPlusDevType(byte[] address, short twsPlusDevType) {
        BluetoothDevice device = mRemoteDevices.getDevice(address);
        DeviceProperties deviceProp;
        if (device == null) {
            deviceProp = mRemoteDevices.addDeviceProperties(address);
        } else {
            deviceProp = mRemoteDevices.getDeviceProperties(device);
        }
        if(deviceProp != null) {
            deviceProp.setTwsPlusDevType(twsPlusDevType);
            return true;
        }
        return false;
    }

    boolean setTwsPlusPeerEbAddress(byte[] address, byte[] peerEbAddress) {

        BluetoothDevice device = mRemoteDevices.getDevice(address);
        BluetoothDevice peerDevice = null;
        DeviceProperties deviceProp;
        DeviceProperties peerDeviceProp;

        if(peerEbAddress != null)
            peerDevice = mRemoteDevices.getDevice(peerEbAddress);

        if (device == null) {
            deviceProp = mRemoteDevices.addDeviceProperties(address);
        } else {
            deviceProp = mRemoteDevices.getDeviceProperties(device);
        }
        if (peerDevice == null && peerEbAddress != null) {
            peerDeviceProp = mRemoteDevices.addDeviceProperties(peerEbAddress);
            peerDevice = mRemoteDevices.getDevice(peerEbAddress);
        }
        if(deviceProp != null) {
            deviceProp.setTwsPlusPeerEbAddress(peerDevice, peerEbAddress);
            return true;
        }
        return false;
    }

    boolean setTwsPlusAutoConnect(byte[] address, boolean autoConnect) {
        BluetoothDevice device = mRemoteDevices.getDevice(address);
        BluetoothDevice peerDevice = null;
        DeviceProperties deviceProp;

        if (device == null) {
            deviceProp = mRemoteDevices.addDeviceProperties(address);
        } else {
            deviceProp = mRemoteDevices.getDeviceProperties(device);
        }
        if(deviceProp != null) {
            deviceProp.setTwsPlusAutoConnect(peerDevice, autoConnect);
            return true;
        }
        return false;
    }

    void updateHostFeatureSupport(byte[] val) {
        mAdapterProperties.updateHostFeatureSupport(val);
    }

    void updateSocFeatureSupport(byte[] val) {
        mAdapterProperties.updateSocFeatureSupport(val);
    }

    void updateWhitelistedMediaPlayers(String Playername) {
        mAdapterProperties.updateWhitelistedMediaPlayers(Playername);
    }

    public String[] getWhitelistedMediaPlayers() {
        return mAdapterProperties.getWhitelistedMediaPlayers();
    }

    int getScanMode() {
        return mAdapterProperties.getScanMode();
    }

    ArrayList<DiscoveringPackage> getDiscoveringPackages() {
        return mDiscoveringPackages;
    }

    void clearDiscoveringPackages() {
        synchronized (mDiscoveringPackages) {
            mDiscoveringPackages.clear();
        }
    }

    boolean startDiscovery(AttributionSource attributionSource) {
        UserHandle callingUser = UserHandle.of(UserHandle.getCallingUserId());
        debugLog("startDiscovery");
        String callingPackage = attributionSource.getPackageName();
        mAppOps.checkPackage(Binder.getCallingUid(), callingPackage);
        boolean isQApp = Utils.isQApp(this, callingPackage);
        boolean hasDisavowedLocation =
                Utils.hasDisavowedLocationForScan(this, attributionSource, mTestModeEnabled);
        String permission = null;
        if (Utils.checkCallerHasNetworkSettingsPermission(this)) {
            permission = android.Manifest.permission.NETWORK_SETTINGS;
        } else if (Utils.checkCallerHasNetworkSetupWizardPermission(this)) {
            permission = android.Manifest.permission.NETWORK_SETUP_WIZARD;
        } else if (!hasDisavowedLocation) {
            if (isQApp) {
                if (!Utils.checkCallerHasFineLocation(this, attributionSource, callingUser)) {
                    return false;
                }
                permission = android.Manifest.permission.ACCESS_FINE_LOCATION;
            } else {
                if (!Utils.checkCallerHasCoarseLocation(this, attributionSource, callingUser)) {
                    return false;
                }
                permission = android.Manifest.permission.ACCESS_COARSE_LOCATION;
            }
        }
        synchronized (mDiscoveringPackages) {
            mDiscoveringPackages.add(
                    new DiscoveringPackage(callingPackage, permission, hasDisavowedLocation));
        }

        return startDiscoveryNative();
    }

    boolean cancelDiscovery() {
        debugLog("cancelDiscovery");
        if (!mAdapterProperties.isDiscovering()) {
            Log.i(TAG,"discovery not active, ignore cancelDiscovery");
            return false;
        }
        return cancelDiscoveryNative();
    }

    /**
     * Same as API method {@link BluetoothAdapter#getBondedDevices()}
     *
     * @return array of bonded {@link BluetoothDevice} or null on error
     */
    public BluetoothDevice[] getBondedDevices() {
        return mAdapterProperties.getBondedDevices();
    }

    /**
     * Get the database manager to access Bluetooth storage
     *
     * @return {@link DatabaseManager} or null on error
     */
    @VisibleForTesting
    public DatabaseManager getDatabase() {
        return mDatabaseManager;
    }

    public boolean isTwsPlusDevice(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return false;
        }
        return (deviceProp.getTwsPlusPeerAddress() != null);
    }

    public String getTwsPlusPeerAddress(BluetoothDevice device)  {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return null;
        }
        byte[] address = deviceProp.getTwsPlusPeerAddress();
        return Utils.getAddressStringFromByte(address);
    }

    public BluetoothDevice getTwsPlusPeerDevice(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return null;
        }
        byte[] address = deviceProp.getTwsPlusPeerAddress();
        return mRemoteDevices.getDevice(address);
    }

    public boolean createBond(BluetoothDevice device, int transport, OobData remoteP192Data,
            OobData remoteP256Data, String callingPackage) {

        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp != null && deviceProp.getBondState() != BluetoothDevice.BOND_NONE) {
            return false;
        }

        if (!isPackageNameAccurate(this, callingPackage, Binder.getCallingUid())) {
            return false;
        }
        mRemoteDevices.setBondingInitiatedLocally(Utils.getByteAddress(device));

        // Pairing is unreliable while scanning, so cancel discovery
        // Note, remove this when native stack improves
        if (!mAdapterProperties.isDiscovering()) {
            Log.i(TAG,"discovery not active, no need to send cancelDiscovery");
        } else {
            cancelDiscoveryNative();
        }

        Message msg = mBondStateMachine.obtainMessage(BondStateMachine.CREATE_BOND);
        msg.obj = device;
        msg.arg1 = transport;

        Bundle remoteOobDatasBundle = new Bundle();
        boolean setData = false;
        if (remoteP192Data != null) {
            remoteOobDatasBundle.putParcelable(BondStateMachine.OOBDATAP192, remoteP192Data);
            setData = true;
        }
        if (remoteP256Data != null) {
            remoteOobDatasBundle.putParcelable(BondStateMachine.OOBDATAP256, remoteP256Data);
            setData = true;
        }
        if (setData) {
            msg.setData(remoteOobDatasBundle);
        }
        mBondStateMachine.sendMessage(msg);
        return true;
    }

    private final ArrayDeque<IBluetoothOobDataCallback> mOobDataCallbackQueue =
            new ArrayDeque<>();

    /**
     * Fetches the local OOB data to give out to remote.
     *
     * @param transport - specify data transport.
     * @param callback - callback used to receive the requested {@link Oobdata}; null will be
     * ignored silently.
     *
     * @hide
     */
    public synchronized void generateLocalOobData(int transport,
            IBluetoothOobDataCallback callback) {
        if (callback == null) {
            Log.e(TAG, "'callback' argument must not be null!");
            return;
        }
        if (mOobDataCallbackQueue.peek() != null) {
            try {
                callback.onError(BluetoothStatusCodes.ERROR_ANOTHER_ACTIVE_OOB_REQUEST);
                return;
            } catch (RemoteException e) {
                Log.e(TAG, "Failed to make callback", e);
            }
        }
        mOobDataCallbackQueue.offer(callback);
        generateLocalOobDataNative(transport);
    }

    /* package */ synchronized void notifyOobDataCallback(int transport, OobData oobData) {
        if (mOobDataCallbackQueue.peek() == null) {
            Log.e(TAG, "Failed to make callback, no callback exists");
            return;
        }
        if (oobData == null) {
            try {
                mOobDataCallbackQueue.poll().onError(BluetoothStatusCodes.ERROR_UNKNOWN);
            } catch (RemoteException e) {
                Log.e(TAG, "Failed to make callback", e);
            }
        } else {
            try {
                mOobDataCallbackQueue.poll().onOobData(transport, oobData);
            } catch (RemoteException e) {
                Log.e(TAG, "Failed to make callback", e);
            }
        }
    }

    public boolean isQuietModeEnabled() {
        debugLog("isQuetModeEnabled() - Enabled = " + mQuietmode);
        return mQuietmode;
    }

    public void updateUuids() {
        debugLog("updateUuids() - Updating UUIDs for bonded devices");
        BluetoothDevice[] bondedDevices = getBondedDevices();
        if (bondedDevices == null) {
            return;
        }

        for (BluetoothDevice device : bondedDevices) {
            mRemoteDevices.updateUuids(device);
        }
    }

    /**
     * Update device UUID changed to {@link BondStateMachine}
     *
     * @param device remote device of interest
     */
    public void deviceUuidUpdated(BluetoothDevice device) {
        // Notify BondStateMachine for SDP complete / UUID changed.
        Message msg = mBondStateMachine.obtainMessage(BondStateMachine.UUID_UPDATE);
        msg.obj = device;
        mBondStateMachine.sendMessage(msg);
    }

    boolean removeBond(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null || deviceProp.getBondState() != BluetoothDevice.BOND_BONDED) {
            return false;
        }
        deviceProp.setBondingInitiatedLocally(false);
        if (device.isTwsPlusDevice()) {
            mActiveDeviceManager.notify_active_device_unbonding(device);
        }
        BluetoothDevice mappingDevice
            = mRemoteDevices.getDevice(deviceProp.getMappingAddr());
        if (mappingDevice != null) {
            DeviceProperties deviceMapProp
                = mRemoteDevices.getDeviceProperties(mappingDevice);
            if (deviceMapProp != null) {
                deviceMapProp.setDefaultBDAddrValidType();
            } else {
                deviceProp.setDefaultBDAddrValidType();
            }
        } else {
            deviceProp.setDefaultBDAddrValidType();
        }
        Message msg = mBondStateMachine.obtainMessage(BondStateMachine.REMOVE_BOND);
        msg.obj = device;
        mBondStateMachine.sendMessage(msg);
        return true;
    }

    /**
     * Get the bond state of a particular {@link BluetoothDevice}
     *
     * @param device remote device of interest
     * @return bond state <p>Possible values are
     * {@link BluetoothDevice#BOND_NONE},
     * {@link BluetoothDevice#BOND_BONDING},
     * {@link BluetoothDevice#BOND_BONDED}.
     */
    @VisibleForTesting
    public int getBondState(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return BluetoothDevice.BOND_NONE;
        }
        return deviceProp.getBondState();
    }

    void setBondingInitiatedLocally(BluetoothDevice device, boolean localInitiated) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return;
        }
        Log.w(TAG," localInitiated " + localInitiated);
        deviceProp.setBondingInitiatedLocally(localInitiated);
        return;
    }

    long getSupportedProfiles() {
        return Config.getSupportedProfilesBitMask();
    }

    int getConnectionState(BluetoothDevice device) {
        byte[] addr = Utils.getBytesFromAddress(device.getAddress());
        return getConnectionStateNative(addr);
    }

    /**
     * Sets device as the active devices for the profiles passed into the function
     *
     * @param device is the remote bluetooth device
     * @param profiles is a constant that references for which profiles we'll be setting the remote
     *                 device as our active device. One of the following:
     *                 {@link BluetoothAdapter#ACTIVE_DEVICE_AUDIO},
     *                 {@link BluetoothAdapter#ACTIVE_DEVICE_PHONE_CALL}
     *                 {@link BluetoothAdapter#ACTIVE_DEVICE_ALL}
     * @return false if profiles value is not one of the constants we accept, true otherwise
     */
    public boolean setActiveDevice(BluetoothDevice device, @ActiveDeviceUse int profiles) {
        enforceCallingOrSelfPermission(
                BLUETOOTH_PRIVILEGED, "Need BLUETOOTH_PRIVILEGED permission");

        boolean setA2dp = false;
        boolean setHeadset = false;
        boolean isLeAudioEnabled = ApmConstIntf.getLeAudioEnabled();
        ActiveDeviceManagerServiceIntf activeDeviceManager = ActiveDeviceManagerServiceIntf.get();

        // Determine for which profiles we want to set device as our active device
        switch(profiles) {
            case BluetoothAdapter.ACTIVE_DEVICE_AUDIO:
                setA2dp = true;
                break;
            case BluetoothAdapter.ACTIVE_DEVICE_PHONE_CALL:
                setHeadset = true;
                break;
            case BluetoothAdapter.ACTIVE_DEVICE_ALL:
                setA2dp = true;
                setHeadset = true;
                break;
            default:
                return false;
        }

        if (setA2dp && mA2dpService != null) {
            if(isLeAudioEnabled) {
                activeDeviceManager.setActiveDevice(device,
                        ApmConstIntf.AudioFeatures.MEDIA_AUDIO, true);
            } else {
                mA2dpService.setActiveDevice(device);
            }
        }

        // Always sets as active device for hearing aid profile
        if (mHearingAidService != null) {
            mHearingAidService.setActiveDevice(device);
        }

        if (setHeadset && mHeadsetService != null) {
            if(isLeAudioEnabled) {
                activeDeviceManager.setActiveDevice(device,
                        ApmConstIntf.AudioFeatures.CALL_AUDIO, true);
            } else {
                mHeadsetService.setActiveDevice(device);
            }
        }

        return true;
    }

    /**
     * Connects all enabled and supported bluetooth profiles between the local and remote device
     *
     * @param device is the remote device with which to connect these profiles
     * @return true if all profiles successfully connected, false if an error occurred
     */
    @RequiresPermission(allOf = {
            android.Manifest.permission.BLUETOOTH_PRIVILEGED,
            android.Manifest.permission.MODIFY_PHONE_STATE,
    })
    public boolean connectAllEnabledProfiles(BluetoothDevice device) {
        if (!profileServicesRunning()) {
            Log.e(TAG, "connectAllEnabledProfiles: Not all profile services running");
            return false;
        }
        boolean isLeAudioEnabled = ApmConstIntf.getLeAudioEnabled();

        // Checks if any profiles are enabled and if so, only connect enabled profiles
        if (isAnyProfileEnabled(device)) {
            return connectEnabledProfiles(device);
        }

        int numProfilesConnected = 0;
        ParcelUuid[] remoteDeviceUuids = getRemoteUuids(device);
        ParcelUuid[] localDeviceUuids = mAdapterProperties.getUuids();

        // All profile toggles disabled, so connects all supported profiles
        if(isLeAudioEnabled) {
    /*Check for isSupported here for LE devices*/
            MediaAudioIntf mMediaAudio = MediaAudioIntf.get();
            if(mMediaAudio != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                        BluetoothProfile.A2DP, device)) {
                mMediaAudio.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
                numProfilesConnected++;
            }
        } else if (mA2dpService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting A2dp");
            // Set connection policy also connects the profile with CONNECTION_POLICY_ALLOWED
            mA2dpService.setConnectionPolicy(device, BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mA2dpSinkService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.A2DP_SINK, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting A2dp Sink");
            mA2dpSinkService.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if(isLeAudioEnabled) {
            CallAudioIntf mCallAudio = CallAudioIntf.get();
            if(mCallAudio != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                        BluetoothProfile.HEADSET, device)) {
                mCallAudio.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
                numProfilesConnected++;
            }
        } else if (mHeadsetService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEADSET, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting Headset Profile");
            mHeadsetService.setConnectionPolicy(device, BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mHeadsetClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEADSET_CLIENT, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting HFP");
            mHeadsetClientService.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mMapClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.MAP_CLIENT, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting MAP");
            mMapClientService.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mHidHostService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HID_HOST, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting Hid Host Profile");
            mHidHostService.setConnectionPolicy(device, BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mPanService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.PAN, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting Pan Profile");
            mPanService.setConnectionPolicy(device, BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mPbapClientService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.PBAP_CLIENT, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting Pbap");
            mPbapClientService.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        if (mHearingAidService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.HEARING_AID, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting Hearing Aid Profile");
            mHearingAidService.setConnectionPolicy(device,
                    BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            numProfilesConnected++;
        }
        ///*_REF
        if (mBCService != null && isSupported(localDeviceUuids, remoteDeviceUuids,
                BluetoothProfile.BC_PROFILE, device)) {
            Log.i(TAG, "connectAllEnabledProfiles: Connecting BC Profile");
            try {
                  mBCSetConnPolicy.invoke(mBCService, device,BluetoothProfile.CONNECTION_POLICY_ALLOWED);
            } catch(IllegalAccessException e) {
                   Log.e(TAG, "BC:setConnPolicy IllegalAccessException");
            } catch (InvocationTargetException e) {
                  Log.e(TAG, "BC:setConnPolicy InvocationTargetException");
            }
            numProfilesConnected++;
        }
        //_REF*/

        Log.i(TAG, "connectAllEnabledProfiles: Number of Profiles Connected: "
                + numProfilesConnected);

        return true;
    }

    /**
     * Disconnects all enabled and supported bluetooth profiles between the local and remote device
     *
     * @param device is the remote device with which to disconnect these profiles
     * @return true if all profiles successfully disconnected, false if an error occurred
     */
    @RequiresPermission(android.Manifest.permission.BLUETOOTH_PRIVILEGED)
    public boolean disconnectAllEnabledProfiles(BluetoothDevice device) {
        CallAudioIntf mCallAudio = CallAudioIntf.get();
        MediaAudioIntf mMediaAudio = MediaAudioIntf.get();
        boolean disconnectMedia = false;

        if (!profileServicesRunning()) {
            Log.e(TAG, "disconnectAllEnabledProfiles: Not all profile services bound");
            return false;
        }
        boolean isLeAudioEnabled = ApmConstIntf.getLeAudioEnabled();
        if(isLeAudioEnabled) {
            if(mMediaAudio != null)
                mMediaAudio.disconnect(device, true);
                disconnectMedia = true;
        } else if (mA2dpService != null && mA2dpService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting A2dp");
            mA2dpService.disconnect(device);
        }
        if (mA2dpSinkService != null && mA2dpSinkService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting A2dp Sink");
            mA2dpSinkService.disconnect(device);
        }
        if(isLeAudioEnabled) {
            if(mCallAudio != null)
                mCallAudio.disconnect(device, disconnectMedia);
        } else if (mHeadsetService != null && mHeadsetService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG,
                    "disconnectAllEnabledProfiles: Disconnecting Headset Profile");
            mHeadsetService.disconnect(device);
        }
        if (mHeadsetClientService != null && mHeadsetClientService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting HFP");
            mHeadsetClientService.disconnect(device);
        }
        if (mMapClientService != null && mMapClientService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting MAP Client");
            mMapClientService.disconnect(device);
        }
        if (mMapService != null && mMapService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting MAP");
            mMapService.disconnect(device);
        }
        if (mHidDeviceService != null && mHidDeviceService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Hid Device Profile");
            mHidDeviceService.disconnect(device);
        }
        if (mHidHostService != null && mHidHostService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Hid Host Profile");
            mHidHostService.disconnect(device);
        }
        if (mPanService != null && mPanService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Pan Profile");
            mPanService.disconnect(device);
        }
        if (mPbapClientService != null && mPbapClientService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Pbap Client");
            mPbapClientService.disconnect(device);
        }
        if (mPbapService != null && mPbapService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Pbap Server");
            mPbapService.disconnect(device);
        }
        if (mHearingAidService != null && mHearingAidService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Hearing Aid Profile");
            mHearingAidService.disconnect(device);
        }
        if (mSapService != null && mSapService.getConnectionState(device)
                == BluetoothProfile.STATE_CONNECTED) {
            Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting Sap Profile");
            mSapService.disconnect(device);
        }
        ///*_REF
        if (mBCService != null &&  mBCGetConnState != null) {
                int connState = BluetoothProfile.STATE_DISCONNECTED;
                try {
                   connState = (int) mBCGetConnState.invoke(mBCService, device);
                } catch(IllegalAccessException e) {
                   Log.e(TAG, "BC:Connstate IllegalAccessException");
                } catch (InvocationTargetException e) {
                   Log.e(TAG, "BC:Connstate InvocationTargetException");
                }
            if (connState == BluetoothProfile.STATE_CONNECTED) {
              Log.i(TAG, "disconnectAllEnabledProfiles: Disconnecting BC Profile");
              if (mBCDisconnect != null) {
                try {
                   mBCDisconnect.invoke(mBCService, device);
                } catch(IllegalAccessException e) {
                   Log.e(TAG, "BC:disconnect IllegalAccessException");
                } catch (InvocationTargetException e) {
                   Log.e(TAG, "BC:disonnect InvocationTargetException");
                }
              } else {
                Log.e(TAG, "no BC disconnect Handle");
              }
            }
        }
        //_REF*/

        return true;
    }

    /**
     * Same as API method {@link BluetoothDevice#getName()}
     *
     * @param device remote device of interest
     * @return remote device name
     */
    public String getRemoteName(BluetoothDevice device) {

        if (mBroadcastService != null && mBroadcastGetAddr != null
            && mBroadcastIsActive != null) {
            String Address = null;
            boolean isactive = false;
            try {
                Address = (String)mBroadcastGetAddr.invoke(mBroadcastService);
            } catch(IllegalAccessException e) {
                Log.e(TAG, "Broadcast:GetAddr IllegalAccessException");
            } catch (InvocationTargetException e) {
                Log.e(TAG, "Broadcast:GetAddr InvocationTargetException");
            }
            try {
                isactive = (boolean)mBroadcastIsActive.invoke(mBroadcastService);
            } catch(IllegalAccessException e) {
                Log.e(TAG, "Broadcast:IsActive IllegalAccessException");
            } catch (InvocationTargetException e) {
                Log.e(TAG, "Broadcast:IsActive InvocationTargetException");
            }
            if (device.getAddress().equals(Address) && isactive) {
                Log.d(TAG," Request Name for Broadcast device ");
                return "Broadcast_Source";
            }
        }
        if (device.getAddress().equals(BATService.mBAAddress)) {
            Log.d(TAG," Request Name for BA device ");
            return "Broadcast_Audio";
        }

        if (device.getAddress().contains("9E:8B:00:00:00")) {
            Log.d(TAG," Request Name for Group");
            return "BT-Audio-Group";
        }

        if (mRemoteDevices == null) {
            return null;
        }
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return null;
        }
        return deviceProp.getName();
    }

    /**
     * Get UUIDs for service supported by a remote device
     *
     * @param device the remote device that we want to get UUIDs from
     * @return
     */
    @VisibleForTesting
    public ParcelUuid[] getRemoteUuids(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return null;
        }
        return deviceProp.getUuids();
    }

    boolean fetchRemoteUuids(BluetoothDevice device) {
        if (device.getAddress().equals(BATService.mBAAddress)) {
            Log.d(TAG," Update from BA, don't check UUIDS, bail out");
            return false;
        }
        mRemoteDevices.fetchUuids(device);
        return true;
    }

    int getPhonebookAccessPermission(BluetoothDevice device) {
        if (mPbapService == null) {
            debugLog("getPhonebookAccessPermission - PbapService Not Enabled");
            return BluetoothDevice.ACCESS_UNKNOWN;
        }

        SharedPreferences pref = getSharedPreferences(PHONEBOOK_ACCESS_PERMISSION_PREFERENCE_FILE,
                Context.MODE_PRIVATE);
        if (!pref.contains(device.getAddress())) {
            return BluetoothDevice.ACCESS_UNKNOWN;
        }
        return pref.getBoolean(device.getAddress(), false) ? BluetoothDevice.ACCESS_ALLOWED
                : BluetoothDevice.ACCESS_REJECTED;
    }

    public boolean setPhonebookAccessPermission(BluetoothDevice device, int value) {
        if (mPbapService == null) {
            debugLog("setPhonebookAccessPermission - PbapService Not Enabled");
            return true;
        }
        SharedPreferences pref = getSharedPreferences(PHONEBOOK_ACCESS_PERMISSION_PREFERENCE_FILE,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = pref.edit();
        if (value == BluetoothDevice.ACCESS_UNKNOWN) {
            editor.remove(device.getAddress());
        } else {
            editor.putBoolean(device.getAddress(), value == BluetoothDevice.ACCESS_ALLOWED);
        }
        editor.apply();
        return true;
    }

    int getMessageAccessPermission(BluetoothDevice device) {
        if (mMapService == null) {
            debugLog("getMessageAccessPermission - MapService Not Enabled");
            return BluetoothDevice.ACCESS_UNKNOWN;
        }
        SharedPreferences pref = getSharedPreferences(MESSAGE_ACCESS_PERMISSION_PREFERENCE_FILE,
                Context.MODE_PRIVATE);
        if (!pref.contains(device.getAddress())) {
            return BluetoothDevice.ACCESS_UNKNOWN;
        }
        return pref.getBoolean(device.getAddress(), false) ? BluetoothDevice.ACCESS_ALLOWED
                : BluetoothDevice.ACCESS_REJECTED;
    }

    public boolean setMessageAccessPermission(BluetoothDevice device, int value) {
        if (mMapService == null) {
            debugLog("setMessageAccessPermission - MapService Not Enabled");
            return true;
        }
        SharedPreferences pref = getSharedPreferences(MESSAGE_ACCESS_PERMISSION_PREFERENCE_FILE,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = pref.edit();
        if (value == BluetoothDevice.ACCESS_UNKNOWN) {
            editor.remove(device.getAddress());
        } else {
            editor.putBoolean(device.getAddress(), value == BluetoothDevice.ACCESS_ALLOWED);
        }
        editor.apply();
        return true;
    }

    public Set<IBluetoothConnectionCallback> getBluetoothConnectionCallbacks() {
        return mBluetoothConnectionCallbacks;
    }

    /**
     * Converts HCI disconnect reasons to Android disconnect reasons.
     * <p>
     * The HCI Error Codes used for ACL disconnect reasons propagated up from native code were
     * copied from: {@link system/bt/stack/include/hci_error_code.h}.
     * <p>
     * These error codes are specified and described in Bluetooth Core Spec v5.1, Vol 2, Part D.
     *
     * @param hciReason is the raw HCI disconnect reason from native.
     * @return the Android disconnect reason for apps.
     */
    static @BluetoothAdapter.BluetoothConnectionCallback.DisconnectReason int
            hciToAndroidDisconnectReason(int hciReason) {
        switch(hciReason) {
            case /*HCI_SUCCESS*/ 0x00:
                return BluetoothStatusCodes.ERROR_UNKNOWN;
            case /*HCI_ERR_ILLEGAL_COMMAND*/ 0x01:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_NO_CONNECTION*/ 0x02:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_HW_FAILURE*/ 0x03:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_PAGE_TIMEOUT*/ 0x04:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_AUTH_FAILURE*/ 0x05:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_KEY_MISSING*/ 0x06:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_MEMORY_FULL*/ 0x07:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_CONNECTION_TOUT*/ 0x08:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_MAX_NUM_OF_CONNECTIONS*/ 0x09:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_MAX_NUM_OF_SCOS*/ 0x0A:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_CONNECTION_EXISTS*/ 0x0B:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_CONNECTION_ALREADY_EXISTS;
            case /*HCI_ERR_COMMAND_DISALLOWED*/ 0x0C:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_HOST_REJECT_RESOURCES*/ 0x0D:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_HOST_REJECT_SECURITY*/ 0x0E:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_HOST_REJECT_DEVICE*/ 0x0F:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SYSTEM_POLICY;
            case /*HCI_ERR_HOST_TIMEOUT*/ 0x10:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_ILLEGAL_PARAMETER_FMT*/ 0x12:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_BAD_PARAMETERS;
            case /*HCI_ERR_PEER_USER*/ 0x13:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_REMOTE_REQUEST;
            case /*HCI_ERR_CONN_CAUSE_LOCAL_HOST*/ 0x16:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL_REQUEST;
            case /*HCI_ERR_REPEATED_ATTEMPTS*/ 0x17:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_PAIRING_NOT_ALLOWED*/ 0x18:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_UNSUPPORTED_REM_FEATURE*/ 0x1A:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_REMOTE;
            case /*HCI_ERR_UNSPECIFIED*/ 0x1F:
                return BluetoothStatusCodes.ERROR_UNKNOWN;
            case /*HCI_ERR_LMP_RESPONSE_TIMEOUT*/ 0x22:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_ENCRY_MODE_NOT_ACCEPTABLE*/ 0x25:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_UNIT_KEY_USED*/ 0x26:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED*/ 0x29:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_DIFF_TRANSACTION_COLLISION*/ 0x2A:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_INSUFFCIENT_SECURITY*/ 0x2F:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_ROLE_SWITCH_PENDING*/ 0x32:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_ROLE_SWITCH_FAILED*/ 0x35:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_LOCAL;
            case /*HCI_ERR_HOST_BUSY_PAIRING*/ 0x38:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_SECURITY;
            case /*HCI_ERR_UNACCEPT_CONN_INTERVAL*/ 0x3B:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_BAD_PARAMETERS;
            case /*HCI_ERR_ADVERTISING_TIMEOUT*/ 0x3C:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_CONN_FAILED_ESTABLISHMENT*/ 0x3E:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_TIMEOUT;
            case /*HCI_ERR_LIMIT_REACHED*/ 0x43:
                return BluetoothStatusCodes.ERROR_DISCONNECT_REASON_RESOURCE_LIMIT_REACHED;
            case /*HCI_ERR_UNDEFINED*/ 0xff:
                return BluetoothStatusCodes.ERROR_UNKNOWN;
            default:
                Log.e(TAG, "Invalid HCI disconnect reason: " + hciReason);
                return BluetoothStatusCodes.ERROR_UNKNOWN;
        }
    }

    void logUserBondResponse(BluetoothDevice device, boolean accepted, int event) {
        final long token = Binder.clearCallingIdentity();
        try {
            BluetoothStatsLog.write(BluetoothStatsLog.BLUETOOTH_BOND_STATE_CHANGED,
                    obfuscateAddress(device), 0, device.getType(),
                    BluetoothDevice.BOND_BONDING,
                    event,
                    accepted ? 0 : BluetoothDevice.UNBOND_REASON_AUTH_REJECTED);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
    }

    int getSimAccessPermission(BluetoothDevice device) {
        if (mSapService == null) {
            debugLog("getSimAccessPermission - SapService Not Enabled");
            return BluetoothDevice.ACCESS_UNKNOWN;
        }
        SharedPreferences pref =
                getSharedPreferences(SIM_ACCESS_PERMISSION_PREFERENCE_FILE, Context.MODE_PRIVATE);
        if (!pref.contains(device.getAddress())) {
            return BluetoothDevice.ACCESS_UNKNOWN;
        }
        return pref.getBoolean(device.getAddress(), false) ? BluetoothDevice.ACCESS_ALLOWED
                : BluetoothDevice.ACCESS_REJECTED;
    }

    public boolean setSimAccessPermission(BluetoothDevice device, int value) {
        if (mSapService == null) {
            debugLog("setSimAccessPermission - SapService Not Enabled");
            return true;
        }

        SharedPreferences pref =
                getSharedPreferences(SIM_ACCESS_PERMISSION_PREFERENCE_FILE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = pref.edit();
        if (value == BluetoothDevice.ACCESS_UNKNOWN) {
            editor.remove(device.getAddress());
        } else {
            editor.putBoolean(device.getAddress(), value == BluetoothDevice.ACCESS_ALLOWED);
        }
        editor.apply();
        return true;
    }

    void sendConnectionStateChange(BluetoothDevice device, int profile, int state, int prevState) {
        // TODO(BT) permission check?
        // Since this is a binder call check if Bluetooth is on still
        if (getState() == BluetoothAdapter.STATE_OFF) {
            return;
        }

        mAdapterProperties.sendConnectionStateChange(device, profile, state, prevState);

    }

    IBluetoothSocketManager getSocketManager() {
        android.os.IBinder obj = getSocketManagerNative();
        if (obj == null) {
            return null;
        }

        return IBluetoothSocketManager.Stub.asInterface(obj);
    }

    public int getNumOfOffloadedIrkSupported() {
        return mAdapterProperties.getNumOfOffloadedIrkSupported();
    }

    public int getNumOfOffloadedScanFilterSupported() {
        return mAdapterProperties.getNumOfOffloadedScanFilterSupported();
    }

    public int getOffloadedScanResultStorage() {
        return mAdapterProperties.getOffloadedScanResultStorage();
    }

    public boolean isLe2MPhySupported() {
        return mAdapterProperties.isLe2MPhySupported();
    }

    public boolean isLeCodedPhySupported() {
        return mAdapterProperties.isLeCodedPhySupported();
    }

    public boolean isLeExtendedAdvertisingSupported() {
        return mAdapterProperties.isLeExtendedAdvertisingSupported();
    }

    public boolean isLePeriodicAdvertisingSupported() {
        return mAdapterProperties.isLePeriodicAdvertisingSupported();
    }

    public int getLeMaximumAdvertisingDataLength() {
        return mAdapterProperties.getLeMaximumAdvertisingDataLength();
    }

    /**
     * Get the maximum number of connected audio devices.
     *
     * @return the maximum number of connected audio devices
     */
    public int getMaxConnectedAudioDevices() {
        return mAdapterProperties.getMaxConnectedAudioDevices();
    }

    /**
     * Check whether A2DP offload is enabled.
     *
     * @return true if A2DP offload is enabled
     */
    public boolean isA2dpOffloadEnabled() {
        return mAdapterProperties.isA2dpOffloadEnabled();
    }

    public boolean isBroadcastActive() {
        if (mBroadcastService != null && mBroadcastIsActive != null) {
            boolean is_active = false;
            try {
                is_active = (boolean)mBroadcastIsActive.invoke(mBroadcastService);
            } catch(IllegalAccessException e) {
                Log.e(TAG, "Broadcast:IsActive IllegalAccessException");
            } catch (InvocationTargetException e) {
                Log.e(TAG, "Broadcast:IsActive InvocationTargetException");
            }
            return is_active;
        }
        return false;
    }
    /**
     * Check whether Wipower Fastboot enabled.
     *
     * @return true if Wipower fastboot is enabled
     */
    public boolean isWipowerFastbootEnabled() {
        return mAdapterProperties.isWipowerFastbootEnabled();
    }

    /**
     * Check whether Split A2DP Scramble Data Required
     *
     * @return true if Split A2DP Scramble Data Required is enabled
     */
    public boolean isSplitA2DPScrambleDataRequired() {
        return mAdapterProperties.isSplitA2DPScrambleDataRequired();
    }

    /**
     * Check whether Split A2DP 44.1Khz Sample Freq enabled.
     *
     * @return true if Split A2DP 44.1Khz Sample Freq is enabled
     */
    public boolean isSplitA2DP44p1KhzSampleFreq() {

        return mAdapterProperties.isSplitA2DP44p1KhzSampleFreq();
    }

    /**
     * Check whether Split A2DP 48Khz Sample Freq enabled.
     *
     * @return true if  Split A2DP 48Khz Sample Freq is enabled
     */
    public boolean isSplitA2DP48KhzSampleFreq() {

        return mAdapterProperties.isSplitA2DP48KhzSampleFreq();
    }

    /**
     * Check whether Split A2DP Single VS Command Support enabled.
     *
     * @return true if Split A2DP Single VSCommand Support is enabled
     */
    public boolean isSplitA2DPSingleVSCommandSupport() {
        return mAdapterProperties.isSplitA2DPSingleVSCommandSupport();
    }

    /**
     * Check whether Split A2DP Source SBC Encoding enabled.
     *
     * @return true if Split A2DP Source SBC Encoding is enabled
     */
    public boolean isSplitA2DPSourceSBCEncoding() {
        return mAdapterProperties.isSplitA2DPSourceSBCEncoding();
    }

    /**
     * Check whether Split A2DP Source SBC  enabled.
     *
     * @return true if Split A2DP Source SBC  is enabled
     */
    public boolean isSplitA2DPSourceSBC() {
        return mAdapterProperties.isSplitA2DPSourceSBC();
    }

    /**
     * Check whether Split A2DP Source MP3  enabled.
     *
     * @return true if Split A2DP Source MP3  is enabled
     */
    public boolean isSplitA2DPSourceMP3() {
        return mAdapterProperties.isSplitA2DPSourceMP3();
    }

    /**
     * Check whether Split A2DP Source AAC  enabled.
     *
     * @return true if Split A2DP Source AAC  is enabled
     */
    public boolean isSplitA2DPSourceAAC() {
        return mAdapterProperties.isSplitA2DPSourceAAC();
    }

    /**
     * Check whether Split A2DP Source LDAC  enabled.
     *
     * @return true if Split A2DP Source LDAC  is enabled
     */
    public boolean isSplitA2DPSourceLDAC() {
        String BT_SOC = getSocName();
        return (!mAdapterProperties.isAddonFeaturesCmdSupported() && BT_SOC.equals("cherokee")) ||
            mAdapterProperties.isSplitA2DPSourceLDAC();
    }

    /**
     * Check whether Split A2DP Source APTX  enabled.
     *
     * @return true if Split A2DP Source APTX  is enabled
     */
    public boolean isSplitA2DPSourceAPTX() {
        return mAdapterProperties.isSplitA2DPSourceAPTX();
    }

    /**
     * Check whether Split A2DP Source APTX HD  enabled.
     *
     * @return true if Split A2DP Source APTX HD  is enabled
     */
    public boolean isSplitA2DPSourceAPTXHD() {
        String BT_SOC = getSocName();
        return (!mAdapterProperties.isAddonFeaturesCmdSupported() && BT_SOC.equals("cherokee")) ||
            mAdapterProperties.isSplitA2DPSourceAPTXHD();
    }

    /**
     * Check whether Split A2DP Source APTX ADAPTIVE  enabled.
     *
     * @return true if Split A2DP Source APTX ADAPTIVE  is enabled
     */
    public boolean isSplitA2DPSourceAPTXADAPTIVE() {
        String BT_SOC = getSocName();
        return (!mAdapterProperties.isAddonFeaturesCmdSupported() && BT_SOC.equals("cherokee")) ||
            mAdapterProperties.isSplitA2DPSourceAPTXADAPTIVE();
    }

    /**
     * Check whether Split A2DP Source APTX TWS+  enabled.
     *
     * @return true if Split A2DP Source APTX TWS+  is enabled
     */
    public boolean isSplitA2DPSourceAPTXTWSPLUS() {
        return mAdapterProperties.isSplitA2DPSourceAPTXTWSPLUS();
    }

    /**
     * Check whether Split A2DP Sink SBC  enabled.
     *
     * @return true if Split A2DP Sink SBC  is enabled
     */
    public boolean isSplitA2DPSinkSBC() {
        return mAdapterProperties.isSplitA2DPSinkSBC();
    }

    /**
     * Check whether Split A2DP Sink MP3  enabled.
     *
     * @return true if Split A2DP Sink MP3  is enabled
     */
    public boolean isSplitA2DPSinkMP3() {
        return mAdapterProperties.isSplitA2DPSinkMP3();
    }

    /**
     * Check whether Split A2DP Sink AAC  enabled.
     *
     * @return true if Split A2DP Sink AAC  is enabled
     */
    public boolean isSplitA2DPSinkAAC() {
        return mAdapterProperties.isSplitA2DPSinkAAC();
    }

    /**
     * Check whether Split A2DP Sink LDAC  enabled.
     *
     * @return true if Split A2DP Sink LDAC  is enabled
     */
    public boolean isSplitA2DPSinkLDAC() {
        return mAdapterProperties.isSplitA2DPSinkLDAC();
    }

    /**
     * Check whether Split A2DP Sink APTX  enabled.
     *
     * @return true if Split A2DP Sink APTX  is enabled
     */
    public boolean isSplitA2DPSinkAPTX() {
        return mAdapterProperties.isSplitA2DPSinkAPTX();
    }

    /**
     * Check whether Split A2DP Sink APTX HD  enabled.
     *
     * @return true if Split A2DP Sink APTX HD  is enabled
     */
    public boolean isSplitA2DPSinkAPTXHD() {
        return mAdapterProperties.isSplitA2DPSinkAPTXHD();
    }

    /**
     * Check whether Split A2DP Sink APTX ADAPTIVE  enabled.
     *
     * @return true if Split A2DP Sink APTX ADAPTIVE  is enabled
     */
    public boolean isSplitA2DPSinkAPTXADAPTIVE() {
        return mAdapterProperties.isSplitA2DPSinkAPTXADAPTIVE();
    }

    /**
     * Check whether Split A2DP Sink APTX TWS+  enabled.
     *
     * @return true if Split A2DP Sink APTX TWS+  is enabled
     */
    public boolean isSplitA2DPSinkAPTXTWSPLUS() {
        return mAdapterProperties.isSplitA2DPSinkAPTXTWSPLUS();
    }

    /**
     * Check whether Voice Dual SCO  enabled.
     *
     * @return true if Voice Dual SCO is enabled
     */
    public boolean isVoiceDualSCO() {
        return mAdapterProperties.isVoiceDualSCO();
    }

    /**
     * Check whether Voice TWS+ eSCO AG enabled.
     *
     * @return true if Voice TWS+ eSCO AG  is enabled
     */
    public boolean isVoiceTWSPLUSeSCOAG() {
        return mAdapterProperties.isVoiceTWSPLUSeSCOAG();
    }

    /**
     * Check whether SWB Voice with Aptx Adaptive AG  enabled.
     *
     * @return true if SWB Voice with Aptx Adaptive AG  is enabled
     */
    public boolean isSWBVoicewithAptxAdaptiveAG() {
        return mAdapterProperties.isSWBVoicewithAptxAdaptiveAG();
    }

    /**
     * Check whether Split A2DP Source AAC ABR enabled.
     *
     * @return true if Split A2DP Source AAC ABR is enabled
     */
    public boolean isSplitA2DPSourceAACABR() {
        return mAdapterProperties.isSplitA2DPSourceAACABR();
    }

    /**
     * Check whether Split A2DP Source Tx-Split APTX ADAPTIVE enabled.
     *
     * @return true if Split A2DP Source Tx-Split APTX ADAPTIVE is enabled
     */
    public boolean isSplitA2DPSourceTxSplitAPTXADAPTIVE() {
        return mAdapterProperties.isSplitA2DPSourceTxSplitAPTXADAPTIVE();
    }

    /**
     * Check whether Broadcast Audio Tx with EC-2:5 enabled.
     *
     * @return true if Broadcast Audio Tx with EC-2:5 is enabled
     */
    public boolean isBroadcastAudioTxwithEC_2_5() {
        return mAdapterProperties.isBroadcastAudioTxwithEC_2_5();
    }

    /**
     * Check whether Broadcast Audio Tx with EC_3:9 enabled.
     *
     * @return true if Broadcast Audio Tx with EC_3:9 is enabled
     */
    public boolean isBroadcastAudioTxwithEC_3_9() {
        return mAdapterProperties.isBroadcastAudioTxwithEC_3_9();
    }

    /**
     * Check whether Broadcast Audio Rx with EC_2:5 enabled.
     *
     * @return true if Broadcast Audio Rx with EC_2:5 is enabled
     */
    public boolean isBroadcastAudioRxwithEC_2_5() {
        return mAdapterProperties.isBroadcastAudioRxwithEC_2_5();
    }

    /**
     * Check whether Broadcast Audio Rx with EC_3:9 enabled.
     *
     * @return true if Broadcast Audio Rx with EC_3:9 is enabled
     */
    public boolean isBroadcastAudioRxwithEC_3_9() {
        return mAdapterProperties.isBroadcastAudioRxwithEC_3_9();
    }

    /**
     * Check  AddonFeatures Cmd Support.
     *
     * @return true if AddonFeatures Cmd is Supported
     */
    public boolean isAddonFeaturesCmdSupported() {
        return mAdapterProperties.isAddonFeaturesCmdSupported();
    }

    public boolean isAdvUnicastAudioFeatEnabled() {
        return (Config.adv_audio_feature_mask & Config.ADV_AUDIO_UNICAST_FEAT_MASK) != 0;
    }

    public boolean isAdvBCAAudioFeatEnabled() {
        return (Config.adv_audio_feature_mask & Config.ADV_AUDIO_BCA_FEAT_MASK) != 0;
    }

    public boolean isAdvBCSAudioFeatEnabled() {
        return (Config.adv_audio_feature_mask & Config.ADV_AUDIO_BCS_FEAT_MASK) != 0;
    }


    /**
     * Check  Host Adv Audio Unicast feature support.
     *
     * @return true if Host Adv Audio Unicast feature supported
     */
    public boolean isHostAdvAudioUnicastFeatureSupported() {
        return mAdapterProperties.isHostAdvAudioUnicastFeatureSupported();
    }

    /**
     * Check  Host Adv Audio BCA feature support.
     *
     * @return true if Host Adv Audio BCA feature supported
     */
    public boolean isHostAdvAudioBCAFeatureSupported() {
        return mAdapterProperties.isHostAdvAudioBCAFeatureSupported();
    }

    /**
     * Check  Host Adv Audio BCS feature support.
     *
     * @return true if Host Adv Audio BCS feature supported
     */
    public boolean isHostAdvAudioBCSFeatureSupported() {
        return mAdapterProperties.isHostAdvAudioBCSFeatureSupported();
    }

    /**
     * Check  Host Adv Audio StereoRecording feature support.
     *
     * @return true if Host Adv Audio StereoRecording feature supported
     */
    public boolean isHostAdvAudioStereoRecordingFeatureSupported() {
        return mAdapterProperties.isHostAdvAudioStereoRecordingFeatureSupported();
    }

    /**
     * Check  Host Adv Audio LC3Q feature support.
     *
     * @return true if Host Adv Audio LC3Q feature supported
     */
    public boolean isHostAdvAudioLC3QFeatureSupported() {
        return mAdapterProperties.isHostAdvAudioLC3QFeatureSupported();
    }

    /**
     * Check  Host QHS feature support.
     *
     * @return true if Host QHS feature supported
     */
    public boolean isHostQHSFeatureSupported() {
        return mAdapterProperties.isHostQHSFeatureSupported();
    }

    /**
     * Check  Host AddonFeatures Support.
     *
     * @return true if Host AddonFeatures supported
     */
    public boolean isHostAddonFeaturesSupported() {
        return mAdapterProperties.isHostAddonFeaturesSupported();
    }

    private BluetoothActivityEnergyInfo reportActivityInfo() {
        if (mAdapterProperties.getState() != BluetoothAdapter.STATE_ON
                || !mAdapterProperties.isActivityAndEnergyReportingSupported()) {
            return null;
        }

        // Pull the data. The callback will notify mEnergyInfoLock.
        readEnergyInfo();

        synchronized (mEnergyInfoLock) {
            try {
                mEnergyInfoLock.wait(CONTROLLER_ENERGY_UPDATE_TIMEOUT_MILLIS);
            } catch (InterruptedException e) {
                // Just continue, the energy data may be stale but we won't miss anything next time
                // we query.
            }

            final BluetoothActivityEnergyInfo info =
                    new BluetoothActivityEnergyInfo(SystemClock.elapsedRealtime(),
                            mStackReportedState, mTxTimeTotalMs, mRxTimeTotalMs, mIdleTimeTotalMs,
                            mEnergyUsedTotalVoltAmpSecMicro);

            // Count the number of entries that have byte counts > 0
            int arrayLen = 0;
            for (int i = 0; i < mUidTraffic.size(); i++) {
                final UidTraffic traffic = mUidTraffic.valueAt(i);
                if (traffic.getTxBytes() != 0 || traffic.getRxBytes() != 0) {
                    arrayLen++;
                }
            }

            // Copy the traffic objects whose byte counts are > 0
            final UidTraffic[] result = arrayLen > 0 ? new UidTraffic[arrayLen] : null;
            int putIdx = 0;
            for (int i = 0; i < mUidTraffic.size(); i++) {
                final UidTraffic traffic = mUidTraffic.valueAt(i);
                if (traffic.getTxBytes() != 0 || traffic.getRxBytes() != 0) {
                    result[putIdx++] = traffic.clone();
                }
            }

            info.setUidTraffic(result);

            return info;
        }
    }

    public int getTotalNumOfTrackableAdvertisements() {
        return mAdapterProperties.getTotalNumOfTrackableAdvertisements();
    }

    void updateQuietModeStatus(boolean quietMode) {
        debugLog("updateQuietModeStatus()-updateQuietModeStatus called with quiet mode status:"
                   + quietMode);
        mQuietmode = quietMode;
    }

    void onLeServiceUp() {
        mAdapterStateMachine.sendMessage(AdapterState.USER_TURN_ON);
    }

    void onBrEdrDown() {
        mAdapterStateMachine.sendMessage(AdapterState.BLE_TURN_OFF);
    }

    int setSocketOpt(int type, int channel, int optionName, byte [] optionVal,
             int optionLen) {
        return mVendorSocket.setSocketOpt(type, channel, optionName, optionVal, optionLen);
    }

    int getSocketOpt(int type, int channel, int optionName, byte [] optionVal) {
        return mVendorSocket.getSocketOpt(type, channel, optionName, optionVal);
    }

    private static int convertScanModeToHal(int mode) {
        switch (mode) {
            case BluetoothAdapter.SCAN_MODE_NONE:
                return AbstractionLayer.BT_SCAN_MODE_NONE;
            case BluetoothAdapter.SCAN_MODE_CONNECTABLE:
                return AbstractionLayer.BT_SCAN_MODE_CONNECTABLE;
            case BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE:
                return AbstractionLayer.BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE;
        }
        // errorLog("Incorrect scan mode in convertScanModeToHal");
        return -1;
    }

    static int convertScanModeFromHal(int mode) {
        switch (mode) {
            case AbstractionLayer.BT_SCAN_MODE_NONE:
                return BluetoothAdapter.SCAN_MODE_NONE;
            case AbstractionLayer.BT_SCAN_MODE_CONNECTABLE:
                return BluetoothAdapter.SCAN_MODE_CONNECTABLE;
            case AbstractionLayer.BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE:
                return BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE;
        }
        //errorLog("Incorrect scan mode in convertScanModeFromHal");
        return -1;
    }

    // This function is called from JNI. It allows native code to set a single wake
    // alarm. If an alarm is already pending and a new request comes in, the alarm
    // will be rescheduled (i.e. the previously set alarm will be cancelled).
    private boolean setWakeAlarm(long delayMillis, boolean shouldWake) {
        synchronized (this) {
            if (mPendingAlarm != null) {
                mAlarmManager.cancel(mPendingAlarm);
            }

            long wakeupTime = SystemClock.elapsedRealtime() + delayMillis;
            int type = shouldWake ? AlarmManager.ELAPSED_REALTIME_WAKEUP
                    : AlarmManager.ELAPSED_REALTIME;

            Intent intent = new Intent(ACTION_ALARM_WAKEUP);
            mPendingAlarm =
                    PendingIntent.getBroadcast(this, 0, intent, PendingIntent.FLAG_ONE_SHOT
                            | PendingIntent.FLAG_IMMUTABLE);
            mAlarmManager.setExact(type, wakeupTime, mPendingAlarm);
            return true;
        }
    }

    // This function is called from JNI. It allows native code to acquire a single wake lock.
    // If the wake lock is already held, this function returns success. Although this function
    // only supports acquiring a single wake lock at a time right now, it will eventually be
    // extended to allow acquiring an arbitrary number of wake locks. The current interface
    // takes |lockName| as a parameter in anticipation of that implementation.
    private boolean acquireWakeLock(String lockName) {
        synchronized (this) {
            if (mWakeLock == null) {
                mWakeLockName = lockName;
                mWakeLock = mPowerManager.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, lockName);
            }

            if (!mWakeLock.isHeld()) {
                mWakeLock.acquire();
            }
        }
        return true;
    }

    // This function is called from JNI. It allows native code to release a wake lock acquired
    // by |acquireWakeLock|. If the wake lock is not held, this function returns failure.
    // Note that the release() call is also invoked by {@link #cleanup()} so a synchronization is
    // needed here. See the comment for |acquireWakeLock| for an explanation of the interface.
    private boolean releaseWakeLock(String lockName) {
        synchronized (this) {
            if (mWakeLock == null) {
                errorLog("Repeated wake lock release; aborting release: " + lockName);
                return false;
            }

            if (mWakeLock.isHeld()) {
                mWakeLock.release();
            }
        }
        return true;
    }

    private void energyInfoCallback(int status, int ctrlState, long txTime, long rxTime,
            long idleTime, long energyUsed, UidTraffic[] data) throws RemoteException {
        if (ctrlState >= BluetoothActivityEnergyInfo.BT_STACK_STATE_INVALID
                && ctrlState <= BluetoothActivityEnergyInfo.BT_STACK_STATE_STATE_IDLE) {
            // Energy is product of mA, V and ms. If the chipset doesn't
            // report it, we have to compute it from time
            if (energyUsed == 0) {
                try {
                    final long txMah = Math.multiplyExact(txTime, getTxCurrentMa());
                    final long rxMah = Math.multiplyExact(rxTime, getRxCurrentMa());
                    final long idleMah = Math.multiplyExact(idleTime, getIdleCurrentMa());
                    energyUsed = (long) (Math.addExact(Math.addExact(txMah, rxMah), idleMah)
                            * getOperatingVolt());
                } catch (ArithmeticException e) {
                    Log.wtf(TAG, "overflow in bluetooth energy callback", e);
                    // Energy is already 0 if the exception was thrown.
                }
            }

            synchronized (mEnergyInfoLock) {
                mStackReportedState = ctrlState;
                long totalTxTimeMs;
                long totalRxTimeMs;
                long totalIdleTimeMs;
                long totalEnergy;
                try {
                    totalTxTimeMs = Math.addExact(mTxTimeTotalMs, txTime);
                    totalRxTimeMs = Math.addExact(mRxTimeTotalMs, rxTime);
                    totalIdleTimeMs = Math.addExact(mIdleTimeTotalMs, idleTime);
                    totalEnergy = Math.addExact(mEnergyUsedTotalVoltAmpSecMicro, energyUsed);
                } catch (ArithmeticException e) {
                    // This could be because we accumulated a lot of time, or we got a very strange
                    // value from the controller (more likely). Discard this data.
                    Log.wtf(TAG, "overflow in bluetooth energy callback", e);
                    totalTxTimeMs = mTxTimeTotalMs;
                    totalRxTimeMs = mRxTimeTotalMs;
                    totalIdleTimeMs = mIdleTimeTotalMs;
                    totalEnergy = mEnergyUsedTotalVoltAmpSecMicro;
                }

                mTxTimeTotalMs = totalTxTimeMs;
                mRxTimeTotalMs = totalRxTimeMs;
                mIdleTimeTotalMs = totalIdleTimeMs;
                mEnergyUsedTotalVoltAmpSecMicro = totalEnergy;

                for (UidTraffic traffic : data) {
                    UidTraffic existingTraffic = mUidTraffic.get(traffic.getUid());
                    if (existingTraffic == null) {
                        mUidTraffic.put(traffic.getUid(), traffic);
                    } else {
                        existingTraffic.addRxBytes(traffic.getRxBytes());
                        existingTraffic.addTxBytes(traffic.getTxBytes());
                    }
                }
                mEnergyInfoLock.notifyAll();
            }
        }

        verboseLog("energyInfoCallback() status = " + status + "txTime = " + txTime + "rxTime = "
                + rxTime + "idleTime = " + idleTime + "energyUsed = " + energyUsed + "ctrlState = "
                + ctrlState + "traffic = " + Arrays.toString(data));
    }

    /**
     * Update metadata change to registered listeners
     */
    @VisibleForTesting
    public void metadataChanged(String address, int key, byte[] value) {
        BluetoothDevice device = mRemoteDevices.getDevice(Utils.getBytesFromAddress(address));
        if (mMetadataListeners.containsKey(device)) {
            ArrayList<IBluetoothMetadataListener> list = mMetadataListeners.get(device);
            for (IBluetoothMetadataListener listener : list) {
                try {
                    listener.onMetadataChanged(device, key, value);
                } catch (RemoteException e) {
                    Log.w(TAG, "RemoteException when onMetadataChanged");
                }
            }
        }
    }

    public ActiveDeviceManager getActiveDeviceManager() {
        return mActiveDeviceManager;
    }
    private int getIdleCurrentMa() {
        return getResources().getInteger(R.integer.config_bluetooth_idle_cur_ma);
    }

    private int getTxCurrentMa() {
        return getResources().getInteger(R.integer.config_bluetooth_tx_cur_ma);
    }

    private int getRxCurrentMa() {
        return getResources().getInteger(R.integer.config_bluetooth_rx_cur_ma);
    }

    private double getOperatingVolt() {
        return getResources().getInteger(R.integer.config_bluetooth_operating_voltage_mv) / 1000.0;
    }

    @Override
    protected void dump(FileDescriptor fd, PrintWriter writer, String[] args) {
        if (args.length == 0) {
            writer.println("Skipping dump in APP SERVICES, see bluetooth_manager section.");
            writer.println("Use --print argument for dumpsys direct from AdapterService.");
            return;
        }

        if ("set-test-mode".equals(args[0])) {
            final boolean testModeEnabled = "enabled".equalsIgnoreCase(args[1]);
            for (ProfileService profile : mRunningProfiles) {
                profile.setTestModeEnabled(testModeEnabled);
            }
            mTestModeEnabled = testModeEnabled;
            return;
        }
        verboseLog("dumpsys arguments, check for protobuf output: " + TextUtils.join(" ", args));
        if (args[0].equals("--proto-bin")) {
            dumpMetrics(fd);
            return;
        }

        writer.println();
        mAdapterProperties.dump(fd, writer, args);
        writer.println("mSnoopLogSettingAtEnable = " + mSnoopLogSettingAtEnable);
        writer.println("mDefaultSnoopLogSettingAtEnable = " + mDefaultSnoopLogSettingAtEnable);

        writer.println();
        mAdapterStateMachine.dump(fd, writer, args);

        StringBuilder sb = new StringBuilder();
        for (ProfileService profile : mRegisteredProfiles) {
            profile.dump(sb);
        }
        mSilenceDeviceManager.dump(fd, writer, args);

        writer.write(sb.toString());
        writer.flush();

        dumpNative(fd, args);
    }

    private void dumpMetrics(FileDescriptor fd) {
        BluetoothMetricsProto.BluetoothLog.Builder metricsBuilder =
                BluetoothMetricsProto.BluetoothLog.newBuilder();
        byte[] nativeMetricsBytes = dumpMetricsNative();
        debugLog("dumpMetrics: native metrics size is " + nativeMetricsBytes.length);
        if (nativeMetricsBytes.length > 0) {
            try {
                metricsBuilder.mergeFrom(nativeMetricsBytes);
            } catch (InvalidProtocolBufferException ex) {
                Log.w(TAG, "dumpMetrics: problem parsing metrics protobuf, " + ex.getMessage());
                return;
            }
        }
        metricsBuilder.setNumBondedDevices(getBondedDevices().length);
        MetricsLogger.dumpProto(metricsBuilder);
        for (ProfileService profile : mRegisteredProfiles) {
            profile.dumpProto(metricsBuilder);
        }
        byte[] metricsBytes = Base64.encode(metricsBuilder.build().toByteArray(), Base64.DEFAULT);
        debugLog("dumpMetrics: combined metrics size is " + metricsBytes.length);
        try (FileOutputStream protoOut = new FileOutputStream(fd)) {
            protoOut.write(metricsBytes);
        } catch (IOException e) {
            errorLog("dumpMetrics: error writing combined protobuf to fd, " + e.getMessage());
        }
    }

    private void debugLog(String msg) {
        if (DBG) {
            Log.d(TAG, msg);
        }
    }

    private void verboseLog(String msg) {
        if (VERBOSE) {
            Log.v(TAG, msg);
        }
    }

    private void errorLog(String msg) {
        Log.e(TAG, msg);
    }

    private final BroadcastReceiver mAlarmBroadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            synchronized (AdapterService.this) {
                mPendingAlarm = null;
                alarmFiredNative();
            }
        }
    };

    private final BroadcastReceiver mWifiStateBroadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = (intent != null) ? intent.getAction():null;
            debugLog(action);
            if (action == null) return;
            if (isEnabled() && (action.equals(WifiManager.NETWORK_STATE_CHANGED_ACTION))) {
                fetchWifiState();
             } else if (isEnabled() &&
                        (action.equals(WifiManager.WIFI_STATE_CHANGED_ACTION) ||
                        (action.equals(WifiManager.WIFI_AP_STATE_CHANGED_ACTION)))){
                 if (isPowerbackRequired()) {
                     mVendor.setPowerBackoff(true);
                 } else {
                     mVendor.setPowerBackoff(false);
                 }
             }
         }
    };

    private boolean isGuest() {
        return UserManager.get(this).isGuestUser();
    }

    private boolean isCommonCriteriaMode() {
        return ((DevicePolicyManager) getSystemService(Context.DEVICE_POLICY_SERVICE))
                .isCommonCriteriaModeEnabled(null);
    }

    @SuppressLint("AndroidFrameworkRequiresPermission")
    private void enforceBluetoothPrivilegedPermissionIfNeeded(OobData remoteP192Data,
            OobData remoteP256Data) {
        if (remoteP192Data != null || remoteP256Data != null) {
            enforceBluetoothPrivilegedPermission(this);
        }
    }

    private static final String GD_CORE_FLAG = "INIT_gd_core";
    private static final String GD_ADVERTISING_FLAG = "INIT_gd_advertising";
    private static final String GD_HCI_FLAG = "INIT_gd_hci";
    private static final String GD_CONTROLLER_FLAG = "INIT_gd_controller";
    private static final String GD_ACL_FLAG = "INIT_gd_acl";
    /**
     * Logging flags logic (only applies to DEBUG and VERBOSE levels):
     * if LOG_TAG in LOGGING_DEBUG_DISABLED_FOR_TAGS_FLAG:
     *   DO NOT LOG
     * else if LOG_TAG in LOGGING_DEBUG_ENABLED_FOR_TAGS_FLAG:
     *   DO LOG
     * else if LOGGING_DEBUG_ENABLED_FOR_ALL_FLAG:
     *   DO LOG
     * else:
     *   DO NOT LOG
     */
    private static final String LOGGING_DEBUG_ENABLED_FOR_ALL_FLAG =
            "INIT_logging_debug_enabled_for_all";
    // String flags
    // Comma separated tags
    private static final String LOGGING_DEBUG_ENABLED_FOR_TAGS_FLAG =
            "INIT_logging_debug_enabled_for_tags";
    private static final String LOGGING_DEBUG_DISABLED_FOR_TAGS_FLAG =
            "INIT_logging_debug_disabled_for_tags";
    private static final String BTAA_HCI_LOG_FLAG = "INIT_btaa_hci";

    private String[] getInitFlags() {
        ArrayList<String> initFlags = new ArrayList<>();
        if (DeviceConfig.getBoolean(DeviceConfig.NAMESPACE_BLUETOOTH, GD_CORE_FLAG, false)) {
            initFlags.add(GD_CORE_FLAG);
        }
        return initFlags.toArray(new String[0]);
    }

    private final Object mDeviceConfigLock = new Object();

    /**
     * Predicate that can be applied to names to determine if a device is
     * well-known to be used for physical location.
     */
    @GuardedBy("mDeviceConfigLock")
    private Predicate<String> mLocationDenylistName = (v) -> false;

    /**
     * Predicate that can be applied to MAC addresses to determine if a device
     * is well-known to be used for physical location.
     */
    @GuardedBy("mDeviceConfigLock")
    private Predicate<byte[]> mLocationDenylistMac = (v) -> false;

    /**
     * Predicate that can be applied to Advertising Data payloads to determine
     * if a device is well-known to be used for physical location.
     */
    @GuardedBy("mDeviceConfigLock")
    private Predicate<byte[]> mLocationDenylistAdvertisingData = (v) -> false;

    @GuardedBy("mDeviceConfigLock")
    private int mScanQuotaCount = DeviceConfigListener.DEFAULT_SCAN_QUOTA_COUNT;
    @GuardedBy("mDeviceConfigLock")
    private long mScanQuotaWindowMillis = DeviceConfigListener.DEFAULT_SCAN_QUOTA_WINDOW_MILLIS;
    @GuardedBy("mDeviceConfigLock")
    private long mScanTimeoutMillis = DeviceConfigListener.DEFAULT_SCAN_TIMEOUT_MILLIS;

    public @NonNull Predicate<String> getLocationDenylistName() {
        synchronized (mDeviceConfigLock) {
            return mLocationDenylistName;
        }
    }

    public @NonNull Predicate<byte[]> getLocationDenylistMac() {
        synchronized (mDeviceConfigLock) {
            return mLocationDenylistMac;
        }
    }

    public @NonNull Predicate<byte[]> getLocationDenylistAdvertisingData() {
        synchronized (mDeviceConfigLock) {
            return mLocationDenylistAdvertisingData;
        }
    }

    public int getScanQuotaCount() {
        synchronized (mDeviceConfigLock) {
            return mScanQuotaCount;
        }
    }

    public long getScanQuotaWindowMillis() {
        synchronized (mDeviceConfigLock) {
            return mScanQuotaWindowMillis;
        }
    }

    public long getScanTimeoutMillis() {
        synchronized (mDeviceConfigLock) {
            return mScanTimeoutMillis;
        }
    }

    private final DeviceConfigListener mDeviceConfigListener = new DeviceConfigListener();

    private class DeviceConfigListener implements DeviceConfig.OnPropertiesChangedListener {
        private static final String LOCATION_DENYLIST_NAME =
                "location_denylist_name";
        private static final String LOCATION_DENYLIST_MAC =
                "location_denylist_mac";
        private static final String LOCATION_DENYLIST_ADVERTISING_DATA =
                "location_denylist_advertising_data";
        private static final String SCAN_QUOTA_COUNT =
                "scan_quota_count";
        private static final String SCAN_QUOTA_WINDOW_MILLIS =
                "scan_quota_window_millis";
        private static final String SCAN_TIMEOUT_MILLIS =
                "scan_timeout_millis";

        /**
         * Default denylist which matches Eddystone and iBeacon payloads.
         */
        private static final String DEFAULT_LOCATION_DENYLIST_ADVERTISING_DATA =
                "⊆0016AAFE/00FFFFFF,⊆00FF4C0002/00FFFFFFFF";

        private static final int DEFAULT_SCAN_QUOTA_COUNT = 5;
        private static final long DEFAULT_SCAN_QUOTA_WINDOW_MILLIS = 30 * SECOND_IN_MILLIS;
        private static final long DEFAULT_SCAN_TIMEOUT_MILLIS = 30 * MINUTE_IN_MILLIS;

        public void start() {
            DeviceConfig.addOnPropertiesChangedListener(DeviceConfig.NAMESPACE_BLUETOOTH,
                    BackgroundThread.getExecutor(), this);
            onPropertiesChanged(DeviceConfig.getProperties(DeviceConfig.NAMESPACE_BLUETOOTH));
        }

        @Override
        public void onPropertiesChanged(DeviceConfig.Properties properties) {
            synchronized (mDeviceConfigLock) {
                final String name = properties.getString(LOCATION_DENYLIST_NAME, null);
                mLocationDenylistName = !TextUtils.isEmpty(name)
                        ? Pattern.compile(name).asPredicate()
                        : (v) -> false;
                mLocationDenylistMac = BytesMatcher
                        .decode(properties.getString(LOCATION_DENYLIST_MAC, null));
                mLocationDenylistAdvertisingData = BytesMatcher
                        .decode(properties.getString(LOCATION_DENYLIST_ADVERTISING_DATA,
                                DEFAULT_LOCATION_DENYLIST_ADVERTISING_DATA));
                mScanQuotaCount = properties.getInt(SCAN_QUOTA_COUNT,
                        DEFAULT_SCAN_QUOTA_COUNT);
                mScanQuotaWindowMillis = properties.getLong(SCAN_QUOTA_WINDOW_MILLIS,
                        DEFAULT_SCAN_QUOTA_WINDOW_MILLIS);
                mScanTimeoutMillis = properties.getLong(SCAN_TIMEOUT_MILLIS,
                        DEFAULT_SCAN_TIMEOUT_MILLIS);
            }
        }
    }
    /**
     *  Obfuscate Bluetooth MAC address into a PII free ID string
     *
     *  @param device Bluetooth device whose MAC address will be obfuscated
     *  @return a byte array that is unique to this MAC address on this device,
     *          or empty byte array when either device is null or obfuscateAddressNative fails
     */
    public byte[] obfuscateAddress(BluetoothDevice device) {
         if (device == null) {
           return new byte[0];
         }
         return obfuscateAddressNative(Utils.getByteAddress(device));
    }

    private boolean isPowerbackRequired() {

        try {

            WifiManager mWifiManager = (WifiManager)getSystemService(Context.WIFI_SERVICE);
            final SoftApConfiguration config = mWifiManager.getSoftApConfiguration();

            if (config != null)
                    Log.d(TAG, "Soft AP is on band: " + config.getBand());

            if ((mWifiManager != null) && ((mWifiManager.isWifiEnabled() ||
                ((mWifiManager.getWifiApState() == WifiManager.WIFI_AP_STATE_ENABLED) &&
                (config != null) &&
                (((config.getBand() & SoftApConfiguration.BAND_5GHZ) != 0) ||
                ((config.getBand() & SoftApConfiguration.BAND_6GHZ) != 0) ||
                ((config.getBand() & SOFT_AP_BAND_DUAL) !=0 )))))) {
                return true;
            }
            return false;
        } catch(SecurityException e) {
            debugLog(e.toString());
        }
        return false;
    }

    /**
     * Get dynamic audio buffer size supported type
     *
     * @return support <p>Possible values are
     * {@link BluetoothA2dp#DYNAMIC_BUFFER_SUPPORT_NONE},
     * {@link BluetoothA2dp#DYNAMIC_BUFFER_SUPPORT_A2DP_OFFLOAD},
     * {@link BluetoothA2dp#DYNAMIC_BUFFER_SUPPORT_A2DP_SOFTWARE_ENCODING}.
     */
    public int getDynamicBufferSupport() {
        return mAdapterProperties.getDynamicBufferSupport();
    }

    /**
     * Get dynamic audio buffer size
     *
     * @return BufferConstraints
     */
    public BufferConstraints getBufferConstraints() {
        return mAdapterProperties.getBufferConstraints();
    }

    /**
     * Set dynamic audio buffer size
     *
     * @param codec Audio codec
     * @param value buffer millis
     * @return true if the settings is successful, false otherwise
     */
    public boolean setBufferLengthMillis(int codec, int value) {
        return mAdapterProperties.setBufferLengthMillis(codec, value);
    }


    boolean isSdpCompleted(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        boolean sdpCompleted = deviceProp.isSdpCompleted();
        debugLog("sdpCompleted  "  + sdpCompleted);
        return sdpCompleted;
    }

    private int getDeviceType(BluetoothDevice device){
        enforceBluetoothPrivilegedPermission(this);
        int type = TYPE_BREDR;
        if (mGroupService == null ) {
            type = TYPE_BREDR;
        } else if (isIgnoreDevice(device)) {
            type  = TYPE_PRIVATE_ADDRESS;
        } else if (isGroupDevice(device)) {
            ArrayList<Object> args = new ArrayList<Object>(
                    Arrays.asList(device, new ParcelUuid(EMPTY_UUID)));
            type = (Integer)(new ReflectionUtils().invokeMethod(
                    mGroupService, "getRemoteDeviceGroupId", args));
            if (type > GROUP_ID_END ) {
                Log.e(TAG, "getDeviceType set id invalid " + type);
            }
        } else if (!isSdpCompleted(device)) {
            type = -1;
        }
        debugLog("getDeviceType device" + device + " name " + device.getName() + " type " + type);
        return type;
    }

    static native void classInitNative();

    native boolean initNative(boolean startRestricted, boolean isCommonCriteriaMode,
            int configCompareResult, boolean isAtvDevice,
            String[] initFlags);

    native void cleanupNative();

    /*package*/
    native boolean enableNative();

    /*package*/
    native boolean disableNative();

    /*package*/
    native boolean setAdapterPropertyNative(int type, byte[] val);

    /*package*/
    native boolean getAdapterPropertiesNative();

    /*package*/
    native boolean getAdapterPropertyNative(int type);

    /*package*/
    native boolean setAdapterPropertyNative(int type);

    /*package*/
    native boolean setDevicePropertyNative(byte[] address, int type, byte[] val);

    /*package*/
    native boolean getDevicePropertyNative(byte[] address, int type);

    /*package*/
    public native boolean createBondNative(byte[] address, int transport);

    /*package*/
    native boolean createBondOutOfBandNative(byte[] address, int transport,
            OobData p192Data, OobData p256Data);

    /*package*/
    public native boolean removeBondNative(byte[] address);

    /*package*/
    native boolean cancelBondNative(byte[] address);

    /*package*/
    native void generateLocalOobDataNative(int transport);

    /*package*/
    native boolean sdpSearchNative(byte[] address, byte[] uuid);

    /*package*/
    native int getConnectionStateNative(byte[] address);

    private native boolean startDiscoveryNative();

    private native boolean cancelDiscoveryNative();

    private native boolean pinReplyNative(byte[] address, boolean accept, int len, byte[] pin);

    private native boolean sspReplyNative(byte[] address, int type, boolean accept, int passkey);

    /*package*/
    native boolean getRemoteServicesNative(byte[] address);

    /*package*/
    native boolean getRemoteMasInstancesNative(byte[] address);

    private native int readEnergyInfo();

    private native IBinder getSocketManagerNative();

    private native void setSystemUiUidNative(int systemUiUid);

    private static native void setForegroundUserIdNative(int foregroundUserId);

    /*package*/
    native boolean factoryResetNative();

    private native void alarmFiredNative();

    private native void dumpNative(FileDescriptor fd, String[] arguments);

    private native byte[] dumpMetricsNative();

    private native void interopDatabaseClearNative();

    private native void interopDatabaseAddNative(int feature, byte[] address, int length);

    private native byte[] obfuscateAddressNative(byte[] address);

    native boolean setBufferLengthMillisNative(int codec, int value);

    private native int getMetricIdNative(byte[] address);

    /*package*/ native int connectSocketNative(
            byte[] address, int type, byte[] uuid, int port, int flag, int callingUid);

    /*package*/ native int createSocketChannelNative(
            int type, String serviceName, byte[] uuid, int port, int flag, int callingUid);

    /*package*/ native void requestMaximumTxDataLengthNative(byte[] address);

    // Returns if this is a mock object. This is currently used in testing so that we may not call
    // System.exit() while finalizing the object. Otherwise GC of mock objects unfortunately ends up
    // calling finalize() which in turn calls System.exit() and the process crashes.
    //
    // Mock this in your testing framework to return true to avoid the mentioned behavior. In
    // production this has no effect.
    public boolean isMock() {
        return false;
    }

    public void processGroupMember(int groupId, BluetoothDevice device) {
      Log.i(TAG," Processing Group Member " + device +
          " BondState " + device.getBondState());
      DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
      if (deviceProp == null) {
        byte[] addrByte = Utils.getByteAddress(device);
        deviceProp = mRemoteDevices.addDeviceProperties(addrByte);
      }
      if (deviceProp != null) {
          int tempBluetoothClass = BluetoothClass.Service.GROUP |
            deviceProp.getBluetoothClass();
          deviceProp.setBluetoothClass(tempBluetoothClass);
          deviceProp.setBondingInitiatedLocally(true);
          Log.i(TAG," Processing Group Member " + device +
              " tempBluetoothClass " + tempBluetoothClass);
      }
      if (device.getBondState() == BluetoothDevice.BOND_NONE) {
          Message msg =
            mBondStateMachine.obtainMessage(BondStateMachine.ADD_DEVICE_BOND_QUEUE);
          msg.obj = device;
          msg.arg1 = groupId;

          mBondStateMachine.sendMessage(msg);
      }
    }

    public boolean isGroupDevice(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        boolean status = false;

        if (deviceProp == null) return false;
        int groupSupport = deviceProp.getBluetoothClass()
                            & BluetoothClass.Service.GROUP;

        Log.i(TAG," Group SUPPORT VALUE " +groupSupport + " device " +device);
        if (groupSupport == BluetoothClass.Service.GROUP) {
            if (mGroupService == null) return false;
            // Add check for valid groupId- TODO replace null with uuid
            ArrayList<Object> args = new ArrayList<Object>(
                    Arrays.asList(device, new ParcelUuid(EMPTY_UUID)));
            int groupId = (Integer)(new ReflectionUtils().invokeMethod(
                    mGroupService, "getRemoteDeviceGroupId", args));
            Log.i(TAG," group id  " + groupId + " device " + device);
            if (groupId != INVALID_GROUP_ID) {
                status = true;
            }
            if (deviceProp.getValidBDAddr() == 0) {
                Log.i(TAG," ITS PRIVATE ADDR  " + deviceProp.getValidBDAddr()
                        + " device " +device);
                status = false;
            }
        }
        Log.i(TAG," isGroupDevice " + status + "  device name " + device.getName()
                + " addr " + device.getAddress());
        return status;
    }

    public int getGroupId(BluetoothDevice device) {
        if (mGroupService == null) return INVALID_GROUP_ID;
        ArrayList<Object> args = new ArrayList<Object>(
                Arrays.asList(device, new ParcelUuid(EMPTY_UUID)));
        int groupId = (Integer)(new ReflectionUtils().invokeMethod(
                mGroupService, "getRemoteDeviceGroupId", args));
        Log.i(TAG," Group ID " + groupId);
        return groupId;
    }

    public boolean isIgnoreDevice(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        boolean status = false;
        if (deviceProp == null) return false;

        if (deviceProp.getValidBDAddr() == 0) {
                status = true;
        }
        Log.i(TAG," isIgnoreDevice " +status +" device name "+device.getName()+" addr "+device.getAddress());

        return status;
    }

    public BluetoothDevice getIdentityAddress(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) return null;
        BluetoothDevice mappingDevice
            = mRemoteDevices.getDevice(deviceProp.getMappingAddr());
        return mappingDevice;
    }

    public boolean isAdvAudioDevice(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        boolean status = false;
        if (deviceProp == null) return false;
        verboseLog(" isAdvAudioDevice " + device + " getBluetoothClass "
            + deviceProp.getBluetoothClass());

        int leAudioSupport = (deviceProp.getBluetoothClass())
                               & (BluetoothClass.Service.GROUP);

        if ((leAudioSupport == BluetoothClass.Service.GROUP)
            && (deviceProp.getValidBDAddr() != 0)) {
            status = true;
        }
        debugLog(" isAdvAudioDevice " + status);
        return status;
    }

    public boolean isGroupExclAccessSupport(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        boolean status = false;
        if (deviceProp == null) return false;

        ParcelUuid[] uuids = deviceProp.getUuids();
        ParcelUuid GROUP_EXCL_ACCESS_SUPPORT =
            ParcelUuid.fromString("00006AD8-0000-1000-8000-00805F9B34FB");

        if (ArrayUtils.contains(uuids,GROUP_EXCL_ACCESS_SUPPORT)) {
            status = true;
        }
        debugLog("isGroupExclusiveAccess supported  " +status);
        return status;
    }

    public int getTransportForUuid(BluetoothDevice device,
        ParcelUuid uuid) {
        DeviceProperties deviceProp
            = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp != null) {
            return deviceProp.getUuidTransport(uuid);
        }
        return 0;
    }

    public void registerUuidSrvcDisc(ParcelUuid reg_uuid) {
        UUID uuid = reg_uuid.getUuid();
        debugLog(" Registering UUID  " + uuid);

        mVendor.registerUuidSrvcDisc(uuid);
    }

    public static void setAdvanceAudioSupport() {
        if (DBG) {
            Log.d(TAG, " setAdvanceAudioSupport ");
        }
        Method mSetAdvanceAudioSupport = null;

        try {
            Class<?> grpSvcCls = Class.forName(
                    "com.android.bluetooth.groupclient.GroupService");
            if (grpSvcCls != null) {
                mSetAdvanceAudioSupport = grpSvcCls.getMethod(
                    "setAdvanceAudioSupport");
                if (mSetAdvanceAudioSupport != null) {
                    mSetAdvanceAudioSupport.invoke(null);
                }
            }
        } catch (NoSuchMethodException|IllegalAccessException|
                 InvocationTargetException|ClassNotFoundException e) {
             Log.e(TAG, "Exception setAdvanceAudioSupport: " + e);
        }
    }

    int getRemoteClass(BluetoothDevice device) {
        DeviceProperties deviceProp = mRemoteDevices.getDeviceProperties(device);
        if (deviceProp == null) {
            return 0;
        }
        return deviceProp.getBluetoothClass();
    }
}
