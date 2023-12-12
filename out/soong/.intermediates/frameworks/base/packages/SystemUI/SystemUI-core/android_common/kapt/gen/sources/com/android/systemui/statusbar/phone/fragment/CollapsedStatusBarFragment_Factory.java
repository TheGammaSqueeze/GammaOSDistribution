package com.android.systemui.statusbar.phone.fragment;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.OperatorNameViewController;
import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
import com.android.systemui.statusbar.phone.NotificationPanelViewController;
import com.android.systemui.statusbar.phone.StatusBarHideIconsForBouncerManager;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher;
import com.android.systemui.statusbar.phone.fragment.dagger.StatusBarFragmentComponent;
import com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.SecureSettings;
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
public final class CollapsedStatusBarFragment_Factory implements Factory<CollapsedStatusBarFragment> {
  private final Provider<StatusBarFragmentComponent.Factory> statusBarFragmentComponentFactoryProvider;

  private final Provider<OngoingCallController> ongoingCallControllerProvider;

  private final Provider<SystemStatusAnimationScheduler> animationSchedulerProvider;

  private final Provider<StatusBarLocationPublisher> locationPublisherProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<StatusBarIconController> statusBarIconControllerProvider;

  private final Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider;

  private final Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<Executor> mainExecutorProvider;

  public CollapsedStatusBarFragment_Factory(
      Provider<StatusBarFragmentComponent.Factory> statusBarFragmentComponentFactoryProvider,
      Provider<OngoingCallController> ongoingCallControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider,
      Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> mainExecutorProvider) {
    this.statusBarFragmentComponentFactoryProvider = statusBarFragmentComponentFactoryProvider;
    this.ongoingCallControllerProvider = ongoingCallControllerProvider;
    this.animationSchedulerProvider = animationSchedulerProvider;
    this.locationPublisherProvider = locationPublisherProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.statusBarIconControllerProvider = statusBarIconControllerProvider;
    this.statusBarHideIconsForBouncerManagerProvider = statusBarHideIconsForBouncerManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.collapsedStatusBarFragmentLoggerProvider = collapsedStatusBarFragmentLoggerProvider;
    this.operatorNameViewControllerFactoryProvider = operatorNameViewControllerFactoryProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public CollapsedStatusBarFragment get() {
    return newInstance(statusBarFragmentComponentFactoryProvider.get(), ongoingCallControllerProvider.get(), animationSchedulerProvider.get(), locationPublisherProvider.get(), notificationIconAreaControllerProvider.get(), panelExpansionStateManagerProvider.get(), featureFlagsProvider.get(), statusBarIconControllerProvider.get(), statusBarHideIconsForBouncerManagerProvider.get(), keyguardStateControllerProvider.get(), notificationPanelViewControllerProvider.get(), networkControllerProvider.get(), statusBarStateControllerProvider.get(), commandQueueProvider.get(), collapsedStatusBarFragmentLoggerProvider.get(), operatorNameViewControllerFactoryProvider.get(), secureSettingsProvider.get(), mainExecutorProvider.get());
  }

  public static CollapsedStatusBarFragment_Factory create(
      Provider<StatusBarFragmentComponent.Factory> statusBarFragmentComponentFactoryProvider,
      Provider<OngoingCallController> ongoingCallControllerProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider,
      Provider<OperatorNameViewController.Factory> operatorNameViewControllerFactoryProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<Executor> mainExecutorProvider) {
    return new CollapsedStatusBarFragment_Factory(statusBarFragmentComponentFactoryProvider, ongoingCallControllerProvider, animationSchedulerProvider, locationPublisherProvider, notificationIconAreaControllerProvider, panelExpansionStateManagerProvider, featureFlagsProvider, statusBarIconControllerProvider, statusBarHideIconsForBouncerManagerProvider, keyguardStateControllerProvider, notificationPanelViewControllerProvider, networkControllerProvider, statusBarStateControllerProvider, commandQueueProvider, collapsedStatusBarFragmentLoggerProvider, operatorNameViewControllerFactoryProvider, secureSettingsProvider, mainExecutorProvider);
  }

  public static CollapsedStatusBarFragment newInstance(
      StatusBarFragmentComponent.Factory statusBarFragmentComponentFactory,
      OngoingCallController ongoingCallController,
      SystemStatusAnimationScheduler animationScheduler,
      StatusBarLocationPublisher locationPublisher,
      NotificationIconAreaController notificationIconAreaController,
      PanelExpansionStateManager panelExpansionStateManager, FeatureFlags featureFlags,
      StatusBarIconController statusBarIconController,
      StatusBarHideIconsForBouncerManager statusBarHideIconsForBouncerManager,
      KeyguardStateController keyguardStateController,
      NotificationPanelViewController notificationPanelViewController,
      NetworkController networkController, StatusBarStateController statusBarStateController,
      CommandQueue commandQueue, CollapsedStatusBarFragmentLogger collapsedStatusBarFragmentLogger,
      OperatorNameViewController.Factory operatorNameViewControllerFactory,
      SecureSettings secureSettings, Executor mainExecutor) {
    return new CollapsedStatusBarFragment(statusBarFragmentComponentFactory, ongoingCallController, animationScheduler, locationPublisher, notificationIconAreaController, panelExpansionStateManager, featureFlags, statusBarIconController, statusBarHideIconsForBouncerManager, keyguardStateController, notificationPanelViewController, networkController, statusBarStateController, commandQueue, collapsedStatusBarFragmentLogger, operatorNameViewControllerFactory, secureSettings, mainExecutor);
  }
}
