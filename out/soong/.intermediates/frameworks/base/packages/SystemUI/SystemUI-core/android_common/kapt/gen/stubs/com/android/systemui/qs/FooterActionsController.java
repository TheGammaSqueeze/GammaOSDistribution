package com.android.systemui.qs;

import android.content.Intent;
import android.os.UserManager;
import android.provider.Settings;
import android.view.View;
import android.widget.Toast;
import androidx.annotation.VisibleForTesting;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.logging.nano.MetricsProto;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.R;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.globalactions.GlobalActionsDialogLite;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.phone.MultiUserSwitchController;
import com.android.systemui.statusbar.phone.SettingsButton;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.UserInfoController;
import com.android.systemui.statusbar.policy.UserInfoController.OnUserInfoChangedListener;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.ViewController;
import javax.inject.Inject;
import javax.inject.Named;

/**
 * Manages [FooterActionsView] behaviour, both when it's placed in QS or QQS (split shade).
 * Main difference between QS and QQS behaviour is condition when buttons should be visible,
 * determined by [buttonsVisibleState]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0094\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\t\n\u0002\u0010\u0007\n\u0002\b\t\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001FBy\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\u0006\u0010\u0018\u001a\u00020\u0019\u0012\b\b\u0001\u0010\u001a\u001a\u00020\u001b\u0012\u0006\u0010\u001c\u001a\u00020\u001d\u00a2\u0006\u0002\u0010\u001eJ\b\u0010/\u001a\u00020\u001bH\u0002J\u000e\u00100\u001a\u0002012\u0006\u00102\u001a\u000203J\u0006\u00104\u001a\u000201J\b\u00105\u001a\u00020\u001bH\u0002J\b\u00106\u001a\u000201H\u0014J\b\u00107\u001a\u000201H\u0017J\b\u00108\u001a\u000201H\u0014J\u000e\u00109\u001a\u0002012\u0006\u0010:\u001a\u00020\u001bJ\u000e\u0010;\u001a\u0002012\u0006\u0010<\u001a\u00020=J\u0006\u0010>\u001a\u000201J\u000e\u0010?\u001a\u0002012\u0006\u0010&\u001a\u00020\u001bJ\u0006\u0010@\u001a\u000201J\b\u0010A\u001a\u000201H\u0002J\u0016\u0010B\u001a\u0002012\u0006\u0010C\u001a\u0002032\u0006\u0010D\u001a\u000203J\b\u0010E\u001a\u000201H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010!\u001a\u00020\u001bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\"\u0010#\"\u0004\b$\u0010%R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010)\u001a\u00020*X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010+\u001a\u00020 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010,\u001a\u00020-X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010.\u001a\u0004\u0018\u00010 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/FooterActionsController;", "Lcom/android/systemui/util/ViewController;", "Lcom/android/systemui/qs/FooterActionsView;", "view", "qsPanelController", "Lcom/android/systemui/qs/QSPanelController;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "userManager", "Landroid/os/UserManager;", "userInfoController", "Lcom/android/systemui/statusbar/policy/UserInfoController;", "multiUserSwitchController", "Lcom/android/systemui/statusbar/phone/MultiUserSwitchController;", "deviceProvisionedController", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "metricsLogger", "Lcom/android/internal/logging/MetricsLogger;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "globalActionsDialog", "Lcom/android/systemui/globalactions/GlobalActionsDialogLite;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "showPMLiteButton", "", "buttonsVisibleState", "Lcom/android/systemui/qs/FooterActionsController$ExpansionState;", "(Lcom/android/systemui/qs/FooterActionsView;Lcom/android/systemui/qs/QSPanelController;Lcom/android/systemui/plugins/ActivityStarter;Landroid/os/UserManager;Lcom/android/systemui/statusbar/policy/UserInfoController;Lcom/android/systemui/statusbar/phone/MultiUserSwitchController;Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/internal/logging/MetricsLogger;Lcom/android/systemui/tuner/TunerService;Lcom/android/systemui/globalactions/GlobalActionsDialogLite;Lcom/android/internal/logging/UiEventLogger;ZLcom/android/systemui/qs/FooterActionsController$ExpansionState;)V", "editButton", "Landroid/view/View;", "expanded", "getExpanded", "()Z", "setExpanded", "(Z)V", "listening", "onClickListener", "Landroid/view/View$OnClickListener;", "onUserInfoChangedListener", "Lcom/android/systemui/statusbar/policy/UserInfoController$OnUserInfoChangedListener;", "powerMenuLite", "settingsButton", "Lcom/android/systemui/statusbar/phone/SettingsButton;", "settingsButtonContainer", "buttonsVisible", "disable", "", "state2", "", "hideFooter", "isTunerEnabled", "onInit", "onViewAttached", "onViewDetached", "refreshVisibility", "shouldBeVisible", "setExpansion", "headerExpansionFraction", "", "setKeyguardShowing", "setListening", "showFooter", "startSettingsActivity", "updateAnimator", "width", "numTiles", "updateView", "ExpansionState"})
public final class FooterActionsController extends com.android.systemui.util.ViewController<com.android.systemui.qs.FooterActionsView> {
    private boolean listening = false;
    private boolean expanded = false;
    private final com.android.systemui.statusbar.phone.SettingsButton settingsButton = null;
    private final android.view.View settingsButtonContainer = null;
    private final android.view.View editButton = null;
    private final android.view.View powerMenuLite = null;
    private final com.android.systemui.statusbar.policy.UserInfoController.OnUserInfoChangedListener onUserInfoChangedListener = null;
    private final android.view.View.OnClickListener onClickListener = null;
    private final com.android.systemui.qs.QSPanelController qsPanelController = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final android.os.UserManager userManager = null;
    private final com.android.systemui.statusbar.policy.UserInfoController userInfoController = null;
    private final com.android.systemui.statusbar.phone.MultiUserSwitchController multiUserSwitchController = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.internal.logging.MetricsLogger metricsLogger = null;
    private final com.android.systemui.tuner.TunerService tunerService = null;
    private final com.android.systemui.globalactions.GlobalActionsDialogLite globalActionsDialog = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final boolean showPMLiteButton = false;
    private final com.android.systemui.qs.FooterActionsController.ExpansionState buttonsVisibleState = null;
    
    public final boolean getExpanded() {
        return false;
    }
    
    public final void setExpanded(boolean p0) {
    }
    
    private final boolean buttonsVisible() {
        return false;
    }
    
    @java.lang.Override()
    protected void onInit() {
    }
    
    public final void hideFooter() {
    }
    
    public final void showFooter() {
    }
    
    private final void startSettingsActivity() {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Override()
    public void onViewAttached() {
    }
    
    private final void updateView() {
    }
    
    @java.lang.Override()
    protected void onViewDetached() {
    }
    
    public final void setListening(boolean listening) {
    }
    
    public final void disable(int state2) {
    }
    
    public final void setExpansion(float headerExpansionFraction) {
    }
    
    public final void updateAnimator(int width, int numTiles) {
    }
    
    public final void setKeyguardShowing() {
    }
    
    public final void refreshVisibility(boolean shouldBeVisible) {
    }
    
    private final boolean isTunerEnabled() {
        return false;
    }
    
    @javax.inject.Inject()
    public FooterActionsController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.FooterActionsView view, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSPanelController qsPanelController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    android.os.UserManager userManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.UserInfoController userInfoController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.MultiUserSwitchController multiUserSwitchController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.MetricsLogger metricsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService, @org.jetbrains.annotations.NotNull()
    com.android.systemui.globalactions.GlobalActionsDialogLite globalActionsDialog, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @javax.inject.Named(value = "pm_lite")
    boolean showPMLiteButton, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.FooterActionsController.ExpansionState buttonsVisibleState) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\b\u0003\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002j\u0002\b\u0003j\u0002\b\u0004"}, d2 = {"Lcom/android/systemui/qs/FooterActionsController$ExpansionState;", "", "(Ljava/lang/String;I)V", "COLLAPSED", "EXPANDED"})
    public static enum ExpansionState {
        /*public static final*/ COLLAPSED /* = new COLLAPSED() */,
        /*public static final*/ EXPANDED /* = new EXPANDED() */;
        
        ExpansionState() {
        }
    }
}