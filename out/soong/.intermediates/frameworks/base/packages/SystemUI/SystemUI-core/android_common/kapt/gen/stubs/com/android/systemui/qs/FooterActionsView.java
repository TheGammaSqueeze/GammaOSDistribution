package com.android.systemui.qs;

import android.app.StatusBarManager;
import android.content.Context;
import android.content.res.Configuration;
import android.graphics.PorterDuff;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.RippleDrawable;
import android.os.UserManager;
import android.util.AttributeSet;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import com.android.settingslib.Utils;
import com.android.settingslib.drawable.UserIconDrawable;
import com.android.systemui.R;
import com.android.systemui.statusbar.phone.MultiUserSwitch;
import com.android.systemui.statusbar.phone.SettingsButton;

/**
 * Quick Settings bottom buttons placed in footer (aka utility bar) - always visible in expanded QS,
 * in split shade mode visible also in collapsed state. May contain up to 5 buttons: settings,
 * edit tiles, power off and conditionally: user switch and tuner
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u000b\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u001e\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u00102\u0006\u0010\u001c\u001a\u00020\u0010J\u0010\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u001fH\u0014J\b\u0010 \u001a\u00020\u0018H\u0014J\u0010\u0010!\u001a\u00020\u00182\u0006\u0010\"\u001a\u00020\u001aH\u0016J\u0018\u0010#\u001a\u00020\u00182\b\u0010$\u001a\u0004\u0018\u00010%2\u0006\u0010&\u001a\u00020\u0010J\u000e\u0010\'\u001a\u00020\u00182\u0006\u0010(\u001a\u00020\nJ\u0006\u0010)\u001a\u00020\u0018J\u0016\u0010*\u001a\u00020\u00182\u0006\u0010+\u001a\u00020\u001a2\u0006\u0010,\u001a\u00020\u001aJ\b\u0010-\u001a\u00020\u0018H\u0002J\u0016\u0010.\u001a\u00020\u00182\u0006\u0010\u001b\u001a\u00020\u00102\u0006\u0010\u001c\u001a\u00020\u0010J\b\u0010/\u001a\u00020\u0018H\u0002J\u0018\u00100\u001a\u00020\u00182\u0006\u0010\u001b\u001a\u00020\u00102\u0006\u0010\u001c\u001a\u00020\u0010H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/FooterActionsView;", "Landroid/widget/LinearLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "editTilesButton", "Landroid/view/View;", "expansionAmount", "", "multiUserAvatar", "Landroid/widget/ImageView;", "multiUserSwitch", "Lcom/android/systemui/statusbar/phone/MultiUserSwitch;", "qsDisabled", "", "settingsButton", "Lcom/android/systemui/statusbar/phone/SettingsButton;", "settingsCogAnimator", "Lcom/android/systemui/qs/TouchAnimator;", "settingsContainer", "tunerIcon", "disable", "", "state2", "", "isTunerEnabled", "multiUserEnabled", "onConfigurationChanged", "newConfig", "Landroid/content/res/Configuration;", "onFinishInflate", "onRtlPropertiesChanged", "layoutDirection", "onUserInfoChanged", "picture", "Landroid/graphics/drawable/Drawable;", "isGuestUser", "setExpansion", "headerExpansionFraction", "setKeyguardShowing", "updateAnimator", "width", "numTiles", "updateClickabilities", "updateEverything", "updateResources", "updateVisibilities"})
public final class FooterActionsView extends android.widget.LinearLayout {
    private android.view.View settingsContainer;
    private com.android.systemui.statusbar.phone.SettingsButton settingsButton;
    private com.android.systemui.statusbar.phone.MultiUserSwitch multiUserSwitch;
    private android.widget.ImageView multiUserAvatar;
    private android.view.View tunerIcon;
    private android.view.View editTilesButton;
    private com.android.systemui.qs.TouchAnimator settingsCogAnimator;
    private boolean qsDisabled = false;
    private float expansionAmount = 0.0F;
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    public final void updateAnimator(int width, int numTiles) {
    }
    
    @java.lang.Override()
    protected void onConfigurationChanged(@org.jetbrains.annotations.NotNull()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    public void onRtlPropertiesChanged(int layoutDirection) {
    }
    
    private final void updateResources() {
    }
    
    public final void setKeyguardShowing() {
    }
    
    public final void setExpansion(float headerExpansionFraction) {
    }
    
    public final void disable(int state2, boolean isTunerEnabled, boolean multiUserEnabled) {
    }
    
    public final void updateEverything(boolean isTunerEnabled, boolean multiUserEnabled) {
    }
    
    private final void updateClickabilities() {
    }
    
    private final void updateVisibilities(boolean isTunerEnabled, boolean multiUserEnabled) {
    }
    
    public final void onUserInfoChanged(@org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Drawable picture, boolean isGuestUser) {
    }
    
    public FooterActionsView(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
}