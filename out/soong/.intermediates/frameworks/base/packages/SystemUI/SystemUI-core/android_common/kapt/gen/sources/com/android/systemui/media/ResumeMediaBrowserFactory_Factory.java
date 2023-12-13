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
public final class ResumeMediaBrowserFactory_Factory implements Factory<ResumeMediaBrowserFactory> {
  private final Provider<Context> contextProvider;

  private final Provider<MediaBrowserFactory> browserFactoryProvider;

  public ResumeMediaBrowserFactory_Factory(Provider<Context> contextProvider,
      Provider<MediaBrowserFactory> browserFactoryProvider) {
    this.contextProvider = contextProvider;
    this.browserFactoryProvider = browserFactoryProvider;
  }

  @Override
  public ResumeMediaBrowserFactory get() {
    return newInstance(contextProvider.get(), browserFactoryProvider.get());
  }

  public static ResumeMediaBrowserFactory_Factory create(Provider<Context> contextProvider,
      Provider<MediaBrowserFactory> browserFactoryProvider) {
    return new ResumeMediaBrowserFactory_Factory(contextProvider, browserFactoryProvider);
  }

  public static ResumeMediaBrowserFactory newInstance(Context context,
      MediaBrowserFactory browserFactory) {
    return new ResumeMediaBrowserFactory(context, browserFactory);
  }
}
