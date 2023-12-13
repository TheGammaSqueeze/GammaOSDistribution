package com.android.systemui.media;

import android.media.MediaRouter2Manager;
import com.android.systemui.dump.DumpManager;
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
public final class MediaDeviceManager_Factory implements Factory<MediaDeviceManager> {
  private final Provider<MediaControllerFactory> controllerFactoryProvider;

  private final Provider<LocalMediaManagerFactory> localMediaManagerFactoryProvider;

  private final Provider<MediaRouter2Manager> mr2managerProvider;

  private final Provider<Executor> fgExecutorProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public MediaDeviceManager_Factory(Provider<MediaControllerFactory> controllerFactoryProvider,
      Provider<LocalMediaManagerFactory> localMediaManagerFactoryProvider,
      Provider<MediaRouter2Manager> mr2managerProvider, Provider<Executor> fgExecutorProvider,
      Provider<Executor> bgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    this.controllerFactoryProvider = controllerFactoryProvider;
    this.localMediaManagerFactoryProvider = localMediaManagerFactoryProvider;
    this.mr2managerProvider = mr2managerProvider;
    this.fgExecutorProvider = fgExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public MediaDeviceManager get() {
    return newInstance(controllerFactoryProvider.get(), localMediaManagerFactoryProvider.get(), mr2managerProvider.get(), fgExecutorProvider.get(), bgExecutorProvider.get(), dumpManagerProvider.get());
  }

  public static MediaDeviceManager_Factory create(
      Provider<MediaControllerFactory> controllerFactoryProvider,
      Provider<LocalMediaManagerFactory> localMediaManagerFactoryProvider,
      Provider<MediaRouter2Manager> mr2managerProvider, Provider<Executor> fgExecutorProvider,
      Provider<Executor> bgExecutorProvider, Provider<DumpManager> dumpManagerProvider) {
    return new MediaDeviceManager_Factory(controllerFactoryProvider, localMediaManagerFactoryProvider, mr2managerProvider, fgExecutorProvider, bgExecutorProvider, dumpManagerProvider);
  }

  public static MediaDeviceManager newInstance(MediaControllerFactory controllerFactory,
      LocalMediaManagerFactory localMediaManagerFactory, MediaRouter2Manager mr2manager,
      Executor fgExecutor, Executor bgExecutor, DumpManager dumpManager) {
    return new MediaDeviceManager(controllerFactory, localMediaManagerFactory, mr2manager, fgExecutor, bgExecutor, dumpManager);
  }
}
