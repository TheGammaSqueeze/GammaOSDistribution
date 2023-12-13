package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.WindowManagerShellWrapper;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.onehanded.OneHandedController;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.pip.phone.PipAppOpsListener;
import com.android.wm.shell.pip.phone.PipTouchHandler;
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
public final class WMShellModule_ProvidePipFactory implements Factory<Optional<Pip>> {
  private final Provider<Context> contextProvider;

  private final Provider<DisplayController> displayControllerProvider;

  private final Provider<PipAppOpsListener> pipAppOpsListenerProvider;

  private final Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider;

  private final Provider<PipBoundsState> pipBoundsStateProvider;

  private final Provider<PipMediaController> pipMediaControllerProvider;

  private final Provider<PhonePipMenuController> phonePipMenuControllerProvider;

  private final Provider<PipTaskOrganizer> pipTaskOrganizerProvider;

  private final Provider<PipTouchHandler> pipTouchHandlerProvider;

  private final Provider<PipTransitionController> pipTransitionControllerProvider;

  private final Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider;

  private final Provider<TaskStackListenerImpl> taskStackListenerProvider;

  private final Provider<Optional<OneHandedController>> oneHandedControllerProvider;

  private final Provider<ShellExecutor> mainExecutorProvider;

  public WMShellModule_ProvidePipFactory(Provider<Context> contextProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipAppOpsListener> pipAppOpsListenerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<PhonePipMenuController> phonePipMenuControllerProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PipTouchHandler> pipTouchHandlerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<Optional<OneHandedController>> oneHandedControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.displayControllerProvider = displayControllerProvider;
    this.pipAppOpsListenerProvider = pipAppOpsListenerProvider;
    this.pipBoundsAlgorithmProvider = pipBoundsAlgorithmProvider;
    this.pipBoundsStateProvider = pipBoundsStateProvider;
    this.pipMediaControllerProvider = pipMediaControllerProvider;
    this.phonePipMenuControllerProvider = phonePipMenuControllerProvider;
    this.pipTaskOrganizerProvider = pipTaskOrganizerProvider;
    this.pipTouchHandlerProvider = pipTouchHandlerProvider;
    this.pipTransitionControllerProvider = pipTransitionControllerProvider;
    this.windowManagerShellWrapperProvider = windowManagerShellWrapperProvider;
    this.taskStackListenerProvider = taskStackListenerProvider;
    this.oneHandedControllerProvider = oneHandedControllerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
  }

  @Override
  public Optional<Pip> get() {
    return providePip(contextProvider.get(), displayControllerProvider.get(), pipAppOpsListenerProvider.get(), pipBoundsAlgorithmProvider.get(), pipBoundsStateProvider.get(), pipMediaControllerProvider.get(), phonePipMenuControllerProvider.get(), pipTaskOrganizerProvider.get(), pipTouchHandlerProvider.get(), pipTransitionControllerProvider.get(), windowManagerShellWrapperProvider.get(), taskStackListenerProvider.get(), oneHandedControllerProvider.get(), mainExecutorProvider.get());
  }

  public static WMShellModule_ProvidePipFactory create(Provider<Context> contextProvider,
      Provider<DisplayController> displayControllerProvider,
      Provider<PipAppOpsListener> pipAppOpsListenerProvider,
      Provider<PipBoundsAlgorithm> pipBoundsAlgorithmProvider,
      Provider<PipBoundsState> pipBoundsStateProvider,
      Provider<PipMediaController> pipMediaControllerProvider,
      Provider<PhonePipMenuController> phonePipMenuControllerProvider,
      Provider<PipTaskOrganizer> pipTaskOrganizerProvider,
      Provider<PipTouchHandler> pipTouchHandlerProvider,
      Provider<PipTransitionController> pipTransitionControllerProvider,
      Provider<WindowManagerShellWrapper> windowManagerShellWrapperProvider,
      Provider<TaskStackListenerImpl> taskStackListenerProvider,
      Provider<Optional<OneHandedController>> oneHandedControllerProvider,
      Provider<ShellExecutor> mainExecutorProvider) {
    return new WMShellModule_ProvidePipFactory(contextProvider, displayControllerProvider, pipAppOpsListenerProvider, pipBoundsAlgorithmProvider, pipBoundsStateProvider, pipMediaControllerProvider, phonePipMenuControllerProvider, pipTaskOrganizerProvider, pipTouchHandlerProvider, pipTransitionControllerProvider, windowManagerShellWrapperProvider, taskStackListenerProvider, oneHandedControllerProvider, mainExecutorProvider);
  }

  public static Optional<Pip> providePip(Context context, DisplayController displayController,
      PipAppOpsListener pipAppOpsListener, PipBoundsAlgorithm pipBoundsAlgorithm,
      PipBoundsState pipBoundsState, PipMediaController pipMediaController,
      PhonePipMenuController phonePipMenuController, PipTaskOrganizer pipTaskOrganizer,
      PipTouchHandler pipTouchHandler, PipTransitionController pipTransitionController,
      WindowManagerShellWrapper windowManagerShellWrapper, TaskStackListenerImpl taskStackListener,
      Optional<OneHandedController> oneHandedController, ShellExecutor mainExecutor) {
    return Preconditions.checkNotNullFromProvides(WMShellModule.providePip(context, displayController, pipAppOpsListener, pipBoundsAlgorithm, pipBoundsState, pipMediaController, phonePipMenuController, pipTaskOrganizer, pipTouchHandler, pipTransitionController, windowManagerShellWrapper, taskStackListener, oneHandedController, mainExecutor));
  }
}
