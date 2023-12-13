package com.android.systemui.statusbar;

import android.content.res.Resources;
import android.view.CrossWindowBlurListeners;
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
public final class BlurUtils_Factory implements Factory<BlurUtils> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<CrossWindowBlurListeners> crossWindowBlurListenersProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public BlurUtils_Factory(Provider<Resources> resourcesProvider,
      Provider<CrossWindowBlurListeners> crossWindowBlurListenersProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.resourcesProvider = resourcesProvider;
    this.crossWindowBlurListenersProvider = crossWindowBlurListenersProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public BlurUtils get() {
    return newInstance(resourcesProvider.get(), crossWindowBlurListenersProvider.get(), dumpManagerProvider.get());
  }

  public static BlurUtils_Factory create(Provider<Resources> resourcesProvider,
      Provider<CrossWindowBlurListeners> crossWindowBlurListenersProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new BlurUtils_Factory(resourcesProvider, crossWindowBlurListenersProvider, dumpManagerProvider);
  }

  public static BlurUtils newInstance(Resources resources,
      CrossWindowBlurListeners crossWindowBlurListeners, DumpManager dumpManager) {
    return new BlurUtils(resources, crossWindowBlurListeners, dumpManager);
  }
}
