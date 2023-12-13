package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.tv.TvPipNotificationController;
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
public final class TvPipModule_ProvideTvPipNotificationControllerFactory implements Factory<TvPipNotificationController> {
  private final Provider<Context> contextProvider;

  private final Provider<PipMediaController> pipMediaControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public TvPipModule_ProvideTvPipNotificationControllerFactory(Provider<Context> contextProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.pipMediaControllerProvider = pipMediaControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public TvPipNotificationController get() {
    return provideTvPipNotificationController(contextProvider.get(), pipMediaControllerProvider.get(), mainHandlerProvider.get());
  }

  public static TvPipModule_ProvideTvPipNotificationControllerFactory create(
      Provider<Context> contextProvider, Provider<PipMediaController> pipMediaControllerProvider,
      Provider<Handler> mainHandlerProvider) {
    return new TvPipModule_ProvideTvPipNotificationControllerFactory(contextProvider, pipMediaControllerProvider, mainHandlerProvider);
  }

  public static TvPipNotificationController provideTvPipNotificationController(Context context,
      PipMediaController pipMediaController, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.provideTvPipNotificationController(context, pipMediaController, mainHandler));
  }
}
