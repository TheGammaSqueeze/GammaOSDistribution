package com.android.systemui.statusbar.phone;

import com.android.systemui.navigationbar.NavigationBarController;
import com.android.systemui.statusbar.NotificationShadeWindowController;
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
public final class StatusBarDemoMode_Factory implements Factory<StatusBarDemoMode> {
  private final Provider<StatusBar> statusBarProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<NotificationShadeWindowViewController> notificationShadeWindowViewControllerProvider;

  private final Provider<NavigationBarController> navigationBarControllerProvider;

  private final Provider<Integer> displayIdProvider;

  public StatusBarDemoMode_Factory(Provider<StatusBar> statusBarProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationShadeWindowViewController> notificationShadeWindowViewControllerProvider,
      Provider<NavigationBarController> navigationBarControllerProvider,
      Provider<Integer> displayIdProvider) {
    this.statusBarProvider = statusBarProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.notificationShadeWindowViewControllerProvider = notificationShadeWindowViewControllerProvider;
    this.navigationBarControllerProvider = navigationBarControllerProvider;
    this.displayIdProvider = displayIdProvider;
  }

  @Override
  public StatusBarDemoMode get() {
    return newInstance(statusBarProvider.get(), notificationShadeWindowControllerProvider.get(), notificationShadeWindowViewControllerProvider.get(), navigationBarControllerProvider.get(), displayIdProvider.get());
  }

  public static StatusBarDemoMode_Factory create(Provider<StatusBar> statusBarProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationShadeWindowViewController> notificationShadeWindowViewControllerProvider,
      Provider<NavigationBarController> navigationBarControllerProvider,
      Provider<Integer> displayIdProvider) {
    return new StatusBarDemoMode_Factory(statusBarProvider, notificationShadeWindowControllerProvider, notificationShadeWindowViewControllerProvider, navigationBarControllerProvider, displayIdProvider);
  }

  public static StatusBarDemoMode newInstance(StatusBar statusBar,
      NotificationShadeWindowController notificationShadeWindowController,
      NotificationShadeWindowViewController notificationShadeWindowViewController,
      NavigationBarController navigationBarController, int displayId) {
    return new StatusBarDemoMode(statusBar, notificationShadeWindowController, notificationShadeWindowViewController, navigationBarController, displayId);
  }
}
