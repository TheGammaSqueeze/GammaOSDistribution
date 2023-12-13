package com.android.systemui.navigationbar;

import android.content.Context;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
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
public final class NavigationModeController_Factory implements Factory<NavigationModeController> {
  private final Provider<Context> contextProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NavigationModeController_Factory(Provider<Context> contextProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NavigationModeController get() {
    return newInstance(contextProvider.get(), deviceProvisionedControllerProvider.get(), configurationControllerProvider.get(), uiBgExecutorProvider.get(), dumpManagerProvider.get());
  }

  public static NavigationModeController_Factory create(Provider<Context> contextProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    return new NavigationModeController_Factory(contextProvider, deviceProvisionedControllerProvider, configurationControllerProvider, uiBgExecutorProvider, dumpManagerProvider);
  }

  public static NavigationModeController newInstance(Context context,
      DeviceProvisionedController deviceProvisionedController,
      ConfigurationController configurationController, Executor uiBgExecutor,
      DumpManager dumpManager) {
    return new NavigationModeController(context, deviceProvisionedController, configurationController, uiBgExecutor, dumpManager);
  }
}
