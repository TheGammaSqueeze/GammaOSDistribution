package com.android.wm.shell.dagger;

import com.android.wm.shell.pip.PipSnapAlgorithm;
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
public final class TvPipModule_ProvidePipSnapAlgorithmFactory implements Factory<PipSnapAlgorithm> {
  @Override
  public PipSnapAlgorithm get() {
    return providePipSnapAlgorithm();
  }

  public static TvPipModule_ProvidePipSnapAlgorithmFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static PipSnapAlgorithm providePipSnapAlgorithm() {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providePipSnapAlgorithm());
  }

  private static final class InstanceHolder {
    private static final TvPipModule_ProvidePipSnapAlgorithmFactory INSTANCE = new TvPipModule_ProvidePipSnapAlgorithmFactory();
  }
}
