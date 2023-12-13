package com.android.systemui.statusbar.notification.interruption;

import com.android.internal.util.NotificationMessagingUtil;
import com.android.systemui.statusbar.notification.row.RowContentBindStage;
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
public final class HeadsUpViewBinder_Factory implements Factory<HeadsUpViewBinder> {
  private final Provider<NotificationMessagingUtil> notificationMessagingUtilProvider;

  private final Provider<RowContentBindStage> bindStageProvider;

  public HeadsUpViewBinder_Factory(
      Provider<NotificationMessagingUtil> notificationMessagingUtilProvider,
      Provider<RowContentBindStage> bindStageProvider) {
    this.notificationMessagingUtilProvider = notificationMessagingUtilProvider;
    this.bindStageProvider = bindStageProvider;
  }

  @Override
  public HeadsUpViewBinder get() {
    return newInstance(notificationMessagingUtilProvider.get(), bindStageProvider.get());
  }

  public static HeadsUpViewBinder_Factory create(
      Provider<NotificationMessagingUtil> notificationMessagingUtilProvider,
      Provider<RowContentBindStage> bindStageProvider) {
    return new HeadsUpViewBinder_Factory(notificationMessagingUtilProvider, bindStageProvider);
  }

  public static HeadsUpViewBinder newInstance(NotificationMessagingUtil notificationMessagingUtil,
      RowContentBindStage bindStage) {
    return new HeadsUpViewBinder(notificationMessagingUtil, bindStage);
  }
}
