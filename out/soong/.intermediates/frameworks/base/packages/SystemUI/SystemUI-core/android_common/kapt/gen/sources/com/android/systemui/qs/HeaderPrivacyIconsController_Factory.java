package com.android.systemui.qs;

import com.android.internal.logging.UiEventLogger;
import com.android.systemui.privacy.OngoingPrivacyChip;
import com.android.systemui.privacy.PrivacyDialogController;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.statusbar.phone.StatusIconContainer;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
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
public final class HeaderPrivacyIconsController_Factory implements Factory<HeaderPrivacyIconsController> {
  private final Provider<PrivacyItemController> privacyItemControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<OngoingPrivacyChip> privacyChipProvider;

  private final Provider<PrivacyDialogController> privacyDialogControllerProvider;

  private final Provider<PrivacyLogger> privacyLoggerProvider;

  private final Provider<StatusIconContainer> iconContainerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  public HeaderPrivacyIconsController_Factory(
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<OngoingPrivacyChip> privacyChipProvider,
      Provider<PrivacyDialogController> privacyDialogControllerProvider,
      Provider<PrivacyLogger> privacyLoggerProvider,
      Provider<StatusIconContainer> iconContainerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider) {
    this.privacyItemControllerProvider = privacyItemControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.privacyChipProvider = privacyChipProvider;
    this.privacyDialogControllerProvider = privacyDialogControllerProvider;
    this.privacyLoggerProvider = privacyLoggerProvider;
    this.iconContainerProvider = iconContainerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
  }

  @Override
  public HeaderPrivacyIconsController get() {
    return newInstance(privacyItemControllerProvider.get(), uiEventLoggerProvider.get(), privacyChipProvider.get(), privacyDialogControllerProvider.get(), privacyLoggerProvider.get(), iconContainerProvider.get(), deviceProvisionedControllerProvider.get());
  }

  public static HeaderPrivacyIconsController_Factory create(
      Provider<PrivacyItemController> privacyItemControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<OngoingPrivacyChip> privacyChipProvider,
      Provider<PrivacyDialogController> privacyDialogControllerProvider,
      Provider<PrivacyLogger> privacyLoggerProvider,
      Provider<StatusIconContainer> iconContainerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider) {
    return new HeaderPrivacyIconsController_Factory(privacyItemControllerProvider, uiEventLoggerProvider, privacyChipProvider, privacyDialogControllerProvider, privacyLoggerProvider, iconContainerProvider, deviceProvisionedControllerProvider);
  }

  public static HeaderPrivacyIconsController newInstance(
      PrivacyItemController privacyItemController, UiEventLogger uiEventLogger,
      OngoingPrivacyChip privacyChip, PrivacyDialogController privacyDialogController,
      PrivacyLogger privacyLogger, StatusIconContainer iconContainer,
      DeviceProvisionedController deviceProvisionedController) {
    return new HeaderPrivacyIconsController(privacyItemController, uiEventLogger, privacyChip, privacyDialogController, privacyLogger, iconContainer, deviceProvisionedController);
  }
}
