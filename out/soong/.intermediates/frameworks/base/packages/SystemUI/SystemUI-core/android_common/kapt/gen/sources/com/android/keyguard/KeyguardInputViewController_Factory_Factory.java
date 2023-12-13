package com.android.keyguard;

import android.content.res.Resources;
import android.telephony.TelephonyManager;
import android.view.inputmethod.InputMethodManager;
import com.android.internal.util.LatencyTracker;
import com.android.internal.widget.LockPatternUtils;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.statusbar.policy.DevicePostureController;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class KeyguardInputViewController_Factory_Factory implements Factory<KeyguardInputViewController.Factory> {
  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<LatencyTracker> latencyTrackerProvider;

  private final Provider<KeyguardMessageAreaController.Factory> messageAreaControllerFactoryProvider;

  private final Provider<InputMethodManager> inputMethodManagerProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<LiftToActivateListener> liftToActivateListenerProvider;

  private final Provider<TelephonyManager> telephonyManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider;

  private final Provider<DevicePostureController> devicePostureControllerProvider;

  public KeyguardInputViewController_Factory_Factory(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<LatencyTracker> latencyTrackerProvider,
      Provider<KeyguardMessageAreaController.Factory> messageAreaControllerFactoryProvider,
      Provider<InputMethodManager> inputMethodManagerProvider,
      Provider<DelayableExecutor> mainExecutorProvider, Provider<Resources> resourcesProvider,
      Provider<LiftToActivateListener> liftToActivateListenerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.latencyTrackerProvider = latencyTrackerProvider;
    this.messageAreaControllerFactoryProvider = messageAreaControllerFactoryProvider;
    this.inputMethodManagerProvider = inputMethodManagerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.resourcesProvider = resourcesProvider;
    this.liftToActivateListenerProvider = liftToActivateListenerProvider;
    this.telephonyManagerProvider = telephonyManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.emergencyButtonControllerFactoryProvider = emergencyButtonControllerFactoryProvider;
    this.devicePostureControllerProvider = devicePostureControllerProvider;
  }

  @Override
  public KeyguardInputViewController.Factory get() {
    return newInstance(keyguardUpdateMonitorProvider.get(), lockPatternUtilsProvider.get(), latencyTrackerProvider.get(), messageAreaControllerFactoryProvider.get(), inputMethodManagerProvider.get(), mainExecutorProvider.get(), resourcesProvider.get(), liftToActivateListenerProvider.get(), telephonyManagerProvider.get(), falsingCollectorProvider.get(), emergencyButtonControllerFactoryProvider.get(), devicePostureControllerProvider.get());
  }

  public static KeyguardInputViewController_Factory_Factory create(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<LatencyTracker> latencyTrackerProvider,
      Provider<KeyguardMessageAreaController.Factory> messageAreaControllerFactoryProvider,
      Provider<InputMethodManager> inputMethodManagerProvider,
      Provider<DelayableExecutor> mainExecutorProvider, Provider<Resources> resourcesProvider,
      Provider<LiftToActivateListener> liftToActivateListenerProvider,
      Provider<TelephonyManager> telephonyManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider,
      Provider<DevicePostureController> devicePostureControllerProvider) {
    return new KeyguardInputViewController_Factory_Factory(keyguardUpdateMonitorProvider, lockPatternUtilsProvider, latencyTrackerProvider, messageAreaControllerFactoryProvider, inputMethodManagerProvider, mainExecutorProvider, resourcesProvider, liftToActivateListenerProvider, telephonyManagerProvider, falsingCollectorProvider, emergencyButtonControllerFactoryProvider, devicePostureControllerProvider);
  }

  public static KeyguardInputViewController.Factory newInstance(
      KeyguardUpdateMonitor keyguardUpdateMonitor, LockPatternUtils lockPatternUtils,
      LatencyTracker latencyTracker,
      KeyguardMessageAreaController.Factory messageAreaControllerFactory,
      InputMethodManager inputMethodManager, DelayableExecutor mainExecutor, Resources resources,
      Object liftToActivateListener, TelephonyManager telephonyManager,
      FalsingCollector falsingCollector,
      EmergencyButtonController.Factory emergencyButtonControllerFactory,
      DevicePostureController devicePostureController) {
    return new KeyguardInputViewController.Factory(keyguardUpdateMonitor, lockPatternUtils, latencyTracker, messageAreaControllerFactory, inputMethodManager, mainExecutor, resources, (LiftToActivateListener) liftToActivateListener, telephonyManager, falsingCollector, emergencyButtonControllerFactory, devicePostureController);
  }
}
