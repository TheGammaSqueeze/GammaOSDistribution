package com.android.systemui.dagger;

import android.content.Context;
import android.content.pm.LauncherApps;
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
public final class FrameworkServicesModule_ProvideLauncherAppsFactory implements Factory<LauncherApps> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideLauncherAppsFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public LauncherApps get() {
    return provideLauncherApps(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideLauncherAppsFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideLauncherAppsFactory(contextProvider);
  }

  public static LauncherApps provideLauncherApps(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideLauncherApps(context));
  }
}
