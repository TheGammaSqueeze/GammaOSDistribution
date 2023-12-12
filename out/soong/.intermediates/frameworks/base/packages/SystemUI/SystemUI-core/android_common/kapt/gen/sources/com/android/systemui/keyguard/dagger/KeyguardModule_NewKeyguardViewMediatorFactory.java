package com.android.systemui.keyguard.dagger;

import android.app.trust.TrustManager;
import android.content.Context;
import android.os.PowerManager;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.KeyguardDisplayManager;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.KeyguardViewController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.DismissCallbackRegistry;
import com.android.systemui.keyguard.KeyguardUnlockAnimationController;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.UserSwitcherController;
import com.android.systemui.unfold.SysUIUnfoldComponent;
import com.android.systemui.util.DeviceConfigProxy;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class KeyguardModule_NewKeyguardViewMediatorFactory implements Factory<KeyguardViewMediator> {
  private final Provider<Context> contextProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<KeyguardViewController> statusBarKeyguardViewManagerLazyProvider;

  private final Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider;

  private final Provider<KeyguardUpdateMonitor> updateMonitorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<TrustManager> trustManagerProvider;

  private final Provider<UserSwitcherController> userSwitcherControllerProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<KeyguardDisplayManager> keyguardDisplayManagerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  private final Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  public KeyguardModule_NewKeyguardViewMediatorFactory(Provider<Context> contextProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<KeyguardViewController> statusBarKeyguardViewManagerLazyProvider,
      Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider,
      Provider<KeyguardUpdateMonitor> updateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<TrustManager> trustManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<DeviceConfigProxy> deviceConfigProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<KeyguardDisplayManager> keyguardDisplayManagerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider) {
    this.contextProvider = contextProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.statusBarKeyguardViewManagerLazyProvider = statusBarKeyguardViewManagerLazyProvider;
    this.dismissCallbackRegistryProvider = dismissCallbackRegistryProvider;
    this.updateMonitorProvider = updateMonitorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.trustManagerProvider = trustManagerProvider;
    this.userSwitcherControllerProvider = userSwitcherControllerProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.deviceConfigProvider = deviceConfigProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.keyguardDisplayManagerProvider = keyguardDisplayManagerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.unfoldComponentProvider = unfoldComponentProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardUnlockAnimationControllerProvider = keyguardUnlockAnimationControllerProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
    this.notificationShadeDepthControllerProvider = notificationShadeDepthControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
  }

  @Override
  public KeyguardViewMediator get() {
    return newKeyguardViewMediator(contextProvider.get(), falsingCollectorProvider.get(), lockPatternUtilsProvider.get(), broadcastDispatcherProvider.get(), DoubleCheck.lazy(statusBarKeyguardViewManagerLazyProvider), dismissCallbackRegistryProvider.get(), updateMonitorProvider.get(), dumpManagerProvider.get(), powerManagerProvider.get(), trustManagerProvider.get(), userSwitcherControllerProvider.get(), uiBgExecutorProvider.get(), deviceConfigProvider.get(), navigationModeControllerProvider.get(), keyguardDisplayManagerProvider.get(), dozeParametersProvider.get(), unfoldComponentProvider.get(), statusBarStateControllerProvider.get(), keyguardStateControllerProvider.get(), DoubleCheck.lazy(keyguardUnlockAnimationControllerProvider), unlockedScreenOffAnimationControllerProvider.get(), DoubleCheck.lazy(notificationShadeDepthControllerProvider), DoubleCheck.lazy(notificationShadeWindowControllerProvider));
  }

  public static KeyguardModule_NewKeyguardViewMediatorFactory create(
      Provider<Context> contextProvider, Provider<FalsingCollector> falsingCollectorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<KeyguardViewController> statusBarKeyguardViewManagerLazyProvider,
      Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider,
      Provider<KeyguardUpdateMonitor> updateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<PowerManager> powerManagerProvider,
      Provider<TrustManager> trustManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<Executor> uiBgExecutorProvider, Provider<DeviceConfigProxy> deviceConfigProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<KeyguardDisplayManager> keyguardDisplayManagerProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider,
      Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider) {
    return new KeyguardModule_NewKeyguardViewMediatorFactory(contextProvider, falsingCollectorProvider, lockPatternUtilsProvider, broadcastDispatcherProvider, statusBarKeyguardViewManagerLazyProvider, dismissCallbackRegistryProvider, updateMonitorProvider, dumpManagerProvider, powerManagerProvider, trustManagerProvider, userSwitcherControllerProvider, uiBgExecutorProvider, deviceConfigProvider, navigationModeControllerProvider, keyguardDisplayManagerProvider, dozeParametersProvider, unfoldComponentProvider, statusBarStateControllerProvider, keyguardStateControllerProvider, keyguardUnlockAnimationControllerProvider, unlockedScreenOffAnimationControllerProvider, notificationShadeDepthControllerProvider, notificationShadeWindowControllerProvider);
  }

  public static KeyguardViewMediator newKeyguardViewMediator(Context context,
      FalsingCollector falsingCollector, LockPatternUtils lockPatternUtils,
      BroadcastDispatcher broadcastDispatcher,
      Lazy<KeyguardViewController> statusBarKeyguardViewManagerLazy,
      DismissCallbackRegistry dismissCallbackRegistry, KeyguardUpdateMonitor updateMonitor,
      DumpManager dumpManager, PowerManager powerManager, TrustManager trustManager,
      UserSwitcherController userSwitcherController, Executor uiBgExecutor,
      DeviceConfigProxy deviceConfig, NavigationModeController navigationModeController,
      KeyguardDisplayManager keyguardDisplayManager, DozeParameters dozeParameters,
      Optional<SysUIUnfoldComponent> unfoldComponent,
      SysuiStatusBarStateController statusBarStateController,
      KeyguardStateController keyguardStateController,
      Lazy<KeyguardUnlockAnimationController> keyguardUnlockAnimationController,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController,
      Lazy<NotificationShadeDepthController> notificationShadeDepthController,
      Lazy<NotificationShadeWindowController> notificationShadeWindowController) {
    return Preconditions.checkNotNullFromProvides(KeyguardModule.newKeyguardViewMediator(context, falsingCollector, lockPatternUtils, broadcastDispatcher, statusBarKeyguardViewManagerLazy, dismissCallbackRegistry, updateMonitor, dumpManager, powerManager, trustManager, userSwitcherController, uiBgExecutor, deviceConfig, navigationModeController, keyguardDisplayManager, dozeParameters, unfoldComponent, statusBarStateController, keyguardStateController, keyguardUnlockAnimationController, unlockedScreenOffAnimationController, notificationShadeDepthController, notificationShadeWindowController));
  }
}
