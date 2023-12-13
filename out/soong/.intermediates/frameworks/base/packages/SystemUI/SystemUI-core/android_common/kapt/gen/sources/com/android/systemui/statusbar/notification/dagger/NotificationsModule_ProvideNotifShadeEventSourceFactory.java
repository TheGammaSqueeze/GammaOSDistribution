package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinator;
import com.android.systemui.statusbar.notification.collection.legacy.LegacyNotificationPresenterExtensions;
import com.android.systemui.statusbar.notification.collection.render.NotifShadeEventSource;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class NotificationsModule_ProvideNotifShadeEventSourceFactory implements Factory<NotifShadeEventSource> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<ShadeEventCoordinator> shadeEventCoordinatorLazyProvider;

  private final Provider<LegacyNotificationPresenterExtensions> legacyNotificationPresenterExtensionsLazyProvider;

  public NotificationsModule_ProvideNotifShadeEventSourceFactory(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<ShadeEventCoordinator> shadeEventCoordinatorLazyProvider,
      Provider<LegacyNotificationPresenterExtensions> legacyNotificationPresenterExtensionsLazyProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.shadeEventCoordinatorLazyProvider = shadeEventCoordinatorLazyProvider;
    this.legacyNotificationPresenterExtensionsLazyProvider = legacyNotificationPresenterExtensionsLazyProvider;
  }

  @Override
  public NotifShadeEventSource get() {
    return provideNotifShadeEventSource(featureFlagsProvider.get(), DoubleCheck.lazy(shadeEventCoordinatorLazyProvider), DoubleCheck.lazy(legacyNotificationPresenterExtensionsLazyProvider));
  }

  public static NotificationsModule_ProvideNotifShadeEventSourceFactory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<ShadeEventCoordinator> shadeEventCoordinatorLazyProvider,
      Provider<LegacyNotificationPresenterExtensions> legacyNotificationPresenterExtensionsLazyProvider) {
    return new NotificationsModule_ProvideNotifShadeEventSourceFactory(featureFlagsProvider, shadeEventCoordinatorLazyProvider, legacyNotificationPresenterExtensionsLazyProvider);
  }

  public static NotifShadeEventSource provideNotifShadeEventSource(FeatureFlags featureFlags,
      Lazy<ShadeEventCoordinator> shadeEventCoordinatorLazy,
      Lazy<LegacyNotificationPresenterExtensions> legacyNotificationPresenterExtensionsLazy) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotifShadeEventSource(featureFlags, shadeEventCoordinatorLazy, legacyNotificationPresenterExtensionsLazy));
  }
}
