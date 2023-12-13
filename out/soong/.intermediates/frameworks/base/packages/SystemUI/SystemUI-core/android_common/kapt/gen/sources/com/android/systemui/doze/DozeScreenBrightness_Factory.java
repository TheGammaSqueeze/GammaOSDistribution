package com.android.systemui.doze;

import android.content.Context;
import android.hardware.Sensor;
import android.os.Handler;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.policy.DevicePostureController;
import com.android.systemui.util.sensors.AsyncSensorManager;
import dagger.internal.Factory;
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
public final class DozeScreenBrightness_Factory implements Factory<DozeScreenBrightness> {
  private final Provider<Context> contextProvider;

  private final Provider<DozeMachine.Service> serviceProvider;

  private final Provider<AsyncSensorManager> sensorManagerProvider;

  private final Provider<Optional<Sensor>[]> lightSensorOptionalProvider;

  private final Provider<DozeHost> hostProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<DevicePostureController> devicePostureControllerProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

  public DozeScreenBrightness_Factory(Provider<Context> contextProvider,
      Provider<DozeMachine.Service> serviceProvider,
      Provider<AsyncSensorManager> sensorManagerProvider,
      Provider<Optional<Sensor>[]> lightSensorOptionalProvider, Provider<DozeHost> hostProvider,
      Provider<Handler> handlerProvider,
      Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<DevicePostureController> devicePostureControllerProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    this.contextProvider = contextProvider;
    this.serviceProvider = serviceProvider;
    this.sensorManagerProvider = sensorManagerProvider;
    this.lightSensorOptionalProvider = lightSensorOptionalProvider;
    this.hostProvider = hostProvider;
    this.handlerProvider = handlerProvider;
    this.alwaysOnDisplayPolicyProvider = alwaysOnDisplayPolicyProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.devicePostureControllerProvider = devicePostureControllerProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.unlockedScreenOffAnimationControllerProvider = unlockedScreenOffAnimationControllerProvider;
  }

  @Override
  public DozeScreenBrightness get() {
    return newInstance(contextProvider.get(), serviceProvider.get(), sensorManagerProvider.get(), lightSensorOptionalProvider.get(), hostProvider.get(), handlerProvider.get(), alwaysOnDisplayPolicyProvider.get(), wakefulnessLifecycleProvider.get(), dozeParametersProvider.get(), devicePostureControllerProvider.get(), dozeLogProvider.get(), unlockedScreenOffAnimationControllerProvider.get());
  }

  public static DozeScreenBrightness_Factory create(Provider<Context> contextProvider,
      Provider<DozeMachine.Service> serviceProvider,
      Provider<AsyncSensorManager> sensorManagerProvider,
      Provider<Optional<Sensor>[]> lightSensorOptionalProvider, Provider<DozeHost> hostProvider,
      Provider<Handler> handlerProvider,
      Provider<AlwaysOnDisplayPolicy> alwaysOnDisplayPolicyProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<DozeParameters> dozeParametersProvider,
      Provider<DevicePostureController> devicePostureControllerProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider) {
    return new DozeScreenBrightness_Factory(contextProvider, serviceProvider, sensorManagerProvider, lightSensorOptionalProvider, hostProvider, handlerProvider, alwaysOnDisplayPolicyProvider, wakefulnessLifecycleProvider, dozeParametersProvider, devicePostureControllerProvider, dozeLogProvider, unlockedScreenOffAnimationControllerProvider);
  }

  public static DozeScreenBrightness newInstance(Context context, DozeMachine.Service service,
      AsyncSensorManager sensorManager, Optional<Sensor>[] lightSensorOptional, DozeHost host,
      Handler handler, AlwaysOnDisplayPolicy alwaysOnDisplayPolicy,
      WakefulnessLifecycle wakefulnessLifecycle, DozeParameters dozeParameters,
      DevicePostureController devicePostureController, DozeLog dozeLog,
      UnlockedScreenOffAnimationController unlockedScreenOffAnimationController) {
    return new DozeScreenBrightness(context, service, sensorManager, lightSensorOptional, host, handler, alwaysOnDisplayPolicy, wakefulnessLifecycle, dozeParameters, devicePostureController, dozeLog, unlockedScreenOffAnimationController);
  }
}
