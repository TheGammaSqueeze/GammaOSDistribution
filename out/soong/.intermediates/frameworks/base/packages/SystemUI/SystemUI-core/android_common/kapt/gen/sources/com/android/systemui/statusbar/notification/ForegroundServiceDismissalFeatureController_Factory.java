package com.android.systemui.statusbar.notification;

import android.content.Context;
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
public final class ForegroundServiceDismissalFeatureController_Factory implements Factory<ForegroundServiceDismissalFeatureController> {
  private final Provider<DeviceConfigProxy> proxyProvider;

  private final Provider<Context> contextProvider;

  public ForegroundServiceDismissalFeatureController_Factory(
      Provider<DeviceConfigProxy> proxyProvider, Provider<Context> contextProvider) {
    this.proxyProvider = proxyProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public ForegroundServiceDismissalFeatureController get() {
    return newInstance(proxyProvider.get(), contextProvider.get());
  }

  public static ForegroundServiceDismissalFeatureController_Factory create(
      Provider<DeviceConfigProxy> proxyProvider, Provider<Context> contextProvider) {
    return new ForegroundServiceDismissalFeatureController_Factory(proxyProvider, contextProvider);
  }

  public static ForegroundServiceDismissalFeatureController newInstance(DeviceConfigProxy proxy,
      Context context) {
    return new ForegroundServiceDismissalFeatureController(proxy, context);
  }
}
