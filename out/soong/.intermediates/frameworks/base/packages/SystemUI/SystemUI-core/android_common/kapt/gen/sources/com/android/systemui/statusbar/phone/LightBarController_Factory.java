package com.android.systemui.statusbar.phone;

import android.content.Context;
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
public final class LightBarController_Factory implements Factory<LightBarController> {
  private final Provider<Context> ctxProvider;

  private final Provider<DarkIconDispatcher> darkIconDispatcherProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<NavigationModeController> navModeControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public LightBarController_Factory(Provider<Context> ctxProvider,
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.ctxProvider = ctxProvider;
    this.darkIconDispatcherProvider = darkIconDispatcherProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.navModeControllerProvider = navModeControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public LightBarController get() {
    return newInstance(ctxProvider.get(), darkIconDispatcherProvider.get(), batteryControllerProvider.get(), navModeControllerProvider.get(), dumpManagerProvider.get());
  }

  public static LightBarController_Factory create(Provider<Context> ctxProvider,
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<NavigationModeController> navModeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new LightBarController_Factory(ctxProvider, darkIconDispatcherProvider, batteryControllerProvider, navModeControllerProvider, dumpManagerProvider);
  }

  public static LightBarController newInstance(Context ctx, DarkIconDispatcher darkIconDispatcher,
      BatteryController batteryController, NavigationModeController navModeController,
      DumpManager dumpManager) {
    return new LightBarController(ctx, darkIconDispatcher, batteryController, navModeController, dumpManager);
  }
}
