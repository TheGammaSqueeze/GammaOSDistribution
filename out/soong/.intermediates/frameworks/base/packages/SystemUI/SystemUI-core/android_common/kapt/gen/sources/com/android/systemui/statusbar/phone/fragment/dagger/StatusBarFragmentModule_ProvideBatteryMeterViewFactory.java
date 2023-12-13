package com.android.systemui.statusbar.phone.fragment.dagger;

import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.statusbar.phone.PhoneStatusBarView;
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
public final class StatusBarFragmentModule_ProvideBatteryMeterViewFactory implements Factory<BatteryMeterView> {
  private final Provider<PhoneStatusBarView> viewProvider;

  public StatusBarFragmentModule_ProvideBatteryMeterViewFactory(
      Provider<PhoneStatusBarView> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public BatteryMeterView get() {
    return provideBatteryMeterView(viewProvider.get());
  }

  public static StatusBarFragmentModule_ProvideBatteryMeterViewFactory create(
      Provider<PhoneStatusBarView> viewProvider) {
    return new StatusBarFragmentModule_ProvideBatteryMeterViewFactory(viewProvider);
  }

  public static BatteryMeterView provideBatteryMeterView(PhoneStatusBarView view) {
    return Preconditions.checkNotNullFromProvides(StatusBarFragmentModule.provideBatteryMeterView(view));
  }
}
