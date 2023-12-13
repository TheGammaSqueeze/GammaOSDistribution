package com.android.systemui.dagger;

import android.view.Choreographer;
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
public final class DependencyProvider_ProvidesChoreographerFactory implements Factory<Choreographer> {
  private final DependencyProvider module;

  public DependencyProvider_ProvidesChoreographerFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public Choreographer get() {
    return providesChoreographer(module);
  }

  public static DependencyProvider_ProvidesChoreographerFactory create(DependencyProvider module) {
    return new DependencyProvider_ProvidesChoreographerFactory(module);
  }

  public static Choreographer providesChoreographer(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.providesChoreographer());
  }
}
