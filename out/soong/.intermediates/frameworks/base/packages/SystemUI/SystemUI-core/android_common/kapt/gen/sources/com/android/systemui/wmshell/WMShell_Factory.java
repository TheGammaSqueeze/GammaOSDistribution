package com.android.systemui.wmshell;

import android.content.Context;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.model.SysUiState;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.tracing.ProtoTracer;
import com.android.wm.shell.ShellCommandHandler;
import com.android.wm.shell.compatui.CompatUI;
import com.android.wm.shell.draganddrop.DragAndDrop;
import com.android.wm.shell.hidedisplaycutout.HideDisplayCutout;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.onehanded.OneHanded;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.splitscreen.SplitScreen;
import dagger.internal.Factory;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class WMShell_Factory implements Factory<WMShell> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<Pip>> pipOptionalProvider;

  private final Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider;

  private final Provider<Optional<SplitScreen>> splitScreenOptionalProvider;

  private final Provider<Optional<OneHanded>> oneHandedOptionalProvider;

  private final Provider<Optional<HideDisplayCutout>> hideDisplayCutoutOptionalProvider;

  private final Provider<Optional<ShellCommandHandler>> shellCommandHandlerProvider;

  private final Provider<Optional<CompatUI>> sizeCompatUIOptionalProvider;

  private final Provider<Optional<DragAndDrop>> dragAndDropOptionalProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<SysUiState> sysUiStateProvider;

  private final Provider<ProtoTracer> protoTracerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<Executor> sysUiMainExecutorProvider;

  public WMShell_Factory(Provider<Context> contextProvider,
      Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<OneHanded>> oneHandedOptionalProvider,
      Provider<Optional<HideDisplayCutout>> hideDisplayCutoutOptionalProvider,
      Provider<Optional<ShellCommandHandler>> shellCommandHandlerProvider,
      Provider<Optional<CompatUI>> sizeCompatUIOptionalProvider,
      Provider<Optional<DragAndDrop>> dragAndDropOptionalProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider, Provider<SysUiState> sysUiStateProvider,
      Provider<ProtoTracer> protoTracerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<Executor> sysUiMainExecutorProvider) {
    this.contextProvider = contextProvider;
    this.pipOptionalProvider = pipOptionalProvider;
    this.legacySplitScreenOptionalProvider = legacySplitScreenOptionalProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
    this.oneHandedOptionalProvider = oneHandedOptionalProvider;
    this.hideDisplayCutoutOptionalProvider = hideDisplayCutoutOptionalProvider;
    this.shellCommandHandlerProvider = shellCommandHandlerProvider;
    this.sizeCompatUIOptionalProvider = sizeCompatUIOptionalProvider;
    this.dragAndDropOptionalProvider = dragAndDropOptionalProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.sysUiStateProvider = sysUiStateProvider;
    this.protoTracerProvider = protoTracerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.sysUiMainExecutorProvider = sysUiMainExecutorProvider;
  }

  @Override
  public WMShell get() {
    return newInstance(contextProvider.get(), pipOptionalProvider.get(), legacySplitScreenOptionalProvider.get(), splitScreenOptionalProvider.get(), oneHandedOptionalProvider.get(), hideDisplayCutoutOptionalProvider.get(), shellCommandHandlerProvider.get(), sizeCompatUIOptionalProvider.get(), dragAndDropOptionalProvider.get(), commandQueueProvider.get(), configurationControllerProvider.get(), keyguardUpdateMonitorProvider.get(), navigationModeControllerProvider.get(), screenLifecycleProvider.get(), sysUiStateProvider.get(), protoTracerProvider.get(), wakefulnessLifecycleProvider.get(), sysUiMainExecutorProvider.get());
  }

  public static WMShell_Factory create(Provider<Context> contextProvider,
      Provider<Optional<Pip>> pipOptionalProvider,
      Provider<Optional<LegacySplitScreen>> legacySplitScreenOptionalProvider,
      Provider<Optional<SplitScreen>> splitScreenOptionalProvider,
      Provider<Optional<OneHanded>> oneHandedOptionalProvider,
      Provider<Optional<HideDisplayCutout>> hideDisplayCutoutOptionalProvider,
      Provider<Optional<ShellCommandHandler>> shellCommandHandlerProvider,
      Provider<Optional<CompatUI>> sizeCompatUIOptionalProvider,
      Provider<Optional<DragAndDrop>> dragAndDropOptionalProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<ScreenLifecycle> screenLifecycleProvider, Provider<SysUiState> sysUiStateProvider,
      Provider<ProtoTracer> protoTracerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<Executor> sysUiMainExecutorProvider) {
    return new WMShell_Factory(contextProvider, pipOptionalProvider, legacySplitScreenOptionalProvider, splitScreenOptionalProvider, oneHandedOptionalProvider, hideDisplayCutoutOptionalProvider, shellCommandHandlerProvider, sizeCompatUIOptionalProvider, dragAndDropOptionalProvider, commandQueueProvider, configurationControllerProvider, keyguardUpdateMonitorProvider, navigationModeControllerProvider, screenLifecycleProvider, sysUiStateProvider, protoTracerProvider, wakefulnessLifecycleProvider, sysUiMainExecutorProvider);
  }

  public static WMShell newInstance(Context context, Optional<Pip> pipOptional,
      Optional<LegacySplitScreen> legacySplitScreenOptional,
      Optional<SplitScreen> splitScreenOptional, Optional<OneHanded> oneHandedOptional,
      Optional<HideDisplayCutout> hideDisplayCutoutOptional,
      Optional<ShellCommandHandler> shellCommandHandler, Optional<CompatUI> sizeCompatUIOptional,
      Optional<DragAndDrop> dragAndDropOptional, CommandQueue commandQueue,
      ConfigurationController configurationController, KeyguardUpdateMonitor keyguardUpdateMonitor,
      NavigationModeController navigationModeController, ScreenLifecycle screenLifecycle,
      SysUiState sysUiState, ProtoTracer protoTracer, WakefulnessLifecycle wakefulnessLifecycle,
      Executor sysUiMainExecutor) {
    return new WMShell(context, pipOptional, legacySplitScreenOptional, splitScreenOptional, oneHandedOptional, hideDisplayCutoutOptional, shellCommandHandler, sizeCompatUIOptional, dragAndDropOptional, commandQueue, configurationController, keyguardUpdateMonitor, navigationModeController, screenLifecycle, sysUiState, protoTracer, wakefulnessLifecycle, sysUiMainExecutor);
  }
}
