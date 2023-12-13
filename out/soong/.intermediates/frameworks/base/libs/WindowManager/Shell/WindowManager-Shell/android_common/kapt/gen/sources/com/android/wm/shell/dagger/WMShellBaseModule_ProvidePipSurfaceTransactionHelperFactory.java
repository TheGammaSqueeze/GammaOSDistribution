package com.android.wm.shell.dagger;

import com.android.wm.shell.pip.PipSurfaceTransactionHelper;
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
public final class WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory implements Factory<PipSurfaceTransactionHelper> {
  @Override
  public PipSurfaceTransactionHelper get() {
    return providePipSurfaceTransactionHelper();
  }

  public static WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static PipSurfaceTransactionHelper providePipSurfaceTransactionHelper() {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providePipSurfaceTransactionHelper());
  }

  private static final class InstanceHolder {
    private static final WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory INSTANCE = new WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory();
  }
}
