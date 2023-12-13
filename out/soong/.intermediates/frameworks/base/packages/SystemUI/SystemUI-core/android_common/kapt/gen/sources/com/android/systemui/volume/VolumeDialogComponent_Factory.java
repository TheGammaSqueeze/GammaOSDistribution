package com.android.systemui.volume;

import android.content.Context;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.PluginDependencyProvider;
import com.android.systemui.plugins.VolumeDialog;
import com.android.systemui.statusbar.policy.ExtensionController;
import com.android.systemui.tuner.TunerService;
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
public final class VolumeDialogComponent_Factory implements Factory<VolumeDialogComponent> {
  private final Provider<Context> contextProvider;

  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<VolumeDialogControllerImpl> volumeDialogControllerProvider;

  private final Provider<DemoModeController> demoModeControllerProvider;

  private final Provider<PluginDependencyProvider> pluginDependencyProvider;

  private final Provider<ExtensionController> extensionControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<VolumeDialog> volumeDialogProvider;

  public VolumeDialogComponent_Factory(Provider<Context> contextProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<VolumeDialogControllerImpl> volumeDialogControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<PluginDependencyProvider> pluginDependencyProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<VolumeDialog> volumeDialogProvider) {
    this.contextProvider = contextProvider;
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.volumeDialogControllerProvider = volumeDialogControllerProvider;
    this.demoModeControllerProvider = demoModeControllerProvider;
    this.pluginDependencyProvider = pluginDependencyProvider;
    this.extensionControllerProvider = extensionControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.volumeDialogProvider = volumeDialogProvider;
  }

  @Override
  public VolumeDialogComponent get() {
    return newInstance(contextProvider.get(), keyguardViewMediatorProvider.get(), activityStarterProvider.get(), volumeDialogControllerProvider.get(), demoModeControllerProvider.get(), pluginDependencyProvider.get(), extensionControllerProvider.get(), tunerServiceProvider.get(), volumeDialogProvider.get());
  }

  public static VolumeDialogComponent_Factory create(Provider<Context> contextProvider,
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<VolumeDialogControllerImpl> volumeDialogControllerProvider,
      Provider<DemoModeController> demoModeControllerProvider,
      Provider<PluginDependencyProvider> pluginDependencyProvider,
      Provider<ExtensionController> extensionControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<VolumeDialog> volumeDialogProvider) {
    return new VolumeDialogComponent_Factory(contextProvider, keyguardViewMediatorProvider, activityStarterProvider, volumeDialogControllerProvider, demoModeControllerProvider, pluginDependencyProvider, extensionControllerProvider, tunerServiceProvider, volumeDialogProvider);
  }

  public static VolumeDialogComponent newInstance(Context context,
      KeyguardViewMediator keyguardViewMediator, ActivityStarter activityStarter,
      VolumeDialogControllerImpl volumeDialogController, DemoModeController demoModeController,
      PluginDependencyProvider pluginDependencyProvider, ExtensionController extensionController,
      TunerService tunerService, VolumeDialog volumeDialog) {
    return new VolumeDialogComponent(context, keyguardViewMediator, activityStarter, volumeDialogController, demoModeController, pluginDependencyProvider, extensionController, tunerService, volumeDialog);
  }
}
