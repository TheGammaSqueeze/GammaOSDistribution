package com.android.systemui.controls.dagger;

import android.content.pm.PackageManager;
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
public final class ControlsModule_ProvidesControlsFeatureEnabledFactory implements Factory<Boolean> {
  private final Provider<PackageManager> pmProvider;

  public ControlsModule_ProvidesControlsFeatureEnabledFactory(Provider<PackageManager> pmProvider) {
    this.pmProvider = pmProvider;
  }

  @Override
  public Boolean get() {
    return providesControlsFeatureEnabled(pmProvider.get());
  }

  public static ControlsModule_ProvidesControlsFeatureEnabledFactory create(
      Provider<PackageManager> pmProvider) {
    return new ControlsModule_ProvidesControlsFeatureEnabledFactory(pmProvider);
  }

  public static boolean providesControlsFeatureEnabled(PackageManager pm) {
    return ControlsModule.providesControlsFeatureEnabled(pm);
  }
}
