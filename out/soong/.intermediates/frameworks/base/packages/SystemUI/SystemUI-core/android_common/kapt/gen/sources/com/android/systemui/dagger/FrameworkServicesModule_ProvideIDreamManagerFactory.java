package com.android.systemui.dagger;

import android.service.dreams.IDreamManager;
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
public final class FrameworkServicesModule_ProvideIDreamManagerFactory implements Factory<IDreamManager> {
  @Override
  public IDreamManager get() {
    return provideIDreamManager();
  }

  public static FrameworkServicesModule_ProvideIDreamManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IDreamManager provideIDreamManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIDreamManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIDreamManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIDreamManagerFactory();
  }
}
