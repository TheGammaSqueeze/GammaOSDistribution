package com.android.systemui.globalactions;

import android.content.Context;
import com.android.systemui.statusbar.BlurUtils;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class GlobalActionsImpl_Factory implements Factory<GlobalActionsImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<GlobalActionsDialogLite> globalActionsDialogLazyProvider;

  private final Provider<BlurUtils> blurUtilsProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  public GlobalActionsImpl_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogLazyProvider,
      Provider<BlurUtils> blurUtilsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.globalActionsDialogLazyProvider = globalActionsDialogLazyProvider;
    this.blurUtilsProvider = blurUtilsProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
  }

  @Override
  public GlobalActionsImpl get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), DoubleCheck.lazy(globalActionsDialogLazyProvider), blurUtilsProvider.get(), keyguardStateControllerProvider.get(), deviceProvisionedControllerProvider.get());
  }

  public static GlobalActionsImpl_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogLazyProvider,
      Provider<BlurUtils> blurUtilsProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider) {
    return new GlobalActionsImpl_Factory(contextProvider, commandQueueProvider, globalActionsDialogLazyProvider, blurUtilsProvider, keyguardStateControllerProvider, deviceProvisionedControllerProvider);
  }

  public static GlobalActionsImpl newInstance(Context context, CommandQueue commandQueue,
      Lazy<GlobalActionsDialogLite> globalActionsDialogLazy, BlurUtils blurUtils,
      KeyguardStateController keyguardStateController,
      DeviceProvisionedController deviceProvisionedController) {
    return new GlobalActionsImpl(context, commandQueue, globalActionsDialogLazy, blurUtils, keyguardStateController, deviceProvisionedController);
  }
}
