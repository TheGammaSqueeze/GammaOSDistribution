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
 * Accessibility delegate for [ControlHolder].
 *
 * Provides the following functionality:
 * * Sets the state description indicating whether the controls is Favorited or Unfavorited
 * * Adds the position to the state description if necessary.
 * * Adds context action for moving (rearranging) a control.
 *
 * @param stateRetriever function to determine the state description based on the favorite state
 * @param positionRetriever function to obtain the position of this control. It only has to be
 *                         correct in controls that are currently favorites (and therefore can
 *                         be moved).
 * @param moveHelper helper interface to determine if a control can be moved and actually move it.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000D\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\b\u0002\u0018\u0000 #2\u00020\u0001:\u0001#B3\u0012\u0014\u0010\u0002\u001a\u0010\u0012\u0004\u0012\u00020\u0004\u0012\u0006\u0012\u0004\u0018\u00010\u00050\u0003\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\b\u0010\t\u001a\u0004\u0018\u00010\n\u00a2\u0006\u0002\u0010\u000bJ\u0018\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002J\u0018\u0010\u001c\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002J\u0018\u0010\u001d\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002J\u0018\u0010\u001e\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0016J$\u0010\u001f\u001a\u00020\u00042\b\u0010\u0018\u001a\u0004\u0018\u00010\u00192\u0006\u0010 \u001a\u00020\b2\b\u0010!\u001a\u0004\u0018\u00010\"H\u0016R\u001a\u0010\f\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u0013\u0010\t\u001a\u0004\u0018\u00010\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0017\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u001f\u0010\u0002\u001a\u0010\u0012\u0004\u0012\u00020\u0004\u0012\u0006\u0012\u0004\u0018\u00010\u00050\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015"}, d2 = {"Lcom/android/systemui/controls/management/ControlHolderAccessibilityDelegate;", "Landroidx/core/view/AccessibilityDelegateCompat;", "stateRetriever", "Lkotlin/Function1;", "", "", "positionRetriever", "Lkotlin/Function0;", "", "moveHelper", "Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "(Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;)V", "isFavorite", "()Z", "setFavorite", "(Z)V", "getMoveHelper", "()Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "getPositionRetriever", "()Lkotlin/jvm/functions/Function0;", "getStateRetriever", "()Lkotlin/jvm/functions/Function1;", "addClickAction", "", "host", "Landroid/view/View;", "info", "Landroidx/core/view/accessibility/AccessibilityNodeInfoCompat;", "maybeAddMoveAfterAction", "maybeAddMoveBeforeAction", "onInitializeAccessibilityNodeInfo", "performAccessibilityAction", "action", "args", "Landroid/os/Bundle;", "Companion"})
final class ControlHolderAccessibilityDelegate extends androidx.core.view.AccessibilityDelegateCompat {
    private boolean isFavorite = false;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function1<java.lang.Boolean, java.lang.CharSequence> stateRetriever = null;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function0<java.lang.Integer> positionRetriever = null;
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.controls.management.ControlsModel.MoveHelper moveHelper = null;
    private static final int MOVE_BEFORE_ID = 0;
    private static final int MOVE_AFTER_ID = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlHolderAccessibilityDelegate.Companion Companion = null;
    
    public final boolean isFavorite() {
        return false;
    }
    
    public final void setFavorite(boolean p0) {
    }
    
    @java.lang.Override()
    public void onInitializeAccessibilityNodeInfo(@org.jetbrains.annotations.NotNull()
    android.view.View host, @org.jetbrains.annotations.NotNull()
    androidx.core.view.accessibility.AccessibilityNodeInfoCompat info) {
    }
    
    @java.lang.Override()
    public boolean performAccessibilityAction(@org.jetbrains.annotations.Nullable()
    android.view.View host, int action, @org.jetbrains.annotations.Nullable()
    android.os.Bundle args) {
        return false;
    }
    
    private final void addClickAction(android.view.View host, androidx.core.view.accessibility.AccessibilityNodeInfoCompat info) {
    }
    
    private final void maybeAddMoveBeforeAction(android.view.View host, androidx.core.view.accessibility.AccessibilityNodeInfoCompat info) {
    }
    
    private final void maybeAddMoveAfterAction(android.view.View host, androidx.core.view.accessibility.AccessibilityNodeInfoCompat info) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<java.lang.Boolean, java.lang.CharSequence> getStateRetriever() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<java.lang.Integer> getPositionRetriever() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.controls.management.ControlsModel.MoveHelper getMoveHelper() {
        return null;
    }
    
    public ControlHolderAccessibilityDelegate(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, ? extends java.lang.CharSequence> stateRetriever, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<java.lang.Integer> positionRetriever, @org.jetbrains.annotations.Nullable()
    com.android.systemui.controls.management.ControlsModel.MoveHelper moveHelper) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlHolderAccessibilityDelegate$Companion;", "", "()V", "MOVE_AFTER_ID", "", "MOVE_BEFORE_ID"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}