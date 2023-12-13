package com.android.systemui.qs;

import android.os.UserManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.globalactions.GlobalActionsDialogLite;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.FooterActionsController.ExpansionState;
import com.android.systemui.qs.dagger.QSFlagsModule;
import com.android.systemui.statusbar.phone.MultiUserSwitchController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.UserInfoController;
import com.android.systemui.tuner.TunerService;
import javax.inject.Inject;
import javax.inject.Named;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000h\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001Bi\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\b\b\u0001\u0010\u0018\u001a\u00020\u0019\u00a2\u0006\u0002\u0010\u001aJ\u0006\u0010\u001f\u001a\u00020 J\u000e\u0010!\u001a\u00020\u00002\u0006\u0010\"\u001a\u00020\u001cJ\u000e\u0010#\u001a\u00020\u00002\u0006\u0010\u001d\u001a\u00020\u001eR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/FooterActionsControllerBuilder;", "", "qsPanelController", "Lcom/android/systemui/qs/QSPanelController;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "userManager", "Landroid/os/UserManager;", "userInfoController", "Lcom/android/systemui/statusbar/policy/UserInfoController;", "multiUserSwitchControllerFactory", "Lcom/android/systemui/statusbar/phone/MultiUserSwitchController$Factory;", "deviceProvisionedController", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "metricsLogger", "Lcom/android/internal/logging/MetricsLogger;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "globalActionsDialog", "Lcom/android/systemui/globalactions/GlobalActionsDialogLite;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "showPMLiteButton", "", "(Lcom/android/systemui/qs/QSPanelController;Lcom/android/systemui/plugins/ActivityStarter;Landroid/os/UserManager;Lcom/android/systemui/statusbar/policy/UserInfoController;Lcom/android/systemui/statusbar/phone/MultiUserSwitchController$Factory;Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/internal/logging/MetricsLogger;Lcom/android/systemui/tuner/TunerService;Lcom/android/systemui/globalactions/GlobalActionsDialogLite;Lcom/android/internal/logging/UiEventLogger;Z)V", "buttonsVisibleState", "Lcom/android/systemui/qs/FooterActionsController$ExpansionState;", "view", "Lcom/android/systemui/qs/FooterActionsView;", "build", "Lcom/android/systemui/qs/FooterActionsController;", "withButtonsVisibleWhen", "state", "withView"})
public final class FooterActionsControllerBuilder {
    private com.android.systemui.qs.FooterActionsView view;
    private com.android.systemui.qs.FooterActionsController.ExpansionState buttonsVisibleState;
    private final com.android.systemui.qs.QSPanelController qsPanelController = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final android.os.UserManager userManager = null;
    private final com.android.systemui.statusbar.policy.UserInfoController userInfoController = null;
    private final com.android.systemui.statusbar.phone.MultiUserSwitchController.Factory multiUserSwitchControllerFactory = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.internal.logging.MetricsLogger metricsLogger = null;
    private final com.android.systemui.tuner.TunerService tunerService = null;
    private final com.android.systemui.globalactions.GlobalActionsDialogLite globalActionsDialog = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final boolean showPMLiteButton = false;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.qs.FooterActionsControllerBuilder withView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.FooterActionsView view) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.qs.FooterActionsControllerBuilder withButtonsVisibleWhen(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.FooterActionsController.ExpansionState state) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.qs.FooterActionsController build() {
        return null;
    }
    
    @javax.inject.Inject()
    public FooterActionsControllerBuilder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSPanelController qsPanelController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    android.os.UserManager userManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.UserInfoController userInfoController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.MultiUserSwitchController.Factory multiUserSwitchControllerFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.MetricsLogger metricsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService, @org.jetbrains.annotations.NotNull()
    com.android.systemui.globalactions.GlobalActionsDialogLite globalActionsDialog, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @javax.inject.Named(value = "pm_lite")
    boolean showPMLiteButton) {
        super();
    }
}