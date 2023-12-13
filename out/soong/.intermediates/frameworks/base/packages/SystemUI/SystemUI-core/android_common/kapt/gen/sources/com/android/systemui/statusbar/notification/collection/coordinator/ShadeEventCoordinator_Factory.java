package com.android.systemui.statusbar.notification.collection.coordinator;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ShadeEventCoordinator_Factory implements Factory<ShadeEventCoordinator> {
  private final Provider<ShadeEventCoordinatorLogger> mLoggerProvider;

  public ShadeEventCoordinator_Factory(Provider<ShadeEventCoordinatorLogger> mLoggerProvider) {
    this.mLoggerProvider = mLoggerProvider;
  }

  @Override
  public ShadeEventCoordinator get() {
    return newInstance(mLoggerProvider.get());
  }

  public static ShadeEventCoordinator_Factory create(
      Provider<ShadeEventCoordinatorLogger> mLoggerProvider) {
    return new ShadeEventCoordinator_Factory(mLoggerProvider);
  }

  public static ShadeEventCoordinator newInstance(ShadeEventCoordinatorLogger mLogger) {
    return new ShadeEventCoordinator(mLogger);
  }
}
