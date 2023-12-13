package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.SensorManager;
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
public final class FrameworkServicesModule_ProvidesSensorManagerFactory implements Factory<SensorManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvidesSensorManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public SensorManager get() {
    return providesSensorManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvidesSensorManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvidesSensorManagerFactory(contextProvider);
  }

  public static SensorManager providesSensorManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.providesSensorManager(context));
  }
}
