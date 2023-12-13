package com.android.systemui.statusbar.phone.dagger;

import android.view.View;
import com.android.systemui.battery.BatteryMeterView;
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
public final class StatusBarViewModule_GetBatteryMeterViewFactory implements Factory<BatteryMeterView> {
  private final Provider<View> viewProvider;

  public StatusBarViewModule_GetBatteryMeterViewFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public BatteryMeterView get() {
    return getBatteryMeterView(viewProvider.get());
  }

  public static StatusBarViewModule_GetBatteryMeterViewFactory create(Provider<View> viewProvider) {
    return new StatusBarViewModule_GetBatteryMeterViewFactory(viewProvider);
  }

  public static BatteryMeterView getBatteryMeterView(View view) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getBatteryMeterView(view));
  }
}
