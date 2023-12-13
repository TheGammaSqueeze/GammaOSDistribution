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
public final class FooterActionsController_Factory implements Factory<FooterActionsController> {
  private final Provider<FooterActionsView> viewProvider;

  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<UserInfoController> userInfoControllerProvider;

  private final Provider<MultiUserSwitchController> multiUserSwitchControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<GlobalActionsDialogLite> globalActionsDialogProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<Boolean> showPMLiteButtonProvider;

  private final Provider<FooterActionsController.ExpansionState> buttonsVisibleStateProvider;

  public FooterActionsController_Factory(Provider<FooterActionsView> viewProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<UserManager> userManagerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<MultiUserSwitchController> multiUserSwitchControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<Boolean> showPMLiteButtonProvider,
      Provider<FooterActionsController.ExpansionState> buttonsVisibleStateProvider) {
    this.viewProvider = viewProvider;
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.userManagerProvider = userManagerProvider;
    this.userInfoControllerProvider = userInfoControllerProvider;
    this.multiUserSwitchControllerProvider = multiUserSwitchControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.globalActionsDialogProvider = globalActionsDialogProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.showPMLiteButtonProvider = showPMLiteButtonProvider;
    this.buttonsVisibleStateProvider = buttonsVisibleStateProvider;
  }

  @Override
  public FooterActionsController get() {
    return newInstance(viewProvider.get(), qsPanelControllerProvider.get(), activityStarterProvider.get(), userManagerProvider.get(), userInfoControllerProvider.get(), multiUserSwitchControllerProvider.get(), deviceProvisionedControllerProvider.get(), falsingManagerProvider.get(), metricsLoggerProvider.get(), tunerServiceProvider.get(), globalActionsDialogProvider.get(), uiEventLoggerProvider.get(), showPMLiteButtonProvider.get(), buttonsVisibleStateProvider.get());
  }

  public static FooterActionsController_Factory create(Provider<FooterActionsView> viewProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<UserManager> userManagerProvider,
      Provider<UserInfoController> userInfoControllerProvider,
      Provider<MultiUserSwitchController> multiUserSwitchControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<TunerService> tunerServiceProvider,
      Provider<GlobalActionsDialogLite> globalActionsDialogProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<Boolean> showPMLiteButtonProvider,
      Provider<FooterActionsController.ExpansionState> buttonsVisibleStateProvider) {
    return new FooterActionsController_Factory(viewProvider, qsPanelControllerProvider, activityStarterProvider, userManagerProvider, userInfoControllerProvider, multiUserSwitchControllerProvider, deviceProvisionedControllerProvider, falsingManagerProvider, metricsLoggerProvider, tunerServiceProvider, globalActionsDialogProvider, uiEventLoggerProvider, showPMLiteButtonProvider, buttonsVisibleStateProvider);
  }

  public static FooterActionsController newInstance(FooterActionsView view,
      QSPanelController qsPanelController, ActivityStarter activityStarter, UserManager userManager,
      UserInfoController userInfoController, MultiUserSwitchController multiUserSwitchController,
      DeviceProvisionedController deviceProvisionedController, FalsingManager falsingManager,
      MetricsLogger metricsLogger, TunerService tunerService,
      GlobalActionsDialogLite globalActionsDialog, UiEventLogger uiEventLogger,
      boolean showPMLiteButton, FooterActionsController.ExpansionState buttonsVisibleState) {
    return new FooterActionsController(view, qsPanelController, activityStarter, userManager, userInfoController, multiUserSwitchController, deviceProvisionedController, falsingManager, metricsLogger, tunerService, globalActionsDialog, uiEventLogger, showPMLiteButton, buttonsVisibleState);
  }
}
