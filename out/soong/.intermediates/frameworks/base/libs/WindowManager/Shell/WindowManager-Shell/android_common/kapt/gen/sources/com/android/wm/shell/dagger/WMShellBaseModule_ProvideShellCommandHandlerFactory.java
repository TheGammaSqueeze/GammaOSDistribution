package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellCommandHandler;
import com.android.wm.shell.ShellCommandHandlerImpl;
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
public final class WMShellBaseModule_ProvideShellCommandHandlerFactory implements Factory<Optional<ShellCommandHandler>> {
  private final Provider<ShellCommandHandlerImpl> implProvider;

  public WMShellBaseModule_ProvideShellCommandHandlerFactory(
      Provider<ShellCommandHandlerImpl> implProvider) {
    this.implProvider = implProvider;
  }

  @Override
  public Optional<ShellCommandHandler> get() {
    return provideShellCommandHandler(implProvider.get());
  }

  public static WMShellBaseModule_ProvideShellCommandHandlerFactory create(
      Provider<ShellCommandHandlerImpl> implProvider) {
    return new WMShellBaseModule_ProvideShellCommandHandlerFactory(implProvider);
  }

  public static Optional<ShellCommandHandler> provideShellCommandHandler(
      ShellCommandHandlerImpl impl) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideShellCommandHandler(impl));
  }
}
