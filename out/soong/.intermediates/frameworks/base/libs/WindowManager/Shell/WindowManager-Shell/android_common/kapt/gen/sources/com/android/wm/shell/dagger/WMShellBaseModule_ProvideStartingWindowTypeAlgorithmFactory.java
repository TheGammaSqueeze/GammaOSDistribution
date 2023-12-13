package com.android.wm.shell.dagger;

import com.android.wm.shell.startingsurface.StartingWindowTypeAlgorithm;
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
public final class WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory implements Factory<StartingWindowTypeAlgorithm> {
  private final Provider<Optional<StartingWindowTypeAlgorithm>> startingWindowTypeAlgorithmProvider;

  public WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory(
      Provider<Optional<StartingWindowTypeAlgorithm>> startingWindowTypeAlgorithmProvider) {
    this.startingWindowTypeAlgorithmProvider = startingWindowTypeAlgorithmProvider;
  }

  @Override
  public StartingWindowTypeAlgorithm get() {
    return provideStartingWindowTypeAlgorithm(startingWindowTypeAlgorithmProvider.get());
  }

  public static WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory create(
      Provider<Optional<StartingWindowTypeAlgorithm>> startingWindowTypeAlgorithmProvider) {
    return new WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory(startingWindowTypeAlgorithmProvider);
  }

  public static StartingWindowTypeAlgorithm provideStartingWindowTypeAlgorithm(
      Optional<StartingWindowTypeAlgorithm> startingWindowTypeAlgorithm) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideStartingWindowTypeAlgorithm(startingWindowTypeAlgorithm));
  }
}
