package com.android.systemui.keyguard.dagger;

import android.annotation.Nullable;
import android.content.Context;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.KeyguardLiftController;
import com.android.systemui.util.sensors.AsyncSensorManager;
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
public final class KeyguardModule_ProvideKeyguardLiftControllerFactory implements Factory<KeyguardLiftController> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<AsyncSensorManager> asyncSensorManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public KeyguardModule_ProvideKeyguardLiftControllerFactory(Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<AsyncSensorManager> asyncSensorManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.asyncSensorManagerProvider = asyncSensorManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  @Nullable
  public KeyguardLiftController get() {
    return provideKeyguardLiftController(contextProvider.get(), statusBarStateControllerProvider.get(), asyncSensorManagerProvider.get(), keyguardUpdateMonitorProvider.get(), dumpManagerProvider.get());
  }

  public static KeyguardModule_ProvideKeyguardLiftControllerFactory create(
      Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<AsyncSensorManager> asyncSensorManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new KeyguardModule_ProvideKeyguardLiftControllerFactory(contextProvider, statusBarStateControllerProvider, asyncSensorManagerProvider, keyguardUpdateMonitorProvider, dumpManagerProvider);
  }

  @Nullable
  public static KeyguardLiftController provideKeyguardLiftController(Context context,
      StatusBarStateController statusBarStateController, AsyncSensorManager asyncSensorManager,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DumpManager dumpManager) {
    return KeyguardModule.provideKeyguardLiftController(context, statusBarStateController, asyncSensorManager, keyguardUpdateMonitor, dumpManager);
  }
}
