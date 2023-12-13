package com.android.systemui.dagger;

import android.app.INotificationManager;
import android.content.Context;
import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.model.SysUiState;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProvider;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.ZenModeController;
import com.android.systemui.wmshell.BubblesManager;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class SystemUIModule_ProvideBubblesManagerFactory implements Factory<Optional<BubblesManager>> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<INotificationManager> notificationManagerProvider;

  private final Provider<NotificationInterruptStateProvider> interruptionStateProvider;

  private final Provider<ZenModeController> zenModeControllerProvider;

  private final Provider<NotificationLockscreenUserManager> notifUserManagerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Executor> sysuiMainExecutorProvider;

  public SystemUIModule_ProvideBubblesManagerFactory(Provider<Context> contextProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<INotificationManager> notificationManagerProvider,
      Provider<NotificationInterruptStateProvider> interruptionStateProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<NotificationLockscreenUserManager> notifUserManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<SysUiState> sysUiStateProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Executor> sysuiMainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.interruptionStateProvider = interruptionStateProvider;
    this.zenModeControllerProvider = zenModeControllerProvider;
    this.notifUserManagerProvider = notifUserManagerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.sysuiMainExecutorProvider = sysuiMainExecutorProvider;
  }

  @Override
  public Optional<BubblesManager> get() {
    return provideBubblesManager(contextProvider.get(), bubblesOptionalProvider.get(), notificationShadeWindowControllerProvider.get(), statusBarStateControllerProvider.get(), shadeControllerProvider.get(), configurationControllerProvider.get(), statusBarServiceProvider.get(), notificationManagerProvider.get(), interruptionStateProvider.get(), zenModeControllerProvider.get(), notifUserManagerProvider.get(), groupManagerProvider.get(), entryManagerProvider.get(), notifPipelineProvider.get(), sysUiStateProvider.get(), featureFlagsProvider.get(), dumpManagerProvider.get(), sysuiMainExecutorProvider.get());
  }

  public static SystemUIModule_ProvideBubblesManagerFactory create(
      Provider<Context> contextProvider, Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<INotificationManager> notificationManagerProvider,
      Provider<NotificationInterruptStateProvider> interruptionStateProvider,
      Provider<ZenModeController> zenModeControllerProvider,
      Provider<NotificationLockscreenUserManager> notifUserManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider, Provider<SysUiState> sysUiStateProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Executor> sysuiMainExecutorProvider) {
    return new SystemUIModule_ProvideBubblesManagerFactory(contextProvider, bubblesOptionalProvider, notificationShadeWindowControllerProvider, statusBarStateControllerProvider, shadeControllerProvider, configurationControllerProvider, statusBarServiceProvider, notificationManagerProvider, interruptionStateProvider, zenModeControllerProvider, notifUserManagerProvider, groupManagerProvider, entryManagerProvider, notifPipelineProvider, sysUiStateProvider, featureFlagsProvider, dumpManagerProvider, sysuiMainExecutorProvider);
  }

  public static Optional<BubblesManager> provideBubblesManager(Context context,
      Optional<Bubbles> bubblesOptional,
      NotificationShadeWindowController notificationShadeWindowController,
      StatusBarStateController statusBarStateController, ShadeController shadeController,
      ConfigurationController configurationController, IStatusBarService statusBarService,
      INotificationManager notificationManager,
      NotificationInterruptStateProvider interruptionStateProvider,
      ZenModeController zenModeController, NotificationLockscreenUserManager notifUserManager,
      NotificationGroupManagerLegacy groupManager, NotificationEntryManager entryManager,
      NotifPipeline notifPipeline, SysUiState sysUiState, FeatureFlags featureFlags,
      DumpManager dumpManager, Executor sysuiMainExecutor) {
    return Preconditions.checkNotNullFromProvides(SystemUIModule.provideBubblesManager(context, bubblesOptional, notificationShadeWindowController, statusBarStateController, shadeController, configurationController, statusBarService, notificationManager, interruptionStateProvider, zenModeController, notifUserManager, groupManager, entryManager, notifPipeline, sysUiState, featureFlags, dumpManager, sysuiMainExecutor));
  }
}
