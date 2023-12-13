package com.android.systemui.dagger;

import android.view.IWindowManager;
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
public final class FrameworkServicesModule_ProvideIWindowManagerFactory implements Factory<IWindowManager> {
  @Override
  public IWindowManager get() {
    return provideIWindowManager();
  }

  public static FrameworkServicesModule_ProvideIWindowManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IWindowManager provideIWindowManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIWindowManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIWindowManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIWindowManagerFactory();
  }
}
