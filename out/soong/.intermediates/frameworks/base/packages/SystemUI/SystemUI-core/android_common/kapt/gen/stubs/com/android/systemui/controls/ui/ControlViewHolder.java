package com.android.systemui.controls.ui;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
import android.annotation.ColorRes;
import android.app.Dialog;
import android.content.Context;
import android.content.res.ColorStateList;
import android.graphics.drawable.ClipDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.graphics.drawable.LayerDrawable;
import android.graphics.drawable.StateListDrawable;
import android.service.controls.Control;
import android.service.controls.DeviceTypes;
import android.service.controls.actions.ControlAction;
import android.service.controls.templates.ControlTemplate;
import android.service.controls.templates.RangeTemplate;
import android.service.controls.templates.StatelessTemplate;
import android.service.controls.templates.TemperatureControlTemplate;
import android.service.controls.templates.ThumbnailTemplate;
import android.service.controls.templates.ToggleRangeTemplate;
import android.service.controls.templates.ToggleTemplate;
import android.util.MathUtils;
import android.util.TypedValue;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.ColorInt;
import androidx.annotation.VisibleForTesting;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.util.concurrency.DelayableExecutor;

/**
 * Wraps the widgets that make up the UI representation of a {@link Control}. Updates to the view
 * are signaled via calls to {@link #bindData}. Similar to the ViewHolder concept used in
 * RecyclerViews.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00c4\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0015\n\u0002\u0018\u0002\n\u0002\b\u001d\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 \u0097\u00012\u00020\u0001:\u0002\u0097\u0001BE\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u0010J\u000e\u0010i\u001a\u00020P2\u0006\u0010i\u001a\u00020CJ\u000e\u0010j\u001a\u00020P2\u0006\u0010k\u001a\u00020\u000eJ \u0010l\u001a\u00020P2\u0006\u0010m\u001a\u00020>2\u0006\u0010n\u001a\u00020>2\u0006\u0010o\u001a\u00020\u000eH\u0002J\u001e\u0010p\u001a\u00020P2\u0006\u0010m\u001a\u00020>2\f\u0010q\u001a\b\u0012\u0004\u0012\u00020P0OH\u0002J4\u0010r\u001a\u00020P2\u0006\u0010s\u001a\u00020t2\u0006\u0010u\u001a\u00020\u000e2\b\b\u0001\u0010v\u001a\u00020\u000e2\b\b\u0001\u0010w\u001a\u00020\u000e2\u0006\u0010x\u001a\u00020^H\u0002J\'\u0010y\u001a\u00020P2\u0006\u0010n\u001a\u00020>2\u0006\u0010z\u001a\u00020\u000e2\b\b\u0002\u0010m\u001a\u00020>H\u0000\u00a2\u0006\u0002\b{J(\u0010|\u001a\u00020\u00142\b\u0010}\u001a\u0004\u0018\u00010\u00142\f\u0010~\u001a\b\u0012\u0004\u0012\u00020\u00140O2\b\b\u0002\u0010z\u001a\u00020\u000eJ\u0017\u0010\u007f\u001a\u00020P2\u0006\u00101\u001a\u0002022\u0007\u0010\u0080\u0001\u001a\u00020>J\u0007\u0010\u0081\u0001\u001a\u00020PJ&\u0010\u0082\u0001\u001a\b\u0012\u0004\u0012\u00020\u00140O2\u0006\u0010S\u001a\u00020\u000e2\u0007\u0010\u0083\u0001\u001a\u00020)2\u0006\u00107\u001a\u00020\u000eJ\u0010\u0010\u0084\u0001\u001a\u000b \u0085\u0001*\u0004\u0018\u00010M0MJ\u0011\u0010\u0086\u0001\u001a\u00020P2\u0006\u0010n\u001a\u00020>H\u0002J\u0007\u0010\u0087\u0001\u001a\u00020PJ\u001b\u0010\u0088\u0001\u001a\u00020P2\u0007\u0010\u0089\u0001\u001a\u00020M2\t\b\u0002\u0010\u008a\u0001\u001a\u00020>J\u0010\u0010\u008b\u0001\u001a\u00020P2\u0007\u0010\u008c\u0001\u001a\u00020^J-\u0010\u008d\u0001\u001a\u00020P2\u0006\u0010s\u001a\u00020t2\u0006\u0010u\u001a\u00020\u000e2\b\b\u0001\u0010v\u001a\u00020\u000e2\b\b\u0001\u0010w\u001a\u00020\u000eH\u0002J\t\u0010\u008e\u0001\u001a\u00020PH\u0002J?\u0010\u008f\u0001\u001a\u00020P2\u0006\u0010n\u001a\u00020>2\u0007\u0010\u0089\u0001\u001a\u00020M2\u0007\u0010\u0090\u0001\u001a\u00020t2\b\u0010\u0091\u0001\u001a\u00030\u0092\u00012\n\u0010\u0093\u0001\u001a\u0005\u0018\u00010\u0094\u0001H\u0001\u00a2\u0006\u0003\b\u0095\u0001J\u0007\u0010\u0096\u0001\u001a\u00020>R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018R\u0011\u0010\b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001aR\u0011\u0010\u001b\u001a\u00020\u001c\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001eR\u0011\u0010\u001f\u001a\u00020 \u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\"R\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010$R\u0011\u0010%\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b&\u0010\'R\u0011\u0010(\u001a\u00020)8F\u00a2\u0006\u0006\u001a\u0004\b*\u0010+R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010-R\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010/R\u0011\u0010\u000f\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b0\u0010\'R\u001a\u00101\u001a\u000202X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b3\u00104\"\u0004\b5\u00106R\u0011\u00107\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b8\u0010\'R\u0011\u00109\u001a\u00020:\u00a2\u0006\b\n\u0000\u001a\u0004\b;\u0010<R\u001a\u0010=\u001a\u00020>X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b=\u0010?\"\u0004\b@\u0010AR\u001c\u0010B\u001a\u0004\u0018\u00010CX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bD\u0010E\"\u0004\bF\u0010GR\u0010\u0010H\u001a\u0004\u0018\u00010IX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\bJ\u0010KR\u000e\u0010L\u001a\u00020MX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010N\u001a\b\u0012\u0004\u0012\u00020P0OX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010Q\u001a\u0004\u0018\u00010RX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010S\u001a\u00020T\u00a2\u0006\b\n\u0000\u001a\u0004\bU\u0010VR\u0010\u0010W\u001a\u0004\u0018\u00010XX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010Y\u001a\u00020T\u00a2\u0006\b\n\u0000\u001a\u0004\bZ\u0010VR\u0011\u0010[\u001a\u00020T\u00a2\u0006\b\n\u0000\u001a\u0004\b\\\u0010VR\u000e\u0010]\u001a\u00020^X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b_\u0010\u001aR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b`\u0010\'R\u001a\u0010a\u001a\u00020>X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bb\u0010?\"\u0004\bc\u0010AR\u001c\u0010d\u001a\u0004\u0018\u00010IX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\be\u0010f\"\u0004\bg\u0010h"}, d2 = {"Lcom/android/systemui/controls/ui/ControlViewHolder;", "", "layout", "Landroid/view/ViewGroup;", "controlsController", "Lcom/android/systemui/controls/controller/ControlsController;", "uiExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "bgExecutor", "controlActionCoordinator", "Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "controlsMetricsLogger", "Lcom/android/systemui/controls/ControlsMetricsLogger;", "uid", "", "currentUserId", "(Landroid/view/ViewGroup;Lcom/android/systemui/controls/controller/ControlsController;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/controls/ui/ControlActionCoordinator;Lcom/android/systemui/controls/ControlsMetricsLogger;II)V", "baseLayer", "Landroid/graphics/drawable/GradientDrawable;", "behavior", "Lcom/android/systemui/controls/ui/Behavior;", "getBehavior", "()Lcom/android/systemui/controls/ui/Behavior;", "setBehavior", "(Lcom/android/systemui/controls/ui/Behavior;)V", "getBgExecutor", "()Lcom/android/systemui/util/concurrency/DelayableExecutor;", "clipLayer", "Landroid/graphics/drawable/ClipDrawable;", "getClipLayer", "()Landroid/graphics/drawable/ClipDrawable;", "context", "Landroid/content/Context;", "getContext", "()Landroid/content/Context;", "getControlActionCoordinator", "()Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "controlStatus", "getControlStatus", "()I", "controlTemplate", "Landroid/service/controls/templates/ControlTemplate;", "getControlTemplate", "()Landroid/service/controls/templates/ControlTemplate;", "getControlsController", "()Lcom/android/systemui/controls/controller/ControlsController;", "getControlsMetricsLogger", "()Lcom/android/systemui/controls/ControlsMetricsLogger;", "getCurrentUserId", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "getCws", "()Lcom/android/systemui/controls/ui/ControlWithState;", "setCws", "(Lcom/android/systemui/controls/ui/ControlWithState;)V", "deviceType", "getDeviceType", "icon", "Landroid/widget/ImageView;", "getIcon", "()Landroid/widget/ImageView;", "isLoading", "", "()Z", "setLoading", "(Z)V", "lastAction", "Landroid/service/controls/actions/ControlAction;", "getLastAction", "()Landroid/service/controls/actions/ControlAction;", "setLastAction", "(Landroid/service/controls/actions/ControlAction;)V", "lastChallengeDialog", "Landroid/app/Dialog;", "getLayout", "()Landroid/view/ViewGroup;", "nextStatusText", "", "onDialogCancel", "Lkotlin/Function0;", "", "stateAnimator", "Landroid/animation/ValueAnimator;", "status", "Landroid/widget/TextView;", "getStatus", "()Landroid/widget/TextView;", "statusAnimator", "Landroid/animation/Animator;", "subtitle", "getSubtitle", "title", "getTitle", "toggleBackgroundIntensity", "", "getUiExecutor", "getUid", "userInteractionInProgress", "getUserInteractionInProgress", "setUserInteractionInProgress", "visibleDialog", "getVisibleDialog", "()Landroid/app/Dialog;", "setVisibleDialog", "(Landroid/app/Dialog;)V", "action", "actionResponse", "response", "animateBackgroundChange", "animated", "enabled", "bgColor", "animateStatusChange", "statusRowUpdater", "applyBackgroundChange", "clipDrawable", "Landroid/graphics/drawable/Drawable;", "newAlpha", "newClipColor", "newBaseColor", "newLayoutAlpha", "applyRenderInfo", "offset", "applyRenderInfo$main", "bindBehavior", "existingBehavior", "createBehaviour", "bindData", "isLocked", "dismiss", "findBehavior", "template", "getStatusText", "kotlin.jvm.PlatformType", "setEnabled", "setErrorStatus", "setStatusText", "text", "immediately", "setStatusTextSize", "textSize", "startBackgroundAnimation", "updateContentDescription", "updateStatusRow", "drawable", "color", "Landroid/content/res/ColorStateList;", "control", "Landroid/service/controls/Control;", "updateStatusRow$main", "usePanel", "Companion"})
public final class ControlViewHolder {
    private final float toggleBackgroundIntensity = 0.0F;
    private android.animation.ValueAnimator stateAnimator;
    private android.animation.Animator statusAnimator;
    private final android.graphics.drawable.GradientDrawable baseLayer = null;
    @org.jetbrains.annotations.NotNull()
    private final android.widget.ImageView icon = null;
    @org.jetbrains.annotations.NotNull()
    private final android.widget.TextView status = null;
    private java.lang.CharSequence nextStatusText = "";
    @org.jetbrains.annotations.NotNull()
    private final android.widget.TextView title = null;
    @org.jetbrains.annotations.NotNull()
    private final android.widget.TextView subtitle = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.drawable.ClipDrawable clipLayer = null;
    public com.android.systemui.controls.ui.ControlWithState cws;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.controls.ui.Behavior behavior;
    @org.jetbrains.annotations.Nullable()
    private android.service.controls.actions.ControlAction lastAction;
    private boolean isLoading = false;
    @org.jetbrains.annotations.Nullable()
    private android.app.Dialog visibleDialog;
    private android.app.Dialog lastChallengeDialog;
    private final kotlin.jvm.functions.Function0<kotlin.Unit> onDialogCancel = null;
    private boolean userInteractionInProgress = false;
    @org.jetbrains.annotations.NotNull()
    private final android.view.ViewGroup layout = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.controller.ControlsController controlsController = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.concurrency.DelayableExecutor uiExecutor = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.concurrency.DelayableExecutor bgExecutor = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.ui.ControlActionCoordinator controlActionCoordinator = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger = null;
    private final int uid = 0;
    private final int currentUserId = 0;
    public static final long STATE_ANIMATION_DURATION = 700L;
    private static final int ALPHA_ENABLED = 255;
    private static final int ALPHA_DISABLED = 0;
    private static final float STATUS_ALPHA_ENABLED = 1.0F;
    private static final float STATUS_ALPHA_DIMMED = 0.45F;
    private static final java.util.Set<java.lang.Integer> FORCE_PANEL_DEVICES = null;
    private static final int[] ATTR_ENABLED = {16842910};
    private static final int[] ATTR_DISABLED = {-16842910};
    public static final int MIN_LEVEL = 0;
    public static final int MAX_LEVEL = 10000;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ControlViewHolder.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.ImageView getIcon() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.TextView getStatus() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.TextView getTitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.TextView getSubtitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.ClipDrawable getClipLayer() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlWithState getCws() {
        return null;
    }
    
    public final void setCws(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.controls.ui.Behavior getBehavior() {
        return null;
    }
    
    public final void setBehavior(@org.jetbrains.annotations.Nullable()
    com.android.systemui.controls.ui.Behavior p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.service.controls.actions.ControlAction getLastAction() {
        return null;
    }
    
    public final void setLastAction(@org.jetbrains.annotations.Nullable()
    android.service.controls.actions.ControlAction p0) {
    }
    
    public final boolean isLoading() {
        return false;
    }
    
    public final void setLoading(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.app.Dialog getVisibleDialog() {
        return null;
    }
    
    public final void setVisibleDialog(@org.jetbrains.annotations.Nullable()
    android.app.Dialog p0) {
    }
    
    public final int getDeviceType() {
        return 0;
    }
    
    public final int getControlStatus() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.templates.ControlTemplate getControlTemplate() {
        return null;
    }
    
    public final boolean getUserInteractionInProgress() {
        return false;
    }
    
    public final void setUserInteractionInProgress(boolean p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<com.android.systemui.controls.ui.Behavior> findBehavior(int status, @org.jetbrains.annotations.NotNull()
    android.service.controls.templates.ControlTemplate template, int deviceType) {
        return null;
    }
    
    public final void bindData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, boolean isLocked) {
    }
    
    public final void actionResponse(@android.service.controls.actions.ControlAction.ResponseResult()
    int response) {
    }
    
    public final void dismiss() {
    }
    
    public final void setErrorStatus() {
    }
    
    private final void updateContentDescription() {
    }
    
    public final void action(@org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action) {
    }
    
    public final boolean usePanel() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.Behavior bindBehavior(@org.jetbrains.annotations.Nullable()
    com.android.systemui.controls.ui.Behavior existingBehavior, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends com.android.systemui.controls.ui.Behavior> createBehaviour, int offset) {
        return null;
    }
    
    public final void applyRenderInfo$main(boolean enabled, int offset, boolean animated) {
    }
    
    public final java.lang.CharSequence getStatusText() {
        return null;
    }
    
    public final void setStatusTextSize(float textSize) {
    }
    
    public final void setStatusText(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence text, boolean immediately) {
    }
    
    private final void animateBackgroundChange(boolean animated, boolean enabled, @android.annotation.ColorRes()
    int bgColor) {
    }
    
    private final void startBackgroundAnimation(android.graphics.drawable.Drawable clipDrawable, int newAlpha, @androidx.annotation.ColorInt()
    int newClipColor, @androidx.annotation.ColorInt()
    int newBaseColor) {
    }
    
    /**
     * Applies a change in background.
     *
     * Updates both alpha and background colors. Only updates colors for GradientDrawables and not
     * static images as used for the ThumbnailTemplate.
     */
    private final void applyBackgroundChange(android.graphics.drawable.Drawable clipDrawable, int newAlpha, @androidx.annotation.ColorInt()
    int newClipColor, @androidx.annotation.ColorInt()
    int newBaseColor, float newLayoutAlpha) {
    }
    
    private final void animateStatusChange(boolean animated, kotlin.jvm.functions.Function0<kotlin.Unit> statusRowUpdater) {
    }
    
    @androidx.annotation.VisibleForTesting()
    public final void updateStatusRow$main(boolean enabled, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence text, @org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable drawable, @org.jetbrains.annotations.NotNull()
    android.content.res.ColorStateList color, @org.jetbrains.annotations.Nullable()
    android.service.controls.Control control) {
    }
    
    private final void setEnabled(boolean enabled) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.ViewGroup getLayout() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.ControlsController getControlsController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.concurrency.DelayableExecutor getUiExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.concurrency.DelayableExecutor getBgExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlActionCoordinator getControlActionCoordinator() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ControlsMetricsLogger getControlsMetricsLogger() {
        return null;
    }
    
    public final int getUid() {
        return 0;
    }
    
    public final int getCurrentUserId() {
        return 0;
    }
    
    public ControlViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup layout, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsController controlsController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor uiExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlActionCoordinator controlActionCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger, int uid, int currentUserId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0015\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\b\u0003\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u0007\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u00040\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0010X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlViewHolder$Companion;", "", "()V", "ALPHA_DISABLED", "", "ALPHA_ENABLED", "ATTR_DISABLED", "", "ATTR_ENABLED", "FORCE_PANEL_DEVICES", "", "MAX_LEVEL", "MIN_LEVEL", "STATE_ANIMATION_DURATION", "", "STATUS_ALPHA_DIMMED", "", "STATUS_ALPHA_ENABLED"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}