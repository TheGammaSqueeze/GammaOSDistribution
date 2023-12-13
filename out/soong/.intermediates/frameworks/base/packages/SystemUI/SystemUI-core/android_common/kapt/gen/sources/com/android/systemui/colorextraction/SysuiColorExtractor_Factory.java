package com.android.systemui.colorextraction;

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
public final class SysuiColorExtractor_Factory implements Factory<SysuiColorExtractor> {
  private final Provider<Context> contextProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public SysuiColorExtractor_Factory(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public SysuiColorExtractor get() {
    return newInstance(contextProvider.get(), configurationControllerProvider.get(), dumpManagerProvider.get());
  }

  public static SysuiColorExtractor_Factory create(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new SysuiColorExtractor_Factory(contextProvider, configurationControllerProvider, dumpManagerProvider);
  }

  public static SysuiColorExtractor newInstance(Context context,
      ConfigurationController configurationController, DumpManager dumpManager) {
    return new SysuiColorExtractor(context, configurationController, dumpManager);
  }
}
