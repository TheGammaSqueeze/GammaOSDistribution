package com.android.systemui.media;

import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class MediaTimeoutListener_Factory implements Factory<MediaTimeoutListener> {
  private final Provider<MediaControllerFactory> mediaControllerFactoryProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  public MediaTimeoutListener_Factory(
      Provider<MediaControllerFactory> mediaControllerFactoryProvider,
      Provider<DelayableExecutor> mainExecutorProvider) {
    this.mediaControllerFactoryProvider = mediaControllerFactoryProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public MediaTimeoutListener get() {
    return newInstance(mediaControllerFactoryProvider.get(), mainExecutorProvider.get());
  }

  public static MediaTimeoutListener_Factory create(
      Provider<MediaControllerFactory> mediaControllerFactoryProvider,
      Provider<DelayableExecutor> mainExecutorProvider) {
    return new MediaTimeoutListener_Factory(mediaControllerFactoryProvider, mainExecutorProvider);
  }

  public static MediaTimeoutListener newInstance(MediaControllerFactory mediaControllerFactory,
      DelayableExecutor mainExecutor) {
    return new MediaTimeoutListener(mediaControllerFactory, mainExecutor);
  }
}
