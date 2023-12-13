package com.android.systemui.statusbar.notification.collection;

import android.os.Handler;
import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.dump.LogBufferEulogizer;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionLogger;
import com.android.systemui.util.time.SystemClock;
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
public final class NotifCollection_Factory implements Factory<NotifCollection> {
  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<SystemClock> clockProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotifCollectionLogger> loggerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<LogBufferEulogizer> logBufferEulogizerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotifCollection_Factory(Provider<IStatusBarService> statusBarServiceProvider,
      Provider<SystemClock> clockProvider, Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotifCollectionLogger> loggerProvider, Provider<Handler> mainHandlerProvider,
      Provider<LogBufferEulogizer> logBufferEulogizerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.clockProvider = clockProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.loggerProvider = loggerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.logBufferEulogizerProvider = logBufferEulogizerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotifCollection get() {
    return newInstance(statusBarServiceProvider.get(), clockProvider.get(), featureFlagsProvider.get(), loggerProvider.get(), mainHandlerProvider.get(), logBufferEulogizerProvider.get(), dumpManagerProvider.get());
  }

  public static NotifCollection_Factory create(Provider<IStatusBarService> statusBarServiceProvider,
      Provider<SystemClock> clockProvider, Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotifCollectionLogger> loggerProvider, Provider<Handler> mainHandlerProvider,
      Provider<LogBufferEulogizer> logBufferEulogizerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotifCollection_Factory(statusBarServiceProvider, clockProvider, featureFlagsProvider, loggerProvider, mainHandlerProvider, logBufferEulogizerProvider, dumpManagerProvider);
  }

  public static NotifCollection newInstance(IStatusBarService statusBarService, SystemClock clock,
      FeatureFlags featureFlags, NotifCollectionLogger logger, Handler mainHandler,
      LogBufferEulogizer logBufferEulogizer, DumpManager dumpManager) {
    return new NotifCollection(statusBarService, clock, featureFlags, logger, mainHandler, logBufferEulogizer, dumpManager);
  }
}
