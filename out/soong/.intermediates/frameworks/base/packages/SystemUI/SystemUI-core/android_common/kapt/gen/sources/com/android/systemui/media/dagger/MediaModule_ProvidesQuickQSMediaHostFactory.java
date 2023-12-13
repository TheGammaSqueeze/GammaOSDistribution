package com.android.systemui.media.dagger;

import com.android.systemui.media.MediaDataManager;
import com.android.systemui.media.MediaHierarchyManager;
import com.android.systemui.media.MediaHost;
import com.android.systemui.media.MediaHostStatesManager;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class MediaModule_ProvidesQuickQSMediaHostFactory implements Factory<MediaHost> {
  private final Provider<MediaHost.MediaHostStateHolder> stateHolderProvider;

  private final Provider<MediaHierarchyManager> hierarchyManagerProvider;

  private final Provider<MediaDataManager> dataManagerProvider;

  private final Provider<MediaHostStatesManager> statesManagerProvider;

  public MediaModule_ProvidesQuickQSMediaHostFactory(
      Provider<MediaHost.MediaHostStateHolder> stateHolderProvider,
      Provider<MediaHierarchyManager> hierarchyManagerProvider,
      Provider<MediaDataManager> dataManagerProvider,
      Provider<MediaHostStatesManager> statesManagerProvider) {
    this.stateHolderProvider = stateHolderProvider;
    this.hierarchyManagerProvider = hierarchyManagerProvider;
    this.dataManagerProvider = dataManagerProvider;
    this.statesManagerProvider = statesManagerProvider;
  }

  @Override
  public MediaHost get() {
    return providesQuickQSMediaHost(stateHolderProvider.get(), hierarchyManagerProvider.get(), dataManagerProvider.get(), statesManagerProvider.get());
  }

  public static MediaModule_ProvidesQuickQSMediaHostFactory create(
      Provider<MediaHost.MediaHostStateHolder> stateHolderProvider,
      Provider<MediaHierarchyManager> hierarchyManagerProvider,
      Provider<MediaDataManager> dataManagerProvider,
      Provider<MediaHostStatesManager> statesManagerProvider) {
    return new MediaModule_ProvidesQuickQSMediaHostFactory(stateHolderProvider, hierarchyManagerProvider, dataManagerProvider, statesManagerProvider);
  }

  public static MediaHost providesQuickQSMediaHost(MediaHost.MediaHostStateHolder stateHolder,
      MediaHierarchyManager hierarchyManager, MediaDataManager dataManager,
      MediaHostStatesManager statesManager) {
    return Preconditions.checkNotNullFromProvides(MediaModule.providesQuickQSMediaHost(stateHolder, hierarchyManager, dataManager, statesManager));
  }
}
