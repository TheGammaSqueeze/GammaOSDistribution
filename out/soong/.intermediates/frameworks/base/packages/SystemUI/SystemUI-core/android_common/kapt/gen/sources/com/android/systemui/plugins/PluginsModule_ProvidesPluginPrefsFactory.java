package com.android.systemui.plugins;

import android.content.Context;
import com.android.systemui.shared.plugins.PluginPrefs;
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
public final class PluginsModule_ProvidesPluginPrefsFactory implements Factory<PluginPrefs> {
  private final Provider<Context> contextProvider;

  public PluginsModule_ProvidesPluginPrefsFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public PluginPrefs get() {
    return providesPluginPrefs(contextProvider.get());
  }

  public static PluginsModule_ProvidesPluginPrefsFactory create(Provider<Context> contextProvider) {
    return new PluginsModule_ProvidesPluginPrefsFactory(contextProvider);
  }

  public static PluginPrefs providesPluginPrefs(Context context) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providesPluginPrefs(context));
  }
}
