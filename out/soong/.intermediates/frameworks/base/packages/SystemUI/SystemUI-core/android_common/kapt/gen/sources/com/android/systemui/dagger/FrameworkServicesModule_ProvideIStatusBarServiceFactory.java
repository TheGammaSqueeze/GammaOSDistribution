package com.android.systemui.dagger;

import com.android.internal.statusbar.IStatusBarService;
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
public final class FrameworkServicesModule_ProvideIStatusBarServiceFactory implements Factory<IStatusBarService> {
  @Override
  public IStatusBarService get() {
    return provideIStatusBarService();
  }

  public static FrameworkServicesModule_ProvideIStatusBarServiceFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IStatusBarService provideIStatusBarService() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIStatusBarService());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIStatusBarServiceFactory INSTANCE = new FrameworkServicesModule_ProvideIStatusBarServiceFactory();
  }
}
