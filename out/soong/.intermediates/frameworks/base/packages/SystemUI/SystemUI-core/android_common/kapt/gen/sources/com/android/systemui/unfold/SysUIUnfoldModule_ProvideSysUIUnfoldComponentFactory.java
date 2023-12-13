package com.android.systemui.unfold;

import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
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
public final class SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory implements Factory<Optional<SysUIUnfoldComponent>> {
  private final SysUIUnfoldModule module;

  private final Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider;

  private final Provider<Optional<NaturalRotationUnfoldProgressProvider>> rotationProvider;

  private final Provider<Optional<ScopedUnfoldTransitionProgressProvider>> scopedProvider;

  private final Provider<SysUIUnfoldComponent.Factory> factoryProvider;

  public SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory(SysUIUnfoldModule module,
      Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider,
      Provider<Optional<NaturalRotationUnfoldProgressProvider>> rotationProvider,
      Provider<Optional<ScopedUnfoldTransitionProgressProvider>> scopedProvider,
      Provider<SysUIUnfoldComponent.Factory> factoryProvider) {
    this.module = module;
    this.providerProvider = providerProvider;
    this.rotationProvider = rotationProvider;
    this.scopedProvider = scopedProvider;
    this.factoryProvider = factoryProvider;
  }

  @Override
  public Optional<SysUIUnfoldComponent> get() {
    return provideSysUIUnfoldComponent(module, providerProvider.get(), rotationProvider.get(), scopedProvider.get(), factoryProvider.get());
  }

  public static SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory create(
      SysUIUnfoldModule module,
      Provider<Optional<UnfoldTransitionProgressProvider>> providerProvider,
      Provider<Optional<NaturalRotationUnfoldProgressProvider>> rotationProvider,
      Provider<Optional<ScopedUnfoldTransitionProgressProvider>> scopedProvider,
      Provider<SysUIUnfoldComponent.Factory> factoryProvider) {
    return new SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory(module, providerProvider, rotationProvider, scopedProvider, factoryProvider);
  }

  public static Optional<SysUIUnfoldComponent> provideSysUIUnfoldComponent(
      SysUIUnfoldModule instance, Optional<UnfoldTransitionProgressProvider> provider,
      Optional<NaturalRotationUnfoldProgressProvider> rotationProvider,
      Optional<ScopedUnfoldTransitionProgressProvider> scopedProvider,
      SysUIUnfoldComponent.Factory factory) {
    return Preconditions.checkNotNullFromProvides(instance.provideSysUIUnfoldComponent(provider, rotationProvider, scopedProvider, factory));
  }
}
