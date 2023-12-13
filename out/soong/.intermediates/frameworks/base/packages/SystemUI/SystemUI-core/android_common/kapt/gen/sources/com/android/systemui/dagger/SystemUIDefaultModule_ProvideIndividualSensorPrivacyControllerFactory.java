package com.android.systemui.dagger;

import android.hardware.SensorPrivacyManager;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
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
public final class SystemUIDefaultModule_ProvideIndividualSensorPrivacyControllerFactory implements Factory<IndividualSensorPrivacyController> {
  private final Provider<SensorPrivacyManager> sensorPrivacyManagerProvider;

  public SystemUIDefaultModule_ProvideIndividualSensorPrivacyControllerFactory(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    this.sensorPrivacyManagerProvider = sensorPrivacyManagerProvider;
  }

  @Override
  public IndividualSensorPrivacyController get() {
    return provideIndividualSensorPrivacyController(sensorPrivacyManagerProvider.get());
  }

  public static SystemUIDefaultModule_ProvideIndividualSensorPrivacyControllerFactory create(
      Provider<SensorPrivacyManager> sensorPrivacyManagerProvider) {
    return new SystemUIDefaultModule_ProvideIndividualSensorPrivacyControllerFactory(sensorPrivacyManagerProvider);
  }

  public static IndividualSensorPrivacyController provideIndividualSensorPrivacyController(
      SensorPrivacyManager sensorPrivacyManager) {
    return Preconditions.checkNotNullFromProvides(SystemUIDefaultModule.provideIndividualSensorPrivacyController(sensorPrivacyManager));
  }
}
