package com.android.systemui.plugins;

import android.app.NotificationManager;
import android.content.Context;
import android.content.pm.PackageManager;
import com.android.systemui.shared.plugins.PluginActionManager;
import com.android.systemui.shared.plugins.PluginEnabler;
import com.android.systemui.shared.plugins.PluginInstance;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.List;
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
public final class PluginsModule_ProvidePluginInstanceManagerFactoryFactory implements Factory<PluginActionManager.Factory> {
  private final Provider<Context> contextProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<Executor> pluginExecutorProvider;

  private final Provider<NotificationManager> notificationManagerProvider;

  private final Provider<PluginEnabler> pluginEnablerProvider;

  private final Provider<List<String>> privilegedPluginsProvider;

  private final Provider<PluginInstance.Factory> pluginInstanceFactoryProvider;

  public PluginsModule_ProvidePluginInstanceManagerFactoryFactory(Provider<Context> contextProvider,
      Provider<PackageManager> packageManagerProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> pluginExecutorProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<PluginEnabler> pluginEnablerProvider,
      Provider<List<String>> privilegedPluginsProvider,
      Provider<PluginInstance.Factory> pluginInstanceFactoryProvider) {
    this.contextProvider = contextProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.pluginExecutorProvider = pluginExecutorProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.pluginEnablerProvider = pluginEnablerProvider;
    this.privilegedPluginsProvider = privilegedPluginsProvider;
    this.pluginInstanceFactoryProvider = pluginInstanceFactoryProvider;
  }

  @Override
  public PluginActionManager.Factory get() {
    return providePluginInstanceManagerFactory(contextProvider.get(), packageManagerProvider.get(), mainExecutorProvider.get(), pluginExecutorProvider.get(), notificationManagerProvider.get(), pluginEnablerProvider.get(), privilegedPluginsProvider.get(), pluginInstanceFactoryProvider.get());
  }

  public static PluginsModule_ProvidePluginInstanceManagerFactoryFactory create(
      Provider<Context> contextProvider, Provider<PackageManager> packageManagerProvider,
      Provider<Executor> mainExecutorProvider, Provider<Executor> pluginExecutorProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<PluginEnabler> pluginEnablerProvider,
      Provider<List<String>> privilegedPluginsProvider,
      Provider<PluginInstance.Factory> pluginInstanceFactoryProvider) {
    return new PluginsModule_ProvidePluginInstanceManagerFactoryFactory(contextProvider, packageManagerProvider, mainExecutorProvider, pluginExecutorProvider, notificationManagerProvider, pluginEnablerProvider, privilegedPluginsProvider, pluginInstanceFactoryProvider);
  }

  public static PluginActionManager.Factory providePluginInstanceManagerFactory(Context context,
      PackageManager packageManager, Executor mainExecutor, Executor pluginExecutor,
      NotificationManager notificationManager, PluginEnabler pluginEnabler,
      List<String> privilegedPlugins, PluginInstance.Factory pluginInstanceFactory) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providePluginInstanceManagerFactory(context, packageManager, mainExecutor, pluginExecutor, notificationManager, pluginEnabler, privilegedPlugins, pluginInstanceFactory));
  }
}
