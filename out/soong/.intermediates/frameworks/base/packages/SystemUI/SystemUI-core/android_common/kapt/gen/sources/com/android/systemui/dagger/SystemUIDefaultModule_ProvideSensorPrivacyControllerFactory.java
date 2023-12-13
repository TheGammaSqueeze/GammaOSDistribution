package com.android.systemui.dagger;

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
public final class SystemUIDefaultModule_ProvideSensorPrivacyControllerFactory implements Factory<SensorPrivacyController> {
  private final Provider<SensorPrivacyManager> sensorPrivacyManagerProvider;

  public SystemUIDefaultModule_ProvideSensorPrivacyControllerFactory(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    this.sensorPrivacyManagerProvider = sensorPrivacyManagerProvider;
  }

  @Override
  public SensorPrivacyController get() {
    return provideSensorPrivacyController(sensorPrivacyManagerProvider.get());
  }

  public static SystemUIDefaultModule_ProvideSensorPrivacyControllerFactory create(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    return new SystemUIDefaultModule_ProvideSensorPrivacyControllerFactory(sensorPrivacyManagerProvider);
  }

  public static SensorPrivacyController provideSensorPrivacyController(
      SensorPrivacyManager sensorPrivacyManager) {
    return Preconditions.checkNotNullFromProvides(SystemUIDefaultModule.provideSensorPrivacyController(sensorPrivacyManager));
  }
}
