package com.android.systemui.accessibility;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.model.SysUiState;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.statusbar.CommandQueue;
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
public final class WindowMagnification_Factory implements Factory<WindowMagnification> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ModeSwitchesController> modeSwitchesControllerProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  public WindowMagnification_Factory(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<ModeSwitchesController> modeSwitchesControllerProvider,
      Provider<SysUiState> sysUiStateProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.modeSwitchesControllerProvider = modeSwitchesControllerProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
  }

  @Override
  public WindowMagnification get() {
    return newInstance(contextProvider.get(), mainHandlerProvider.get(), commandQueueProvider.get(), modeSwitchesControllerProvider.get(), sysUiStateProvider.get(), overviewProxyServiceProvider.get());
  }

  public static WindowMagnification_Factory create(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<ModeSwitchesController> modeSwitchesControllerProvider,
      Provider<SysUiState> sysUiStateProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider) {
    return new WindowMagnification_Factory(contextProvider, mainHandlerProvider, commandQueueProvider, modeSwitchesControllerProvider, sysUiStateProvider, overviewProxyServiceProvider);
  }

  public static WindowMagnification newInstance(Context context, Handler mainHandler,
      CommandQueue commandQueue, ModeSwitchesController modeSwitchesController,
      SysUiState sysUiState, OverviewProxyService overviewProxyService) {
    return new WindowMagnification(context, mainHandler, commandQueue, modeSwitchesController, sysUiState, overviewProxyService);
  }
}
