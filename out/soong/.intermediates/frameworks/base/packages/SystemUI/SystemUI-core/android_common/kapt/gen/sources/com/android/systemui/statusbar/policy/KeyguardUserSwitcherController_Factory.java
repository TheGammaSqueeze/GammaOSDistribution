package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.content.res.Resources;
import android.view.LayoutInflater;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.keyguard.ScreenLifecycle;
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
public final class KeyguardUserSwitcherController_Factory implements Factory<KeyguardUserSwitcherController> {
  private final Provider<KeyguardUserSwitcherView> keyguardUserSwitcherViewProvider;

  private final Provider<Context> contextProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<UserSwitcherController> userSwitcherControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  public KeyguardUserSwitcherController_Factory(
      Provider<KeyguardUserSwitcherView> keyguardUserSwitcherViewProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    this.keyguardUserSwitcherViewProvider = keyguardUserSwitcherViewProvider;
    this.contextProvider = contextProvider;
    this.resourcesProvider = resourcesProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.userSwitcherControllerProvider = userSwitcherControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
  }

  @Override
  public KeyguardUserSwitcherController get() {
    return newInstance(keyguardUserSwitcherViewProvider.get(), contextProvider.get(), resourcesProvider.get(), layoutInflaterProvider.get(), screenLifecycleProvider.get(), userSwitcherControllerProvider.get(), keyguardStateControllerProvider.get(), statusBarStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), dozeParametersProvider.get(), unlockedScreenOffAnimationControllerProvider.get());
  }

  public static KeyguardUserSwitcherController_Factory create(
      Provider<KeyguardUserSwitcherView> keyguardUserSwitcherViewProvider,
      Provider<Context> contextProvider, Provider<Resources> resourcesProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    return new KeyguardUserSwitcherController_Factory(keyguardUserSwitcherViewProvider, contextProvider, resourcesProvider, layoutInflaterProvider, screenLifecycleProvider, userSwitcherControllerProvider, keyguardStateControllerProvider, statusBarStateControllerProvider, keyguardUpdateMonitorProvider, dozeParametersProvider, unlockedScreenOffAnimationControllerProvider);
  }

  public static KeyguardUserSwitcherController newInstance(
      KeyguardUserSwitcherView keyguardUserSwitcherView, Context context, Resources resources,
      LayoutInflater layoutInflater, ScreenLifecycle screenLifecycle,
      UserSwitcherController userSwitcherController,
      KeyguardStateController keyguardStateController,
      SysuiStatusBarStateController statusBarStateController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DozeParameters dozeParameters,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
    return new KeyguardUserSwitcherController(keyguardUserSwitcherView, context, resources, layoutInflater, screenLifecycle, userSwitcherController, keyguardStateController, statusBarStateController, keyguardUpdateMonitor, dozeParameters, unlockedScreenOffAnimationController);
  }
}
