package com.android.systemui.dagger;

import android.app.IActivityTaskManager;
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
public final class FrameworkServicesModule_ProvideIActivityTaskManagerFactory implements Factory<IActivityTaskManager> {
  @Override
  public IActivityTaskManager get() {
    return provideIActivityTaskManager();
  }

  public static FrameworkServicesModule_ProvideIActivityTaskManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IActivityTaskManager provideIActivityTaskManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIActivityTaskManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIActivityTaskManagerFactory INSTANCE = new FrameworkServicesModule_ProvideIActivityTaskManagerFactory();
  }
}
