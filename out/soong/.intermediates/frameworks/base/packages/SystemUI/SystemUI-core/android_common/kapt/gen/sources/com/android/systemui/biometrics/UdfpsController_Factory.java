package com.android.systemui.biometrics;

import android.content.Context;
import android.hardware.display.DisplayManager;
import android.hardware.fingerprint.FingerprintManager;
import android.os.Handler;
import android.os.PowerManager;
import android.os.Vibrator;
import android.view.LayoutInflater;
import android.view.WindowManager;
import android.view.accessibility.AccessibilityManager;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager;
import com.android.systemui.statusbar.phone.SystemUIDialogManager;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.concurrency.Execution;
import com.android.systemui.util.time.SystemClock;
import dagger.internal.Factory;
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
public final class UdfpsController_Factory implements Factory<UdfpsController> {
  private final Provider<Context> contextProvider;

  private final Provider<Execution> executionProvider;

  private final Provider<LayoutInflater> inflaterProvider;

  private final Provider<FingerprintManager> fingerprintManagerProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DelayableExecutor> fgExecutorProvider;

  private final Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<Vibrator> vibratorProvider;

  private final Provider<UdfpsHapticsSimulator> udfpsHapticsSimulatorProvider;

  private final Provider<Optional<UdfpsHbmProvider>> hbmProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<DisplayManager> displayManagerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<SystemUIDialogManager> dialogManagerProvider;

  public UdfpsController_Factory(Provider<Context> contextProvider,
      Provider<Execution> executionProvider, Provider<LayoutInflater> inflaterProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DelayableExecutor> fgExecutorProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider, Provider<Vibrator> vibratorProvider,
      Provider<UdfpsHapticsSimulator> udfpsHapticsSimulatorProvider,
      Provider<Optional<UdfpsHbmProvider>> hbmProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<DisplayManager> displayManagerProvider, Provider<Handler> mainHandlerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemClock> systemClockProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider) {
    this.contextProvider = contextProvider;
    this.executionProvider = executionProvider;
    this.inflaterProvider = inflaterProvider;
    this.fingerprintManagerProvider = fingerprintManagerProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.fgExecutorProvider = fgExecutorProvider;
    this.panelExpansionStateManagerProvider = panelExpansionStateManagerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.lockscreenShadeTransitionControllerProvider = lockscreenShadeTransitionControllerProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.vibratorProvider = vibratorProvider;
    this.udfpsHapticsSimulatorProvider = udfpsHapticsSimulatorProvider;
    this.hbmProvider = hbmProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.displayManagerProvider = displayManagerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.systemClockProvider = systemClockProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.dialogManagerProvider = dialogManagerProvider;
  }

  @Override
  public UdfpsController get() {
    return newInstance(contextProvider.get(), executionProvider.get(), inflaterProvider.get(), fingerprintManagerProvider.get(), windowManagerProvider.get(), statusBarStateControllerProvider.get(), fgExecutorProvider.get(), panelExpansionStateManagerProvider.get(), statusBarKeyguardViewManagerProvider.get(), dumpManagerProvider.get(), keyguardUpdateMonitorProvider.get(), falsingManagerProvider.get(), powerManagerProvider.get(), accessibilityManagerProvider.get(), lockscreenShadeTransitionControllerProvider.get(), screenLifecycleProvider.get(), vibratorProvider.get(), udfpsHapticsSimulatorProvider.get(), hbmProvider.get(), keyguardStateControllerProvider.get(), keyguardBypassControllerProvider.get(), displayManagerProvider.get(), mainHandlerProvider.get(), configurationControllerProvider.get(), systemClockProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), dialogManagerProvider.get());
  }

  public static UdfpsController_Factory create(Provider<Context> contextProvider,
      Provider<Execution> executionProvider, Provider<LayoutInflater> inflaterProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DelayableExecutor> fgExecutorProvider,
      Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider, Provider<Vibrator> vibratorProvider,
      Provider<UdfpsHapticsSimulator> udfpsHapticsSimulatorProvider,
      Provider<Optional<UdfpsHbmProvider>> hbmProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<DisplayManager> displayManagerProvider, Provider<Handler> mainHandlerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SystemClock> systemClockProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider) {
    return new UdfpsController_Factory(contextProvider, executionProvider, inflaterProvider, fingerprintManagerProvider, windowManagerProvider, statusBarStateControllerProvider, fgExecutorProvider, panelExpansionStateManagerProvider, statusBarKeyguardViewManagerProvider, dumpManagerProvider, keyguardUpdateMonitorProvider, falsingManagerProvider, powerManagerProvider, accessibilityManagerProvider, lockscreenShadeTransitionControllerProvider, screenLifecycleProvider, vibratorProvider, udfpsHapticsSimulatorProvider, hbmProvider, keyguardStateControllerProvider, keyguardBypassControllerProvider, displayManagerProvider, mainHandlerProvider, configurationControllerProvider, systemClockProvider, unlockedScreenOffAnimationControllerProvider, dialogManagerProvider);
  }

  public static UdfpsController newInstance(Context context, Execution execution,
      LayoutInflater inflater, FingerprintManager fingerprintManager, WindowManager windowManager,
      StatusBarStateController statusBarStateController, DelayableExecutor fgExecutor,
      PanelExpansionStateManager panelExpansionStateManager,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager, DumpManager dumpManager,
      KeyguardUpdateMonitor keyguardUpdateMonitor, FalsingManager falsingManager,
      PowerManager powerManager, AccessibilityManager accessibilityManager,
      LockscreenShadeTransitionController lockscreenShadeTransitionController,
      ScreenLifecycle screenLifecycle, Vibrator vibrator,
      UdfpsHapticsSimulator udfpsHapticsSimulator, Optional<UdfpsHbmProvider> hbmProvider,
      KeyguardStateController keyguardStateController,
      KeyguardBypassController keyguardBypassController, DisplayManager displayManager,
      Handler mainHandler, ConfigurationController configurationController, SystemClock systemClock,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      SystemUIDialogManager dialogManager) {
    return new UdfpsController(context, execution, inflater, fingerprintManager, windowManager, statusBarStateController, fgExecutor, panelExpansionStateManager, statusBarKeyguardViewManager, dumpManager, keyguardUpdateMonitor, falsingManager, powerManager, accessibilityManager, lockscreenShadeTransitionController, screenLifecycle, vibrator, udfpsHapticsSimulator, hbmProvider, keyguardStateController, keyguardBypassController, displayManager, mainHandler, configurationController, systemClock, unlockedScreenOffAnimationController, dialogManager);
  }
}
