package com.android.systemui.statusbar.phone;

import android.app.KeyguardManager;
import android.content.Context;
import android.os.Handler;
import android.service.dreams.IDreamManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.widget.LockPatternUtils;
import com.android.systemui.ActivityIntentHelper;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationClickNotifier;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProvider;
import com.android.systemui.statusbar.notification.row.OnUserInteractionCallback;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.wmshell.BubblesManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class StatusBarNotificationActivityStarter_Builder_Factory implements Factory<StatusBarNotificationActivityStarter.Builder> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<Handler> mainThreadHandlerProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<NotificationClickNotifier> clickNotifierProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<KeyguardManager> keyguardManagerProvider;

  private final Provider<IDreamManager> dreamManagerProvider;

  private final Provider<Optional<BubblesManager>> bubblesManagerProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<GroupMembershipManager> groupMembershipManagerProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<StatusBarRemoteInputCallback> remoteInputCallbackProvider;

  private final Provider<ActivityIntentHelper> activityIntentHelperProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<StatusBarNotificationActivityStarterLogger> loggerProvider;

  private final Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider;

  public StatusBarNotificationActivityStarter_Builder_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<Handler> mainThreadHandlerProvider,
      Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<KeyguardManager> keyguardManagerProvider,
      Provider<IDreamManager> dreamManagerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<StatusBarRemoteInputCallback> remoteInputCallbackProvider,
      Provider<ActivityIntentHelper> activityIntentHelperProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarNotificationActivityStarterLogger> loggerProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.mainThreadHandlerProvider = mainThreadHandlerProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.clickNotifierProvider = clickNotifierProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.keyguardManagerProvider = keyguardManagerProvider;
    this.dreamManagerProvider = dreamManagerProvider;
    this.bubblesManagerProvider = bubblesManagerProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.groupMembershipManagerProvider = groupMembershipManagerProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.notificationInterruptStateProvider = notificationInterruptStateProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.remoteInputCallbackProvider = remoteInputCallbackProvider;
    this.activityIntentHelperProvider = activityIntentHelperProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.loggerProvider = loggerProvider;
    this.onUserInteractionCallbackProvider = onUserInteractionCallbackProvider;
  }

  @Override
  public StatusBarNotificationActivityStarter.Builder get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), mainThreadHandlerProvider.get(), uiBgExecutorProvider.get(), entryManagerProvider.get(), notifPipelineProvider.get(), headsUpManagerProvider.get(), activityStarterProvider.get(), clickNotifierProvider.get(), statusBarStateControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), keyguardManagerProvider.get(), dreamManagerProvider.get(), bubblesManagerProvider.get(), DoubleCheck.lazy(assistManagerLazyProvider), remoteInputManagerProvider.get(), groupMembershipManagerProvider.get(), lockscreenUserManagerProvider.get(), shadeControllerProvider.get(), keyguardStateControllerProvider.get(), notificationInterruptStateProvider.get(), lockPatternUtilsProvider.get(), remoteInputCallbackProvider.get(), activityIntentHelperProvider.get(), featureFlagsProvider.get(), metricsLoggerProvider.get(), loggerProvider.get(), onUserInteractionCallbackProvider.get());
  }

  public static StatusBarNotificationActivityStarter_Builder_Factory create(
      Provider<Context> contextProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<Handler> mainThreadHandlerProvider, Provider<Executor> uiBgExecutorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<KeyguardManager> keyguardManagerProvider,
      Provider<IDreamManager> dreamManagerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationInterruptStateProvider> notificationInterruptStateProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<StatusBarRemoteInputCallback> remoteInputCallbackProvider,
      Provider<ActivityIntentHelper> activityIntentHelperProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<MetricsLogger> metricsLoggerProvider,
      Provider<StatusBarNotificationActivityStarterLogger> loggerProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider) {
    return new StatusBarNotificationActivityStarter_Builder_Factory(contextProvider, commandQueueProvider, mainThreadHandlerProvider, uiBgExecutorProvider, entryManagerProvider, notifPipelineProvider, headsUpManagerProvider, activityStarterProvider, clickNotifierProvider, statusBarStateControllerProvider, statusBarKeyguardViewManagerProvider, keyguardManagerProvider, dreamManagerProvider, bubblesManagerProvider, assistManagerLazyProvider, remoteInputManagerProvider, groupMembershipManagerProvider, lockscreenUserManagerProvider, shadeControllerProvider, keyguardStateControllerProvider, notificationInterruptStateProvider, lockPatternUtilsProvider, remoteInputCallbackProvider, activityIntentHelperProvider, featureFlagsProvider, metricsLoggerProvider, loggerProvider, onUserInteractionCallbackProvider);
  }

  public static StatusBarNotificationActivityStarter.Builder newInstance(Context context,
      CommandQueue commandQueue, Handler mainThreadHandler, Executor uiBgExecutor,
      NotificationEntryManager entryManager, NotifPipeline notifPipeline,
      HeadsUpManagerPhone headsUpManager, ActivityStarter activityStarter,
      NotificationClickNotifier clickNotifier, StatusBarStateController statusBarStateController,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager, KeyguardManager keyguardManager,
      IDreamManager dreamManager, Optional<BubblesManager> bubblesManager,
      Lazy<AssistManager> assistManagerLazy, NotificationRemoteInputManager remoteInputManager,
      GroupMembershipManager groupMembershipManager,
      NotificationLockscreenUserManager lockscreenUserManager, ShadeController shadeController,
      KeyguardStateController keyguardStateController,
      NotificationInterruptStateProvider notificationInterruptStateProvider,
      LockPatternUtils lockPatternUtils, StatusBarRemoteInputCallback remoteInputCallback,
      ActivityIntentHelper activityIntentHelper, FeatureFlags featureFlags,
      MetricsLogger metricsLogger, StatusBarNotificationActivityStarterLogger logger,
      OnUserInteractionCallback onUserInteractionCallback) {
    return new StatusBarNotificationActivityStarter.Builder(context, commandQueue, mainThreadHandler, uiBgExecutor, entryManager, notifPipeline, headsUpManager, activityStarter, clickNotifier, statusBarStateController, statusBarKeyguardViewManager, keyguardManager, dreamManager, bubblesManager, assistManagerLazy, remoteInputManager, groupMembershipManager, lockscreenUserManager, shadeController, keyguardStateController, notificationInterruptStateProvider, lockPatternUtils, remoteInputCallback, activityIntentHelper, featureFlags, metricsLogger, logger, onUserInteractionCallback);
  }
}
