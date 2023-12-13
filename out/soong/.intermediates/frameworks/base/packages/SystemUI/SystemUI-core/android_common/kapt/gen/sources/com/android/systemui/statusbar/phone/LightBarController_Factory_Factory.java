package com.android.systemui.statusbar.phone;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.plugins.DarkIconDispatcher;
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
public final class LightBarController_Factory_Factory implements Factory<LightBarController.Factory> {
  private final Provider<DarkIconDispatcher> darkIconDispatcherProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<NavigationModeController> navModeControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public LightBarController_Factory_Factory(Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.darkIconDispatcherProvider = darkIconDispatcherProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.navModeControllerProvider = navModeControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public LightBarController.Factory get() {
    return newInstance(darkIconDispatcherProvider.get(), batteryControllerProvider.get(), navModeControllerProvider.get(), dumpManagerProvider.get());
  }

  public static LightBarController_Factory_Factory create(
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new LightBarController_Factory_Factory(darkIconDispatcherProvider, batteryControllerProvider, navModeControllerProvider, dumpManagerProvider);
  }

  public static LightBarController.Factory newInstance(DarkIconDispatcher darkIconDispatcher,
      BatteryController batteryController, NavigationModeController navModeController,
      DumpManager dumpManager) {
    return new LightBarController.Factory(darkIconDispatcher, batteryController, navModeController, dumpManager);
  }
}
