package com.android.keyguard;

import android.content.Context;
import android.os.Looper;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.util.LatencyTracker;
import com.android.internal.widget.LockPatternUtils;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.telephony.TelephonyListenerManager;
import com.android.systemui.util.RingerModeTracker;
import dagger.internal.Factory;
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
public final class KeyguardUpdateMonitor_Factory implements Factory<KeyguardUpdateMonitor> {
  private final Provider<Context> contextProvider;

  private final Provider<Looper> mainLooperProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<RingerModeTracker> ringerModeTrackerProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<TelephonyListenerManager> telephonyListenerManagerProvider;

  private final Provider<InteractionJankMonitor> interactionJankMonitorProvider;

  private final Provider<LatencyTracker> latencyTrackerProvider;

  public KeyguardUpdateMonitor_Factory(Provider<Context> contextProvider,
      Provider<Looper> mainLooperProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<Executor> mainExecutorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<AuthController> authControllerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<InteractionJankMonitor> interactionJankMonitorProvider,
      Provider<LatencyTracker> latencyTrackerProvider) {
    this.contextProvider = contextProvider;
    this.mainLooperProvider = mainLooperProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.ringerModeTrackerProvider = ringerModeTrackerProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.authControllerProvider = authControllerProvider;
    this.telephonyListenerManagerProvider = telephonyListenerManagerProvider;
    this.interactionJankMonitorProvider = interactionJankMonitorProvider;
    this.latencyTrackerProvider = latencyTrackerProvider;
  }

  @Override
  public KeyguardUpdateMonitor get() {
    return newInstance(contextProvider.get(), mainLooperProvider.get(), broadcastDispatcherProvider.get(), dumpManagerProvider.get(), ringerModeTrackerProvider.get(), backgroundExecutorProvider.get(), mainExecutorProvider.get(), statusBarStateControllerProvider.get(), lockPatternUtilsProvider.get(), authControllerProvider.get(), telephonyListenerManagerProvider.get(), interactionJankMonitorProvider.get(), latencyTrackerProvider.get());
  }

  public static KeyguardUpdateMonitor_Factory create(Provider<Context> contextProvider,
      Provider<Looper> mainLooperProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<Executor> backgroundExecutorProvider, Provider<Executor> mainExecutorProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<AuthController> authControllerProvider,
      Provider<TelephonyListenerManager> telephonyListenerManagerProvider,
      Provider<InteractionJankMonitor> interactionJankMonitorProvider,
      Provider<LatencyTracker> latencyTrackerProvider) {
    return new KeyguardUpdateMonitor_Factory(contextProvider, mainLooperProvider, broadcastDispatcherProvider, dumpManagerProvider, ringerModeTrackerProvider, backgroundExecutorProvider, mainExecutorProvider, statusBarStateControllerProvider, lockPatternUtilsProvider, authControllerProvider, telephonyListenerManagerProvider, interactionJankMonitorProvider, latencyTrackerProvider);
  }

  public static KeyguardUpdateMonitor newInstance(Context context, Looper mainLooper,
      BroadcastDispatcher broadcastDispatcher, DumpManager dumpManager,
      RingerModeTracker ringerModeTracker, Executor backgroundExecutor, Executor mainExecutor,
      StatusBarStateController statusBarStateController, LockPatternUtils lockPatternUtils,
      AuthController authController, TelephonyListenerManager telephonyListenerManager,
      InteractionJankMonitor interactionJankMonitor, LatencyTracker latencyTracker) {
    return new KeyguardUpdateMonitor(context, mainLooper, broadcastDispatcher, dumpManager, ringerModeTracker, backgroundExecutor, mainExecutor, statusBarStateController, lockPatternUtils, authController, telephonyListenerManager, interactionJankMonitor, latencyTracker);
  }
}
