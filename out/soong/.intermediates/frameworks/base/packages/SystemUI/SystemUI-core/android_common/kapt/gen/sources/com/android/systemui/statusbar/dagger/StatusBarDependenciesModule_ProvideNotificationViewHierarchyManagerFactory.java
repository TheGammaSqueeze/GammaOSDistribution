package com.android.systemui.statusbar.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationViewHierarchyManager;
import com.android.systemui.statusbar.notification.AssistantFeedbackController;
import com.android.systemui.statusbar.notification.DynamicChildBindController;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.inflation.LowPriorityInflationHelper;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.stack.ForegroundServiceSectionController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.wm.shell.bubbles.Bubbles;
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
public final class StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory implements Factory<NotificationViewHierarchyManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<DynamicPrivacyController> privacyControllerProvider;

  private final Provider<ForegroundServiceSectionController> fgsSectionControllerProvider;

  private final Provider<DynamicChildBindController> dynamicChildBindControllerProvider;

  private final Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider;

  private final Provider<AssistantFeedbackController> assistantFeedbackControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  public StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory(
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DynamicPrivacyController> privacyControllerProvider,
      Provider<ForegroundServiceSectionController> fgsSectionControllerProvider,
      Provider<DynamicChildBindController> dynamicChildBindControllerProvider,
      Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider,
      Provider<AssistantFeedbackController> assistantFeedbackControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.privacyControllerProvider = privacyControllerProvider;
    this.fgsSectionControllerProvider = fgsSectionControllerProvider;
    this.dynamicChildBindControllerProvider = dynamicChildBindControllerProvider;
    this.lowPriorityInflationHelperProvider = lowPriorityInflationHelperProvider;
    this.assistantFeedbackControllerProvider = assistantFeedbackControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
  }

  @Override
  public NotificationViewHierarchyManager get() {
    return provideNotificationViewHierarchyManager(contextProvider.get(), mainHandlerProvider.get(), featureFlagsProvider.get(), notificationLockscreenUserManagerProvider.get(), groupManagerProvider.get(), visualStabilityManagerProvider.get(), statusBarStateControllerProvider.get(), notificationEntryManagerProvider.get(), bypassControllerProvider.get(), bubblesOptionalProvider.get(), privacyControllerProvider.get(), fgsSectionControllerProvider.get(), dynamicChildBindControllerProvider.get(), lowPriorityInflationHelperProvider.get(), assistantFeedbackControllerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardStateControllerProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory create(
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DynamicPrivacyController> privacyControllerProvider,
      Provider<ForegroundServiceSectionController> fgsSectionControllerProvider,
      Provider<DynamicChildBindController> dynamicChildBindControllerProvider,
      Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider,
      Provider<AssistantFeedbackController> assistantFeedbackControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider) {
    return new StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory(contextProvider, mainHandlerProvider, featureFlagsProvider, notificationLockscreenUserManagerProvider, groupManagerProvider, visualStabilityManagerProvider, statusBarStateControllerProvider, notificationEntryManagerProvider, bypassControllerProvider, bubblesOptionalProvider, privacyControllerProvider, fgsSectionControllerProvider, dynamicChildBindControllerProvider, lowPriorityInflationHelperProvider, assistantFeedbackControllerProvider, keyguardUpdateMonitorProvider, keyguardStateControllerProvider);
  }

  public static NotificationViewHierarchyManager provideNotificationViewHierarchyManager(
      Context context, Handler mainHandler, FeatureFlags featureFlags,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotificationGroupManagerLegacy groupManager, VisualStabilityManager visualStabilityManager,
      StatusBarStateController statusBarStateController,
      NotificationEntryManager notificationEntryManager, KeyguardBypassController bypassController,
      Optional<Bubbles> bubblesOptional, DynamicPrivacyController privacyController,
      ForegroundServiceSectionController fgsSectionController,
      DynamicChildBindController dynamicChildBindController,
      LowPriorityInflationHelper lowPriorityInflationHelper,
      AssistantFeedbackController assistantFeedbackController,
      KeyguardUpdateMonitor keyguardUpdateMonitor,
      KeyguardStateController keyguardStateController) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideNotificationViewHierarchyManager(context, mainHandler, featureFlags, notificationLockscreenUserManager, groupManager, visualStabilityManager, statusBarStateController, notificationEntryManager, bypassController, bubblesOptional, privacyController, fgsSectionController, dynamicChildBindController, lowPriorityInflationHelper, assistantFeedbackController, keyguardUpdateMonitor, keyguardStateController));
  }
}
