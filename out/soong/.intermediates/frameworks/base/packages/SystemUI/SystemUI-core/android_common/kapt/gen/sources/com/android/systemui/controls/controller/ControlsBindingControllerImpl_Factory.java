package com.android.systemui.controls.controller;

import android.content.Context;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.concurrency.DelayableExecutor;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class ControlsBindingControllerImpl_Factory implements Factory<ControlsBindingControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DelayableExecutor> backgroundExecutorProvider;

  private final Provider<ControlsController> controllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public ControlsBindingControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DelayableExecutor> backgroundExecutorProvider,
      Provider<ControlsController> controllerProvider, Provider<UserTracker> userTrackerProvider) {
    this.contextProvider = contextProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.controllerProvider = controllerProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public ControlsBindingControllerImpl get() {
    return newInstance(contextProvider.get(), backgroundExecutorProvider.get(), DoubleCheck.lazy(controllerProvider), userTrackerProvider.get());
  }

  public static ControlsBindingControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DelayableExecutor> backgroundExecutorProvider,
      Provider<ControlsController> controllerProvider, Provider<UserTracker> userTrackerProvider) {
    return new ControlsBindingControllerImpl_Factory(contextProvider, backgroundExecutorProvider, controllerProvider, userTrackerProvider);
  }

  public static ControlsBindingControllerImpl newInstance(Context context,
      DelayableExecutor backgroundExecutor, Lazy<ControlsController> lazyController,
      UserTracker userTracker) {
    return new ControlsBindingControllerImpl(context, backgroundExecutor, lazyController, userTracker);
  }
}
