package com.android.systemui.dagger;

import com.android.systemui.shared.system.PackageManagerWrapper;
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
public final class FrameworkServicesModule_ProvidePackageManagerWrapperFactory implements Factory<PackageManagerWrapper> {
  @Override
  public PackageManagerWrapper get() {
    return providePackageManagerWrapper();
  }

  public static FrameworkServicesModule_ProvidePackageManagerWrapperFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static PackageManagerWrapper providePackageManagerWrapper() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.providePackageManagerWrapper());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvidePackageManagerWrapperFactory INSTANCE = new FrameworkServicesModule_ProvidePackageManagerWrapperFactory();
  }
}
