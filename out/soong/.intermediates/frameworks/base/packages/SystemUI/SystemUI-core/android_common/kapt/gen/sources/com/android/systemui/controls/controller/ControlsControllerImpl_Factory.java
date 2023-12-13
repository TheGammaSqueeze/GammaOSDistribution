package com.android.systemui.controls.controller;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.concurrency.DelayableExecutor;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class ControlsControllerImpl_Factory implements Factory<ControlsControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DelayableExecutor> executorProvider;

  private final Provider<ControlsUiController> uiControllerProvider;

  private final Provider<ControlsBindingController> bindingControllerProvider;

  private final Provider<ControlsListingController> listingControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Optional<ControlsFavoritePersistenceWrapper>> optionalWrapperProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  public ControlsControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DelayableExecutor> executorProvider,
      Provider<ControlsUiController> uiControllerProvider,
      Provider<ControlsBindingController> bindingControllerProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<ControlsFavoritePersistenceWrapper>> optionalWrapperProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<UserTracker> userTrackerProvider) {
    this.contextProvider = contextProvider;
    this.executorProvider = executorProvider;
    this.uiControllerProvider = uiControllerProvider;
    this.bindingControllerProvider = bindingControllerProvider;
    this.listingControllerProvider = listingControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.optionalWrapperProvider = optionalWrapperProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.userTrackerProvider = userTrackerProvider;
  }

  @Override
  public ControlsControllerImpl get() {
    return newInstance(contextProvider.get(), executorProvider.get(), uiControllerProvider.get(), bindingControllerProvider.get(), listingControllerProvider.get(), broadcastDispatcherProvider.get(), optionalWrapperProvider.get(), dumpManagerProvider.get(), userTrackerProvider.get());
  }

  public static ControlsControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DelayableExecutor> executorProvider,
      Provider<ControlsUiController> uiControllerProvider,
      Provider<ControlsBindingController> bindingControllerProvider,
      Provider<ControlsListingController> listingControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<ControlsFavoritePersistenceWrapper>> optionalWrapperProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<UserTracker> userTrackerProvider) {
    return new ControlsControllerImpl_Factory(contextProvider, executorProvider, uiControllerProvider, bindingControllerProvider, listingControllerProvider, broadcastDispatcherProvider, optionalWrapperProvider, dumpManagerProvider, userTrackerProvider);
  }

  public static ControlsControllerImpl newInstance(Context context, DelayableExecutor executor,
      ControlsUiController uiController, ControlsBindingController bindingController,
      ControlsListingController listingController, BroadcastDispatcher broadcastDispatcher,
      Optional<ControlsFavoritePersistenceWrapper> optionalWrapper, DumpManager dumpManager,
      UserTracker userTracker) {
    return new ControlsControllerImpl(context, executor, uiController, bindingController, listingController, broadcastDispatcher, optionalWrapper, dumpManager, userTracker);
  }
}
