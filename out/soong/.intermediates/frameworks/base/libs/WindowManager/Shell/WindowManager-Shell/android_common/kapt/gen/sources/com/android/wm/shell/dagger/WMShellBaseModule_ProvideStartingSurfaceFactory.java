package com.android.wm.shell.dagger;

import com.android.wm.shell.startingsurface.StartingSurface;
import com.android.wm.shell.startingsurface.StartingWindowController;
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
public final class WMShellBaseModule_ProvideStartingSurfaceFactory implements Factory<Optional<StartingSurface>> {
  private final Provider<StartingWindowController> startingWindowControllerProvider;

  public WMShellBaseModule_ProvideStartingSurfaceFactory(
      Provider<StartingWindowController> startingWindowControllerProvider) {
    this.startingWindowControllerProvider = startingWindowControllerProvider;
  }

  @Override
  public Optional<StartingSurface> get() {
    return provideStartingSurface(startingWindowControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideStartingSurfaceFactory create(
      Provider<StartingWindowController> startingWindowControllerProvider) {
    return new WMShellBaseModule_ProvideStartingSurfaceFactory(startingWindowControllerProvider);
  }

  public static Optional<StartingSurface> provideStartingSurface(
      StartingWindowController startingWindowController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideStartingSurface(startingWindowController));
  }
}
