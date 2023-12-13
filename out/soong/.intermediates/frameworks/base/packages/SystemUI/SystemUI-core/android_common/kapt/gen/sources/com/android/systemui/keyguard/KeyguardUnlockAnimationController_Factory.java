package com.android.systemui.keyguard;

import android.content.Context;
import com.android.keyguard.KeyguardViewController;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class KeyguardUnlockAnimationController_Factory implements Factory<KeyguardUnlockAnimationController> {
  private final Provider<Context> contextProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<KeyguardViewController> keyguardViewControllerProvider;

  private final Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  public KeyguardUnlockAnimationController_Factory(Provider<Context> contextProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider) {
    this.contextProvider = contextProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.keyguardViewControllerProvider = keyguardViewControllerProvider;
    this.smartspaceTransitionControllerProvider = smartspaceTransitionControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
  }

  @Override
  public KeyguardUnlockAnimationController get() {
    return newInstance(contextProvider.get(), keyguardStateControllerProvider.get(), DoubleCheck.lazy(keyguardViewMediatorProvider), keyguardViewControllerProvider.get(), smartspaceTransitionControllerProvider.get(), featureFlagsProvider.get(), biometricUnlockControllerProvider.get());
  }

  public static KeyguardUnlockAnimationController_Factory create(Provider<Context> contextProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider) {
    return new KeyguardUnlockAnimationController_Factory(contextProvider, keyguardStateControllerProvider, keyguardViewMediatorProvider, keyguardViewControllerProvider, smartspaceTransitionControllerProvider, featureFlagsProvider, biometricUnlockControllerProvider);
  }

  public static KeyguardUnlockAnimationController newInstance(Context context,
      KeyguardStateController keyguardStateController,
      Lazy<KeyguardViewMediator> keyguardViewMediator,
      KeyguardViewController keyguardViewController,
      SmartspaceTransitionController smartspaceTransitionController, FeatureFlags featureFlags,
      BiometricUnlockController biometricUnlockController) {
    return new KeyguardUnlockAnimationController(context, keyguardStateController, keyguardViewMediator, keyguardViewController, smartspaceTransitionController, featureFlags, biometricUnlockController);
  }
}
