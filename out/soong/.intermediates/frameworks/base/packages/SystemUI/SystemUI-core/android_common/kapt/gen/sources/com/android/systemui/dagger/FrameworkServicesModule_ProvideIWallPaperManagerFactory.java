package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.app.IWallpaperManager;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FrameworkServicesModule_ProvideIWallPaperManagerFactory implements Factory<IWallpaperManager> {
  @Override
  @Nullable
  public IWallpaperManager get() {
    return provideIWallPaperManager();
  }

  public static FrameworkServicesModule_ProvideIWallPaperManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  @Nullable
  public static IWallpaperManager provideIWallPaperManager() {
    return FrameworkServicesModule.provideIWallPaperManager();
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIWallPaperManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIWallPaperManagerFactory();
  }
}
