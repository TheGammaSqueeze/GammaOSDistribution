package com.android.wm.shell.dagger;

import com.android.wm.shell.common.ShellExecutor;
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
public final class WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory implements Factory<ShellExecutor> {
  @Override
  public ShellExecutor get() {
    return provideSplashScreenExecutor();
  }

  public static WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ShellExecutor provideSplashScreenExecutor() {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideSplashScreenExecutor());
  }

  private static final class InstanceHolder {
    private static final WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory INSTANCE = new WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory();
  }
}
