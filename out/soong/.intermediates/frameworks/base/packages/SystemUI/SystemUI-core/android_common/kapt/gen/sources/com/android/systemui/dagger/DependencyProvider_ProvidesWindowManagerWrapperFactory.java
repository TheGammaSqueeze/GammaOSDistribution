package com.android.systemui.dagger;

import com.android.systemui.shared.system.WindowManagerWrapper;
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
public final class DependencyProvider_ProvidesWindowManagerWrapperFactory implements Factory<WindowManagerWrapper> {
  private final DependencyProvider module;

  public DependencyProvider_ProvidesWindowManagerWrapperFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public WindowManagerWrapper get() {
    return providesWindowManagerWrapper(module);
  }

  public static DependencyProvider_ProvidesWindowManagerWrapperFactory create(
      DependencyProvider module) {
    return new DependencyProvider_ProvidesWindowManagerWrapperFactory(module);
  }

  public static WindowManagerWrapper providesWindowManagerWrapper(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.providesWindowManagerWrapper());
  }
}
