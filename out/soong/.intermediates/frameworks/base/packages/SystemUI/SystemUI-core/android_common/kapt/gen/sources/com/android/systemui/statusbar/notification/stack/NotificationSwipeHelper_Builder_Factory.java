package com.android.systemui.statusbar.notification.stack;

import android.content.res.Resources;
import android.view.ViewConfiguration;
import com.android.systemui.plugins.FalsingManager;
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
public final class NotificationSwipeHelper_Builder_Factory implements Factory<NotificationSwipeHelper.Builder> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<ViewConfiguration> viewConfigurationProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  public NotificationSwipeHelper_Builder_Factory(Provider<Resources> resourcesProvider,
      Provider<ViewConfiguration> viewConfigurationProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    this.resourcesProvider = resourcesProvider;
    this.viewConfigurationProvider = viewConfigurationProvider;
    this.falsingManagerProvider = falsingManagerProvider;
  }

  @Override
  public NotificationSwipeHelper.Builder get() {
    return newInstance(resourcesProvider.get(), viewConfigurationProvider.get(), falsingManagerProvider.get());
  }

  public static NotificationSwipeHelper_Builder_Factory create(
      Provider<Resources> resourcesProvider, Provider<ViewConfiguration> viewConfigurationProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    return new NotificationSwipeHelper_Builder_Factory(resourcesProvider, viewConfigurationProvider, falsingManagerProvider);
  }

  public static NotificationSwipeHelper.Builder newInstance(Resources resources,
      ViewConfiguration viewConfiguration, FalsingManager falsingManager) {
    return new NotificationSwipeHelper.Builder(resources, viewConfiguration, falsingManager);
  }
}
