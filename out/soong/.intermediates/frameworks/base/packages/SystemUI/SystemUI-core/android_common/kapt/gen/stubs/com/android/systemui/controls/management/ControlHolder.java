package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.Rect;
import android.os.Bundle;
import android.service.controls.Control;
import android.service.controls.DeviceTypes;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityNodeInfo;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;
import androidx.core.view.AccessibilityDelegateCompat;
import androidx.core.view.ViewCompat;
import androidx.core.view.accessibility.AccessibilityNodeInfoCompat;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.R;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ui.CanUseIconPredicate;
import com.android.systemui.controls.ui.RenderInfo;

/**
 * Holder for using with [ControlStatusWrapper] to display names of zones.
 * @param moveHelper a helper interface to facilitate a11y rearranging. Null indicates no
 *                  rearranging
 * @param favoriteCallback this callback will be called whenever the favorite state of the
 *                        [Control] this view represents changes.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000|\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0010\u000b\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\b\u0000\u0018\u00002\u00020\u0001B=\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u001c\u0010\b\u001a\u0018\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\f0\tj\u0002`\r\u00a2\u0006\u0002\u0010\u000eJ\u0018\u0010\"\u001a\u00020\f2\u0006\u0010#\u001a\u00020$2\u0006\u0010%\u001a\u00020&H\u0002J\u0010\u0010\'\u001a\u00020\f2\u0006\u0010(\u001a\u00020)H\u0016J\u0018\u0010*\u001a\u00020$2\u0006\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020\u0005H\u0002J\u0012\u0010.\u001a\u0004\u0018\u00010/2\u0006\u0010\u0013\u001a\u00020\u000bH\u0002J\u0010\u00100\u001a\u00020\f2\u0006\u0010\u0013\u001a\u00020\u000bH\u0016R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\'\u0010\b\u001a\u0018\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\f0\tj\u0002`\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u0016\u0010\u0017\u001a\n \u0018*\u0004\u0018\u00010\n0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0013\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u001cR\u0016\u0010\u001d\u001a\n \u0018*\u0004\u0018\u00010\n0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010!\u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlHolder;", "Lcom/android/systemui/controls/management/Holder;", "view", "Landroid/view/View;", "currentUserId", "", "moveHelper", "Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "favoriteCallback", "Lkotlin/Function2;", "", "", "", "Lcom/android/systemui/controls/management/ModelFavoriteChanger;", "(Landroid/view/View;ILcom/android/systemui/controls/management/ControlsModel$MoveHelper;Lkotlin/jvm/functions/Function2;)V", "accessibilityDelegate", "Lcom/android/systemui/controls/management/ControlHolderAccessibilityDelegate;", "canUseIconPredicate", "Lcom/android/systemui/controls/ui/CanUseIconPredicate;", "favorite", "Landroid/widget/CheckBox;", "getFavoriteCallback", "()Lkotlin/jvm/functions/Function2;", "favoriteStateDescription", "kotlin.jvm.PlatformType", "icon", "Landroid/widget/ImageView;", "getMoveHelper", "()Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "notFavoriteStateDescription", "removed", "Landroid/widget/TextView;", "subtitle", "title", "applyRenderInfo", "ri", "Lcom/android/systemui/controls/ui/RenderInfo;", "ci", "Lcom/android/systemui/controls/ControlInterface;", "bindData", "wrapper", "Lcom/android/systemui/controls/management/ElementWrapper;", "getRenderInfo", "component", "Landroid/content/ComponentName;", "deviceType", "stateDescription", "", "updateFavorite"})
public final class ControlHolder extends com.android.systemui.controls.management.Holder {
    private final java.lang.String favoriteStateDescription = null;
    private final java.lang.String notFavoriteStateDescription = null;
    private final android.widget.ImageView icon = null;
    private final android.widget.TextView title = null;
    private final android.widget.TextView subtitle = null;
    private final android.widget.TextView removed = null;
    private final android.widget.CheckBox favorite = null;
    private final com.android.systemui.controls.ui.CanUseIconPredicate canUseIconPredicate = null;
    private final com.android.systemui.controls.management.ControlHolderAccessibilityDelegate accessibilityDelegate = null;
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.controls.management.ControlsModel.MoveHelper moveHelper = null;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function2<java.lang.String, java.lang.Boolean, kotlin.Unit> favoriteCallback = null;
    
    private final java.lang.CharSequence stateDescription(boolean favorite) {
        return null;
    }
    
    @java.lang.Override()
    public void bindData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ElementWrapper wrapper) {
    }
    
    @java.lang.Override()
    public void updateFavorite(boolean favorite) {
    }
    
    private final com.android.systemui.controls.ui.RenderInfo getRenderInfo(android.content.ComponentName component, @android.service.controls.DeviceTypes.DeviceType()
    int deviceType) {
        return null;
    }
    
    private final void applyRenderInfo(com.android.systemui.controls.ui.RenderInfo ri, com.android.systemui.controls.ControlInterface ci) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.controls.management.ControlsModel.MoveHelper getMoveHelper() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function2<java.lang.String, java.lang.Boolean, kotlin.Unit> getFavoriteCallback() {
        return null;
    }
    
    public ControlHolder(@org.jetbrains.annotations.NotNull()
    android.view.View view, int currentUserId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.controls.management.ControlsModel.MoveHelper moveHelper, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.lang.String, ? super java.lang.Boolean, kotlin.Unit> favoriteCallback) {
    }
}