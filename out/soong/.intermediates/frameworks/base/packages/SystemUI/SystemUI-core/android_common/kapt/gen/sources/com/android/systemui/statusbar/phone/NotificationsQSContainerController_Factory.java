package com.android.systemui.statusbar.phone;

import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.recents.OverviewProxyService;
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
public final class NotificationsQSContainerController_Factory implements Factory<NotificationsQSContainerController> {
  private final Provider<NotificationsQuickSettingsContainer> viewProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  public NotificationsQSContainerController_Factory(
      Provider<NotificationsQuickSettingsContainer> viewProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider) {
    this.viewProvider = viewProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
  }

  @Override
  public NotificationsQSContainerController get() {
    return newInstance(viewProvider.get(), navigationModeControllerProvider.get(), overviewProxyServiceProvider.get());
  }

  public static NotificationsQSContainerController_Factory create(
      Provider<NotificationsQuickSettingsContainer> viewProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider) {
    return new NotificationsQSContainerController_Factory(viewProvider, navigationModeControllerProvider, overviewProxyServiceProvider);
  }

  public static NotificationsQSContainerController newInstance(
      NotificationsQuickSettingsContainer view, NavigationModeController navigationModeController,
      OverviewProxyService overviewProxyService) {
    return new NotificationsQSContainerController(view, navigationModeController, overviewProxyService);
  }
}
