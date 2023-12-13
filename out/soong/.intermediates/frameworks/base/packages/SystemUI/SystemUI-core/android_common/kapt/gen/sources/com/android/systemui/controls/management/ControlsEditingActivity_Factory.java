package com.android.systemui.controls.management;

import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.CustomIconCache;
import com.android.systemui.controls.controller.ControlsControllerImpl;
import com.android.systemui.controls.ui.ControlsUiController;
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
public final class ControlsEditingActivity_Factory implements Factory<ControlsEditingActivity> {
  private final Provider<ControlsControllerImpl> controllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<CustomIconCache> customIconCacheProvider;

  private final Provider<ControlsUiController> uiControllerProvider;

  public ControlsEditingActivity_Factory(Provider<ControlsControllerImpl> controllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CustomIconCache> customIconCacheProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    this.controllerProvider = controllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.customIconCacheProvider = customIconCacheProvider;
    this.uiControllerProvider = uiControllerProvider;
  }

  @Override
  public ControlsEditingActivity get() {
    return newInstance(controllerProvider.get(), broadcastDispatcherProvider.get(), customIconCacheProvider.get(), uiControllerProvider.get());
  }

  public static ControlsEditingActivity_Factory create(
      Provider<ControlsControllerImpl> controllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<CustomIconCache> customIconCacheProvider,
      Provider<ControlsUiController> uiControllerProvider) {
    return new ControlsEditingActivity_Factory(controllerProvider, broadcastDispatcherProvider, customIconCacheProvider, uiControllerProvider);
  }

  public static ControlsEditingActivity newInstance(ControlsControllerImpl controller,
      BroadcastDispatcher broadcastDispatcher, CustomIconCache customIconCache,
      ControlsUiController uiController) {
    return new ControlsEditingActivity(controller, broadcastDispatcher, customIconCache, uiController);
  }
}
