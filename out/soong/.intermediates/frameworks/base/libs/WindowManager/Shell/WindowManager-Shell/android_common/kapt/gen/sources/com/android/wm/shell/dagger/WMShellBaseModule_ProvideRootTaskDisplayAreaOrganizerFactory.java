package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.RootTaskDisplayAreaOrganizer;
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
public final class WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory implements Factory<RootTaskDisplayAreaOrganizer> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<Context> contextProvider;

  public WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory(
      Provider<ShellExecutor> mainExecutorProvider, Provider<Context> contextProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public RootTaskDisplayAreaOrganizer get() {
    return provideRootTaskDisplayAreaOrganizer(mainExecutorProvider.get(), contextProvider.get());
  }

  public static WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory create(
      Provider<ShellExecutor> mainExecutorProvider, Provider<Context> contextProvider) {
    return new WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory(mainExecutorProvider, contextProvider);
  }

  public static RootTaskDisplayAreaOrganizer provideRootTaskDisplayAreaOrganizer(
      ShellExecutor mainExecutor, Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideRootTaskDisplayAreaOrganizer(mainExecutor, context));
  }
}
