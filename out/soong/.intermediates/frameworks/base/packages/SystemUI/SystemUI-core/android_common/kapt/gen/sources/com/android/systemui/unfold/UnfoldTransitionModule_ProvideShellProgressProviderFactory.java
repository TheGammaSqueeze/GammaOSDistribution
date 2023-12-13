package com.android.systemui.unfold;

import com.android.systemui.unfold.config.UnfoldTransitionConfig;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class UnfoldTransitionModule_ProvideShellProgressProviderFactory implements Factory<ShellUnfoldProgressProvider> {
  private final UnfoldTransitionModule module;

  private final Provider<UnfoldTransitionConfig> configProvider;

  private final Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider;

  public UnfoldTransitionModule_ProvideShellProgressProviderFactory(UnfoldTransitionModule module,
      Provider<UnfoldTransitionConfig> configProvider,
      Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider) {
    this.module = module;
    this.configProvider = configProvider;
    this.providerProvider = providerProvider;
  }

  @Override
  public ShellUnfoldProgressProvider get() {
    return provideShellProgressProvider(module, configProvider.get(), providerProvider.get());
  }

  public static UnfoldTransitionModule_ProvideShellProgressProviderFactory create(
      UnfoldTransitionModule module, Provider<UnfoldTransitionConfig> configProvider,
      Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider) {
    return new UnfoldTransitionModule_ProvideShellProgressProviderFactory(module, configProvider, providerProvider);
  }

  public static ShellUnfoldProgressProvider provideShellProgressProvider(
      UnfoldTransitionModule instance, UnfoldTransitionConfig config,
      Optional<UnfoldTransitionProgressProvider> provider) {
    return Preconditions.checkNotNullFromProvides(instance.provideShellProgressProvider(config, provider));
  }
}
