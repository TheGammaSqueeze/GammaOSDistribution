package com.android.systemui.dump;

import android.content.Context;
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
public final class DumpHandler_Factory implements Factory<DumpHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<LogBufferEulogizer> logBufferEulogizerProvider;

  public DumpHandler_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<LogBufferEulogizer> logBufferEulogizerProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.logBufferEulogizerProvider = logBufferEulogizerProvider;
  }

  @Override
  public DumpHandler get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get(), logBufferEulogizerProvider.get());
  }

  public static DumpHandler_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<LogBufferEulogizer> logBufferEulogizerProvider) {
    return new DumpHandler_Factory(contextProvider, dumpManagerProvider, logBufferEulogizerProvider);
  }

  public static DumpHandler newInstance(Context context, DumpManager dumpManager,
      LogBufferEulogizer logBufferEulogizer) {
    return new DumpHandler(context, dumpManager, logBufferEulogizer);
  }
}
