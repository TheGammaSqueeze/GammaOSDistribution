package com.android.systemui.dagger;

import android.content.Context;
import android.content.pm.PackageManager;
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
public final class FrameworkServicesModule_ProvidePackageManagerFactory implements Factory<PackageManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvidePackageManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public PackageManager get() {
    return providePackageManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvidePackageManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvidePackageManagerFactory(contextProvider);
  }

  public static PackageManager providePackageManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.providePackageManager(context));
  }
}
