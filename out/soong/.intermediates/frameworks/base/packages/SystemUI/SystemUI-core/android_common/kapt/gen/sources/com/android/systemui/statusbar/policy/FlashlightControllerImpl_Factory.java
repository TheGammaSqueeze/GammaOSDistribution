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
public final class FlashlightControllerImpl_Factory implements Factory<FlashlightControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public FlashlightControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public FlashlightControllerImpl get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get());
  }

  public static FlashlightControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new FlashlightControllerImpl_Factory(contextProvider, dumpManagerProvider);
  }

  public static FlashlightControllerImpl newInstance(Context context, DumpManager dumpManager) {
    return new FlashlightControllerImpl(context, dumpManager);
  }
}
