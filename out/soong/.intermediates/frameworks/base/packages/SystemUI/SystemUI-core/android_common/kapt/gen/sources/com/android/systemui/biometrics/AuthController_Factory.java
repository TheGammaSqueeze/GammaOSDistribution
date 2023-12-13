package com.android.systemui.biometrics;

import android.app.ActivityTaskManager;
import android.content.Context;
import android.hardware.display.DisplayManager;
import android.hardware.face.FaceManager;
import android.hardware.fingerprint.FingerprintManager;
import android.os.Handler;
import android.view.WindowManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.util.concurrency.Execution;
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
public final class AuthController_Factory implements Factory<AuthController> {
  private final Provider<Context> contextProvider;

  private final Provider<Execution> executionProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ActivityTaskManager> activityTaskManagerProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<FingerprintManager> fingerprintManagerProvider;

  private final Provider<FaceManager> faceManagerProvider;

  private final Provider<UdfpsController> udfpsControllerFactoryProvider;

  private final Provider<SidefpsController> sidefpsControllerFactoryProvider;

  private final Provider<DisplayManager> displayManagerProvider;

  private final Provider<Handler> handlerProvider;

  public AuthController_Factory(Provider<Context> contextProvider,
      Provider<Execution> executionProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<FaceManager> faceManagerProvider,
      Provider<UdfpsController> udfpsControllerFactoryProvider,
      Provider<SidefpsController> sidefpsControllerFactoryProvider,
      Provider<DisplayManager> displayManagerProvider, Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.executionProvider = executionProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.activityTaskManagerProvider = activityTaskManagerProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.fingerprintManagerProvider = fingerprintManagerProvider;
    this.faceManagerProvider = faceManagerProvider;
    this.udfpsControllerFactoryProvider = udfpsControllerFactoryProvider;
    this.sidefpsControllerFactoryProvider = sidefpsControllerFactoryProvider;
    this.displayManagerProvider = displayManagerProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public AuthController get() {
    return newInstance(contextProvider.get(), executionProvider.get(), commandQueueProvider.get(), activityTaskManagerProvider.get(), windowManagerProvider.get(), fingerprintManagerProvider.get(), faceManagerProvider.get(), udfpsControllerFactoryProvider, sidefpsControllerFactoryProvider, displayManagerProvider.get(), handlerProvider.get());
  }

  public static AuthController_Factory create(Provider<Context> contextProvider,
      Provider<Execution> executionProvider, Provider<CommandQueue> commandQueueProvider,
      Provider<ActivityTaskManager> activityTaskManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<FingerprintManager> fingerprintManagerProvider,
      Provider<FaceManager> faceManagerProvider,
      Provider<UdfpsController> udfpsControllerFactoryProvider,
      Provider<SidefpsController> sidefpsControllerFactoryProvider,
      Provider<DisplayManager> displayManagerProvider, Provider<Handler> handlerProvider) {
    return new AuthController_Factory(contextProvider, executionProvider, commandQueueProvider, activityTaskManagerProvider, windowManagerProvider, fingerprintManagerProvider, faceManagerProvider, udfpsControllerFactoryProvider, sidefpsControllerFactoryProvider, displayManagerProvider, handlerProvider);
  }

  public static AuthController newInstance(Context context, Execution execution,
      CommandQueue commandQueue, ActivityTaskManager activityTaskManager,
      WindowManager windowManager, FingerprintManager fingerprintManager, FaceManager faceManager,
      Provider<UdfpsController> udfpsControllerFactory,
      Provider<SidefpsController> sidefpsControllerFactory, DisplayManager displayManager,
      Handler handler) {
    return new AuthController(context, execution, commandQueue, activityTaskManager, windowManager, fingerprintManager, faceManager, udfpsControllerFactory, sidefpsControllerFactory, displayManager, handler);
  }
}
