package com.android.systemui.qs;

import android.hardware.display.ColorDisplayManager;
import android.os.Handler;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.settings.SecureSettings;
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
public final class ReduceBrightColorsController_Factory implements Factory<ReduceBrightColorsController> {
  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<ColorDisplayManager> colorDisplayManagerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  public ReduceBrightColorsController_Factory(Provider<UserTracker> userTrackerProvider,
      Provider<Handler> handlerProvider, Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    this.userTrackerProvider = userTrackerProvider;
    this.handlerProvider = handlerProvider;
    this.colorDisplayManagerProvider = colorDisplayManagerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
  }

  @Override
  public ReduceBrightColorsController get() {
    return newInstance(userTrackerProvider.get(), handlerProvider.get(), colorDisplayManagerProvider.get(), secureSettingsProvider.get());
  }

  public static ReduceBrightColorsController_Factory create(
      Provider<UserTracker> userTrackerProvider, Provider<Handler> handlerProvider,
      Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    return new ReduceBrightColorsController_Factory(userTrackerProvider, handlerProvider, colorDisplayManagerProvider, secureSettingsProvider);
  }

  public static ReduceBrightColorsController newInstance(UserTracker userTracker, Handler handler,
      ColorDisplayManager colorDisplayManager, SecureSettings secureSettings) {
    return new ReduceBrightColorsController(userTracker, handler, colorDisplayManager, secureSettings);
  }
}
