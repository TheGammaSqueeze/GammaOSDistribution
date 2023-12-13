package com.android.systemui.plugins;

import android.content.Context;
import com.android.systemui.shared.plugins.PluginActionManager;
import com.android.systemui.shared.plugins.PluginEnabler;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.shared.plugins.PluginPrefs;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.List;
import java.util.Optional;
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
public final class PluginsModule_ProvidesPluginManagerFactory implements Factory<PluginManager> {
  private final Provider<Context> contextProvider;

  private final Provider<PluginActionManager.Factory> instanceManagerFactoryProvider;

  private final Provider<Boolean> debugProvider;

  private final Provider<Optional<Thread.UncaughtExceptionHandler>> uncaughtExceptionHandlerOptionalProvider;

  private final Provider<PluginEnabler> pluginEnablerProvider;

  private final Provider<PluginPrefs> pluginPrefsProvider;

  private final Provider<List<String>> privilegedPluginsProvider;

  public PluginsModule_ProvidesPluginManagerFactory(Provider<Context> contextProvider,
      Provider<PluginActionManager.Factory> instanceManagerFactoryProvider,
      Provider<Boolean> debugProvider,
      Provider<Optional<Thread.UncaughtExceptionHandler>> uncaughtExceptionHandlerOptionalProvider,
      Provider<PluginEnabler> pluginEnablerProvider, Provider<PluginPrefs> pluginPrefsProvider,
      Provider<List<String>> privilegedPluginsProvider) {
    this.contextProvider = contextProvider;
    this.instanceManagerFactoryProvider = instanceManagerFactoryProvider;
    this.debugProvider = debugProvider;
    this.uncaughtExceptionHandlerOptionalProvider = uncaughtExceptionHandlerOptionalProvider;
    this.pluginEnablerProvider = pluginEnablerProvider;
    this.pluginPrefsProvider = pluginPrefsProvider;
    this.privilegedPluginsProvider = privilegedPluginsProvider;
  }

  @Override
  public PluginManager get() {
    return providesPluginManager(contextProvider.get(), instanceManagerFactoryProvider.get(), debugProvider.get(), uncaughtExceptionHandlerOptionalProvider.get(), pluginEnablerProvider.get(), pluginPrefsProvider.get(), privilegedPluginsProvider.get());
  }

  public static PluginsModule_ProvidesPluginManagerFactory create(Provider<Context> contextProvider,
      Provider<PluginActionManager.Factory> instanceManagerFactoryProvider,
      Provider<Boolean> debugProvider,
      Provider<Optional<Thread.UncaughtExceptionHandler>> uncaughtExceptionHandlerOptionalProvider,
      Provider<PluginEnabler> pluginEnablerProvider, Provider<PluginPrefs> pluginPrefsProvider,
      Provider<List<String>> privilegedPluginsProvider) {
    return new PluginsModule_ProvidesPluginManagerFactory(contextProvider, instanceManagerFactoryProvider, debugProvider, uncaughtExceptionHandlerOptionalProvider, pluginEnablerProvider, pluginPrefsProvider, privilegedPluginsProvider);
  }

  public static PluginManager providesPluginManager(Context context,
      PluginActionManager.Factory instanceManagerFactory, boolean debug,
      Optional<Thread.UncaughtExceptionHandler> uncaughtExceptionHandlerOptional,
      PluginEnabler pluginEnabler, PluginPrefs pluginPrefs, List<String> privilegedPlugins) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providesPluginManager(context, instanceManagerFactory, debug, uncaughtExceptionHandlerOptional, pluginEnabler, pluginPrefs, privilegedPlugins));
  }
}
