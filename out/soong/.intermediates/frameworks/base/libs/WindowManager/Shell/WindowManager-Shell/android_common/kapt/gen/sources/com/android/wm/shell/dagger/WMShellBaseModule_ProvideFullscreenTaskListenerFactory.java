package com.android.wm.shell.dagger;

import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.fullscreen.FullscreenTaskListener;
import com.android.wm.shell.fullscreen.FullscreenUnfoldController;
import com.android.wm.shell.recents.RecentTasksController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellBaseModule_ProvideFullscreenTaskListenerFactory implements Factory<FullscreenTaskListener> {
  private final Provider<SyncTransactionQueue> syncQueueProvider;

  private final Provider<Optional<FullscreenUnfoldController>> optionalFullscreenUnfoldControllerProvider;

  private final Provider<Optional<RecentTasksController>> recentTasksOptionalProvider;

  public WMShellBaseModule_ProvideFullscreenTaskListenerFactory(
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<Optional<FullscreenUnfoldController>> optionalFullscreenUnfoldControllerProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider) {
    this.syncQueueProvider = syncQueueProvider;
    this.optionalFullscreenUnfoldControllerProvider = optionalFullscreenUnfoldControllerProvider;
    this.recentTasksOptionalProvider = recentTasksOptionalProvider;
  }

  @Override
  public FullscreenTaskListener get() {
    return provideFullscreenTaskListener(syncQueueProvider.get(), optionalFullscreenUnfoldControllerProvider.get(), recentTasksOptionalProvider.get());
  }

  public static WMShellBaseModule_ProvideFullscreenTaskListenerFactory create(
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<Optional<FullscreenUnfoldController>> optionalFullscreenUnfoldControllerProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider) {
    return new WMShellBaseModule_ProvideFullscreenTaskListenerFactory(syncQueueProvider, optionalFullscreenUnfoldControllerProvider, recentTasksOptionalProvider);
  }

  public static FullscreenTaskListener provideFullscreenTaskListener(SyncTransactionQueue syncQueue,
      Optional<FullscreenUnfoldController> optionalFullscreenUnfoldController,
      Optional<RecentTasksController> recentTasksOptional) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideFullscreenTaskListener(syncQueue, optionalFullscreenUnfoldController, recentTasksOptional));
  }
}
