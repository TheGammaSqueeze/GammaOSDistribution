package com.android.systemui.util.sensors;

import android.content.res.Resources;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class SensorModule_ProvideProximitySensorFactory implements Factory<ProximitySensor> {
  private final Provider<Resources> resourcesProvider;

  private final Provider<PostureDependentProximitySensor> postureDependentProximitySensorProvider;

  private final Provider<ProximitySensorImpl> proximitySensorProvider;

  public SensorModule_ProvideProximitySensorFactory(Provider<Resources> resourcesProvider,
      Provider<PostureDependentProximitySensor> postureDependentProximitySensorProvider,
      Provider<ProximitySensorImpl> proximitySensorProvider) {
    this.resourcesProvider = resourcesProvider;
    this.postureDependentProximitySensorProvider = postureDependentProximitySensorProvider;
    this.proximitySensorProvider = proximitySensorProvider;
  }

  @Override
  public ProximitySensor get() {
    return provideProximitySensor(resourcesProvider.get(), DoubleCheck.lazy(postureDependentProximitySensorProvider), DoubleCheck.lazy(proximitySensorProvider));
  }

  public static SensorModule_ProvideProximitySensorFactory create(
      Provider<Resources> resourcesProvider,
      Provider<PostureDependentProximitySensor> postureDependentProximitySensorProvider,
      Provider<ProximitySensorImpl> proximitySensorProvider) {
    return new SensorModule_ProvideProximitySensorFactory(resourcesProvider, postureDependentProximitySensorProvider, proximitySensorProvider);
  }

  public static ProximitySensor provideProximitySensor(Resources resources,
      Lazy<PostureDependentProximitySensor> postureDependentProximitySensorProvider,
      Lazy<ProximitySensorImpl> proximitySensorProvider) {
    return Preconditions.checkNotNullFromProvides(SensorModule.provideProximitySensor(resources, postureDependentProximitySensorProvider, proximitySensorProvider));
  }
}
