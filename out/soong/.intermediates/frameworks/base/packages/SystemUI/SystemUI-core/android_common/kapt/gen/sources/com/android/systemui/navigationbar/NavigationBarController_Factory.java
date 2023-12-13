package com.android.systemui.navigationbar;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.model.SysUiState;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.phone.AutoHideController;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.wm.shell.pip.Pip;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class NavigationBarController_Factory implements Factory<NavigationBarController> {
  private final Provider<Context> contextProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<SysUiState> sysUiFlagsContainerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<NavBarHelper> navBarHelperProvider;

  private final Provider<TaskbarDelegate> taskbarDelegateProvider;

  private final Provider<NavigationBar.Factory> navigationBarFactoryProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<AutoHideController> autoHideControllerProvider;

  private final Provider<LightBarController> lightBarControllerProvider;

  private final Provider<Optional<Pip>> pipOptionalProvider;

  public NavigationBarController_Factory(Provider<Context> contextProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<SysUiState> sysUiFlagsContainerProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NavBarHelper> navBarHelperProvider,
      Provider<TaskbarDelegate> taskbarDelegateProvider,
      Provider<NavigationBar.Factory> navigationBarFactoryProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<AutoHideController> autoHideControllerProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<Optional<Pip>> pipOptionalProvider) {
    this.contextProvider = contextProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.sysUiFlagsContainerProvider = sysUiFlagsContainerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.navBarHelperProvider = navBarHelperProvider;
    this.taskbarDelegateProvider = taskbarDelegateProvider;
    this.navigationBarFactoryProvider = navigationBarFactoryProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.autoHideControllerProvider = autoHideControllerProvider;
    this.lightBarControllerProvider = lightBarControllerProvider;
    this.pipOptionalProvider = pipOptionalProvider;
  }

  @Override
  public NavigationBarController get() {
    return newInstance(contextProvider.get(), overviewProxyServiceProvider.get(), navigationModeControllerProvider.get(), sysUiFlagsContainerProvider.get(), commandQueueProvider.get(), mainHandlerProvider.get(), configurationControllerProvider.get(), navBarHelperProvider.get(), taskbarDelegateProvider.get(), navigationBarFactoryProvider.get(), dumpManagerProvider.get(), autoHideControllerProvider.get(), lightBarControllerProvider.get(), pipOptionalProvider.get());
  }

  public static NavigationBarController_Factory create(Provider<Context> contextProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<SysUiState> sysUiFlagsContainerProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<NavBarHelper> navBarHelperProvider,
      Provider<TaskbarDelegate> taskbarDelegateProvider,
      Provider<NavigationBar.Factory> navigationBarFactoryProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<AutoHideController> autoHideControllerProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<Optional<Pip>> pipOptionalProvider) {
    return new NavigationBarController_Factory(contextProvider, overviewProxyServiceProvider, navigationModeControllerProvider, sysUiFlagsContainerProvider, commandQueueProvider, mainHandlerProvider, configurationControllerProvider, navBarHelperProvider, taskbarDelegateProvider, navigationBarFactoryProvider, dumpManagerProvider, autoHideControllerProvider, lightBarControllerProvider, pipOptionalProvider);
  }

  public static NavigationBarController newInstance(Context context,
      OverviewProxyService overviewProxyService, NavigationModeController navigationModeController,
      SysUiState sysUiFlagsContainer, CommandQueue commandQueue, Handler mainHandler,
      ConfigurationController configurationController, NavBarHelper navBarHelper,
      TaskbarDelegate taskbarDelegate, NavigationBar.Factory navigationBarFactory,
      DumpManager dumpManager, AutoHideController autoHideController,
      LightBarController lightBarController, Optional<Pip> pipOptional) {
    return new NavigationBarController(context, overviewProxyService, navigationModeController, sysUiFlagsContainer, commandQueue, mainHandler, configurationController, navBarHelper, taskbarDelegate, navigationBarFactory, dumpManager, autoHideController, lightBarController, pipOptional);
  }
}
