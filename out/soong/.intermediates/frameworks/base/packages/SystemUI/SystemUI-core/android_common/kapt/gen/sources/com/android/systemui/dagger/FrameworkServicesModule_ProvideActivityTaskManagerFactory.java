package com.android.systemui.dagger;

import android.app.ActivityTaskManager;
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
public final class FrameworkServicesModule_ProvideActivityTaskManagerFactory implements Factory<ActivityTaskManager> {
  @Override
  public ActivityTaskManager get() {
    return provideActivityTaskManager();
  }

  public static FrameworkServicesModule_ProvideActivityTaskManagerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ActivityTaskManager provideActivityTaskManager() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideActivityTaskManager());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideActivityTaskManagerFactory INSTANCE = new FrameworkServicesModule_ProvideActivityTaskManagerFactory();
  }
}
