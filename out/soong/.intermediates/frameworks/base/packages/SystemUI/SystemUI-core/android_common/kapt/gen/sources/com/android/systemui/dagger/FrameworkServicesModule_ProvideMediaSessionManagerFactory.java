package com.android.systemui.dagger;

import android.content.Context;
import android.media.session.MediaSessionManager;
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
public final class FrameworkServicesModule_ProvideMediaSessionManagerFactory implements Factory<MediaSessionManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideMediaSessionManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public MediaSessionManager get() {
    return provideMediaSessionManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideMediaSessionManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideMediaSessionManagerFactory(contextProvider);
  }

  public static MediaSessionManager provideMediaSessionManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideMediaSessionManager(context));
  }
}
