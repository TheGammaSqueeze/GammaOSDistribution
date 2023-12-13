package com.android.systemui.screenshot;

import android.content.Context;
import com.android.internal.logging.UiEventLogger;
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
public final class ScrollCaptureController_Factory implements Factory<ScrollCaptureController> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<ScrollCaptureClient> clientProvider;

  private final Provider<ImageTileSet> imageTileSetProvider;

  private final Provider<UiEventLogger> loggerProvider;

  public ScrollCaptureController_Factory(Provider<Context> contextProvider,
      Provider<Executor> bgExecutorProvider, Provider<ScrollCaptureClient> clientProvider,
      Provider<ImageTileSet> imageTileSetProvider, Provider<UiEventLogger> loggerProvider) {
    this.contextProvider = contextProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.clientProvider = clientProvider;
    this.imageTileSetProvider = imageTileSetProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public ScrollCaptureController get() {
    return newInstance(contextProvider.get(), bgExecutorProvider.get(), clientProvider.get(), imageTileSetProvider.get(), loggerProvider.get());
  }

  public static ScrollCaptureController_Factory create(Provider<Context> contextProvider,
      Provider<Executor> bgExecutorProvider, Provider<ScrollCaptureClient> clientProvider,
      Provider<ImageTileSet> imageTileSetProvider, Provider<UiEventLogger> loggerProvider) {
    return new ScrollCaptureController_Factory(contextProvider, bgExecutorProvider, clientProvider, imageTileSetProvider, loggerProvider);
  }

  public static ScrollCaptureController newInstance(Context context, Executor bgExecutor,
      ScrollCaptureClient client, Object imageTileSet, UiEventLogger logger) {
    return new ScrollCaptureController(context, bgExecutor, client, (ImageTileSet) imageTileSet, logger);
  }
}
