package com.android.systemui.qs;

import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.qs.carrier.QSCarrierGroupController;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.statusbar.policy.VariableDateViewController;
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
public final class QuickStatusBarHeaderController_Factory implements Factory<QuickStatusBarHeaderController> {
  private final Provider<QuickStatusBarHeader> viewProvider;

  private final Provider<HeaderPrivacyIconsController> headerPrivacyIconsControllerProvider;

  private final Provider<StatusBarIconController> statusBarIconControllerProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<QuickQSPanelController> quickQSPanelControllerProvider;

  private final Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider;

  private final Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider;

  private final Provider<BatteryMeterViewController> batteryMeterViewControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<VariableDateViewController.Factory> variableDateViewControllerFactoryProvider;

  private final Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider;

  public QuickStatusBarHeaderController_Factory(Provider<QuickStatusBarHeader> viewProvider,
      Provider<HeaderPrivacyIconsController> headerPrivacyIconsControllerProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider,
      Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<VariableDateViewController.Factory> variableDateViewControllerFactoryProvider,
      Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider) {
    this.viewProvider = viewProvider;
    this.headerPrivacyIconsControllerProvider = headerPrivacyIconsControllerProvider;
    this.statusBarIconControllerProvider = statusBarIconControllerProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.quickQSPanelControllerProvider = quickQSPanelControllerProvider;
    this.qsCarrierGroupControllerBuilderProvider = qsCarrierGroupControllerBuilderProvider;
    this.qsExpansionPathInterpolatorProvider = qsExpansionPathInterpolatorProvider;
    this.batteryMeterViewControllerProvider = batteryMeterViewControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.variableDateViewControllerFactoryProvider = variableDateViewControllerFactoryProvider;
    this.statusBarContentInsetsProvider = statusBarContentInsetsProvider;
  }

  @Override
  public QuickStatusBarHeaderController get() {
    return newInstance(viewProvider.get(), headerPrivacyIconsControllerProvider.get(), statusBarIconControllerProvider.get(), demoModeControllerProvider.get(), quickQSPanelControllerProvider.get(), qsCarrierGroupControllerBuilderProvider.get(), qsExpansionPathInterpolatorProvider.get(), batteryMeterViewControllerProvider.get(), featureFlagsProvider.get(), variableDateViewControllerFactoryProvider.get(), statusBarContentInsetsProvider.get());
  }

  public static QuickStatusBarHeaderController_Factory create(
      Provider<QuickStatusBarHeader> viewProvider,
      Provider<HeaderPrivacyIconsController> headerPrivacyIconsControllerProvider,
      Provider<StatusBarIconController> statusBarIconControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<QSCarrierGroupController.Builder> qsCarrierGroupControllerBuilderProvider,
      Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider,
      Provider<BatteryMeterViewController> batteryMeterViewControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<VariableDateViewController.Factory> variableDateViewControllerFactoryProvider,
      Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider) {
    return new QuickStatusBarHeaderController_Factory(viewProvider, headerPrivacyIconsControllerProvider, statusBarIconControllerProvider, demoModeControllerProvider, quickQSPanelControllerProvider, qsCarrierGroupControllerBuilderProvider, qsExpansionPathInterpolatorProvider, batteryMeterViewControllerProvider, featureFlagsProvider, variableDateViewControllerFactoryProvider, statusBarContentInsetsProvider);
  }

  public static QuickStatusBarHeaderController newInstance(QuickStatusBarHeader view,
      HeaderPrivacyIconsController headerPrivacyIconsController,
      StatusBarIconController statusBarIconController, DemoModeController demoModeController,
      QuickQSPanelController quickQSPanelController,
      QSCarrierGroupController.Builder qsCarrierGroupControllerBuilder,
      QSExpansionPathInterpolator qsExpansionPathInterpolator,
      BatteryMeterViewController batteryMeterViewController, FeatureFlags featureFlags,
      VariableDateViewController.Factory variableDateViewControllerFactory,
      StatusBarContentInsetsProvider statusBarContentInsetsProvider) {
    return new QuickStatusBarHeaderController(view, headerPrivacyIconsController, statusBarIconController, demoModeController, quickQSPanelController, qsCarrierGroupControllerBuilder, qsExpansionPathInterpolator, batteryMeterViewController, featureFlags, variableDateViewControllerFactory, statusBarContentInsetsProvider);
  }
}
