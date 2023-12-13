package com.android.wm.shell.dagger;

import android.animation.AnimationHandler;
import android.content.Context;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.SystemWindows;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreenController;
import com.android.wm.shell.transition.Transitions;
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
public final class WMShellModule_ProvideLegacySplitScreenFactory implements Factory<LegacySplitScreenController> {
  private final Provider<Context> contextProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<SystemWindows> systemWindowsProvider;

  private final Provider<DisplayImeController> displayImeControllerProvider;

  private final Provider<TransactionPool> transactionPoolProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<SyncTransactionQueue> syncQueueProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<Transitions> transitionsProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  private final Provider<AnimationHandler> sfVsyncAnimationHandlerProvider;

  public WMShellModule_ProvideLegacySplitScreenFactory(Provider<Context> contextProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<TransactionPool> transactionPoolProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<Transitions> transitionsProvider, Provider<ShellExecutor> mainExecutorProvider,
      Provider<AnimationHandler> sfVsyncAnimationHandlerProvider) {
    this.contextProvider = contextProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.systemWindowsProvider = systemWindowsProvider;
    this.displayImeControllerProvider = displayImeControllerProvider;
    this.transactionPoolProvider = transactionPoolProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.syncQueueProvider = syncQueueProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.transitionsProvider = transitionsProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.sfVsyncAnimationHandlerProvider = sfVsyncAnimationHandlerProvider;
  }

  @Override
  public LegacySplitScreenController get() {
    return provideLegacySplitScreen(contextProvider.get(), displayControllerProvider.get(), systemWindowsProvider.get(), displayImeControllerProvider.get(), transactionPoolProvider.get(), shellTaskOrganizerProvider.get(), syncQueueProvider.get(), taskStackListenerProvider.get(), transitionsProvider.get(), mainExecutorProvider.get(), sfVsyncAnimationHandlerProvider.get());
  }

  public static WMShellModule_ProvideLegacySplitScreenFactory create(
      Provider<Context> contextProvider, Provider<DisplayController> displayControllerProvider,
      Provider<SystemWindows> systemWindowsProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<TransactionPool> transactionPoolProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<SyncTransactionQueue> syncQueueProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<Transitions> transitionsProvider, Provider<ShellExecutor> mainExecutorProvider,
      Provider<AnimationHandler> sfVsyncAnimationHandlerProvider) {
    return new WMShellModule_ProvideLegacySplitScreenFactory(contextProvider, displayControllerProvider, systemWindowsProvider, displayImeControllerProvider, transactionPoolProvider, shellTaskOrganizerProvider, syncQueueProvider, taskStackListenerProvider, transitionsProvider, mainExecutorProvider, sfVsyncAnimationHandlerProvider);
  }

  public static LegacySplitScreenController provideLegacySplitScreen(Context context,
      DisplayController displayController, SystemWindows systemWindows,
      DisplayImeController displayImeController, TransactionPool transactionPool,
      ShellTaskOrganizer shellTaskOrganizer, SyncTransactionQueue syncQueue,
      TaskStackListenerImpl taskStackListener, Transitions transitions, ShellExecutor mainExecutor,
      AnimationHandler sfVsyncAnimationHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.provideLegacySplitScreen(context, displayController, systemWindows, displayImeController, transactionPool, shellTaskOrganizer, syncQueue, taskStackListener, transitions, mainExecutor, sfVsyncAnimationHandler));
  }
}
