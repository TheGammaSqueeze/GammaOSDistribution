package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class StatusBarContentInsetsProvider_Factory implements Factory<StatusBarContentInsetsProvider> {
  private final Provider<Context> contextProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public StatusBarContentInsetsProvider_Factory(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public StatusBarContentInsetsProvider get() {
    return newInstance(contextProvider.get(), configurationControllerProvider.get(), dumpManagerProvider.get());
  }

  public static StatusBarContentInsetsProvider_Factory create(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new StatusBarContentInsetsProvider_Factory(contextProvider, configurationControllerProvider, dumpManagerProvider);
  }

  public static StatusBarContentInsetsProvider newInstance(Context context,
      ConfigurationController configurationController, DumpManager dumpManager) {
    return new StatusBarContentInsetsProvider(context, configurationController, dumpManager);
  }
}
