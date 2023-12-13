package com.android.systemui.dagger;

import android.content.Context;
import android.content.SharedPreferences;
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
public final class DependencyProvider_ProvideSharePreferencesFactory implements Factory<SharedPreferences> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideSharePreferencesFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public SharedPreferences get() {
    return provideSharePreferences(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideSharePreferencesFactory create(DependencyProvider module,
      Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideSharePreferencesFactory(module, contextProvider);
  }

  public static SharedPreferences provideSharePreferences(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideSharePreferences(context));
  }
}
