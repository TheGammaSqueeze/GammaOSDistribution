package com.android.systemui.tuner;

import com.android.systemui.demomode.DemoModeController;
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
public final class TunerActivity_Factory implements Factory<TunerActivity> {
  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  public TunerActivity_Factory(Provider<DemoModeController> demoModeControllerProvider,
      Provider<TunerService> tunerServiceProvider) {
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
  }

  @Override
  public TunerActivity get() {
    return newInstance(demoModeControllerProvider.get(), tunerServiceProvider.get());
  }

  public static TunerActivity_Factory create(
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<TunerService> tunerServiceProvider) {
    return new TunerActivity_Factory(demoModeControllerProvider, tunerServiceProvider);
  }

  public static TunerActivity newInstance(DemoModeController demoModeController,
      TunerService tunerService) {
    return new TunerActivity(demoModeController, tunerService);
  }
}
