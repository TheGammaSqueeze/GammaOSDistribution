package com.android.wm.shell.dagger;

import com.android.wm.shell.startingsurface.StartingWindowTypeAlgorithm;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class TvWMShellModule_ProvideStartingWindowTypeAlgorithmFactory implements Factory<StartingWindowTypeAlgorithm> {
  @Override
  public StartingWindowTypeAlgorithm get() {
    return provideStartingWindowTypeAlgorithm();
  }

  public static TvWMShellModule_ProvideStartingWindowTypeAlgorithmFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static StartingWindowTypeAlgorithm provideStartingWindowTypeAlgorithm() {
    return Preconditions.checkNotNullFromProvides(TvWMShellModule.provideStartingWindowTypeAlgorithm());
  }

  private static final class InstanceHolder {
    private static final TvWMShellModule_ProvideStartingWindowTypeAlgorithmFactory INSTANCE = new TvWMShellModule_ProvideStartingWindowTypeAlgorithmFactory();
  }
}
