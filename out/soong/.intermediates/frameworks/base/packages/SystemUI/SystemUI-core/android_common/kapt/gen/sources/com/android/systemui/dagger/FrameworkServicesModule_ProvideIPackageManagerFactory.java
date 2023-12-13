package com.android.systemui.dagger;

import android.content.pm.IPackageManager;
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
public final class FrameworkServicesModule_ProvideIPackageManagerFactory implements Factory<IPackageManager> {
  @Override
  public IPackageManager get() {
    return provideIPackageManager();
  }

  public static FrameworkServicesModule_ProvideIPackageManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IPackageManager provideIPackageManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIPackageManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIPackageManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIPackageManagerFactory();
  }
}
