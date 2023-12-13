package com.android.wm.shell.dagger;

import android.content.Context;
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
public final class WMShellBaseModule_ProvidesSplitScreenControllerFactory implements Factory<Optional<SplitScreenController>> {
  private final Provider<Optional<SplitScreenController>> splitscreenControllerProvider;

  private final Provider<Context> contextProvider;

  public WMShellBaseModule_ProvidesSplitScreenControllerFactory(
      Provider<Optional<SplitScreenController>> splitscreenControllerProvider,
      Provider<Context> contextProvider) {
    this.splitscreenControllerProvider = splitscreenControllerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public Optional<SplitScreenController> get() {
    return providesSplitScreenController(splitscreenControllerProvider.get(), contextProvider.get());
  }

  public static WMShellBaseModule_ProvidesSplitScreenControllerFactory create(
      Provider<Optional<SplitScreenController>> splitscreenControllerProvider,
      Provider<Context> contextProvider) {
    return new WMShellBaseModule_ProvidesSplitScreenControllerFactory(splitscreenControllerProvider, contextProvider);
  }

  public static Optional<SplitScreenController> providesSplitScreenController(
      Optional<SplitScreenController> splitscreenController, Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providesSplitScreenController(splitscreenController, context));
  }
}
