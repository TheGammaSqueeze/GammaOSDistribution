package com.android.systemui.dagger;

import android.content.Context;
import android.content.res.Resources;
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
public final class FrameworkServicesModule_ProvideResourcesFactory implements Factory<Resources> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideResourcesFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Resources get() {
    return provideResources(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideResourcesFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideResourcesFactory(contextProvider);
  }

  public static Resources provideResources(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideResources(context));
  }
}
