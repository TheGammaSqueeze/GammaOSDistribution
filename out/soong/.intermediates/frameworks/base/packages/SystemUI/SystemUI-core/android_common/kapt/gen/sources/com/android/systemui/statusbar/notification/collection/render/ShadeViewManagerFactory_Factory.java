package com.android.systemui.statusbar.notification.collection.render;

import android.content.Context;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
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
public final class ShadeViewManagerFactory_Factory implements Factory<ShadeViewManagerFactory> {
  private final Provider<Context> contextProvider;

  private final Provider<ShadeViewDifferLogger> loggerProvider;

  private final Provider<NotifViewBarn> viewBarnProvider;

  private final Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

  public ShadeViewManagerFactory_Factory(Provider<Context> contextProvider,
      Provider<ShadeViewDifferLogger> loggerProvider, Provider<NotifViewBarn> viewBarnProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider) {
    this.contextProvider = contextProvider;
    this.loggerProvider = loggerProvider;
    this.viewBarnProvider = viewBarnProvider;
    this.notificationIconAreaControllerProvider = notificationIconAreaControllerProvider;
  }

  @Override
  public ShadeViewManagerFactory get() {
    return newInstance(contextProvider.get(), loggerProvider.get(), viewBarnProvider.get(), notificationIconAreaControllerProvider.get());
  }

  public static ShadeViewManagerFactory_Factory create(Provider<Context> contextProvider,
      Provider<ShadeViewDifferLogger> loggerProvider, Provider<NotifViewBarn> viewBarnProvider,
      Provider<NotificationIconAreaController> notificationIconAreaControllerProvider) {
    return new ShadeViewManagerFactory_Factory(contextProvider, loggerProvider, viewBarnProvider, notificationIconAreaControllerProvider);
  }

  public static ShadeViewManagerFactory newInstance(Context context, ShadeViewDifferLogger logger,
      NotifViewBarn viewBarn, NotificationIconAreaController notificationIconAreaController) {
    return new ShadeViewManagerFactory(context, logger, viewBarn, notificationIconAreaController);
  }
}
