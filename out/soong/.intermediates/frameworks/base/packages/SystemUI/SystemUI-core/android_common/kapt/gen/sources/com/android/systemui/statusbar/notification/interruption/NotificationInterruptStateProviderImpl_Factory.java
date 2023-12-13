package com.android.systemui.statusbar.notification.interruption;

import android.content.ContentResolver;
import android.hardware.display.AmbientDisplayConfiguration;
import android.os.Handler;
import android.os.PowerManager;
import android.service.dreams.IDreamManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationFilter;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
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
public final class NotificationInterruptStateProviderImpl_Factory implements Factory<NotificationInterruptStateProviderImpl> {
  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<PowerManager> powerManagerProvider;

  private final Provider<IDreamManager> dreamManagerProvider;

  private final Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider;

  private final Provider<NotificationFilter> notificationFilterProvider;

  private final Provider<BatteryController> batteryControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public NotificationInterruptStateProviderImpl_Factory(
      Provider<ContentResolver> contentResolverProvider,
      Provider<PowerManager> powerManagerProvider, Provider<IDreamManager> dreamManagerProvider,
      Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider,
      Provider<NotificationFilter> notificationFilterProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider, Provider<Handler> mainHandlerProvider) {
    this.contentResolverProvider = contentResolverProvider;
    this.powerManagerProvider = powerManagerProvider;
    this.dreamManagerProvider = dreamManagerProvider;
    this.ambientDisplayConfigurationProvider = ambientDisplayConfigurationProvider;
    this.notificationFilterProvider = notificationFilterProvider;
    this.batteryControllerProvider = batteryControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public NotificationInterruptStateProviderImpl get() {
    return newInstance(contentResolverProvider.get(), powerManagerProvider.get(), dreamManagerProvider.get(), ambientDisplayConfigurationProvider.get(), notificationFilterProvider.get(), batteryControllerProvider.get(), statusBarStateControllerProvider.get(), headsUpManagerProvider.get(), mainHandlerProvider.get());
  }

  public static NotificationInterruptStateProviderImpl_Factory create(
      Provider<ContentResolver> contentResolverProvider,
      Provider<PowerManager> powerManagerProvider, Provider<IDreamManager> dreamManagerProvider,
      Provider<AmbientDisplayConfiguration> ambientDisplayConfigurationProvider,
      Provider<NotificationFilter> notificationFilterProvider,
      Provider<BatteryController> batteryControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider, Provider<Handler> mainHandlerProvider) {
    return new NotificationInterruptStateProviderImpl_Factory(contentResolverProvider, powerManagerProvider, dreamManagerProvider, ambientDisplayConfigurationProvider, notificationFilterProvider, batteryControllerProvider, statusBarStateControllerProvider, headsUpManagerProvider, mainHandlerProvider);
  }

  public static NotificationInterruptStateProviderImpl newInstance(ContentResolver contentResolver,
      PowerManager powerManager, IDreamManager dreamManager,
      AmbientDisplayConfiguration ambientDisplayConfiguration,
      NotificationFilter notificationFilter, BatteryController batteryController,
      StatusBarStateController statusBarStateController, HeadsUpManager headsUpManager,
      Handler mainHandler) {
    return new NotificationInterruptStateProviderImpl(contentResolver, powerManager, dreamManager, ambientDisplayConfiguration, notificationFilter, batteryController, statusBarStateController, headsUpManager, mainHandler);
  }
}
