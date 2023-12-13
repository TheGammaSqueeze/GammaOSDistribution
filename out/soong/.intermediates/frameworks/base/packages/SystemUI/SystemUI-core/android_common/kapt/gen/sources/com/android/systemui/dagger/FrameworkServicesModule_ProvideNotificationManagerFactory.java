package com.android.systemui.dagger;

import android.app.NotificationManager;
import android.content.Context;
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
public final class FrameworkServicesModule_ProvideNotificationManagerFactory implements Factory<NotificationManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideNotificationManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public NotificationManager get() {
    return provideNotificationManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideNotificationManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideNotificationManagerFactory(contextProvider);
  }

  public static NotificationManager provideNotificationManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideNotificationManager(context));
  }
}
