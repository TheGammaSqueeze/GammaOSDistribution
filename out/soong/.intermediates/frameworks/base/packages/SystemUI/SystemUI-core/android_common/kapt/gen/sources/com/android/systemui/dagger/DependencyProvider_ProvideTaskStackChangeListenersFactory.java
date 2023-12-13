package com.android.systemui.dagger;

import com.android.systemui.shared.system.TaskStackChangeListeners;
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
public final class DependencyProvider_ProvideTaskStackChangeListenersFactory implements Factory<TaskStackChangeListeners> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideTaskStackChangeListenersFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public TaskStackChangeListeners get() {
    return provideTaskStackChangeListeners(module);
  }

  public static DependencyProvider_ProvideTaskStackChangeListenersFactory create(
      DependencyProvider module) {
    return new DependencyProvider_ProvideTaskStackChangeListenersFactory(module);
  }

  public static TaskStackChangeListeners provideTaskStackChangeListeners(
      DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideTaskStackChangeListeners());
  }
}
