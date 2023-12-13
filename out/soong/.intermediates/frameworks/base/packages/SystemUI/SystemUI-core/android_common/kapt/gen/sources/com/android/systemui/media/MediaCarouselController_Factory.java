package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class MediaCarouselController_Factory implements Factory<MediaCarouselController> {
  private final Provider<Context> contextProvider;

  private final Provider<MediaControlPanel> mediaControlPanelFactoryProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<MediaHostStatesManager> mediaHostStatesManagerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<DelayableExecutor> executorProvider;

  private final Provider<MediaDataManager> mediaManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public MediaCarouselController_Factory(Provider<Context> contextProvider,
      Provider<MediaControlPanel> mediaControlPanelFactoryProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<MediaHostStatesManager> mediaHostStatesManagerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<SystemClock> systemClockProvider,
      Provider<DelayableExecutor> executorProvider, Provider<MediaDataManager> mediaManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.mediaControlPanelFactoryProvider = mediaControlPanelFactoryProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.mediaHostStatesManagerProvider = mediaHostStatesManagerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.systemClockProvider = systemClockProvider;
    this.executorProvider = executorProvider;
    this.mediaManagerProvider = mediaManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public MediaCarouselController get() {
    return newInstance(contextProvider.get(), mediaControlPanelFactoryProvider, visualStabilityManagerProvider.get(), mediaHostStatesManagerProvider.get(), activityStarterProvider.get(), systemClockProvider.get(), executorProvider.get(), mediaManagerProvider.get(), configurationControllerProvider.get(), falsingCollectorProvider.get(), falsingManagerProvider.get(), dumpManagerProvider.get());
  }

  public static MediaCarouselController_Factory create(Provider<Context> contextProvider,
      Provider<MediaControlPanel> mediaControlPanelFactoryProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<MediaHostStatesManager> mediaHostStatesManagerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<SystemClock> systemClockProvider,
      Provider<DelayableExecutor> executorProvider, Provider<MediaDataManager> mediaManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new MediaCarouselController_Factory(contextProvider, mediaControlPanelFactoryProvider, visualStabilityManagerProvider, mediaHostStatesManagerProvider, activityStarterProvider, systemClockProvider, executorProvider, mediaManagerProvider, configurationControllerProvider, falsingCollectorProvider, falsingManagerProvider, dumpManagerProvider);
  }

  public static MediaCarouselController newInstance(Context context,
      Provider<MediaControlPanel> mediaControlPanelFactory,
      VisualStabilityManager visualStabilityManager, MediaHostStatesManager mediaHostStatesManager,
      ActivityStarter activityStarter, SystemClock systemClock, DelayableExecutor executor,
      MediaDataManager mediaManager, ConfigurationController configurationController,
      FalsingCollector falsingCollector, FalsingManager falsingManager, DumpManager dumpManager) {
    return new MediaCarouselController(context, mediaControlPanelFactory, visualStabilityManager, mediaHostStatesManager, activityStarter, systemClock, executor, mediaManager, configurationController, falsingCollector, falsingManager, dumpManager);
  }
}
