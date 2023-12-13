package com.android.wm.shell.dagger;

import com.android.wm.shell.RootDisplayAreaOrganizer;
import com.android.wm.shell.common.ShellExecutor;
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
public final class WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory implements Factory<RootDisplayAreaOrganizer> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory(
      Provider<ShellExecutor> mainExecutorProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public RootDisplayAreaOrganizer get() {
    return provideRootDisplayAreaOrganizer(mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory create(
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory(mainExecutorProvider);
  }

  public static RootDisplayAreaOrganizer provideRootDisplayAreaOrganizer(
      ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideRootDisplayAreaOrganizer(mainExecutor));
  }
}
