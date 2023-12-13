package com.android.systemui.dagger;

import android.app.admin.DevicePolicyManager;
import android.content.Context;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class FrameworkServicesModule_ProvideDevicePolicyManagerFactory implements Factory<DevicePolicyManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideDevicePolicyManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public DevicePolicyManager get() {
    return provideDevicePolicyManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideDevicePolicyManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideDevicePolicyManagerFactory(contextProvider);
  }

  public static DevicePolicyManager provideDevicePolicyManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideDevicePolicyManager(context));
  }
}
