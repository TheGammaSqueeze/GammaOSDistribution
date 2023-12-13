package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.plugins.DarkIconDispatcher;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.wm.shell.bubbles.Bubbles;
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
public final class NotificationIconAreaController_Factory implements Factory<NotificationIconAreaController> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<NotificationMediaManager> notificationMediaManagerProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<DarkIconDispatcher> darkIconDispatcherProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  public NotificationIconAreaController_Factory(Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.wakeUpCoordinatorProvider = wakeUpCoordinatorProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.notificationMediaManagerProvider = notificationMediaManagerProvider;
    this.notificationListenerProvider = notificationListenerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.darkIconDispatcherProvider = darkIconDispatcherProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
  }

  @Override
  public NotificationIconAreaController get() {
    return newInstance(contextProvider.get(), statusBarStateControllerProvider.get(), wakeUpCoordinatorProvider.get(), keyguardBypassControllerProvider.get(), notificationMediaManagerProvider.get(), notificationListenerProvider.get(), dozeParametersProvider.get(), bubblesOptionalProvider.get(), demoModeControllerProvider.get(), darkIconDispatcherProvider.get(), statusBarWindowControllerProvider.get(), unlockedScreenOffAnimationControllerProvider.get());
  }

  public static NotificationIconAreaController_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<NotificationListener> notificationListenerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<DarkIconDispatcher> darkIconDispatcherProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    return new NotificationIconAreaController_Factory(contextProvider, statusBarStateControllerProvider, wakeUpCoordinatorProvider, keyguardBypassControllerProvider, notificationMediaManagerProvider, notificationListenerProvider, dozeParametersProvider, bubblesOptionalProvider, demoModeControllerProvider, darkIconDispatcherProvider, statusBarWindowControllerProvider, unlockedScreenOffAnimationControllerProvider);
  }

  public static NotificationIconAreaController newInstance(Context context,
      StatusBarStateController statusBarStateController,
      NotificationWakeUpCoordinator wakeUpCoordinator,
      KeyguardBypassController keyguardBypassController,
      NotificationMediaManager notificationMediaManager, NotificationListener notificationListener,
      DozeParameters dozeParameters, Optional<Bubbles> bubblesOptional,
      DemoModeController demoModeController, DarkIconDispatcher darkIconDispatcher,
      StatusBarWindowController statusBarWindowController,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
    return new NotificationIconAreaController(context, statusBarStateController, wakeUpCoordinator, keyguardBypassController, notificationMediaManager, notificationListener, dozeParameters, bubblesOptional, demoModeController, darkIconDispatcher, statusBarWindowController, unlockedScreenOffAnimationController);
  }
}
