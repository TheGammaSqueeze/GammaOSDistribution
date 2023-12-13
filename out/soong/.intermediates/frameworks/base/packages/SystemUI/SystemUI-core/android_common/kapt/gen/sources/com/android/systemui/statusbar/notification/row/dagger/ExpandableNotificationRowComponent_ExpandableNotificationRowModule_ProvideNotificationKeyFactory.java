package com.android.systemui.statusbar.notification.row.dagger;

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
public final class ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory implements Factory<String> {
  private final Provider<StatusBarNotification> statusBarNotificationProvider;

  public ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory(
      Provider<StatusBarNotification> statusBarNotificationProvider) {
    this.statusBarNotificationProvider = statusBarNotificationProvider;
  }

  @Override
  public String get() {
    return provideNotificationKey(statusBarNotificationProvider.get());
  }

  public static ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory create(
      Provider<StatusBarNotification> statusBarNotificationProvider) {
    return new ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory(statusBarNotificationProvider);
  }

  public static String provideNotificationKey(StatusBarNotification statusBarNotification) {
    return Preconditions.checkNotNullFromProvides(ExpandableNotificationRowComponent.ExpandableNotificationRowModule.provideNotificationKey(statusBarNotification));
  }
}
