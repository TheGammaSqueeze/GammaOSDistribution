package com.android.systemui.unfold;

import android.content.Context;
import android.hardware.devicestate.DeviceStateManager;
import android.hardware.display.DisplayManager;
import android.os.Handler;
import com.android.wm.shell.displayareahelper.DisplayAreaHelper;
import dagger.internal.Factory;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class UnfoldLightRevealOverlayAnimation_Factory implements Factory<UnfoldLightRevealOverlayAnimation> {
  private final Provider<Context> contextProvider;

  private final Provider<DeviceStateManager> deviceStateManagerProvider;

  private final Provider<DisplayManager> displayManagerProvider;

  private final Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider;

  private final Provider<Optional<DisplayAreaHelper>> displayAreaHelperProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  public UnfoldLightRevealOverlayAnimation_Factory(Provider<Context> contextProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<DisplayManager> displayManagerProvider,
      Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider,
      Provider<Optional<DisplayAreaHelper>> displayAreaHelperProvider,
      Provider<Executor> executorProvider, Provider<Handler> handlerProvider,
      Provider<Executor> backgroundExecutorProvider) {
    this.contextProvider = contextProvider;
    this.deviceStateManagerProvider = deviceStateManagerProvider;
    this.displayManagerProvider = displayManagerProvider;
    this.unfoldTransitionProgressProvider = unfoldTransitionProgressProvider;
    this.displayAreaHelperProvider = displayAreaHelperProvider;
    this.executorProvider = executorProvider;
    this.handlerProvider = handlerProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
  }

  @Override
  public UnfoldLightRevealOverlayAnimation get() {
    return newInstance(contextProvider.get(), deviceStateManagerProvider.get(), displayManagerProvider.get(), unfoldTransitionProgressProvider.get(), displayAreaHelperProvider.get(), executorProvider.get(), handlerProvider.get(), backgroundExecutorProvider.get());
  }

  public static UnfoldLightRevealOverlayAnimation_Factory create(Provider<Context> contextProvider,
      Provider<DeviceStateManager> deviceStateManagerProvider,
      Provider<DisplayManager> displayManagerProvider,
      Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider,
      Provider<Optional<DisplayAreaHelper>> displayAreaHelperProvider,
      Provider<Executor> executorProvider, Provider<Handler> handlerProvider,
      Provider<Executor> backgroundExecutorProvider) {
    return new UnfoldLightRevealOverlayAnimation_Factory(contextProvider, deviceStateManagerProvider, displayManagerProvider, unfoldTransitionProgressProvider, displayAreaHelperProvider, executorProvider, handlerProvider, backgroundExecutorProvider);
  }

  public static UnfoldLightRevealOverlayAnimation newInstance(Context context,
      DeviceStateManager deviceStateManager, DisplayManager displayManager,
      UnfoldTransitionProgressProvider unfoldTransitionProgressProvider,
      Optional<DisplayAreaHelper> displayAreaHelper, Executor executor, Handler handler,
      Executor backgroundExecutor) {
    return new UnfoldLightRevealOverlayAnimation(context, deviceStateManager, displayManager, unfoldTransitionProgressProvider, displayAreaHelper, executor, handler, backgroundExecutor);
  }
}
