package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.os.Vibrator;
import dagger.internal.Factory;
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
public final class FrameworkServicesModule_ProvideVibratorFactory implements Factory<Vibrator> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideVibratorFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  @Nullable
  public Vibrator get() {
    return provideVibrator(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideVibratorFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideVibratorFactory(contextProvider);
  }

  @Nullable
  public static Vibrator provideVibrator(Context context) {
    return FrameworkServicesModule.provideVibrator(context);
  }
}
