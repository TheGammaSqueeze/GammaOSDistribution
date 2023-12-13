package com.android.systemui.dagger;

import com.android.systemui.shared.system.DevicePolicyManagerWrapper;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class DependencyProvider_ProvideDevicePolicyManagerWrapperFactory implements Factory<DevicePolicyManagerWrapper> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideDevicePolicyManagerWrapperFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public DevicePolicyManagerWrapper get() {
    return provideDevicePolicyManagerWrapper(module);
  }

  public static DependencyProvider_ProvideDevicePolicyManagerWrapperFactory create(
      DependencyProvider module) {
    return new DependencyProvider_ProvideDevicePolicyManagerWrapperFactory(module);
  }

  public static DevicePolicyManagerWrapper provideDevicePolicyManagerWrapper(
      DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideDevicePolicyManagerWrapper());
  }
}
