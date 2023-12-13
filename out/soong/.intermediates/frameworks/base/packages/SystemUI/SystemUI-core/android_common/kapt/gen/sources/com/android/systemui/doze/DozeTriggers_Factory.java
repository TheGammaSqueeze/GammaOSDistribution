package com.android.systemui.doze;

import android.content.Context;
import android.hardware.display.AmbientDisplayConfiguration;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dock.DockManager;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.policy.DevicePostureController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.sensors.AsyncSensorManager;
import com.android.systemui.util.sensors.ProximityCheck;
import com.android.systemui.util.sensors.ProximitySensor;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.util.wakelock.WakeLock;
import dagger.internal.Factory;
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
public final class DozeTriggers_Factory implements Factory<DozeTriggers> {
  private final Provider<Context> contextProvider;

  private final Provider<DozeHost> dozeHostProvider;

  private final Provider<AmbientDisplayConfiguration> configProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<AsyncSensorManager> sensorManagerProvider;

  private final Provider<WakeLock> wakeLockProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<ProximitySensor> proximitySensorProvider;

  private final Provider<ProximityCheck> proxCheckProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DevicePostureController> devicePostureControllerProvider;

  public DozeTriggers_Factory(Provider<Context> contextProvider,
      Provider<DozeHost> dozeHostProvider, Provider<AmbientDisplayConfiguration> configProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<WakeLock> wakeLockProvider,
      Provider<DockManager> dockManagerProvider, Provider<ProximitySensor> proximitySensorProvider,
      Provider<ProximityCheck> proxCheckProvider, Provider<DozeLog> dozeLogProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<AuthController> authControllerProvider,
      Provider<DelayableExecutor> mainExecutorProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    this.contextProvider = contextProvider;
    this.dozeHostProvider = dozeHostProvider;
    this.configProvider = configProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.sensorManagerProvider = sensorManagerProvider;
    this.wakeLockProvider = wakeLockProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.proximitySensorProvider = proximitySensorProvider;
    this.proxCheckProvider = proxCheckProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.authControllerProvider = authControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.devicePostureControllerProvider = devicePostureControllerProvider;
  }

  @Override
  public DozeTriggers get() {
    return newInstance(contextProvider.get(), dozeHostProvider.get(), configProvider.get(), dozeParametersProvider.get(), sensorManagerProvider.get(), wakeLockProvider.get(), dockManagerProvider.get(), proximitySensorProvider.get(), proxCheckProvider.get(), dozeLogProvider.get(), broadcastDispatcherProvider.get(), secureSettingsProvider.get(), authControllerProvider.get(), mainExecutorProvider.get(), uiEventLoggerProvider.get(), keyguardStateControllerProvider.get(), devicePostureControllerProvider.get());
  }

  public static DozeTriggers_Factory create(Provider<Context> contextProvider,
      Provider<DozeHost> dozeHostProvider, Provider<AmbientDisplayConfiguration> configProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<AsyncSensorManager> sensorManagerProvider, Provider<WakeLock> wakeLockProvider,
      Provider<DockManager> dockManagerProvider, Provider<ProximitySensor> proximitySensorProvider,
      Provider<ProximityCheck> proxCheckProvider, Provider<DozeLog> dozeLogProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<AuthController> authControllerProvider,
      Provider<DelayableExecutor> mainExecutorProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    return new DozeTriggers_Factory(contextProvider, dozeHostProvider, configProvider, dozeParametersProvider, sensorManagerProvider, wakeLockProvider, dockManagerProvider, proximitySensorProvider, proxCheckProvider, dozeLogProvider, broadcastDispatcherProvider, secureSettingsProvider, authControllerProvider, mainExecutorProvider, uiEventLoggerProvider, keyguardStateControllerProvider, devicePostureControllerProvider);
  }

  public static DozeTriggers newInstance(Context context, DozeHost dozeHost,
      AmbientDisplayConfiguration config, DozeParameters dozeParameters,
      AsyncSensorManager sensorManager, WakeLock wakeLock, DockManager dockManager,
      ProximitySensor proximitySensor, ProximityCheck proxCheck, DozeLog dozeLog,
      BroadcastDispatcher broadcastDispatcher, SecureSettings secureSettings,
      AuthController authController, DelayableExecutor mainExecutor, UiEventLogger uiEventLogger,
      KeyguardStateController keyguardStateController,
      DevicePostureController devicePostureController) {
    return new DozeTriggers(context, dozeHost, config, dozeParameters, sensorManager, wakeLock, dockManager, proximitySensor, proxCheck, dozeLog, broadcastDispatcher, secureSettings, authController, mainExecutor, uiEventLogger, keyguardStateController, devicePostureController);
  }
}
