package com.android.systemui.statusbar.notification.collection.coordinator;

import android.content.Context;
import android.os.Handler;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
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
public final class KeyguardCoordinator_Factory implements Factory<KeyguardCoordinator> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainThreadHandlerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<HighPriorityProvider> highPriorityProvider;

  public KeyguardCoordinator_Factory(Provider<Context> contextProvider,
      Provider<Handler> mainThreadHandlerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<HighPriorityProvider> highPriorityProvider) {
    this.contextProvider = contextProvider;
    this.mainThreadHandlerProvider = mainThreadHandlerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.highPriorityProvider = highPriorityProvider;
  }

  @Override
  public KeyguardCoordinator get() {
    return newInstance(contextProvider.get(), mainThreadHandlerProvider.get(), keyguardStateControllerProvider.get(), lockscreenUserManagerProvider.get(), broadcastDispatcherProvider.get(), statusBarStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), highPriorityProvider.get());
  }

  public static KeyguardCoordinator_Factory create(Provider<Context> contextProvider,
      Provider<Handler> mainThreadHandlerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<HighPriorityProvider> highPriorityProvider) {
    return new KeyguardCoordinator_Factory(contextProvider, mainThreadHandlerProvider, keyguardStateControllerProvider, lockscreenUserManagerProvider, broadcastDispatcherProvider, statusBarStateControllerProvider, keyguardUpdateMonitorProvider, highPriorityProvider);
  }

  public static KeyguardCoordinator newInstance(Context context, Handler mainThreadHandler,
      KeyguardStateController keyguardStateController,
      NotificationLockscreenUserManager lockscreenUserManager,
      BroadcastDispatcher broadcastDispatcher, StatusBarStateController statusBarStateController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, HighPriorityProvider highPriorityProvider) {
    return new KeyguardCoordinator(context, mainThreadHandler, keyguardStateController, lockscreenUserManager, broadcastDispatcher, statusBarStateController, keyguardUpdateMonitor, highPriorityProvider);
  }
}
