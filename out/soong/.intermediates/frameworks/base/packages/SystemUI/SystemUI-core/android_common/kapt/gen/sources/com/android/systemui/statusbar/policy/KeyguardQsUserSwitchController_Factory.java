package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.content.res.Resources;
import android.widget.FrameLayout;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.tiles.UserDetailView;
import com.android.systemui.qs.user.UserSwitchDialogController;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
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
public final class KeyguardQsUserSwitchController_Factory implements Factory<KeyguardQsUserSwitchController> {
  private final Provider<FrameLayout> viewProvider;

  private final Provider<Context> contextProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<UserSwitcherController> userSwitcherControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<UserDetailView.Adapter> userDetailViewAdapterProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<UserSwitchDialogController> userSwitchDialogControllerProvider;

  public KeyguardQsUserSwitchController_Factory(Provider<FrameLayout> viewProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<UserSwitchDialogController> userSwitchDialogControllerProvider) {
    this.viewProvider = viewProvider;
    this.contextProvider = contextProvider;
    this.resourcesProvider = resourcesProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.userSwitcherControllerProvider = userSwitcherControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.userDetailViewAdapterProvider = userDetailViewAdapterProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.userSwitchDialogControllerProvider = userSwitchDialogControllerProvider;
  }

  @Override
  public KeyguardQsUserSwitchController get() {
    return newInstance(viewProvider.get(), contextProvider.get(), resourcesProvider.get(), screenLifecycleProvider.get(), userSwitcherControllerProvider.get(), keyguardStateControllerProvider.get(), falsingManagerProvider.get(), configurationControllerProvider.get(), statusBarStateControllerProvider.get(), dozeParametersProvider.get(), userDetailViewAdapterProvider, unlockedScreenOffAnimationControllerProvider.get(), featureFlagsProvider.get(), userSwitchDialogControllerProvider.get());
  }

  public static KeyguardQsUserSwitchController_Factory create(Provider<FrameLayout> viewProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<UserSwitchDialogController> userSwitchDialogControllerProvider) {
    return new KeyguardQsUserSwitchController_Factory(viewProvider, contextProvider, resourcesProvider, screenLifecycleProvider, userSwitcherControllerProvider, keyguardStateControllerProvider, falsingManagerProvider, configurationControllerProvider, statusBarStateControllerProvider, dozeParametersProvider, userDetailViewAdapterProvider, unlockedScreenOffAnimationControllerProvider, featureFlagsProvider, userSwitchDialogControllerProvider);
  }

  public static KeyguardQsUserSwitchController newInstance(FrameLayout view, Context context,
      Resources resources, ScreenLifecycle screenLifecycle,
      UserSwitcherController userSwitcherController,
      KeyguardStateController keyguardStateController, FalsingManager falsingManager,
      ConfigurationController configurationController,
      SysuiStatusBarStateController statusBarStateController, DozeParameters dozeParameters,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      FeatureFlags featureFlags, UserSwitchDialogController userSwitchDialogController) {
    return new KeyguardQsUserSwitchController(view, context, resources, screenLifecycle, userSwitcherController, keyguardStateController, falsingManager, configurationController, statusBarStateController, dozeParameters, userDetailViewAdapterProvider, unlockedScreenOffAnimationController, featureFlags, userSwitchDialogController);
  }
}
