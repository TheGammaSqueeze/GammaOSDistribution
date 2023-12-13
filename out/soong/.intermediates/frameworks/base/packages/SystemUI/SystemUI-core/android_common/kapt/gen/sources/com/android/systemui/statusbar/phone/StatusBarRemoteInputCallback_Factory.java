package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.ActionClickLogger;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class StatusBarRemoteInputCallback_Factory implements Factory<StatusBarRemoteInputCallback> {
  private final Provider<Context> contextProvider;

  private final Provider<GroupExpansionManager> groupExpansionManagerProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ActionClickLogger> clickLoggerProvider;

  private final Provider<Executor> executorProvider;

  public StatusBarRemoteInputCallback_Factory(Provider<Context> contextProvider,
      Provider<GroupExpansionManager> groupExpansionManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<ActionClickLogger> clickLoggerProvider,
      Provider<Executor> executorProvider) {
    this.contextProvider = contextProvider;
    this.groupExpansionManagerProvider = groupExpansionManagerProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.clickLoggerProvider = clickLoggerProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public StatusBarRemoteInputCallback get() {
    return newInstance(contextProvider.get(), groupExpansionManagerProvider.get(), notificationLockscreenUserManagerProvider.get(), keyguardStateControllerProvider.get(), statusBarStateControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), activityStarterProvider.get(), shadeControllerProvider.get(), commandQueueProvider.get(), clickLoggerProvider.get(), executorProvider.get());
  }

  public static StatusBarRemoteInputCallback_Factory create(Provider<Context> contextProvider,
      Provider<GroupExpansionManager> groupExpansionManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<ActionClickLogger> clickLoggerProvider,
      Provider<Executor> executorProvider) {
    return new StatusBarRemoteInputCallback_Factory(contextProvider, groupExpansionManagerProvider, notificationLockscreenUserManagerProvider, keyguardStateControllerProvider, statusBarStateControllerProvider, statusBarKeyguardViewManagerProvider, activityStarterProvider, shadeControllerProvider, commandQueueProvider, clickLoggerProvider, executorProvider);
  }

  public static StatusBarRemoteInputCallback newInstance(Context context,
      GroupExpansionManager groupExpansionManager,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      KeyguardStateController keyguardStateController,
      StatusBarStateController statusBarStateController,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager, ActivityStarter activityStarter,
      ShadeController shadeController, CommandQueue commandQueue, ActionClickLogger clickLogger,
      Executor executor) {
    return new StatusBarRemoteInputCallback(context, groupExpansionManager, notificationLockscreenUserManager, keyguardStateController, statusBarStateController, statusBarKeyguardViewManager, activityStarter, shadeController, commandQueue, clickLogger, executor);
  }
}
