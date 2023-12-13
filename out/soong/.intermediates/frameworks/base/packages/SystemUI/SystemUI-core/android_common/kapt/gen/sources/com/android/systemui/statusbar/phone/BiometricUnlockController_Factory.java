package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.content.res.Resources;
import android.os.Handler;
import android.os.PowerManager;
import com.android.internal.logging.MetricsLogger;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
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
public final class BiometricUnlockController_Factory implements Factory<BiometricUnlockController> {
  private final Provider<Context> contextProvider;

  private final Provider<DozeScrimController> dozeScrimControllerProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<ScrimController> scrimControllerProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<NotificationMediaManager> notificationMediaManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public BiometricUnlockController_Factory(Provider<Context> contextProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<Resources> resourcesProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<AuthController> authControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.contextProvider = contextProvider;
    this.dozeScrimControllerProvider = dozeScrimControllerProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.scrimControllerProvider = scrimControllerProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.handlerProvider = handlerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.resourcesProvider = resourcesProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.notificationMediaManagerProvider = notificationMediaManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.authControllerProvider = authControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public BiometricUnlockController get() {
    return newInstance(contextProvider.get(), dozeScrimControllerProvider.get(), keyguardViewMediatorProvider.get(), scrimControllerProvider.get(), shadeControllerProvider.get(), notificationShadeWindowControllerProvider.get(), keyguardStateControllerProvider.get(), handlerProvider.get(), keyguardUpdateMonitorProvider.get(), resourcesProvider.get(), keyguardBypassControllerProvider.get(), dozeParametersProvider.get(), metricsLoggerProvider.get(), dumpManagerProvider.get(), powerManagerProvider.get(), notificationMediaManagerProvider.get(), wakefulnessLifecycleProvider.get(), screenLifecycleProvider.get(), authControllerProvider.get(), statusBarStateControllerProvider.get());
  }

  public static BiometricUnlockController_Factory create(Provider<Context> contextProvider,
      Provider<DozeScrimController> dozeScrimControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<ScrimController> scrimControllerProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<Handler> handlerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<Resources> resourcesProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<PowerManager> powerManagerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<AuthController> authControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new BiometricUnlockController_Factory(contextProvider, dozeScrimControllerProvider, keyguardViewMediatorProvider, scrimControllerProvider, shadeControllerProvider, notificationShadeWindowControllerProvider, keyguardStateControllerProvider, handlerProvider, keyguardUpdateMonitorProvider, resourcesProvider, keyguardBypassControllerProvider, dozeParametersProvider, metricsLoggerProvider, dumpManagerProvider, powerManagerProvider, notificationMediaManagerProvider, wakefulnessLifecycleProvider, screenLifecycleProvider, authControllerProvider, statusBarStateControllerProvider);
  }

  public static BiometricUnlockController newInstance(Context context,
      DozeScrimController dozeScrimController, KeyguardViewMediator keyguardViewMediator,
      ScrimController scrimController, ShadeController shadeController,
      NotificationShadeWindowController notificationShadeWindowController,
      KeyguardStateController keyguardStateController, Handler handler,
      KeyguardUpdateMonitor keyguardUpdateMonitor, Resources resources,
      KeyguardBypassController keyguardBypassController, DozeParameters dozeParameters,
      MetricsLogger metricsLogger, DumpManager dumpManager, PowerManager powerManager,
      NotificationMediaManager notificationMediaManager, WakefulnessLifecycle wakefulnessLifecycle,
      ScreenLifecycle screenLifecycle, AuthController authController,
      StatusBarStateController statusBarStateController) {
    return new BiometricUnlockController(context, dozeScrimController, keyguardViewMediator, scrimController, shadeController, notificationShadeWindowController, keyguardStateController, handler, keyguardUpdateMonitor, resources, keyguardBypassController, dozeParameters, metricsLogger, dumpManager, powerManager, notificationMediaManager, wakefulnessLifecycle, screenLifecycle, authController, statusBarStateController);
  }
}
