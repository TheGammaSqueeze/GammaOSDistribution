package com.android.systemui.statusbar.phone;

import android.view.WindowInsets;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.plugins.qs.QS;
import com.android.systemui.plugins.qs.QSContainerController;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.recents.OverviewProxyService.OverviewProxyListener;
import com.android.systemui.shared.system.QuickStepContract;
import com.android.systemui.util.ViewController;
import java.util.function.Consumer;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u000e\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\b\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003B\u001f\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0002\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u0014\u0010\"\u001a\u000e\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u000b0#H\u0002J\b\u0010$\u001a\u00020%H\u0014J\b\u0010&\u001a\u00020%H\u0016J\b\u0010\'\u001a\u00020%H\u0014J\u0010\u0010(\u001a\u00020%2\u0006\u0010)\u001a\u00020\u000eH\u0016J\u0010\u0010*\u001a\u00020%2\u0006\u0010+\u001a\u00020\u000eH\u0016J\u0010\u0010,\u001a\u00020%2\u0006\u0010+\u001a\u00020\u000eH\u0016J\b\u0010-\u001a\u00020%H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u0014\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u000e@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018R$\u0010\u0019\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u000e@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001a\u0010\u0016\"\u0004\b\u001b\u0010\u0018R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020!0 X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/NotificationsQSContainerController;", "Lcom/android/systemui/util/ViewController;", "Lcom/android/systemui/statusbar/phone/NotificationsQuickSettingsContainer;", "Lcom/android/systemui/plugins/qs/QSContainerController;", "view", "navigationModeController", "Lcom/android/systemui/navigationbar/NavigationModeController;", "overviewProxyService", "Lcom/android/systemui/recents/OverviewProxyService;", "(Lcom/android/systemui/statusbar/phone/NotificationsQuickSettingsContainer;Lcom/android/systemui/navigationbar/NavigationModeController;Lcom/android/systemui/recents/OverviewProxyService;)V", "bottomCutoutInsets", "", "bottomStableInsets", "isGestureNavigation", "", "isQSCustomizerAnimating", "isQSCustomizing", "isQSDetailShowing", "notificationsBottomMargin", "value", "qsExpanded", "getQsExpanded", "()Z", "setQsExpanded", "(Z)V", "splitShadeEnabled", "getSplitShadeEnabled", "setSplitShadeEnabled", "taskbarVisibilityListener", "Lcom/android/systemui/recents/OverviewProxyService$OverviewProxyListener;", "taskbarVisible", "windowInsetsListener", "Ljava/util/function/Consumer;", "Landroid/view/WindowInsets;", "calculateBottomSpacing", "Lkotlin/Pair;", "onInit", "", "onViewAttached", "onViewDetached", "setCustomizerAnimating", "animating", "setCustomizerShowing", "showing", "setDetailShowing", "updateBottomSpacing"})
public final class NotificationsQSContainerController extends com.android.systemui.util.ViewController<com.android.systemui.statusbar.phone.NotificationsQuickSettingsContainer> implements com.android.systemui.plugins.qs.QSContainerController {
    private boolean qsExpanded = false;
    private boolean splitShadeEnabled = false;
    private boolean isQSDetailShowing = false;
    private boolean isQSCustomizing = false;
    private boolean isQSCustomizerAnimating = false;
    private int notificationsBottomMargin = 0;
    private int bottomStableInsets = 0;
    private int bottomCutoutInsets = 0;
    private boolean isGestureNavigation = true;
    private boolean taskbarVisible = false;
    private final com.android.systemui.recents.OverviewProxyService.OverviewProxyListener taskbarVisibilityListener = null;
    private final java.util.function.Consumer<android.view.WindowInsets> windowInsetsListener = null;
    private final com.android.systemui.navigationbar.NavigationModeController navigationModeController = null;
    private final com.android.systemui.recents.OverviewProxyService overviewProxyService = null;
    
    public final boolean getQsExpanded() {
        return false;
    }
    
    public final void setQsExpanded(boolean value) {
    }
    
    public final boolean getSplitShadeEnabled() {
        return false;
    }
    
    public final void setSplitShadeEnabled(boolean value) {
    }
    
    @java.lang.Override()
    protected void onInit() {
    }
    
    @java.lang.Override()
    public void onViewAttached() {
    }
    
    @java.lang.Override()
    protected void onViewDetached() {
    }
    
    @java.lang.Override()
    public void setCustomizerAnimating(boolean animating) {
    }
    
    @java.lang.Override()
    public void setCustomizerShowing(boolean showing) {
    }
    
    @java.lang.Override()
    public void setDetailShowing(boolean showing) {
    }
    
    private final void updateBottomSpacing() {
    }
    
    private final kotlin.Pair<java.lang.Integer, java.lang.Integer> calculateBottomSpacing() {
        return null;
    }
    
    @javax.inject.Inject()
    public NotificationsQSContainerController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationsQuickSettingsContainer view, @org.jetbrains.annotations.NotNull()
    com.android.systemui.navigationbar.NavigationModeController navigationModeController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.recents.OverviewProxyService overviewProxyService) {
        super(null);
    }
}