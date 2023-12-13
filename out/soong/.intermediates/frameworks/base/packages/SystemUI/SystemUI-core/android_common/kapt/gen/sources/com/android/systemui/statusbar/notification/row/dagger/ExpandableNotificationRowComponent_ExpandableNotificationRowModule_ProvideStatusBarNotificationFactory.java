package com.android.systemui.statusbar.notification.row.dagger;

import android.service.notification.StatusBarNotification;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
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
public final class ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory implements Factory<StatusBarNotification> {
  private final Provider<NotificationEntry> notificationEntryProvider;

  public ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory(
      Provider<NotificationEntry> notificationEntryProvider) {
    this.notificationEntryProvider = notificationEntryProvider;
  }

  @Override
  public StatusBarNotification get() {
    return provideStatusBarNotification(notificationEntryProvider.get());
  }

  public static ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory create(
      Provider<NotificationEntry> notificationEntryProvider) {
    return new ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory(notificationEntryProvider);
  }

  public static StatusBarNotification provideStatusBarNotification(
      NotificationEntry notificationEntry) {
    return Preconditions.checkNotNullFromProvides(ExpandableNotificationRowComponent.ExpandableNotificationRowModule.provideStatusBarNotification(notificationEntry));
  }
}
