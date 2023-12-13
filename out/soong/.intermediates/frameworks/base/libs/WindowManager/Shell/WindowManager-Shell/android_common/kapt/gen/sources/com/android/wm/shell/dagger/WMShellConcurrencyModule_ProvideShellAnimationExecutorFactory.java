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
public final class WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory implements Factory<ShellExecutor> {
  @Override
  public ShellExecutor get() {
    return provideShellAnimationExecutor();
  }

  public static WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ShellExecutor provideShellAnimationExecutor() {
    return Preconditions.checkNotNullFromProvides(WMShellConcurrencyModule.provideShellAnimationExecutor());
  }

  private static final class InstanceHolder {
    private static final WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory INSTANCE = new WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory();
  }
}
