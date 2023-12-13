package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.net.wifi.WifiManager;
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
public final class FrameworkServicesModule_ProvideWifiManagerFactory implements Factory<WifiManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideWifiManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  @Nullable
  public WifiManager get() {
    return provideWifiManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideWifiManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideWifiManagerFactory(contextProvider);
  }

  @Nullable
  public static WifiManager provideWifiManager(Context context) {
    return FrameworkServicesModule.provideWifiManager(context);
  }
}
