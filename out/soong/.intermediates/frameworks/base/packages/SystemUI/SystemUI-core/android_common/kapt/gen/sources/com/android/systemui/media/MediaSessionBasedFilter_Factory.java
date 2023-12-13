package com.android.systemui.media;

import android.content.Context;
import android.media.session.MediaSessionManager;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class MediaSessionBasedFilter_Factory implements Factory<MediaSessionBasedFilter> {
  private final Provider<Context> contextProvider;

  private final Provider<MediaSessionManager> sessionManagerProvider;

  private final Provider<Executor> foregroundExecutorProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  public MediaSessionBasedFilter_Factory(Provider<Context> contextProvider,
      Provider<MediaSessionManager> sessionManagerProvider,
      Provider<Executor> foregroundExecutorProvider,
      Provider<Executor> backgroundExecutorProvider) {
    this.contextProvider = contextProvider;
    this.sessionManagerProvider = sessionManagerProvider;
    this.foregroundExecutorProvider = foregroundExecutorProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
  }

  @Override
  public MediaSessionBasedFilter get() {
    return newInstance(contextProvider.get(), sessionManagerProvider.get(), foregroundExecutorProvider.get(), backgroundExecutorProvider.get());
  }

  public static MediaSessionBasedFilter_Factory create(Provider<Context> contextProvider,
      Provider<MediaSessionManager> sessionManagerProvider,
      Provider<Executor> foregroundExecutorProvider,
      Provider<Executor> backgroundExecutorProvider) {
    return new MediaSessionBasedFilter_Factory(contextProvider, sessionManagerProvider, foregroundExecutorProvider, backgroundExecutorProvider);
  }

  public static MediaSessionBasedFilter newInstance(Context context,
      MediaSessionManager sessionManager, Executor foregroundExecutor,
      Executor backgroundExecutor) {
    return new MediaSessionBasedFilter(context, sessionManager, foregroundExecutor, backgroundExecutor);
  }
}
