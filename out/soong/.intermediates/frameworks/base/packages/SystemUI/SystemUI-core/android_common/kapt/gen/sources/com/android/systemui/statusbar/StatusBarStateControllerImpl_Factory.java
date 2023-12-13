package com.android.systemui.statusbar;

import com.android.internal.logging.UiEventLogger;
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
public final class StatusBarStateControllerImpl_Factory implements Factory<StatusBarStateControllerImpl> {
  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public StatusBarStateControllerImpl_Factory(Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public StatusBarStateControllerImpl get() {
    return newInstance(uiEventLoggerProvider.get(), dumpManagerProvider.get());
  }

  public static StatusBarStateControllerImpl_Factory create(
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new StatusBarStateControllerImpl_Factory(uiEventLoggerProvider, dumpManagerProvider);
  }

  public static StatusBarStateControllerImpl newInstance(UiEventLogger uiEventLogger,
      DumpManager dumpManager) {
    return new StatusBarStateControllerImpl(uiEventLogger, dumpManager);
  }
}
