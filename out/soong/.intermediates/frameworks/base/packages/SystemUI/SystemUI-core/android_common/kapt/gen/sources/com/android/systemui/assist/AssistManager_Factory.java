package com.android.systemui.assist;

import android.content.Context;
import android.os.Handler;
import com.android.internal.app.AssistUtils;
import com.android.systemui.assist.ui.DefaultUiController;
import com.android.systemui.model.SysUiState;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class AssistManager_Factory implements Factory<AssistManager> {
  private final Provider<DeviceProvisionedController> controllerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<AssistUtils> assistUtilsProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<PhoneStateMonitor> phoneStateMonitorProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<DefaultUiController> defaultUiControllerProvider;

  private final Provider<AssistLogger> assistLoggerProvider;

  private final Provider<Handler> uiHandlerProvider;

  public AssistManager_Factory(Provider<DeviceProvisionedController> controllerProvider,
      Provider<Context> contextProvider, Provider<AssistUtils> assistUtilsProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<PhoneStateMonitor> phoneStateMonitorProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<SysUiState> sysUiStateProvider,
      Provider<DefaultUiController> defaultUiControllerProvider,
      Provider<AssistLogger> assistLoggerProvider, Provider<Handler> uiHandlerProvider) {
    this.controllerProvider = controllerProvider;
    this.contextProvider = contextProvider;
    this.assistUtilsProvider = assistUtilsProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.phoneStateMonitorProvider = phoneStateMonitorProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.defaultUiControllerProvider = defaultUiControllerProvider;
    this.assistLoggerProvider = assistLoggerProvider;
    this.uiHandlerProvider = uiHandlerProvider;
  }

  @Override
  public AssistManager get() {
    return newInstance(controllerProvider.get(), contextProvider.get(), assistUtilsProvider.get(), commandQueueProvider.get(), phoneStateMonitorProvider.get(), overviewProxyServiceProvider.get(), DoubleCheck.lazy(sysUiStateProvider), defaultUiControllerProvider.get(), assistLoggerProvider.get(), uiHandlerProvider.get());
  }

  public static AssistManager_Factory create(
      Provider<DeviceProvisionedController> controllerProvider, Provider<Context> contextProvider,
      Provider<AssistUtils> assistUtilsProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<PhoneStateMonitor> phoneStateMonitorProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<SysUiState> sysUiStateProvider,
      Provider<DefaultUiController> defaultUiControllerProvider,
      Provider<AssistLogger> assistLoggerProvider, Provider<Handler> uiHandlerProvider) {
    return new AssistManager_Factory(controllerProvider, contextProvider, assistUtilsProvider, commandQueueProvider, phoneStateMonitorProvider, overviewProxyServiceProvider, sysUiStateProvider, defaultUiControllerProvider, assistLoggerProvider, uiHandlerProvider);
  }

  public static AssistManager newInstance(DeviceProvisionedController controller, Context context,
      AssistUtils assistUtils, CommandQueue commandQueue, PhoneStateMonitor phoneStateMonitor,
      OverviewProxyService overviewProxyService, Lazy<SysUiState> sysUiState,
      DefaultUiController defaultUiController, AssistLogger assistLogger, Handler uiHandler) {
    return new AssistManager(controller, context, assistUtils, commandQueue, phoneStateMonitor, overviewProxyService, sysUiState, defaultUiController, assistLogger, uiHandler);
  }
}
