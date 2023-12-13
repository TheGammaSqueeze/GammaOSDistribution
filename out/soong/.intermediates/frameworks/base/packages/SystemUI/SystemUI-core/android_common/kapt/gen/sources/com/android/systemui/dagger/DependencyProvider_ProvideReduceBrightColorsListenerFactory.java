package com.android.systemui.dagger;

import android.hardware.display.ColorDisplayManager;
import android.os.Handler;
import com.android.systemui.qs.ReduceBrightColorsController;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.settings.SecureSettings;
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
public final class DependencyProvider_ProvideReduceBrightColorsListenerFactory implements Factory<ReduceBrightColorsController> {
  private final DependencyProvider module;

  private final Provider<Handler> bgHandlerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<ColorDisplayManager> colorDisplayManagerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  public DependencyProvider_ProvideReduceBrightColorsListenerFactory(DependencyProvider module,
      Provider<Handler> bgHandlerProvider, Provider<UserTracker> userTrackerProvider,
      Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    this.module = module;
    this.bgHandlerProvider = bgHandlerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.colorDisplayManagerProvider = colorDisplayManagerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
  }

  @Override
  public ReduceBrightColorsController get() {
    return provideReduceBrightColorsListener(module, bgHandlerProvider.get(), userTrackerProvider.get(), colorDisplayManagerProvider.get(), secureSettingsProvider.get());
  }

  public static DependencyProvider_ProvideReduceBrightColorsListenerFactory create(
      DependencyProvider module, Provider<Handler> bgHandlerProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<ColorDisplayManager> colorDisplayManagerProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    return new DependencyProvider_ProvideReduceBrightColorsListenerFactory(module, bgHandlerProvider, userTrackerProvider, colorDisplayManagerProvider, secureSettingsProvider);
  }

  public static ReduceBrightColorsController provideReduceBrightColorsListener(
      DependencyProvider instance, Handler bgHandler, UserTracker userTracker,
      ColorDisplayManager colorDisplayManager, SecureSettings secureSettings) {
    return Preconditions.checkNotNullFromProvides(instance.provideReduceBrightColorsListener(bgHandler, userTracker, colorDisplayManager, secureSettings));
  }
}
