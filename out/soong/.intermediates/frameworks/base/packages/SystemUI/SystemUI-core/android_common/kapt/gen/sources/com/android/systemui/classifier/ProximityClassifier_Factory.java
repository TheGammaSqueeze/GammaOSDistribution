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
public final class ProximityClassifier_Factory implements Factory<ProximityClassifier> {
  private final Provider<DistanceClassifier> distanceClassifierProvider;

  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProxyProvider;

  public ProximityClassifier_Factory(Provider<DistanceClassifier> distanceClassifierProvider,
      Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    this.distanceClassifierProvider = distanceClassifierProvider;
    this.dataProvider = dataProvider;
    this.deviceConfigProxyProvider = deviceConfigProxyProvider;
  }

  @Override
  public ProximityClassifier get() {
    return newInstance(distanceClassifierProvider.get(), dataProvider.get(), deviceConfigProxyProvider.get());
  }

  public static ProximityClassifier_Factory create(
      Provider<DistanceClassifier> distanceClassifierProvider,
      Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    return new ProximityClassifier_Factory(distanceClassifierProvider, dataProvider, deviceConfigProxyProvider);
  }

  public static ProximityClassifier newInstance(Object distanceClassifier,
      FalsingDataProvider dataProvider, DeviceConfigProxy deviceConfigProxy) {
    return new ProximityClassifier((DistanceClassifier) distanceClassifier, dataProvider, deviceConfigProxy);
  }
}
