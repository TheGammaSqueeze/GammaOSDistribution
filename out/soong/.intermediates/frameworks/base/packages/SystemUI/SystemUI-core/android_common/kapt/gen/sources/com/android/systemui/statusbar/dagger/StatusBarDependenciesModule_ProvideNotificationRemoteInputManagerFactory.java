package com.android.systemui.statusbar.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.ActionClickLogger;
import com.android.systemui.statusbar.NotificationClickNotifier;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.RemoteInputUriController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory implements Factory<NotificationRemoteInputManager> {
  private final Provider<Context> contextProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<SmartReplyController> smartReplyControllerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<RemoteInputNotificationRebuilder> rebuilderProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<RemoteInputUriController> remoteInputUriControllerProvider;

  private final Provider<NotificationClickNotifier> clickNotifierProvider;

  private final Provider<ActionClickLogger> actionClickLoggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory(
      Provider<Context> contextProvider, Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<RemoteInputNotificationRebuilder> rebuilderProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<RemoteInputUriController> remoteInputUriControllerProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<ActionClickLogger> actionClickLoggerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.smartReplyControllerProvider = smartReplyControllerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.rebuilderProvider = rebuilderProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.remoteInputUriControllerProvider = remoteInputUriControllerProvider;
    this.clickNotifierProvider = clickNotifierProvider;
    this.actionClickLoggerProvider = actionClickLoggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationRemoteInputManager get() {
    return provideNotificationRemoteInputManager(contextProvider.get(), featureFlagsProvider.get(), lockscreenUserManagerProvider.get(), smartReplyControllerProvider.get(), notificationEntryManagerProvider.get(), rebuilderProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), statusBarStateControllerProvider.get(), mainHandlerProvider.get(), remoteInputUriControllerProvider.get(), clickNotifierProvider.get(), actionClickLoggerProvider.get(), dumpManagerProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory create(
      Provider<Context> contextProvider, Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<RemoteInputNotificationRebuilder> rebuilderProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<Handler> mainHandlerProvider,
      Provider<RemoteInputUriController> remoteInputUriControllerProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<ActionClickLogger> actionClickLoggerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory(contextProvider, featureFlagsProvider, lockscreenUserManagerProvider, smartReplyControllerProvider, notificationEntryManagerProvider, rebuilderProvider, statusBarOptionalLazyProvider, statusBarStateControllerProvider, mainHandlerProvider, remoteInputUriControllerProvider, clickNotifierProvider, actionClickLoggerProvider, dumpManagerProvider);
  }

  public static NotificationRemoteInputManager provideNotificationRemoteInputManager(
      Context context, FeatureFlags featureFlags,
      NotificationLockscreenUserManager lockscreenUserManager,
      SmartReplyController smartReplyController, NotificationEntryManager notificationEntryManager,
      RemoteInputNotificationRebuilder rebuilder, Lazy<Optional<StatusBar>> statusBarOptionalLazy,
      StatusBarStateController statusBarStateController, Handler mainHandler,
      RemoteInputUriController remoteInputUriController, NotificationClickNotifier clickNotifier,
      ActionClickLogger actionClickLogger, DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideNotificationRemoteInputManager(context, featureFlags, lockscreenUserManager, smartReplyController, notificationEntryManager, rebuilder, statusBarOptionalLazy, statusBarStateController, mainHandler, remoteInputUriController, clickNotifier, actionClickLogger, dumpManager));
  }
}
