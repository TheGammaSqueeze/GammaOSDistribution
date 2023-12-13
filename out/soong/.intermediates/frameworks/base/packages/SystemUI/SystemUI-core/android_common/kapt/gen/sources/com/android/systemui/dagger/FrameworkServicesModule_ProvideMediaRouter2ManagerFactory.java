package com.android.systemui.dagger;

import android.content.Context;
import android.media.MediaRouter2Manager;
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
public final class FrameworkServicesModule_ProvideMediaRouter2ManagerFactory implements Factory<MediaRouter2Manager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideMediaRouter2ManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public MediaRouter2Manager get() {
    return provideMediaRouter2Manager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideMediaRouter2ManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideMediaRouter2ManagerFactory(contextProvider);
  }

  public static MediaRouter2Manager provideMediaRouter2Manager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideMediaRouter2Manager(context));
  }
}
