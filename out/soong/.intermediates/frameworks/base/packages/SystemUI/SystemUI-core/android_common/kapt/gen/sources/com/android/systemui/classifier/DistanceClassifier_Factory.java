package com.android.systemui.classifier;

import com.android.systemui.util.DeviceConfigProxy;
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
public final class DistanceClassifier_Factory implements Factory<DistanceClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProxyProvider;

  public DistanceClassifier_Factory(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    this.dataProvider = dataProvider;
    this.deviceConfigProxyProvider = deviceConfigProxyProvider;
  }

  @Override
  public DistanceClassifier get() {
    return newInstance(dataProvider.get(), deviceConfigProxyProvider.get());
  }

  public static DistanceClassifier_Factory create(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    return new DistanceClassifier_Factory(dataProvider, deviceConfigProxyProvider);
  }

  public static DistanceClassifier newInstance(FalsingDataProvider dataProvider,
      DeviceConfigProxy deviceConfigProxy) {
    return new DistanceClassifier(dataProvider, deviceConfigProxy);
  }
}
