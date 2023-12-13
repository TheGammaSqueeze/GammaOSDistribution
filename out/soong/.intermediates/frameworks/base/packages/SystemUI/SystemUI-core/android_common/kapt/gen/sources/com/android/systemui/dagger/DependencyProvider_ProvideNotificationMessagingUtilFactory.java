package com.android.systemui.dagger;

import android.content.Context;
import com.android.internal.util.NotificationMessagingUtil;
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
public final class DependencyProvider_ProvideNotificationMessagingUtilFactory implements Factory<NotificationMessagingUtil> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideNotificationMessagingUtilFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public NotificationMessagingUtil get() {
    return provideNotificationMessagingUtil(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideNotificationMessagingUtilFactory create(
      DependencyProvider module, Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideNotificationMessagingUtilFactory(module, contextProvider);
  }

  public static NotificationMessagingUtil provideNotificationMessagingUtil(
      DependencyProvider instance, Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideNotificationMessagingUtil(context));
  }
}
