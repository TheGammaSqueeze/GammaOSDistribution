package com.android.systemui.unfold;

import android.content.Context;
import com.android.systemui.unfold.config.UnfoldTransitionConfig;
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
public final class UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory implements Factory<UnfoldTransitionConfig> {
  private final UnfoldTransitionModule module;

  private final Provider<Context> contextProvider;

  public UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory(UnfoldTransitionModule module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public UnfoldTransitionConfig get() {
    return provideUnfoldTransitionConfig(module, contextProvider.get());
  }

  public static UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory create(
      UnfoldTransitionModule module, Provider<Context> contextProvider) {
    return new UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory(module, contextProvider);
  }

  public static UnfoldTransitionConfig provideUnfoldTransitionConfig(
      UnfoldTransitionModule instance, Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideUnfoldTransitionConfig(context));
  }
}
