package com.android.systemui.statusbar.policy.dagger;

import android.content.res.Resources;
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
public final class StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory implements Factory<String[]> {
  private final Provider<Resources> resourcesProvider;

  public StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory(
      Provider<Resources> resourcesProvider) {
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public String[] get() {
    return providesDeviceStateRotationLockDefaults(resourcesProvider.get());
  }

  public static StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory create(
      Provider<Resources> resourcesProvider) {
    return new StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory(resourcesProvider);
  }

  public static String[] providesDeviceStateRotationLockDefaults(Resources resources) {
    return Preconditions.checkNotNullFromProvides(StatusBarPolicyModule.providesDeviceStateRotationLockDefaults(resources));
  }
}
