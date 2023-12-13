package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.wm.shell.common.SystemWindows;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.tv.TvPipMenuController;
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
public final class TvPipModule_ProvidesTvPipMenuControllerFactory implements Factory<TvPipMenuController> {
  private final Provider<Context> contextProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<SystemWindows> systemWindowsProvider;

  private final Provider<PipMediaController> pipMediaControllerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public TvPipModule_ProvidesTvPipMenuControllerFactory(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.systemWindowsProvider = systemWindowsProvider;
    this.pipMediaControllerProvider = pipMediaControllerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public TvPipMenuController get() {
    return providesTvPipMenuController(contextProvider.get(), pipBoundsStateProvider.get(), systemWindowsProvider.get(), pipMediaControllerProvider.get(), mainHandlerProvider.get());
  }

  public static TvPipModule_ProvidesTvPipMenuControllerFactory create(
      Provider<Context> contextProvider, Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<Handler> mainHandlerProvider) {
    return new TvPipModule_ProvidesTvPipMenuControllerFactory(contextProvider, pipBoundsStateProvider, systemWindowsProvider, pipMediaControllerProvider, mainHandlerProvider);
  }

  public static TvPipMenuController providesTvPipMenuController(Context context,
      PipBoundsState pipBoundsState, SystemWindows systemWindows,
      PipMediaController pipMediaController, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providesTvPipMenuController(context, pipBoundsState, systemWindows, pipMediaController, mainHandler));
  }
}
