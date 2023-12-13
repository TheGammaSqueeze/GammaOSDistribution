package com.android.systemui.tuner;

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
public final class TunablePadding_TunablePaddingService_Factory implements Factory<TunablePadding.TunablePaddingService> {
  private final Provider<TunerService> tunerServiceProvider;

  public TunablePadding_TunablePaddingService_Factory(Provider<TunerService> tunerServiceProvider) {
    this.tunerServiceProvider = tunerServiceProvider;
  }

  @Override
  public TunablePadding.TunablePaddingService get() {
    return newInstance(tunerServiceProvider.get());
  }

  public static TunablePadding_TunablePaddingService_Factory create(
      Provider<TunerService> tunerServiceProvider) {
    return new TunablePadding_TunablePaddingService_Factory(tunerServiceProvider);
  }

  public static TunablePadding.TunablePaddingService newInstance(TunerService tunerService) {
    return new TunablePadding.TunablePaddingService(tunerService);
  }
}
