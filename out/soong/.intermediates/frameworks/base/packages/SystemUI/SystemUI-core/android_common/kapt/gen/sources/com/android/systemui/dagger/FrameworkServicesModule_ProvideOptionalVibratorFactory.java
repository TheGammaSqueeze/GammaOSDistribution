package com.android.systemui.dagger;

import android.content.Context;
import android.os.Vibrator;
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
public final class FrameworkServicesModule_ProvideOptionalVibratorFactory implements Factory<Optional<Vibrator>> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideOptionalVibratorFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Optional<Vibrator> get() {
    return provideOptionalVibrator(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideOptionalVibratorFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideOptionalVibratorFactory(contextProvider);
  }

  public static Optional<Vibrator> provideOptionalVibrator(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideOptionalVibrator(context));
  }
}
