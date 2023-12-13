package com.android.systemui.doze;

import android.os.Handler;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.biometrics.UdfpsController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.util.wakelock.WakeLock;
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
public final class DozeScreenState_Factory implements Factory<DozeScreenState> {
  private final Provider<DozeMachine.Service> serviceProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<DozeHost> hostProvider;

  private final Provider<DozeParameters> parametersProvider;

  private final Provider<WakeLock> wakeLockProvider;

  private final Provider<AuthController> authControllerProvider;

  private final Provider<UdfpsController> udfpsControllerProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<DozeScreenBrightness> dozeScreenBrightnessProvider;

  public DozeScreenState_Factory(Provider<DozeMachine.Service> serviceProvider,
      Provider<Handler> handlerProvider, Provider<DozeHost> hostProvider,
      Provider<DozeParameters> parametersProvider, Provider<WakeLock> wakeLockProvider,
      Provider<AuthController> authControllerProvider,
      Provider<UdfpsController> udfpsControllerProvider, Provider<DozeLog> dozeLogProvider,
      Provider<DozeScreenBrightness> dozeScreenBrightnessProvider) {
    this.serviceProvider = serviceProvider;
    this.handlerProvider = handlerProvider;
    this.hostProvider = hostProvider;
    this.parametersProvider = parametersProvider;
    this.wakeLockProvider = wakeLockProvider;
    this.authControllerProvider = authControllerProvider;
    this.udfpsControllerProvider = udfpsControllerProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.dozeScreenBrightnessProvider = dozeScreenBrightnessProvider;
  }

  @Override
  public DozeScreenState get() {
    return newInstance(serviceProvider.get(), handlerProvider.get(), hostProvider.get(), parametersProvider.get(), wakeLockProvider.get(), authControllerProvider.get(), udfpsControllerProvider, dozeLogProvider.get(), dozeScreenBrightnessProvider.get());
  }

  public static DozeScreenState_Factory create(Provider<DozeMachine.Service> serviceProvider,
      Provider<Handler> handlerProvider, Provider<DozeHost> hostProvider,
      Provider<DozeParameters> parametersProvider, Provider<WakeLock> wakeLockProvider,
      Provider<AuthController> authControllerProvider,
      Provider<UdfpsController> udfpsControllerProvider, Provider<DozeLog> dozeLogProvider,
      Provider<DozeScreenBrightness> dozeScreenBrightnessProvider) {
    return new DozeScreenState_Factory(serviceProvider, handlerProvider, hostProvider, parametersProvider, wakeLockProvider, authControllerProvider, udfpsControllerProvider, dozeLogProvider, dozeScreenBrightnessProvider);
  }

  public static DozeScreenState newInstance(DozeMachine.Service service, Handler handler,
      DozeHost host, DozeParameters parameters, WakeLock wakeLock, AuthController authController,
      Provider<UdfpsController> udfpsControllerProvider, DozeLog dozeLog,
      DozeScreenBrightness dozeScreenBrightness) {
    return new DozeScreenState(service, handler, host, parameters, wakeLock, authController, udfpsControllerProvider, dozeLog, dozeScreenBrightness);
  }
}
