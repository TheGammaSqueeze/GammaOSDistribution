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
public final class ZigZagClassifier_Factory implements Factory<ZigZagClassifier> {
  private final Provider<FalsingDataProvider> dataProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProxyProvider;

  public ZigZagClassifier_Factory(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    this.dataProvider = dataProvider;
    this.deviceConfigProxyProvider = deviceConfigProxyProvider;
  }

  @Override
  public ZigZagClassifier get() {
    return newInstance(dataProvider.get(), deviceConfigProxyProvider.get());
  }

  public static ZigZagClassifier_Factory create(Provider<FalsingDataProvider> dataProvider,
      Provider<DeviceConfigProxy> deviceConfigProxyProvider) {
    return new ZigZagClassifier_Factory(dataProvider, deviceConfigProxyProvider);
  }

  public static ZigZagClassifier newInstance(FalsingDataProvider dataProvider,
      DeviceConfigProxy deviceConfigProxy) {
    return new ZigZagClassifier(dataProvider, deviceConfigProxy);
  }
}
