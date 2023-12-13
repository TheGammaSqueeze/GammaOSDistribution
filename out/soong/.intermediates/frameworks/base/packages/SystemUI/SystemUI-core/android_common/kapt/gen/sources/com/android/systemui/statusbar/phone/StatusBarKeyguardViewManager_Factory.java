package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.KeyguardMessageAreaController;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.ViewMediatorCallback;
import com.android.systemui.dock.DockManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class StatusBarKeyguardViewManager_Factory implements Factory<StatusBarKeyguardViewManager> {
  private final Provider<Context> contextProvider;

  private final Provider<ViewMediatorCallback> callbackProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<SysuiStatusBarStateController> sysuiStatusBarStateControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<NotificationMediaManager> notificationMediaManagerProvider;

  private final Provider<KeyguardBouncer.Factory> keyguardBouncerFactoryProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<KeyguardMessageAreaController.Factory> keyguardMessageAreaFactoryProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  public StatusBarKeyguardViewManager_Factory(Provider<Context> contextProvider,
      Provider<ViewMediatorCallback> callbackProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<SysuiStatusBarStateController> sysuiStatusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<KeyguardBouncer.Factory> keyguardBouncerFactoryProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<KeyguardMessageAreaController.Factory> keyguardMessageAreaFactoryProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    this.contextProvider = contextProvider;
    this.callbackProvider = callbackProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.sysuiStatusBarStateControllerProvider = sysuiStatusBarStateControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.notificationMediaManagerProvider = notificationMediaManagerProvider;
    this.keyguardBouncerFactoryProvider = keyguardBouncerFactoryProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.keyguardMessageAreaFactoryProvider = keyguardMessageAreaFactoryProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
  }

  @Override
  public StatusBarKeyguardViewManager get() {
    return newInstance(contextProvider.get(), callbackProvider.get(), lockPatternUtilsProvider.get(), sysuiStatusBarStateControllerProvider.get(), configurationControllerProvider.get(), keyguardUpdateMonitorProvider.get(), navigationModeControllerProvider.get(), dockManagerProvider.get(), notificationShadeWindowControllerProvider.get(), keyguardStateControllerProvider.get(), notificationMediaManagerProvider.get(), keyguardBouncerFactoryProvider.get(), wakefulnessLifecycleProvider.get(), unlockedScreenOffAnimationControllerProvider.get(), keyguardMessageAreaFactoryProvider.get(), DoubleCheck.lazy(shadeControllerProvider), DoubleCheck.lazy(statusBarOptionalLazyProvider));
  }

  public static StatusBarKeyguardViewManager_Factory create(Provider<Context> contextProvider,
      Provider<ViewMediatorCallback> callbackProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<SysuiStatusBarStateController> sysuiStatusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<NotificationMediaManager> notificationMediaManagerProvider,
      Provider<KeyguardBouncer.Factory> keyguardBouncerFactoryProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<KeyguardMessageAreaController.Factory> keyguardMessageAreaFactoryProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    return new StatusBarKeyguardViewManager_Factory(contextProvider, callbackProvider, lockPatternUtilsProvider, sysuiStatusBarStateControllerProvider, configurationControllerProvider, keyguardUpdateMonitorProvider, navigationModeControllerProvider, dockManagerProvider, notificationShadeWindowControllerProvider, keyguardStateControllerProvider, notificationMediaManagerProvider, keyguardBouncerFactoryProvider, wakefulnessLifecycleProvider, unlockedScreenOffAnimationControllerProvider, keyguardMessageAreaFactoryProvider, shadeControllerProvider, statusBarOptionalLazyProvider);
  }

  public static StatusBarKeyguardViewManager newInstance(Context context,
      ViewMediatorCallback callback, LockPatternUtils lockPatternUtils,
      SysuiStatusBarStateController sysuiStatusBarStateController,
      ConfigurationController configurationController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      NavigationModeController navigationModeController, DockManager dockManager,
      NotificationShadeWindowController notificationShadeWindowController,
      KeyguardStateController keyguardStateController,
      NotificationMediaManager notificationMediaManager,
      KeyguardBouncer.Factory keyguardBouncerFactory, WakefulnessLifecycle wakefulnessLifecycle,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      KeyguardMessageAreaController.Factory keyguardMessageAreaFactory,
      Lazy<ShadeController> shadeController, Lazy<Optional<StatusBar>> statusBarOptionalLazy) {
    return new StatusBarKeyguardViewManager(context, callback, lockPatternUtils, sysuiStatusBarStateController, configurationController, keyguardUpdateMonitor, navigationModeController, dockManager, notificationShadeWindowController, keyguardStateController, notificationMediaManager, keyguardBouncerFactory, wakefulnessLifecycle, unlockedScreenOffAnimationController, keyguardMessageAreaFactory, shadeController, statusBarOptionalLazy);
  }
}
