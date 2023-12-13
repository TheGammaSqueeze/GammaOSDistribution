package com.android.systemui.statusbar.phone;

import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class HeadsUpAppearanceController_Factory implements Factory<HeadsUpAppearanceController> {
  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  private final Provider<PhoneStatusBarView> statusBarViewProvider;

  public HeadsUpAppearanceController_Factory(
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<PhoneStatusBarView> statusBarViewProvider) {
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.notificationStackScrollLayoutControllerProvider = notificationStackScrollLayoutControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.wakeUpCoordinatorProvider = wakeUpCoordinatorProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
    this.statusBarViewProvider = statusBarViewProvider;
  }

  @Override
  public HeadsUpAppearanceController get() {
    return newInstance(notificationIconAreaControllerProvider.get(), headsUpManagerProvider.get(), notificationStackScrollLayoutControllerProvider.get(), statusBarStateControllerProvider.get(), keyguardBypassControllerProvider.get(), keyguardStateControllerProvider.get(), wakeUpCoordinatorProvider.get(), commandQueueProvider.get(), notificationPanelViewControllerProvider.get(), statusBarViewProvider.get());
  }

  public static HeadsUpAppearanceController_Factory create(
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<PhoneStatusBarView> statusBarViewProvider) {
    return new HeadsUpAppearanceController_Factory(notificationIconAreaControllerProvider, headsUpManagerProvider, notificationStackScrollLayoutControllerProvider, statusBarStateControllerProvider, keyguardBypassControllerProvider, keyguardStateControllerProvider, wakeUpCoordinatorProvider, commandQueueProvider, notificationPanelViewControllerProvider, statusBarViewProvider);
  }

  public static HeadsUpAppearanceController newInstance(
      NotificationIconAreaController notificationIconAreaController,
      HeadsUpManagerPhone headsUpManager,
      NotificationStackScrollLayoutController notificationStackScrollLayoutController,
      SysuiStatusBarStateController statusBarStateController,
      KeyguardBypassController keyguardBypassController,
      KeyguardStateController keyguardStateController,
      NotificationWakeUpCoordinator wakeUpCoordinator, CommandQueue commandQueue,
      NotificationPanelViewController notificationPanelViewController,
      PhoneStatusBarView statusBarView) {
    return new HeadsUpAppearanceController(notificationIconAreaController, headsUpManager, notificationStackScrollLayoutController, statusBarStateController, keyguardBypassController, keyguardStateController, wakeUpCoordinator, commandQueue, notificationPanelViewController, statusBarView);
  }
}
