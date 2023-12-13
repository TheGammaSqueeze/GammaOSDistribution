package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipSnapAlgorithm;
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
public final class TvPipModule_ProvidePipBoundsAlgorithmFactory implements Factory<PipBoundsAlgorithm> {
  private final Provider<Context> contextProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider;

  public TvPipModule_ProvidePipBoundsAlgorithmFactory(Provider<Context> contextProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider) {
    this.contextProvider = contextProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipSnapAlgorithmProvider = pipSnapAlgorithmProvider;
  }

  @Override
  public PipBoundsAlgorithm get() {
    return providePipBoundsAlgorithm(contextProvider.get(), pipBoundsStateProvider.get(), pipSnapAlgorithmProvider.get());
  }

  public static TvPipModule_ProvidePipBoundsAlgorithmFactory create(
      Provider<Context> contextProvider, Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipSnapAlgorithm> pipSnapAlgorithmProvider) {
    return new TvPipModule_ProvidePipBoundsAlgorithmFactory(contextProvider, pipBoundsStateProvider, pipSnapAlgorithmProvider);
  }

  public static PipBoundsAlgorithm providePipBoundsAlgorithm(Context context,
      PipBoundsState pipBoundsState, PipSnapAlgorithm pipSnapAlgorithm) {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providePipBoundsAlgorithm(context, pipBoundsState, pipSnapAlgorithm));
  }
}
