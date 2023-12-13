package com.android.systemui.plugins;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class PluginsModule_ProvidesPluginDebugFactory implements Factory<Boolean> {
  @Override
  public Boolean get() {
    return providesPluginDebug();
  }

  public static PluginsModule_ProvidesPluginDebugFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static boolean providesPluginDebug() {
    return PluginsModule.providesPluginDebug();
  }

  private static final class InstanceHolder {
    private static final PluginsModule_ProvidesPluginDebugFactory INSTANCE = new PluginsModule_ProvidesPluginDebugFactory();
  }
}
