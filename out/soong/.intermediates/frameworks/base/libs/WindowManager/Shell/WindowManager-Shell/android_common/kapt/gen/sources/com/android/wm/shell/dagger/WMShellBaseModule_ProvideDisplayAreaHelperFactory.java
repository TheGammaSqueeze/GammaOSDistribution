package com.android.wm.shell.dagger;

import com.android.wm.shell.RootDisplayAreaOrganizer;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.displayareahelper.DisplayAreaHelper;
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
public final class WMShellBaseModule_ProvideDisplayAreaHelperFactory implements Factory<Optional<DisplayAreaHelper>> {
  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<RootDisplayAreaOrganizer> rootDisplayAreaOrganizerProvider;

  public WMShellBaseModule_ProvideDisplayAreaHelperFactory(
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<RootDisplayAreaOrganizer> rootDisplayAreaOrganizerProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
    this.rootDisplayAreaOrganizerProvider = rootDisplayAreaOrganizerProvider;
  }

  @Override
  public Optional<DisplayAreaHelper> get() {
    return provideDisplayAreaHelper(mainExecutorProvider.get(), rootDisplayAreaOrganizerProvider.get());
  }

  public static WMShellBaseModule_ProvideDisplayAreaHelperFactory create(
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<RootDisplayAreaOrganizer> rootDisplayAreaOrganizerProvider) {
    return new WMShellBaseModule_ProvideDisplayAreaHelperFactory(mainExecutorProvider, rootDisplayAreaOrganizerProvider);
  }

  public static Optional<DisplayAreaHelper> provideDisplayAreaHelper(ShellExecutor mainExecutor,
      RootDisplayAreaOrganizer rootDisplayAreaOrganizer) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDisplayAreaHelper(mainExecutor, rootDisplayAreaOrganizer));
  }
}
