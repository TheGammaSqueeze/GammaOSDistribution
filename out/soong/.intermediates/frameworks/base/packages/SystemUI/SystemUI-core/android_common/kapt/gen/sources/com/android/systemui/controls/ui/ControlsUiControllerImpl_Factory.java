package com.android.systemui.controls.ui;

import android.content.Context;
import android.content.SharedPreferences;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.controls.CustomIconCache;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class ControlsUiControllerImpl_Factory implements Factory<ControlsUiControllerImpl> {
  private final Provider<ControlsController> controlsControllerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<DelayableExecutor> uiExecutorProvider;

  private final Provider<DelayableExecutor> bgExecutorProvider;

  private final Provider<ControlsListingController> controlsListingControllerProvider;

  private final Provider<SharedPreferences> sharedPreferencesProvider;

  private final Provider<ControlActionCoordinator> controlActionCoordinatorProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<CustomIconCache> iconCacheProvider;

  private final Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  public ControlsUiControllerImpl_Factory(Provider<ControlsController> controlsControllerProvider,
      Provider<Context> contextProvider, Provider<DelayableExecutor> uiExecutorProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<ControlsListingController> controlsListingControllerProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<ControlActionCoordinator> controlActionCoordinatorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CustomIconCache> iconCacheProvider,
      Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    this.controlsControllerProvider = controlsControllerProvider;
    this.contextProvider = contextProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.controlsListingControllerProvider = controlsListingControllerProvider;
    this.sharedPreferencesProvider = sharedPreferencesProvider;
    this.controlActionCoordinatorProvider = controlActionCoordinatorProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.iconCacheProvider = iconCacheProvider;
    this.controlsMetricsLoggerProvider = controlsMetricsLoggerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
  }

  @Override
  public ControlsUiControllerImpl get() {
    return newInstance(DoubleCheck.lazy(controlsControllerProvider), contextProvider.get(), uiExecutorProvider.get(), bgExecutorProvider.get(), DoubleCheck.lazy(controlsListingControllerProvider), sharedPreferencesProvider.get(), controlActionCoordinatorProvider.get(), activityStarterProvider.get(), shadeControllerProvider.get(), iconCacheProvider.get(), controlsMetricsLoggerProvider.get(), keyguardStateControllerProvider.get());
  }

  public static ControlsUiControllerImpl_Factory create(
      Provider<ControlsController> controlsControllerProvider, Provider<Context> contextProvider,
      Provider<DelayableExecutor> uiExecutorProvider,
      Provider<DelayableExecutor> bgExecutorProvider,
      Provider<ControlsListingController> controlsListingControllerProvider,
      Provider<SharedPreferences> sharedPreferencesProvider,
      Provider<ControlActionCoordinator> controlActionCoordinatorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CustomIconCache> iconCacheProvider,
      Provider<ControlsMetricsLogger> controlsMetricsLoggerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    return new ControlsUiControllerImpl_Factory(controlsControllerProvider, contextProvider, uiExecutorProvider, bgExecutorProvider, controlsListingControllerProvider, sharedPreferencesProvider, controlActionCoordinatorProvider, activityStarterProvider, shadeControllerProvider, iconCacheProvider, controlsMetricsLoggerProvider, keyguardStateControllerProvider);
  }

  public static ControlsUiControllerImpl newInstance(Lazy<ControlsController> controlsController,
      Context context, DelayableExecutor uiExecutor, DelayableExecutor bgExecutor,
      Lazy<ControlsListingController> controlsListingController,
      SharedPreferences sharedPreferences, ControlActionCoordinator controlActionCoordinator,
      ActivityStarter activityStarter, ShadeController shadeController, CustomIconCache iconCache,
      ControlsMetricsLogger controlsMetricsLogger,
      KeyguardStateController keyguardStateController) {
    return new ControlsUiControllerImpl(controlsController, context, uiExecutor, bgExecutor, controlsListingController, sharedPreferences, controlActionCoordinator, activityStarter, shadeController, iconCache, controlsMetricsLogger, keyguardStateController);
  }
}
