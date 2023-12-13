package com.android.systemui.dagger;

import android.content.Context;
import android.view.LayoutInflater;
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
public final class DependencyProvider_ProviderLayoutInflaterFactory implements Factory<LayoutInflater> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProviderLayoutInflaterFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public LayoutInflater get() {
    return providerLayoutInflater(module, contextProvider.get());
  }

  public static DependencyProvider_ProviderLayoutInflaterFactory create(DependencyProvider module,
      Provider<Context> contextProvider) {
    return new DependencyProvider_ProviderLayoutInflaterFactory(module, contextProvider);
  }

  public static LayoutInflater providerLayoutInflater(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.providerLayoutInflater(context));
  }
}
