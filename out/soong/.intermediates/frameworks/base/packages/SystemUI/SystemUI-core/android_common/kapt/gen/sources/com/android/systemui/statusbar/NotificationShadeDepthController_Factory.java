package com.android.systemui.statusbar;

import android.view.Choreographer;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class NotificationShadeDepthController_Factory implements Factory<NotificationShadeDepthController> {
  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<BlurUtils> blurUtilsProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<Choreographer> choreographerProvider;

  private final Provider<WallpaperController> wallpaperControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationShadeDepthController_Factory(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<BlurUtils> blurUtilsProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<Choreographer> choreographerProvider,
      Provider<WallpaperController> wallpaperControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeParameters> dozeParametersProvider, Provider<DumpManager> dumpManagerProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.blurUtilsProvider = blurUtilsProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.choreographerProvider = choreographerProvider;
    this.wallpaperControllerProvider = wallpaperControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.dozeParametersProvider = dozeParametersProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationShadeDepthController get() {
    return newInstance(statusBarStateControllerProvider.get(), blurUtilsProvider.get(), biometricUnlockControllerProvider.get(), keyguardStateControllerProvider.get(), choreographerProvider.get(), wallpaperControllerProvider.get(), notificationShadeWindowControllerProvider.get(), dozeParametersProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationShadeDepthController_Factory create(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<BlurUtils> blurUtilsProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<Choreographer> choreographerProvider,
      Provider<WallpaperController> wallpaperControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<DozeParameters> dozeParametersProvider, Provider<DumpManager> dumpManagerProvider) {
    return new NotificationShadeDepthController_Factory(statusBarStateControllerProvider, blurUtilsProvider, biometricUnlockControllerProvider, keyguardStateControllerProvider, choreographerProvider, wallpaperControllerProvider, notificationShadeWindowControllerProvider, dozeParametersProvider, dumpManagerProvider);
  }

  public static NotificationShadeDepthController newInstance(
      StatusBarStateController statusBarStateController, BlurUtils blurUtils,
      BiometricUnlockController biometricUnlockController,
      KeyguardStateController keyguardStateController, Choreographer choreographer,
      WallpaperController wallpaperController,
      NotificationShadeWindowController notificationShadeWindowController,
      DozeParameters dozeParameters, DumpManager dumpManager) {
    return new NotificationShadeDepthController(statusBarStateController, blurUtils, biometricUnlockController, keyguardStateController, choreographer, wallpaperController, notificationShadeWindowController, dozeParameters, dumpManager);
  }
}
