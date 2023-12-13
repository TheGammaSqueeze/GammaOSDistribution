package com.android.systemui.settings.brightness;

import com.android.systemui.plugins.FalsingManager;
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
public final class BrightnessSliderController_Factory_Factory implements Factory<BrightnessSliderController.Factory> {
  private final Provider<FalsingManager> falsingManagerProvider;

  public BrightnessSliderController_Factory_Factory(
      Provider<FalsingManager> falsingManagerProvider) {
    this.falsingManagerProvider = falsingManagerProvider;
  }

  @Override
  public BrightnessSliderController.Factory get() {
    return newInstance(falsingManagerProvider.get());
  }

  public static BrightnessSliderController_Factory_Factory create(
      Provider<FalsingManager> falsingManagerProvider) {
    return new BrightnessSliderController_Factory_Factory(falsingManagerProvider);
  }

  public static BrightnessSliderController.Factory newInstance(FalsingManager falsingManager) {
    return new BrightnessSliderController.Factory(falsingManager);
  }
}
