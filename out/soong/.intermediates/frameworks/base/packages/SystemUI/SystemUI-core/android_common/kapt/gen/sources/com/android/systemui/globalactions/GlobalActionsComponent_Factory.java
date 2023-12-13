package com.android.systemui.globalactions;

import android.content.Context;
import com.android.systemui.plugins.GlobalActions;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager;
import com.android.systemui.statusbar.policy.ExtensionController;
import dagger.internal.Factory;
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
public final class GlobalActionsComponent_Factory implements Factory<GlobalActionsComponent> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ExtensionController> extensionControllerProvider;

  private final Provider<GlobalActions> globalActionsProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  public GlobalActionsComponent_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<GlobalActions> globalActionsProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.extensionControllerProvider = extensionControllerProvider;
    this.globalActionsProvider = globalActionsProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
  }

  @Override
  public GlobalActionsComponent get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), extensionControllerProvider.get(), globalActionsProvider, statusBarKeyguardViewManagerProvider.get());
  }

  public static GlobalActionsComponent_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<GlobalActions> globalActionsProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider) {
    return new GlobalActionsComponent_Factory(contextProvider, commandQueueProvider, extensionControllerProvider, globalActionsProvider, statusBarKeyguardViewManagerProvider);
  }

  public static GlobalActionsComponent newInstance(Context context, CommandQueue commandQueue,
      ExtensionController extensionController, Provider<GlobalActions> globalActionsProvider,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager) {
    return new GlobalActionsComponent(context, commandQueue, extensionController, globalActionsProvider, statusBarKeyguardViewManager);
  }
}
