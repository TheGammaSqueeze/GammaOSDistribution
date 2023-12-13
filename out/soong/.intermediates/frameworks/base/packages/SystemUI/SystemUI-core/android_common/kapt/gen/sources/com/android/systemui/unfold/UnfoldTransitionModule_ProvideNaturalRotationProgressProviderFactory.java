package com.android.systemui.unfold;

import android.content.Context;
import android.view.IWindowManager;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
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
public final class UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory implements Factory<Optional<NaturalRotationUnfoldProgressProvider>> {
  private final UnfoldTransitionModule module;

  private final Provider<Context> contextProvider;

  private final Provider<IWindowManager> windowManagerProvider;

  private final Provider<Optional<UnfoldTransitionProgressProvider>> unfoldTransitionProgressProvider;

  public UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory(
      UnfoldTransitionModule module, Provider<Context> contextProvider,
      Provider<IWindowManager> windowManagerProvider,
      Provider<Optional<UnfoldTransitionProgressProvider>> unfoldTransitionProgressProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.unfoldTransitionProgressProvider = unfoldTransitionProgressProvider;
  }

  @Override
  public Optional<NaturalRotationUnfoldProgressProvider> get() {
    return provideNaturalRotationProgressProvider(module, contextProvider.get(), windowManagerProvider.get(), unfoldTransitionProgressProvider.get());
  }

  public static UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory create(
      UnfoldTransitionModule module, Provider<Context> contextProvider,
      Provider<IWindowManager> windowManagerProvider,
      Provider<Optional<UnfoldTransitionProgressProvider>> unfoldTransitionProgressProvider) {
    return new UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory(module, contextProvider, windowManagerProvider, unfoldTransitionProgressProvider);
  }

  public static Optional<NaturalRotationUnfoldProgressProvider> provideNaturalRotationProgressProvider(
      UnfoldTransitionModule instance, Context context, IWindowManager windowManager,
      Optional<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider) {
    return Preconditions.checkNotNullFromProvides(instance.provideNaturalRotationProgressProvider(context, windowManager, unfoldTransitionProgressProvider));
  }
}
