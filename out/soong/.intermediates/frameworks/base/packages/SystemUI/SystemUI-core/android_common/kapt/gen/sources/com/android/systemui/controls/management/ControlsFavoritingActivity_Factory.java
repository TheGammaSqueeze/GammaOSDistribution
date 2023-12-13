package com.android.systemui.controls.management;

import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.controller.ControlsControllerImpl;
import com.android.systemui.controls.ui.ControlsUiController;
import dagger.internal.Factory;
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
public final class ControlsFavoritingActivity_Factory implements Factory<ControlsFavoritingActivity> {
  private final Provider<Executor> executorProvider;

  private final Provider<ControlsControllerImpl> controllerProvider;

  private final Provider<ControlsListingController> listingControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ControlsUiController> uiControllerProvider;

  public ControlsFavoritingActivity_Factory(Provider<Executor> executorProvider,
      Provider<ControlsControllerImpl> controllerProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    this.executorProvider = executorProvider;
    this.controllerProvider = controllerProvider;
    this.listingControllerProvider = listingControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.uiControllerProvider = uiControllerProvider;
  }

  @Override
  public ControlsFavoritingActivity get() {
    return newInstance(executorProvider.get(), controllerProvider.get(), listingControllerProvider.get(), broadcastDispatcherProvider.get(), uiControllerProvider.get());
  }

  public static ControlsFavoritingActivity_Factory create(Provider<Executor> executorProvider,
      Provider<ControlsControllerImpl> controllerProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    return new ControlsFavoritingActivity_Factory(executorProvider, controllerProvider, listingControllerProvider, broadcastDispatcherProvider, uiControllerProvider);
  }

  public static ControlsFavoritingActivity newInstance(Executor executor,
      ControlsControllerImpl controller, ControlsListingController listingController,
      BroadcastDispatcher broadcastDispatcher, ControlsUiController uiController) {
    return new ControlsFavoritingActivity(executor, controller, listingController, broadcastDispatcher, uiController);
  }
}
