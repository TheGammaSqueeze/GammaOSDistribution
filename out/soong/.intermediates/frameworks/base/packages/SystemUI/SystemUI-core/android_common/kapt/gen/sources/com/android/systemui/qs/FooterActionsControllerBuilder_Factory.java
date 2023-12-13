package com.android.systemui.qs;

import android.os.UserManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.globalactions.GlobalActionsDialogLite;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.phone.MultiUserSwitchController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.UserInfoController;
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
public final class FooterActionsControllerBuilder_Factory implements Factory<FooterActionsControllerBuilder> {
  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<UserInfoController> userInfoControllerProvider;

  private final Provider<MultiUserSwitchController.Factory> multiUserSwitchControllerFactoryProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<GlobalActionsDialogLite> globalActionsDialogProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<Boolean> showPMLiteButtonProvider;

  public FooterActionsControllerBuilder_Factory(
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<UserManager> userManagerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<MultiUserSwitchController.Factory> multiUserSwitchControllerFactoryProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<Boolean> showPMLiteButtonProvider) {
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.userManagerProvider = userManagerProvider;
    this.userInfoControllerProvider = userInfoControllerProvider;
    this.multiUserSwitchControllerFactoryProvider = multiUserSwitchControllerFactoryProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.globalActionsDialogProvider = globalActionsDialogProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.showPMLiteButtonProvider = showPMLiteButtonProvider;
  }

  @Override
  public FooterActionsControllerBuilder get() {
    return newInstance(qsPanelControllerProvider.get(), activityStarterProvider.get(), userManagerProvider.get(), userInfoControllerProvider.get(), multiUserSwitchControllerFactoryProvider.get(), deviceProvisionedControllerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), tunerServiceProvider.get(), globalActionsDialogProvider.get(), uiEventLoggerProvider.get(), showPMLiteButtonProvider.get());
  }

  public static FooterActionsControllerBuilder_Factory create(
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<UserManager> userManagerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<MultiUserSwitchController.Factory> multiUserSwitchControllerFactoryProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<Boolean> showPMLiteButtonProvider) {
    return new FooterActionsControllerBuilder_Factory(qsPanelControllerProvider, activityStarterProvider, userManagerProvider, userInfoControllerProvider, multiUserSwitchControllerFactoryProvider, deviceProvisionedControllerProvider, falsingManagerProvider, metricsLoggerProvider, tunerServiceProvider, globalActionsDialogProvider, uiEventLoggerProvider, showPMLiteButtonProvider);
  }

  public static FooterActionsControllerBuilder newInstance(QSPanelController qsPanelController,
      ActivityStarter activityStarter, UserManager userManager,
      UserInfoController userInfoController,
      MultiUserSwitchController.Factory multiUserSwitchControllerFactory,
      DeviceProvisionedController deviceProvisionedController, FalsingManager falsingManager,
      MetricsLogger metricsLogger, TunerService tunerService,
      GlobalActionsDialogLite globalActionsDialog, UiEventLogger uiEventLogger,
      boolean showPMLiteButton) {
    return new FooterActionsControllerBuilder(qsPanelController, activityStarter, userManager, userInfoController, multiUserSwitchControllerFactory, deviceProvisionedController, falsingManager, metricsLogger, tunerService, globalActionsDialog, uiEventLogger, showPMLiteButton);
  }
}
