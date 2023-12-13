package com.android.systemui.statusbar.events;

import android.content.Context;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.statusbar.policy.BatteryController;
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
public final class SystemEventCoordinator_Factory implements Factory<SystemEventCoordinator> {
  private final Provider<SystemClock> systemClockProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<PrivacyItemController> privacyControllerProvider;

  private final Provider<Context> contextProvider;

  public SystemEventCoordinator_Factory(Provider<SystemClock> systemClockProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<PrivacyItemController> privacyControllerProvider,
      Provider<Context> contextProvider) {
    this.systemClockProvider = systemClockProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.privacyControllerProvider = privacyControllerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public SystemEventCoordinator get() {
    return newInstance(systemClockProvider.get(), batteryControllerProvider.get(), privacyControllerProvider.get(), contextProvider.get());
  }

  public static SystemEventCoordinator_Factory create(Provider<SystemClock> systemClockProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<PrivacyItemController> privacyControllerProvider,
      Provider<Context> contextProvider) {
    return new SystemEventCoordinator_Factory(systemClockProvider, batteryControllerProvider, privacyControllerProvider, contextProvider);
  }

  public static SystemEventCoordinator newInstance(SystemClock systemClock,
      BatteryController batteryController, PrivacyItemController privacyController,
      Context context) {
    return new SystemEventCoordinator(systemClock, batteryController, privacyController, context);
  }
}
