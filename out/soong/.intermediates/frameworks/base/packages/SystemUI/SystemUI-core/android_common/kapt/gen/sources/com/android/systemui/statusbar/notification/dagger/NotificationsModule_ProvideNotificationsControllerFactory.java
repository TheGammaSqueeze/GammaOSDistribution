package com.android.systemui.statusbar.notification.dagger;

import android.content.Context;
import com.android.systemui.statusbar.notification.init.NotificationsController;
import com.android.systemui.statusbar.notification.init.NotificationsControllerImpl;
import com.android.systemui.statusbar.notification.init.NotificationsControllerStub;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class NotificationsModule_ProvideNotificationsControllerFactory implements Factory<NotificationsController> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationsControllerImpl> realControllerProvider;

  private final Provider<NotificationsControllerStub> stubControllerProvider;

  public NotificationsModule_ProvideNotificationsControllerFactory(
      Provider<Context> contextProvider,
      Provider<NotificationsControllerImpl> realControllerProvider,
      Provider<NotificationsControllerStub> stubControllerProvider) {
    this.contextProvider = contextProvider;
    this.realControllerProvider = realControllerProvider;
    this.stubControllerProvider = stubControllerProvider;
  }

  @Override
  public NotificationsController get() {
    return provideNotificationsController(contextProvider.get(), DoubleCheck.lazy(realControllerProvider), DoubleCheck.lazy(stubControllerProvider));
  }

  public static NotificationsModule_ProvideNotificationsControllerFactory create(
      Provider<Context> contextProvider,
      Provider<NotificationsControllerImpl> realControllerProvider,
      Provider<NotificationsControllerStub> stubControllerProvider) {
    return new NotificationsModule_ProvideNotificationsControllerFactory(contextProvider, realControllerProvider, stubControllerProvider);
  }

  public static NotificationsController provideNotificationsController(Context context,
      Lazy<NotificationsControllerImpl> realController,
      Lazy<NotificationsControllerStub> stubController) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotificationsController(context, realController, stubController));
  }
}
