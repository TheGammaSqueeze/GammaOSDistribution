package com.android.systemui.dagger;

import android.app.WallpaperManager;
import android.content.Context;
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
public final class FrameworkServicesModule_ProvideWallpaperManagerFactory implements Factory<WallpaperManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideWallpaperManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public WallpaperManager get() {
    return provideWallpaperManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideWallpaperManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideWallpaperManagerFactory(contextProvider);
  }

  public static WallpaperManager provideWallpaperManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideWallpaperManager(context));
  }
}
