package com.android.systemui.controls.management;

import android.content.Context;
import com.android.systemui.settings.UserTracker;
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
public final class ControlsListingControllerImpl_Factory implements Factory<ControlsListingControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public ControlsListingControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Executor> executorProvider, Provider<UserTracker> userTrackerProvider) {
    this.contextProvider = contextProvider;
    this.executorProvider = executorProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public ControlsListingControllerImpl get() {
    return newInstance(contextProvider.get(), executorProvider.get(), userTrackerProvider.get());
  }

  public static ControlsListingControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Executor> executorProvider, Provider<UserTracker> userTrackerProvider) {
    return new ControlsListingControllerImpl_Factory(contextProvider, executorProvider, userTrackerProvider);
  }

  public static ControlsListingControllerImpl newInstance(Context context, Executor executor,
      UserTracker userTracker) {
    return new ControlsListingControllerImpl(context, executor, userTracker);
  }
}
