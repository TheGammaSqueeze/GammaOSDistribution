package com.android.systemui.unfold;

import com.android.systemui.util.WallpaperController;
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
public final class UnfoldTransitionWallpaperController_Factory implements Factory<UnfoldTransitionWallpaperController> {
  private final Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider;

  private final Provider<WallpaperController> wallpaperControllerProvider;

  public UnfoldTransitionWallpaperController_Factory(
      Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider,
      Provider<WallpaperController> wallpaperControllerProvider) {
    this.unfoldTransitionProgressProvider = unfoldTransitionProgressProvider;
    this.wallpaperControllerProvider = wallpaperControllerProvider;
  }

  @Override
  public UnfoldTransitionWallpaperController get() {
    return newInstance(unfoldTransitionProgressProvider.get(), wallpaperControllerProvider.get());
  }

  public static UnfoldTransitionWallpaperController_Factory create(
      Provider<UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider,
      Provider<WallpaperController> wallpaperControllerProvider) {
    return new UnfoldTransitionWallpaperController_Factory(unfoldTransitionProgressProvider, wallpaperControllerProvider);
  }

  public static UnfoldTransitionWallpaperController newInstance(
      UnfoldTransitionProgressProvider unfoldTransitionProgressProvider,
      WallpaperController wallpaperController) {
    return new UnfoldTransitionWallpaperController(unfoldTransitionProgressProvider, wallpaperController);
  }
}
