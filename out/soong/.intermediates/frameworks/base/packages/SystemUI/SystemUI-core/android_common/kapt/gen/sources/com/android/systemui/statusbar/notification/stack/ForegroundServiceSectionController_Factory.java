package com.android.systemui.statusbar.notification.stack;

import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
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
public final class ForegroundServiceSectionController_Factory implements Factory<ForegroundServiceSectionController> {
  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<ForegroundServiceDismissalFeatureController> featureControllerProvider;

  public ForegroundServiceSectionController_Factory(
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<ForegroundServiceDismissalFeatureController> featureControllerProvider) {
    this.entryManagerProvider = entryManagerProvider;
    this.featureControllerProvider = featureControllerProvider;
  }

  @Override
  public ForegroundServiceSectionController get() {
    return newInstance(entryManagerProvider.get(), featureControllerProvider.get());
  }

  public static ForegroundServiceSectionController_Factory create(
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<ForegroundServiceDismissalFeatureController> featureControllerProvider) {
    return new ForegroundServiceSectionController_Factory(entryManagerProvider, featureControllerProvider);
  }

  public static ForegroundServiceSectionController newInstance(
      NotificationEntryManager entryManager,
      ForegroundServiceDismissalFeatureController featureController) {
    return new ForegroundServiceSectionController(entryManager, featureController);
  }
}
