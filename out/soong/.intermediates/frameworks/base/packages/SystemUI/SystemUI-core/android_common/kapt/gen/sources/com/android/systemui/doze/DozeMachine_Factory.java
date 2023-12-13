package com.android.systemui.doze;

import android.hardware.display.AmbientDisplayConfiguration;
import com.android.systemui.dock.DockManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.policy.BatteryController;
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
public final class DozeMachine_Factory implements Factory<DozeMachine> {
  private final Provider<DozeMachine.Service> serviceProvider;

  private final Provider<AmbientDisplayConfiguration> configProvider;

  private final Provider<WakeLock> wakeLockProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<DozeHost> dozeHostProvider;

  private final Provider<DozeMachine.Part[]> partsProvider;

  public DozeMachine_Factory(Provider<DozeMachine.Service> serviceProvider,
      Provider<AmbientDisplayConfiguration> configProvider, Provider<WakeLock> wakeLockProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<BatteryController> batteryControllerProvider, Provider<DozeLog> dozeLogProvider,
      Provider<DockManager> dockManagerProvider, Provider<DozeHost> dozeHostProvider,
      Provider<DozeMachine.Part[]> partsProvider) {
    this.serviceProvider = serviceProvider;
    this.configProvider = configProvider;
    this.wakeLockProvider = wakeLockProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.dozeHostProvider = dozeHostProvider;
    this.partsProvider = partsProvider;
  }

  @Override
  public DozeMachine get() {
    return newInstance(serviceProvider.get(), configProvider.get(), wakeLockProvider.get(), wakefulnessLifecycleProvider.get(), batteryControllerProvider.get(), dozeLogProvider.get(), dockManagerProvider.get(), dozeHostProvider.get(), partsProvider.get());
  }

  public static DozeMachine_Factory create(Provider<DozeMachine.Service> serviceProvider,
      Provider<AmbientDisplayConfiguration> configProvider, Provider<WakeLock> wakeLockProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<BatteryController> batteryControllerProvider, Provider<DozeLog> dozeLogProvider,
      Provider<DockManager> dockManagerProvider, Provider<DozeHost> dozeHostProvider,
      Provider<DozeMachine.Part[]> partsProvider) {
    return new DozeMachine_Factory(serviceProvider, configProvider, wakeLockProvider, wakefulnessLifecycleProvider, batteryControllerProvider, dozeLogProvider, dockManagerProvider, dozeHostProvider, partsProvider);
  }

  public static DozeMachine newInstance(DozeMachine.Service service,
      AmbientDisplayConfiguration config, WakeLock wakeLock,
      WakefulnessLifecycle wakefulnessLifecycle, BatteryController batteryController,
      DozeLog dozeLog, DockManager dockManager, DozeHost dozeHost, DozeMachine.Part[] parts) {
    return new DozeMachine(service, config, wakeLock, wakefulnessLifecycle, batteryController, dozeLog, dockManager, dozeHost, parts);
  }
}
