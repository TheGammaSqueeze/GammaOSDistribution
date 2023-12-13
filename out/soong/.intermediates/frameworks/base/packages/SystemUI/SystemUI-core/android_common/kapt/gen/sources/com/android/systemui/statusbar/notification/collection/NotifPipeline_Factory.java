package com.android.systemui.statusbar.notification.collection;

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
public final class NotifPipeline_Factory implements Factory<NotifPipeline> {
  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<ShadeListBuilder> shadeListBuilderProvider;

  public NotifPipeline_Factory(Provider<NotifCollection> notifCollectionProvider,
      Provider<ShadeListBuilder> shadeListBuilderProvider) {
    this.notifCollectionProvider = notifCollectionProvider;
    this.shadeListBuilderProvider = shadeListBuilderProvider;
  }

  @Override
  public NotifPipeline get() {
    return newInstance(notifCollectionProvider.get(), shadeListBuilderProvider.get());
  }

  public static NotifPipeline_Factory create(Provider<NotifCollection> notifCollectionProvider,
      Provider<ShadeListBuilder> shadeListBuilderProvider) {
    return new NotifPipeline_Factory(notifCollectionProvider, shadeListBuilderProvider);
  }

  public static NotifPipeline newInstance(NotifCollection notifCollection,
      ShadeListBuilder shadeListBuilder) {
    return new NotifPipeline(notifCollection, shadeListBuilder);
  }
}
