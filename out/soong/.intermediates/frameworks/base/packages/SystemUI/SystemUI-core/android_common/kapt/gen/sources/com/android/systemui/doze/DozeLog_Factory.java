package com.android.systemui.doze;

import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dump.DumpManager;
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
public final class DozeLog_Factory implements Factory<DozeLog> {
  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<DozeLogger> loggerProvider;

  public DozeLog_Factory(Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<DozeLogger> loggerProvider) {
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public DozeLog get() {
    return newInstance(keyguardUpdateMonitorProvider.get(), dumpManagerProvider.get(), loggerProvider.get());
  }

  public static DozeLog_Factory create(
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<DozeLogger> loggerProvider) {
    return new DozeLog_Factory(keyguardUpdateMonitorProvider, dumpManagerProvider, loggerProvider);
  }

  public static DozeLog newInstance(KeyguardUpdateMonitor keyguardUpdateMonitor,
      DumpManager dumpManager, DozeLogger logger) {
    return new DozeLog(keyguardUpdateMonitor, dumpManager, logger);
  }
}
