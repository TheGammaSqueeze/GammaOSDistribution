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
public final class MediaBrowserFactory_Factory implements Factory<MediaBrowserFactory> {
  private final Provider<Context> contextProvider;

  public MediaBrowserFactory_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public MediaBrowserFactory get() {
    return newInstance(contextProvider.get());
  }

  public static MediaBrowserFactory_Factory create(Provider<Context> contextProvider) {
    return new MediaBrowserFactory_Factory(contextProvider);
  }

  public static MediaBrowserFactory newInstance(Context context) {
    return new MediaBrowserFactory(context);
  }
}
