package com.android.systemui.dagger;

import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.statusbar.policy.DataSaverController;
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
public final class DependencyProvider_ProvideDataSaverControllerFactory implements Factory<DataSaverController> {
  private final DependencyProvider module;

  private final Provider<NetworkController> networkControllerProvider;

  public DependencyProvider_ProvideDataSaverControllerFactory(DependencyProvider module,
      Provider<NetworkController> networkControllerProvider) {
    this.module = module;
    this.networkControllerProvider = networkControllerProvider;
  }

  @Override
  public DataSaverController get() {
    return provideDataSaverController(module, networkControllerProvider.get());
  }

  public static DependencyProvider_ProvideDataSaverControllerFactory create(
      DependencyProvider module, Provider<NetworkController> networkControllerProvider) {
    return new DependencyProvider_ProvideDataSaverControllerFactory(module, networkControllerProvider);
  }

  public static DataSaverController provideDataSaverController(DependencyProvider instance,
      NetworkController networkController) {
    return Preconditions.checkNotNullFromProvides(instance.provideDataSaverController(networkController));
  }
}
