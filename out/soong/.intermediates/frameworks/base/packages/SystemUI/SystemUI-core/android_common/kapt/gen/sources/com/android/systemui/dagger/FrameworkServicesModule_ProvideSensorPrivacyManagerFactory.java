package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.SensorPrivacyManager;
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
public final class FrameworkServicesModule_ProvideSensorPrivacyManagerFactory implements Factory<SensorPrivacyManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideSensorPrivacyManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public SensorPrivacyManager get() {
    return provideSensorPrivacyManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideSensorPrivacyManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideSensorPrivacyManagerFactory(contextProvider);
  }

  public static SensorPrivacyManager provideSensorPrivacyManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideSensorPrivacyManager(context));
  }
}
