package com.android.systemui.sensorprivacy.television;

import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
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
public final class TvUnblockSensorActivity_Factory implements Factory<TvUnblockSensorActivity> {
  private final Provider<IndividualSensorPrivacyController> individualSensorPrivacyControllerProvider;

  public TvUnblockSensorActivity_Factory(
      Provider<IndividualSensorPrivacyController> individualSensorPrivacyControllerProvider) {
    this.individualSensorPrivacyControllerProvider = individualSensorPrivacyControllerProvider;
  }

  @Override
  public TvUnblockSensorActivity get() {
    return newInstance(individualSensorPrivacyControllerProvider.get());
  }

  public static TvUnblockSensorActivity_Factory create(
      Provider<IndividualSensorPrivacyController> individualSensorPrivacyControllerProvider) {
    return new TvUnblockSensorActivity_Factory(individualSensorPrivacyControllerProvider);
  }

  public static TvUnblockSensorActivity newInstance(
      IndividualSensorPrivacyController individualSensorPrivacyController) {
    return new TvUnblockSensorActivity(individualSensorPrivacyController);
  }
}
