package com.android.systemui.statusbar.phone;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.notification.init.NotificationsController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
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
public final class StatusBarHeadsUpChangeListener_Factory implements Factory<StatusBarHeadsUpChangeListener> {
  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider;

  private final Provider<NotificationsController> notificationsControllerProvider;

  private final Provider<DozeServiceHost> dozeServiceHostProvider;

  private final Provider<DozeScrimController> dozeScrimControllerProvider;

  public StatusBarHeadsUpChangeListener_Factory(
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationsController> notificationsControllerProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider) {
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationRemoteInputManagerProvider = notificationRemoteInputManagerProvider;
    this.notificationsControllerProvider = notificationsControllerProvider;
    this.dozeServiceHostProvider = dozeServiceHostProvider;
    this.dozeScrimControllerProvider = dozeScrimControllerProvider;
  }

  @Override
  public StatusBarHeadsUpChangeListener get() {
    return newInstance(notificationShadeWindowControllerProvider.get(), statusBarWindowControllerProvider.get(), notificationPanelViewControllerProvider.get(), keyguardBypassControllerProvider.get(), headsUpManagerProvider.get(), statusBarStateControllerProvider.get(), notificationRemoteInputManagerProvider.get(), notificationsControllerProvider.get(), dozeServiceHostProvider.get(), dozeScrimControllerProvider.get());
  }

  public static StatusBarHeadsUpChangeListener_Factory create(
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationsController> notificationsControllerProvider,
      Provider<DozeServiceHost> dozeServiceHostProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider) {
    return new StatusBarHeadsUpChangeListener_Factory(notificationShadeWindowControllerProvider, statusBarWindowControllerProvider, notificationPanelViewControllerProvider, keyguardBypassControllerProvider, headsUpManagerProvider, statusBarStateControllerProvider, notificationRemoteInputManagerProvider, notificationsControllerProvider, dozeServiceHostProvider, dozeScrimControllerProvider);
  }

  public static StatusBarHeadsUpChangeListener newInstance(
      NotificationShadeWindowController notificationShadeWindowController,
      StatusBarWindowController statusBarWindowController,
      NotificationPanelViewController notificationPanelViewController,
      KeyguardBypassController keyguardBypassController, HeadsUpManagerPhone headsUpManager,
      StatusBarStateController statusBarStateController,
      NotificationRemoteInputManager notificationRemoteInputManager,
      NotificationsController notificationsController, DozeServiceHost dozeServiceHost,
      DozeScrimController dozeScrimController) {
    return new StatusBarHeadsUpChangeListener(notificationShadeWindowController, statusBarWindowController, notificationPanelViewController, keyguardBypassController, headsUpManager, statusBarStateController, notificationRemoteInputManager, notificationsController, dozeServiceHost, dozeScrimController);
  }
}
