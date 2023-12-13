package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellInit;
import com.android.wm.shell.ShellInitImpl;
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
public final class WMShellBaseModule_ProvideShellInitFactory implements Factory<ShellInit> {
  private final Provider<ShellInitImpl> implProvider;

  public WMShellBaseModule_ProvideShellInitFactory(Provider<ShellInitImpl> implProvider) {
    this.implProvider = implProvider;
  }

  @Override
  public ShellInit get() {
    return provideShellInit(implProvider.get());
  }

  public static WMShellBaseModule_ProvideShellInitFactory create(
      Provider<ShellInitImpl> implProvider) {
    return new WMShellBaseModule_ProvideShellInitFactory(implProvider);
  }

  public static ShellInit provideShellInit(ShellInitImpl impl) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideShellInit(impl));
  }
}
