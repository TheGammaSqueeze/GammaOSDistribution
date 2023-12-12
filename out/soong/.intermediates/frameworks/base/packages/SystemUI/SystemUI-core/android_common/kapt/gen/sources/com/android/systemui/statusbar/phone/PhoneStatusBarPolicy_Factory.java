package com.android.systemui.statusbar.phone;

import android.app.AlarmManager;
import android.app.IActivityManager;
import android.content.SharedPreferences;
import android.content.res.Resources;
import android.os.UserManager;
import android.telecom.TelecomManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.screenrecord.RecordingController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.policy.BluetoothController;
import com.android.systemui.statusbar.policy.CastController;
import com.android.systemui.statusbar.policy.DataSaverController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.HotspotController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.LocationController;
import com.android.systemui.statusbar.policy.NextAlarmController;
import com.android.systemui.statusbar.policy.RotationLockController;
import com.android.systemui.statusbar.policy.SensorPrivacyController;
import com.android.systemui.statusbar.policy.UserInfoController;
import com.android.systemui.statusbar.policy.ZenModeController;
import com.android.systemui.util.RingerModeTracker;
import com.android.systemui.util.time.DateFormatUtil;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class PhoneStatusBarPolicy_Factory implements Factory<PhoneStatusBarPolicy> {
  private final Provider<StatusBarIconController> iconControllerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<CastController> castControllerProvider;

  private final Provider<HotspotController> hotspotControllerProvider;

  private final Provider<BluetoothController> bluetoothControllerProvider;

  private final Provider<NextAlarmController> nextAlarmControllerProvider;

  private final Provider<UserInfoController> userInfoControllerProvider;

  private final Provider<RotationLockController> rotationLockControllerProvider;

  private final Provider<DataSaverController> dataSaverControllerProvider;

  private final Provider<ZenModeController> zenModeControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<LocationController> locationControllerProvider;

  private final Provider<SensorPrivacyController> sensorPrivacyControllerProvider;

  private final Provider<IActivityManager> iActivityManagerProvider;

  private final Provider<AlarmManager> alarmManagerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<RecordingController> recordingControllerProvider;

  private final Provider<TelecomManager> telecomManagerProvider;

  private final Provider<Integer> displayIdProvider;

  private final Provider<SharedPreferences> sharedPreferencesProvider;

  private final Provider<DateFormatUtil> dateFormatUtilProvider;

  private final Provider<RingerModeTracker> ringerModeTrackerProvider;

  private final Provider<PrivacyItemController> privacyItemControllerProvider;

  private final Provider<PrivacyLogger> privacyLoggerProvider;

  public PhoneStatusBarPolicy_Factory(Provider<StatusBarIconController> iconControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<Resources> resourcesProvider,
      Provider<CastController> castControllerProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<BluetoothController> bluetoothControllerProvider,
      Provider<NextAlarmController> nextAlarmControllerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<RotationLockController> rotationLockControllerProvider,
      Provider<DataSaverController> dataSaverControllerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<SensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<UserManager> userManagerProvider,
      Provider<RecordingController> recordingControllerProvider,
      Provider<TelecomManager> telecomManagerProvider, Provider<Integer> displayIdProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<DateFormatUtil> dateFormatUtilProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<PrivacyLogger> privacyLoggerProvider) {
    this.iconControllerProvider = iconControllerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.resourcesProvider = resourcesProvider;
    this.castControllerProvider = castControllerProvider;
    this.hotspotControllerProvider = hotspotControllerProvider;
    this.bluetoothControllerProvider = bluetoothControllerProvider;
    this.nextAlarmControllerProvider = nextAlarmControllerProvider;
    this.userInfoControllerProvider = userInfoControllerProvider;
    this.rotationLockControllerProvider = rotationLockControllerProvider;
    this.dataSaverControllerProvider = dataSaverControllerProvider;
    this.zenModeControllerProvider = zenModeControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.locationControllerProvider = locationControllerProvider;
    this.sensorPrivacyControllerProvider = sensorPrivacyControllerProvider;
    this.iActivityManagerProvider = iActivityManagerProvider;
    this.alarmManagerProvider = alarmManagerProvider;
    this.userManagerProvider = userManagerProvider;
    this.recordingControllerProvider = recordingControllerProvider;
    this.telecomManagerProvider = telecomManagerProvider;
    this.displayIdProvider = displayIdProvider;
    this.sharedPreferencesProvider = sharedPreferencesProvider;
    this.dateFormatUtilProvider = dateFormatUtilProvider;
    this.ringerModeTrackerProvider = ringerModeTrackerProvider;
    this.privacyItemControllerProvider = privacyItemControllerProvider;
    this.privacyLoggerProvider = privacyLoggerProvider;
  }

  @Override
  public PhoneStatusBarPolicy get() {
    return newInstance(iconControllerProvider.get(), commandQueueProvider.get(), broadcastDispatcherProvider.get(), uiBgExecutorProvider.get(), resourcesProvider.get(), castControllerProvider.get(), hotspotControllerProvider.get(), bluetoothControllerProvider.get(), nextAlarmControllerProvider.get(), userInfoControllerProvider.get(), rotationLockControllerProvider.get(), dataSaverControllerProvider.get(), zenModeControllerProvider.get(), deviceProvisionedControllerProvider.get(), keyguardStateControllerProvider.get(), locationControllerProvider.get(), sensorPrivacyControllerProvider.get(), iActivityManagerProvider.get(), alarmManagerProvider.get(), userManagerProvider.get(), recordingControllerProvider.get(), telecomManagerProvider.get(), displayIdProvider.get(), sharedPreferencesProvider.get(), dateFormatUtilProvider.get(), ringerModeTrackerProvider.get(), privacyItemControllerProvider.get(), privacyLoggerProvider.get());
  }

  public static PhoneStatusBarPolicy_Factory create(
      Provider<StatusBarIconController> iconControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<Resources> resourcesProvider,
      Provider<CastController> castControllerProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<BluetoothController> bluetoothControllerProvider,
      Provider<NextAlarmController> nextAlarmControllerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<RotationLockController> rotationLockControllerProvider,
      Provider<DataSaverController> dataSaverControllerProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<LocationController> locationControllerProvider,
      Provider<SensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<UserManager> userManagerProvider,
      Provider<RecordingController> recordingControllerProvider,
      Provider<TelecomManager> telecomManagerProvider, Provider<Integer> displayIdProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<DateFormatUtil> dateFormatUtilProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<PrivacyLogger> privacyLoggerProvider) {
    return new PhoneStatusBarPolicy_Factory(iconControllerProvider, commandQueueProvider, broadcastDispatcherProvider, uiBgExecutorProvider, resourcesProvider, castControllerProvider, hotspotControllerProvider, bluetoothControllerProvider, nextAlarmControllerProvider, userInfoControllerProvider, rotationLockControllerProvider, dataSaverControllerProvider, zenModeControllerProvider, deviceProvisionedControllerProvider, keyguardStateControllerProvider, locationControllerProvider, sensorPrivacyControllerProvider, iActivityManagerProvider, alarmManagerProvider, userManagerProvider, recordingControllerProvider, telecomManagerProvider, displayIdProvider, sharedPreferencesProvider, dateFormatUtilProvider, ringerModeTrackerProvider, privacyItemControllerProvider, privacyLoggerProvider);
  }

  public static PhoneStatusBarPolicy newInstance(StatusBarIconController iconController,
      CommandQueue commandQueue, BroadcastDispatcher broadcastDispatcher, Executor uiBgExecutor,
      Resources resources, CastController castController, HotspotController hotspotController,
      BluetoothController bluetoothController, NextAlarmController nextAlarmController,
      UserInfoController userInfoController, RotationLockController rotationLockController,
      DataSaverController dataSaverController, ZenModeController zenModeController,
      DeviceProvisionedController deviceProvisionedController,
      KeyguardStateController keyguardStateController, LocationController locationController,
      SensorPrivacyController sensorPrivacyController, IActivityManager iActivityManager,
      AlarmManager alarmManager, UserManager userManager, RecordingController recordingController,
      TelecomManager telecomManager, int displayId, SharedPreferences sharedPreferences,
      DateFormatUtil dateFormatUtil, RingerModeTracker ringerModeTracker,
      PrivacyItemController privacyItemController, PrivacyLogger privacyLogger) {
    return new PhoneStatusBarPolicy(iconController, commandQueue, broadcastDispatcher, uiBgExecutor, resources, castController, hotspotController, bluetoothController, nextAlarmController, userInfoController, rotationLockController, dataSaverController, zenModeController, deviceProvisionedController, keyguardStateController, locationController, sensorPrivacyController, iActivityManager, alarmManager, userManager, recordingController, telecomManager, displayId, sharedPreferences, dateFormatUtil, ringerModeTracker, privacyItemController, privacyLogger);
  }
}
