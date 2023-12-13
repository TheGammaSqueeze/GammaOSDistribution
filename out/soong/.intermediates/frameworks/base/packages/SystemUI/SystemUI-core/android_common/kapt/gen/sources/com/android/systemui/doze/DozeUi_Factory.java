package com.android.systemui.doze;

import android.app.AlarmManager;
import android.content.Context;
import android.os.Handler;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.util.wakelock.WakeLock;
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
public final class DozeUi_Factory implements Factory<DozeUi> {
  private final Provider<Context> contextProvider;

  private final Provider<AlarmManager> alarmManagerProvider;

  private final Provider<WakeLock> wakeLockProvider;

  private final Provider<DozeHost> hostProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<DozeParameters> paramsProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public DozeUi_Factory(Provider<Context> contextProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<WakeLock> wakeLockProvider,
      Provider<DozeHost> hostProvider, Provider<Handler> handlerProvider,
      Provider<DozeParameters> paramsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.contextProvider = contextProvider;
    this.alarmManagerProvider = alarmManagerProvider;
    this.wakeLockProvider = wakeLockProvider;
    this.hostProvider = hostProvider;
    this.handlerProvider = handlerProvider;
    this.paramsProvider = paramsProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public DozeUi get() {
    return newInstance(contextProvider.get(), alarmManagerProvider.get(), wakeLockProvider.get(), hostProvider.get(), handlerProvider.get(), paramsProvider.get(), keyguardUpdateMonitorProvider.get(), dozeLogProvider.get(), DoubleCheck.lazy(statusBarStateControllerProvider));
  }

  public static DozeUi_Factory create(Provider<Context> contextProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<WakeLock> wakeLockProvider,
      Provider<DozeHost> hostProvider, Provider<Handler> handlerProvider,
      Provider<DozeParameters> paramsProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new DozeUi_Factory(contextProvider, alarmManagerProvider, wakeLockProvider, hostProvider, handlerProvider, paramsProvider, keyguardUpdateMonitorProvider, dozeLogProvider, statusBarStateControllerProvider);
  }

  public static DozeUi newInstance(Context context, AlarmManager alarmManager, WakeLock wakeLock,
      DozeHost host, Handler handler, DozeParameters params,
      KeyguardUpdateMonitor keyguardUpdateMonitor, DozeLog dozeLog,
      Lazy<StatusBarStateController> statusBarStateController) {
    return new DozeUi(context, alarmManager, wakeLock, host, handler, params, keyguardUpdateMonitor, dozeLog, statusBarStateController);
  }
}
