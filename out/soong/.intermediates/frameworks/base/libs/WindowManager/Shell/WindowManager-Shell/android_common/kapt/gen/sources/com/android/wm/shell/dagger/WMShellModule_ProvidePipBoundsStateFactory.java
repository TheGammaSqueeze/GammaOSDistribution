package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.pip.PipBoundsState;
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
public final class WMShellModule_ProvidePipBoundsStateFactory implements Factory<PipBoundsState> {
  private final Provider<Context> contextProvider;

  public WMShellModule_ProvidePipBoundsStateFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public PipBoundsState get() {
    return providePipBoundsState(contextProvider.get());
  }

  public static WMShellModule_ProvidePipBoundsStateFactory create(
      Provider<Context> contextProvider) {
    return new WMShellModule_ProvidePipBoundsStateFactory(contextProvider);
  }

  public static PipBoundsState providePipBoundsState(Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePipBoundsState(context));
  }
}
