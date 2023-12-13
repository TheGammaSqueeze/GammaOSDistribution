package com.android.systemui.sensorprivacy;

import android.os.Handler;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class SensorUseStartedActivity_Factory implements Factory<SensorUseStartedActivity> {
  private final Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<Handler> bgHandlerProvider;

  public SensorUseStartedActivity_Factory(
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<Handler> bgHandlerProvider) {
    this.sensorPrivacyControllerProvider = sensorPrivacyControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public SensorUseStartedActivity get() {
    return newInstance(sensorPrivacyControllerProvider.get(), keyguardStateControllerProvider.get(), keyguardDismissUtilProvider.get(), bgHandlerProvider.get());
  }

  public static SensorUseStartedActivity_Factory create(
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<Handler> bgHandlerProvider) {
    return new SensorUseStartedActivity_Factory(sensorPrivacyControllerProvider, keyguardStateControllerProvider, keyguardDismissUtilProvider, bgHandlerProvider);
  }

  public static SensorUseStartedActivity newInstance(
      IndividualSensorPrivacyController sensorPrivacyController,
      KeyguardStateController keyguardStateController, KeyguardDismissUtil keyguardDismissUtil,
      Handler bgHandler) {
    return new SensorUseStartedActivity(sensorPrivacyController, keyguardStateController, keyguardDismissUtil, bgHandler);
  }
}
