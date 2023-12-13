package com.android.wm.shell.dagger;

import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.freeform.FreeformTaskListener;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellModule_ProvideFreeformTaskListenerFactory implements Factory<FreeformTaskListener> {
  private final Provider<SyncTransactionQueue> syncQueueProvider;

  public WMShellModule_ProvideFreeformTaskListenerFactory(
      Provider<SyncTransactionQueue> syncQueueProvider) {
    this.syncQueueProvider = syncQueueProvider;
  }

  @Override
  public FreeformTaskListener get() {
    return provideFreeformTaskListener(syncQueueProvider.get());
  }

  public static WMShellModule_ProvideFreeformTaskListenerFactory create(
      Provider<SyncTransactionQueue> syncQueueProvider) {
    return new WMShellModule_ProvideFreeformTaskListenerFactory(syncQueueProvider);
  }

  public static FreeformTaskListener provideFreeformTaskListener(SyncTransactionQueue syncQueue) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideFreeformTaskListener(syncQueue));
  }
}
