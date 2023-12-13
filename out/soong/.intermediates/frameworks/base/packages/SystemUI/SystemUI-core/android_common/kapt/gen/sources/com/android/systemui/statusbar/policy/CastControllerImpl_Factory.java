package com.android.systemui.statusbar.policy;

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
public final class CastControllerImpl_Factory implements Factory<CastControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public CastControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public CastControllerImpl get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get());
  }

  public static CastControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new CastControllerImpl_Factory(contextProvider, dumpManagerProvider);
  }

  public static CastControllerImpl newInstance(Context context, DumpManager dumpManager) {
    return new CastControllerImpl(context, dumpManager);
  }
}
