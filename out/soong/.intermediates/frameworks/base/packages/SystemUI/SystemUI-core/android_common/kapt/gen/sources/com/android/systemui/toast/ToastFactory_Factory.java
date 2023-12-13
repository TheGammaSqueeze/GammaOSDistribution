package com.android.systemui.toast;

import android.view.LayoutInflater;
import com.android.systemui.dump.DumpManager;
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
public final class ToastFactory_Factory implements Factory<ToastFactory> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public ToastFactory_Factory(Provider<LayoutInflater> layoutInflaterProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public ToastFactory get() {
    return newInstance(layoutInflaterProvider.get(), pluginManagerProvider.get(), dumpManagerProvider.get());
  }

  public static ToastFactory_Factory create(Provider<LayoutInflater> layoutInflaterProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new ToastFactory_Factory(layoutInflaterProvider, pluginManagerProvider, dumpManagerProvider);
  }

  public static ToastFactory newInstance(LayoutInflater layoutInflater, PluginManager pluginManager,
      DumpManager dumpManager) {
    return new ToastFactory(layoutInflater, pluginManager, dumpManager);
  }
}
