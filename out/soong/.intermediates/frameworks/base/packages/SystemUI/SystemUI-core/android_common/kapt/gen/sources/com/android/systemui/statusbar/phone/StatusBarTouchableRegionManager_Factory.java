package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class StatusBarTouchableRegionManager_Factory implements Factory<StatusBarTouchableRegionManager> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  public StatusBarTouchableRegionManager_Factory(Provider<Context> contextProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider) {
    this.contextProvider = contextProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
  }

  @Override
  public StatusBarTouchableRegionManager get() {
    return newInstance(contextProvider.get(), notificationShadeWindowControllerProvider.get(), configurationControllerProvider.get(), headsUpManagerProvider.get());
  }

  public static StatusBarTouchableRegionManager_Factory create(Provider<Context> contextProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider) {
    return new StatusBarTouchableRegionManager_Factory(contextProvider, notificationShadeWindowControllerProvider, configurationControllerProvider, headsUpManagerProvider);
  }

  public static StatusBarTouchableRegionManager newInstance(Context context,
      NotificationShadeWindowController notificationShadeWindowController,
      ConfigurationController configurationController, HeadsUpManagerPhone headsUpManager) {
    return new StatusBarTouchableRegionManager(context, notificationShadeWindowController, configurationController, headsUpManager);
  }
}
