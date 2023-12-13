package com.android.systemui.statusbar.notification.row.dagger;

import android.content.Context;
import android.service.notification.StatusBarNotification;
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
public final class ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory implements Factory<String> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarNotification> statusBarNotificationProvider;

  public ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory(
      Provider<Context> contextProvider,
      Provider<StatusBarNotification> statusBarNotificationProvider) {
    this.contextProvider = contextProvider;
    this.statusBarNotificationProvider = statusBarNotificationProvider;
  }

  @Override
  public String get() {
    return provideAppName(contextProvider.get(), statusBarNotificationProvider.get());
  }

  public static ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory create(
      Provider<Context> contextProvider,
      Provider<StatusBarNotification> statusBarNotificationProvider) {
    return new ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory(contextProvider, statusBarNotificationProvider);
  }

  public static String provideAppName(Context context,
      StatusBarNotification statusBarNotification) {
    return Preconditions.checkNotNullFromProvides(ExpandableNotificationRowComponent.ExpandableNotificationRowModule.provideAppName(context, statusBarNotification));
  }
}
