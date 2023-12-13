package com.android.systemui.dagger;

import android.content.Context;
import android.content.om.OverlayManager;
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
public final class FrameworkServicesModule_ProvideOverlayManagerFactory implements Factory<OverlayManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideOverlayManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public OverlayManager get() {
    return provideOverlayManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideOverlayManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideOverlayManagerFactory(contextProvider);
  }

  public static OverlayManager provideOverlayManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideOverlayManager(context));
  }
}
