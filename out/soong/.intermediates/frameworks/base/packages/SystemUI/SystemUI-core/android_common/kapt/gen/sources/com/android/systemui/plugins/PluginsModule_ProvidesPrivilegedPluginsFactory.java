package com.android.systemui.plugins;

import android.content.Context;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.List;
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
public final class PluginsModule_ProvidesPrivilegedPluginsFactory implements Factory<List<String>> {
  private final Provider<Context> contextProvider;

  public PluginsModule_ProvidesPrivilegedPluginsFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public List<String> get() {
    return providesPrivilegedPlugins(contextProvider.get());
  }

  public static PluginsModule_ProvidesPrivilegedPluginsFactory create(
      Provider<Context> contextProvider) {
    return new PluginsModule_ProvidesPrivilegedPluginsFactory(contextProvider);
  }

  public static List<String> providesPrivilegedPlugins(Context context) {
    return Preconditions.checkNotNullFromProvides(PluginsModule.providesPrivilegedPlugins(context));
  }
}
