package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellCommandHandlerImpl;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.apppairs.AppPairsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.hidedisplaycutout.HideDisplayCutoutController;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreenController;
import com.android.wm.shell.onehanded.OneHandedController;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.recents.RecentTasksController;
import com.android.wm.shell.splitscreen.SplitScreenController;
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
public final class WMShellBaseModule_ProvideShellCommandHandlerImplFactory implements Factory<ShellCommandHandlerImpl> {
  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<Optional<LegacySplitScreenController>> legacySplitScreenOptionalProvider;

  private final Provider<Optional<SplitScreenController>> splitScreenOptionalProvider;

  private final Provider<Optional<Pip>> pipOptionalProvider;

  private final Provider<Optional<OneHandedController>> oneHandedOptionalProvider;

  private final Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutProvider;

  private final Provider<Optional<AppPairsController>> appPairsOptionalProvider;

  private final Provider<Optional<RecentTasksController>> recentTasksOptionalProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideShellCommandHandlerImplFactory(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<Optional<LegacySplitScreenController>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<OneHandedController>> oneHandedOptionalProvider,
      Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutProvider,
      Provider<Optional<AppPairsController>> appPairsOptionalProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.legacySplitScreenOptionalProvider = legacySplitScreenOptionalProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.pipOptionalProvider = pipOptionalProvider;
    this.oneHandedOptionalProvider = oneHandedOptionalProvider;
    this.hideDisplayCutoutProvider = hideDisplayCutoutProvider;
    this.appPairsOptionalProvider = appPairsOptionalProvider;
    this.recentTasksOptionalProvider = recentTasksOptionalProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public ShellCommandHandlerImpl get() {
    return provideShellCommandHandlerImpl(shellTaskOrganizerProvider.get(), legacySplitScreenOptionalProvider.get(), splitScreenOptionalProvider.get(), pipOptionalProvider.get(), oneHandedOptionalProvider.get(), hideDisplayCutoutProvider.get(), appPairsOptionalProvider.get(), recentTasksOptionalProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideShellCommandHandlerImplFactory create(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<Optional<LegacySplitScreenController>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<OneHandedController>> oneHandedOptionalProvider,
      Provider<Optional<HideDisplayCutoutController>> hideDisplayCutoutProvider,
      Provider<Optional<AppPairsController>> appPairsOptionalProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideShellCommandHandlerImplFactory(shellTaskOrganizerProvider, legacySplitScreenOptionalProvider, splitScreenOptionalProvider, pipOptionalProvider, oneHandedOptionalProvider, hideDisplayCutoutProvider, appPairsOptionalProvider, recentTasksOptionalProvider, mainExecutorProvider);
  }

  public static ShellCommandHandlerImpl provideShellCommandHandlerImpl(
      ShellTaskOrganizer shellTaskOrganizer,
      Optional<LegacySplitScreenController> legacySplitScreenOptional,
      Optional<SplitScreenController> splitScreenOptional, Optional<Pip> pipOptional,
      Optional<OneHandedController> oneHandedOptional,
      Optional<HideDisplayCutoutController> hideDisplayCutout,
      Optional<AppPairsController> appPairsOptional,
      Optional<RecentTasksController> recentTasksOptional, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideShellCommandHandlerImpl(shellTaskOrganizer, legacySplitScreenOptional, splitScreenOptional, pipOptional, oneHandedOptional, hideDisplayCutout, appPairsOptional, recentTasksOptional, mainExecutor));
  }
}
