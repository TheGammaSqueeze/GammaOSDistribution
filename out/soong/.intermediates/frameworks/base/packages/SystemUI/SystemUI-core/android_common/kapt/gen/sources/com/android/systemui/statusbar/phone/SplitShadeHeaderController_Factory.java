package com.android.systemui.statusbar.phone;

import android.view.View;
import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.qs.HeaderPrivacyIconsController;
import com.android.systemui.qs.carrier.QSCarrierGroupController;
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
public final class SplitShadeHeaderController_Factory implements Factory<SplitShadeHeaderController> {
  private final Provider<View> statusBarProvider;

  private final Provider<StatusBarIconController> statusBarIconControllerProvider;

  private final Provider<HeaderPrivacyIconsController> privacyIconsControllerProvider;

  private final Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<BatteryMeterViewController> batteryMeterViewControllerProvider;

  public SplitShadeHeaderController_Factory(Provider<View> statusBarProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<HeaderPrivacyIconsController> privacyIconsControllerProvider,
      Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider) {
    this.statusBarProvider = statusBarProvider;
    this.statusBarIconControllerProvider = statusBarIconControllerProvider;
    this.privacyIconsControllerProvider = privacyIconsControllerProvider;
    this.qsCarrierGroupControllerBuilderProvider = qsCarrierGroupControllerBuilderProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.batteryMeterViewControllerProvider = batteryMeterViewControllerProvider;
  }

  @Override
  public SplitShadeHeaderController get() {
    return newInstance(statusBarProvider.get(), statusBarIconControllerProvider.get(), privacyIconsControllerProvider.get(), qsCarrierGroupControllerBuilderProvider.get(), featureFlagsProvider.get(), batteryMeterViewControllerProvider.get());
  }

  public static SplitShadeHeaderController_Factory create(Provider<View> statusBarProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<HeaderPrivacyIconsController> privacyIconsControllerProvider,
      Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider) {
    return new SplitShadeHeaderController_Factory(statusBarProvider, statusBarIconControllerProvider, privacyIconsControllerProvider, qsCarrierGroupControllerBuilderProvider, featureFlagsProvider, batteryMeterViewControllerProvider);
  }

  public static SplitShadeHeaderController newInstance(View statusBar,
      StatusBarIconController statusBarIconController,
      HeaderPrivacyIconsController privacyIconsController,
      QSCarrierGroupController.Builder qsCarrierGroupControllerBuilder, FeatureFlags featureFlags,
      BatteryMeterViewController batteryMeterViewController) {
    return new SplitShadeHeaderController(statusBar, statusBarIconController, privacyIconsController, qsCarrierGroupControllerBuilder, featureFlags, batteryMeterViewController);
  }
}
