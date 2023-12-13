package com.android.systemui.statusbar.phone;

import android.view.View;
import androidx.constraintlayout.motion.widget.MotionLayout;
import com.android.systemui.R;
import com.android.systemui.animation.ShadeInterpolation;
import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.qs.HeaderPrivacyIconsController;
import com.android.systemui.qs.carrier.QSCarrierGroupController;
import com.android.systemui.statusbar.phone.dagger.StatusBarComponent.StatusBarScope;
import javax.inject.Inject;
import javax.inject.Named;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0013\n\u0002\u0010\u0002\n\u0002\b\b\b\u0007\u0018\u0000 72\u00020\u0001:\u00017B;\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\b\u0010.\u001a\u00020/H\u0002J\b\u00100\u001a\u00020/H\u0002J\b\u00101\u001a\u00020/H\u0002J\b\u00102\u001a\u00020/H\u0002J\b\u00103\u001a\u00020/H\u0002J\u0010\u00104\u001a\u00020/2\u0006\u00105\u001a\u00020\u0013H\u0002J\b\u00106\u001a\u00020/H\u0002R\u0014\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u001c\u001a\u00020\u001b2\u0006\u0010\u001a\u001a\u00020\u001b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u001e\"\u0004\b\u001f\u0010 R$\u0010!\u001a\u00020\u00132\u0006\u0010\u001a\u001a\u00020\u0013@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\"\u0010#\"\u0004\b$\u0010%R$\u0010&\u001a\u00020\u001b2\u0006\u0010\u001a\u001a\u00020\u001b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\'\u0010\u001e\"\u0004\b(\u0010 R$\u0010)\u001a\u00020\u00132\u0006\u0010\u001a\u001a\u00020\u0013@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b*\u0010#\"\u0004\b+\u0010%R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010,\u001a\u00020\u00132\u0006\u0010\u001a\u001a\u00020\u0013@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b-\u0010%"}, d2 = {"Lcom/android/systemui/statusbar/phone/SplitShadeHeaderController;", "", "statusBar", "Landroid/view/View;", "statusBarIconController", "Lcom/android/systemui/statusbar/phone/StatusBarIconController;", "privacyIconsController", "Lcom/android/systemui/qs/HeaderPrivacyIconsController;", "qsCarrierGroupControllerBuilder", "Lcom/android/systemui/qs/carrier/QSCarrierGroupController$Builder;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "batteryMeterViewController", "Lcom/android/systemui/battery/BatteryMeterViewController;", "(Landroid/view/View;Lcom/android/systemui/statusbar/phone/StatusBarIconController;Lcom/android/systemui/qs/HeaderPrivacyIconsController;Lcom/android/systemui/qs/carrier/QSCarrierGroupController$Builder;Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/battery/BatteryMeterViewController;)V", "carrierIconSlots", "", "", "combinedHeaders", "", "iconContainer", "Lcom/android/systemui/statusbar/phone/StatusIconContainer;", "iconManager", "Lcom/android/systemui/statusbar/phone/StatusBarIconController$IconManager;", "qsCarrierGroupController", "Lcom/android/systemui/qs/carrier/QSCarrierGroupController;", "value", "", "qsExpandedFraction", "getQsExpandedFraction", "()F", "setQsExpandedFraction", "(F)V", "shadeExpanded", "getShadeExpanded", "()Z", "setShadeExpanded", "(Z)V", "shadeExpandedFraction", "getShadeExpandedFraction", "setShadeExpandedFraction", "splitShadeMode", "getSplitShadeMode", "setSplitShadeMode", "visible", "setVisible", "onShadeExpandedChanged", "", "onSplitShadeModeChanged", "updateConstraints", "updateListeners", "updatePosition", "updateSingleCarrier", "singleCarrier", "updateVisibility", "Companion"})
@com.android.systemui.statusbar.phone.dagger.StatusBarComponent.StatusBarScope()
public final class SplitShadeHeaderController {
    private final java.util.List<java.lang.String> carrierIconSlots = null;
    private final boolean combinedHeaders = false;
    private final com.android.systemui.statusbar.phone.StatusBarIconController.IconManager iconManager = null;
    private final com.android.systemui.qs.carrier.QSCarrierGroupController qsCarrierGroupController = null;
    private final com.android.systemui.statusbar.phone.StatusIconContainer iconContainer = null;
    private boolean visible = false;
    private boolean shadeExpanded = false;
    private boolean splitShadeMode = false;
    private float shadeExpandedFraction = -1.0F;
    private float qsExpandedFraction = -1.0F;
    private final android.view.View statusBar = null;
    private final com.android.systemui.statusbar.phone.StatusBarIconController statusBarIconController = null;
    private final com.android.systemui.qs.HeaderPrivacyIconsController privacyIconsController = null;
    private static final int HEADER_TRANSITION_ID = 0;
    private static final int SPLIT_HEADER_TRANSITION_ID = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.phone.SplitShadeHeaderController.Companion Companion = null;
    
    private final void setVisible(boolean value) {
    }
    
    public final boolean getShadeExpanded() {
        return false;
    }
    
    public final void setShadeExpanded(boolean value) {
    }
    
    public final boolean getSplitShadeMode() {
        return false;
    }
    
    public final void setSplitShadeMode(boolean value) {
    }
    
    public final float getShadeExpandedFraction() {
        return 0.0F;
    }
    
    public final void setShadeExpandedFraction(float value) {
    }
    
    public final float getQsExpandedFraction() {
        return 0.0F;
    }
    
    public final void setQsExpandedFraction(float value) {
    }
    
    private final void onShadeExpandedChanged() {
    }
    
    private final void onSplitShadeModeChanged() {
    }
    
    private final void updateVisibility() {
    }
    
    private final void updateConstraints() {
    }
    
    private final void updatePosition() {
    }
    
    private final void updateListeners() {
    }
    
    private final void updateSingleCarrier(boolean singleCarrier) {
    }
    
    @javax.inject.Inject()
    public SplitShadeHeaderController(@org.jetbrains.annotations.NotNull()
    @javax.inject.Named(value = "split_shade_header")
    android.view.View statusBar, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarIconController statusBarIconController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.HeaderPrivacyIconsController privacyIconsController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.carrier.QSCarrierGroupController.Builder qsCarrierGroupControllerBuilder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    @javax.inject.Named(value = "split_shade_battery_controller")
    com.android.systemui.battery.BatteryMeterViewController batteryMeterViewController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/SplitShadeHeaderController$Companion;", "", "()V", "HEADER_TRANSITION_ID", "", "SPLIT_HEADER_TRANSITION_ID"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}