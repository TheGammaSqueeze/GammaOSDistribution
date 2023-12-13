package com.android.systemui.fragments;

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
public final class FragmentService_Factory implements Factory<FragmentService> {
  private final Provider<FragmentService.FragmentCreator.Factory> fragmentCreatorFactoryProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public FragmentService_Factory(
      Provider<FragmentService.FragmentCreator.Factory> fragmentCreatorFactoryProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.fragmentCreatorFactoryProvider = fragmentCreatorFactoryProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public FragmentService get() {
    return newInstance(fragmentCreatorFactoryProvider.get(), configurationControllerProvider.get(), dumpManagerProvider.get());
  }

  public static FragmentService_Factory create(
      Provider<FragmentService.FragmentCreator.Factory> fragmentCreatorFactoryProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new FragmentService_Factory(fragmentCreatorFactoryProvider, configurationControllerProvider, dumpManagerProvider);
  }

  public static FragmentService newInstance(
      FragmentService.FragmentCreator.Factory fragmentCreatorFactory,
      ConfigurationController configurationController, DumpManager dumpManager) {
    return new FragmentService(fragmentCreatorFactory, configurationController, dumpManager);
  }
}
