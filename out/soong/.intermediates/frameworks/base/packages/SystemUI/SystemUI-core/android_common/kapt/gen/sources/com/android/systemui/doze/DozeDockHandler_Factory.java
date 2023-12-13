package com.android.systemui.doze;

import android.hardware.display.AmbientDisplayConfiguration;
import com.android.systemui.dock.DockManager;
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
public final class DozeDockHandler_Factory implements Factory<DozeDockHandler> {
  private final Provider<AmbientDisplayConfiguration> configProvider;

  private final Provider<DockManager> dockManagerProvider;

  public DozeDockHandler_Factory(Provider<AmbientDisplayConfiguration> configProvider,
      Provider<DockManager> dockManagerProvider) {
    this.configProvider = configProvider;
    this.dockManagerProvider = dockManagerProvider;
  }

  @Override
  public DozeDockHandler get() {
    return newInstance(configProvider.get(), dockManagerProvider.get());
  }

  public static DozeDockHandler_Factory create(Provider<AmbientDisplayConfiguration> configProvider,
      Provider<DockManager> dockManagerProvider) {
    return new DozeDockHandler_Factory(configProvider, dockManagerProvider);
  }

  public static DozeDockHandler newInstance(AmbientDisplayConfiguration config,
      DockManager dockManager) {
    return new DozeDockHandler(config, dockManager);
  }
}
