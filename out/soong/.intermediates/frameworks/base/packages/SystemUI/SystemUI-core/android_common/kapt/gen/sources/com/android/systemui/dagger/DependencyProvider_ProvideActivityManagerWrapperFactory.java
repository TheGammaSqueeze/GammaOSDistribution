package com.android.systemui.dagger;

import com.android.systemui.shared.system.ActivityManagerWrapper;
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
public final class DependencyProvider_ProvideActivityManagerWrapperFactory implements Factory<ActivityManagerWrapper> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideActivityManagerWrapperFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public ActivityManagerWrapper get() {
    return provideActivityManagerWrapper(module);
  }

  public static DependencyProvider_ProvideActivityManagerWrapperFactory create(
      DependencyProvider module) {
    return new DependencyProvider_ProvideActivityManagerWrapperFactory(module);
  }

  public static ActivityManagerWrapper provideActivityManagerWrapper(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideActivityManagerWrapper());
  }
}
