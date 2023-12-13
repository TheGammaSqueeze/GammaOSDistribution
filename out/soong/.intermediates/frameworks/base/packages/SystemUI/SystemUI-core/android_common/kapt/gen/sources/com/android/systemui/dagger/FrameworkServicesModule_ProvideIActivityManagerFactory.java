package com.android.systemui.dagger;

import android.app.IActivityManager;
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
public final class FrameworkServicesModule_ProvideIActivityManagerFactory implements Factory<IActivityManager> {
  @Override
  public IActivityManager get() {
    return provideIActivityManager();
  }

  public static FrameworkServicesModule_ProvideIActivityManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IActivityManager provideIActivityManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIActivityManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIActivityManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIActivityManagerFactory();
  }
}
