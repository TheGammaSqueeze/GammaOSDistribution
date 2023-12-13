package com.android.keyguard;

import android.content.res.Resources;
import android.os.Vibrator;
import android.view.accessibility.AccessibilityManager;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.biometrics.AuthRippleController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class LockIconViewController_Factory implements Factory<LockIconViewController> {
  private final Provider<LockIconView> viewProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<KeyguardViewController> keyguardViewControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<DelayableExecutor> executorProvider;

  private final Provider<Vibrator> vibratorProvider;

  private final Provider<AuthRippleController> authRippleControllerProvider;

  private final Provider<Resources> resourcesProvider;

  public LockIconViewController_Factory(Provider<LockIconView> viewProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<AuthController> authControllerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DelayableExecutor> executorProvider, Provider<Vibrator> vibratorProvider,
      Provider<AuthRippleController> authRippleControllerProvider,
      Provider<Resources> resourcesProvider) {
    this.viewProvider = viewProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.keyguardViewControllerProvider = keyguardViewControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.authControllerProvider = authControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.executorProvider = executorProvider;
    this.vibratorProvider = vibratorProvider;
    this.authRippleControllerProvider = authRippleControllerProvider;
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public LockIconViewController get() {
    return newInstance(viewProvider.get(), statusBarStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), keyguardViewControllerProvider.get(), keyguardStateControllerProvider.get(), falsingManagerProvider.get(), authControllerProvider.get(), dumpManagerProvider.get(), accessibilityManagerProvider.get(), configurationControllerProvider.get(), executorProvider.get(), vibratorProvider.get(), authRippleControllerProvider.get(), resourcesProvider.get());
  }

  public static LockIconViewController_Factory create(Provider<LockIconView> viewProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<AuthController> authControllerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DelayableExecutor> executorProvider, Provider<Vibrator> vibratorProvider,
      Provider<AuthRippleController> authRippleControllerProvider,
      Provider<Resources> resourcesProvider) {
    return new LockIconViewController_Factory(viewProvider, statusBarStateControllerProvider, keyguardUpdateMonitorProvider, keyguardViewControllerProvider, keyguardStateControllerProvider, falsingManagerProvider, authControllerProvider, dumpManagerProvider, accessibilityManagerProvider, configurationControllerProvider, executorProvider, vibratorProvider, authRippleControllerProvider, resourcesProvider);
  }

  public static LockIconViewController newInstance(LockIconView view,
      StatusBarStateController statusBarStateController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, KeyguardViewController keyguardViewController,
      KeyguardStateController keyguardStateController, FalsingManager falsingManager,
      AuthController authController, DumpManager dumpManager,
      AccessibilityManager accessibilityManager, ConfigurationController configurationController,
      DelayableExecutor executor, Vibrator vibrator, AuthRippleController authRippleController,
      Resources resources) {
    return new LockIconViewController(view, statusBarStateController, keyguardUpdateMonitor, keyguardViewController, keyguardStateController, falsingManager, authController, dumpManager, accessibilityManager, configurationController, executor, vibrator, authRippleController, resources);
  }
}
