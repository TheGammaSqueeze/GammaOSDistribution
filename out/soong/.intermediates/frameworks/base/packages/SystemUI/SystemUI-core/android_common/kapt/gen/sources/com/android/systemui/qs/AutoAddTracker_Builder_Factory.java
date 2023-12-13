package com.android.systemui.qs;

import android.os.Handler;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.settings.SecureSettings;
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
public final class AutoAddTracker_Builder_Factory implements Factory<AutoAddTracker.Builder> {
  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<QSHost> qsHostProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<Executor> executorProvider;

  public AutoAddTracker_Builder_Factory(Provider<SecureSettings> secureSettingsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider, Provider<QSHost> qsHostProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Handler> handlerProvider,
      Provider<Executor> executorProvider) {
    this.secureSettingsProvider = secureSettingsProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.qsHostProvider = qsHostProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.handlerProvider = handlerProvider;
    this.executorProvider = executorProvider;
  }

  @Override
  public AutoAddTracker.Builder get() {
    return newInstance(secureSettingsProvider.get(), broadcastDispatcherProvider.get(), qsHostProvider.get(), dumpManagerProvider.get(), handlerProvider.get(), executorProvider.get());
  }

  public static AutoAddTracker_Builder_Factory create(
      Provider<SecureSettings> secureSettingsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider, Provider<QSHost> qsHostProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Handler> handlerProvider,
      Provider<Executor> executorProvider) {
    return new AutoAddTracker_Builder_Factory(secureSettingsProvider, broadcastDispatcherProvider, qsHostProvider, dumpManagerProvider, handlerProvider, executorProvider);
  }

  public static AutoAddTracker.Builder newInstance(SecureSettings secureSettings,
      BroadcastDispatcher broadcastDispatcher, QSHost qsHost, DumpManager dumpManager,
      Handler handler, Executor executor) {
    return new AutoAddTracker.Builder(secureSettings, broadcastDispatcher, qsHost, dumpManager, handler, executor);
  }
}
