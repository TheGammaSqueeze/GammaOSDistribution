package com.android.systemui.statusbar.notification.row;

import android.os.Looper;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
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
public final class NotifBindPipeline_Factory implements Factory<NotifBindPipeline> {
  private final Provider<CommonNotifCollection> collectionProvider;

  private final Provider<NotifBindPipelineLogger> loggerProvider;

  private final Provider<Looper> mainLooperProvider;

  public NotifBindPipeline_Factory(Provider<CommonNotifCollection> collectionProvider,
      Provider<NotifBindPipelineLogger> loggerProvider, Provider<Looper> mainLooperProvider) {
    this.collectionProvider = collectionProvider;
    this.loggerProvider = loggerProvider;
    this.mainLooperProvider = mainLooperProvider;
  }

  @Override
  public NotifBindPipeline get() {
    return newInstance(collectionProvider.get(), loggerProvider.get(), mainLooperProvider.get());
  }

  public static NotifBindPipeline_Factory create(Provider<CommonNotifCollection> collectionProvider,
      Provider<NotifBindPipelineLogger> loggerProvider, Provider<Looper> mainLooperProvider) {
    return new NotifBindPipeline_Factory(collectionProvider, loggerProvider, mainLooperProvider);
  }

  public static NotifBindPipeline newInstance(CommonNotifCollection collection,
      NotifBindPipelineLogger logger, Looper mainLooper) {
    return new NotifBindPipeline(collection, logger, mainLooper);
  }
}
