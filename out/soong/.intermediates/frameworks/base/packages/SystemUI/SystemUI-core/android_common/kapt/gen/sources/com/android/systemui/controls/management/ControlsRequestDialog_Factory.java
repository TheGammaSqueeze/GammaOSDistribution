package com.android.systemui.controls.management;

import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.controller.ControlsController;
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
public final class ControlsRequestDialog_Factory implements Factory<ControlsRequestDialog> {
  private final Provider<ControlsController> controllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ControlsListingController> controlsListingControllerProvider;

  public ControlsRequestDialog_Factory(Provider<ControlsController> controllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsListingController> controlsListingControllerProvider) {
    this.controllerProvider = controllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.controlsListingControllerProvider = controlsListingControllerProvider;
  }

  @Override
  public ControlsRequestDialog get() {
    return newInstance(controllerProvider.get(), broadcastDispatcherProvider.get(), controlsListingControllerProvider.get());
  }

  public static ControlsRequestDialog_Factory create(
      Provider<ControlsController> controllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsListingController> controlsListingControllerProvider) {
    return new ControlsRequestDialog_Factory(controllerProvider, broadcastDispatcherProvider, controlsListingControllerProvider);
  }

  public static ControlsRequestDialog newInstance(ControlsController controller,
      BroadcastDispatcher broadcastDispatcher,
      ControlsListingController controlsListingController) {
    return new ControlsRequestDialog(controller, broadcastDispatcher, controlsListingController);
  }
}
