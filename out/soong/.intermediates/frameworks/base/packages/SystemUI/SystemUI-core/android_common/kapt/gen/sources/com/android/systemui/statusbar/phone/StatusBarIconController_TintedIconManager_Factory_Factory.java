package com.android.systemui.statusbar.phone;

import com.android.systemui.flags.FeatureFlags;
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
public final class StatusBarIconController_TintedIconManager_Factory_Factory implements Factory<StatusBarIconController.TintedIconManager.Factory> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  public StatusBarIconController_TintedIconManager_Factory_Factory(
      Provider<FeatureFlags> featureFlagsProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public StatusBarIconController.TintedIconManager.Factory get() {
    return newInstance(featureFlagsProvider.get());
  }

  public static StatusBarIconController_TintedIconManager_Factory_Factory create(
      Provider<FeatureFlags> featureFlagsProvider) {
    return new StatusBarIconController_TintedIconManager_Factory_Factory(featureFlagsProvider);
  }

  public static StatusBarIconController.TintedIconManager.Factory newInstance(
      FeatureFlags featureFlags) {
    return new StatusBarIconController.TintedIconManager.Factory(featureFlags);
  }
}
