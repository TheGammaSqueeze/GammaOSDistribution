package com.android.systemui.dagger;

import android.content.Context;
import android.telecom.TelecomManager;
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
public final class FrameworkServicesModule_ProvideOptionalTelecomManagerFactory implements Factory<Optional<TelecomManager>> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideOptionalTelecomManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Optional<TelecomManager> get() {
    return provideOptionalTelecomManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideOptionalTelecomManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideOptionalTelecomManagerFactory(contextProvider);
  }

  public static Optional<TelecomManager> provideOptionalTelecomManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideOptionalTelecomManager(context));
  }
}
