package com.android.systemui.statusbar;

import android.content.Context;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
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
public final class PulseExpansionHandler_Factory implements Factory<PulseExpansionHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<NotificationRoundnessManager> roundnessManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public PulseExpansionHandler_Factory(Provider<Context> contextProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationRoundnessManager> roundnessManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.wakeUpCoordinatorProvider = wakeUpCoordinatorProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.roundnessManagerProvider = roundnessManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.lockscreenShadeTransitionControllerProvider = lockscreenShadeTransitionControllerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public PulseExpansionHandler get() {
    return newInstance(contextProvider.get(), wakeUpCoordinatorProvider.get(), bypassControllerProvider.get(), headsUpManagerProvider.get(), roundnessManagerProvider.get(), configurationControllerProvider.get(), statusBarStateControllerProvider.get(), falsingManagerProvider.get(), lockscreenShadeTransitionControllerProvider.get(), falsingCollectorProvider.get(), dumpManagerProvider.get());
  }

  public static PulseExpansionHandler_Factory create(Provider<Context> contextProvider,
      Provider<NotificationWakeUpCoordinator> wakeUpCoordinatorProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationRoundnessManager> roundnessManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new PulseExpansionHandler_Factory(contextProvider, wakeUpCoordinatorProvider, bypassControllerProvider, headsUpManagerProvider, roundnessManagerProvider, configurationControllerProvider, statusBarStateControllerProvider, falsingManagerProvider, lockscreenShadeTransitionControllerProvider, falsingCollectorProvider, dumpManagerProvider);
  }

  public static PulseExpansionHandler newInstance(Context context,
      NotificationWakeUpCoordinator wakeUpCoordinator, KeyguardBypassController bypassController,
      HeadsUpManagerPhone headsUpManager, NotificationRoundnessManager roundnessManager,
      ConfigurationController configurationController,
      StatusBarStateController statusBarStateController, FalsingManager falsingManager,
      LockscreenShadeTransitionController lockscreenShadeTransitionController,
      FalsingCollector falsingCollector, DumpManager dumpManager) {
    return new PulseExpansionHandler(context, wakeUpCoordinator, bypassController, headsUpManager, roundnessManager, configurationController, statusBarStateController, falsingManager, lockscreenShadeTransitionController, falsingCollector, dumpManager);
  }
}
