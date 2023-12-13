package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.launcher3.icons.IconProvider;
import com.android.wm.shell.RootTaskDisplayAreaOrganizer;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.recents.RecentTasksController;
import com.android.wm.shell.splitscreen.SplitScreenController;
import com.android.wm.shell.splitscreen.StageTaskUnfoldController;
import com.android.wm.shell.transition.Transitions;
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
public final class WMShellModule_ProvideSplitScreenControllerFactory implements Factory<SplitScreenController> {
  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  private final Provider<Context> contextProvider;

  private final Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<DisplayImeController> displayImeControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<Transitions> transitionsProvider;

  private final Provider<TransactionPool> transactionPoolProvider;

  private final Provider<IconProvider> iconProvider;

  private final Provider<Optional<RecentTasksController>> recentTasksProvider;

  private final Provider<Optional<StageTaskUnfoldController>> stageTaskUnfoldControllerProvider;

  public WMShellModule_ProvideSplitScreenControllerFactory(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider, Provider<Context> contextProvider,
      Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<Transitions> transitionsProvider, Provider<TransactionPool> transactionPoolProvider,
      Provider<IconProvider> iconProvider,
      Provider<Optional<RecentTasksController>> recentTasksProvider,
      Provider<Optional<StageTaskUnfoldController>> stageTaskUnfoldControllerProvider) {
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.syncQueueProvider = syncQueueProvider;
    this.contextProvider = contextProvider;
    this.rootTaskDisplayAreaOrganizerProvider = rootTaskDisplayAreaOrganizerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.displayImeControllerProvider = displayImeControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.transitionsProvider = transitionsProvider;
    this.transactionPoolProvider = transactionPoolProvider;
    this.iconProvider = iconProvider;
    this.recentTasksProvider = recentTasksProvider;
    this.stageTaskUnfoldControllerProvider = stageTaskUnfoldControllerProvider;
  }

  @Override
  public SplitScreenController get() {
    return provideSplitScreenController(shellTaskOrganizerProvider.get(), syncQueueProvider.get(), contextProvider.get(), rootTaskDisplayAreaOrganizerProvider.get(), mainExecutorProvider.get(), displayImeControllerProvider.get(), displayInsetsControllerProvider.get(), transitionsProvider.get(), transactionPoolProvider.get(), iconProvider.get(), recentTasksProvider.get(), stageTaskUnfoldControllerProvider);
  }

  public static WMShellModule_ProvideSplitScreenControllerFactory create(
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider, Provider<Context> contextProvider,
      Provider<RootTaskDisplayAreaOrganizer> rootTaskDisplayAreaOrganizerProvider,
      Provider<ShellExecutor> mainExecutorProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<Transitions> transitionsProvider, Provider<TransactionPool> transactionPoolProvider,
      Provider<IconProvider> iconProvider,
      Provider<Optional<RecentTasksController>> recentTasksProvider,
      Provider<Optional<StageTaskUnfoldController>> stageTaskUnfoldControllerProvider) {
    return new WMShellModule_ProvideSplitScreenControllerFactory(shellTaskOrganizerProvider, syncQueueProvider, contextProvider, rootTaskDisplayAreaOrganizerProvider, mainExecutorProvider, displayImeControllerProvider, displayInsetsControllerProvider, transitionsProvider, transactionPoolProvider, iconProvider, recentTasksProvider, stageTaskUnfoldControllerProvider);
  }

  public static SplitScreenController provideSplitScreenController(
      ShellTaskOrganizer shellTaskOrganizer, SyncTransactionQueue syncQueue, Context context,
      RootTaskDisplayAreaOrganizer rootTaskDisplayAreaOrganizer, ShellExecutor mainExecutor,
      DisplayImeController displayImeController, DisplayInsetsController displayInsetsController,
      Transitions transitions, TransactionPool transactionPool, IconProvider iconProvider,
      Optional<RecentTasksController> recentTasks,
      Provider<Optional<StageTaskUnfoldController>> stageTaskUnfoldControllerProvider) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideSplitScreenController(shellTaskOrganizer, syncQueue, context, rootTaskDisplayAreaOrganizer, mainExecutor, displayImeController, displayInsetsController, transitions, transactionPool, iconProvider, recentTasks, stageTaskUnfoldControllerProvider));
  }
}
