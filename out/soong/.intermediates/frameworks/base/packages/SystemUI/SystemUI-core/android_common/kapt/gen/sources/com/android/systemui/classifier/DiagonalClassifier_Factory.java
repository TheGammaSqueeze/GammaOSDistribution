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
public final class DiagonalClassifier_Factory implements Factory<DiagonalClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProxyProvider;

  public DiagonalClassifier_Factory(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    this.dataProvider = dataProvider;
    this.deviceConfigProxyProvider = deviceConfigProxyProvider;
  }

  @Override
  public DiagonalClassifier get() {
    return newInstance(dataProvider.get(), deviceConfigProxyProvider.get());
  }

  public static DiagonalClassifier_Factory create(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    return new DiagonalClassifier_Factory(dataProvider, deviceConfigProxyProvider);
  }

  public static DiagonalClassifier newInstance(FalsingDataProvider dataProvider,
      DeviceConfigProxy deviceConfigProxy) {
    return new DiagonalClassifier(dataProvider, deviceConfigProxy);
  }
}
