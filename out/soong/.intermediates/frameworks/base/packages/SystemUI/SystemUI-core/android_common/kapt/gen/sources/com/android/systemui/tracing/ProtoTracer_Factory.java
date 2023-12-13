package com.android.systemui.tracing;

import android.content.Context;
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
public final class ProtoTracer_Factory implements Factory<ProtoTracer> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public ProtoTracer_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public ProtoTracer get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get());
  }

  public static ProtoTracer_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new ProtoTracer_Factory(contextProvider, dumpManagerProvider);
  }

  public static ProtoTracer newInstance(Context context, DumpManager dumpManager) {
    return new ProtoTracer(context, dumpManager);
  }
}
