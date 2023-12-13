package com.android.systemui.controls.dagger;

import android.content.Context;
import com.android.internal.widget.LockPatternUtils;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.SecureSettings;
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
public final class ControlsComponent_Factory implements Factory<ControlsComponent> {
  private final Provider<Boolean> featureEnabledProvider;

  private final Provider<Context> contextProvider;

  private final Provider<ControlsController> controlsControllerProvider;

  private final Provider<ControlsUiController> controlsUiControllerProvider;

  private final Provider<ControlsListingController> controlsListingControllerProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  public ControlsComponent_Factory(Provider<Boolean> featureEnabledProvider,
      Provider<Context> contextProvider, Provider<ControlsController> controlsControllerProvider,
      Provider<ControlsUiController> controlsUiControllerProvider,
      Provider<ControlsListingController> controlsListingControllerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<SecureSettings> secureSettingsProvider) {
    this.featureEnabledProvider = featureEnabledProvider;
    this.contextProvider = contextProvider;
    this.controlsControllerProvider = controlsControllerProvider;
    this.controlsUiControllerProvider = controlsUiControllerProvider;
    this.controlsListingControllerProvider = controlsListingControllerProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
  }

  @Override
  public ControlsComponent get() {
    return newInstance(featureEnabledProvider.get(), contextProvider.get(), DoubleCheck.lazy(controlsControllerProvider), DoubleCheck.lazy(controlsUiControllerProvider), DoubleCheck.lazy(controlsListingControllerProvider), lockPatternUtilsProvider.get(), keyguardStateControllerProvider.get(), userTrackerProvider.get(), secureSettingsProvider.get());
  }

  public static ControlsComponent_Factory create(Provider<Boolean> featureEnabledProvider,
      Provider<Context> contextProvider, Provider<ControlsController> controlsControllerProvider,
      Provider<ControlsUiController> controlsUiControllerProvider,
      Provider<ControlsListingController> controlsListingControllerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<SecureSettings> secureSettingsProvider) {
    return new ControlsComponent_Factory(featureEnabledProvider, contextProvider, controlsControllerProvider, controlsUiControllerProvider, controlsListingControllerProvider, lockPatternUtilsProvider, keyguardStateControllerProvider, userTrackerProvider, secureSettingsProvider);
  }

  public static ControlsComponent newInstance(boolean featureEnabled, Context context,
      Lazy<ControlsController> lazyControlsController,
      Lazy<ControlsUiController> lazyControlsUiController,
      Lazy<ControlsListingController> lazyControlsListingController,
      LockPatternUtils lockPatternUtils, KeyguardStateController keyguardStateController,
      UserTracker userTracker, SecureSettings secureSettings) {
    return new ControlsComponent(featureEnabled, context, lazyControlsController, lazyControlsUiController, lazyControlsListingController, lockPatternUtils, keyguardStateController, userTracker, secureSettings);
  }
}
