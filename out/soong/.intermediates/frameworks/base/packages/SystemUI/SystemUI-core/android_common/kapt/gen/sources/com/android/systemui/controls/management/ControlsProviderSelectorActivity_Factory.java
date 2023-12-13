package com.android.systemui.controls.management;

import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.controller.ControlsController;
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
public final class ControlsProviderSelectorActivity_Factory implements Factory<ControlsProviderSelectorActivity> {
  private final Provider<Executor> executorProvider;

  private final Provider<Executor> backExecutorProvider;

  private final Provider<ControlsListingController> listingControllerProvider;

  private final Provider<ControlsController> controlsControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<ControlsUiController> uiControllerProvider;

  public ControlsProviderSelectorActivity_Factory(Provider<Executor> executorProvider,
      Provider<Executor> backExecutorProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<ControlsController> controlsControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    this.executorProvider = executorProvider;
    this.backExecutorProvider = backExecutorProvider;
    this.listingControllerProvider = listingControllerProvider;
    this.controlsControllerProvider = controlsControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.uiControllerProvider = uiControllerProvider;
  }

  @Override
  public ControlsProviderSelectorActivity get() {
    return newInstance(executorProvider.get(), backExecutorProvider.get(), listingControllerProvider.get(), controlsControllerProvider.get(), broadcastDispatcherProvider.get(), uiControllerProvider.get());
  }

  public static ControlsProviderSelectorActivity_Factory create(Provider<Executor> executorProvider,
      Provider<Executor> backExecutorProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<ControlsController> controlsControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    return new ControlsProviderSelectorActivity_Factory(executorProvider, backExecutorProvider, listingControllerProvider, controlsControllerProvider, broadcastDispatcherProvider, uiControllerProvider);
  }

  public static ControlsProviderSelectorActivity newInstance(Executor executor,
      Executor backExecutor, ControlsListingController listingController,
      ControlsController controlsController, BroadcastDispatcher broadcastDispatcher,
      ControlsUiController uiController) {
    return new ControlsProviderSelectorActivity(executor, backExecutor, listingController, controlsController, broadcastDispatcher, uiController);
  }
}
