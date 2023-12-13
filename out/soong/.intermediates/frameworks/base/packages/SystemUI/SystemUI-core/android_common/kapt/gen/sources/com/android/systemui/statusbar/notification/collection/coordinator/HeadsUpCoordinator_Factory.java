package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProvider;
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
public final class HeadsUpCoordinator_Factory implements Factory<HeadsUpCoordinator> {
  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<HeadsUpViewBinder> headsUpViewBinderProvider;

  private final Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<NodeController> incomingHeaderControllerProvider;

  public HeadsUpCoordinator_Factory(Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<NodeController> incomingHeaderControllerProvider) {
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.headsUpViewBinderProvider = headsUpViewBinderProvider;
    this.notificationInterruptStateProvider = notificationInterruptStateProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.incomingHeaderControllerProvider = incomingHeaderControllerProvider;
  }

  @Override
  public HeadsUpCoordinator get() {
    return newInstance(headsUpManagerProvider.get(), headsUpViewBinderProvider.get(), notificationInterruptStateProvider.get(), remoteInputManagerProvider.get(), incomingHeaderControllerProvider.get());
  }

  public static HeadsUpCoordinator_Factory create(Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<HeadsUpViewBinder> headsUpViewBinderProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<NodeController> incomingHeaderControllerProvider) {
    return new HeadsUpCoordinator_Factory(headsUpManagerProvider, headsUpViewBinderProvider, notificationInterruptStateProvider, remoteInputManagerProvider, incomingHeaderControllerProvider);
  }

  public static HeadsUpCoordinator newInstance(HeadsUpManager headsUpManager,
      HeadsUpViewBinder headsUpViewBinder,
      NotificationInterruptStateProvider notificationInterruptStateProvider,
      NotificationRemoteInputManager remoteInputManager, NodeController incomingHeaderController) {
    return new HeadsUpCoordinator(headsUpManager, headsUpViewBinder, notificationInterruptStateProvider, remoteInputManager, incomingHeaderController);
  }
}
