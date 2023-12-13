package com.android.systemui.navigationbar.gestural;

import android.view.IWindowManager;
import android.view.ViewConfiguration;
import android.view.WindowManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.model.SysUiState;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.tracing.ProtoTracer;
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
public final class EdgeBackGestureHandler_Factory_Factory implements Factory<EdgeBackGestureHandler.Factory> {
  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ProtoTracer> protoTracerProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<ViewConfiguration> viewConfigurationProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<IWindowManager> windowManagerServiceProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  public EdgeBackGestureHandler_Factory_Factory(
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<Executor> executorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ProtoTracer> protoTracerProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<ViewConfiguration> viewConfigurationProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<IWindowManager> windowManagerServiceProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.executorProvider = executorProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.protoTracerProvider = protoTracerProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.viewConfigurationProvider = viewConfigurationProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.windowManagerServiceProvider = windowManagerServiceProvider;
    this.falsingManagerProvider = falsingManagerProvider;
  }

  @Override
  public EdgeBackGestureHandler.Factory get() {
    return newInstance(overviewProxyServiceProvider.get(), sysUiStateProvider.get(), pluginManagerProvider.get(), executorProvider.get(), broadcastDispatcherProvider.get(), protoTracerProvider.get(), navigationModeControllerProvider.get(), viewConfigurationProvider.get(), windowManagerProvider.get(), windowManagerServiceProvider.get(), falsingManagerProvider.get());
  }

  public static EdgeBackGestureHandler_Factory_Factory create(
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<SysUiState> sysUiStateProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<Executor> executorProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ProtoTracer> protoTracerProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<ViewConfiguration> viewConfigurationProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<IWindowManager> windowManagerServiceProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    return new EdgeBackGestureHandler_Factory_Factory(overviewProxyServiceProvider, sysUiStateProvider, pluginManagerProvider, executorProvider, broadcastDispatcherProvider, protoTracerProvider, navigationModeControllerProvider, viewConfigurationProvider, windowManagerProvider, windowManagerServiceProvider, falsingManagerProvider);
  }

  public static EdgeBackGestureHandler.Factory newInstance(
      OverviewProxyService overviewProxyService, SysUiState sysUiState, PluginManager pluginManager,
      Executor executor, BroadcastDispatcher broadcastDispatcher, ProtoTracer protoTracer,
      NavigationModeController navigationModeController, ViewConfiguration viewConfiguration,
      WindowManager windowManager, IWindowManager windowManagerService,
      FalsingManager falsingManager) {
    return new EdgeBackGestureHandler.Factory(overviewProxyService, sysUiState, pluginManager, executor, broadcastDispatcher, protoTracer, navigationModeController, viewConfiguration, windowManager, windowManagerService, falsingManager);
  }
}
