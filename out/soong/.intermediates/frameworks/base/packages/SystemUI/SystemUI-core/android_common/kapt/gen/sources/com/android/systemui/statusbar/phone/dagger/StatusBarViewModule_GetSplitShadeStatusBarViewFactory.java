package com.android.systemui.statusbar.phone.dagger;

import android.view.View;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.phone.NotificationShadeWindowView;
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
public final class StatusBarViewModule_GetSplitShadeStatusBarViewFactory implements Factory<View> {
  private final Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  public StatusBarViewModule_GetSplitShadeStatusBarViewFactory(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    this.notificationShadeWindowViewProvider = notificationShadeWindowViewProvider;
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public View get() {
    return getSplitShadeStatusBarView(notificationShadeWindowViewProvider.get(), featureFlagsProvider.get());
  }

  public static StatusBarViewModule_GetSplitShadeStatusBarViewFactory create(
      Provider<NotificationShadeWindowView> notificationShadeWindowViewProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    return new StatusBarViewModule_GetSplitShadeStatusBarViewFactory(notificationShadeWindowViewProvider, featureFlagsProvider);
  }

  public static View getSplitShadeStatusBarView(
      NotificationShadeWindowView notificationShadeWindowView, FeatureFlags featureFlags) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getSplitShadeStatusBarView(notificationShadeWindowView, featureFlags));
  }
}
