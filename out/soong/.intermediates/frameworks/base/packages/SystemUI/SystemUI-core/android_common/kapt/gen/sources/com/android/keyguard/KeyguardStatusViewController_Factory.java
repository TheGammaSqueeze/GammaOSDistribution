package com.android.keyguard;

import com.android.systemui.keyguard.KeyguardUnlockAnimationController;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class KeyguardStatusViewController_Factory implements Factory<KeyguardStatusViewController> {
  private final Provider<KeyguardStatusView> keyguardStatusViewProvider;

  private final Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider;

  private final Provider<KeyguardClockSwitchController> keyguardClockSwitchControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider;

  private final Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  public KeyguardStatusViewController_Factory(
      Provider<KeyguardStatusView> keyguardStatusViewProvider,
      Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider,
      Provider<KeyguardClockSwitchController> keyguardClockSwitchControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    this.keyguardStatusViewProvider = keyguardStatusViewProvider;
    this.keyguardSliceViewControllerProvider = keyguardSliceViewControllerProvider;
    this.keyguardClockSwitchControllerProvider = keyguardClockSwitchControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.keyguardUnlockAnimationControllerProvider = keyguardUnlockAnimationControllerProvider;
    this.smartspaceTransitionControllerProvider = smartspaceTransitionControllerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
  }

  @Override
  public KeyguardStatusViewController get() {
    return newInstance(keyguardStatusViewProvider.get(), keyguardSliceViewControllerProvider.get(), keyguardClockSwitchControllerProvider.get(), keyguardStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), configurationControllerProvider.get(), dozeParametersProvider.get(), keyguardUnlockAnimationControllerProvider.get(), smartspaceTransitionControllerProvider.get(), unlockedScreenOffAnimationControllerProvider.get());
  }

  public static KeyguardStatusViewController_Factory create(
      Provider<KeyguardStatusView> keyguardStatusViewProvider,
      Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider,
      Provider<KeyguardClockSwitchController> keyguardClockSwitchControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    return new KeyguardStatusViewController_Factory(keyguardStatusViewProvider, keyguardSliceViewControllerProvider, keyguardClockSwitchControllerProvider, keyguardStateControllerProvider, keyguardUpdateMonitorProvider, configurationControllerProvider, dozeParametersProvider, keyguardUnlockAnimationControllerProvider, smartspaceTransitionControllerProvider, unlockedScreenOffAnimationControllerProvider);
  }

  public static KeyguardStatusViewController newInstance(KeyguardStatusView keyguardStatusView,
      KeyguardSliceViewController keyguardSliceViewController,
      KeyguardClockSwitchController keyguardClockSwitchController,
      KeyguardStateController keyguardStateController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      ConfigurationController configurationController, DozeParameters dozeParameters,
      KeyguardUnlockAnimationController keyguardUnlockAnimationController,
      SmartspaceTransitionController smartspaceTransitionController,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
    return new KeyguardStatusViewController(keyguardStatusView, keyguardSliceViewController, keyguardClockSwitchController, keyguardStateController, keyguardUpdateMonitor, configurationController, dozeParameters, keyguardUnlockAnimationController, smartspaceTransitionController, unlockedScreenOffAnimationController);
  }
}
