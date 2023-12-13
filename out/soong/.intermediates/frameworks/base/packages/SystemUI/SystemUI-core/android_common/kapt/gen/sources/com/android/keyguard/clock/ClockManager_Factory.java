package com.android.keyguard.clock;

import android.content.Context;
import android.view.LayoutInflater;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.dock.DockManager;
import com.android.systemui.shared.plugins.PluginManager;
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
public final class ClockManager_Factory implements Factory<ClockManager> {
  private final Provider<Context> contextProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<SysuiColorExtractor> colorExtractorProvider;

  private final Provider<DockManager> dockManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public ClockManager_Factory(Provider<Context> contextProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<PluginManager> pluginManagerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.contextProvider = contextProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.colorExtractorProvider = colorExtractorProvider;
    this.dockManagerProvider = dockManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public ClockManager get() {
    return newInstance(contextProvider.get(), layoutInflaterProvider.get(), pluginManagerProvider.get(), colorExtractorProvider.get(), dockManagerProvider.get(), broadcastDispatcherProvider.get());
  }

  public static ClockManager_Factory create(Provider<Context> contextProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<PluginManager> pluginManagerProvider,
      Provider<SysuiColorExtractor> colorExtractorProvider,
      Provider<DockManager> dockManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new ClockManager_Factory(contextProvider, layoutInflaterProvider, pluginManagerProvider, colorExtractorProvider, dockManagerProvider, broadcastDispatcherProvider);
  }

  public static ClockManager newInstance(Context context, LayoutInflater layoutInflater,
      PluginManager pluginManager, SysuiColorExtractor colorExtractor, DockManager dockManager,
      BroadcastDispatcher broadcastDispatcher) {
    return new ClockManager(context, layoutInflater, pluginManager, colorExtractor, dockManager, broadcastDispatcher);
  }
}
