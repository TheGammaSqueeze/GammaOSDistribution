package com.android.systemui.statusbar.notification.row;

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
public final class NotifRemoteViewCacheImpl_Factory implements Factory<NotifRemoteViewCacheImpl> {
  private final Provider<CommonNotifCollection> collectionProvider;

  public NotifRemoteViewCacheImpl_Factory(Provider<CommonNotifCollection> collectionProvider) {
    this.collectionProvider = collectionProvider;
  }

  @Override
  public NotifRemoteViewCacheImpl get() {
    return newInstance(collectionProvider.get());
  }

  public static NotifRemoteViewCacheImpl_Factory create(
      Provider<CommonNotifCollection> collectionProvider) {
    return new NotifRemoteViewCacheImpl_Factory(collectionProvider);
  }

  public static NotifRemoteViewCacheImpl newInstance(CommonNotifCollection collection) {
    return new NotifRemoteViewCacheImpl(collection);
  }
}
