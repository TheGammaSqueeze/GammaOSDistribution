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
 * Adapter for binding [Control] information to views.
 *
 * The model for this adapter is provided by a [ControlModel] that is set using
 * [changeFavoritesModel]. This allows for updating the model if there's a reload.
 *
 * @property elevation elevation of each control view
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0010!\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u001d2\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001\u001dB\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000e\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\b\u001a\u00020\tJ\b\u0010\u0010\u001a\u00020\u0006H\u0016J\u0010\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0012\u001a\u00020\u0006H\u0016J\u0018\u0010\u0013\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\u00022\u0006\u0010\u0015\u001a\u00020\u0006H\u0016J&\u0010\u0013\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\u00022\u0006\u0010\u0012\u001a\u00020\u00062\f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00180\u0017H\u0016J\u0018\u0010\u0019\u001a\u00020\u00022\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u0006H\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\b\u001a\u0004\u0018\u00010\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/controls/management/ControlAdapter;", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "Lcom/android/systemui/controls/management/Holder;", "elevation", "", "currentUserId", "", "(FI)V", "model", "Lcom/android/systemui/controls/management/ControlsModel;", "spanSizeLookup", "Landroidx/recyclerview/widget/GridLayoutManager$SpanSizeLookup;", "getSpanSizeLookup", "()Landroidx/recyclerview/widget/GridLayoutManager$SpanSizeLookup;", "changeModel", "", "getItemCount", "getItemViewType", "position", "onBindViewHolder", "holder", "index", "payloads", "", "", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "viewType", "Companion"})
public final class ControlAdapter extends androidx.recyclerview.widget.RecyclerView.Adapter<com.android.systemui.controls.management.Holder> {
    @org.jetbrains.annotations.NotNull()
    private final androidx.recyclerview.widget.GridLayoutManager.SpanSizeLookup spanSizeLookup = null;
    private com.android.systemui.controls.management.ControlsModel model;
    private final float elevation = 0.0F;
    private final int currentUserId = 0;
    public static final int TYPE_ZONE = 0;
    public static final int TYPE_CONTROL = 1;
    public static final int TYPE_DIVIDER = 2;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlAdapter.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.recyclerview.widget.GridLayoutManager.SpanSizeLookup getSpanSizeLookup() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.management.Holder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int viewType) {
        return null;
    }
    
    public final void changeModel(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsModel model) {
    }
    
    @java.lang.Override()
    public int getItemCount() {
        return 0;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.Holder holder, int index) {
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.Holder holder, int position, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Object> payloads) {
    }
    
    @java.lang.Override()
    public int getItemViewType(int position) {
        return 0;
    }
    
    public ControlAdapter(float elevation, int currentUserId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlAdapter$Companion;", "", "()V", "TYPE_CONTROL", "", "TYPE_DIVIDER", "TYPE_ZONE"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}