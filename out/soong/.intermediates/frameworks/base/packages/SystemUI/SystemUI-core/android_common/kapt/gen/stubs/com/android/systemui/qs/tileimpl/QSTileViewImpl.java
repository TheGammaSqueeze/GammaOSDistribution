package com.android.systemui.qs.tileimpl;

import android.animation.ArgbEvaluator;
import android.animation.PropertyValuesHolder;
import android.animation.ValueAnimator;
import android.content.Context;
import android.content.res.ColorStateList;
import android.content.res.Configuration;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.RippleDrawable;
import android.service.quicksettings.Tile;
import android.text.TextUtils;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityEvent;
import android.view.accessibility.AccessibilityNodeInfo;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;
import androidx.annotation.VisibleForTesting;
import com.android.settingslib.Utils;
import com.android.systemui.FontSizeUtils;
import com.android.systemui.R;
import com.android.systemui.animation.LaunchableView;
import com.android.systemui.plugins.qs.QSIconView;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.plugins.qs.QSTile.BooleanState;
import com.android.systemui.plugins.qs.QSTileView;
import java.util.Objects;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00c0\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0010\u0015\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0010\u0007\n\u0002\b\t\n\u0002\u0010\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u001f\b\u0016\u0018\u0000 \u008d\u00012\u00020\u00012\u00020\u00022\u00020\u0003:\u0002\u008d\u0001B!\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010J\u001a\u00020\tH\u0014J\b\u0010K\u001a\u00020LH\u0002J\b\u0010M\u001a\u00020LH\u0002J\u0006\u0010N\u001a\u00020\u0013J\u0010\u0010O\u001a\u00020\u00112\u0006\u0010P\u001a\u00020\u0011H\u0002J\u0010\u0010Q\u001a\u00020\u00112\u0006\u0010P\u001a\u00020\u0011H\u0002J\b\u0010R\u001a\u00020\u0011H\u0016J\b\u0010S\u001a\u00020\u0007H\u0016J\b\u0010T\u001a\u00020UH\u0016J\u0010\u0010V\u001a\u00020\u00112\u0006\u0010P\u001a\u00020\u0011H\u0002J\b\u0010W\u001a\u00020UH\u0016J\b\u0010X\u001a\u00020UH\u0016J\b\u00101\u001a\u00020UH\u0016J\u0010\u0010Y\u001a\u00020\u00112\u0006\u0010P\u001a\u00020\u0011H\u0002J\u0010\u0010Z\u001a\u00020\f2\u0006\u0010P\u001a\u00020[H\u0002J\u0010\u0010\\\u001a\u00020L2\u0006\u0010P\u001a\u00020[H\u0014J\b\u0010]\u001a\u00020\tH\u0016J\u001c\u0010^\u001a\u00020L2\b\u0010_\u001a\u0004\u0018\u00010`2\b\u0010a\u001a\u0004\u0018\u00010bH\u0002J\u0010\u0010^\u001a\u00020L2\u0006\u0010c\u001a\u00020dH\u0016J\u0010\u0010e\u001a\u00020L2\u0006\u0010P\u001a\u00020[H\u0002J\u0012\u0010f\u001a\u00020L2\b\u0010g\u001a\u0004\u0018\u00010hH\u0014J\u0010\u0010i\u001a\u00020L2\u0006\u0010j\u001a\u00020kH\u0016J\u0010\u0010l\u001a\u00020L2\u0006\u0010m\u001a\u00020nH\u0016J0\u0010o\u001a\u00020L2\u0006\u0010p\u001a\u00020\t2\u0006\u0010q\u001a\u00020\u00112\u0006\u0010r\u001a\u00020\u00112\u0006\u0010s\u001a\u00020\u00112\u0006\u0010t\u001a\u00020\u0011H\u0014J\u0010\u0010u\u001a\u00020L2\u0006\u0010P\u001a\u00020[H\u0016J\b\u0010v\u001a\u00020LH\u0016J(\u0010w\u001a\u00020L2\u0006\u0010x\u001a\u00020\u00112\u0006\u0010y\u001a\u00020\u00112\u0006\u0010z\u001a\u00020\u00112\u0006\u0010{\u001a\u00020\u0011H\u0002J\u0010\u0010|\u001a\u00020L2\u0006\u0010}\u001a\u00020\u0011H\u0002J\u0010\u0010~\u001a\u00020L2\u0006\u0010\u007f\u001a\u00020\tH\u0016J\u0011\u0010\u0080\u0001\u001a\u00020L2\u0006\u0010}\u001a\u00020\u0011H\u0002J\u0011\u0010\u0081\u0001\u001a\u00020L2\u0006\u0010}\u001a\u00020\u0011H\u0002J\u0011\u0010\u0082\u0001\u001a\u00020L2\u0006\u0010}\u001a\u00020\u0011H\u0002J\u0012\u0010\u0083\u0001\u001a\u00020L2\u0007\u0010\u0084\u0001\u001a\u00020\tH\u0016J\u0012\u0010\u0085\u0001\u001a\u00020L2\u0007\u0010\u0086\u0001\u001a\u00020\u0011H\u0016J\u0012\u0010\u0087\u0001\u001a\u00020L2\u0007\u0010\u0086\u0001\u001a\u00020\u0011H\u0016J\t\u0010\u0088\u0001\u001a\u00020\fH\u0016J\u0014\u0010\u0089\u0001\u001a\u00020U2\t\u0010\u008a\u0001\u001a\u0004\u0018\u00010UH\u0016J\t\u0010\u008b\u0001\u001a\u00020LH\u0002J\u0007\u0010\u008c\u0001\u001a\u00020LR\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u000fX\u0082.\u00a2\u0006\u0002\n\u0000R$\u0010\u001e\u001a\u00020\u00112\u0006\u0010\u001d\u001a\u00020\u0011@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001f\u0010 \"\u0004\b!\u0010\"R\u000e\u0010#\u001a\u00020$X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020&X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010(\u001a\u0004\u0018\u00010)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010+\u001a\u00020,X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010-\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010.\u001a\u00020/X\u0082.\u00a2\u0006\u0002\n\u0000R\u001a\u00100\u001a\u00020$X\u0084.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b1\u00102\"\u0004\b3\u00104R\u001a\u00105\u001a\u00020\tX\u0084\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b6\u00107\"\u0004\b8\u00109R\u001a\u0010:\u001a\u00020;X\u0084.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b<\u0010=\"\u0004\b>\u0010?R\u000e\u0010@\u001a\u00020AX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010C\u001a\u00020B2\u0006\u0010\u001d\u001a\u00020B@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bD\u0010E\"\u0004\bF\u0010GR\u0010\u0010H\u001a\u0004\u0018\u00010)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010I\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tileimpl/QSTileViewImpl;", "Lcom/android/systemui/plugins/qs/QSTileView;", "Lcom/android/systemui/qs/tileimpl/HeightOverrideable;", "Lcom/android/systemui/animation/LaunchableView;", "context", "Landroid/content/Context;", "_icon", "Lcom/android/systemui/plugins/qs/QSIconView;", "collapsed", "", "(Landroid/content/Context;Lcom/android/systemui/plugins/qs/QSIconView;Z)V", "accessibilityClass", "", "blockVisibilityChanges", "chevronView", "Landroid/widget/ImageView;", "colorActive", "", "colorBackgroundDrawable", "Landroid/graphics/drawable/Drawable;", "colorInactive", "colorLabelActive", "colorLabelInactive", "colorLabelUnavailable", "colorSecondaryLabelActive", "colorSecondaryLabelInactive", "colorSecondaryLabelUnavailable", "colorUnavailable", "customDrawableView", "value", "heightOverride", "getHeightOverride", "()I", "setHeightOverride", "(I)V", "label", "Landroid/widget/TextView;", "labelContainer", "Lcom/android/systemui/qs/tileimpl/IgnorableChildLinearLayout;", "lastState", "lastStateDescription", "", "lastVisibility", "locInScreen", "", "paintColor", "ripple", "Landroid/graphics/drawable/RippleDrawable;", "secondaryLabel", "getSecondaryLabel", "()Landroid/widget/TextView;", "setSecondaryLabel", "(Landroid/widget/TextView;)V", "showRippleEffect", "getShowRippleEffect", "()Z", "setShowRippleEffect", "(Z)V", "sideView", "Landroid/view/ViewGroup;", "getSideView", "()Landroid/view/ViewGroup;", "setSideView", "(Landroid/view/ViewGroup;)V", "singleAnimator", "Landroid/animation/ValueAnimator;", "", "squishinessFraction", "getSquishinessFraction", "()F", "setSquishinessFraction", "(F)V", "stateDescriptionDeltas", "tileState", "animationsEnabled", "createAndAddLabels", "", "createAndAddSideView", "createTileBackground", "getBackgroundColorForState", "state", "getChevronColorForState", "getDetailY", "getIcon", "getIconWithBackground", "Landroid/view/View;", "getLabelColorForState", "getLabelContainer", "getSecondaryIcon", "getSecondaryLabelColorForState", "getStateText", "Lcom/android/systemui/plugins/qs/QSTile$State;", "handleStateChanged", "hasOverlappingRendering", "init", "click", "Landroid/view/View$OnClickListener;", "longClick", "Landroid/view/View$OnLongClickListener;", "tile", "Lcom/android/systemui/plugins/qs/QSTile;", "loadSideViewDrawableIfNecessary", "onConfigurationChanged", "newConfig", "Landroid/content/res/Configuration;", "onInitializeAccessibilityEvent", "event", "Landroid/view/accessibility/AccessibilityEvent;", "onInitializeAccessibilityNodeInfo", "info", "Landroid/view/accessibility/AccessibilityNodeInfo;", "onLayout", "changed", "l", "t", "r", "b", "onStateChanged", "resetOverride", "setAllColors", "backgroundColor", "labelColor", "secondaryLabelColor", "chevronColor", "setChevronColor", "color", "setClickable", "clickable", "setColor", "setLabelColor", "setSecondaryLabelColor", "setShouldBlockVisibilityChanges", "block", "setTransitionVisibility", "visibility", "setVisibility", "toString", "updateAccessibilityOrder", "previousView", "updateHeight", "updateResources", "Companion"})
public class QSTileViewImpl extends com.android.systemui.plugins.qs.QSTileView implements com.android.systemui.qs.tileimpl.HeightOverrideable, com.android.systemui.animation.LaunchableView {
    private int heightOverride = -1;
    private float squishinessFraction = 1.0F;
    private final int colorActive = 0;
    private final int colorInactive = 0;
    private final int colorUnavailable = 0;
    private final int colorLabelActive = 0;
    private final int colorLabelInactive = 0;
    private final int colorLabelUnavailable = 0;
    private final int colorSecondaryLabelActive = 0;
    private final int colorSecondaryLabelInactive = 0;
    private final int colorSecondaryLabelUnavailable = 0;
    private android.widget.TextView label;
    protected android.widget.TextView secondaryLabel;
    private com.android.systemui.qs.tileimpl.IgnorableChildLinearLayout labelContainer;
    protected android.view.ViewGroup sideView;
    private android.widget.ImageView customDrawableView;
    private android.widget.ImageView chevronView;
    private boolean showRippleEffect = true;
    private android.graphics.drawable.RippleDrawable ripple;
    private android.graphics.drawable.Drawable colorBackgroundDrawable;
    private int paintColor = 0;
    private final android.animation.ValueAnimator singleAnimator = null;
    private java.lang.String accessibilityClass;
    private java.lang.CharSequence stateDescriptionDeltas;
    private java.lang.CharSequence lastStateDescription;
    private boolean tileState = false;
    private int lastState = -1;
    private boolean blockVisibilityChanges = false;
    private int lastVisibility = android.view.View.VISIBLE;
    private final int[] locInScreen = null;
    private final com.android.systemui.plugins.qs.QSIconView _icon = null;
    private final boolean collapsed = false;
    private static final int INVALID = -1;
    private static final java.lang.String BACKGROUND_NAME = "background";
    private static final java.lang.String LABEL_NAME = "label";
    private static final java.lang.String SECONDARY_LABEL_NAME = "secondaryLabel";
    private static final java.lang.String CHEVRON_NAME = "chevron";
    public static final float UNAVAILABLE_ALPHA = 0.3F;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TILE_STATE_RES_PREFIX = "tile_states_";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.tileimpl.QSTileViewImpl.Companion Companion = null;
    
    @java.lang.Override()
    public int getHeightOverride() {
        return 0;
    }
    
    @java.lang.Override()
    public void setHeightOverride(int value) {
    }
    
    @java.lang.Override()
    public float getSquishinessFraction() {
        return 0.0F;
    }
    
    @java.lang.Override()
    public void setSquishinessFraction(float value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final android.widget.TextView getSecondaryLabel() {
        return null;
    }
    
    protected final void setSecondaryLabel(@org.jetbrains.annotations.NotNull()
    android.widget.TextView p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final android.view.ViewGroup getSideView() {
        return null;
    }
    
    protected final void setSideView(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup p0) {
    }
    
    protected final boolean getShowRippleEffect() {
        return false;
    }
    
    protected final void setShowRippleEffect(boolean p0) {
    }
    
    @java.lang.Override()
    protected void onConfigurationChanged(@org.jetbrains.annotations.Nullable()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    public void resetOverride() {
    }
    
    public final void updateResources() {
    }
    
    private final void createAndAddLabels() {
    }
    
    private final void createAndAddSideView() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable createTileBackground() {
        return null;
    }
    
    @java.lang.Override()
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
    }
    
    private final void updateHeight() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View updateAccessibilityOrder(@org.jetbrains.annotations.Nullable()
    android.view.View previousView) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.plugins.qs.QSIconView getIcon() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getIconWithBackground() {
        return null;
    }
    
    @java.lang.Override()
    public void init(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile tile) {
    }
    
    private final void init(android.view.View.OnClickListener click, android.view.View.OnLongClickListener longClick) {
    }
    
    @java.lang.Override()
    public void onStateChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    @java.lang.Override()
    public int getDetailY() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean hasOverlappingRendering() {
        return false;
    }
    
    @java.lang.Override()
    public void setClickable(boolean clickable) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getLabelContainer() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getSecondaryLabel() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getSecondaryIcon() {
        return null;
    }
    
    @java.lang.Override()
    public void setShouldBlockVisibilityChanges(boolean block) {
    }
    
    @java.lang.Override()
    public void setVisibility(int visibility) {
    }
    
    @java.lang.Override()
    public void setTransitionVisibility(int visibility) {
    }
    
    @java.lang.Override()
    public void onInitializeAccessibilityEvent(@org.jetbrains.annotations.NotNull()
    android.view.accessibility.AccessibilityEvent event) {
    }
    
    @java.lang.Override()
    public void onInitializeAccessibilityNodeInfo(@org.jetbrains.annotations.NotNull()
    android.view.accessibility.AccessibilityNodeInfo info) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    protected void handleStateChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    private final void setAllColors(int backgroundColor, int labelColor, int secondaryLabelColor, int chevronColor) {
    }
    
    private final void setColor(int color) {
    }
    
    private final void setLabelColor(int color) {
    }
    
    private final void setSecondaryLabelColor(int color) {
    }
    
    private final void setChevronColor(int color) {
    }
    
    private final void loadSideViewDrawableIfNecessary(com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    private final java.lang.String getStateText(com.android.systemui.plugins.qs.QSTile.State state) {
        return null;
    }
    
    protected boolean animationsEnabled() {
        return false;
    }
    
    private final int getBackgroundColorForState(int state) {
        return 0;
    }
    
    private final int getLabelColorForState(int state) {
        return 0;
    }
    
    private final int getSecondaryLabelColorForState(int state) {
        return 0;
    }
    
    private final int getChevronColorForState(int state) {
        return 0;
    }
    
    public QSTileViewImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSIconView _icon, boolean collapsed) {
        super(null);
    }
    
    public QSTileViewImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSIconView _icon) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u0007\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\n\u001a\u00020\u00048\u0000X\u0081T\u00a2\u0006\b\n\u0000\u0012\u0004\b\u000b\u0010\u0002R\u000e\u0010\f\u001a\u00020\rX\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tileimpl/QSTileViewImpl$Companion;", "", "()V", "BACKGROUND_NAME", "", "CHEVRON_NAME", "INVALID", "", "LABEL_NAME", "SECONDARY_LABEL_NAME", "TILE_STATE_RES_PREFIX", "getTILE_STATE_RES_PREFIX$main$annotations", "UNAVAILABLE_ALPHA", ""})
    public static final class Companion {
        
        @androidx.annotation.VisibleForTesting()
        @java.lang.Deprecated()
        public static void getTILE_STATE_RES_PREFIX$main$annotations() {
        }
        
        private Companion() {
            super();
        }
    }
}