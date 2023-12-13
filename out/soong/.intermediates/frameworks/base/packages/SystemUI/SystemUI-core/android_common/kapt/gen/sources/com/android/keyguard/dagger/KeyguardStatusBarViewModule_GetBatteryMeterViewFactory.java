package com.android.keyguard.dagger;

import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.statusbar.phone.KeyguardStatusBarView;
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
public final class KeyguardStatusBarViewModule_GetBatteryMeterViewFactory implements Factory<BatteryMeterView> {
  private final Provider<KeyguardStatusBarView> viewProvider;

  public KeyguardStatusBarViewModule_GetBatteryMeterViewFactory(
      Provider<KeyguardStatusBarView> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public BatteryMeterView get() {
    return getBatteryMeterView(viewProvider.get());
  }

  public static KeyguardStatusBarViewModule_GetBatteryMeterViewFactory create(
      Provider<KeyguardStatusBarView> viewProvider) {
    return new KeyguardStatusBarViewModule_GetBatteryMeterViewFactory(viewProvider);
  }

  public static BatteryMeterView getBatteryMeterView(KeyguardStatusBarView view) {
    return Preconditions.checkNotNullFromProvides(KeyguardStatusBarViewModule.getBatteryMeterView(view));
  }
}
