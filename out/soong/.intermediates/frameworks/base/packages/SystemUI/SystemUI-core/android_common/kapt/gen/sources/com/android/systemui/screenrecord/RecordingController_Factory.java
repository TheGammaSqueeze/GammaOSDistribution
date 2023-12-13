package com.android.systemui.screenrecord;

import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.settings.UserContextProvider;
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
public final class RecordingController_Factory implements Factory<RecordingController> {
  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<UserContextProvider> userContextProvider;

  public RecordingController_Factory(Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<UserContextProvider> userContextProvider) {
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.userContextProvider = userContextProvider;
  }

  @Override
  public RecordingController get() {
    return newInstance(broadcastDispatcherProvider.get(), userContextProvider.get());
  }

  public static RecordingController_Factory create(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<UserContextProvider> userContextProvider) {
    return new RecordingController_Factory(broadcastDispatcherProvider, userContextProvider);
  }

  public static RecordingController newInstance(BroadcastDispatcher broadcastDispatcher,
      UserContextProvider userContextProvider) {
    return new RecordingController(broadcastDispatcher, userContextProvider);
  }
}
