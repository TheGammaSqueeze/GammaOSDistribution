package com.android.wm.shell.dagger;

import com.android.wm.shell.splitscreen.SplitScreen;
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
public final class WMShellBaseModule_ProvideSplitScreenFactory implements Factory<Optional<SplitScreen>> {
  private final Provider<Optional<SplitScreenController>> splitScreenControllerProvider;

  public WMShellBaseModule_ProvideSplitScreenFactory(
      Provider<Optional<SplitScreenController>> splitScreenControllerProvider) {
    this.splitScreenControllerProvider = splitScreenControllerProvider;
  }

  @Override
  public Optional<SplitScreen> get() {
    return provideSplitScreen(splitScreenControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideSplitScreenFactory create(
      Provider<Optional<SplitScreenController>> splitScreenControllerProvider) {
    return new WMShellBaseModule_ProvideSplitScreenFactory(splitScreenControllerProvider);
  }

  public static Optional<SplitScreen> provideSplitScreen(
      Optional<SplitScreenController> splitScreenController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideSplitScreen(splitScreenController));
  }
}
