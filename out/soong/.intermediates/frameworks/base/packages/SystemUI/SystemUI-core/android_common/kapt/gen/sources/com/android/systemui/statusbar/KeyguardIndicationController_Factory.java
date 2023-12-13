package com.android.systemui.statusbar;

import android.app.IActivityManager;
import android.app.admin.DevicePolicyManager;
import android.content.Context;
import android.os.UserManager;
import com.android.internal.app.IBatteryStats;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dock.DockManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.wakelock.WakeLock;
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
public final class KeyguardIndicationController_Factory implements Factory<KeyguardIndicationController> {
  private final Provider<Context> contextProvider;

  private final Provider<WakeLock.Builder> wakeLockBuilderProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DevicePolicyManager> devicePolicyManagerProvider;

  private final Provider<IBatteryStats> iBatteryStatsProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<DelayableExecutor> executorProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<IActivityManager> iActivityManagerProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  public KeyguardIndicationController_Factory(Provider<Context> contextProvider,
      Provider<WakeLock.Builder> wakeLockBuilderProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<IBatteryStats> iBatteryStatsProvider, Provider<UserManager> userManagerProvider,
      Provider<DelayableExecutor> executorProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider) {
    this.contextProvider = contextProvider;
    this.wakeLockBuilderProvider = wakeLockBuilderProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.devicePolicyManagerProvider = devicePolicyManagerProvider;
    this.iBatteryStatsProvider = iBatteryStatsProvider;
    this.userManagerProvider = userManagerProvider;
    this.executorProvider = executorProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.iActivityManagerProvider = iActivityManagerProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
  }

  @Override
  public KeyguardIndicationController get() {
    return newInstance(contextProvider.get(), wakeLockBuilderProvider.get(), keyguardStateControllerProvider.get(), statusBarStateControllerProvider.get(), keyguardUpdateMonitorProvider.get(), dockManagerProvider.get(), broadcastDispatcherProvider.get(), devicePolicyManagerProvider.get(), iBatteryStatsProvider.get(), userManagerProvider.get(), executorProvider.get(), falsingManagerProvider.get(), lockPatternUtilsProvider.get(), iActivityManagerProvider.get(), keyguardBypassControllerProvider.get());
  }

  public static KeyguardIndicationController_Factory create(Provider<Context> contextProvider,
      Provider<WakeLock.Builder> wakeLockBuilderProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DevicePolicyManager> devicePolicyManagerProvider,
      Provider<IBatteryStats> iBatteryStatsProvider, Provider<UserManager> userManagerProvider,
      Provider<DelayableExecutor> executorProvider, Provider<FalsingManager> falsingManagerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider) {
    return new KeyguardIndicationController_Factory(contextProvider, wakeLockBuilderProvider, keyguardStateControllerProvider, statusBarStateControllerProvider, keyguardUpdateMonitorProvider, dockManagerProvider, broadcastDispatcherProvider, devicePolicyManagerProvider, iBatteryStatsProvider, userManagerProvider, executorProvider, falsingManagerProvider, lockPatternUtilsProvider, iActivityManagerProvider, keyguardBypassControllerProvider);
  }

  public static KeyguardIndicationController newInstance(Context context,
      WakeLock.Builder wakeLockBuilder, KeyguardStateController keyguardStateController,
      StatusBarStateController statusBarStateController,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DockManager dockManager,
      BroadcastDispatcher broadcastDispatcher, DevicePolicyManager devicePolicyManager,
      IBatteryStats iBatteryStats, UserManager userManager, DelayableExecutor executor,
      FalsingManager falsingManager, LockPatternUtils lockPatternUtils,
      IActivityManager iActivityManager, KeyguardBypassController keyguardBypassController) {
    return new KeyguardIndicationController(context, wakeLockBuilder, keyguardStateController, statusBarStateController, keyguardUpdateMonitor, dockManager, broadcastDispatcher, devicePolicyManager, iBatteryStats, userManager, executor, falsingManager, lockPatternUtils, iActivityManager, keyguardBypassController);
  }
}
