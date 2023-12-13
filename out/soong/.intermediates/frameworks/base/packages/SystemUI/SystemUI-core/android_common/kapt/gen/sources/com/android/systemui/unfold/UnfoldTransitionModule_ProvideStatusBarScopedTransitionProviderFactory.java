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
public final class UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory implements Factory<Optional<ScopedUnfoldTransitionProgressProvider>> {
  private final UnfoldTransitionModule module;

  private final Provider<Optional<NaturalRotationUnfoldProgressProvider>> sourceProvider;

  public UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory(
      UnfoldTransitionModule module,
      Provider<Optional<NaturalRotationUnfoldProgressProvider>> sourceProvider) {
    this.module = module;
    this.sourceProvider = sourceProvider;
  }

  @Override
  public Optional<ScopedUnfoldTransitionProgressProvider> get() {
    return provideStatusBarScopedTransitionProvider(module, sourceProvider.get());
  }

  public static UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory create(
      UnfoldTransitionModule module,
      Provider<Optional<NaturalRotationUnfoldProgressProvider>> sourceProvider) {
    return new UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory(module, sourceProvider);
  }

  public static Optional<ScopedUnfoldTransitionProgressProvider> provideStatusBarScopedTransitionProvider(
      UnfoldTransitionModule instance, Optional<NaturalRotationUnfoldProgressProvider> source) {
    return Preconditions.checkNotNullFromProvides(instance.provideStatusBarScopedTransitionProvider(source));
  }
}
