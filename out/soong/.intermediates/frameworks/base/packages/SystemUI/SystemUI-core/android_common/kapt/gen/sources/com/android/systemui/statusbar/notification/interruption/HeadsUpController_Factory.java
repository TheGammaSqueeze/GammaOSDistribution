package com.android.systemui.statusbar.notification.interruption;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.policy.HeadsUpManager;
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
public final class HeadsUpController_Factory implements Factory<HeadsUpController> {
  private final Provider<HeadsUpViewBinder> headsUpViewBinderProvider;

  private final Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<NotificationListener> notificationListenerProvider;

  public HeadsUpController_Factory(Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    this.headsUpViewBinderProvider = headsUpViewBinderProvider;
    this.notificationInterruptStateProvider = notificationInterruptStateProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.notificationListenerProvider = notificationListenerProvider;
  }

  @Override
  public HeadsUpController get() {
    return newInstance(headsUpViewBinderProvider.get(), notificationInterruptStateProvider.get(), headsUpManagerProvider.get(), remoteInputManagerProvider.get(), statusBarStateControllerProvider.get(), visualStabilityManagerProvider.get(), notificationListenerProvider.get());
  }

  public static HeadsUpController_Factory create(
      Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<NotificationListener> notificationListenerProvider) {
    return new HeadsUpController_Factory(headsUpViewBinderProvider, notificationInterruptStateProvider, headsUpManagerProvider, remoteInputManagerProvider, statusBarStateControllerProvider, visualStabilityManagerProvider, notificationListenerProvider);
  }

  public static HeadsUpController newInstance(HeadsUpViewBinder headsUpViewBinder,
      NotificationInterruptStateProvider notificationInterruptStateProvider,
      HeadsUpManager headsUpManager, NotificationRemoteInputManager remoteInputManager,
      StatusBarStateController statusBarStateController,
      VisualStabilityManager visualStabilityManager, NotificationListener notificationListener) {
    return new HeadsUpController(headsUpViewBinder, notificationInterruptStateProvider, headsUpManager, remoteInputManager, statusBarStateController, visualStabilityManager, notificationListener);
  }
}
