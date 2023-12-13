package com.android.systemui.classifier;

import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dock.DockManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.sensors.ProximitySensor;
import com.android.systemui.util.time.SystemClock;
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
public final class FalsingCollectorImpl_Factory implements Factory<FalsingCollectorImpl> {
  private final Provider<FalsingDataProvider> falsingDataProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<HistoryTracker> historyTrackerProvider;

  private final Provider<ProximitySensor> proximitySensorProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<SystemClock> systemClockProvider;

  public FalsingCollectorImpl_Factory(Provider<FalsingDataProvider> falsingDataProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<HistoryTracker> historyTrackerProvider,
      Provider<ProximitySensor> proximitySensorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<DockManager> dockManagerProvider, Provider<DelayableExecutor> mainExecutorProvider,
      Provider<SystemClock> systemClockProvider) {
    this.falsingDataProvider = falsingDataProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.historyTrackerProvider = historyTrackerProvider;
    this.proximitySensorProvider = proximitySensorProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public FalsingCollectorImpl get() {
    return newInstance(falsingDataProvider.get(), falsingManagerProvider.get(), keyguardUpdateMonitorProvider.get(), historyTrackerProvider.get(), proximitySensorProvider.get(), statusBarStateControllerProvider.get(), keyguardStateControllerProvider.get(), batteryControllerProvider.get(), dockManagerProvider.get(), mainExecutorProvider.get(), systemClockProvider.get());
  }

  public static FalsingCollectorImpl_Factory create(
      Provider<FalsingDataProvider> falsingDataProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<HistoryTracker> historyTrackerProvider,
      Provider<ProximitySensor> proximitySensorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<DockManager> dockManagerProvider, Provider<DelayableExecutor> mainExecutorProvider,
      Provider<SystemClock> systemClockProvider) {
    return new FalsingCollectorImpl_Factory(falsingDataProvider, falsingManagerProvider, keyguardUpdateMonitorProvider, historyTrackerProvider, proximitySensorProvider, statusBarStateControllerProvider, keyguardStateControllerProvider, batteryControllerProvider, dockManagerProvider, mainExecutorProvider, systemClockProvider);
  }

  public static FalsingCollectorImpl newInstance(FalsingDataProvider falsingDataProvider,
      FalsingManager falsingManager, KeyguardUpdateMonitor keyguardUpdateMonitor,
      HistoryTracker historyTracker, ProximitySensor proximitySensor,
      StatusBarStateController statusBarStateController,
      KeyguardStateController keyguardStateController, BatteryController batteryController,
      DockManager dockManager, DelayableExecutor mainExecutor, SystemClock systemClock) {
    return new FalsingCollectorImpl(falsingDataProvider, falsingManager, keyguardUpdateMonitor, historyTracker, proximitySensor, statusBarStateController, keyguardStateController, batteryController, dockManager, mainExecutor, systemClock);
  }
}
