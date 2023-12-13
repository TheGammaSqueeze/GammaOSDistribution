package com.android.systemui.doze;

import android.app.IWallpaperManager;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.DozeParameters;
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
public final class DozeWallpaperState_Factory implements Factory<DozeWallpaperState> {
  private final Provider<IWallpaperManager> wallpaperManagerServiceProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  private final Provider<DozeParameters> parametersProvider;

  public DozeWallpaperState_Factory(Provider<IWallpaperManager> wallpaperManagerServiceProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<DozeParameters> parametersProvider) {
    this.wallpaperManagerServiceProvider = wallpaperManagerServiceProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
    this.parametersProvider = parametersProvider;
  }

  @Override
  public DozeWallpaperState get() {
    return newInstance(wallpaperManagerServiceProvider.get(), biometricUnlockControllerProvider.get(), parametersProvider.get());
  }

  public static DozeWallpaperState_Factory create(
      Provider<IWallpaperManager> wallpaperManagerServiceProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<DozeParameters> parametersProvider) {
    return new DozeWallpaperState_Factory(wallpaperManagerServiceProvider, biometricUnlockControllerProvider, parametersProvider);
  }

  public static DozeWallpaperState newInstance(IWallpaperManager wallpaperManagerService,
      BiometricUnlockController biometricUnlockController, DozeParameters parameters) {
    return new DozeWallpaperState(wallpaperManagerService, biometricUnlockController, parameters);
  }
}
