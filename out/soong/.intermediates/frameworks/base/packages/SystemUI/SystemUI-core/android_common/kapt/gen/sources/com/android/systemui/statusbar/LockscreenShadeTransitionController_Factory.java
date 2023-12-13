package com.android.systemui.statusbar;

import android.content.Context;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.media.MediaHierarchyManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.notification.stack.AmbientState;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.LSShadeTransitionLogger;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class LockscreenShadeTransitionController_Factory implements Factory<LockscreenShadeTransitionController> {
  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<LSShadeTransitionLogger> loggerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<AmbientState> ambientStateProvider;

  private final Provider<MediaHierarchyManager> mediaHierarchyManagerProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<NotificationShadeDepthController> depthControllerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public LockscreenShadeTransitionController_Factory(
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<LSShadeTransitionLogger> loggerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<AmbientState> ambientStateProvider,
      Provider<MediaHierarchyManager> mediaHierarchyManagerProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<NotificationShadeDepthController> depthControllerProvider,
      Provider<Context> contextProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.loggerProvider = loggerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.lockScreenUserManagerProvider = lockScreenUserManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.ambientStateProvider = ambientStateProvider;
    this.mediaHierarchyManagerProvider = mediaHierarchyManagerProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.depthControllerProvider = depthControllerProvider;
    this.contextProvider = contextProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public LockscreenShadeTransitionController get() {
    return newInstance(statusBarStateControllerProvider.get(), loggerProvider.get(), keyguardBypassControllerProvider.get(), lockScreenUserManagerProvider.get(), falsingCollectorProvider.get(), ambientStateProvider.get(), mediaHierarchyManagerProvider.get(), scrimControllerProvider.get(), depthControllerProvider.get(), contextProvider.get(), wakefulnessLifecycleProvider.get(), configurationControllerProvider.get(), falsingManagerProvider.get(), dumpManagerProvider.get());
  }

  public static LockscreenShadeTransitionController_Factory create(
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<LSShadeTransitionLogger> loggerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationLockscreenUserManager> lockScreenUserManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<AmbientState> ambientStateProvider,
      Provider<MediaHierarchyManager> mediaHierarchyManagerProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<NotificationShadeDepthController> depthControllerProvider,
      Provider<Context> contextProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new LockscreenShadeTransitionController_Factory(statusBarStateControllerProvider, loggerProvider, keyguardBypassControllerProvider, lockScreenUserManagerProvider, falsingCollectorProvider, ambientStateProvider, mediaHierarchyManagerProvider, scrimControllerProvider, depthControllerProvider, contextProvider, wakefulnessLifecycleProvider, configurationControllerProvider, falsingManagerProvider, dumpManagerProvider);
  }

  public static LockscreenShadeTransitionController newInstance(
      SysuiStatusBarStateController statusBarStateController, LSShadeTransitionLogger logger,
      KeyguardBypassController keyguardBypassController,
      NotificationLockscreenUserManager lockScreenUserManager, FalsingCollector falsingCollector,
      AmbientState ambientState, MediaHierarchyManager mediaHierarchyManager,
      ScrimController scrimController, NotificationShadeDepthController depthController,
      Context context, WakefulnessLifecycle wakefulnessLifecycle,
      ConfigurationController configurationController, FalsingManager falsingManager,
      DumpManager dumpManager) {
    return new LockscreenShadeTransitionController(statusBarStateController, logger, keyguardBypassController, lockScreenUserManager, falsingCollector, ambientState, mediaHierarchyManager, scrimController, depthController, context, wakefulnessLifecycle, configurationController, falsingManager, dumpManager);
  }
}
