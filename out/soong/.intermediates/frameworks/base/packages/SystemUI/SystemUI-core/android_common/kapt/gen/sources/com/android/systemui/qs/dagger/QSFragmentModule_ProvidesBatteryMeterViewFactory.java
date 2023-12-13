package com.android.systemui.qs.dagger;

import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.qs.QuickStatusBarHeader;
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
public final class QSFragmentModule_ProvidesBatteryMeterViewFactory implements Factory<BatteryMeterView> {
  private final Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider;

  public QSFragmentModule_ProvidesBatteryMeterViewFactory(
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider) {
    this.quickStatusBarHeaderProvider = quickStatusBarHeaderProvider;
  }

  @Override
  public BatteryMeterView get() {
    return providesBatteryMeterView(quickStatusBarHeaderProvider.get());
  }

  public static QSFragmentModule_ProvidesBatteryMeterViewFactory create(
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider) {
    return new QSFragmentModule_ProvidesBatteryMeterViewFactory(quickStatusBarHeaderProvider);
  }

  public static BatteryMeterView providesBatteryMeterView(
      QuickStatusBarHeader quickStatusBarHeader) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesBatteryMeterView(quickStatusBarHeader));
  }
}
