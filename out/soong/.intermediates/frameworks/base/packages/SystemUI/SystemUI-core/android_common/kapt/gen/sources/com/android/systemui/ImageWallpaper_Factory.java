package com.android.systemui;

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
public final class ImageWallpaper_Factory implements Factory<ImageWallpaper> {
  @Override
  public ImageWallpaper get() {
    return newInstance();
  }

  public static ImageWallpaper_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ImageWallpaper newInstance() {
    return new ImageWallpaper();
  }

  private static final class InstanceHolder {
    private static final ImageWallpaper_Factory INSTANCE = new ImageWallpaper_Factory();
  }
}
