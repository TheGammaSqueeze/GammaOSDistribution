package com.android.systemui.classifier;

import android.util.DisplayMetrics;
import com.android.systemui.dock.DockManager;
import com.android.systemui.statusbar.policy.BatteryController;
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
public final class FalsingDataProvider_Factory implements Factory<FalsingDataProvider> {
  private final Provider<DisplayMetrics> displayMetricsProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<DockManager> dockManagerProvider;

  public FalsingDataProvider_Factory(Provider<DisplayMetrics> displayMetricsProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<DockManager> dockManagerProvider) {
    this.displayMetricsProvider = displayMetricsProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.dockManagerProvider = dockManagerProvider;
  }

  @Override
  public FalsingDataProvider get() {
    return newInstance(displayMetricsProvider.get(), batteryControllerProvider.get(), dockManagerProvider.get());
  }

  public static FalsingDataProvider_Factory create(Provider<DisplayMetrics> displayMetricsProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<DockManager> dockManagerProvider) {
    return new FalsingDataProvider_Factory(displayMetricsProvider, batteryControllerProvider, dockManagerProvider);
  }

  public static FalsingDataProvider newInstance(DisplayMetrics displayMetrics,
      BatteryController batteryController, DockManager dockManager) {
    return new FalsingDataProvider(displayMetrics, batteryController, dockManager);
  }
}
