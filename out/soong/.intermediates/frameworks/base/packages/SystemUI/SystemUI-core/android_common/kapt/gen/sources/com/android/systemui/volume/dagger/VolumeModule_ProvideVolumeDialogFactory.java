package com.android.systemui.volume.dagger;

import android.content.Context;
import com.android.systemui.media.dialog.MediaOutputDialogFactory;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.VolumeDialog;
import com.android.systemui.plugins.VolumeDialogController;
import com.android.systemui.statusbar.policy.AccessibilityManagerWrapper;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.tuner.TunerService;
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
public final class VolumeModule_ProvideVolumeDialogFactory implements Factory<VolumeDialog> {
  private final Provider<Context> contextProvider;

  private final Provider<VolumeDialogController> volumeDialogControllerProvider;

  private final Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<TunerService> tunerServiceProvider;

  public VolumeModule_ProvideVolumeDialogFactory(Provider<Context> contextProvider,
      Provider<VolumeDialogController> volumeDialogControllerProvider,
      Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<TunerService> tunerServiceProvider) {
    this.contextProvider = contextProvider;
    this.volumeDialogControllerProvider = volumeDialogControllerProvider;
    this.accessibilityManagerWrapperProvider = accessibilityManagerWrapperProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.mediaOutputDialogFactoryProvider = mediaOutputDialogFactoryProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.tunerServiceProvider = tunerServiceProvider;
  }

  @Override
  public VolumeDialog get() {
    return provideVolumeDialog(contextProvider.get(), volumeDialogControllerProvider.get(), accessibilityManagerWrapperProvider.get(), deviceProvisionedControllerProvider.get(), configurationControllerProvider.get(), mediaOutputDialogFactoryProvider.get(), activityStarterProvider.get(), tunerServiceProvider.get());
  }

  public static VolumeModule_ProvideVolumeDialogFactory create(Provider<Context> contextProvider,
      Provider<VolumeDialogController> volumeDialogControllerProvider,
      Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<TunerService> tunerServiceProvider) {
    return new VolumeModule_ProvideVolumeDialogFactory(contextProvider, volumeDialogControllerProvider, accessibilityManagerWrapperProvider, deviceProvisionedControllerProvider, configurationControllerProvider, mediaOutputDialogFactoryProvider, activityStarterProvider, tunerServiceProvider);
  }

  public static VolumeDialog provideVolumeDialog(Context context,
      VolumeDialogController volumeDialogController,
      AccessibilityManagerWrapper accessibilityManagerWrapper,
      DeviceProvisionedController deviceProvisionedController,
      ConfigurationController configurationController,
      MediaOutputDialogFactory mediaOutputDialogFactory, ActivityStarter activityStarter,
      TunerService tunerService) {
    return Preconditions.checkNotNullFromProvides(VolumeModule.provideVolumeDialog(context, volumeDialogController, accessibilityManagerWrapper, deviceProvisionedController, configurationController, mediaOutputDialogFactory, activityStarter, tunerService));
  }
}
