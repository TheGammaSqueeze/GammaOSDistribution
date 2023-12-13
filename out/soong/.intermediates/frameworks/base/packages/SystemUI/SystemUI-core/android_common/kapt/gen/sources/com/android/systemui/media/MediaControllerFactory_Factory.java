package com.android.systemui.media;

import android.content.Context;
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
public final class MediaControllerFactory_Factory implements Factory<MediaControllerFactory> {
  private final Provider<Context> contextProvider;

  public MediaControllerFactory_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public MediaControllerFactory get() {
    return newInstance(contextProvider.get());
  }

  public static MediaControllerFactory_Factory create(Provider<Context> contextProvider) {
    return new MediaControllerFactory_Factory(contextProvider);
  }

  public static MediaControllerFactory newInstance(Context context) {
    return new MediaControllerFactory(context);
  }
}
