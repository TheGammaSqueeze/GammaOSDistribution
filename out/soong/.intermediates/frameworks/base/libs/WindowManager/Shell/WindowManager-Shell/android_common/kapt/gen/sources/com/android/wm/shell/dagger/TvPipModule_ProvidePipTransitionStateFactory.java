package com.android.wm.shell.dagger;

import com.android.wm.shell.pip.PipTransitionState;
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
public final class TvPipModule_ProvidePipTransitionStateFactory implements Factory<PipTransitionState> {
  @Override
  public PipTransitionState get() {
    return providePipTransitionState();
  }

  public static TvPipModule_ProvidePipTransitionStateFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static PipTransitionState providePipTransitionState() {
    return Preconditions.checkNotNullFromProvides(TvPipModule.providePipTransitionState());
  }

  private static final class InstanceHolder {
    private static final TvPipModule_ProvidePipTransitionStateFactory INSTANCE = new TvPipModule_ProvidePipTransitionStateFactory();
  }
}
