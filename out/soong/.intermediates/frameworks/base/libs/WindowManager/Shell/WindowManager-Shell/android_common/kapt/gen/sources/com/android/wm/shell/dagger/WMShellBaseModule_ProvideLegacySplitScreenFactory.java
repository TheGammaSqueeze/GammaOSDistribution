package com.android.wm.shell.dagger;

import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreenController;
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
public final class WMShellBaseModule_ProvideLegacySplitScreenFactory implements Factory<Optional<LegacySplitScreen>> {
  private final Provider<Optional<LegacySplitScreenController>> splitScreenControllerProvider;

  public WMShellBaseModule_ProvideLegacySplitScreenFactory(
      Provider<Optional<LegacySplitScreenController>> splitScreenControllerProvider) {
    this.splitScreenControllerProvider = splitScreenControllerProvider;
  }

  @Override
  public Optional<LegacySplitScreen> get() {
    return provideLegacySplitScreen(splitScreenControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideLegacySplitScreenFactory create(
      Provider<Optional<LegacySplitScreenController>> splitScreenControllerProvider) {
    return new WMShellBaseModule_ProvideLegacySplitScreenFactory(splitScreenControllerProvider);
  }

  public static Optional<LegacySplitScreen> provideLegacySplitScreen(
      Optional<LegacySplitScreenController> splitScreenController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideLegacySplitScreen(splitScreenController));
  }
}
