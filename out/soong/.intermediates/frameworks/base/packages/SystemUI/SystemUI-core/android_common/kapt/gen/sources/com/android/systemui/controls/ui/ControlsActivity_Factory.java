package com.android.systemui.controls.ui;

import com.android.systemui.broadcast.BroadcastDispatcher;
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
public final class ControlsActivity_Factory implements Factory<ControlsActivity> {
  private final Provider<ControlsUiController> uiControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public ControlsActivity_Factory(Provider<ControlsUiController> uiControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.uiControllerProvider = uiControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public ControlsActivity get() {
    return newInstance(uiControllerProvider.get(), broadcastDispatcherProvider.get());
  }

  public static ControlsActivity_Factory create(Provider<ControlsUiController> uiControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new ControlsActivity_Factory(uiControllerProvider, broadcastDispatcherProvider);
  }

  public static ControlsActivity newInstance(ControlsUiController uiController,
      BroadcastDispatcher broadcastDispatcher) {
    return new ControlsActivity(uiController, broadcastDispatcher);
  }
}
