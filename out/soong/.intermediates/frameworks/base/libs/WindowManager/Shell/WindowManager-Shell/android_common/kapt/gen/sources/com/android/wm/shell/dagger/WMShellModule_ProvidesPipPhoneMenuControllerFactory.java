package com.android.wm.shell.dagger;

import android.content.Context;
import android.os.Handler;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SystemWindows;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.splitscreen.SplitScreenController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
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
public final class WMShellModule_ProvidesPipPhoneMenuControllerFactory implements Factory<PhonePipMenuController> {
  private final Provider<Context> contextProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipMediaController> pipMediaControllerProvider;

  private final Provider<SystemWindows> systemWindowsProvider;

  private final Provider<Optional<SplitScreenController>> splitScreenOptionalProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<Handler> mainHandlerProvider;

  public WMShellModule_ProvidesPipPhoneMenuControllerFactory(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<ShellExecutor> mainExecutorProvider, Provider<Handler> mainHandlerProvider) {
    this.contextProvider = contextProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipMediaControllerProvider = pipMediaControllerProvider;
    this.systemWindowsProvider = systemWindowsProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public PhonePipMenuController get() {
    return providesPipPhoneMenuController(contextProvider.get(), pipBoundsStateProvider.get(), pipMediaControllerProvider.get(), systemWindowsProvider.get(), splitScreenOptionalProvider.get(), mainExecutorProvider.get(), mainHandlerProvider.get());
  }

  public static WMShellModule_ProvidesPipPhoneMenuControllerFactory create(
      Provider<Context> contextProvider, Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<ShellExecutor> mainExecutorProvider, Provider<Handler> mainHandlerProvider) {
    return new WMShellModule_ProvidesPipPhoneMenuControllerFactory(contextProvider, pipBoundsStateProvider, pipMediaControllerProvider, systemWindowsProvider, splitScreenOptionalProvider, mainExecutorProvider, mainHandlerProvider);
  }

  public static PhonePipMenuController providesPipPhoneMenuController(Context context,
      PipBoundsState pipBoundsState, PipMediaController pipMediaController,
      SystemWindows systemWindows, Optional<SplitScreenController> splitScreenOptional,
      ShellExecutor mainExecutor, Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providesPipPhoneMenuController(context, pipBoundsState, pipMediaController, systemWindows, splitScreenOptional, mainExecutor, mainHandler));
  }
}
