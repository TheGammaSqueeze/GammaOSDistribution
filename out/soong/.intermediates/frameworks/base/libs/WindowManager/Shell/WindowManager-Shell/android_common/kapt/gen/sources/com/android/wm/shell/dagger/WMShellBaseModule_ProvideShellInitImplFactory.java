package com.android.wm.shell.dagger;

import com.android.wm.shell.ShellInitImpl;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.apppairs.AppPairsController;
import com.android.wm.shell.bubbles.BubbleController;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.draganddrop.DragAndDropController;
import com.android.wm.shell.freeform.FreeformTaskListener;
import com.android.wm.shell.fullscreen.FullscreenTaskListener;
import com.android.wm.shell.fullscreen.FullscreenUnfoldController;
import com.android.wm.shell.pip.phone.PipTouchHandler;
import com.android.wm.shell.recents.RecentTasksController;
import com.android.wm.shell.splitscreen.SplitScreenController;
import com.android.wm.shell.startingsurface.StartingWindowController;
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
public final class WMShellBaseModule_ProvideShellInitImplFactory implements Factory<ShellInitImpl> {
  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<DisplayImeController> displayImeControllerProvider;

  private final Provider<DisplayInsetsController> displayInsetsControllerProvider;

  private final Provider<DragAndDropController> dragAndDropControllerProvider;

  private final Provider<ShellTaskOrganizer> shellTaskOrganizerProvider;

  private final Provider<Optional<BubbleController>> bubblesOptionalProvider;

  private final Provider<Optional<SplitScreenController>> splitScreenOptionalProvider;

  private final Provider<Optional<AppPairsController>> appPairsOptionalProvider;

  private final Provider<Optional<PipTouchHandler>> pipTouchHandlerOptionalProvider;

  private final Provider<FullscreenTaskListener> fullscreenTaskListenerProvider;

  private final Provider<Optional<FullscreenUnfoldController>> appUnfoldTransitionControllerProvider;

  private final Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider;

  private final Provider<Optional<RecentTasksController>> recentTasksOptionalProvider;

  private final Provider<Transitions> transitionsProvider;

  private final Provider<StartingWindowController> startingWindowProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellBaseModule_ProvideShellInitImplFactory(
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<DragAndDropController> dragAndDropControllerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<Optional<BubbleController>> bubblesOptionalProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<AppPairsController>> appPairsOptionalProvider,
      Provider<Optional<PipTouchHandler>> pipTouchHandlerOptionalProvider,
      Provider<FullscreenTaskListener> fullscreenTaskListenerProvider,
      Provider<Optional<FullscreenUnfoldController>> appUnfoldTransitionControllerProvider,
      Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider,
      Provider<Transitions> transitionsProvider,
      Provider<StartingWindowController> startingWindowProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.displayControllerProvider = displayControllerProvider;
    this.displayImeControllerProvider = displayImeControllerProvider;
    this.displayInsetsControllerProvider = displayInsetsControllerProvider;
    this.dragAndDropControllerProvider = dragAndDropControllerProvider;
    this.shellTaskOrganizerProvider = shellTaskOrganizerProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.appPairsOptionalProvider = appPairsOptionalProvider;
    this.pipTouchHandlerOptionalProvider = pipTouchHandlerOptionalProvider;
    this.fullscreenTaskListenerProvider = fullscreenTaskListenerProvider;
    this.appUnfoldTransitionControllerProvider = appUnfoldTransitionControllerProvider;
    this.freeformTaskListenerProvider = freeformTaskListenerProvider;
    this.recentTasksOptionalProvider = recentTasksOptionalProvider;
    this.transitionsProvider = transitionsProvider;
    this.startingWindowProvider = startingWindowProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public ShellInitImpl get() {
    return provideShellInitImpl(displayControllerProvider.get(), displayImeControllerProvider.get(), displayInsetsControllerProvider.get(), dragAndDropControllerProvider.get(), shellTaskOrganizerProvider.get(), bubblesOptionalProvider.get(), splitScreenOptionalProvider.get(), appPairsOptionalProvider.get(), pipTouchHandlerOptionalProvider.get(), fullscreenTaskListenerProvider.get(), appUnfoldTransitionControllerProvider.get(), freeformTaskListenerProvider.get(), recentTasksOptionalProvider.get(), transitionsProvider.get(), startingWindowProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellBaseModule_ProvideShellInitImplFactory create(
      Provider<DisplayController> displayControllerProvider,
      Provider<DisplayImeController> displayImeControllerProvider,
      Provider<DisplayInsetsController> displayInsetsControllerProvider,
      Provider<DragAndDropController> dragAndDropControllerProvider,
      Provider<ShellTaskOrganizer> shellTaskOrganizerProvider,
      Provider<Optional<BubbleController>> bubblesOptionalProvider,
      Provider<Optional<SplitScreenController>> splitScreenOptionalProvider,
      Provider<Optional<AppPairsController>> appPairsOptionalProvider,
      Provider<Optional<PipTouchHandler>> pipTouchHandlerOptionalProvider,
      Provider<FullscreenTaskListener> fullscreenTaskListenerProvider,
      Provider<Optional<FullscreenUnfoldController>> appUnfoldTransitionControllerProvider,
      Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider,
      Provider<Optional<RecentTasksController>> recentTasksOptionalProvider,
      Provider<Transitions> transitionsProvider,
      Provider<StartingWindowController> startingWindowProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellBaseModule_ProvideShellInitImplFactory(displayControllerProvider, displayImeControllerProvider, displayInsetsControllerProvider, dragAndDropControllerProvider, shellTaskOrganizerProvider, bubblesOptionalProvider, splitScreenOptionalProvider, appPairsOptionalProvider, pipTouchHandlerOptionalProvider, fullscreenTaskListenerProvider, appUnfoldTransitionControllerProvider, freeformTaskListenerProvider, recentTasksOptionalProvider, transitionsProvider, startingWindowProvider, mainExecutorProvider);
  }

  public static ShellInitImpl provideShellInitImpl(DisplayController displayController,
      DisplayImeController displayImeController, DisplayInsetsController displayInsetsController,
      DragAndDropController dragAndDropController, ShellTaskOrganizer shellTaskOrganizer,
      Optional<BubbleController> bubblesOptional,
      Optional<SplitScreenController> splitScreenOptional,
      Optional<AppPairsController> appPairsOptional,
      Optional<PipTouchHandler> pipTouchHandlerOptional,
      FullscreenTaskListener fullscreenTaskListener,
      Optional<FullscreenUnfoldController> appUnfoldTransitionController,
      Optional<FreeformTaskListener> freeformTaskListener,
      Optional<RecentTasksController> recentTasksOptional, Transitions transitions,
      StartingWindowController startingWindow, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideShellInitImpl(displayController, displayImeController, displayInsetsController, dragAndDropController, shellTaskOrganizer, bubblesOptional, splitScreenOptional, appPairsOptional, pipTouchHandlerOptional, fullscreenTaskListener, appUnfoldTransitionController, freeformTaskListener, recentTasksOptional, transitions, startingWindow, mainExecutor));
  }
}
