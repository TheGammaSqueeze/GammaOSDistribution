package com.android.systemui.statusbar.notification.collection.coordinator.dagger;

import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class CoordinatorsModule_NotifCoordinatorsFactory implements Factory<NotifCoordinators> {
  private final Provider<CoordinatorsSubcomponent.Factory> factoryProvider;

  public CoordinatorsModule_NotifCoordinatorsFactory(
      Provider<CoordinatorsSubcomponent.Factory> factoryProvider) {
    this.factoryProvider = factoryProvider;
  }

  @Override
  public NotifCoordinators get() {
    return notifCoordinators(factoryProvider.get());
  }

  public static CoordinatorsModule_NotifCoordinatorsFactory create(
      Provider<CoordinatorsSubcomponent.Factory> factoryProvider) {
    return new CoordinatorsModule_NotifCoordinatorsFactory(factoryProvider);
  }

  public static NotifCoordinators notifCoordinators(CoordinatorsSubcomponent.Factory factory) {
    return Preconditions.checkNotNullFromProvides(CoordinatorsModule.notifCoordinators(factory));
  }
}
