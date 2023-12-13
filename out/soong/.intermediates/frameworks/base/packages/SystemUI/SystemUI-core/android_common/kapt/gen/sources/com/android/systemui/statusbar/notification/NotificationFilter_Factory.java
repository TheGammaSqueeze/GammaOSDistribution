package com.android.systemui.statusbar.notification;

import com.android.systemui.ForegroundServiceController;
import com.android.systemui.media.MediaFeatureFlag;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
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
public final class NotificationFilter_Factory implements Factory<NotificationFilter> {
  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider;

  private final Provider<ForegroundServiceController> foregroundServiceControllerProvider;

  private final Provider<NotificationLockscreenUserManager> userManagerProvider;

  private final Provider<MediaFeatureFlag> mediaFeatureFlagProvider;

  public NotificationFilter_Factory(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider,
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<NotificationLockscreenUserManager> userManagerProvider,
      Provider<MediaFeatureFlag> mediaFeatureFlagProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardEnvironmentProvider = keyguardEnvironmentProvider;
    this.foregroundServiceControllerProvider = foregroundServiceControllerProvider;
    this.userManagerProvider = userManagerProvider;
    this.mediaFeatureFlagProvider = mediaFeatureFlagProvider;
  }

  @Override
  public NotificationFilter get() {
    return newInstance(statusBarStateControllerProvider.get(), keyguardEnvironmentProvider.get(), foregroundServiceControllerProvider.get(), userManagerProvider.get(), mediaFeatureFlagProvider.get());
  }

  public static NotificationFilter_Factory create(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider,
      Provider<ForegroundServiceController> foregroundServiceControllerProvider,
      Provider<NotificationLockscreenUserManager> userManagerProvider,
      Provider<MediaFeatureFlag> mediaFeatureFlagProvider) {
    return new NotificationFilter_Factory(statusBarStateControllerProvider, keyguardEnvironmentProvider, foregroundServiceControllerProvider, userManagerProvider, mediaFeatureFlagProvider);
  }

  public static NotificationFilter newInstance(StatusBarStateController statusBarStateController,
      NotificationEntryManager.KeyguardEnvironment keyguardEnvironment,
      ForegroundServiceController foregroundServiceController,
      NotificationLockscreenUserManager userManager, MediaFeatureFlag mediaFeatureFlag) {
    return new NotificationFilter(statusBarStateController, keyguardEnvironment, foregroundServiceController, userManager, mediaFeatureFlag);
  }
}
