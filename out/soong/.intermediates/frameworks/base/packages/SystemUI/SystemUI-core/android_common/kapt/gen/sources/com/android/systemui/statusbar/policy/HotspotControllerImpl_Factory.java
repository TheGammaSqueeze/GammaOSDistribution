package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Handler;
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
public final class HotspotControllerImpl_Factory implements Factory<HotspotControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<Handler> backgroundHandlerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public HotspotControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> backgroundHandlerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.backgroundHandlerProvider = backgroundHandlerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public HotspotControllerImpl get() {
    return newInstance(contextProvider.get(), mainHandlerProvider.get(), backgroundHandlerProvider.get(), dumpManagerProvider.get());
  }

  public static HotspotControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> backgroundHandlerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new HotspotControllerImpl_Factory(contextProvider, mainHandlerProvider, backgroundHandlerProvider, dumpManagerProvider);
  }

  public static HotspotControllerImpl newInstance(Context context, Handler mainHandler,
      Handler backgroundHandler, DumpManager dumpManager) {
    return new HotspotControllerImpl(context, mainHandler, backgroundHandler, dumpManager);
  }
}
