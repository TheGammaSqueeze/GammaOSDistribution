package com.android.systemui.tv;

import android.hardware.SensorPrivacyManager;
import com.android.systemui.statusbar.policy.SensorPrivacyController;
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
public final class TvSystemUIModule_ProvideSensorPrivacyControllerFactory implements Factory<SensorPrivacyController> {
  private final Provider<SensorPrivacyManager> sensorPrivacyManagerProvider;

  public TvSystemUIModule_ProvideSensorPrivacyControllerFactory(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    this.sensorPrivacyManagerProvider = sensorPrivacyManagerProvider;
  }

  @Override
  public SensorPrivacyController get() {
    return provideSensorPrivacyController(sensorPrivacyManagerProvider.get());
  }

  public static TvSystemUIModule_ProvideSensorPrivacyControllerFactory create(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    return new TvSystemUIModule_ProvideSensorPrivacyControllerFactory(sensorPrivacyManagerProvider);
  }

  public static SensorPrivacyController provideSensorPrivacyController(
      SensorPrivacyManager sensorPrivacyManager) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.provideSensorPrivacyController(sensorPrivacyManager));
  }
}
