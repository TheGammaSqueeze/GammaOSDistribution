package com.android.systemui.statusbar.phone.dagger;

import com.android.systemui.statusbar.notification.row.RowContentBindStage;
import com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper;
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
public final class StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory implements Factory<NotificationGroupAlertTransferHelper> {
  private final Provider<RowContentBindStage> bindStageProvider;

  public StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory(
      Provider<RowContentBindStage> bindStageProvider) {
    this.bindStageProvider = bindStageProvider;
  }

  @Override
  public NotificationGroupAlertTransferHelper get() {
    return provideNotificationGroupAlertTransferHelper(bindStageProvider.get());
  }

  public static StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory create(
      Provider<RowContentBindStage> bindStageProvider) {
    return new StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory(bindStageProvider);
  }

  public static NotificationGroupAlertTransferHelper provideNotificationGroupAlertTransferHelper(
      RowContentBindStage bindStage) {
    return Preconditions.checkNotNullFromProvides(StatusBarPhoneDependenciesModule.provideNotificationGroupAlertTransferHelper(bindStage));
  }
}
