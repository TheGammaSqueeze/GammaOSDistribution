package com.android.systemui.statusbar.notification.collection;

import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.statusbar.notification.row.NotifInflationErrorManager;
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
public final class NotifInflaterImpl_Factory implements Factory<NotifInflaterImpl> {
  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<NotifInflationErrorManager> errorManagerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  public NotifInflaterImpl_Factory(Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider) {
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.notifCollectionProvider = notifCollectionProvider;
    this.errorManagerProvider = errorManagerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
  }

  @Override
  public NotifInflaterImpl get() {
    return newInstance(statusBarServiceProvider.get(), notifCollectionProvider.get(), errorManagerProvider.get(), notifPipelineProvider.get());
  }

  public static NotifInflaterImpl_Factory create(
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<NotifInflationErrorManager> errorManagerProvider,
      Provider<NotifPipeline> notifPipelineProvider) {
    return new NotifInflaterImpl_Factory(statusBarServiceProvider, notifCollectionProvider, errorManagerProvider, notifPipelineProvider);
  }

  public static NotifInflaterImpl newInstance(IStatusBarService statusBarService,
      NotifCollection notifCollection, NotifInflationErrorManager errorManager,
      NotifPipeline notifPipeline) {
    return new NotifInflaterImpl(statusBarService, notifCollection, errorManager, notifPipeline);
  }
}
