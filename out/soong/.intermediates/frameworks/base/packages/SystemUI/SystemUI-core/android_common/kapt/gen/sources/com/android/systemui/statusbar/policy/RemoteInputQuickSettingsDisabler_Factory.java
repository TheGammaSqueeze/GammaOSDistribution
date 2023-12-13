package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.systemui.statusbar.CommandQueue;
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
public final class RemoteInputQuickSettingsDisabler_Factory implements Factory<RemoteInputQuickSettingsDisabler> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ConfigurationController> configControllerProvider;

  public RemoteInputQuickSettingsDisabler_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ConfigurationController> configControllerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.configControllerProvider = configControllerProvider;
  }

  @Override
  public RemoteInputQuickSettingsDisabler get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), configControllerProvider.get());
  }

  public static RemoteInputQuickSettingsDisabler_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ConfigurationController> configControllerProvider) {
    return new RemoteInputQuickSettingsDisabler_Factory(contextProvider, commandQueueProvider, configControllerProvider);
  }

  public static RemoteInputQuickSettingsDisabler newInstance(Context context,
      CommandQueue commandQueue, ConfigurationController configController) {
    return new RemoteInputQuickSettingsDisabler(context, commandQueue, configController);
  }
}
