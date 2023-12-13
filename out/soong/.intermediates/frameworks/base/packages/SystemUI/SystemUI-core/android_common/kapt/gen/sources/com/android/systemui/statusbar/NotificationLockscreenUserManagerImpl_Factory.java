package com.android.systemui.statusbar;

import android.app.KeyguardManager;
import android.app.admin.DevicePolicyManager;
import android.content.Context;
import android.os.Handler;
import android.os.UserManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
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
public final class NotificationLockscreenUserManagerImpl_Factory implements Factory<NotificationLockscreenUserManagerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DevicePolicyManager> devicePolicyManagerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<NotificationClickNotifier> clickNotifierProvider;

  private final Provider<KeyguardManager> keyguardManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationLockscreenUserManagerImpl_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<UserManager> userManagerProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<KeyguardManager> keyguardManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.devicePolicyManagerProvider = devicePolicyManagerProvider;
    this.userManagerProvider = userManagerProvider;
    this.clickNotifierProvider = clickNotifierProvider;
    this.keyguardManagerProvider = keyguardManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationLockscreenUserManagerImpl get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), devicePolicyManagerProvider.get(), userManagerProvider.get(), clickNotifierProvider.get(), keyguardManagerProvider.get(), statusBarStateControllerProvider.get(), mainHandlerProvider.get(), deviceProvisionedControllerProvider.get(), keyguardStateControllerProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationLockscreenUserManagerImpl_Factory create(
      Provider<Context> contextProvider, Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<UserManager> userManagerProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<KeyguardManager> keyguardManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotificationLockscreenUserManagerImpl_Factory(contextProvider, broadcastDispatcherProvider, devicePolicyManagerProvider, userManagerProvider, clickNotifierProvider, keyguardManagerProvider, statusBarStateControllerProvider, mainHandlerProvider, deviceProvisionedControllerProvider, keyguardStateControllerProvider, dumpManagerProvider);
  }

  public static NotificationLockscreenUserManagerImpl newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, DevicePolicyManager devicePolicyManager,
      UserManager userManager, NotificationClickNotifier clickNotifier,
      KeyguardManager keyguardManager, StatusBarStateController statusBarStateController,
      Handler mainHandler, DeviceProvisionedController deviceProvisionedController,
      KeyguardStateController keyguardStateController, DumpManager dumpManager) {
    return new NotificationLockscreenUserManagerImpl(context, broadcastDispatcher, devicePolicyManager, userManager, clickNotifier, keyguardManager, statusBarStateController, mainHandler, deviceProvisionedController, keyguardStateController, dumpManager);
  }
}
