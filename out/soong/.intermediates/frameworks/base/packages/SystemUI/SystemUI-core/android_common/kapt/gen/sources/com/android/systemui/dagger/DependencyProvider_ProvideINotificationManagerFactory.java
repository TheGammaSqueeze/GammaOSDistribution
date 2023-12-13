package com.android.systemui.dagger;

import android.app.INotificationManager;
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
public final class DependencyProvider_ProvideINotificationManagerFactory implements Factory<INotificationManager> {
  private final DependencyProvider module;

  public DependencyProvider_ProvideINotificationManagerFactory(DependencyProvider module) {
    this.module = module;
  }

  @Override
  public INotificationManager get() {
    return provideINotificationManager(module);
  }

  public static DependencyProvider_ProvideINotificationManagerFactory create(
      DependencyProvider module) {
    return new DependencyProvider_ProvideINotificationManagerFactory(module);
  }

  public static INotificationManager provideINotificationManager(DependencyProvider instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideINotificationManager());
  }
}
