package com.android.systemui.dagger;

import android.app.KeyguardManager;
import android.content.Context;
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
public final class FrameworkServicesModule_ProvideKeyguardManagerFactory implements Factory<KeyguardManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideKeyguardManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public KeyguardManager get() {
    return provideKeyguardManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideKeyguardManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideKeyguardManagerFactory(contextProvider);
  }

  public static KeyguardManager provideKeyguardManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideKeyguardManager(context));
  }
}
