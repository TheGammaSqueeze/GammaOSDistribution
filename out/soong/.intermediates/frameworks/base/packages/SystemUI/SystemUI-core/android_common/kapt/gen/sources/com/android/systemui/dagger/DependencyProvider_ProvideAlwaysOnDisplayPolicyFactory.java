package com.android.systemui.dagger;

import android.content.Context;
import com.android.systemui.doze.AlwaysOnDisplayPolicy;
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
public final class DependencyProvider_ProvideAlwaysOnDisplayPolicyFactory implements Factory<AlwaysOnDisplayPolicy> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideAlwaysOnDisplayPolicyFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public AlwaysOnDisplayPolicy get() {
    return provideAlwaysOnDisplayPolicy(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideAlwaysOnDisplayPolicyFactory create(
      DependencyProvider module, Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideAlwaysOnDisplayPolicyFactory(module, contextProvider);
  }

  public static AlwaysOnDisplayPolicy provideAlwaysOnDisplayPolicy(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideAlwaysOnDisplayPolicy(context));
  }
}
