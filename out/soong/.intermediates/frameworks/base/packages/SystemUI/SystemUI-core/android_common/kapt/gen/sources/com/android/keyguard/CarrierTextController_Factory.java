package com.android.keyguard;

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
public final class CarrierTextController_Factory implements Factory<CarrierTextController> {
  private final Provider<CarrierText> viewProvider;

  private final Provider<CarrierTextManager.Builder> carrierTextManagerBuilderProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public CarrierTextController_Factory(Provider<CarrierText> viewProvider,
      Provider<CarrierTextManager.Builder> carrierTextManagerBuilderProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.viewProvider = viewProvider;
    this.carrierTextManagerBuilderProvider = carrierTextManagerBuilderProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public CarrierTextController get() {
    return newInstance(viewProvider.get(), carrierTextManagerBuilderProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static CarrierTextController_Factory create(Provider<CarrierText> viewProvider,
      Provider<CarrierTextManager.Builder> carrierTextManagerBuilderProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new CarrierTextController_Factory(viewProvider, carrierTextManagerBuilderProvider, keyguardUpdateMonitorProvider);
  }

  public static CarrierTextController newInstance(CarrierText view,
      CarrierTextManager.Builder carrierTextManagerBuilder,
      KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new CarrierTextController(view, carrierTextManagerBuilder, keyguardUpdateMonitor);
  }
}
