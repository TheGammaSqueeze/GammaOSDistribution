package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.RootTaskDisplayAreaOrganizer;
import com.android.wm.shell.unfold.UnfoldBackgroundController;
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
public final class WMShellModule_ProvideUnfoldBackgroundControllerFactory implements Factory<UnfoldBackgroundController> {
  private final Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider;

  private final Provider<Context> contextProvider;

  public WMShellModule_ProvideUnfoldBackgroundControllerFactory(
      Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider,
      Provider<Context> contextProvider) {
    this.rootTaskDisplayAreaOrganizerProvider = rootTaskDisplayAreaOrganizerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public UnfoldBackgroundController get() {
    return provideUnfoldBackgroundController(rootTaskDisplayAreaOrganizerProvider.get(), contextProvider.get());
  }

  public static WMShellModule_ProvideUnfoldBackgroundControllerFactory create(
      Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider,
      Provider<Context> contextProvider) {
    return new WMShellModule_ProvideUnfoldBackgroundControllerFactory(rootTaskDisplayAreaOrganizerProvider, contextProvider);
  }

  public static UnfoldBackgroundController provideUnfoldBackgroundController(
      RootTaskDisplayAreaOrganizer rootTaskDisplayAreaOrganizer, Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideUnfoldBackgroundController(rootTaskDisplayAreaOrganizer, context));
  }
}
