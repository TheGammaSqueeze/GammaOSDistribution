package com.android.systemui.util;

import android.app.WallpaperManager;
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
public final class WallpaperController_Factory implements Factory<WallpaperController> {
  private final Provider<WallpaperManager> wallpaperManagerProvider;

  public WallpaperController_Factory(Provider<WallpaperManager> wallpaperManagerProvider) {
    this.wallpaperManagerProvider = wallpaperManagerProvider;
  }

  @Override
  public WallpaperController get() {
    return newInstance(wallpaperManagerProvider.get());
  }

  public static WallpaperController_Factory create(
      Provider<WallpaperManager> wallpaperManagerProvider) {
    return new WallpaperController_Factory(wallpaperManagerProvider);
  }

  public static WallpaperController newInstance(WallpaperManager wallpaperManager) {
    return new WallpaperController(wallpaperManager);
  }
}
